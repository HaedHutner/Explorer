//
// Created by Miro on 4/30/2018.
//

#include "QuadTerrain.h"

QuadTerrain::QuadTerrain(TerrainGenerator *generator, const glm::vec2 &origin, float size, int depth)
        : origin(origin), size(size), depth(depth), generator(generator)
{
    root = nullptr;
    mesh = nullptr;
    //Log::info("Generating from {%f, %f} to {%f, %f}", origin.x, origin.y, origin.x + size, origin.y + size);
    set_depth(depth);
}

/*

 nw      n       ne
  +------+-------+
  |      |       |
  |  NW  |  NE   |
  |      |       |
 w|------c-------|e
  |      |       |
  |  SW  |  SE   |
  |      |       |
  +------+-------+
 sw      s       se

*/

QuadTerrain::Node::Node(
        std::vector<Vertex> &vertices,
        std::vector<GLuint> &elements,
        TerrainGenerator *generator,
        const glm::vec2 &origin,
        float size,
        int depth
)
    : size(size), origin(origin)
{

    NW = nullptr;
    NE = nullptr;
    SE = nullptr;
    SW = nullptr;

    generate(vertices, elements, generator, origin, size, depth);
}

QuadTerrain::Node::~Node() {
    delete NW;
    delete NE;
    delete SE;
    delete SW;
}

void QuadTerrain::Node::generate(
        std::vector<Vertex> &vertices,
        std::vector<GLuint> &elements,
        TerrainGenerator *generator,
        const glm::vec2 &origin,
        float size,
        int depth
) {
    if (depth != 0) {
        SW = new Node(
                vertices,
                elements,
                generator,
                origin,
                size / 2,
                depth - 1
        );

        NW = new Node(
                vertices,
                elements,
                generator,
                {origin.x, origin.y + size / 2.0f},
                size / 2,
                depth - 1
        );

        NE = new Node(
                vertices,
                elements,
                generator,
                {origin.x + size / 2.0f, origin.y + size / 2.0f},
                size / 2,
                depth - 1
        );

        SE = new Node(
                vertices,
                elements,
                generator,
                {origin.x + size / 2.0f, origin.y},
                size / 2,
                depth - 1
        );

        return;
    }

    sw = Vertex{
            {
                    origin.x,
                    generator->get_height(origin.x, origin.y),
                    origin.y
            },
            { 0, 0 },
            {}
    };
    unsigned int i1 = vertices.size();
    vertices.push_back(sw);

    se = Vertex{
            {
                    origin.x + size,
                    generator->get_height(origin.x + size, origin.y),
                    origin.y
            },
            { 1, 0 },
            {}
    };
    unsigned int i2 = vertices.size();
    vertices.push_back(se);

    ne = Vertex{
            {
                    origin.x + size,
                    generator->get_height(origin.x + size, origin.y + size),
                    origin.y + size
            },
            { 1, 1 },
            {}
    };
    unsigned int i3 = vertices.size();
    vertices.push_back(ne);

    nw = Vertex{
            {
                    origin.x,
                    generator->get_height(origin.x, origin.y + size),
                    origin.y + size
            },
            { 0, 1 },
            {}
    };
    unsigned int i4 = vertices.size();
    vertices.push_back(nw);

    center = Vertex{
            {
                    origin.x + size / 2.0,
                    generator->get_height(origin.x + size / 2.0f, origin.y + size / 2.0f),
                    origin.y + size / 2.0
            },
            { 0.5, 0.5 },
            {}
    };
    unsigned int i5 = vertices.size();
    vertices.push_back(center);

    elements.push_back(i1);
    elements.push_back(i5);
    elements.push_back(i2);

    elements.push_back(i2);
    elements.push_back(i5);
    elements.push_back(i3);

    elements.push_back(i3);
    elements.push_back(i5);
    elements.push_back(i4);

    elements.push_back(i4);
    elements.push_back(i5);
    elements.push_back(i1);
}

void QuadTerrain::Node::update_depth(
        TerrainGenerator *generator,
        std::vector<Vertex> &vertices,
        std::vector<GLuint> &elements,
        int depth
) {
    if ( depth != 0 ) {

        if ( !SW ) {
            SW = new Node(
                    vertices,
                    elements,
                    generator,
                    origin,
                    size / 2,
                    depth - 1
            );
        } else SW->update_depth(generator, vertices, elements, depth-1);

        if ( !NW ) {
            NW = new Node(
                    vertices,
                    elements,
                    generator,
                    {origin.x, origin.y + size / 2.0f},
                    size / 2,
                    depth - 1
            );
        } else NW->update_depth(generator, vertices, elements, depth-1);

        if ( !NE ) {
            NE = new Node(
                    vertices,
                    elements,
                    generator,
                    {origin.x + size / 2.0f, origin.y + size / 2.0f},
                    size / 2,
                    depth - 1
            );
        } else NE->update_depth(generator, vertices, elements, depth-1);

        if ( !SE ) {
            SE = new Node(
                    vertices,
                    elements,
                    generator,
                    {origin.x + size / 2.0f, origin.y},
                    size / 2,
                    depth - 1
            );
        } else SE->update_depth(generator, vertices, elements, depth-1);

        return;
    }

    if ( sw.xyz.x == 0 && sw.xyz.y == 0 && sw.xyz.z == 0 ) {
        generate( vertices, elements, generator, origin, size, 0);
    } else {
        unsigned int i1 = vertices.size();
        vertices.push_back(sw);

        unsigned int i2 = vertices.size();
        vertices.push_back(se);

        unsigned int i3 = vertices.size();
        vertices.push_back(ne);

        unsigned int i4 = vertices.size();
        vertices.push_back(nw);

        unsigned int i5 = vertices.size();
        vertices.push_back(center);

        elements.push_back(i1);
        elements.push_back(i5);
        elements.push_back(i2);

        elements.push_back(i2);
        elements.push_back(i5);
        elements.push_back(i3);

        elements.push_back(i3);
        elements.push_back(i5);
        elements.push_back(i4);

        elements.push_back(i4);
        elements.push_back(i5);
        elements.push_back(i1);
    }
}

void QuadTerrain::draw(const ShaderProgram &program) {
    mesh->draw(program);
}

float QuadTerrain::get_height(int x, int y) {
    return 0;
}

float QuadTerrain::get_max_height() {
    return 0;
}

glm::vec2 QuadTerrain::get_size() {
    return glm::vec2();
}

glm::ivec2 QuadTerrain::get_origin() {
    return origin;
}

void QuadTerrain::set_depth(int depth) {
    std::vector<Vertex> vertices(size * size);
    std::vector<GLuint> elements(size * size * 6);

    if ( root ) {
        root->update_depth(generator, vertices, elements, depth);
    } else {
        root = new Node(
                vertices,
                elements,
                generator,
                origin,
                size,
                depth
        );
    }

    if ( mesh ) {
        mesh->set_vertices(vertices);
        mesh->set_elements(elements);
    } else {
        mesh = new Mesh(vertices, elements, new SimpleTexture("resources/textures/none.png"));
    }

    QuadTerrain::depth = depth;
}

int QuadTerrain::get_depth() {
    return depth;
}

QuadTerrain::~QuadTerrain() {
    delete mesh;
    delete root;
}
