#ifndef _TERRAIN_TREE_H
#define _TERRAIN_TREE_H

#include <game\newterrain\Terrain.h>
#include <game\newterrain\TerrainChunk.h>

class TerrainTree {

	class Node {
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

		void update(Mesh& mesh);

		void draw(int depth, const ShaderProgram& program);

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

	void update();

	void draw(int depth, const ShaderProgram& program);

	~TerrainTree();

};

#endif