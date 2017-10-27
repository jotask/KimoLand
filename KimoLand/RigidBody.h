#pragma once

#include <btBulletDynamicsCommon.h>

#include <exception>

#include "Physics.h"

#include "Component.h"
#include "ShapeCollider.h"
#include "Renderer.h"
#include "Object.h"

namespace Aiko {

	class RigidBody : public Component
	{
	public:
		RigidBody(Object& obj, float mass);
		~RigidBody();

		virtual void update();
		virtual void render();

		btRigidBody* getBodyinPhysics();

	private:

		btRigidBody* body;

	};

}