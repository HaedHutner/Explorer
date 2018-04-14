#include "TerrainTree.h"

TerrainTree::TerrainTree(TerrainGenerator* generator, glm::vec2 origin, float size, int depth) 
	: generator(generator)
{

}

void TerrainTree::Node::draw(int depth, const ShaderProgram & program)
{
}
