#include "Mesh.h"

namespace Aiko {

	Mesh::Mesh(Object& obj)
		: Component ("mesh", obj)
	{
	}

	Mesh::~Mesh()
	{
		glDeleteVertexArrays(1, &vao);
		glDeleteBuffers(1, &vbo);
		glDeleteBuffers(1, &vcolor);
		glDeleteBuffers(1, &ebo);
	}

	Mesh* Mesh::createQuad(Object& obj)
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
		
		const std::vector<glm::vec3> normals{
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

		Mesh* mesh = new Mesh(obj);
		mesh->create(vertices, colors, indices, normals);

		return mesh;

	}

	Mesh * Mesh::createCube(Object& obj)
	{

		const std::vector<glm::vec3> vertices{
			glm::vec3(0.5f,  0.5f, 0.5f),  // top right
			glm::vec3(0.5f, -0.5f, 0.5f),  // bottom right
			glm::vec3(-0.5f, -0.5f, 0.5f),  // bottom left
			glm::vec3(-0.5f,  0.5f, 0.5f),   // top left 

			glm::vec3(0.5f,  0.5f, -0.5f),  // top right
			glm::vec3(0.5f, -0.5f, -0.5f),  // bottom right
			glm::vec3(-0.5f, -0.5f, -0.5f),  // bottom left
			glm::vec3(-0.5f,  0.5f, -0.5f)   // top left 
		};

		const std::vector<glm::vec3> colors{
			glm::vec3(0.583f,  0.771f,  0.014f),
			glm::vec3(0.609f,  0.115f,  0.436f),
			glm::vec3(0.327f,  0.483f,  0.844f),
			glm::vec3(0.822f,  0.569f,  0.201f),
			glm::vec3(0.583f,  0.771f,  0.014f),
			glm::vec3(0.609f,  0.115f,  0.436f),
			glm::vec3(0.327f,  0.483f,  0.844f),
			glm::vec3(0.822f,  0.569f,  0.201f)
		};

		const std::vector<glm::vec3> normals{
			glm::vec3(0.583f,  0.771f,  0.014f),
			glm::vec3(0.609f,  0.115f,  0.436f),
			glm::vec3(0.327f,  0.483f,  0.844f),
			glm::vec3(0.822f,  0.569f,  0.201f),
			glm::vec3(0.583f,  0.771f,  0.014f),
			glm::vec3(0.609f,  0.115f,  0.436f),
			glm::vec3(0.327f,  0.483f,  0.844f),
			glm::vec3(0.609f,  0.115f,  0.436f),
			glm::vec3(0.327f,  0.483f,  0.844f),
			glm::vec3(0.609f,  0.115f,  0.436f),
			glm::vec3(0.327f,  0.483f,  0.844f),
			glm::vec3(0.822f,  0.569f,  0.201f)
		};

		const std::vector<GLuint> indices{  // note that we start from 0!
			//Front
			0, 1, 3,
			1, 2, 3,

			// Right
			4, 5, 0,
			5, 1, 0,

			// Back
			7, 6, 4,
			6, 5, 4,

			// Left
			3, 2, 7,
			2, 6, 7,

			// Bottom
			1, 5, 2,
			5, 6, 2,

			// Top
			4, 0, 7,
			0, 3, 7

		};

		// TODO change this by using a shared pointer maybe
		// needs to do more research

		Mesh* mesh = new Mesh(obj);
		mesh->create(vertices, colors, indices, normals);

		return mesh;
	}

	void Mesh::update()
	{
	}

	void Mesh::create(const std::vector<glm::vec3> vertices, const std::vector<glm::vec3> colors,
		const std::vector<GLuint> indices, const std::vector<glm::vec3> normals)
	{

		this->vertices = vertices;
		this->indices = indices,
		this->size = indices.size();

		// generate ,get and bind the buffer
		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);

		// store vertex
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, 3 * vertices.size() * sizeof(GLfloat), vertices.data(), GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		// store color
		glGenBuffers(1, &vcolor);
		glBindBuffer(GL_ARRAY_BUFFER, vcolor);
		glBufferData(GL_ARRAY_BUFFER, 3 * colors.size() * sizeof(GLfloat), colors.data(), GL_STATIC_DRAW);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		// normals color
		glGenBuffers(1, &vnorm);
		glBindBuffer(GL_ARRAY_BUFFER, vnorm);
		glBufferData(GL_ARRAY_BUFFER, 3 * normals.size() * sizeof(GLfloat), normals.data(), GL_STATIC_DRAW);
		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		// Indices
		glGenBuffers(1, &ebo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(),GL_STATIC_DRAW);

		glBindVertexArray(0);

	}

	std::vector<glm::vec3>& Mesh::getVertices()
	{
		// TODO: insert return statement here
		return this->vertices;
	}

	std::vector<GLuint>& Mesh::getIndices()
	{
		return this->indices;
	}

	void Mesh::render(Renderer& renderer)
	{

		glBindVertexArray(vao);

		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glEnableVertexAttribArray(2);

		glDrawElements(GL_TRIANGLES, size, GL_UNSIGNED_INT, 0);

		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		glDisableVertexAttribArray(2);

		glBindVertexArray(0);
	}

}