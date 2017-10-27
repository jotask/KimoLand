#pragma once

#include <iostream>
#include <Gl/glew.h>

#include <vector>

#include "definitions.h"
#include "Shader.h"
#include "Camera.h"
#include "Renderer.h"
#include "Object.h"

namespace Aiko {

	class GBuffer
	{
	public:
		GBuffer();
		~GBuffer();

		void render(Camera& cam, std::vector<Object*> & objs, std::vector<Renderer::Lighto> & lights);

	private:

		GLuint gBuffer;

		GLuint gPosition, gNormal, gAlbedoSpec;

		GLuint rboDepth;

		GLuint quadVAO = -2;
		GLuint quadVBO;
		void renderQuad();

		Shader geometryPass;
		Shader lightingPass;

	};

}