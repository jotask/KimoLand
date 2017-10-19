#pragma once

#include "Object.h"
#include "Mesh.h"

namespace Aiko {

	class Terrain : public Object
	{
	public:
		Terrain(Mesh& mesh);
		~Terrain();

		virtual void update() override;
		virtual void render() override;

	private:
		Mesh& mesh;
	};

}