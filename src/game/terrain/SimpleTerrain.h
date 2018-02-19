#ifndef _SIMPLE_TERRAIN_H
#define _SIMPLE_TERRAIN_H

#include <engine\Engine.h>

#include <game\terrain\Terrain.h>
#include <game\terrain\TerrainGenerator.h>

#include <util\MathUtils.hpp>

class SimpleTerrain : public Terrain {

	void generate_vertices(std::vector<Vertex>& vertices, std::vector<GLuint>& elements, float size, float texture_size);

public:

	SimpleTerrain(Texture* texture, TerrainGenerator* generator, int size);

	virtual void tick() override;

	virtual void draw(const ShaderProgram & program) override;

	~SimpleTerrain() = default;
};

#endif