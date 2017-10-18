#include <iostream>
#include <GL/glew.h>
#include <SFML/Window.hpp>

#include "definitions.h"

#include "Shader.h"
#include "Camera.h"
#include "Object.h"

int main()
{

	sf::ContextSettings settings;
	settings.depthBits = 24;
	settings.stencilBits = 8;
	settings.majorVersion = 3;
	settings.minorVersion = 3;
	settings.attributeFlags = sf::ContextSettings::Core;

	sf::Window window;
	window.create(sf::VideoMode(WIDTH, HEIGHT, 32), "openGL", sf::Style::Default, settings);

	glewExperimental = GLU_TRUE;

	if (GLEW_OK != glewInit())
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		return EXIT_FAILURE;
	}

	Aiko::Camera cam;

	Aiko::Shader shader("basicvertex.glsl", "basicfragment.glsl");
	shader.use();

	Aiko::Object obj;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:
					window.close();
					break;
			}
		}

		cam.update();

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		shader.use();
		shader.setCamera(cam);

		// Draw code
		shader.setObject(obj);
		obj.render();

		window.display();

	}

	return EXIT_SUCCESS;
	
}