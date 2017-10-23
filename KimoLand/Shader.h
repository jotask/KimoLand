#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "Camera.h"
#include "definitions.h"

namespace Aiko {

	class Shader
	{
	public:
		Shader();
		Shader(const std::string vertex_file, const std::string fragment_file);
		~Shader();

		void start();
		void end();

		void prepare();

		GLuint program;

		void bindAttribute(int attribute, std::string variablename);

		GLuint getLocation(const std::string name );

		void setMat4(const std::string name, const glm::mat4 mat);
		void setVec3(const std::string name, const glm::vec3 vec);

	};

}