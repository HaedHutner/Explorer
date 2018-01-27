#include "Game.h"

Game::Game(const char* name, const int width, const int height) 
	: name(name), width(width), height(height)
{
}

bool Game::init()
{
	int glfwInitRes = glfwInit();
	if (!glfwInitRes) {
		fprintf(stderr, "Unable to initialize GLFW\n");
		return false;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	context = glfwCreateWindow(width, height, name, nullptr, nullptr);
	if (!context) {
		fprintf(stderr, "Unable to create GLFW window\n");

		glfwTerminate();

		return false;
	}

	glfwMakeContextCurrent(context);

	int gladInitRes = gladLoadGL();
	if (!gladInitRes) {
		fprintf(stderr, "Unable to initialize glad\n");

		glfwDestroyWindow(context);
		glfwTerminate();

		return false;
	}

	glfwSetErrorCallback(glfwErrorCallback);

	return true;
}

void Game::run()
{
	glClearColor(0.15f, 0.3f, 0.7f, 1.0f);

	while (!glfwWindowShouldClose(context)) {
		tick();
		render();
	}
}

void Game::tick()
{
	glfwSwapBuffers(context);
	glfwPollEvents();
}

void Game::render()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

int Game::stop()
{
	glfwDestroyWindow(context);
	glfwTerminate();

	return 0;
}

void Game::glfwErrorCallback(int error, const char * description)
{
	fprintf(stderr, "GLFW error %d: %s\n", error, description);
}
