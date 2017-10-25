#include "Engine.h"

namespace Aiko {

	Engine::Engine()
	{
	}

	Engine::~Engine()
	{
		// TODO make sure this method it's called
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

		Physics::getInstance();

		this->state = new Game();
	}

	void Engine::update()
	{
		Physics::getInstance().update();
		this->state->update();
	}

	void Engine::render()
	{
		this->state->render();
	}

}