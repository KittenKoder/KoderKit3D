#ifndef COLOR_HPP
#define COLOR_HPP

#include "stds/universal.h"

namespace kk3d {
namespace math {

/**
 * \brief RGB color object.
 * Used by KK3D as the basic color object using OpenGL float values.
 */
class Color3F
{
	public:
		GLfloat r, g, b;
};

/**
 * \brief RGBA color object.
 * Used by KK3D as the basic color object using OpenGL float values.
 */
class Color4F
{
	public:
		GLfloat r, g, b, a;
};

};
};

#endif
