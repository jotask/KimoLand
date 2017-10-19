#include "ColorGenerator.h"

namespace Aiko {

	ColorGenerator::ColorGenerator()
		:biomeColours( {
				sf::Color(201, 178, 99),
				sf::Color(135, 184, 82),
				sf::Color(80, 171, 93),
				sf::Color(120, 120, 120),
				sf::Color(200, 200, 200),
			}
		), spread(COLOUR_SPREAD), halfSpread( COLOUR_SPREAD / 2.0f ), part ( 1.0f / (biomeColours.size() - 1) )
	{
	}

	ColorGenerator::~ColorGenerator()
	{
	}

	std::vector<std::vector<sf::Color>> ColorGenerator::generateColors(std::vector<std::vector<float>> heights, float amplitude)
	{
		std::vector<std::vector<sf::Color>> colors(heights.size(), std::vector<sf::Color>(heights[0].size()));

		for (int z = 0; z < heights.size(); z++)
		{
			for (int x = 0; x < heights[z].size(); x++)
			{
				colors[z][x] = calculateColor(heights[z][x], amplitude);
			}
		}
		return colors;
	}


	float ColorGenerator::clamp(float value, float min, float max)
	{
		return std::max(min, std::min(value, max));
	}

	sf::Color ColorGenerator::calculateColor(float height, float amplitude)
	{
		float value = ( height + amplitude ) / ( amplitude * 2.0f );
		value = clamp(( value - halfSpread ) * ( 1.0f / spread ) , 0.0f, 0.9999f);
		int firstBiome = floor( value / part );
		float blend = ( value - ( firstBiome * part ) ) / part;
		return interpolateColor(biomeColours[firstBiome], biomeColours[firstBiome + 1], blend);
	}

	sf::Color ColorGenerator::interpolateColor(sf::Color c1, sf::Color c2, float blend)
	{
		float color1Weight = 1 - blend;
		float r = ( color1Weight * c1.r ) + ( blend * c2.r );
		float g = ( color1Weight * c1.g ) + ( blend * c2.g );
		float b = ( color1Weight * c1.b ) + ( blend * c2.b );
		sf::Color color (r, g, b);
		return color;
	}

}