#include <glad\glad.h>
#include <GLFW\glfw3.h>

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

#include <SOIL.h>

#include <stdio.h>

GLFWwindow* init() {
	int glfwInitRes = glfwInit();
	if (!glfwInitRes) {
		fprintf(stderr, "Unable to initialize GLFW\n");
		return nullptr;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLFWwindow* window = glfwCreateWindow(1280, 720, "InitGL", nullptr, nullptr);
	if (!window) {
		fprintf(stderr, "Unable to create GLFW window\n");
		glfwTerminate();
		return nullptr;
	}

	glfwMakeContextCurrent(window);

	int gladInitRes = gladLoadGL();
	if (!gladInitRes) {
		fprintf(stderr, "Unable to initialize glad\n");
		glfwDestroyWindow(window);
		glfwTerminate();
		return nullptr;
	}

	return window;
}

void errorCallback(int error, const char* description) {
	fprintf(stderr, "GLFW error %d: %s\n", error, description);
}

int main() {
	glfwSetErrorCallback(errorCallback);

	GLFWwindow* window = init();
	if (!window) return -1;

	// Set the clear color to a nice green
	glClearColor(0.15f, 0.6f, 0.4f, 1.0f);

	glm::mat4 test = glm::mat4();

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}