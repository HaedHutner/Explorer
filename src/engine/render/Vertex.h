#ifndef _VERTEX_H
#define _VERTEX_H

#include <glad\glad.h>
#include <glm\glm.hpp>

struct Vertex {

    glm::vec3 xyz;
    glm::vec2 uv;
    glm::vec3 normal;

    static void bindAttribs(GLuint program) {
        glBindAttribLocation(program, 0, "position");
        glBindAttribLocation(program, 1, "uv");
        glBindAttribLocation(program, 2, "normal");
    }

    static void fillVAO() {
        glEnableVertexAttribArray(0); // positions at location 0
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *) 0);

        glEnableVertexAttribArray(1); // texture coordinates at location 1
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *) (3 * sizeof(GLfloat)));

        glEnableVertexAttribArray(2); // normals at location 2
        glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *) (5 * sizeof(GLfloat)));
    }

    Vertex operator+(const Vertex &other) {
        return {xyz + other.xyz, uv + other.uv, normal + other.normal};
    }

    Vertex operator-(const Vertex &other) {
        return {xyz - other.xyz, uv - other.uv, normal - other.normal};
    }

    Vertex operator*(const Vertex &other) {
        return {xyz * other.xyz, uv * other.uv, normal * other.normal};
    }

    Vertex operator*(const float &value) {
        return {xyz * value, uv * value, normal * value};
    }

    static Vertex midpoint(Vertex &first, Vertex &second) {
        return (first + second) * 0.5f;
    }

};

#endif // !_VERTEX_H
