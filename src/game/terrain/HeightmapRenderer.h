//
// Created by Miro on 4/29/2018.
//

#ifndef TERRAINEXPLORER_HEIGHTMAPRENDERER_H
#define TERRAINEXPLORER_HEIGHTMAPRENDERER_H


#include <engine/render/AbstractRenderer.h>
#include <engine/terrain/Heightmap.h>

class HeightmapRenderer : public AbstractRenderer {

    Heightmap* heightmap;

public:
    HeightmapRenderer(Camera *camera, Heightmap* heightmap);

protected:
    void pre(const ShaderProgram &shader) override;

    void draw(const ShaderProgram &shader) override;

    void post(const ShaderProgram &shader) override;

};


#endif //TERRAINEXPLORER_HEIGHTMAPRENDERER_H
