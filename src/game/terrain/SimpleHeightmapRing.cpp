//
// Created by Miro on 4/27/2018.
//

#include "SimpleHeightmapRing.h"

SimpleHeightmapRing::SimpleHeightmapRing(
        TerrainGenerator *generator,
        const glm::vec2 &origin,
        const glm::ivec2 &size,
        const glm::vec2 &inner_origin,
        const glm::ivec2 &inner_size
) {

}

float SimpleHeightmapRing::get_height(const float &x, const float &y) {
    return 0;
}

glm::ivec2 SimpleHeightmapRing::get_size() {
    return glm::ivec2();
}

glm::vec2 SimpleHeightmapRing::get_origin() {
    return glm::vec2();
}

SimpleTexture SimpleHeightmapRing::as_texture() {
    return SimpleTexture(nullptr);
}

void SimpleHeightmapRing::draw(const ShaderProgram &program) {

}

glm::ivec2 SimpleHeightmapRing::get_inner_size() {
    return glm::ivec2();
}

glm::vec2 SimpleHeightmapRing::get_inner_origin() {
    return glm::vec2();
}
