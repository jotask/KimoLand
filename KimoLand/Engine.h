#pragma once

#include <iostream>

#include "Physics.h"

#include "Display.h"
#include "State.hpp"
#include "Game.h"

namespace Aiko {

	class Engine
	{
	public:

		static Engine& getInstance(){
			static Engine instance;
			return instance;
		}

		Engine(Engine const&) = delete;
		void operator=(Engine const&) = delete;

		Engine();
		~Engine();

		void run();

	private:

		Display window;

		Physics* physics;

		IState* state;

		void init();

		void update();

		void render();

	};

}