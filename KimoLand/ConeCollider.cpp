#include "ConeCollider.h"

namespace Aiko {

	ConeCollider::ConeCollider(Object& obj)
		: ShapeCollider(obj)
	{

	}

	ConeCollider::~ConeCollider()
	{

	}

	Mesh * ConeCollider::createMeshFromShape()
	{
		return nullptr;
	}

}