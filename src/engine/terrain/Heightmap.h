//
// Created by Miro on 4/27/2018.
//

#ifndef TERRAINEXPLORER_HEIGHTMAP_H
#define TERRAINEXPLORER_HEIGHTMAP_H

#include <glm/glm.hpp>
#include <engine/texture/SimpleTexture.h>
#include <engine/render/ShaderProgram.h>

class Heightmap {

public:

    virtual float get_height(const float &x, const float &y) = 0;

    virtual glm::ivec2 get_size() = 0;

    virtual glm::vec2 get_origin() = 0;

    virtual SimpleTexture as_texture() = 0;

    virtual void draw(const ShaderProgram &program) = 0;

};


#endif //TERRAINEXPLORER_HEIGHTMAP_H
