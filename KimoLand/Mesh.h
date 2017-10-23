#pragma once

#include <iostream>
#include <vector>

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <SFML/Graphics.hpp>

#include "Component.h"

namespace Aiko {

	class Object;

	class Mesh : public Component
	{
	public:
		Mesh(Object& obj);
		~Mesh();

		static Mesh* createQuad(Object& obj);
		static Mesh* createCube(Object& obj);

		virtual void update();
		virtual void render(Renderer& renderer);

		void create(const std::vector<glm::vec3> vertices, const std::vector<glm::vec3> colours,
			const std::vector<GLuint> indices, const std::vector<glm::vec3> normals);
		 
	private:

		int size = 0;

		GLuint vao;
		GLuint vbo;
		GLuint vcolor;
		GLuint vnorm;
		GLuint ebo;

	};


}