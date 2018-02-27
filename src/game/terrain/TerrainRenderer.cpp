#include "TerrainRenderer.h"

TerrainRenderer::TerrainRenderer(Camera* camera, Terrain* terrain)
	: AbstractRenderer(camera), terrain(terrain)
{
}

void TerrainRenderer::pre(const ShaderProgram & shader_program)
{
	shader_program.set_uniform_mat4("view", AbstractRenderer::camera->get_view());
	shader_program.set_uniform_mat4("projection", AbstractRenderer::camera->get_projection());
	shader_program.set_uniform_mat4("model", glm::mat4(1.0f));

	glEnable(GL_DEPTH_TEST);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void TerrainRenderer::draw(const ShaderProgram & shader_program)
{
	terrain->draw(shader_program);
}

void TerrainRenderer::post(const ShaderProgram & shader_program)
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

TerrainRenderer::~TerrainRenderer()
{
	delete terrain;
}
