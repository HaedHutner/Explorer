#ifndef _TERRAIN_CHUNK_H
#define _TERRAIN_CHUNK_H

#include <engine/Engine.h>

#include <game/terrain/Terrain.h>

#include <game/terrain/TerrainGenerator.h>

#include <util/MathUtils.hpp>

class TerrainChunk : public Terrain {
private:

	TerrainGenerator* generator;

	Mesh* mesh;

	TerrainChunk* children[4];

	glm::vec2 center;

	int size;
	float min_height;
	float max_height;

	bool split;

	void generate_vertices( std::vector<Vertex>& vertices, std::vector<GLuint>& elements, int texture_resolution, int resolution );

public:

	TerrainChunk(TerrainGenerator* generator, glm::vec2 center, int size, float min_height, float max_height);

	void tick() override;

	void draw(const ShaderProgram& program) override;

	void split_chunk();

	void join_chunk();

	bool is_split();

	~TerrainChunk();
};

#endif