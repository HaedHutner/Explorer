//
// Created by Miro on 4/26/2018.
//

#include "SimpleTerrain.h"

SimpleTerrain::SimpleTerrain(const glm::ivec2 &size, TerrainGenerator *generator)
        : mesh(new Mesh(size.x * size.y)) {
    // TODO: Generate vertices/elements
}

void SimpleTerrain::draw(const ShaderProgram &program) {
    // TODO: Render mesh
    Log::info( "Drawing SimpleTerrain" );
}

SimpleTerrain::~SimpleTerrain() {
    delete mesh;
}

float SimpleTerrain::get_height(int x, int y) {
    return 0;
}

float SimpleTerrain::get_max_height() {
    return 0;
}

glm::vec2 SimpleTerrain::get_size() {
    return glm::vec2();
}
