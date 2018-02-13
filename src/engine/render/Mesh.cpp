#include "Mesh.h"

Mesh::Mesh(const std::vector<Vertex>& vertices, const std::vector<GLuint>& elements)
	: vertices(vertices), elements(elements)
{
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);

	glBindVertexArray(vao);

	size_t vbo_size = vertices.size() * sizeof(Vertex);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vbo_size, &vertices[0], GL_STATIC_DRAW);

	size_t ebo_size = elements.size() * sizeof(GLuint);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, ebo_size, &elements[0], GL_STATIC_DRAW);

	Vertex::fillVAO(vao);

	glBindVertexArray(0);
}

void Mesh::draw(const ShaderProgram & shader_program)
{
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, elements.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

Mesh::~Mesh()
{
	glDeleteBuffers(1, &ebo);
	glDeleteBuffers(1, &vbo);
	glDeleteVertexArrays(1, &vao);
}
