#include "Model.h"

Model::Model()
	: mesh( std::vector<Vertex>(), std::vector<GLuint>() ), texture()
{
}

Model::Model(const Mesh & mesh, const Texture & texture)
	: mesh(mesh), texture(texture)
{
}

glm::mat4 Model::get_model_matrix()
{
	return model;
}

void Model::moveBy(const glm::vec3 & difference)
{
	glm::translate(model, difference);
}

void Model::rotateBy(const float& amount, const glm::vec3& direction)
{
	glm::rotate(model, amount, direction);
}

void Model::scaleBy(const glm::vec3 & difference)
{
	glm::scale(model, difference);
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
