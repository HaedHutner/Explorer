#ifndef _MESH_H
#define _MESH_H

#include <glad\glad.h>

#include <vector>

#include <engine\texture\SimpleTexture.h>
#include <engine\render\Vertex.h>
#include <engine\render\ShaderProgram.h>

class Mesh {

private:

	std::vector<Vertex> vertices;
	std::vector<GLuint> elements;
	Texture* texture;

	GLuint vao, vbo, ebo;

	void init();

public:

	Mesh(int vert_size);

	Mesh(const std::vector<Vertex>& vertices, const std::vector<GLuint>& elements, Texture* texture);

	void draw( const ShaderProgram& shader_program );

	~Mesh();

};

#endif