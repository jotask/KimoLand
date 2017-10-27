#include "MeshCollider.h"

namespace Aiko {

	MeshCollider::MeshCollider(Object& obj)
		: ShapeCollider(obj)
	{

		std::vector<glm::vec3>& vert = ((Mesh*)obj.getComponent(Component::MESH))->getVertices();
		std::vector<GLuint>& ind = ((Mesh*)obj.getComponent(Component::MESH))->getIndices();

		btVector3 vertex1, vertex2, vertex3, vertex4;
		this->shape = new btTriangleMesh();

		for (unsigned int i = 0; i < ind.size(); i+=3)
		{
			glm::vec3 a = vert.at(ind.at(i + 0));
			glm::vec3 b = vert.at(ind.at(i + 1));
			glm::vec3 c = vert.at(ind.at(i + 2));

			this->shape->addTriangle(
				btVector3(a.x, a.y, a.z),
				btVector3(b.x, b.y, b.z),
				btVector3(c.x, c.y, c.z)
			);

		}

		btCollisionShape* collisionShapeTerrain = new btBvhTriangleMeshShape(this->shape, true);

		btTransform t;
		t.setIdentity();
		Transform trans = obj.getTransform();
		t.setOrigin( btVector3( trans.position.x, -1.0f, trans.position.z) );

		btDefaultMotionState* motionState = new btDefaultMotionState( t );

		btRigidBody::btRigidBodyConstructionInfo rigidBodyConstructionInfo(0.0f, motionState, collisionShapeTerrain, btVector3(0, 0, 0));
		btRigidBody* rigidBodyTerrain = new btRigidBody(rigidBodyConstructionInfo);
		rigidBodyTerrain->setFriction(btScalar(0.9));

		Physics::getInstance().getWorld().addRigidBody(rigidBodyTerrain );

	}


	MeshCollider::~MeshCollider()
	{

	}

	Mesh * MeshCollider::createMeshFromShape()
	{
		return nullptr;
	}

}