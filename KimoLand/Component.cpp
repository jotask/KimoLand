#include "Component.h"

namespace Aiko {

	Component::Component(std::string id, Object& obj)
		: id(id), obj( obj )
	{

	}


	Component::~Component()
	{

	}

	std::string Component::getId()
	{
		return this->id;
	}

}