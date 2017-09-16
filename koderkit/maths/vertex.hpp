#ifndef VERTEX_HPP
#define VERTEX_HPP

//#include "stds/universal.h"
#include <GL/gl.h>

namespace kk3d {
	namespace math {

class Vertex2D {
	public:
		GLfloat x, y;

		Vertex2D operator=(Vertex2D);
		Vertex2D operator=(Vertex2D *);
		Vertex2D operator-=(Vertex2D);
		Vertex2D operator-=(Vertex2D *);
		Vertex2D operator+=(Vertex2D);
		Vertex2D operator+=(Vertex2D *);
		Vertex2D operator*=(Vertex2D); // scale
		Vertex2D operator*=(Vertex2D *); // scale
		Vertex2D operator/=(Vertex2D);
		Vertex2D operator/=(Vertex2D *);

		Vertex2D operator=(GLfloat);
		Vertex2D operator+=(GLfloat);
		Vertex2D operator-=(GLfloat);
		Vertex2D operator*=(GLfloat); // scale
		Vertex2D operator/=(GLfloat);

		Vertex2D operator+(GLfloat);
		Vertex2D operator-(GLfloat);
		Vertex2D operator*(GLfloat); // scale
		Vertex2D operator/(GLfloat);

		Vertex2D operator+(Vertex2D);
		Vertex2D operator-(Vertex2D);
		Vertex2D operator*(Vertex2D); // dot product
		Vertex2D operator/(Vertex2D);
		Vertex2D operator%(Vertex2D); // cross product

		Vertex2D operator+(Vertex2D *);
		Vertex2D operator-(Vertex2D *);
		Vertex2D operator*(Vertex2D *); // dot product
		Vertex2D operator/(Vertex2D *);
		Vertex2D operator%(Vertex2D *); // cross product

		Vertex2D operator-();

		bool operator==(Vertex2D *);
		bool operator==(Vertex2D);
		bool operator<(Vertex2D *);
		bool operator<(Vertex2D);
		bool operator>(Vertex2D *);
		bool operator>(Vertex2D);
		bool operator<=(Vertex2D *);
		bool operator<=(Vertex2D);
		bool operator>=(Vertex2D *);
		bool operator>=(Vertex2D);

		Vertex2D();
		Vertex2D(Vertex2D *);
		Vertex2D(const Vertex2D &);

		GLfloat length();
		void lerpFast(Vertex2D, Vertex2D, GLfloat);
		void lerpFast(Vertex2D *, Vertex2D *, GLfloat);
		void slerpFast(Vertex2D, Vertex2D, GLfloat);
		void slerpFast(Vertex2D *, Vertex2D *, GLfloat);
		void bezier(Vertex2D [], GLfloat);
		void normalize();
		GLfloat toAngle();
		void set(GLfloat, GLfloat);
};

class Vertex3D {
	public:
		GLfloat x, y, z;

		Vertex3D operator=(Vertex3D);
		Vertex3D operator=(Vertex3D *);
		Vertex3D operator-=(Vertex3D);
		Vertex3D operator-=(Vertex3D *);
		Vertex3D operator+=(Vertex3D);
		Vertex3D operator+=(Vertex3D *);
		Vertex3D operator*=(Vertex3D); // scale
		Vertex3D operator*=(Vertex3D *); // scale
		Vertex3D operator/=(Vertex3D);
		Vertex3D operator/=(Vertex3D *);

		Vertex3D operator=(GLfloat);
		Vertex3D operator+=(GLfloat);
		Vertex3D operator-=(GLfloat);
		Vertex3D operator*=(GLfloat); // scale
		Vertex3D operator/=(GLfloat);

		Vertex3D operator+(GLfloat);
		Vertex3D operator-(GLfloat);
		Vertex3D operator*(GLfloat); // scale
		Vertex3D operator/(GLfloat);

		Vertex3D operator+(Vertex3D);
		Vertex3D operator-(Vertex3D);
		GLfloat operator*(Vertex3D); // dot product
		Vertex3D operator/(Vertex3D);
		Vertex3D operator%(Vertex3D); // cross product

		Vertex3D operator+(Vertex3D *);
		Vertex3D operator-(Vertex3D *);
		GLfloat operator*(Vertex3D *); // dot product
		Vertex3D operator/(Vertex3D *);
		Vertex3D operator%(Vertex3D *); // cross product

		Vertex3D operator-();

