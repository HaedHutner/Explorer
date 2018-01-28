#ifndef _MESH_H
#define _MESH_H

#include <glad\glad.h>

#include <vector>

#include <engine\render\Vertex.h>
#include <engine\render\ShaderProgram.h>

class Mesh {

private:

	std::vector<Vertex> vertices;
	std::vector<GLuint> elements;

	GLuint vao, vbo, ebo;

public:

	Mesh(const std::vector<Vertex>& vertices, const std::vector<GLuint>& elements);

	void draw( const ShaderProgram& shader_program );

	~Mesh();

};

#endif