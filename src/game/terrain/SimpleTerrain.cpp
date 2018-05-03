//
// Created by Miro on 4/26/2018.
//

#include "SimpleTerrain.h"

SimpleTerrain::SimpleTerrain(TerrainGenerator *generator, const glm::ivec2 &size) {
    std::vector<Vertex> vertices(size.x * size.y);
    std::vector<GLuint> elements(size.x * size.y * 6);

    int j = 5;
    for (unsigned int y = 0; y < size.y; y++) {
        for (unsigned int x = 0; x < size.x; x++) {
            unsigned int i = x + size.x * y;

            vertices[i] = {
                    {
                        x,
                        generator->get_height({x, y}), // height
                        y
                    },
                    {},
                    {}
            };

            if ( x != size.x - 1 && y != size.y - 1) {

                elements[j - 5] = i;
                elements[j - 4] = i + 1;
                elements[j - 3] = i + size.x;
                elements[j - 2] = i + size.x;
                elements[j - 1] = i + size.x + 1;
                elements[j] = i + 1;

                j += 6;
            }
        }
    }

    mesh = new Mesh(vertices, elements, new SimpleTexture("resources/textures/bricks.bmp"));
    // TODO: Generate vertices/elements
}

void SimpleTerrain::draw(const ShaderProgram &program) {
    mesh->draw(program);
    //Log::info("Drawing");
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
