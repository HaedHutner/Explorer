#ifndef _TERRAIN_H
#define _TERRAIN_H

#include <engine\Engine.h>
#include <game\terrain\TerrainGenerator.h>

class Terrain {

protected:

	TerrainGenerator* generator;

	Mesh* mesh;

public:

	Terrain(TerrainGenerator* generator, Texture* texture)
		: generator(generator), mesh(nullptr)
	{
	}

	virtual void tick() = 0;

	virtual void draw(const ShaderProgram& program) = 0;

	~Terrain() 
	{
		delete generator;
		delete mesh;
	}
};

#endif