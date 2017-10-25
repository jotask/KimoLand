#include "MeshCollider.h"


namespace Aiko {

	MeshCollider::MeshCollider(Object& obj)
		: Component("collider", obj)
	{
		btVector3 vertex1, vertex2, vertex3, vertex4;
		this->shape = new btTriangleMesh();

		for (int i = -250; i < 250; i = i + 10) {
			for (int j = -250; j < 250; j = j + 10) {

				vertex1 = btVector3(i, 0.0f, j);
				vertex2 = btVector3(i + 10.0f, 0.0f, j);
				vertex3 = btVector3(i + 10.0f, 0.0f, j + 10.0f);
				vertex4 = btVector3(i, 0.0f, j + 10.0f);

				this->shape->addTriangle(vertex1, vertex2, vertex3);
				this->shape->addTriangle(vertex1, vertex3, vertex4);
			}
		}

		btCollisionShape* collisionShapeTerrain = new btBvhTriangleMeshShape(this->shape, true);

		btDefaultMotionState* motionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, -15, 0)));

		btRigidBody::btRigidBodyConstructionInfo rigidBodyConstructionInfo(0.0f, motionState, collisionShapeTerrain, btVector3(0, 0, 0));
		btRigidBody* rigidBodyTerrain = new btRigidBody(rigidBodyConstructionInfo);
		rigidBodyTerrain->setFriction(btScalar(0.9));

		// m_dynamicsWorld->addRigidBody(rigidBodyTerrain);
	}


	MeshCollider::~MeshCollider()
	{

	}

	void MeshCollider::update()
	{
	}

	void MeshCollider::render(Renderer & renderer)
	{
	}

}