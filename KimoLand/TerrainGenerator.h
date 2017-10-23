#pragma once

#include <vector>
#include <iostream>

#include "definitions.h"
#include "perlin.hpp"
#include "ColorGenerator.h"
#include "Mesh.h"

#include "Util.hpp"

namespace Aiko {

	class Object;

	struct MeshData {
		std::vector<glm::vec3> vertices;
		std::vector<glm::vec3> colors;
		std::vector<glm::vec3> normals;
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

		Mesh* generateTerrain(int x, int y, Object& obj);

	private:

		void addTriangle(MeshData& data, int a, int b, int c);

		void calculateNormals(MeshData&data);

		glm::vec3 calculateNormal(glm::vec3 a, glm::vec3 b, glm::vec3 c);

	};

}