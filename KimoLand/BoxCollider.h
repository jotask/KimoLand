#pragma once

#include "ShapeCollider.h"

namespace Aiko {

	class BoxCollider : public ShapeCollider
	{
	public:
		BoxCollider(Object& oj, float width, float height, float depth);
		~BoxCollider();

		virtual void update();
		virtual void render(Renderer& renderer);
	};

}