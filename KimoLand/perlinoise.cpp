#include "perlinoise.h"

namespace Aiko {
	
	PerlinNoise::PerlinNoise()
		: seed(rand() % 1000000000), octaves(OCTAVES), amplitude(AMPLITUDE), roughness(ROUGHNESS)
	{

	}
	
	PerlinNoise::PerlinNoise(int seed)
		: seed(seed), octaves(OCTAVES), amplitude(AMPLITUDE), roughness(ROUGHNESS)
	{

	}
	
	PerlinNoise::PerlinNoise(int octaves, float amplitude, float roughness)
		: seed(rand() % 1000000000), octaves(octaves), amplitude(amplitude), roughness(roughness)
	{

	}
	
	PerlinNoise::PerlinNoise(int seed, int octaves, float amplitude, float roughness)
		: seed(seed), octaves(octaves), amplitude(amplitude), roughness(roughness)
	{

	}

	PerlinNoise::~PerlinNoise()
	{
	}

	float PerlinNoise::getNoise(int x, int y)
	{
		srand(x * 49632 + y * 325176 + seed);
		return rand() * 2.0f - 1.0f;
	}

	float PerlinNoise::getPerlinNoise(int x, int y)
	{
		float total = 0.0f;
		float d = pow( 2, octaves - 1 );
		for (int i = 0; i < octaves; i++)
		{
			float freq = ( pow( 2, i ) / d );
			float amp = pow( roughness, i ) * amplitude;
			total += getInterpolatedNoise( x * freq, y * freq ) * amp;
		}
		return total;
	}

	float PerlinNoise::getSmoothNoise(int x, int y)
	{
		float corners = (getNoise(x - 1, y - 1) + getNoise(x + 1, y - 1) + getNoise(x - 1, y + 1) +
			getNoise(x + 1, y + 1)) / 16.0f;

		float sides = ( getNoise( x - 1, y ) + getNoise( x+ 1, y ) + getNoise( x, y - 1 ) + getNoise( x, y + 1) ) / 8.0f;
		float center = getNoise( x, y );
		return corners + sides + center;
	}

	float PerlinNoise::getInterpolatedNoise(float x, float y)
	{
		int intX = x;
		int intY = y;

		float fractX = x - intX;
		float fractY = y - intY;

		float v1 = getSmoothNoise(intX, intY);
		float v2 = getSmoothNoise(intX + 1, intY);
		float v3 = getSmoothNoise(intX, intY + 1);
		float v4 = getSmoothNoise(intX + 1 , intY + 1);

		float i1 = interpolate(v1, v2, fractX);
		float i2 = interpolate(v3, v4, fractY);

		return interpolate(i1, i2, fractY);

	}

	float PerlinNoise::interpolate(float a, float b, float blend)
	{
		// ADD define for pi
		double theta = blend * 3.14159265358979323846;
		float f = (1.0f - cos(theta)) * 0.5f;
		return a * (1 - f) + b * f;
	}

}