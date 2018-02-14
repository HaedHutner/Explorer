#include "SimpleTexture.h"

SimpleTexture::SimpleTexture(const char * path)
	: Texture()
{
	glBindTexture(GL_TEXTURE_2D, this->texture_id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width = 512, height = 512, channels;

	unsigned char* image = stbi_load(path, &width, &height, &channels, 0);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	this->w = width;
	this->h = height;
	stbi_image_free(image);

}

SimpleTexture::~SimpleTexture()
{
	glDeleteTextures(1, &this->texture_id);
}
