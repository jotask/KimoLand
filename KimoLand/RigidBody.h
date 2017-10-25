#pragma once

#include <btBulletDynamicsCommon.h>

#include <exception>

#include "Physics.h"

#include "Component.h"
#include "Renderer.h"
#include "Object.h"

namespace Aiko {

	class RigidBody : public Component
	{
	public:
		RigidBody(Object& obj);
		~RigidBody();

		virtual void update();
		virtual void render(Renderer& renderer);

	private:

		btRigidBody* body;

	};

}