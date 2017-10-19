#include "Mesh.h"

namespace Aiko {

	Mesh::Mesh()
	{
	}

	Mesh::~Mesh()
	{
		glDeleteVertexArrays(1, &vao);
		glDeleteBuffers(1, &vbo);
		glDeleteBuffers(1, &vcolor);
		glDeleteBuffers(1, &ebo);
	}

	Mesh* Mesh::createQuad()
	{

		const std::vector<glm::vec3> vertices{
			glm::vec3(0.5f,  0.5f, 0.0f),  // top right
			glm::vec3(0.5f, -0.5f, 0.0f),  // bottom right
			glm::vec3(-0.5f, -0.5f, 0.0f),  // bottom left
			glm::vec3(-0.5f,  0.5f, 0.0f)   // top left 
		};

		const std::vector<glm::vec3> colors{
			glm::vec3(0.583f,  0.771f,  0.014f),
			glm::vec3(0.609f,  0.115f,  0.436f),
			glm::vec3(0.327f,  0.483f,  0.844f),
			glm::vec3(0.822f,  0.569f,  0.201f)
		};

		const std::vector<GLuint> indices{  // note that we start from 0!
			0, 1, 3,  // first Triangle
			1, 2, 3   // second Triangle
		};

		// TODO change this by using a shared pointer maybe
		// needs to do more research

		Mesh* mesh = new Mesh();
		mesh->create(vertices, colors, indices);

		return mesh;

	}

	void Mesh::create(const std::vector<glm::vec3> vertices, const std::vector<glm::vec3> colors, const std::vector<GLuint> indices)
	{

		this->size = indices.size();

		// generate and get the buffer
		glGenVertexArrays(1, &vao);
		glGenBuffers(1, &vbo);
		glGenBuffers(1, &vcolor);
		glGenBuffers(1, &ebo);

		// bind the Vertex Array Object first, then bind and set vertex buffer(s), and
		// then configure vertex attributes(s).
		glBindVertexArray(vao);

		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, 3 * vertices.size() * sizeof(GLfloat), vertices.data(), GL_STATIC_DRAW);

		glBindBuffer(GL_ARRAY_BUFFER, vcolor);
		glBufferData(GL_ARRAY_BUFFER, 3 * colors.size() * sizeof(GLfloat), colors.data(), GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), &indices.front(), GL_STATIC_DRAW);

		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

		glBindBuffer(GL_ARRAY_BUFFER, vcolor);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);

		glBindVertexArray(0);

	}

	void Mesh::render()
	{
		glBindVertexArray(vao);
		glDrawElements(GL_TRIANGLES, size, GL_UNSIGNED_INT, 0);

	}

}