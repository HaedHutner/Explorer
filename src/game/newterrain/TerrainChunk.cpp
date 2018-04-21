#include "TerrainChunk.h"

TerrainChunk::TerrainChunk( TerrainGenerator* generator, glm::vec2 origin, float initial_depth, float size) 
	: mesh(new TerrainTree(generator, origin, size, initial_depth))
{

}

void TerrainChunk::tick()
{
}

void TerrainChunk::draw(int lod_level, const ShaderProgram & program)
{
	mesh->draw(lod_level, program);
}

TerrainChunk::~TerrainChunk() {
	delete mesh;
}