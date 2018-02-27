#include "TerrainGenerator.h"

TerrainGenerator::TerrainGenerator(FastNoise * noiseGen)
	: generator(noiseGen)
{
}

TerrainGenerator::TerrainGenerator(int seed)
	: generator(new FastNoise(seed))
{
	generator->SetNoiseType(FastNoise::NoiseType::Perlin);
}

FN_DECIMAL TerrainGenerator::get_height(const glm::vec2& coords)
{
	return generator->GetNoise(coords.x, coords.y);
}

FN_DECIMAL TerrainGenerator::get_height(FN_DECIMAL x, FN_DECIMAL y)
{
	return generator->GetNoise(x, y);
}

TerrainGenerator::~TerrainGenerator()
{
	delete generator;
}
