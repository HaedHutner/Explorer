#ifndef _GAME_H
#define _GAME_H

#include <glad\glad.h>
#include <GLFW\glfw3.h>

#include <stdio.h>

class Game {
private:

	const char* name;
	int width;
	int height;

	static void glfwErrorCallback(int error, const char* description);

protected:

	GLFWwindow * context;

	Game(const char* name, int width, int height);

	virtual void tick();

	virtual void render();

public:

	bool init();

	void run();

	int stop();

};

#endif