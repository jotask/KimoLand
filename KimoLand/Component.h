#pragma once

namespace Aiko {

	class Component
	{
	public:
		Component();
		~Component();

		virtual void update() = 0;
		virtual void render() = 0;

	};

}