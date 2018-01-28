#ifndef _SIMPLE_TEXTURE_H
#define _SIMPLE_TEXTURE_H

#include <glad\glad.h>
#include <SOIL.h>

#include <engine\texture\Texture.h>

class SimpleTexture : public Texture {
public:

	SimpleTexture(const char* path);

	~SimpleTexture();

};

#endif