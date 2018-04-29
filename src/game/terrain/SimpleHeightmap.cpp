//
// Created by Miro on 4/27/2018.
//

#include "SimpleHeightmap.h"

SimpleHeightmap::SimpleHeightmap(TerrainGenerator *generator, const glm::vec2 &origin, const glm::ivec2 &size)
        : origin(origin), size(size) {

    std::vector<glm::ivec2> position_data(static_cast<unsigned long long int>(size.x * size.y));
    std::vector<GLuint> elements(static_cast<unsigned long long int>(size.x * size.y * 6));
    float height_data[size.x * size.y];

    for (unsigned int x = 0; x < size.x; x++) {
        for (unsigned int y = 0; y < size.y; y++) {
            unsigned int i = x + size.x * y;
            position_data[i] = {origin.x + x, origin.y + y};

            if (i != 0 && i != elements.size() && i % size.x == 0) {
                // size.x = 5;
                // size.y = 2;
                // i = 5;
                // 0, 1, 2, 3,  4,  5
                // 6, 7, 8, 9, 10, 11
                // elements:
                // 0, 6, 7, 7, 1, 0

                elements[i - 5] = i;
                elements[i - 4] = i + size.x;
                elements[i - 3] = i + size.x + 1;
                elements[i - 2] = i + size.x + 1;
                elements[i - 1] = i + 1;
                elements[i] = i;
            }

            height_data[i] = generator->get_height(x, y);
        }
    }

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glEnableVertexAttribArray(0); // positions at location 0
    glVertexAttribPointer(0, 2, GL_INT, GL_FALSE, sizeof(glm::ivec2), (void *) 0);

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::ivec2) * position_data.size(), &position_data[0], GL_STATIC_DRAW);

    elements_size = static_cast<GLsizei>(elements.size());
    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, elements_size * sizeof(GLuint), &elements[0], GL_STATIC_DRAW);

    glGenBuffers(1, &tbo_height_data);
    glBindBuffer(GL_TEXTURE_BUFFER, tbo_height_data);
    glBufferData(GL_TEXTURE_BUFFER, sizeof(height_data), &height_data[0], GL_STATIC_DRAW);

    glGenTextures(1, &tex_height_data);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
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
    program.set_uniform_mat4("model", glm::mat4(1.0));
    program.set_uniform_ivec2("size", size);
    program.set_uniform_int("height_data", 0);

    glBindVertexArray(vao);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_BUFFER, tex_height_data);
    glTexBuffer(GL_TEXTURE_BUFFER, GL_R32F, tbo_height_data);

    glDrawElements(GL_TRIANGLES, elements_size, GL_UNSIGNED_INT, 0);

    glBindVertexArray(0);
}
