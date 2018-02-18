#include "TerrainChunk.h"

TerrainChunk::TerrainChunk(int size, float min_height, float max_height)
	: size(size), split(false), min_height(min_height), max_height(max_height)
{
	for (int i = 0; i < 4; i++) {
		children[i] = NULL;
	}
}

void TerrainChunk::draw(const ShaderProgram & program)
{
	if (is_split()) {
		for (int i = 0; i < 4; i++) {
			children[i]->draw(program);
		}
		return;
	}

	mesh->draw(program);
}

void TerrainChunk::split()
{
	for (int i = 0; i < 4; i++) {
		children[i] = new TerrainChunk(size);
	}

	this->split = true;
}

bool TerrainChunk::is_split() 
{
	return split;
}

void TerrainChunk::join()
{
}

TerrainChunk::~TerrainChunk()
{
	for (int i = 0; i < 4; i++) {
		delete children[i];
		children[i] = NULL;
	}
}
