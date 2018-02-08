#ifndef _EXPLORER_H
#define _EXPLORER_H

#include <engine\Game.h>

class Explorer : public Game {
private:

	Camera * camera;

	ShaderProgram test_shader;
	Model* test;
	SimpleRenderer* test_renderer;

	void tick() override;

	void render() override;

public:

	Explorer( const int width, const int height );

	void run() override;

	~Explorer();

};

#endif
