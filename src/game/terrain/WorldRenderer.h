//
// Created by Miro on 5/2/2018.
//

#ifndef TERRAINEXPLORER_WORLDRENDERER_H
#define TERRAINEXPLORER_WORLDRENDERER_H


#include <engine/render/AbstractRenderer.h>
#include "WorldGenerator.h"

class WorldRenderer : public AbstractRenderer {

    WorldGenerator *generator;

public:
    WorldRenderer(Camera *camera, WorldGenerator *generator);

    ~WorldRenderer();

protected:
    void pre(const ShaderProgram &shader) override;

    void draw(const ShaderProgram &shader) override;

    void post(const ShaderProgram &shader) override;

};


#endif //TERRAINEXPLORER_WORLDRENDERER_H
