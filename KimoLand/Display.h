#pragma once

#include <exception>

#include <GL/glew.h>
#include <SFML/Window.hpp>

#include "definitions.h"

namespace Aiko {

	class Display
	{
	public:
		Display();
		~Display();

		void init();

		void pollEvents();

		bool isOpen();

		void swap();

	private:
		sf::Window window;
	};

}