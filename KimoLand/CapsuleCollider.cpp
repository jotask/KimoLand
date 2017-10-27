#include "CapsuleCollider.h"

namespace Aiko {

	CapsuleCollider::CapsuleCollider(Object& obj)
		: ShapeCollider(obj)
	{
	}


	CapsuleCollider::~CapsuleCollider()
	{
	}

	Mesh * CapsuleCollider::createMeshFromShape()
	{
		return nullptr;
	}

}