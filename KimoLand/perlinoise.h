#pragma once

#include <random>
#include <math.h>

#include "definitions.h"

namespace Aiko {

	class PerlinNoise {
	public:
		PerlinNoise();
		PerlinNoise(int seed);
		PerlinNoise(int octaves, float amplitude, float roughness);
		PerlinNoise(int seed, int octaves, float amplitude, float roughness);
		~PerlinNoise();

		float getNoise(int x, int y);
		float getPerlinNoise(int x, int y);
		float getSmoothNoise(int x, int y);

	private:
		int seed;
		float roughness;
		int octaves;
		float amplitude;

		float getInterpolatedNoise(float x, float y);
		float interpolate(float a, float b, float blend);

	};

}