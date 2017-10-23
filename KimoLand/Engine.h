#pragma once

#include <iostream>

#include "Display.h"
#include "State.hpp"
#include "Game.h"

namespace Aiko {

	class Engine
	{
	public:
		Engine();
		~Engine();

		void run();

	private:

		Display window;

		IState* state;

		void init();

		void update();

		void render();

	};

}