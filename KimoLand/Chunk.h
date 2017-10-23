#pragma once

#include "Object.h"
#include "Mesh.h"

#include "TerrainGenerator.h"

namespace Aiko {

	class Chunk : public Object
	{
	public:
		Chunk(int x, int y);
		~Chunk();

	private:

		int x;
		int y;

	};

}