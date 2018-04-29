#ifndef _TERRAIN_H
#define _TERRAIN_H

#include <engine/Engine.h>

class Terrain {

public:

    virtual void draw(const ShaderProgram &program) = 0;

    virtual float get_height(int x, int y) = 0;

    virtual float get_max_height() = 0;

    virtual glm::vec2 get_size() = 0;

    virtual ~Terrain() = default;
};

#endif