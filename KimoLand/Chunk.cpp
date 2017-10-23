#include "Chunk.h"

namespace Aiko {

	Chunk::Chunk(int x, int y)
		: x (x), y (y)
	{

		TerrainGenerator gen;

		Mesh* mesh = gen.generateTerrain(x, y, *this);

		this->getTransform().position.x = x * TERRAIN_SIZE;
		this->getTransform().position.z = y * TERRAIN_SIZE;

		this->addComponent( mesh ); 

	}


	Chunk::~Chunk()
	{

	}

}