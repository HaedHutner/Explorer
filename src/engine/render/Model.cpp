#include "Model.h"

#include <utility>

Model::Model()
        : meshes(std::vector<Mesh *>()), model(glm::mat4(1.0f)), position(glm::vec3()), rotation(glm::vec3()),
          scale(glm::vec3()) {
}

Model::Model(std::vector<Mesh *> meshes, const glm::vec3 &position, const glm::fvec3 &rotation, const glm::vec3 &scale)
        : meshes(std::move(meshes)), model(glm::mat4(1.0f)), position(position), rotation(rotation), scale(scale) {
    moveBy(position);
    rotateBy(rotation);
    scaleBy(scale);
}

glm::mat4 Model::get_model_matrix() {
    return model;
}

void Model::moveBy(const glm::vec3 &difference) {
    glm::translate(model, difference);
}

void Model::rotateBy(const glm::fvec3 &rotation) {
    if (rotation.x) rotateBy(rotation.x, glm::vec3(1, 0, 0));
    if (rotation.y) rotateBy(rotation.y, glm::vec3(0, 1, 0));
    if (rotation.z) rotateBy(rotation.z, glm::vec3(0, 0, 1));
}

void Model::rotateBy(float amount, const glm::vec3 &direction) {
    glm::rotate(model, amount, direction);
}

void Model::scaleBy(const glm::vec3 &difference) {
    glm::scale(model, difference);
}

void Model::tick() {
}

void Model::draw(const ShaderProgram &shader_program) {
    shader_program.set_uniform_mat4("model", model);
    for (Mesh *mesh : meshes) {
        mesh->draw(shader_program);
    }
}

Model::~Model() {
    for (Mesh *mesh : meshes) {
        delete mesh;
    }
}
