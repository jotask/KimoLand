#include "Mesh.h"

namespace Aiko {

	Mesh::Mesh(Object& obj)
		: Component (Component::MESH, obj)
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

	Mesh * Mesh::createSphere(Object & obj)
	{
		
		const float X = .525731112119133606f;
		const float Z = .850650808352039932f;
		const float N = 0.f;

		const std::vector<glm::vec3> vertices{
			glm::vec3(-X, N, Z),
			glm::vec3(X, N, Z),
			glm::vec3(-X, N, -Z),
			glm::vec3(X, N, -Z),

			glm::vec3(N, Z, X),
			glm::vec3(N, Z, -X),
			glm::vec3(N, -Z, X),
			glm::vec3(N, -Z, -X),

			glm::vec3(Z, X , N),
			glm::vec3(-Z, X, N),
			glm::vec3(Z, -X, N),
			glm::vec3(-Z, -X, N)
		};


		std::cout << "created vert" << std::endl;

		const std::vector<glm::vec3> colors{
			glm::vec3(0.583f,  0.771f,  0.014f),
			glm::vec3(0.609f,  0.115f,  0.436f),
			glm::vec3(0.327f,  0.483f,  0.844f),
			glm::vec3(0.822f,  0.569f,  0.201f),
			glm::vec3(0.583f,  0.771f,  0.014f),
			glm::vec3(0.609f,  0.115f,  0.436f),
			glm::vec3(0.327f,  0.483f,  0.844f),
			glm::vec3(0.822f,  0.569f,  0.201f),
			glm::vec3(0.583f,  0.771f,  0.014f),
			glm::vec3(0.609f,  0.115f,  0.436f),
			glm::vec3(0.327f,  0.483f,  0.844f),
			glm::vec3(0.822f,  0.569f,  0.201f)
		};

		std::cout << "created color" << std::endl;

		const std::vector<GLuint> indices{
			0,4,1,
			0,9,4,
			9,5,4,
			4,5,8,
			4,8,1,
			8,10,1,
			8,3,10,
			5,3,8,
			5,2,3,
			2,7,3,
			7,10,3,
			7,6,10,
			7,11,6,
			11,0,6,
			0,1,6,
			6,1,10,
			9,0,11,
			9,11,2,
			9,2,5,
			7,2,11
		};

		std::cout << "created ind" << std::endl;

		const std::vector<glm::vec3> normals = calculateNormals(vertices, indices);

		std::cout << "created" << std::endl;

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
		return this->vertices;
	}

	std::vector<GLuint>& Mesh::getIndices()
	{
		return this->indices;
	}

	const std::vector<glm::vec3> Mesh::calculateNormals(std::vector<glm::vec3> vert, std::vector<GLuint> ind)
	{
		std::vector<glm::vec3> normals;

		std::cout << "v: " << vert.size() << " i: " << ind.size() << std::endl;

		for (unsigned int i = 0; i < ind.size(); i+=3)
		{

			std::cout << "i: " << i << " : " << i + 1 << " : " << i +1 << std::endl;

			glm::vec3 a = vert.at(i+0);
			glm::vec3 b = vert.at(i+1);
			glm::vec3 c = vert.at(i+2);

			std::cout << "called" << std::endl;
			
			glm::vec3 normal;

			glm::vec3 tmp1 = b - a;
			glm::vec3 tmp2 = c - a;

			normal = glm::cross(tmp1, tmp2);
			normal = glm::normalize(normal);

			normals.push_back(normal);

		}

		std::cout << "finished and returning" << std::endl;

		return normals;
	}

	void Mesh::render()
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