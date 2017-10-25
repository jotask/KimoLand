#pragma once
#include "Component.h"
#include "Object.h"
#include "Renderer.h"

#include "btBulletCollisionCommon.h"
#include "btBulletDynamicsCommon.h"

namespace Aiko {

	class MeshCollider : public Component
	{
	public:
		MeshCollider(Object& obj);
		~MeshCollider();

		virtual void update();
		virtual void render(Renderer& renderer);

	private:

		btTriangleMesh* shape;

	};

}