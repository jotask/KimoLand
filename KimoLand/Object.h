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
		std::map<Component::Type, Component*>& getComponents();

		bool containsComponent(Component::Type cmp);

		Component* getComponent(Component::Type id);

	protected:

		void addComponent(Component* component);

	private:

		Transform transform;

		std::map<Component::Type, Component*> components;

	};

}