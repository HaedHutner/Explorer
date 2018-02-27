#ifndef _MATH_UTIL_HPP
#define _MATH_UTIL_HPP

#include <glm\glm.hpp>
#include <engine\render\Vertex.h>

namespace MathUtils {

	static inline void calc_normal(Vertex* v, const glm::vec3& neighbor1, const glm::vec3& neighbor2) {
		glm::vec3 va = v->xyz - neighbor1;
		glm::vec3 vb = v->xyz - neighbor2;

		v->normal = ( v->normal + glm::cross(va, vb) ) * 0.5f;
	}

}

#endif
