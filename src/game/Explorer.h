#ifndef _EXPLORER_H
#define _EXPLORER_H

#include <engine\Game.h>
#include <game/terrain/SimpleHeightmap.h>
#include <game/terrain/HeightmapRenderer.h>


class Explorer : public Game {
private:

    Camera *camera;

    ShaderProgram test_shader;

    Heightmap *terrain;
    AbstractRenderer *renderer;

    void tick() override;

    void render() override;

    Explorer();

public:

    static Explorer &instance() {
        static Explorer explorer;
        return explorer;
    }

    Explorer(const Explorer &) = delete;

    Explorer(Explorer &&) = delete;

    void operator=(const Explorer &) = delete;

    void operator=(Explorer &&) = delete;

    void run() override;

    ~Explorer();

};

#endif
