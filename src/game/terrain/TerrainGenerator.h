#ifndef _TERRAIN_GENERATOR_H
#define _TERRAIN_GENERATOR_H

#include <FastNoise.h>

class TerrainGenerator {

	FastNoise* generator;

public:

	TerrainGenerator(FastNoise* noiseGen);

	TerrainGenerator(int seed);

	FN_DECIMAL get_height(FN_DECIMAL x, FN_DECIMAL y);

	~TerrainGenerator();

};

#endif