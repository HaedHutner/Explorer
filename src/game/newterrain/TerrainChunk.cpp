#include "TerrainChunk.h"

TerrainChunk::TerrainChunk( TerrainGenerator* generator, glm::vec2 origin, float initial_depth, float size) 
	: mesh(new TerrainTree(generator, origin, size, initial_depth))
{

}

TerrainChunk::~TerrainChunk() {
	delete mesh;
}