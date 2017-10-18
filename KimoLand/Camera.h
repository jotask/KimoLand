#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <SFML/System.hpp>

#include "definitions.h"
#include "Transform.h"

namespace Aiko {

	class Camera
	{
	public:
		Camera();
		~Camera();

		void update();

		glm::mat4 getView();
		glm::mat4 getProjection();

	private:
		
		Transform tranform;

		glm::vec3 target = glm::vec3( 0.0f, 0.0f, 0.0f );
		glm::vec3 dir = glm::normalize( tranform.position - target );

		glm::vec3 right = glm::vec3( glm::normalize( glm::cross(glm::vec3(0.0f, 1.0f, 0.0f), dir) ) );

		glm::vec3 up = glm::cross( dir, right );

		glm::vec3 front = glm::vec3(0.0f, 0.0f, -1.0f);

		/*
		glm::mat4 view = glm::lookAt(
			glm::vec3( 0.0f, 0.0f, 3.0f ), // position
			glm::vec3( 0.0f, 0.0f, 0.0f ), // target
			glm::vec3( 0.0f, 1.0f, 0.0f )  // up
		);
		*/

		sf::Clock clock;


	};

}