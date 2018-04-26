#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION

Texture::Texture() {
    glGenTextures(1, &tex_id);
}

GLuint Texture::texture_id() const {
    return tex_id;
}

GLsizei Texture::width() const {
    return w;
}

GLsizei Texture::height() const {
    return h;
}

Texture::~Texture() {
    glDeleteTextures(1, &tex_id);
}
