#ifndef _SHADER_PROGRAM_H
#define _SHADER_PROGRAM_H

#include <glad\glad.h>
#include <glm\glm.hpp>
#include <glm\gtc\type_ptr.hpp>

#include <string>

#include <engine\render\Vertex.h>
#include <engine\texture\Texture.h>

#include <util/Log.h>
#include <util/FileUtils.hpp>

class ShaderProgram {
private:
    GLuint program_id;

    GLuint vertex_shader;
    GLuint fragment_shader;

    static GLuint create_shader(const std::string source, GLenum type);

    ShaderProgram(const std::string &vertexSrc, const std::string &fragmentSrc);

public:

    ShaderProgram();

    static ShaderProgram from_sources(const std::string &vertexSrc, const std::string &fragmentSrc);

    static ShaderProgram from_files(const std::string &vertexPath, const std::string &fragmentPath);

    void set_uniform_texture(const std::string &name, const Texture &texture, const GLint &texture_unit) const;

    void set_uniform_bool(const std::string &name, bool value) const;

    void set_uniform_int(const std::string &name, int value) const;

    void set_uniform_float(const std::string &name, float value) const;

    void set_uniform_double(const std::string &name, double value) const;

    void set_uniform_mat4(const std::string &name, const glm::mat4 &matrix) const;

    void set_uniform_vec3(const std::string &name, const glm::vec3 &vector) const;

    void set_uniform_vec4(const std::string &name, const glm::vec4 &vector) const;

    void link();

    const void use() const;

    void clear();

    const GLuint id() const;
};


#endif