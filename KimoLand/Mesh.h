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
		static Mesh* createSphere(Object& obj);

		virtual void update();
		virtual void render();

		void create(const std::vector<glm::vec3> vertices, const std::vector<glm::vec3> colours,
			const std::vector<GLuint> indices, const std::vector<glm::vec3> normals);


		std::vector<glm::vec3>& getVertices();
		std::vector<GLuint>& getIndices();
		 
	private:

		int size = 0;

		std::vector<glm::vec3> vertices;
		std::vector<GLuint> indices;

		static const std::vector<glm::vec3> calculateNormals(const std::vector<glm::vec3> vert, const std::vector<GLuint> ind);


		GLuint vao;
		GLuint vbo;
		GLuint vcolor;
		GLuint vnorm;
		GLuint ebo;

	};


}