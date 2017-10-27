#pragma once

#include <exception>
#include <vector>

#include "Shader.h"
#include "Camera.h"
#include "Transform.h"
#include "Light.h"

namespace Aiko {
	
	class Object;
	class GBuffer;

	class Renderer
	{
	public:

		struct Lighto
		{
			glm::vec3 pos;
			glm::vec3 col;
			float attenuation;
			float linear;
			float quadratic;

			Lighto(glm::vec3 _pos, glm::vec3 _col, float _att, float _lin, float _qua)
			{
				pos = _pos;
				col = _col;
				attenuation = _att;
				linear = _lin;
				quadratic = _qua;
			};

		};

		Renderer();
		~Renderer();

		void begin(Camera& camera);
		void end(Camera& cam);


		void render(Object* obj);

		Shader& getShader();

		void addLight(glm::vec3 pos, glm::vec3 color, float attenuation, float linear, float quadratic);

		private:

			GBuffer* gbuffer;

			void loadCamera(Camera& camera);

			void loadTrasnform(Transform& transform);

			std::vector<Object*> objects;
			std::vector<Lighto> lights;

			bool started = false;

			Shader shader;

	};

}