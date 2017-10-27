#include "SphereCollider.h"


namespace Aiko {

	SphereCollider::SphereCollider(Object& obj, float rad)
		: ShapeCollider(obj)
		, radius(rad)
	{
		this->shape = new btSphereShape( btScalar( rad ) );
	}


	SphereCollider::~SphereCollider()
	{

	}

	Mesh * SphereCollider::createMeshFromShape()
	{

		return nullptr;
	}

}