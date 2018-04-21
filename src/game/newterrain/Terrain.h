#ifndef _TERRAIN_H
#define _TERRAIN_H

#include <engine\Engine.h>

class Terrain {

public:

	virtual void tick() = 0;

	virtual void draw(int lod_level, const ShaderProgram& program) = 0;

	~Terrain() = default;
};

#endif