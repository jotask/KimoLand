#pragma once

#include "SFML/System.hpp"

#include "Object.h"

#include "Mesh.h"
#include "Light.h"

namespace Aiko {

	class Sun :
		public Object
	{
	public:
		Sun();
		~Sun();

		virtual void update();

		sf::Clock clock;

	};

}