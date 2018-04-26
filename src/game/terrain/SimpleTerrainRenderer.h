#ifndef _TERRAIN_RENDERER_H
#define _TERRAIN_RENDERER_H

#include <engine/render/AbstractRenderer.h>

#include <game/terrain/Terrain.h>
#include "SimpleTerrain.h"

class SimpleTerrainRenderer : public AbstractRenderer {
private:

    SimpleTerrain *terrain;

    void pre(const ShaderProgram &shader_program) override;

    void draw(const ShaderProgram &shader_program) override;

    void post(const ShaderProgram &shader_program) override;

public:

    SimpleTerrainRenderer(Camera *camera, SimpleTerrain *terrain);

    ~SimpleTerrainRenderer();

};

#endif