#include "TerrainChunk.h"

TerrainChunk::TerrainChunk( glm::vec2 origin, float size, float max_height )
	: origin(origin), size(size), max_height(max_height), split(false)
{
	for (int i = 0; i < 4; i++) {
		children[i] = NULL;
	}
}

void TerrainChunk::split_chunk()
{
	/*
	=========
	| 2 | 3 |
	=========
	| 0 | 1 |
	=========
	*/
	if (is_split()) {
		for (int i = 0; i < 4; i++) {
			if ( children[i] != nullptr ) children[i]->split_chunk();
		}
		return;
	}

	children[0] = new TerrainChunk(
		origin, 
		size * 0.5f, 
		max_height
	); // lower-left
	children[1] = new TerrainChunk(
		{
			origin.x + size * 0.5f, 
			origin.y
		}, 
		size * 0.5f, 
		max_height
	); // lower-right
	children[2] = new TerrainChunk(
		{
			origin.x, 
			origin.y + size * 0.5f 
		}, 
		size * 0.5f, 
		max_height
	); // upper-left
	children[3] = new TerrainChunk(
		{
			origin.x + size * 0.5f, 
			origin.y + size * 0.5f 
		}, 
		size * 0.5f, 
		max_height
	); // upper-right

	this->split = true;
}

bool TerrainChunk::is_split() 
{
	return split;
}

void TerrainChunk::join_chunk()
{
	this->split = false;
}

void TerrainChunk::generate_vertices(TerrainGenerator* generator, std::vector<Vertex>& vertices, std::vector<GLuint>& elements)
{
	if (is_split()) {
		for (int i = 0; i < 4; i++) {
			if (children[i] != nullptr) children[i]->generate_vertices(generator, vertices, elements);
		}
		return;
	}

	/*
    v3            v4
	================ 
	|\            /| 
	| \          / | 
	|  \        /  | 
	|   \      /   | 
	|    \    /    | 
	|     \  /     | 
	|      \/ v5   | 
	|      /\      | 
	|     /  \     | 
	|    /    \    | 
	|   /      \   | 
	|  /        \  | 
	| /          \ | 
	|/            \| 
	================
	v1 (origin)   v2

	v1 = {x,          y,          gen(x,y)}
	v2 = {x + size,   y,          gen(x,y)}
	v3 = {x,          y + size,   gen(x,y)}
	v4 = {x + size,   y + size,   gen(x,y)}
	v5 = {x + size/2, y + size/2, gen(x,y)}

	order:

	v1, v5, v2
	v2, v5, v4
	v4, v5, v3
	v3, v5, v1
	*/ 
	
	Vertex v1 = { 
		{ 
			origin.x, 
			max_height * generator->get_height(origin),
			origin.y 
		},
		{ 0, 0 }, 
		{ 0, 0, 0 } 
	};

	Vertex v2 = { 
		{ 
			origin.x + size, 
			max_height * generator->get_height(origin.x + size, origin.y), 
			origin.y 
		},
		{ 0, 0 }, 
		{ 0, 0, 0 } 
	};

	Vertex v3 = { 
		{ 
			origin.x, 
			max_height * generator->get_height(origin.x, origin.y + size),
			origin.y + size
		},
		{ 0, 0 },
		{ 0, 0, 0 } 
	};

	Vertex v4 = { 
		{ 
			origin.x + size, 
			max_height * generator->get_height(origin.x + size, origin.y + size),
			origin.y + size
		},
		{ 0, 0 },
		{ 0, 0, 0 } 
	};

	Vertex v5 = { 
		{ 
			origin.x + size/2, 
			max_height * generator->get_height(origin.x + size / 2, origin.y + size / 2),
			origin.y + size/2
		},
		{ 0, 0 },
		{ 0, 0, 0 } 
	};

	int i1 = vertices.size();
	vertices.push_back(v1);

	int i2 = vertices.size();
	vertices.push_back(v2);

	int i3 = vertices.size();
	vertices.push_back(v3);

	int i4 = vertices.size();
	vertices.push_back(v4);

	int i5 = vertices.size();
	vertices.push_back(v5);

	elements.push_back(i1);
	elements.push_back(i5);
	elements.push_back(i2);

	elements.push_back(i2);
	elements.push_back(i5);
	elements.push_back(i4);

	elements.push_back(i4);
	elements.push_back(i5);
	elements.push_back(i3);
	
	elements.push_back(i3);
	elements.push_back(i5);
	elements.push_back(i1);
}

TerrainChunk::~TerrainChunk()
{
	for (int i = 0; i < 4; i++) {
		delete children[i];
		children[i] = NULL;
	}
}
