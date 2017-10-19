#pragma once

#include <vector>
#include <iostream>

#include "definitions.h"
#include "Terrain.h"
#include "Mesh.h"

namespace Aiko {

	struct MeshData {
		std::vector<glm::vec3> vertices;
		std::vector<glm::vec3> colors;
		std::vector<GLuint> triangles;
		int triangleIndex;
		MeshData(int width, int height)
			: vertices(std::vector<glm::vec3>(width * height)),
			colors(std::vector<glm::vec3>(width * height)),
			triangles (std::vector<GLuint>( ( width - 1 ) * ( height - 1 ) * 6 )),
			triangleIndex(0)
		{

		}

	};

	class TerrainGenerator
	{
	public:
		TerrainGenerator();
		~TerrainGenerator();

		Terrain* generateTerrain();

		void addTriangle(MeshData& data, int a, int b, int c);

	};

}