#ifndef _EXPLORER_H
#define _EXPLORER_H

#include <engine\Game.h>

class Explorer : public Game {
private:

	void tick();

	void render();

public:

	Explorer( const int width, const int height );

};

#endif
