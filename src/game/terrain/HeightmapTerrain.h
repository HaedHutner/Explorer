//
// Created by Miro on 4/26/2018.
//

#ifndef TERRAINEXPLORER_HEIGHTMAPTERRAIN_H
#define TERRAINEXPLORER_HEIGHTMAPTERRAIN_H


#include <engine/terrain/Heightmap.h>
#include <engine/terrain/HeightmapRing.h>
#include "Terrain.h"
#include "TerrainGenerator.h"

class HeightmapTerrain : public Terrain {

    Heightmap center;
    std::vector<HeightmapRing> rings;

public:

    HeightmapTerrain(Heightmap heightmap, std::vector<HeightmapRing> rings);

    HeightmapTerrain(TerrainGenerator *generator, const glm::ivec2 &size, const float &max_height);

    HeightmapTerrain(Heightmap center, int rings_amount);

    float get_height(int x, int y) override;

    float get_max_height() override;

    glm::vec2 get_size() override;

    void draw(const ShaderProgram &program);

};


#endif //TERRAINEXPLORER_HEIGHTMAPTERRAIN_H
