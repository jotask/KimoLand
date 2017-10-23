#include "Renderer.h"

namespace Aiko {

	Renderer::Renderer()
		: shader( Shader("terrainvertex.glsl", "terrainfragment.glsl") )
	{
	}


	Renderer::~Renderer()
	{
	}

	void Renderer::begin()
	{
		shader.start();
		shader.prepare();
		this->started = true;
	}

	void Renderer::end()
	{
		if (!this->started) {
			throw std::runtime_error("call begin before start");
		}

		/*
		for (unsigned int i = 0; i < this->objects.size(); i++)
		{
			// TODO add transform to the shader
			Object& obj = *(this->objects.at(i));
			Transform& transform = obj.getTransform();
			obj.render();
		}
		this->objects.clear();
		*/

		shader.end();
		this->started = false;
	}

	void Renderer::loadCamera(Camera & camera)
	{
		this->shader.setMat4("view", camera.getView());
		this->shader.setMat4("projection", camera.getProjection());
	}

	void Renderer::loadTrasnform(Transform & transform)
	{
		this->shader.setMat4("model", transform.getModel());
	}

	Shader& Renderer::getShader()
	{
		return this->shader;
	}

}