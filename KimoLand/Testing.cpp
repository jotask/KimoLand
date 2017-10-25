#include "Testing.h"

namespace Aiko {

	Testing::Testing()
	{
		btBoxShape* groundShape = new btBoxShape( btVector3( 5, 5, 5 ) );
		btSphereShape* ballShape = new btSphereShape( btScalar( 2 ) );

		// Orientation and Position of Ground
		btDefaultMotionState* groundMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, -3, 0)));
		btRigidBody::btRigidBodyConstructionInfo groundRigidBodyCI(0, groundMotionState, groundShape, btVector3(0, 0, 0));
		groundRigidBodyCI.m_restitution = 1.0f;
		this->ground = new btRigidBody(groundRigidBodyCI);
		//dynamicsWorld->addRigidBody(groundRigidBody);

		Physics::getInstance().getWorld().addRigidBody(ground);

		// Orientation and Position of Falling body
		btDefaultMotionState* fallMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(-1, 5, 0)));
		btScalar mass = 1;
		btVector3 fallInertia(0, 0, 0);
		ballShape->calculateLocalInertia(mass, fallInertia);
		btRigidBody::btRigidBodyConstructionInfo fallRigidBodyCI(mass, fallMotionState, ballShape, fallInertia);
		fallRigidBodyCI.m_restitution = 1.0f;
		this->ball = new btRigidBody(fallRigidBodyCI);
		//dynamicsWorld->addRigidBody(fallRigidBody);

		Physics::getInstance().getWorld().addRigidBody(ball);

		//bulletDebugugger.setDebugMode(btIDebugDraw::DBG_DrawWireframe);
		//dynamicsWorld->setDebugDrawer(&bulletDebugugger);

	}

	Testing::~Testing()
	{
	}

}