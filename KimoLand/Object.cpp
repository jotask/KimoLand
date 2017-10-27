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

	void Object::render()
	{
		for (auto const& comp : this->components)
			comp.second->render();
	}

	Transform & Object::getTransform()
	{
		return this->transform;
	}

	std::map<Component::Type, Component*>& Object::getComponents()
	{
		return this->components;
	}

	bool Object::containsComponent(Component::Type id)
	{
		return (this->components.find(id) != this->components.end());
	}

	Component * Object::getComponent(Component::Type id)
	{

		if (!this->containsComponent(id))
			throw std::runtime_error("Component doesn't exist");

		return  this->components.find(id)->second;

	}

	void Object::addComponent(Component* component)
	{
		// std::cout << component->getId() << std::endl;

		// Check if component already exist
		if (containsComponent(component->getId()))
		{
			// we already have this component
			throw std::runtime_error("Component already exist in this object");
		}

		std::pair<Component::Type, Component*> tmp = std::pair<Component::Type, Component*>(component->getId(), component);

		this->components.insert(tmp);

	}

}