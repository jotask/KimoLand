#include "BoxCollider.h"

namespace Aiko {

	BoxCollider::BoxCollider(Object& oj, float width, float height, float depth)
		: ShapeCollider(obj)
	{
		this->shape = new btBoxShape(btVector3(width, height, depth));
	}

	BoxCollider::~BoxCollider()
	{
	}

	void BoxCollider::update()
	{

	}

	void BoxCollider::render(Renderer & renderer)
	{

	}

}