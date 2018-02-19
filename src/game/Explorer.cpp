#include "Explorer.h"

Explorer::Explorer( ) 
	: Game("Explorer", 800, 600),
	test_shader()
{
}

void Explorer::run() {
	test_shader = ShaderProgram::from_files("resources/simple.vert", "resources/simple.frag");
	test_shader.link();

	camera = new Camera(90.0, 1, 1, Game::width, Game::height);

	glClearColor(0.5, 0.1, 0.5, 1.0);

	TerrainGenerator* generator = new TerrainGenerator(1234);

	terrain = new SimpleTerrain(new SimpleTexture("resources/textures/terrain.bmp"), generator, 256);

	renderer = new TerrainRenderer(camera, terrain);

	//Mesh* test_mesh = new Mesh(
	//	{
	//		{ { -1.0f, -1.0f,  1.0f },{ 0.0f, 1.0f },{ 0.0f, 0.0f, 0.0f } },
	//		{ {  1.0f, -1.0f,  1.0f },{ 1.0f, 1.0f },{ 0.0f, 0.0f, 0.0f } },
	//		{ {  1.0f,  1.0f,  1.0f },{ 1.0f, 0.0f },{ 0.0f, 0.0f, 0.0f } },
	//		{ { -1.0f,  1.0f,  1.0f },{ 0.0f, 0.0f },{ 0.0f, 0.0f, 0.0f } },
	//		{ { -1.0f, -1.0f, -1.0f },{ 0.0f, 1.0f },{ 0.0f, 0.0f, 0.0f } },
	//		{ {  1.0f, -1.0f, -1.0f },{ 1.0f, 1.0f },{ 0.0f, 0.0f, 0.0f } },
	//		{ {  1.0f,  1.0f, -1.0f },{ 1.0f, 0.0f },{ 0.0f, 0.0f, 0.0f } },
	//		{ { -1.0f,  1.0f, -1.0f },{ 0.0f, 0.0f },{ 0.0f, 0.0f, 0.0f } },
	//	}, 
	//	{ 
	//		// front
	//		0, 1, 2,
	//		2, 3, 0,
	//	
	//		// top
	//		1, 5, 6,
	//		6, 2, 1,
	//	
	//		// back
	//		7, 6, 5,
	//		5, 4, 7,
	//	
	//		// bottom
	//		4, 0, 3,
	//		3, 7, 4,
	//	
	//		// left
	//		4, 5, 1,
	//		1, 0, 4,
	//
	//		// right
	//		3, 2, 6,
	//		6, 7, 3, 
	//	},
	//	test_texture
	//);

	//test = new Model({ test_mesh }, { 0, 0, 0 }, { 0.0f, 0.0f, 0.0f }, { 1, 1, 1 });
	
	//test_renderer = new SimpleRenderer(camera, { test }, false);

	Game::run();
}

void Explorer::tick() {
	Game::tick();

	double x, y;
	glfwGetCursorPos(Game::context, &x, &y);
	camera->process_mouse_input(Game::context, x, y);
	camera->process_key_input(Game::context);
	glfwGetFramebufferSize(Game::context, &(Game::width), &(Game::height));
	camera->update_projection(width, height);

	terrain->tick();
}

void Explorer::render() {
	Game::render();
	renderer->render(test_shader);
}

Explorer::~Explorer() {
	delete renderer;
	delete camera;
}