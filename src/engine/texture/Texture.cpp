#include "Texture.h"

Texture::Texture()
{
	glGenTextures(1, &texture_id);
}

GLuint Texture::id()
{
	return texture_id;
}

GLsizei Texture::width()
{
	return w;
}

GLsizei Texture::height()
{
	return h;
}

Texture::~Texture()
{
	glDeleteTextures(1, &texture_id);
}
