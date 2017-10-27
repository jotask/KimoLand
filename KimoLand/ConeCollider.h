#pragma once

#include "ShapeCollider.h"

namespace Aiko {

	class ConeCollider : public ShapeCollider
	{
	public:
		ConeCollider(Object& obj);
		~ConeCollider();

		virtual Mesh* createMeshFromShape();

	};

}