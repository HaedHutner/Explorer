#ifndef _SIMPLE_TEXTURE_H
#define _SIMPLE_TEXTURE_H

#include <engine\texture\Texture.h>

class SimpleTexture : public Texture {
public:

	SimpleTexture(const char* path);

	~SimpleTexture();

};

#endif