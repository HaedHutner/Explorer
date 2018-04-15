#include "TerrainTree.h"

TerrainTree::TerrainTree(TerrainGenerator* generator, glm::vec2 origin, float size, int depth)
	: generator(generator), root(generator, origin, size), mesh(depth * 5)
{

}

TerrainTree::Node::Node(TerrainGenerator* generator, const glm::vec2& origin, const float& size)
{
}

void TerrainTree::Node::update(Mesh & mesh)
{
}

void TerrainTree::Node::draw(int depth, const ShaderProgram & program)
{

}

Vertex & TerrainTree::Node::get_nw()
{
	// TODO: insert return statement here
}

Vertex & TerrainTree::Node::get_ne()
{
	// TODO: insert return statement here
}

Vertex & TerrainTree::Node::get_se()
{
	// TODO: insert return statement here
}

Vertex & TerrainTree::Node::get_sw()
{
	// TODO: insert return statement here
}

Vertex & TerrainTree::Node::get_center()
{
	// TODO: insert return statement here
}

glm::vec2 TerrainTree::Node::get_origin()
{
	return glm::vec2();
}

float TerrainTree::Node::get_size()
{
	return 0.0f;
}

TerrainTree::Node::~Node()
{
}

void TerrainTree::update()
{
}

void TerrainTree::draw(int depth, const ShaderProgram& program) 
{
	root.draw(depth, program);
}
