#ifndef _TERRAIN_CHUNK_H
#define _TERRAIN_CHUNK_H

#include <engine/Engine.h>

#include <game/terrain/Terrain.h>

#include <util/MathUtils.hpp>

class TerrainChunk {
private:

	TerrainChunk* children[4];

	glm::vec2 origin;
	float size;

	float max_height;

	bool split;

public:

	TerrainChunk(glm::vec2 origin, float size, float max_height);

	void generate_vertices(TerrainGenerator* generator, std::vector<Vertex>& vertices, std::vector<GLuint>& elements);

	void split_chunk();

	void join_chunk();

	bool is_split();

	~TerrainChunk();
};

#endif