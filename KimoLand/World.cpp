#include "World.h"

namespace Aiko {

	World::World()
	{
		this->terrain = generator.generateTerrain();
		this->light.transform.position.y = 3.0f;
	}

	World::~World()
	{
		delete terrain;
	}

	void World::update()
	{
		float radius = 4.0f;
		float camX = sin(clock.getElapsedTime().asSeconds()) * radius;
		float camZ = cos(clock.getElapsedTime().asSeconds()) * radius;
		float camY = cos(clock.getElapsedTime().asSeconds()) * radius;
		//this->light.position.x = camX;
		//this->light.position.z = camZ;
	}

	void World::render(Shader & shader)
	{

		shader.setLight(light);
		shader.setObject(light);
		light.render();

		shader.setObject(*terrain);
		terrain->render();
	}

}