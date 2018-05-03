//
// Created by Miro on 5/2/2018.
//

#ifndef TERRAINEXPLORER_WORLDGENERATOR_H
#define TERRAINEXPLORER_WORLDGENERATOR_H

#include <unordered_map>
#include "TerrainGenerator.h"
#include "QuadTerrain.h"

#define CHUNK_SIZE 64.0
#define DEFAULT_DEPTH 5

class WorldGenerator : public TerrainGenerator {

public:

    class Chunk : public QuadTerrain {
    public:
        Chunk(WorldGenerator *generator, const glm::vec2 &origin, float size, int depth);
    };

private:

    struct IVec2KeyFuncs
    {
        size_t operator()(const glm::ivec2& k)const
        {
            return std::hash<int>()(k.x) ^ std::hash<int>()(k.y);
        }

        bool operator()(const glm::ivec2& a, const glm::ivec2& b)const
        {
            return a.x == b.x && a.y == b.y;
        }
    };

    std::unordered_map<glm::ivec2, Chunk*, IVec2KeyFuncs, IVec2KeyFuncs> chunk_cache = std::unordered_map<glm::ivec2, Chunk*, IVec2KeyFuncs, IVec2KeyFuncs>();

    public:

    WorldGenerator(int seed, float max_height);

    glm::vec2 get_world_coordinates( const glm::ivec2 &chunk_coordinates);

    glm::ivec2 get_chunk_coordinates( const glm::vec2 &world_coordinates );

    Chunk* get_chunk_at(const glm::ivec2 &chunk_coordinates);

    Chunk* get_chunk_at(const glm::ivec2 &chunk_coordinates, int lod);

    Chunk* get_at(const glm::vec3 &position);

    Chunk* get_at(const glm::vec2 &position);

    Chunk* get_at(const glm::vec2 &position, int lod);

    std::vector<Chunk*> get_within(const glm::vec2 &point, float radius, int lod);

    ~WorldGenerator();
};


#endif //TERRAINEXPLORER_WORLDGENERATOR_H
