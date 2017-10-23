#include "Engine.h"

namespace Aiko {

	Engine::Engine()
	{
	}

	Engine::~Engine()
	{
		delete state;
	}

	void Engine::run()
	{
		this->init();
		while (this->window.isOpen()) {

			this->window.pollEvents();

			this->update();
			this->render();

			// swap buffers
			this->window.swap();

		}
	}

	void Engine::init()
	{
		this->window.init();

		this->state = new Game();
	}

	void Engine::update()
	{
		this->state->update();
	}

	void Engine::render()
	{
		this->state->render();
	}

}