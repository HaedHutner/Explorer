#include "Model.h"

Model::Model()
	: mesh( std::vector<Vertex>(), std::vector<GLuint>() ), texture()
{
}

Model::Model(const Mesh & mesh, const Texture & texture)
	: mesh(mesh), texture(texture)
{
}

void Model::moveBy(const glm::vec3 & difference)
{
}

void Model::rotateBy(const glm::vec3 & difference)
{
}

void Model::tick()
{
}

void Model::draw(const ShaderProgram & shader_program)
{
	shader_program.set_uniform_int("texture", texture.id());
	mesh.draw(shader_program);
}

Model::~Model()
{
}
