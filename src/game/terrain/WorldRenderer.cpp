//
// Created by Miro on 5/2/2018.
//

#include "WorldRenderer.h"

WorldRenderer::WorldRenderer(Camera *camera, WorldGenerator* generator) : AbstractRenderer(camera), generator(generator) {}

void WorldRenderer::pre(const ShaderProgram &shader) {
    shader.set_uniform_mat4("view", AbstractRenderer::camera->get_view());
    shader.set_uniform_mat4("projection", AbstractRenderer::camera->get_projection());
    shader.set_uniform_mat4("model", glm::mat4(1.0f));

    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glCullFace(GL_BACK);
}

void WorldRenderer::draw(const ShaderProgram &shader) {
    glm::ivec2 coords = generator->get_chunk_coordinates({camera->get_position().x, camera->get_position().z});

    int max_depth = 5;

    for ( int distance = 0; distance < max_depth; distance++ ) {
        for ( int x = -distance; x < ( distance + 1 ); x++ ) {
            for ( int y = -distance; y < (distance + 1); y++ ) {
                if ( abs(y) == distance || abs(x) == distance ) {
                    generator->get_chunk_at({coords.x + x, coords.y + y}, max_depth - distance)->draw(shader);
                }
            }
        }
    }

//    std::vector<WorldGenerator::Chunk*> chunks = {
//        generator->get_chunk_at(coords, 4),
//        generator->get_chunk_at(coords + glm::ivec2(1,0), 4),
//        generator->get_chunk_at({coords.x - 1, coords.y}, 4),
//        generator->get_chunk_at({coords.x, coords.y + 1}, 4),
//        generator->get_chunk_at({coords.x, coords.y - 1}, 4),
//        generator->get_chunk_at({coords.x + 1, coords.y + 1}, 4),
//        generator->get_chunk_at({coords.x - 1, coords.y - 1}, 4),
//        generator->get_chunk_at({coords.x + 1, coords.y - 1}, 4),
//        generator->get_chunk_at({coords.x - 1, coords.y + 1}, 4),
//        generator->get_chunk_at({coords.x - 2, coords.y + 1}, 3)
//    };
//
//    for ( auto chunk : chunks ) {
//        chunk->draw(shader);
//    }
}

void WorldRenderer::post(const ShaderProgram &shader) {

}

WorldRenderer::~WorldRenderer() {
    delete generator;
}
