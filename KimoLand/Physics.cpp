#include "Physics.h"


namespace Aiko {

	Physics::Physics()
	{

		this->broadphase = new btDbvtBroadphase();

		this->collisionConfig = new btDefaultCollisionConfiguration();
		this->dispatcher = new btCollisionDispatcher(collisionConfig);

		this->solver = new btSequentialImpulseConstraintSolver;

		this->world = new btDiscreteDynamicsWorld(dispatcher, broadphase, solver, collisionConfig);

		this->world->setGravity(btVector3(0, -9.8, 0));

		this->debug = new PhysicRenderer();
		this->debug->setDebugMode(btIDebugDraw::DBG_DrawWireframe);

		this->world->setDebugDrawer(this->debug);
	}

	Physics::~Physics()
	{

		// TODO make sure this method it's called

		delete this->world;
		delete this->solver;
		delete this->collisionConfig;
		delete this->dispatcher;
		delete this->broadphase;

	}

	void Physics::update()
	{
		sf::Time t = clock.restart();
		this->world->stepSimulation(t.asSeconds());
	}

	void Physics::render(Camera& camera)
	{
		this->world->debugDrawWorld();
		this->debug->render(camera);

		// std::cout << this->world->getNumCollisionObjects() << std::endl;

	}

	btDiscreteDynamicsWorld & Physics::getWorld()
	{
		return *this->world;
	}

}