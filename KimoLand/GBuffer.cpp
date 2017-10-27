#include "GBuffer.h"

#include "Light.h"

namespace Aiko {

	GBuffer::GBuffer()
		:geometryPass(Shader("buffervertex.glsl", "bufferfragment.glsl")),
		lightingPass(Shader("deferredShadingvertex.glsl", "deferredShadingfragment.glsl")
		)
	{

		// configure g-buffer framebuffer
		// ------------------------------
		
		glGenFramebuffers(1, &gBuffer);
		glBindFramebuffer(GL_FRAMEBUFFER, gBuffer);
		
		// position color buffer
		glGenTextures(1, &gPosition);
		glBindTexture(GL_TEXTURE_2D, gPosition);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB16F, WIDTH, HEIGHT, 0, GL_RGB, GL_FLOAT, NULL);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, gPosition, 0);
		// normal color buffer
		glGenTextures(1, &gNormal);
		glBindTexture(GL_TEXTURE_2D, gNormal);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB16F, WIDTH, HEIGHT, 0, GL_RGB, GL_FLOAT, NULL);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT1, GL_TEXTURE_2D, gNormal, 0);
		// color + specular color buffer
		glGenTextures(1, &gAlbedoSpec);
		glBindTexture(GL_TEXTURE_2D, gAlbedoSpec);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, WIDTH, HEIGHT, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT2, GL_TEXTURE_2D, gAlbedoSpec, 0);

		// tell OpenGL which color attachments we'll use (of this framebuffer) for rendering 
		GLuint attachments[3] = { GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1, GL_COLOR_ATTACHMENT2 };
		glDrawBuffers(3, attachments);

		// create and attach depth buffer (renderbuffer)
		glGenRenderbuffers(1, &rboDepth);
		glBindRenderbuffer(GL_RENDERBUFFER, rboDepth);
		glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, WIDTH, HEIGHT);
		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, rboDepth);
		// finally check if framebuffer is complete
		if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
			throw std::runtime_error("Framebuffer not complete!");
		glBindFramebuffer(GL_FRAMEBUFFER, 0);

	}

	GBuffer::~GBuffer()
	{

	}

	void GBuffer::render(Camera & cam, std::vector<Object*> &objs, std::vector<Renderer::Lighto> &lights)
	{

		lightingPass.start();
		lightingPass.setInt("gPosition", 0);
		lightingPass.setInt("gNormal", 1);
		lightingPass.setInt("gAlbedoSpec", 2);
		lightingPass.end();

		glEnable(GL_DEPTH_TEST);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		/////////////////////////////////////////////////////////////////////
		// 1. geometry pass: render scene's geometry/color data into gbuffer
		/////////////////////////////////////////////////////////////////////

		glBindFramebuffer(GL_FRAMEBUFFER, gBuffer);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glm::mat4 projection = cam.getProjection();
		glm::mat4 view = cam.getView();

		geometryPass.start();
		geometryPass.setMat4("projection", projection);
		geometryPass.setMat4("view", view);

		for (unsigned int i = 0; i < objs.size(); i++)
		{
			Object& obj = *(objs.at(i));
			glm::mat4 model = obj.getTransform().getModel();
			geometryPass.setMat4("model", model);
			obj.render();
			//nanosuit.Draw(shaderGeometryPass);
		}

		glBindFramebuffer(GL_FRAMEBUFFER, 0);

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		// 2. lighting pass: calculate lighting by iterating over a screen filled quad pixel-by-pixel using the gbuffer's content.
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		lightingPass.start();

		lightingPass.setInt("NR_LIGHTS", Light::NUMBER_LIGTHS);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, gPosition);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, gNormal);
		glActiveTexture(GL_TEXTURE2);
		glBindTexture(GL_TEXTURE_2D, gAlbedoSpec);

		for (unsigned int i = 0; i < lights.size(); i++)
		{
			Renderer::Lighto light = lights.at(i);
			lightingPass.setVec3("lights[" + std::to_string(i) + "].Position", light.pos);
			lightingPass.setVec3("lights[" + std::to_string(i) + "].Color", light.col);
			// update attenuation parameters and calculate radius
			const float constant = 1.0; // note that we don't send this to the shader, we assume it is always 1.0 (in our case)
			const float linear = 0.7;
			const float quadratic = 1.8;
			lightingPass.setFloat("lights[" + std::to_string(i) + "].Attenuation", light.attenuation);
			lightingPass.setFloat("lights[" + std::to_string(i) + "].Linear", light.linear);
			lightingPass.setFloat("lights[" + std::to_string(i) + "].Quadratic", light.quadratic);

			// then calculate radius of light volume/sphere
			const float maxBrightness = std::fmaxf(std::fmaxf(light.col.r, light.col.g), light.col.b);
			float radius = (-linear + std::sqrt(linear * linear - 4 * quadratic * (constant - (256.0f / 5.0f) * maxBrightness))) / (2.0f * quadratic);
			lightingPass.setFloat("lights[" + std::to_string(i) + "].Radius", radius);

		}

		lightingPass.setVec3("viewPos", cam.getTransform().position);

		// finally render quad
		renderQuad();

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		// 2.5. copy content of geometry's depth buffer to default framebuffer's depth buffer
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		glBindFramebuffer(GL_READ_FRAMEBUFFER, gBuffer);
		glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0); // write to default framebuffer
		// blit to default framebuffer. Note that this may or may not work as the internal formats of both the FBO and default
		// framebuffer have to match.
		// the internal formats are implementation defined. This works on all of my systems, but if it doesn't on yours you'll
		// likely have to write to the 		
		// depth buffer in another shader stage (or somehow see to match the default framebuffer's internal format with the FBO's
		// internal format).
		glBlitFramebuffer(0, 0, WIDTH, HEIGHT, 0, 0, WIDTH, HEIGHT, GL_DEPTH_BUFFER_BIT, GL_NEAREST);
		glBindBuffer(GL_FRAMEBUFFER, 0);

	}

	void GBuffer::renderQuad()
	{
		if (quadVAO == -2)
		{
			float quadVertices[] = {
				// positions        // texture Coords
				-1.0f,  1.0f, 0.0f, 0.0f, 1.0f,
				-1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
				1.0f,  1.0f, 0.0f, 1.0f, 1.0f,
				1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
			};
			// setup plane VAO
			glGenVertexArrays(1, &quadVAO);
			glGenBuffers(1, &quadVBO);
			glBindVertexArray(quadVAO);
			glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
		}

		glBindVertexArray(quadVAO);
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
		glBindVertexArray(0);

	}

}