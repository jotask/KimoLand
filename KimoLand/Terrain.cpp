#include "Terrain.h"

namespace Aiko {

	Terrain::Terrain(Mesh& mesh)
		:mesh( mesh )
	{

	}

	Terrain::~Terrain()
	{
		delete &mesh;
	}

	void Terrain::update()
	{
	}

	void Terrain::render()
	{
		mesh.render();
	}

}