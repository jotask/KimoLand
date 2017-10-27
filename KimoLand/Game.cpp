#include "Game.h"

namespace Aiko {

	Game::Game()
	{
	}

	Game::~Game()
	{
	}

	void Game::update()
	{
		cam.update();
		chunk.update();

		sun.update();
	}

	void Game::render()
	{
		renderer.begin(cam);

		// renderer.loadCamera(cam);

		chunk.render(renderer);

		renderer.render(&sun);

		renderer.end(cam);

		if(DRAW_DEBUG)
			Physics::getInstance().render(cam);

	}

}