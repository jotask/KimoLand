#include "Display.h"

namespace Aiko {

	Display::Display()
	{
	}

	Display::~Display()
	{
	}

	void Display::init()
	{
		sf::ContextSettings settings;
		settings.depthBits = 24;
		settings.stencilBits = 8;
		settings.majorVersion = 3;
		settings.minorVersion = 3;
		settings.attributeFlags = sf::ContextSettings::Core;

		this->window.create(sf::VideoMode(WIDTH, HEIGHT, 32), "openGL", sf::Style::Default, settings);
		this->window.setVerticalSyncEnabled(true);

		glewExperimental = GLU_TRUE;

		if (GLEW_OK != glewInit())
		{
			//std::cout << "Failed to initialize GLEW" << std::endl;
			throw std::runtime_error("Failed to initialize GLEW");
			//return EXIT_FAILURE;
		}

	}

	void Display::pollEvents()
	{
		sf::Event event;
		while (this->window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				this->window.close();
				break;
			case sf::Event::Resized:
				//cam.resize(event.size.width, event.size.height);
				break;
			}
		}
	}

	bool Display::isOpen()
	{
		return this->window.isOpen();
	}

	void Display::swap()
	{
		this->window.display();
	}

}