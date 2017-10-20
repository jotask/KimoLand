#include "Light.h"

namespace Aiko {

	Light::Light()
	{
		mesh = Mesh::createCube();

	}

	Light::~Light()
	{

	}

	void Light::update()
	{
	}

	void Light::render()
	{
		this->mesh->render();
	}

}