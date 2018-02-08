#include "SimpleRenderer.h"

SimpleRenderer::SimpleRenderer(Camera * camera, std::vector<Model*> models)
	: AbstractRenderer(camera), models(models)
{
}

void SimpleRenderer::pre(const ShaderProgram& shader)
{
	shader.set_uniform_mat4("view", AbstractRenderer::camera->get_view());
	shader.set_uniform_mat4("projection", AbstractRenderer::camera->get_projection());

	glEnable(GL_DEPTH_TEST);
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
}

SimpleRenderer::~SimpleRenderer()
{
	for (auto model : models) {
		delete model;
	}
}
