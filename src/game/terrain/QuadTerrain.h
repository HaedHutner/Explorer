//
// Created by Miro on 4/30/2018.
//

#ifndef TERRAINEXPLORER_QUADTERRAIN_H
#define TERRAINEXPLORER_QUADTERRAIN_H


#include <engine/render/Mesh.h>
#include "Terrain.h"
#include "TerrainGenerator.h"

class QuadTerrain : public Terrain {

    class Node {

        glm::vec2 origin;
        float size;

        Node *NW;
        Node *NE;
        Node *SE;
        Node *SW;

        Vertex nw;
        Vertex sw;
        Vertex se;
        Vertex ne;
        Vertex center;

    public:

        Node(std::vector<Vertex> &vertices, std::vector<GLuint> &elements, TerrainGenerator *generator,
             const glm::vec2 &origin, float size, int depth);

        void generate(std::vector<Vertex> &vertices, std::vector<GLuint> &elements, TerrainGenerator *generator, const glm::vec2 &origin, float size, int depth);

        void update_depth(TerrainGenerator *generator, std::vector<Vertex> &vertices, std::vector<GLuint> &elements, int depth);

        ~Node();
    };

    Mesh *mesh;

    Node *root;

    TerrainGenerator* generator;
    glm::ivec2 origin;
    float size;
    int depth;

public:

    QuadTerrain(TerrainGenerator *generator, const glm::vec2 &origin, float size, int depth);

    void draw(const ShaderProgram &program) override;

    glm::ivec2 get_origin();

    float get_height(int x, int y) override;

    float get_max_height() override;

    glm::vec2 get_size() override;

    void set_depth(int depth);

    int get_depth();

    ~QuadTerrain() override;


};


#endif //TERRAINEXPLORER_QUADTERRAIN_H
