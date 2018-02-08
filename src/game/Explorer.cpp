#include "Explorer.h"

Explorer::Explorer( const int width, const int height ) 
	: Game("Explorer", width, height), camera(new Camera(90.0, 1, 1, width, height)), test_renderer(new SimpleRenderer(camera, {}))
{
}

void Explorer::run() {
	glClearColor(0.5, 0.1, 0.5, 1.0);

	test_shader = ShaderProgram::from_files("resources/simple.vert", "resources/simple.frag");

	Mesh test_mesh = Mesh(
		{
			{ {1.0, 0.0, 1.0}, {0.0, 1.0}, {0.0, 0.0, 0.0} },
			{}
		}, 
		{}
	);

	SimpleTexture test_texture = SimpleTexture("resources/textures/test.png");

	test = new Model(test_mesh, test_texture);
	
	test_renderer = new SimpleRenderer(camera, { test });

	Game::run();
}

void Explorer::tick() {
	Game::tick();
}

void Explorer::render() {
	Game::render();
	test_renderer->render(test_shader);
}

Explorer::~Explorer() {
	delete test_renderer;
	delete camera;
}