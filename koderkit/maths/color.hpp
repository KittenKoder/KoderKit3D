#ifndef COLOR_HPP
#define COLOR_HPP

#include <GL/glew.h>
#include <GL/gl.h>

namespace kk3d {
namespace math {

/**
 * RGB color object.
 * Used by KK3D as the basic color object using OpenGL float values.
 */
class Color3F
{
	public:
		GLfloat r, g, b;

		void set(GLfloat _r, GLfloat _g, GLfloat _b);
};

/**
 * RGBA color object.
 * Used by KK3D as the basic color object using OpenGL float values.
 */
class Color4F
{
	public:
		GLfloat r, g, b, a;

		void set(GLfloat _r, GLfloat _g, GLfloat _b, GLfloat _a);
};

};
};

#endif
