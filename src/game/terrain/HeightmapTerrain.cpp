#include "HeightmapTerrain.h"

HeightmapTerrain::HeightmapTerrain(TerrainGenerator *generator, const glm::ivec2 &size, const float &max_height) {

}

float HeightmapTerrain::get_height(int x, int y) {
    return 0;
}

float HeightmapTerrain::get_max_height() {
    return 0;
}

glm::vec2 HeightmapTerrain::get_size() {
    return glm::vec2();
}

void HeightmapTerrain::draw(const ShaderProgram &program) {
    center->draw(program);
    for (auto ring : rings) {
        ring->draw(program);
    }
}

HeightmapTerrain::~HeightmapTerrain() {
    delete center;
    for ( auto ring : rings ) {
        delete ring;
    }
}
