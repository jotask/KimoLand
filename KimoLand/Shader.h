#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "Camera.h"
#include "Object.h"
#include "definitions.h"

namespace Aiko {

	class Shader
	{
	public:
		Shader(const std::string vertex_file, const std::string fragment_file);
		~Shader();

		void use();
		void unuse();

		void setCamera(Aiko::Camera& cam);
		void setObject(Aiko::Object& obj);


	private:
		GLuint program;

		GLuint getLocation(const std::string name );

		void setMat4(const std::string name, const glm::mat4 mat);

	};

}