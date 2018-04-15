#include "TerrainChunk.h"

TerrainChunk::TerrainChunk( TerrainGenerator* generator, glm::vec2 origin, float initial_depth, float size, float height) 
	: mesh(generator, initial_depth)
{

}