#include "Camera.h"


namespace Aiko {

	Camera::Camera()
	{
		tranform.position.z = 3.0f;
		tranform.position.y = 10.0f;
	}


	Camera::~Camera()
	{
	}

	void Camera::update()
	{
		float radius = 10.0f;
		float camX = sin( clock.getElapsedTime().asSeconds() ) * radius;
		float camZ = cos(clock.getElapsedTime().asSeconds()) * radius;
		float camY = cos(clock.getElapsedTime().asSeconds()) * radius;
		//this->tranform.position.x = camX;
		//this->tranform.position.z = camZ;
		//this->tranform.position.y = camY;
		// view = glm::lookAt(glm::vec3(camX, 0.0, camZ), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));
	}

	void Camera::resize(unsigned int width, unsigned int height)
	{
		this->width = width;
		this->height = height;
	}

	glm::mat4 Camera::getView()
	{
		//return glm::lookAt(this->tranform.position, this->tranform.position + this->front, glm::vec3(0.0f, 1.0f, 0.0f));
		return glm::lookAt(this->tranform.position, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	}

	glm::mat4 Camera::getProjection()
	{
		return glm::perspective(glm::radians(FOV), (float)this->width / (float)this->height, 0.1f, 100.0f);
	}

}