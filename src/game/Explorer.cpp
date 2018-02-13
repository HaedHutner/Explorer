#include "Explorer.h"

Explorer::Explorer( const int width, const int height ) 
	: Game("Explorer", width, height),
	test_shader()
{
}

void Explorer::run() {
	test_shader = ShaderProgram::from_files("resources/simple.vert", "resources/simple.frag");
	camera = new Camera(90.0, 1, 1, Game::width, Game::height);

	glClearColor(0.5, 0.1, 0.5, 1.0);

	Mesh test_mesh = Mesh(
		{
			{ { -1.0, -1.0,  1.0 },{ 0.0, 1.0 },{ 0.0, 0.0, 0.0 } },
			{ {  1.0, -1.0,  1.0 },{ 0.0, 1.0 },{ 0.0, 0.0, 0.0 } },
			{ {  1.0,  1.0,  1.0 },{ 0.0, 1.0 },{ 0.0, 0.0, 0.0 } },
			{ { -1.0,  1.0,  1.0 },{ 0.0, 1.0 },{ 0.0, 0.0, 0.0 } },
			{ { -1.0, -1.0, -1.0 },{ 0.0, 1.0 },{ 0.0, 0.0, 0.0 } },
			{ {  1.0, -1.0, -1.0 },{ 0.0, 1.0 },{ 0.0, 0.0, 0.0 } },
			{ {  1.0,  1.0, -1.0 },{ 0.0, 1.0 },{ 0.0, 0.0, 0.0 } },
			{ { -1.0,  1.0, -1.0 },{ 0.0, 1.0 },{ 0.0, 0.0, 0.0 } },
		}, 
		{ 
			// front
			0, 1, 2,
			2, 3, 0,
		
			// top
			1, 5, 6,
			6, 2, 1,
		
			// back
			7, 6, 5,
			5, 4, 7,
		
			// bottom
			4, 0, 3,
			3, 7, 4,
		
			// left
			4, 5, 1,
			1, 0, 4,
			// right
			3, 2, 6,
			6, 7, 3, 
		}
	);

	SimpleTexture test_texture = SimpleTexture("resources/textures/test.png");

	test = new Model(test_mesh, test_texture, {0, 0, 0}, {0.0f, 0.0f, 0.0f}, {1, 1, 1});
	
	test_renderer = new SimpleRenderer(camera, { test }, true);

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