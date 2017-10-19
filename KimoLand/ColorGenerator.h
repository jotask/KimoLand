#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

#include "definitions.h"

namespace Aiko {

	class ColorGenerator
	{
	public:
		ColorGenerator();
		~ColorGenerator();

		std::vector< std::vector<sf::Color> > generateColors( std::vector< std::vector<float> > heights, float amplitude );

	private:
		float spread;
		float halfSpread;

		std::vector<sf::Color> biomeColours;
		float part;

		float clamp(float value, float min, float max);

		sf::Color calculateColor( float height, float amplitude );

		sf::Color interpolateColor(sf::Color c1, sf::Color c2, float blend);


	};

}