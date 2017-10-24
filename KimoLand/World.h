#pragma once

#include <exception>

#include <btBulletDynamicsCommon.h>
#include <SFML/System.hpp>

#include "Object.h"

namespace Aiko {

	class Renderer;

	class World
	{
	public:
		World();
		~World();

		void update();
		void render(Renderer& renderer);

		void addObjectToWorld(Object& obj);
		void removeObjectFromWorld(Object& obj);

	private:

		btBroadphaseInterface* broadphase;
		btDefaultCollisionConfiguration* collisionConfig;
		btCollisionDispatcher* dispatcher;

		btSequentialImpulseConstraintSolver* solver;
		btDiscreteDynamicsWorld* world;

		sf::Clock clock;

	};

}