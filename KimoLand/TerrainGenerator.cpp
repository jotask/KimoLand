#include "TerrainGenerator.h"

namespace Aiko {

	TerrainGenerator::TerrainGenerator() { }
	TerrainGenerator::~TerrainGenerator() { }

	Terrain * TerrainGenerator::generateTerrain()
	{
		int width = TERRAIN_SIZE + 1;
		int height = TERRAIN_SIZE + 1;

		float topLeftX = (width - 1) / -2.0f;
		float topLeftZ = (height - 1) / -2.0f;

		siv::PerlinNoise noise;

		ColorGenerator color;

		MeshData data(width, height);

		int vertexIndex = 0;

		const double fx = width / FREQUENCY;
		const double fy = height / FREQUENCY;

		for (int y = 0; y < height; y++) 
		{
			for (int x = 0; x < height; x++)
			{

				float h = (float) noise.octaveNoise0_1(x / fx, y / fy, OCTAVES);

				data.colors[vertexIndex] = color.calculateColor(h, 1.0f);

				h = Util::map(h, 0.0f, 1.0f, 0.0f, 10.0f);

				data.vertices[vertexIndex] = glm::vec3(topLeftX + x, h, topLeftZ + y);

				if ((x < (width - 1)) && (y < (height - 1)))
				{
					addTriangle(data, vertexIndex, vertexIndex + width + 1, vertexIndex + width);
					addTriangle(data, vertexIndex + width + 1, vertexIndex, vertexIndex + 1);
				}

				vertexIndex++;
			}
		}

		Mesh* mesh = new Mesh();

		mesh->create(data.vertices, data.colors, data.triangles);

		Terrain* terrain = new Terrain(*mesh);

		return terrain;
	}

	void TerrainGenerator::addTriangle(MeshData & data, int a, int b, int c)
	{
		data.triangles[data.triangleIndex + 0] = a;
		data.triangles[data.triangleIndex + 1] = b;
		data.triangles[data.triangleIndex + 2] = c;
		data.triangleIndex += 3;
	}

}