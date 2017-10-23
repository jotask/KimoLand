#pragma once

namespace Aiko {

	class IState
	{
	public:
		virtual ~IState() {}

		virtual void update() = 0;
		virtual void render() = 0;

	};

}