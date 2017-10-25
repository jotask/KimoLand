#include "SphereCollider.h"


namespace Aiko {

	SphereCollider::SphereCollider(Object& obj, float rad)
		: ShapeCollider(obj)
		, radius(rad)
	{
		this->shape = new btSphereShape( btScalar( rad ) );
	}


	SphereCollider::~SphereCollider()
	{

	}

	void SphereCollider::update()
	{
	}

	void SphereCollider::render(Renderer & renderer)
	{
	}

}