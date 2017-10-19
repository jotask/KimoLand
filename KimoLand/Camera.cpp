#include "Camera.h"


namespace Aiko {

	Camera::Camera()
	{
		tranform.position.y = CAM_Y;
	}


	Camera::~Camera()
	{
	}

	void Camera::update()
	{
		if (!ROTATE) {
			return;
		}
		float radius = CAM_RADIUS;
		float camX = sin( clock.getElapsedTime().asSeconds() ) * radius;
		float camZ = cos(clock.getElapsedTime().asSeconds()) * radius;
		float camY = cos(clock.getElapsedTime().asSeconds()) * radius;
		this->tranform.position.x = camX;
		this->tranform.position.z = camZ;
		//this->tranform.position.y = camY;
	}

	void Camera::resize(unsigned int width, unsigned int height)
	{
		this->width = width;
		this->height = height;
	}

	glm::mat4 Camera::getView()
	{
		return glm::lookAt(this->tranform.position, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	}

	glm::mat4 Camera::getProjection()
	{
		return glm::perspective(glm::radians(FOV), ((float)this->width / (float)this->height), 0.1f, 1000.0f);
	}

}