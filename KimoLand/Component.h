#pragma once

#include <string>

#include "Renderer.h"

namespace Aiko {

	class Object;

	class Component
	{
	public:
		Component(std::string id, Object& obj);
		~Component();

		virtual void update() = 0;
		virtual void render(Renderer& renderer) = 0;

		std::string getId();

	protected:

		const std::string id;

		Object& obj;

	};

}