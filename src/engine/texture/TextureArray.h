#ifndef _TEXTURE_ARRAY_H
#define _TEXTURE_ARRAY_H

#include <glad\glad.h>
#include <SOIL.h>

#include <engine\texture\Texture.h>

#include <string>
#include <vector>

class TextureArray : public Texture {
private:
	GLubyte num_textures;

public:

	TextureArray(int width, int height, const std::vector<std::string>& texturePaths);

	~TextureArray();
};


#endif