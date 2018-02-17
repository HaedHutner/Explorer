#include "Game.h"

Game::Game(const char* name, const int width, const int height) 
	: name(name), width(width), height(height)
{
}

bool Game::init()
{
	Log::info("Starting...");

	int glfwInitRes = glfwInit();
	if (!glfwInitRes) {
		Log::error("Unable to initialize GLFW");
		return false;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	context = glfwCreateWindow(width, height, name, nullptr, nullptr);
	if (!context) {
		Log::error("Unable to create GLFW window");

		glfwTerminate();

		return false;
	}

	glfwMakeContextCurrent(context);

	int gladInitRes = gladLoadGL();
	if (!gladInitRes) {
		Log::error("Unable to init GLAD");

		glfwDestroyWindow(context);
		glfwTerminate();

		return false;
	}

	glfwSetErrorCallback(glfwErrorCallback);
	glfwSetWindowSizeCallback(context, on_screen_resize);

	return true;
}

void Game::run()
{
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
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

int Game::stop()
{
	glfwDestroyWindow(context);
	glfwTerminate();

	return 0;
}

void Game::glfwErrorCallback(int error, const char * description)
{
	Log::error("GLFW Error %d: %s\n", error, description);
}

void Game::on_screen_resize(GLFWwindow *context, int width, int height) {
    glViewport( 0, 0, width, height );
}
