#pragma once

#include <iostream>
#include <vector>

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <SFML/Graphics.hpp>

#include "Component.h"

namespace Aiko {

	class Mesh
	{
	public:
		Mesh();
		~Mesh();

		static Mesh* createQuad();
		static Mesh* createCube();

		void create(const std::vector<glm::vec3> vertices, const std::vector<glm::vec3> colours,
			const std::vector<GLuint> indices, const std::vector<glm::vec3> normals);

		void render();
		 
	private:

		int size = 0;

		GLuint vao;
		GLuint vbo;
		GLuint vcolor;
		GLuint vnorm;
		GLuint ebo;

	};


}