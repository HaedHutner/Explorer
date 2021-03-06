#include "ShaderProgram.h"

ShaderProgram::ShaderProgram() {
}

GLuint ShaderProgram::create_shader(const std::string source, GLenum type) {

    GLint _shader = glCreateShader(type);

    const GLchar *c_source = source.c_str();
    glShaderSource(_shader, 1, &c_source, NULL);
    glCompileShader(_shader);

    GLint success = 0;
    glGetShaderiv(_shader, GL_COMPILE_STATUS, &success);
    if (success == GL_FALSE) {
        GLint len = 0;
        glGetShaderiv(_shader, GL_INFO_LOG_LENGTH, &len);

        char errorLog[2048];
        glGetShaderInfoLog(_shader, len, 0, errorLog);

        Log::error("SHADER::%s::COMPILATION_ERROR(%d; %d):\n%s", ((type == GL_VERTEX_SHADER) ? "VERTEX" : "FRAGMENT"),
                   len, success, errorLog);

        glDeleteShader(_shader);
        return -1;
    }

    return _shader;
}

ShaderProgram::ShaderProgram(const std::string &vertexSrc, const std::string &fragmentSrc) {
    vertex_shader = create_shader(vertexSrc, GL_VERTEX_SHADER);
    if (vertex_shader == -1) {
        Log::error("SHADER::VERTEX::LOAD_FAILED");
        return;
    }
    fragment_shader = create_shader(fragmentSrc, GL_FRAGMENT_SHADER);
    if (fragment_shader == -1) {
        Log::error("SHADER::FRAGMENT::LOAD_FAILED");
        return;
    }

    program_id = glCreateProgram();
    glAttachShader(program_id, vertex_shader);
    glAttachShader(program_id, fragment_shader);
}

ShaderProgram ShaderProgram::from_sources(const std::string &vertexSrc, const std::string &fragmentSrc) {
    return ShaderProgram(vertexSrc, fragmentSrc);
}

ShaderProgram ShaderProgram::from_files(const std::string &vertexPath, const std::string &fragmentPath) {
    std::string vertexSrc = FileUtils::file_to_string(vertexPath);
    std::string fragmentSrc = FileUtils::file_to_string(fragmentPath);

    ShaderProgram program = ShaderProgram(vertexSrc.c_str(), fragmentSrc.c_str());

    return program;
}

void ShaderProgram::clear() {
    glDeleteProgram(program_id);
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);
}

void
ShaderProgram::set_uniform_texture(const std::string &name, const Texture &texture, const GLint &texture_unit) const {
    texture.bind(GL_TEXTURE0 + texture_unit);
    set_uniform_int(name, texture_unit);
}

void ShaderProgram::set_uniform_bool(const std::string &name, bool value) const {
    glUniform1i(glGetUniformLocation(program_id, name.c_str()), (int) value);
}

void ShaderProgram::set_uniform_int(const std::string &name, int value) const {
    glUniform1i(glGetUniformLocation(program_id, name.c_str()), value);
}

void ShaderProgram::set_uniform_float(const std::string &name, float value) const {
    glUniform1f(glGetUniformLocation(program_id, name.c_str()), value);
}

void ShaderProgram::set_uniform_double(const std::string &name, double value) const {
    glUniform1d(glGetUniformLocation(program_id, name.c_str()), value);
}

void ShaderProgram::set_uniform_mat4(const std::string &name, const glm::mat4 &matrix) const {
    glUniformMatrix4fv(glGetUniformLocation(program_id, name.c_str()), 1, GL_FALSE, glm::value_ptr(matrix));
}

void ShaderProgram::set_uniform_ivec2(const std::string &name, const glm::ivec2 &vector) const {
    glUniform2i(glGetUniformLocation(program_id, name.c_str()), vector.x, vector.y);
}

void ShaderProgram::set_uniform_vec2(const std::string &name, const glm::vec2 &vector) const {
    glUniform2f(glGetUniformLocation(program_id, name.c_str()), vector.x, vector.y);
}

void ShaderProgram::set_uniform_vec3(const std::string &name, const glm::vec3 &vector) const {
    glUniform3f(glGetUniformLocation(program_id, name.c_str()), vector.x, vector.y, vector.z);
}

void ShaderProgram::set_uniform_vec4(const std::string &name, const glm::vec4 &vector) const {
    glUniform4f(glGetUniformLocation(program_id, name.c_str()), vector.x, vector.y, vector.z, vector.w);
}

void ShaderProgram::link() {
    Vertex::bindAttribs(id());

    glLinkProgram(program_id);

    GLint isLinked = 0;
    glGetProgramiv(program_id, GL_LINK_STATUS, &isLinked);
    if (isLinked == GL_FALSE) {
        GLint maxLength = 0;
        glGetProgramiv(program_id, GL_INFO_LOG_LENGTH, &maxLength);

        std::vector<GLchar> infoLog(maxLength);
        glGetProgramInfoLog(program_id, maxLength, &maxLength, &infoLog[0]);

        glDeleteProgram(program_id);

        Log::error("GLSL Program Link Error: %s", &infoLog[0]);

        return;
    }
}

const void ShaderProgram::use() const { glUseProgram(program_id); }

const GLuint ShaderProgram::id() const { return program_id; }
