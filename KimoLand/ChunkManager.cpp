#include "ChunkManager.h"

namespace Aiko {

	ChunkManager::ChunkManager()
	{

		const int half = SIZE / 2;

		for (int i = -half; i <= half; i++)
		{
			for (int j = -half; j <= half; j++)
			{
				this->chunks.push_back( new Chunk(j, i) );
			}
		}
	}

	ChunkManager::~ChunkManager()
	{
		for (unsigned int i = 0; i < chunks.size(); i++)
			delete this->chunks.at(i);
	}

	void ChunkManager::update()
	{
		for (unsigned int i = 0; i < chunks.size(); i++)
			this->chunks.at(i)->update();
	}

	void ChunkManager::render(Renderer & renderer)
	{
		for (unsigned int i = 0; i < chunks.size(); i++)
			renderer.render(this->chunks.at(i));
	}

}