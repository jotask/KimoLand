#pragma once

#include <exception>
#include <vector>

#include "Shader.h"
#include "Camera.h"
#include "Transform.h"

namespace Aiko {

	class Renderer
	{
	public:
		Renderer();
		~Renderer();

		void begin();
		void end();

		void loadCamera(Camera& camera);
		void loadTrasnform(Transform& transform);

		Shader& getShader();

		private:

			bool started = false;

			Shader shader;

	};

}