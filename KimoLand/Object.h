#pragma once

#include <GL/glew.h>

namespace Aiko {

	class Object
	{
	public:
		Object();
		~Object();

		void render();
	private:

		GLuint vao;
		GLuint vbo;
		GLuint ebo;

	};

}