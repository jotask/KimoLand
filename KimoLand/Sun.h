#pragma once

#include "SFML/System.hpp"

#include "Object.h"

#include "Mesh.h"
#include "Light.h"
#include "RigidBody.h"
#include "SphereCollider.h"

namespace Aiko {

	class Sun :
		public Object
	{
	public:
		Sun();
		~Sun();

		virtual void update();

		sf::Clock clock;

		RigidBody* body;

	};

}