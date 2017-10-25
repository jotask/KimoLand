#include "RigidBody.h"


namespace Aiko {

	RigidBody::RigidBody(Object& obj, float _mass)
		: Component( Component::RIGIDBODY , obj )
	{
		if (!obj.containsComponent(Component::COLLIDER))
			throw std::runtime_error("component collision doesn't exist");

		btCollisionShape* shape = ((ShapeCollider*)(obj.getComponent(Component::COLLIDER)))->shape;

		btTransform t;
		t.setIdentity();
		t.setOrigin( btVector3(0, obj.getTransform().position.y, 0) );

		btDefaultMotionState* state = new btDefaultMotionState( t );

		//rigidbody is dynamic if and only if mass is non zero, otherwise static
		btScalar mass = btScalar(_mass);

		btVector3 fallIntertia( 0, 0, 0 );
		shape->calculateLocalInertia( mass, fallIntertia );
		btRigidBody::btRigidBodyConstructionInfo ci(mass, state, shape, fallIntertia);

		this->body = new btRigidBody(ci);

		Physics::getInstance().getWorld().addRigidBody(this->body);

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

	btRigidBody * RigidBody::getBodyinPhysics()
	{
		return this->body;
	}

}