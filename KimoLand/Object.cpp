#include "Object.h"

namespace Aiko {

	Object::Object()
	{
	}


	Object::~Object()
	{
		for (auto const& comp : this->components)
		{
			delete comp.second;
		}
	}

	void Object::update()
	{
		for (auto const& comp : this->components)
			comp.second->update();
	}

	void Object::render(Renderer& renderer)
	{
		renderer.loadTrasnform(this->transform);
		for (auto const& comp : this->components)
			comp.second->render(renderer);
	}

	Transform & Object::getTransform()
	{
		return this->transform;
	}

	void Object::addComponent(Component* component)
	{
		// Check if component already exist
		if (!(this->components.find(component->getId()) == this->components.end()))
		{
			// we already have this component
			throw std::runtime_error("Component: " + component->getId() + " already exist in this object");
		}

		std::pair<std::string, Component*> tmp = std::pair<std::string, Component*>(component->getId(), component);

		this->components.insert(tmp);

	}

}