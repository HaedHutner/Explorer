#ifndef _MODEL_H
#define _MODEL_H

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

#include <engine\render\Mesh.h>
#include <engine\texture\Texture.h>
#include <engine\render\ShaderProgram.h>

class Model {
private:

	glm::mat4 model;

	glm::vec3 position;
	glm::fvec3 rotation;
	glm::vec3 scale;

	std::vector<Mesh*> meshes;

public:

	Model(const std::vector<Mesh*>& meshes, const glm::vec3& position, const glm::fvec3 rotation, const glm::vec3& scale );

	glm::mat4 get_model_matrix();

	void moveBy(const glm::vec3& difference);

	void rotateBy(const glm::fvec3& rotation);

	void rotateBy(const float& amount, const glm::vec3& direction);

	void scaleBy(const glm::vec3& difference);

	virtual void tick();

	virtual void draw( const ShaderProgram& shader_program );

	~Model();

};

#endif