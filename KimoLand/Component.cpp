#include "Component.h"

namespace Aiko {

	Component::Component(Type id, Object& obj)
		: id(id), obj( obj )
	{

	}


	Component::~Component()
	{

	}

	Component::Type Component::getId()
	{
		return this->id;
	}

}