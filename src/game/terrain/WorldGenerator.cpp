//
// Created by Miro on 5/2/2018.
//

#include "WorldGenerator.h"

WorldGenerator::WorldGenerator(int seed, float max_height) : TerrainGenerator(seed, max_height) {

}



WorldGenerator::Chunk *WorldGenerator::get_at(const glm::vec3 &position) {
    return get_at(glm::vec2(position.x, position.z));
}

WorldGenerator::Chunk *WorldGenerator::get_at(const glm::vec2 &position) {
    Chunk *result;
    glm::ivec2 chunk_position = get_chunk_coordinates(position);

    try {
        result = chunk_cache.at(chunk_position);
    } catch ( std::out_of_range &e ) {
        result = new Chunk(this, get_world_coordinates(chunk_position), CHUNK_SIZE, DEFAULT_DEPTH);
        chunk_cache[chunk_position] = result;
    }

    return result;
}

WorldGenerator::Chunk *WorldGenerator::get_at(const glm::vec2 &position, int lod) {
    Chunk *result;
    const glm::ivec2 &chunk_position = get_chunk_coordinates(position);

    try {
        result = chunk_cache.at(chunk_position);
        result->set_depth(lod);
    } catch ( std::out_of_range &e ) {
        result = new Chunk(this, get_world_coordinates(chunk_position), CHUNK_SIZE, lod);
        chunk_cache[chunk_position] = result;
    }

    return result;
}

WorldGenerator::Chunk *WorldGenerator::get_chunk_at(const glm::ivec2 &chunk_coordinates) {
    Chunk *result;

    try {
        result = chunk_cache.at(chunk_coordinates);
    } catch ( std::out_of_range &e ) {
        result = new Chunk(this, get_world_coordinates(chunk_coordinates), CHUNK_SIZE, DEFAULT_DEPTH);
        chunk_cache[chunk_coordinates] = result;
    }

    return result;
}

WorldGenerator::Chunk *WorldGenerator::get_chunk_at(const glm::ivec2 &chunk_coordinates, int lod) {
    Chunk *result;

    try {
        result = chunk_cache.at(chunk_coordinates);
        result->set_depth(lod);
    } catch ( std::out_of_range &e ) {
        result = new Chunk(this, get_world_coordinates(chunk_coordinates), CHUNK_SIZE, lod);
        chunk_cache[chunk_coordinates] = result;
    }

    return result;
}

std::vector<WorldGenerator::Chunk *> WorldGenerator::get_within(const glm::vec2 &point, float radius, int lod) {
    // TODO
    return std::vector<WorldGenerator::Chunk *>();
}

glm::ivec2 WorldGenerator::get_chunk_coordinates(const glm::vec2 &world_coordinates) {
    return {
            floor(world_coordinates.x / CHUNK_SIZE),
            floor(world_coordinates.y / CHUNK_SIZE)
    };
}

glm::vec2 WorldGenerator::get_world_coordinates(const glm::ivec2 &chunk_coordinates) {
    return {
            chunk_coordinates.x * CHUNK_SIZE,
            chunk_coordinates.y * CHUNK_SIZE
    };
}

WorldGenerator::Chunk::Chunk(WorldGenerator *generator, const glm::vec2 &origin, float size, int depth)
        : QuadTerrain(generator, origin, size, depth) {

}

WorldGenerator::~WorldGenerator() {
    for ( auto &pair : chunk_cache ) {
        delete pair.second;
    }
}
