//
// Created by Miro on 4/27/2018.
//

#include "SimpleHeightmap.h"

SimpleHeightmap::SimpleHeightmap(TerrainGenerator *generator, const glm::vec2 &origin, const glm::ivec2 &size)
        : origin(origin), size(size) {

    float height_data[size.x * size.y];

    for (int x = 0; x < size.x; x++) {
        for (int y = 0; y < size.y; y++) {
            int i = x + size.x*y;
            height_data[i] = generator->get_height(x, y);
        }
    }

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &tbo_height_data);
    glBindBuffer(GL_TEXTURE_BUFFER, tbo_height_data);

    glBufferData(GL_TEXTURE_BUFFER, sizeof(height_data), height_data, GL_STATIC_DRAW);
    glGenTextures(1, &tex_height_data);

    glBindBuffer(GL_TEXTURE_BUFFER, 0);

    glBindVertexArray(0);
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
    program.use();
    glBindVertexArray(vao);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_BUFFER, tex_height_data);
    glTexBuffer(GL_TEXTURE_BUFFER, GL_R32F, tbo_height_data);

    program.set_uniform_int("height_data", 0);

    glDrawArrays(GL_TRIANGLES, 0, 6);
}
