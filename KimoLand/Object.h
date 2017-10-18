#pragma once

#include <GL/glew.h>

#include "Transform.h"

namespace Aiko {

	class Object
	{
	public:
		Object();
		~Object();

		void render();

		Transform& getTranform();

	private:

		GLuint vao;
		GLuint vbo;
		GLuint ebo;

		Transform transform;

	};

}