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

		virtual void update();
		virtual void render(Renderer& renderer);

	private:
		float radius;

	};

}