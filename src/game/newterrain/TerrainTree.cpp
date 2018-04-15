#include "TerrainTree.h"

TerrainTree::TerrainTree(TerrainGenerator* generator, glm::vec2 origin, float size, int depth)
	: generator(generator), root(generator, origin, size), mesh(depth * 5)
{

}

TerrainTree::Node::Node(TerrainGenerator* generator, const glm::vec2& origin, const float& size)
	: generator(generator)
{
	sw = {
		{
			origin.x,
			generator->get_height(origin.x, origin.y),
			origin.y
		},
		{
			0,
			0
		},
		{
			0,
			0,
			0
		}
	};

	nw = {
		{
			origin.x,
			generator->get_height(origin.x, origin.y + size),
			origin.y + size
		},
		{
			0,
			0
		},
		{
			0,
			0,
			0
		}
	};

	ne = {
		{
			origin.x + size,
			generator->get_height(origin.x + size, origin.y + size),
			origin.y + size
		},
		{
			0,
			0
		},
		{
			0,
			0,
			0
		}
	};

	se = {
		{
			origin.x + size,
			generator->get_height(origin.x + size, origin.y),
			origin.y
		},
		{
			0,
			0
		},
		{
			0,
			0,
			0
		}
	};

	center = {
		{
			origin.x + size * 0.5f,
			generator->get_height(origin.x + size * 0.5f, origin.y + size * 0.5f),
			origin.y + size * 0.5f
		},
		{
			0,
			0
		},
		{
			0,
			0,
			0
		}
	};
}

void TerrainTree::Node::update(int depth, Mesh & mesh)
{
	if (depth > 0) {
		glm::vec2 c = { center.xyz.x, center.xyz.y };
		float size = se.xyz.x - sw.xyz.x;

		if (!southeast) {
			glm::vec2 origin_se = { c.x - size * 0.5f, c.y };
			southeast = new Node(generator, origin_se, size * 0.5f);
		}

		if (!southwest) {
			glm::vec2 origin_sw = { c.x - size * 0.5f, c.y - size * 0.5f };
			southwest = new Node(generator, origin_sw, size * 0.5f);
		}

		if (!northwest) {
			glm::vec2 origin_nw = { c.x, c.y - size * 0.5f };
			northwest = new Node(generator, origin_nw, size * 0.5f);
		}

		if (!northeast) {
			northeast = new Node(generator, c, size * 0.5f);
		}

		southwest->update(depth - 1, mesh);
		southeast->update(depth - 1, mesh);
		northeast->update(depth - 1, mesh);
		northwest->update(depth - 1, mesh);
	}

	unsigned int i_sw = mesh.vert(sw);
	unsigned int i_nw = mesh.vert(nw);
	unsigned int i_ne = mesh.vert(ne);
	unsigned int i_se = mesh.vert(se);
	unsigned int i_c = mesh.vert(center);

	mesh.add_indices(
		{
			i_sw, i_c, i_nw,
			i_nw, i_c, i_ne,
			i_ne, i_c, i_se,
			i_se, i_c, i_sw
		}
	);
}

Vertex & TerrainTree::Node::get_nw()
{
	// TODO: insert return statement here
}

Vertex & TerrainTree::Node::get_ne()
{
	// TODO: insert return statement here
}

Vertex & TerrainTree::Node::get_se()
{
	// TODO: insert return statement here
}

Vertex & TerrainTree::Node::get_sw()
{
	// TODO: insert return statement here
}

Vertex & TerrainTree::Node::get_center()
{
	// TODO: insert return statement here
}

glm::vec2 TerrainTree::Node::get_origin()
{
	return glm::vec2();
}

float TerrainTree::Node::get_size()
{
	return 0.0f;
}

TerrainTree::Node::~Node()
{
	if (southeast) delete southeast;
	if (southwest) delete southwest;
	if (northwest) delete northwest;
	if (northeast) delete northeast;
}

void TerrainTree::update(int depth)
{
	root.update(depth, mesh);
}

void TerrainTree::draw(int depth, const ShaderProgram& program)
{
	update(depth);
	mesh.draw(program);
}

TerrainTree::~TerrainTree()
{
}
