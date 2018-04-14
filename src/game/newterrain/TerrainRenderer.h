#ifndef _TERRAIN_RENDERER_H
#define _TERRAIN_RENDERER_H

#include <engine\render\AbstractRenderer.h>

#include <game\terrain\Terrain.h>

class TerrainRenderer : public AbstractRenderer {
private:

	Terrain * terrain;

	void pre (const ShaderProgram& shader_program) override;

	void draw(const ShaderProgram& shader_program) override;

	void post(const ShaderProgram& shader_program) override;

public:

	TerrainRenderer(Camera* camera, Terrain* terrain);

	~TerrainRenderer();

};

#endif