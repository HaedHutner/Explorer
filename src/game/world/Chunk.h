#ifndef _CHUNK_H
#define _CHUNK_H

#include <engine\render\Model.h>

class Chunk {
private:

	Model model;

public:

	Chunk(glm::vec3 position);

	void tick();

	void draw();

	~Chunk();

};

#endif