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
		virtual void render(Renderer& renderer);

		glm::vec3 color = glm::vec3(0.78f, 0.47f, 0.36f);

		glm::vec3 ambient;
		glm::vec3 diffuse;
		glm::vec3 specular;
		
		const int id;

	};

}