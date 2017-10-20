#pragma once

#include <glm/glm.hpp>

#include "Mesh.h"
#include "Object.h"

namespace Aiko {

	class Light : public Object
	{
	public:
		Light();
		~Light();

		virtual void update() override;
		virtual void render() override;

		glm::vec3 color;

		Mesh* mesh;

	};

}