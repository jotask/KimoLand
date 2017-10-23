#include "ColorGenerator.h"

namespace Aiko {

	ColorGenerator::ColorGenerator()
		:biomeColours( {
			glm::vec3(0.79f, 0.7, 0.39),
			glm::vec3(0.53f, 0.72f, 0.32f),
			glm::vec3(0.31f, 0.67f, 0.36f),
			glm::vec3(0.47f, 0.47f, 0.47f),
			glm::vec3(0.78f, 0.78f, 0.78f)
			}
		), spread(COLOUR_SPREAD), halfSpread( COLOUR_SPREAD / 2.0f ), part ( 1.0f / (biomeColours.size() - 1) )
	{
	}

	ColorGenerator::~ColorGenerator()
	{
	}

	glm::vec3 ColorGenerator::calculateColor(float height, float amplitude)
	{
		float value = ( height + amplitude ) / ( amplitude * 2.0f );
		value = Util::clamp(( value - halfSpread ) * ( 1.0f / spread ) , 0.0f, 0.9999f);
		value = height;
		float tmp = floor( value / part );
		int firstBiome = ( (int) tmp );
		float blend = ( value - ( firstBiome * part ) ) / part;
		return biomeColours[firstBiome];
		//return interpolateColor(biomeColours[firstBiome], biomeColours[firstBiome + 1], blend);
	}

	glm::vec3 ColorGenerator::interpolateColor(glm::vec3 c1, glm::vec3 c2, float blend)
	{
		float color1Weight = 1 - blend;
		float r = ( color1Weight * c1.r ) + ( blend * c2.r );
		float g = ( color1Weight * c1.g ) + ( blend * c2.g );
		float b = ( color1Weight * c1.b ) + ( blend * c2.b );
		glm::vec3 color (r, g, b);
		return color;
	}

}