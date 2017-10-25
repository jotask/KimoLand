#include "Sun.h"

namespace Aiko {

	Sun::Sun()
	{

		this->getTransform().position.y = 30.0f;

		Mesh* mesh = Mesh::createCube(*this);
		this->addComponent( mesh );

		Light* light = new Light(*this);
		this->addComponent( light );

		SphereCollider* coll = new SphereCollider(*this, 1.0f);
		this->addComponent(coll);

		this->body = new RigidBody(*this, 1.0f);
		this->addComponent(this->body);

	}

	Sun::~Sun()
	{

	}

	void Sun::update()
	{
		/*
		float radius = 10.0f;
		float x = cos(clock.getElapsedTime().asSeconds()) * radius;
		float z = sin(clock.getElapsedTime().asSeconds()) * radius;
		this->getTransform().position.x = x;
		this->getTransform().position.z = z;
		*/
		btTransform transform;
		this->body-> getBodyinPhysics() -> getMotionState()->getWorldTransform(transform);

		glm::vec3 p = this->getTransform().position;
		p.x = transform.getOrigin().x();
		p.y = transform.getOrigin().y();
		p.z = transform.getOrigin().z();
		this->getTransform().position = p;

		//transform.setPosition(new_position);
		//this->body->getMotionState()->setWorldTransform(transform);
	}

}