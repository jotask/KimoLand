#pragma once

#include "Component.h"

#include "btBulletCollisionCommon.h"

namespace Aiko {

	class ShapeCollider : public Component
	{
	public:
		ShapeCollider(Object& obj);
		~ShapeCollider();

		btCollisionShape* shape;

	};

}