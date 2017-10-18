#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Aiko {

	class Transform
	{
	public:
		Transform();
		~Transform();

		glm::vec3 position = glm::vec3();
		glm::vec3 rotation = glm::vec3();
		glm::vec3 scale = glm::vec3();

		glm::mat4 getModel();

	};

}