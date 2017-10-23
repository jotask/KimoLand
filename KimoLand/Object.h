#pragma once

#include <iostream>

#include <map>
#include <exception>

#include "Renderer.h"

#include "Transform.h"
#include "Component.h"

namespace Aiko {

	class Object
	{
	public:
		Object();
		~Object();

		virtual void update();
		virtual void render(Renderer& renderer);

		Transform& getTransform();

	protected:

		void addComponent(Component* component);

	private:

		Transform transform;

		std::map<std::string, Component*> components;

	};

}