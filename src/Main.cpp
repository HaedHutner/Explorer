#include <game\Explorer.h>

int main() {
	Explorer game = Explorer(640, 480);
	if (game.init()) {
		game.run();
	}

	return game.stop();
}