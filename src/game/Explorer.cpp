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

//    TerrainGenerator *generator = new TerrainGenerator(115231, 64.0f);
//
//    double timeBefore = glfwGetTime();
//
//    simple_terrain = new QuadTerrain(generator, {0, 0}, 64, 8);
//    //simple_terrain = new SimpleTerrain(generator, {512, 512});
//    //simple_terrain = new SimpleHeightmap(generator, {0,0}, {256, 256});
//
//    double timeAfter = glfwGetTime();
//
//    //Log::info("Generating terrain took %.3f seconds.", timeAfter - timeBefore);
//
//    //renderer = new ChunkedTerrainRenderer(camera);
//
//    //renderer = new HeightmapRenderer(camera, terrain);
//    simple_terrain_renderer = new SimpleTerrainRenderer(camera, simple_terrain);

    renderer = new WorldRenderer( camera, new WorldGenerator(874528, 64.0f) );

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

//    if (glfwGetKey(Game::context, GLFW_KEY_UP) == GLFW_PRESS) {
//        depth++;
//        simple_terrain->set_depth(depth);
//        Log::info("Current Depth: %d", depth);
//    }
//
//    if (glfwGetKey(Game::context, GLFW_KEY_DOWN) == GLFW_PRESS) {
//        if ( depth != 0 ) {
//            depth--;
//            simple_terrain->set_depth(depth);
//        }
//        Log::info("Current Depth: %d", depth);
//    }

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