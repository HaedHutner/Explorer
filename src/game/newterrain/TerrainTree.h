#ifndef _TERRAIN_TREE_H
#define _TERRAIN_TREE_H

#include <engine\Engine.h>

#include <game\newterrain\TerrainGenerator.h>

class TerrainTree {

	class Node {
		TerrainGenerator* generator;

		Vertex nw;
		Vertex ne;
		Vertex se;
		Vertex sw;
		Vertex center;

		Node* northwest;
		Node* northeast;
		Node* southeast;
		Node* southwest;

	public:

		Node(TerrainGenerator* generator, const glm::vec2& origin, const float& size);

		void update(int depth, Mesh& mesh);

		Vertex& get_nw();

		Vertex& get_ne();

		Vertex& get_se();

		Vertex& get_sw();

		Vertex& get_center();

		glm::vec2 get_origin();

		float get_size();

		~Node();

	};

	TerrainGenerator* generator;

	Node root;

	Mesh mesh;

public:

	TerrainTree(TerrainGenerator* generator, glm::vec2 origin, float size, int depth);

	void update(int depth);

	void draw(int depth, const ShaderProgram& program);

	~TerrainTree();

};

#endif