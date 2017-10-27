#include "Renderer.h"

#include "Object.h"
#include "GBuffer.h"

namespace Aiko {

	Renderer::Renderer()
		: shader( Shader("terrainvertex.glsl", "terrainfragment.glsl") )
	{
		gbuffer = new GBuffer();
	}


	Renderer::~Renderer()
	{
		delete gbuffer;
	}

	void Renderer::begin(Camera& cam)
	{
		//shader.start();
		// shader.prepare();
		this->started = true;

		// loadCamera(cam);

	}

	void Renderer::end(Camera& cam)
	{
		if (!this->started) {
			throw std::runtime_error("call begin before start");
		}

		for (unsigned int i = 0; i < this->objects.size(); i++)
		{
			Object& obj = *(this->objects.at(i));

			if (obj.containsComponent(Component::LIGHT))
			{
				Light* light = (Light*)obj.getComponent(Component::LIGHT);
				addLight(obj.getTransform().position, light->color, light->attenuation, light->linear, light->quadratic);
			}

		}

		this->gbuffer->render(cam, objects, lights);
		
		this->objects.clear();
		this->lights.clear();

		//shader.end();
		this->started = false;
	}

	void Renderer::loadCamera(Camera & camera)
	{
		this->shader.setMat4("view", camera.getView());
		this->shader.setMat4("projection", camera.getProjection());
	}

	void Renderer::loadTrasnform(Transform & transform)
	{
		this->shader.setMat4("model", transform.getModel());
	}

	void Renderer::render(Object * obj)
	{
		if (!this->started)
			throw std::runtime_error("please call begin() before start drawing things on screen");

		this->objects.push_back(obj);

	}

	Shader& Renderer::getShader()
	{
		return this->shader;
	}

	void Renderer::addLight(glm::vec3 pos, glm::vec3 color, float attenuation, float linear, float quadratic)
	{
		if (this->lights.size() >= 128)
			throw std::runtime_error("They are too many light loaded. Update lights on shader too");

		this->lights.push_back(Lighto(pos, color, attenuation, linear, quadratic));
	}

}