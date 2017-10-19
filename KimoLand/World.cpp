#include "World.h"

namespace Aiko {

	World::World()
	{
		this->terrain = generator.generateTerrain();
	}


	World::~World()
	{
		delete terrain;
	}

	void World::render(Shader & shader)
	{
		shader.setObject(*terrain);
		terrain->render();
	}

}