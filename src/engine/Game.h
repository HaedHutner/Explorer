#ifndef _GAME_H
#define _GAME_H

#include <engine\Engine.h>
#include <GLFW\glfw3.h>

#include <util\Log.h>

class Game {
private:

	static void glfwErrorCallback(int error, const char* description);

protected:

	GLFWwindow * context;

	const char* name;
	int width;
	int height;

	Game(const char* name, int width, int height);

	virtual void tick();

	virtual void render();

public:

	bool init();

	virtual void run();

	virtual int stop();

};

#endif