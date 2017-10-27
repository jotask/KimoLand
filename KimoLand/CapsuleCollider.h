#pragma once
#include "ShapeCollider.h"

namespace Aiko {

	class CapsuleCollider : public ShapeCollider
	{
	public:
		CapsuleCollider(Object& obj);
		~CapsuleCollider();

		virtual Mesh* createMeshFromShape();

	};

}