#pragma once

#include "State.hpp"

#include "Physics.h"

#include "Renderer.h"
#include "Camera.h"
#include "ChunkManager.h"
#include "Sun.h"

#include "Testing.h"

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

		//ChunkManager chunk;
		//Sun sun;

		Testing tests;

	};

}