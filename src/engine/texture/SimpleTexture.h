#ifndef _SIMPLE_TEXTURE_H
#define _SIMPLE_TEXTURE_H

#include <engine\texture\Texture.h>

class SimpleTexture : public Texture {
public:

    SimpleTexture();

    SimpleTexture(const char *path);

    SimpleTexture(const int &width, const int &height, const int &channels, const unsigned char *data);

    ~SimpleTexture();

    void bind(GLint unit) const;
};

#endif