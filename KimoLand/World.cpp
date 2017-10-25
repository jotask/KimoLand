#include "World.h"

namespace Aiko {

	World::World()
	{

	}


	World::~World()
	{
		
	}

	void World::update()
	{
		
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