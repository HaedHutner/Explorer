#include "Explorer.h"

Explorer::Explorer()
        : Game("Explorer", 800, 600),
          test_shader() {
}

void Explorer::run() {
    test_shader = ShaderProgram::from_files("resources/heightmap.vert", "resources/heightmap.frag");
    test_shader.link();

    camera = new Camera(90.0, 5, 1, Game::width, Game::height);

    glClearColor(0.5, 0.1, 0.5, 1.0);

    TerrainGenerator *generator = new TerrainGenerator(115231, 64.0f);

    double timeBefore = glfwGetTime();

    terrain = new SimpleHeightmap(generator, {0,0}, {256, 256});

    double timeAfter = glfwGetTime();

    Log::info("Generating terrain took %.3f seconds.", timeAfter - timeBefore);

    renderer = new HeightmapRenderer(camera, terrain);

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

    //terrain->tick();
}

void Explorer::render() {
    Game::render();
    renderer->render(test_shader);
}

Explorer::~Explorer() {
    delete terrain;
    delete renderer;
    delete camera;
}