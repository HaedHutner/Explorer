#include "TerrainTree.h"

TerrainTree::TerrainTree(TerrainGenerator * generator, Texture * texture, glm::vec2 origin, int size, float max_height)
	: Terrain(generator, texture), root(new TerrainChunk(origin, size, max_height))
{
	for (int i = 0; i < 8; i++) {
		root->split_chunk();
	}

	std::vector<Vertex> vertices;
	std::vector<GLuint> elements;

	root->generate_vertices(this->generator, vertices, elements);

	this->mesh = new Mesh(vertices, elements, texture);
}

void TerrainTree::tick()
{
}

void TerrainTree::draw(const ShaderProgram & program)
{
	this->mesh->draw(program);
}

TerrainTree::~TerrainTree() {
	delete root;
}
