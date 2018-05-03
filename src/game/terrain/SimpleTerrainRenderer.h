#ifndef _TERRAIN_RENDERER_H
#define _TERRAIN_RENDERER_H

#include <engine/render/AbstractRenderer.h>

#include <game/terrain/Terrain.h>
#include "SimpleTerrain.h"
#include "HeightmapTerrain.h"
#include "QuadTerrain.h"

class SimpleTerrainRenderer : public AbstractRenderer {
private:

    Terrain *terrain;

    void pre(const ShaderProgram &shader_program) override;

    void draw(const ShaderProgram &shader_program) override;

    void post(const ShaderProgram &shader_program) override;

public:

    SimpleTerrainRenderer(Camera *camera, QuadTerrain *terrain);

    SimpleTerrainRenderer(Camera *camera, SimpleTerrain *terrain);

    SimpleTerrainRenderer(Camera *camera, HeightmapTerrain *terrain);

    ~SimpleTerrainRenderer();

};

#endif