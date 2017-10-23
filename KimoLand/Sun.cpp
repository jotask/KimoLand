#include "Sun.h"

namespace Aiko {

	Sun::Sun()
	{

		this->getTransform().position.y = 100.0f;

		Mesh* mesh = Mesh::createCube(*this);
		this->addComponent( mesh );

		Light* light = new Light(*this);
		this->addComponent( light );

	}

	Sun::~Sun()
	{

	}

	void Sun::update()
	{
		float radius = 10.0f;
		float x = cos(clock.getElapsedTime().asSeconds()) * radius;
		float z = sin(clock.getElapsedTime().asSeconds()) * radius;
		this->getTransform().position.x = x;
		this->getTransform().position.z = z;
	}

}