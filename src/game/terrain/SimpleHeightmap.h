//
// Created by Miro on 4/27/2018.
//

#ifndef TERRAINEXPLORER_SIMPLEHEIGHTMAP_H
#define TERRAINEXPLORER_SIMPLEHEIGHTMAP_H


#include <engine/terrain/Heightmap.h>
#include "TerrainGenerator.h"

class SimpleHeightmap : public Heightmap {

    glm::vec2 origin;
    glm::ivec2 size;

    GLsizei elements_size;
    GLuint vbo, ebo, vao;

    GLuint tbo_height_data;
    GLuint tex_height_data;

public:

    SimpleHeightmap(TerrainGenerator *generator, const glm::vec2 &origin, const glm::ivec2 &size);

    float get_height(const float &x, const float &y) override;

    glm::ivec2 get_size() override;

    glm::vec2 get_origin() override;

    SimpleTexture as_texture() override;

    void draw(const ShaderProgram &program) override;

};


#endif //TERRAINEXPLORER_SIMPLEHEIGHTMAP_H
