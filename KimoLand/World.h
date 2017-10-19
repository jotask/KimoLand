#pragma once

#include "Shader.h"
#include "Terrain.h"
#include "Mesh.h"
#include "TerrainGenerator.h"

namespace Aiko {

	class World
	{
	public:
		World();
		~World();

		void render(Shader & shader);

	private:

		Aiko::TerrainGenerator generator;
		Aiko::Terrain* terrain;

	};

}