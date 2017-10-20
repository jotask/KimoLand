#pragma once

#include "Shader.h"
#include "Terrain.h"
#include "Mesh.h"
#include "TerrainGenerator.h"
#include "Light.h"

#include <SFML/System.hpp>

namespace Aiko {

	class World
	{
	public:
		World();
		~World();

		void update();
		void render(Shader & shader);

	private:

		Aiko::TerrainGenerator generator;
		Aiko::Terrain* terrain;

		Aiko::Light light;

		sf::Clock clock;

	};

}