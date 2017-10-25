#include "Testing.h"

namespace Aiko {

	Testing::Testing()
	{
		btBoxShape* groundShape = new btBoxShape( btVector3( 5, 5, 5 ) );
		btSphereShape* ballShape = new btSphereShape( btScalar( 2 ) );

		// Orientation and Position of Ground
		btTransform tGround;
		tGround.setIdentity();
		tGround.setOrigin(btVector3(0, 0, 0));
		btDefaultMotionState* groundMotionState = new btDefaultMotionState(tGround);
		btRigidBody::btRigidBodyConstructionInfo groundRigidBodyCI(0, groundMotionState, groundShape, btVector3(0, 0, 0));
		groundRigidBodyCI.m_restitution = 1.0f;
		this->ground = new btRigidBody(groundRigidBodyCI);

		Physics::getInstance().getWorld().addRigidBody(ground);

		// Orientation and Position of Falling body

		btTransform tBall;
		tBall.setIdentity();
		tBall.setOrigin(btVector3(0, 20, 0));

		btDefaultMotionState* fallMotionState = new btDefaultMotionState(tBall);
		btScalar mass = 100;
		btVector3 fallInertia(0, 0, 0);
		ballShape->calculateLocalInertia(mass, fallInertia);
		btRigidBody::btRigidBodyConstructionInfo fallRigidBodyCI(mass, fallMotionState, ballShape, fallInertia);
		fallRigidBodyCI.m_restitution = 1.0f;
		this->ball = new btRigidBody(fallRigidBodyCI);

		Physics::getInstance().getWorld().addRigidBody(ball);


	}

	Testing::~Testing()
	{
		
	}

}