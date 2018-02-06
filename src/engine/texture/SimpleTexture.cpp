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

	int channels = 0;
	unsigned char* image = stbi_load(path, &this->w, &this->h, &channels, 0);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, this->w, this->h, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	stbi_image_free(image);

}

SimpleTexture::~SimpleTexture()
{
	glDeleteTextures(1, &this->texture_id);
}
