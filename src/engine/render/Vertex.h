#ifndef _VERTEX_H
#define _VERTEX_H

#include <glad\glad.h>
#include <glm\glm.hpp>

struct Vertex {

	glm::dvec3 xyz;
	glm::dvec2 uv;
	glm::dvec3 normal;

	static void fillVAO(const GLuint& vao) {
		glBindVertexArray(vao);

		glEnableVertexAttribArray(0); // positions at location 0
		glVertexAttribPointer(0, 3, GL_DOUBLE, GL_FALSE, sizeof(Vertex), (void*)0);

		glEnableVertexAttribArray(1); // texture coordinates at location 1
		glVertexAttribPointer(1, 2, GL_DOUBLE, GL_FALSE, sizeof(Vertex), (void*)(3 * sizeof(GLdouble)));

		glEnableVertexAttribArray(2); // normals at location 2
		glVertexAttribPointer(2, 3, GL_DOUBLE, GL_FALSE, sizeof(Vertex), (void*)(5 * sizeof(GLdouble)));

		glBindVertexArray(0);
	}

};

#endif // !_VERTEX_H
