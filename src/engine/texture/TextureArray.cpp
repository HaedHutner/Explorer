#include "TextureArray.h"

TextureArray::TextureArray(int width, int height, const std::vector<std::string>& texturePaths) 
	: Texture(), num_textures(texturePaths.size()) 
{
	glBindTexture(GL_TEXTURE_2D_ARRAY, id() );

	glTexImage3D(GL_TEXTURE_2D_ARRAY, 0, GL_RGBA8, width, height, num_textures, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);

	for (int i = 0; i < num_textures; i++) {
		int channels = 0;
		unsigned char* image = stbi_load(texturePaths[i].c_str(), &this->w, &this->h, &channels, 0);
		glTexSubImage3D(GL_TEXTURE_2D_ARRAY, 0, 0, 0, i, width, height, 1, GL_RGB, GL_UNSIGNED_BYTE, image);
		stbi_image_free(image);

		glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_T, GL_REPEAT);
	}

	this->w = width;
	this->h = height;
}

TextureArray::~TextureArray() {
	Texture::~Texture();
}
