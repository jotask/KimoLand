#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

#include <glm/glm.hpp>

#include "definitions.h"

namespace Aiko {

	class ColorGenerator
	{
	public:
		ColorGenerator();
		~ColorGenerator();

		glm::vec3 generateColor(float height);

		float spread;
		float halfSpread;

		std::vector<sf::Color> biomeColours;
		float part;

		float clamp(float value, float min, float max);

		sf::Color calculateColor( float height, float amplitude );

		sf::Color interpolateColor(sf::Color c1, sf::Color c2, float blend);


	};

}