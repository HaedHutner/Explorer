#ifndef _TEXTURE_H
#define _TEXTURE_H

#include <glad\glad.h>
#include <stb_image.h>

#include <util\Log.h>


class Texture {
protected:
	GLuint tex_id;
	GLsizei w, h;

public:

	Texture();

	GLuint texture_id() const;

	GLsizei width() const;

	GLsizei height() const;

	virtual void bind(GLint unit) const = 0;

	~Texture();

};

#endif