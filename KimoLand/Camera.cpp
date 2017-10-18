#include "Camera.h"


namespace Aiko {

	Camera::Camera()
	{
		tranform.position.z = 3.0f;
	}


	Camera::~Camera()
	{
	}

	void Camera::update()
	{
		float radius = 10.0f;
		float camX = sin( clock.getElapsedTime().asSeconds() ) * radius;
		float camZ = cos(clock.getElapsedTime().asSeconds() ) * radius;
		// view = glm::lookAt(glm::vec3(camX, 0.0, camZ), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));
	}

	glm::mat4 Camera::getView()
	{
		return glm::lookAt( this->tranform.position, this->tranform.position + this->front, glm::vec3(0.0f, 1.0f, 0.0f));
	}

	glm::mat4 Camera::getProjection()
	{
		return glm::perspective(glm::radians(FOV), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);
	}

}