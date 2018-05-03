#ifndef _TERRAIN_GENERATOR_H
#define _TERRAIN_GENERATOR_H

#include <FastNoise.h>
#include <glm/glm.hpp>

class TerrainGenerator {

    FastNoise *generator;

    float max_height;

public:

    TerrainGenerator(FastNoise *noiseGen, float max_height);

    TerrainGenerator(int seed, float max_height);

    virtual float get_height(const glm::vec2 &coords);

    virtual float get_height(FN_DECIMAL x, FN_DECIMAL y);

    ~TerrainGenerator();

};

#endif