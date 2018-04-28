//
// Created by Miro on 4/27/2018.
//

#include "SimpleHeightmap.h"

SimpleHeightmap::SimpleHeightmap(TerrainGenerator *generator, const glm::vec2 &origin, const glm::ivec2 &size) {

}

float SimpleHeightmap::get_height(const float &x, const float &y) {
    return 0;
}

glm::ivec2 SimpleHeightmap::get_size() {
    return glm::ivec2();
}

glm::vec2 SimpleHeightmap::get_origin() {
    return glm::vec2();
}

SimpleTexture SimpleHeightmap::as_texture() {
    return SimpleTexture(nullptr);
}

void SimpleHeightmap::draw(const ShaderProgram &program) {

}
