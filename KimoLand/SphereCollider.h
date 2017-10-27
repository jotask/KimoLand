#pragma once

#include "ShapeCollider.h"
#include "Object.h"

#include "btBulletCollisionCommon.h"

namespace Aiko {

	class SphereCollider : public ShapeCollider
	{
	public:
		SphereCollider(Object& obj, float radious);
		~SphereCollider();

		virtual Mesh* createMeshFromShape();

	private:
		float radius;

	};

}