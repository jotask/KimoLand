#pragma once

#include <string>

namespace Aiko {

	class Renderer;
	class Object;

	class Component
	{
	public:

		enum Type {
			LIGHT,MESH, COLLIDER, RIGIDBODY
		};

		Component(Type id, Object& obj);
		~Component();

		virtual void update() = 0;
		virtual void render() = 0;

		Type getId();

		template<typename Component, typename T>
		inline bool instanceof(const T *ptr) {
			return dynamic_cast<const Component*>(ptr) != nullptr;
		}

	protected:

		const Type id;

		Object& obj;

	};

}