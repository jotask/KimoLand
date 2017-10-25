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

		template<typename Component, typename T>
		inline bool instanceof(const T *ptr) {
			return dynamic_cast<const Component*>(ptr) != nullptr;
		}

	protected:

		const std::string id;

		Object& obj;

	};

}