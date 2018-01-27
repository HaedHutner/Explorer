#ifndef _EXPLORER_H
#define _EXPLORER_H

#include <engine\Game.h>

class Explorer : public Game {
public:

	Explorer( const int width, const int height );

private:

	void tick();

	void render();

};

#endif
