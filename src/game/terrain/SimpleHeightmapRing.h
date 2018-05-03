//
// Created by Miro on 4/27/2018.
//

#ifndef TERRAINEXPLORER_SIMPLEHEIGHTMAPRING_H
#define TERRAINEXPLORER_SIMPLEHEIGHTMAPRING_H


#include <engine/terrain/HeightmapRing.h>
#include "TerrainGenerator.h"

class SimpleHeightmapRing : public HeightmapRing {

    glm::vec2 origin;
    glm::vec2 inner_origin;

    glm::ivec2 size;
    glm::ivec2 inner_size;

    GLuint vao, vbo, ebo;

    SimpleTexture height_data;

public:

    SimpleHeightmapRing(
            TerrainGenerator *generator,
            const glm::vec2 &origin,
            const glm::ivec2 &size,
            const glm::vec2 &inner_origin,
            const glm::ivec2 &inner_size
    );

    float get_height(const float &x, const float &y) override;

    glm::ivec2 get_size() override;

    glm::vec2 get_origin() override;

    glm::ivec2 get_inner_size() override;

    glm::vec2 get_inner_origin() override;

    SimpleTexture as_texture() override;

    void draw(const ShaderProgram &program) override;

};


#endif //TERRAINEXPLORER_SIMPLEHEIGHTMAPRING_H
