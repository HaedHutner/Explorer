#ifndef _MESH_H
#define _MESH_H

#include <glad\glad.h>

#include <vector>

#include <engine\texture\SimpleTexture.h>
#include <engine\render\Vertex.h>
#include <engine\render\ShaderProgram.h>

class Mesh {

private:

    Texture *texture;

    GLuint vertices_size, elements_size;
    GLuint vao, vbo, ebo;

public:

    Mesh(int vert_size);

    Mesh(const std::vector<Vertex> &vertices, const std::vector<GLuint> &elements, Texture *texture);

    void set_vertices(const std::vector<Vertex> &vertices);

    void set_elements(const std::vector<GLuint> &elements);

    void draw(const ShaderProgram &shader_program);

    unsigned int vert(Vertex &vertex);

    void index(GLuint index);

    void add_indices(const std::vector<GLuint> &indices);

    ~Mesh();

};

#endif