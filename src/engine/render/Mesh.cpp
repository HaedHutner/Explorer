#include "Mesh.h"

Mesh::Mesh(const std::vector<Vertex>& vertices, const std::vector<GLuint>& elements, Texture* texture)
	: vertices(vertices), elements(elements), texture(texture)
{
	init();
}

void Mesh::init() {

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);

	GLsizei vbo_size = vertices.size() * sizeof(Vertex);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vbo_size, &vertices[0], GL_STATIC_DRAW);

	GLsizei ebo_size = elements.size() * sizeof(GLuint);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, ebo_size, &elements[0], GL_STATIC_DRAW);

	Vertex::fillVAO();

	glBindVertexArray(0);
}

void Mesh::draw(const ShaderProgram & shader_program)
{
	shader_program.set_uniform_texture("textures", *texture, 0);
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
