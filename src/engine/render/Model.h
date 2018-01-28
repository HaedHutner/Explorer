#ifndef _MODEL_H
#define _MODEL_H

#include <glm\glm.hpp>

#include <engine\render\Mesh.h>
#include <engine\texture\Texture.h>
#include <engine\render\ShaderProgram.h>

class Model {
private:

	glm::vec3 position;
	glm::vec3 rotation;

	Mesh mesh;
	Texture texture;

public:

	Model();

	Model(const Mesh& mesh, const Texture& texture);

	void moveBy(const glm::vec3& difference);

	void rotateBy(const glm::vec3& difference);

	virtual void tick();

	virtual void draw( const ShaderProgram& shader_program );

	~Model();

};

#endif