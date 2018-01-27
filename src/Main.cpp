#include <iostream>
#include <GLFW\glfw3.h>

int main() {
	std::cout << "Working!" << std::endl;

	if (glfwInit()) {
		std::cout << "GLFW Working!" << std::endl;
	}

	return 0;
}