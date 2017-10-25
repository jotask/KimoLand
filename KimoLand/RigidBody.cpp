#include "RigidBody.h"


namespace Aiko {

	RigidBody::RigidBody(Object& obj)
		: Component( "rigidbody", obj )
	{
		if (!obj.containsComponent("collision"))
			throw std::runtime_error("component collision doesn't exist");

		// get collision shape
		Component* coll = obj.getComponent("collision");

		btCollisionShape* shape = new btSphereShape( 1 );

		btTransform t;
		t.setIdentity();
		t.setOrigin( btVector3(0, 0, 0) );

		btDefaultMotionState* state = new btDefaultMotionState( t );

		//rigidbody is dynamic if and only if mass is non zero, otherwise static
		btScalar mass = 1;

		btVector3 fallIntertia( 0, 0, 0 );
		shape->calculateLocalInertia( mass, fallIntertia );
		btRigidBody::btRigidBodyConstructionInfo ci(mass, state, shape, fallIntertia);

		this->body = new btRigidBody(ci);

		// TODO add to the world

	}


	RigidBody::~RigidBody()
	{
		// TODO delete from world
		Physics::getInstance().getWorld().removeRigidBody(this->body);
		delete this->body->getMotionState();
		delete this->body;
	}

	void RigidBody::update()
	{

	}

	void RigidBody::render(Renderer & renderer)
	{

	}

}