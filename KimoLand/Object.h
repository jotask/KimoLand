#pragma once

#include "Transform.h"

namespace Aiko {

	class Object
	{
	public:
		Object();
		~Object();

		Transform& getTranform();

		virtual void update() = 0;
		virtual void render() = 0;

		Transform transform;

	};

}