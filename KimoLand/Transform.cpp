#include "Transform.h"

namespace Aiko {

	Transform::Transform()
	{

	}

	Transform::~Transform()
	{

	}

	glm::mat4 Transform::getModel()
	{
		// TODO implement rotation and scale
		glm::mat4 model;
		model = glm::translate(model, position);
		return model;
	}

}