#include "Light.h"
#include "Object.h"

namespace Aiko {

	int Light::NUMBER_LIGTHS = 0;

	Light::Light(Object& obj)
		: Component(Component::LIGHT, obj)
		, id(NUMBER_LIGTHS++)
	{

	}

	Light::~Light()
	{

	}

	void Light::update()
	{
	}

	void Light::render(Renderer& renderer)
	{
		Shader& s = renderer.getShader();

		s.setVec3("lightPos", this->obj.getTransform().position);
		s.setVec3("lightColor", this->color);

	}

}