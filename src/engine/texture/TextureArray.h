#ifndef _TEXTURE_ARRAY_H
#define _TEXTURE_ARRAY_H

#include <engine\texture\Texture.h>

#include <string>
#include <vector>

class TextureArray : public Texture {
private:
	GLubyte num_textures;

public:

	TextureArray(int width, int height, const std::vector<std::string>& texturePaths);

	void bind(GLint unit) const;

	~TextureArray();
};


#endif