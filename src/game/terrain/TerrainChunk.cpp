#include "TerrainChunk.h"

TerrainChunk::TerrainChunk(TerrainGenerator* generator, glm::vec2 center, int size, float min_height, float max_height)
	: generator(generator), center(center), size(size), split(false), min_height(min_height), max_height(max_height)
{
	for (int i = 0; i < 4; i++) {
		children[i] = NULL;
	}

	std::vector<Vertex> vertices = std::vector<Vertex>(size ^ 2);
	std::vector<GLuint> elements = std::vector<GLuint>(size * 6);

	generate_vertices(vertices, elements, 256, 1);

	this->mesh = new Mesh(vertices, elements, new SimpleTexture("resources/textures/terrain.bmp"));
}

void TerrainChunk::tick()
{
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

void TerrainChunk::split_chunk()
{
	/*
	=========
	| 1 | 0 |
	=========
	| 2 | 3 |
	=========
	*/
	if (children[0] == NULL) children[0] = new TerrainChunk(generator, glm::vec2(center.x + 0.25f * size, center.y + 0.25f * size), size / 2, min_height, max_height);
	if (children[1] == NULL) children[1] = new TerrainChunk(generator, glm::vec2(center.x - 0.25f * size, center.y + 0.25f * size), size / 2, min_height, max_height);
	if (children[2] == NULL) children[2] = new TerrainChunk(generator, glm::vec2(center.x - 0.25f * size, center.y - 0.25f * size), size / 2, min_height, max_height);
	if (children[3] == NULL) children[3] = new TerrainChunk(generator, glm::vec2(center.x + 0.25f * size, center.y - 0.25f * size), size / 2, min_height, max_height);

	this->split = true;
}

bool TerrainChunk::is_split() 
{
	return split;
}

void TerrainChunk::join_chunk()
{
	this->split = false;
}

void TerrainChunk::generate_vertices(std::vector<Vertex>& vertices, std::vector<GLuint>& elements, int texture_resolution, int resolution)
{
	glm::vec2 begin = { center.x - size/2, center.y - size/2 };

	int width = size;
	int height = size;

	float tX = 0.0f;
	float tY = height * texture_resolution;

	int i = 0;
	int j = 0;

	int lastZ = begin.y;

	int beginX = begin.x;
	int beginY = begin.y;

	for (int i = 0; i < vertices.size(); i++) {

		int x = (i % width + beginX) * resolution;

		x == beginX ? tX = 0.0f : tX += 1.0f * texture_resolution; // for every increase in x, increase tX, and reset tX to 0 when x = 0

		int z = (i / width + beginY) * resolution;

		if (z != lastZ) { // for every increase in z, decrease tY
			tY -= 1.0f * texture_resolution;
			lastZ += resolution;
		}

		const float y = min_height + max_height * generator->get_height(x, z);
		vertices[i].xyz = { x, y, z };
		vertices[i].uv = { tX, tY };

		if (z == beginY * resolution || x == beginX * resolution) {
			// a vertex with either z or x equaling their beginning values is missing neighboring vertices requried to construct the quad
			// just add vertex to vertices vector and continue
			continue;
		}

		if (z != beginY * resolution && x != beginX * resolution) {
			// movement on both axis
			// there are vertices prior to this one on the row
			// there is at least 1 row above this one
			// there is enough information to construct a quad
			// generate this vertex, find indices of other 3 vertices, calculate normals and save their indices

			const int e[4] = {
				i - height - 1,	// upper - left
				i - 1,			// left
				i - height,		// up
				i				// this
			};

			Vertex* v1 = &vertices[e[0]];
			Vertex* v2 = &vertices[e[1]];
			Vertex* v3 = &vertices[e[2]];
			Vertex* v4 = &vertices[e[3]];

			MathUtils::calc_normal(v1, v2->xyz, v3->xyz);
			MathUtils::calc_normal(v2, v1->xyz, v3->xyz);
			MathUtils::calc_normal(v3, v2->xyz, v4->xyz);
			MathUtils::calc_normal(v4, v2->xyz, v3->xyz);

			elements[j + 0] = e[0];
			elements[j + 1] = e[1];
			elements[j + 2] = e[2];
			elements[j + 3] = e[2];
			elements[j + 4] = e[1];
			elements[j + 5] = e[3];

			j += 6;
		}
	}

}

TerrainChunk::~TerrainChunk()
{
	for (int i = 0; i < 4; i++) {
		delete children[i];
		children[i] = NULL;
	}
}
