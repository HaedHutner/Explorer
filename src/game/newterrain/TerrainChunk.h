#ifndef _TERRAIN_CHUNK_H
#define _TERRAIN_CHUNK_H

#include <engine/Engine.h>

#include <game/newterrain/Terrain.h>
#include <game/newterrain/TerrainTree.h>
#include <game/newterrain/TerrainGenerator.h>

#include <util/MathUtils.hpp>

class TerrainChunk : public Terrain {
private:

	TerrainTree* mesh;

public:

	TerrainChunk(TerrainGenerator* generator, glm::vec2 origin, float initial_depth, float size, float height);

	// Inherited via Terrain
	virtual void tick() override;

	virtual void draw(int lod_level, const ShaderProgram & program) override;

	~TerrainChunk();
};

#endif