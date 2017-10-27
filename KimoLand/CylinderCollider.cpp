#include "CylinderCollider.h"

namespace Aiko {

	CylinderCollider::CylinderCollider(Object& obj)
		: ShapeCollider (obj)
	{
	}


	CylinderCollider::~CylinderCollider()
	{
	}

	Mesh * CylinderCollider::createMeshFromShape()
	{
		return nullptr;
	}

}