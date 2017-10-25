#pragma once

#include "Physics.h"

#include "btBulletDynamicsCommon.h"

namespace Aiko {

	class Testing
	{
	public:
		Testing();
		~Testing();

		// void update();
		// void render();

	private:

		btRigidBody* ground;

		btRigidBody* ball;

	};

}