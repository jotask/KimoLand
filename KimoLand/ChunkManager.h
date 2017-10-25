#pragma once

#include <vector>
#include <iostream>

#include "definitions.h"

#include "Chunk.h"

namespace Aiko {

	class Renderer;

	class ChunkManager
	{
	public:
		ChunkManager();
		~ChunkManager();

		void update();
		void render(Renderer& renderer);

	private:

		const unsigned int SIZE = CHUNK_MANAGER_SIZE;

		std::vector< Chunk* > chunks;
	};

}