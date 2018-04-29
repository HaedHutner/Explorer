//
// Created by Miro on 4/29/2018.
//

#include "HeightmapRenderer.h"

HeightmapRenderer::HeightmapRenderer(Camera *camera, Heightmap* heightmap)
        : AbstractRenderer(camera), heightmap(heightmap) {

}

void HeightmapRenderer::pre(const ShaderProgram &shader) {
    shader.set_uniform_mat4("view", AbstractRenderer::camera->get_view());
    shader.set_uniform_mat4("projection", AbstractRenderer::camera->get_projection());

    glEnable(GL_DEPTH_TEST);
}

void HeightmapRenderer::draw(const ShaderProgram &shader) {
    heightmap->draw(shader);
}

void HeightmapRenderer::post(const ShaderProgram &shader) {

}
