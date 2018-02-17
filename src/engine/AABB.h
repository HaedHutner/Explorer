#ifndef _AABB_H
#define _AABB_H

#include <glm\glm.hpp>

class AABB {

private:

	glm::vec2 center;
	float half_dimension;

public:

	AABB(const glm::vec2& center, const float& half_dimension);

	bool contains(const glm::vec2& point);

	bool intersects(const AABB& other);

	~AABB() = default;

};

#endif