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

				//h = Util::map(h, 0.0f, 1.0f, 0.0f, 10.0f);

				data.vertices[vertexIndex] = glm::vec3(topLeftX + x, h, topLeftZ + y);

				if ((x < (width - 1)) && (y < (height - 1)))
				{
					addTriangle(data, vertexIndex, vertexIndex + width + 1, vertexIndex + width);
					addTriangle(data, vertexIndex + width + 1, vertexIndex, vertexIndex + 1);
				}

				vertexIndex++;
			}
		}

		calculateNormals(data);

		std::cout << data.vertices.size() << " : " << data.triangles.size() << " : " << data.normals.size() << std::endl;

		Mesh* mesh = new Mesh();

		mesh->create(data.vertices, data.colors, data.triangles, data.normals);

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

	void TerrainGenerator::calculateNormals(MeshData & data)
	{
		for (int i = 0; i < data.triangles.size(); i += 3)
		{
			glm::vec3 a = data.vertices.at( data.triangles.at( i + 0 ) );
			glm::vec3 b = data.vertices.at( data.triangles.at( i + 1 ) );
			glm::vec3 c = data.vertices.at( data.triangles.at( i + 2 ) );
			glm::vec3 norm = calculateNormal( a, b, c );
			data.normals.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
		}
	}

	glm::vec3 TerrainGenerator::calculateNormal(glm::vec3 a, glm::vec3 b, glm::vec3 c)
	{
		glm::vec3 normal;

		glm::vec3 tmp1 = b - a;
		glm::vec3 tmp2 = c - a;

		normal = glm::cross( tmp1, tmp2 );
		normal = glm::normalize(normal);

		return normal;
	}

}