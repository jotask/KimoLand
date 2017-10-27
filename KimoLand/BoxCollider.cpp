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

	Mesh * BoxCollider::createMeshFromShape()
	{

		btVector3 extend = ((btBoxShape*) this->shape)->getHalfExtentsWithoutMargin();

		return nullptr;
	}

}