		bool operator==(Vertex3D *);
		bool operator==(Vertex3D);
		bool operator<(Vertex3D *);
		bool operator<(Vertex3D);
		bool operator>(Vertex3D *);
		bool operator>(Vertex3D);
		bool operator<=(Vertex3D *);
		bool operator<=(Vertex3D);
		bool operator>=(Vertex3D *);
		bool operator>=(Vertex3D);

		Vertex3D();
		Vertex3D(Vertex3D *);
		Vertex3D(const Vertex3D &);
		Vertex3D(GLfloat, GLfloat, GLfloat);

		GLfloat length();
		void lerpFast(Vertex3D, Vertex3D, GLfloat);
		void lerpFast(Vertex3D *, Vertex3D *, GLfloat);
		void slerpFast(Vertex3D, Vertex3D, GLfloat);
		void slerpFast(Vertex3D *, Vertex3D *, GLfloat);
		void bezier(Vertex3D [], GLfloat);
		void normalize();
		GLfloat cosAngle(Vertex3D, Vertex3D);
		GLfloat cosAngle(Vertex3D *, Vertex3D *);
		void toNormal(Vertex3D [], bool);
		void toNormal(Vertex3D*, Vertex3D*, Vertex3D*, bool);
		void set(GLfloat, GLfloat, GLfloat);
};

class Vertex4D {
	public:
		GLfloat x, y, z, w;

		Vertex4D operator=(Vertex4D);
		Vertex4D operator=(Vertex4D *);
		Vertex4D operator-=(Vertex4D); // Conjugate
		Vertex4D operator-=(Vertex4D *); // Conjugate
		Vertex4D operator+=(Vertex4D);
		Vertex4D operator+=(Vertex4D *);
		Vertex4D operator*=(Vertex4D); // Quat multiply
		Vertex4D operator*=(Vertex4D *); // Quat multiply
		Vertex4D operator/=(Vertex4D); // Quat conjugate multiply
		Vertex4D operator/=(Vertex4D *); // Quat conjugate multiply

		Vertex4D operator=(GLfloat);
		Vertex4D operator+=(GLfloat);
		Vertex4D operator-=(GLfloat);
		Vertex4D operator*=(GLfloat); // scale
		Vertex4D operator/=(GLfloat);

		Vertex4D operator+(GLfloat);
		Vertex4D operator-(GLfloat);
		Vertex4D operator*(GLfloat); // scale
		Vertex4D operator/(GLfloat);

		Vertex4D operator+(Vertex4D);
		Vertex4D operator-(Vertex4D);
		Vertex4D operator*(Vertex4D); // Quat multiply
		Vertex4D operator/(Vertex4D); // Quat conjugate multiply
		GLfloat operator%(Vertex4D); // dot product

		Vertex4D operator+(Vertex4D *);
		Vertex4D operator-(Vertex4D *);
		Vertex4D operator*(Vertex4D *); // Quat multiply
		Vertex4D operator/(Vertex4D *); // Quat conjugate multiply
		GLfloat operator%(Vertex4D *); // dot product

		Vertex4D operator-();

		bool operator==(Vertex4D *);
		bool operator==(Vertex4D);
		bool operator<(Vertex4D *);
		bool operator<(Vertex4D);
		bool operator>(Vertex4D *);
		bool operator>(Vertex4D);
		bool operator<=(Vertex4D *);
		bool operator<=(Vertex4D);
		bool operator>=(Vertex4D *);
		bool operator>=(Vertex4D);

		Vertex4D();
		Vertex4D(Vertex4D *);
		Vertex4D(const Vertex4D &);

		GLfloat length();
		void lerpFast(Vertex4D *, Vertex4D *, GLfloat);
		void lerpFast(Vertex4D, Vertex4D, GLfloat);
		void slerpFast(Vertex4D *, Vertex4D *, GLfloat);
		void slerpFast(Vertex4D, Vertex4D, GLfloat);
		void bezier(Vertex4D [], GLfloat);
		void normalize();
		void normalizeXYZ();
		void toNormal(Vertex4D []);
		void rotateByQuaternion(Vertex4D *);
		void set(GLfloat, GLfloat, GLfloat, GLfloat);
		void fromAxisAngle(GLfloat, GLfloat, GLfloat, GLfloat);
		void fromEuler(GLfloat, GLfloat, GLfloat);
		void fromAxisAngle(Vertex4D *);
		void fromEuler(Vertex3D *);
};

	};
};

#endif
