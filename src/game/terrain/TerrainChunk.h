#ifndef _TERRAIN_CHUNK_H
#define _TERRAIN_CHUNK_H

#include <engine/Engine.h>

class TerrainChunk {
	Mesh* mesh;

	TerrainChunk* children[4];

	int size;
	float min_height;
	float max_height;

	bool split;

public:

	TerrainChunk(int size, float min_height, float max_height);

	void draw(const ShaderProgram& program);

	void split_chunk();

	void join_chunk();

	bool is_split();

	~TerrainChunk();
};

#endif