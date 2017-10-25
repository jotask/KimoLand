#include "PhysicRenderer.h"



namespace Aiko {

	PhysicRenderer::PhysicRenderer()
		: shader( Shader("lineVertex.glsl", "lineFragment.glsl") ), m_debugMode( 0 )
	{
	}

	PhysicRenderer::~PhysicRenderer()
	{
		
	}

	void PhysicRenderer::drawLine(const btVector3 & from, const btVector3 & to, const btVector3 & color)
	{
		lines.push_back( _LINE(from, to) );
	}

	void PhysicRenderer::drawContactPoint(const btVector3 & PointOnB, const btVector3 & normalOnB, btScalar distance, int lifeTime, const btVector3 & color)
	{
	}

	void PhysicRenderer::reportErrorWarning(const char * warningString)
	{
		std::cout << "Physics debugger warning: " << warningString << std::endl;
	}

	void PhysicRenderer::draw3dText(const btVector3 & location, const char * textString)
	{
	}

	void PhysicRenderer::setDebugMode(int debugMode)
	{
		this->m_debugMode = debugMode;
	}

	int PhysicRenderer::getDebugMode() const
	{
		return this->m_debugMode;
	}

	void PhysicRenderer::render(Camera& camera)
	{
		
		if (!(lines.size() > 0)) 
		{
			return;
		}

		shader.start();

		GLuint vao;
		GLuint vbo;

		// create object
		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);

		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, lines.size() * sizeof(_LINE), lines.data(), GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(0);
		
		/*
		glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
		glBufferData(GL_ARRAY_BUFFER, colors.size() * sizeof(_COLOR), colors.data(), GL_STATIC_DRAW);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(1);
		*/

		glBindVertexArray(0);

		/// end create object

		// render object


		// Finally rendering

		// set projection and view
		shader.setMat4("view", camera.getView());
		shader.setMat4("projection", camera.getProjection());

		// modelova matice
		Transform t;
		shader.setMat4("model", t.getModel());

		//glBindBuffer(GL_ARRAY_BUFFER, 0);

		glBindVertexArray(vao);
		glEnableVertexAttribArray(0);
		glDrawArrays(GL_LINES, 0, lines.size() * 2);

		// std::cout << lines.size() << std::endl;

		lines.clear();
		//colors.clear();
		
		shader.end();

		glDeleteBuffers(1, &vbo);
		glDeleteBuffers(1, &vao);

	}

}