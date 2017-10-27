#pragma once

#include "ShapeCollider.h"

namespace Aiko {

	class BoxCollider : public ShapeCollider
	{
	public:
		BoxCollider(Object& oj, float width, float height, float depth);
		~BoxCollider();

		virtual Mesh* createMeshFromShape() override;

	};

}