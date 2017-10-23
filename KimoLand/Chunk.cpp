#include "Chunk.h"

namespace Aiko {

	Chunk::Chunk()
	{

		TerrainGenerator gen;

		Mesh* mesh = gen.generateTerrain(0, 0, *this);
		this->addComponent( mesh ); 
	}


	Chunk::~Chunk()
	{

	}

}