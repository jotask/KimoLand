#pragma once

#include <vector>

#include <glm/glm.hpp>

#include "Util.hpp"

#include "definitions.h"

namespace Aiko {

	class ColorGenerator
	{
	public:
		ColorGenerator();
		~ColorGenerator();

		float spread;
		float halfSpread;

		std::vector<glm::vec3> biomeColours;
		float part;

		glm::vec3 calculateColor( float height, float amplitude );

		glm::vec3 interpolateColor(glm::vec3 c1, glm::vec3 c2, float blend);


	};

}