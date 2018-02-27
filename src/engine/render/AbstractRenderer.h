#ifndef _ABSTRACT_RENDERER_H
#define _ABSTRACT_RENDERER_H

#include <glad\glad.h>
#include <engine\render\ShaderProgram.h>
#include <engine\render\Camera.h>

class AbstractRenderer {

protected:
	
	Camera * camera;

	virtual void pre(const ShaderProgram& shader) = 0;

	virtual void draw(const ShaderProgram& shader) = 0;

	virtual void post(const ShaderProgram& shader) = 0;

public:

	AbstractRenderer(Camera* camera) : camera(camera) {}

	void render(ShaderProgram& shader) {
		shader.use();
		pre(shader);
		draw(shader);
		post(shader);
	}

};

#endif