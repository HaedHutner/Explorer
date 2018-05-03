#include "Mesh.h"

Mesh::Mesh(int vert_size)
        : texture(nullptr) {

}

Mesh::Mesh(const std::vector<Vertex> &vertices, const std::vector<GLuint> &elements, Texture *texture)
        : texture(texture) {
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    vertices_size = vertices.size() * sizeof(Vertex);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vertices_size, &vertices[0], GL_STATIC_DRAW);

    elements_size = elements.size() * sizeof(GLuint);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, elements_size, &elements[0], GL_STATIC_DRAW);

    Vertex::fillVAO();

    glBindVertexArray(0);
}

void Mesh::draw(const ShaderProgram &shader_program) {
    if (texture) shader_program.set_uniform_texture("textures", *texture, 0);

    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, elements_size, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void Mesh::set_vertices(const std::vector<Vertex> &vertices) {
    glBindVertexArray(vao);

    vertices_size = vertices.size() * sizeof(Vertex);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vertices_size, &vertices[0], GL_STATIC_DRAW);

    glBindVertexArray(0);
}

void Mesh::set_elements(const std::vector<GLuint> &elements) {
    glBindVertexArray(vao);

    elements_size = elements.size() * sizeof(GLuint);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, elements_size, &elements[0], GL_STATIC_DRAW);

    glBindVertexArray(0);
}

Mesh::~Mesh() {
    delete texture;

    glDeleteBuffers(1, &ebo);
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);
}
