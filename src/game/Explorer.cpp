#include "Explorer.h"

Explorer::Explorer()
        : Game("Explorer", 800, 600),
          test_shader() {
}

void Explorer::run() {
    test_shader = ShaderProgram::from_files("resources/simple.vert", "resources/simple.frag");
    //test_shader = ShaderProgram::from_files("resources/heightmap.vert", "resources/heightmap.frag");
    test_shader.link();

    camera = new Camera(90.0, 5, 1, Game::width, Game::height);

    glClearColor(0.5, 0.1, 0.5, 1.0);

    renderer = new WorldRenderer( camera, new WorldGenerator(874528, 64.0f) );

    //generator = new TerrainGenerator(874528, 64.0f);
    //heightmap = new SimpleHeightmap(generator, {0, 0}, {256, 256});

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
}

void Explorer::render() {
    Game::render();
    /*test_shader.use();
    test_shader.set_uniform_mat4("view", camera->get_view());
    test_shader.set_uniform_mat4("projection", camera->get_projection());
    test_shader.set_uniform_mat4("model", glm::mat4(1.0f));

    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glCullFace(GL_BACK);

    heightmap->draw(test_shader);*/
    renderer->render(test_shader);
}

Explorer::~Explorer() {
    //delete heightmap;
    //delete generator;
    delete renderer;
    delete camera;
}