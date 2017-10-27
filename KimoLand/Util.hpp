#pragma once
#include <algorithm>

namespace Aiko {

	class Util {
	public:

		static float clamp(float value, float min, float max)
		{
			return std::max(min, std::min(value, max));
		};

		static float map(float value, float istart, float istop, float ostart, float ostop)
		{
			return ostart + (ostop - ostart) * ((value - istart) / (istop - istart));
		}

	};

}