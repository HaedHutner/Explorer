#ifndef _TERRAIN_TREE_H
#define _TERRAIN_TREE_H

#include <game\terrain\Terrain.h>
#include <game\terrain\TerrainChunk.h>

class TerrainTree : public Terrain {

	TerrainChunk* root;

public:

	TerrainTree(TerrainGenerator* generator, Texture* texture, glm::vec2 origin, int size, float max_height);

	// Inherited via Terrain
	virtual void tick() override;

	virtual void draw(const ShaderProgram & program) override;

	~TerrainTree();

};

#endif