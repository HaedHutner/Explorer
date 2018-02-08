#ifndef _SIMPLE_RENDERER_H
#define _SIMPLE_RENDERER_H

#include <vector>

#include <engine\render\AbstractRenderer.h>
#include <engine\render\Model.h>

class SimpleRenderer : public AbstractRenderer {

private:

	std::vector<Model*> models;

protected:

	// Inherited via AbstractRenderer
	virtual void pre (const ShaderProgram& shader) override;
	virtual void draw(const ShaderProgram& shader) override;
	virtual void post(const ShaderProgram& shader) override;

public:

	SimpleRenderer(Camera* camera, std::vector<Model*> models);

	~SimpleRenderer();
};

#endif