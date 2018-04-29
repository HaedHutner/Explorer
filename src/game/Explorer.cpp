#include <game/terrain/SimpleHeightmap.h>
#include "Explorer.h"

Explorer::Explorer()
        : Game("Explorer", 800, 600),
          test_shader() {
}

void Explorer::run() {
    test_shader = ShaderProgram::from_files("resources/simple.vert", "resources/simple.frag");
    test_shader.link();

    camera = new Camera(90.0, 5, 1, Game::width, Game::height);

    glClearColor(0.5, 0.1, 0.5, 1.0);

    TerrainGenerator *generator = new TerrainGenerator(115231, 64.0f);

    double timeBefore = glfwGetTime();

    Heightmap center = SimpleHeightmap(generator, {0,0}, {256, 256});

    terrain = new HeightmapTerrain(center, {});

    double timeAfter = glfwGetTime();

    Log::info("Generating terrain took %.3f seconds.", timeAfter - timeBefore);

    renderer = new SimpleTerrainRenderer(camera, terrain);

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
    delete renderer;
    delete camera;
}