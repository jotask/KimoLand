#include "World.h"

namespace Aiko {

	World::World()
	{
		this->broadphase = new btDbvtBroadphase();

		this->collisionConfig = new btDefaultCollisionConfiguration();
		this->dispatcher = new btCollisionDispatcher(collisionConfig);

		this->solver = new btSequentialImpulseConstraintSolver;

		this->world = new btDiscreteDynamicsWorld(dispatcher, broadphase, solver, collisionConfig);

		this->world->setGravity(btVector3(0, -9.8, 0));

	}


	World::~World()
	{
		delete this->world;
		delete this->solver;
		delete this->collisionConfig;
		delete this->dispatcher;
		delete this->broadphase;
	}

	void World::update()
	{
		sf::Time t = clock.restart();
		this->world->stepSimulation( t.asSeconds() );
	}

	void World::render(Renderer & renderer)
	{

	}

	void World::addObjectToWorld(Object & obj)
	{
		if (!obj.containsComponent("rigidbody"))
		{
			throw std::runtime_error("component doesn't exist on this object");
		}
		else {
			// TODO add object to world
		}
	}

	void World::removeObjectFromWorld(Object & obj)
	{
		// todo remove object from world
	}

}