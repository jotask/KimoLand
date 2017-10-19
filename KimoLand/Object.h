#pragma once

#include "Transform.h"
#include "Mesh.h"

namespace Aiko {

	class Object
	{
	public:
		Object();
		~Object();

		Transform& getTranform();

		virtual void update() = 0;
		virtual void render() = 0;

	protected:

		Transform transform;

	};

}