#pragma once
#include "ShapeCollider.h"
#include "Object.h"
#include "Renderer.h"
#include "Mesh.h"
#include "Physics.h"
#include "definitions.h"

#include "btBulletCollisionCommon.h"
#include "btBulletDynamicsCommon.h"

namespace Aiko {

	class MeshCollider : public ShapeCollider
	{
	public:
		MeshCollider(Object& obj);
		~MeshCollider();

		virtual Mesh* createMeshFromShape() override;

	private:

		btTriangleMesh* shape;

	};

}