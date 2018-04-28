#ifndef TERRAINEXPLORER_HEIGHTMAPRING_H
#define TERRAINEXPLORER_HEIGHTMAPRING_H

#include "Heightmap.h"

class HeightmapRing : public Heightmap {

public:

    virtual glm::ivec2 get_inner_size() = 0;

    virtual glm::vec2 get_inner_origin() = 0;

};

#endif //TERRAINEXPLORER_HEIGHTMAPRING_H
