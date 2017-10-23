#pragma once

#include "State.hpp"

#include "Renderer.h"
#include "Camera.h"
#include "Chunk.h"
#include "Sun.h"

namespace Aiko {

	class Game : public IState
	{
	public:
		Game();
		~Game();

		virtual void update();
		virtual void render();

	private:

		Renderer renderer;

		Camera cam;

		Chunk chunk;
		Sun sun;

	};

}