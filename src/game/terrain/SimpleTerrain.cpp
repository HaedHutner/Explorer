#include "SimpleTerrain.h"

SimpleTerrain::SimpleTerrain(Texture* texture, TerrainGenerator * generator, int size)
	: Terrain(generator, texture)
{
	std::vector<Vertex> vertices = std::vector<Vertex>( size * size );
	std::vector<GLuint> elements = std::vector<GLuint>( size * size * 6 );

	generate_vertices(vertices, elements, size, 1.0f);

	Terrain::mesh = new Mesh(vertices, elements, texture);
}

void SimpleTerrain::generate_vertices(std::vector<Vertex>& vertices, std::vector<GLuint>& elements, float size, float texture_size)
{
	glm::vec2 begin = { 0.0f - size / 2, 0.0f - size / 2 };

	float max_height = 128.0f;

	int width = size;
	int height = size;

	float tX = 0.0f;
	float tY = height * texture_size;

	int i = 0;
	int j = 0;

	int lastZ = begin.y;

	int beginX = begin.x;
	int beginY = begin.y;

	for (int i = 0; i < vertices.size(); i++) {

		int x = (i % width + beginX);

		x == beginX ? tX = 0.0f : tX += 1.0f * texture_size; // for every increase in x, increase tX, and reset tX to 0 when x = 0

		int z = (i / width + beginY);

		if (z != lastZ) { // for every increase in z, decrease tY
			tY -= 1.0f * texture_size;
			lastZ += 1.0f;
		}

		const float y = max_height * generator->get_height(x, z);
		vertices[i].xyz = { x, y, z };
		vertices[i].uv = { tX, tY };

		if (z == beginY * 1.0f || x == beginX * 1.0f) {
			// a vertex with either z or x equaling their beginning values is missing neighboring vertices requried to construct the quad
			// just add vertex to vertices vector and continue
			continue;
		}

		if (z != beginY * 1.0f && x != beginX * 1.0f) {
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

void SimpleTerrain::tick()
{
}

void SimpleTerrain::draw(const ShaderProgram & program)
{
	mesh->draw(program);
}
