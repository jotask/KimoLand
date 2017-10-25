#pragma once

#include <exception>

#include <btBulletDynamicsCommon.h>
#include <SFML/System.hpp>

#include "Object.h"

namespace Aiko {

	class Renderer;

	class World
	{
	public:
		World();
		~World();

		void update();
		void render(Renderer& renderer);

	private:

	};

}