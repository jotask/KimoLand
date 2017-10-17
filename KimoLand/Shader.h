#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <GL\glew.h>

namespace Aiko {

	class Shader
	{
	public:
		Shader(const std::string vertex_file, const std::string fragment_file);
		~Shader();

		void use();
		void unuse();

	private:
		GLuint program;
	};

}