#pragma once

#include "ShapeCollider.h"

namespace Aiko {

	class CylinderCollider :
		public ShapeCollider
	{
	public:
		CylinderCollider(Object& obj);
		~CylinderCollider();

		virtual Mesh* createMeshFromShape();

	};

}