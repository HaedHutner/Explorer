#ifndef _TEXTURE_H
#define _TEXTURE_H

#include <glad\glad.h>

class Texture {
protected:
	GLuint texture_id;
	GLsizei w, h;

public:

	Texture();

	GLuint id();

	GLsizei width();

	GLsizei height();

	~Texture();

};

#endif