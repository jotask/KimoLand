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
		renderer.begin();
		renderer.loadCamera(cam);
		chunk.render(renderer);
		sun.render(renderer);
		renderer.end();
	}

}