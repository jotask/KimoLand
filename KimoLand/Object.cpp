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

	std::map<std::string, Component*>& Object::getComponents()
	{
		return this->components;
	}

	bool Object::containsComponent(std::string cmp)
	{
		return (this->components.find(cmp) != this->components.end());
	}

	Component * Object::getComponent(std::string id)
	{

		if (!this->containsComponent(id))
			throw std::runtime_error("Component doesn't exist");

		return  this->components.find(id)->second;

	}

	void Object::addComponent(Component* component)
	{
		std::cout << component->getId() << std::endl;


		// Check if component already exist
		if (containsComponent(component->getId()))
		{
			// we already have this component
			throw std::runtime_error("Component: " + component->getId() + " already exist in this object");
		}

		std::pair<std::string, Component*> tmp = std::pair<std::string, Component*>(component->getId(), component);

		this->components.insert(tmp);

	}

}