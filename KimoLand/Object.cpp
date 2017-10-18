#include "Object.h"

namespace Aiko {

	Object::Object()
	{

		float vertices[] = {
			0.5f,  0.5f, 0.0f,  // top right
			0.5f, -0.5f, 0.0f,  // bottom right
			-0.5f, -0.5f, 0.0f,  // bottom left
			-0.5f,  0.5f, 0.0f   // top left 
		};

		float colors[] = {
			0.583f,  0.771f,  0.014f,
			0.609f,  0.115f,  0.436f,
			0.327f,  0.483f,  0.844f,
			0.822f,  0.569f,  0.201f
		};

		unsigned int indices[] = {  // note that we start from 0!
			0, 1, 3,  // first Triangle
			1, 2, 3   // second Triangle
		};

		// generate and get the buffer
		glGenVertexArrays(1, &vao);
		glGenBuffers(1, &vbo);
		glGenBuffers(1, &vcolor);
		glGenBuffers(1, &ebo);

		// Set colors

		// bind the Vertex Array Object first, then bind and set vertex buffer(s), and
		// then configure vertex attributes(s).
		glBindVertexArray(vao);

		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ARRAY_BUFFER, vcolor);
		glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

		glBindBuffer(GL_ARRAY_BUFFER, vcolor);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);

		glBindVertexArray(0);

	}

	Object::~Object()
	{
		glDeleteVertexArrays(1, &vao);
		glDeleteBuffers(1, &vbo);
		glDeleteBuffers(1, &ebo);
	}

	void Object::render()
	{
		glBindVertexArray(vao);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}

	Transform & Object::getTranform()
	{
		return this->transform;
	}

}