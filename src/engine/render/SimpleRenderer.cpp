#include "SimpleRenderer.h"

SimpleRenderer::SimpleRenderer(Camera * camera, std::vector<Model*> models, bool wireframe )
	: AbstractRenderer(camera), models(models), wireframe(wireframe)
{
}

void SimpleRenderer::pre(const ShaderProgram& shader)
{
	shader.set_uniform_mat4("view", AbstractRenderer::camera->get_view());
	shader.set_uniform_mat4("projection", AbstractRenderer::camera->get_projection());

	glEnable(GL_DEPTH_TEST);

	if (wireframe) glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void SimpleRenderer::draw(const ShaderProgram& shader)
{
	for (Model* model : models) {
		shader.set_uniform_mat4("model", model->get_model_matrix());
		model->draw(shader);
	}
}

void SimpleRenderer::post(const ShaderProgram& shader)
{
	if (wireframe) glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

SimpleRenderer::~SimpleRenderer()
{
	for (auto model : models) {
		delete model;
	}
}
