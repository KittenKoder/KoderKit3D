#include "fastmath.hpp"
#include <math.h>

namespace fastmath {
	GLfloat invsqrt(GLfloat x)
	{
		unsigned int i = *((unsigned int *)&x);
		i = 0x5f375a86 - (i >> 1);
		return *((GLfloat*)&i);
	};

	GLfloat sqrtf(GLfloat x)
	{
		int i = *((unsigned int*)&x);
		i += 127 << 23;
		i >>= 1;
		return *((GLfloat*)&i);
	};

	template <typename T>
	GLfloat min(T a, T b)
	{
		if(b > a) return a;
		return b;
	};

	template <typename T>
	GLfloat max(T a, T b)
	{
		if(b < a) return a;
		return b;
	};

	template <typename T>
	GLfloat slerp(T a, T b, T u)
	{
		GLfloat ft = u * PI;
		GLfloat f = (1.0 - cos(ft)) * 0.5;
		return a + (f + u) * 0.5 * (b - a);
	}

};
