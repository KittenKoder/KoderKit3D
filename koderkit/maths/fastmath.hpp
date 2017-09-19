#ifndef FASTMATH_H
#define FASTMATH_H

#include <GL/glew.h>
#include <GL/gl.h>
#include "../types.h"

namespace fastmath {
    /**
     * Inverse square root.
     * A very fast and decently accurate inverse square root function.
     */
	GLfloat invsqrt(GLfloat);
	/**
     * Square root.
     * A very fast and decently accurate square root function.
     */
	GLfloat sqrtf(GLfloat);

	template <typename T>
	GLfloat min(T, T);
	template <typename T>
	GLfloat max(T, T);
	template <typename T>
	GLfloat slerp(T, T, T);
};

#endif
