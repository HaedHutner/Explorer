#include "SimpleTexture.h"

SimpleTexture::SimpleTexture(const char *path)
        : Texture() {
    glBindTexture(GL_TEXTURE_2D, this->tex_id);

    int width(0), height(0), channels(3);
    unsigned char *image = stbi_load(path, &width, &height, &channels, 0);

    if (NULL == image) {
        Log::error("Failed to load texture: %s", path);
        return;
    }

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    this->w = width;
    this->h = height;
    stbi_image_free(image);

}

void SimpleTexture::bind(GLint unit) const {
    glActiveTexture(unit);
    glBindTexture(GL_TEXTURE_2D, this->tex_id);
}

SimpleTexture::~SimpleTexture() = default;
