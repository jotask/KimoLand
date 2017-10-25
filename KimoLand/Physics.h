#pragma once

#include "SFML/System/Clock.hpp"

#include "btBulletCollisionCommon.h"
#include "btBulletDynamicsCommon.h"
#include "LinearMath/btIDebugDraw.h"

#include "PhysicRenderer.h"

#include <iostream>
#include "Renderer.h"
#include "glm/glm.hpp"

#include "Camera.h"

namespace Aiko {

	class Physics
	{
	public:
		static Physics& getInstance()
		{
			static Physics instance; // Guaranteed to be destroyed.
									 // Instantiated on first use.
			return instance;
		}

		// delete copy constructor and equal operator for this class
		// make sure that this class is a singleton
		Physics(Physics const&) = delete;
		void operator=(Physics const&) = delete;


		void update();
		void render(Camera& cam);

		btDiscreteDynamicsWorld& getWorld();

	private:
		Physics();
		~Physics();

		btBroadphaseInterface* broadphase;
		btDefaultCollisionConfiguration* collisionConfig;
		btCollisionDispatcher* dispatcher;

		btSequentialImpulseConstraintSolver* solver;
		btDiscreteDynamicsWorld* world;

		PhysicRenderer* debug;

		sf::Clock clock;

	};

}