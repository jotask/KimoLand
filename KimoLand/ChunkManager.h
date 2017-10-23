#pragma once

#include <vector>
#include <iostream>

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

		const unsigned int SIZE = 3 * 3;

		std::vector< Chunk* > chunks;
	};

}