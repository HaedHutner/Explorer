#ifndef _SIMPLETERRAIN_H
#define _SIMPLETERRAIN_H


#include "Terrain.h"
#include "TerrainGenerator.h"

class SimpleTerrain : public Terrain {

    Mesh *mesh;

public:

    SimpleTerrain(TerrainGenerator *generator, const glm::ivec2 &size);

    void draw(const ShaderProgram &program);

    ~SimpleTerrain() override;

    float get_height(int x, int y) override;

    float get_max_height() override;

    glm::vec2 get_size() override;
};


#endif //_SIMPLETERRAIN_H
