#pragma once

#include <glm/glm.hpp>

#include "Component.h"

namespace Aiko {

	class Object;

	class Light : public Component
	{
	public:
		Light(Object& obj);
		~Light();

		static int NUMBER_LIGTHS;

		virtual void update();
		virtual void render();

		// glm::vec3 color = glm::vec3(0.78f, 0.47f, 0.36f);
		glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f);

		float attenuation = 1.0f;
		float linear = 0.7f;
		float quadratic = 1.8f;
		
		const int id;

	};

}