#pragma once

#include "Component.h"

#include "Mesh.h"

#include "btBulletCollisionCommon.h"

namespace Aiko {

	class ShapeCollider : public Component
	{
	public:
		ShapeCollider(Object& obj);
		~ShapeCollider();

		virtual void update();
		virtual void render();

		btCollisionShape* shape;

		virtual Mesh* createMeshFromShape() = 0;

	};

}