#pragma once

#include <LinearMath\btIDebugDraw.h>

#include "Camera.h"
#include "Shader.h"

#include <glm/glm.hpp>
#include <GL/glew.h>

#include <vector>

namespace Aiko {

	class PhysicRenderer : public btIDebugDraw
	{
	public:
		PhysicRenderer();
		~PhysicRenderer();

		struct _LINE 
		{
			glm::vec3 from;
			glm::vec3 to;

			_LINE(btVector3 a, btVector3 b)
			{
				from.x = a.x();
				from.y = a.y();
				from.z = a.z();

				to.x = b.x();
				to.y = b.y();
				to.z = b.z();
			}
		};

		struct _COLOR
		{
			glm::vec3 col;
			_COLOR(btVector3 c)
			{
				col.x = c.x();
				col.y = c.y();
				col.z = c.z();
			}
		};

		struct LINE {
			LINE(glm::vec3 a, glm::vec3 b, glm::vec3 color) : a(a), b(b), color(color) {};

			glm::vec3 a;
			glm::vec3 b;
			glm::vec3 color;
		};

		virtual void drawLine(const btVector3& from, const btVector3& to, const btVector3& color);

		virtual void drawContactPoint(const btVector3& PointOnB, const btVector3& normalOnB, btScalar distance, int lifeTime, const btVector3& color);

		virtual void reportErrorWarning(const char* warningString);

		virtual void draw3dText(const btVector3& location, const char* textString);

		virtual void setDebugMode(int debugMode);

		virtual int getDebugMode() const;

		void render(Camera& camera);

	private:

		Shader shader;

		int m_debugMode;

		std::vector<_LINE> lines;
		// std::vector<_COLOR> colors;

	};

}