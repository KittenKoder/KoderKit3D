#include "vertex.hpp"
#include "fastmath.hpp"
#include <math.h>

using namespace kk3d::math;

		// assignment
Vertex4D Vertex4D::operator=(Vertex4D v)
{
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
	this->w = v.w;
	return (*this);
};

Vertex4D Vertex4D::operator=(Vertex4D *v)
{
	this->x = v->x;
	this->y = v->y;
	this->z = v->z;
	this->w = v->w;
	return (*this);
};

Vertex4D Vertex4D::operator+=(Vertex4D v)
{
	this->x += v.x;
	this->y += v.y;
	this->z += v.z;
	this->w += v.w;
	return (*this);
};

Vertex4D Vertex4D::operator+=(Vertex4D *v)
{
	this->x += v->x;
	this->y += v->y;
	this->z += v->z;
	this->w += v->w;
	return (*this);
};

Vertex4D Vertex4D::operator-=(Vertex4D v)
{
	this->x = -v.x;
	this->y = -v.y;
	this->z = -v.z;
	this->w = v.w;
	return (*this);
};

Vertex4D Vertex4D::operator-=(Vertex4D *v)
{
	this->x = -v->x;
	this->y = -v->y;
	this->z = -v->z;
	this->w = v->w;
	return (*this);
};

Vertex4D Vertex4D::operator*=(Vertex4D v)
{
	// Quat multiply
	Vertex4D rv;
	rv.x = (this->w * v.x) + (this->x * v.w) + (this->y * v.z) - (this->z * v.y);
	rv.y = (this->w * v.y) + (this->y * v.w) + (this->z * v.x) - (this->x * v.z);
	rv.z = (this->w * v.z) + (this->z * v.w) + (this->x * v.y) - (this->y * v.x);
	rv.w = (this->w * v.w) - (this->x * v.x) - (this->y * v.y) - (this->z * v.z);
	return rv;
};

Vertex4D Vertex4D::operator*=(Vertex4D *v)
{
	// Quat multiply
	Vertex4D rv;
	rv.x = (this->w * v->x) + (this->x * v->w) + (this->y * v->z) - (this->z * v->y);
	rv.y = (this->w * v->y) + (this->y * v->w) + (this->z * v->x) - (this->x * v->z);
	rv.z = (this->w * v->z) + (this->z * v->w) + (this->x * v->y) - (this->y * v->x);
	rv.w = (this->w * v->w) - (this->x * v->x) - (this->y * v->y) - (this->z * v->z);
	return rv;
};

Vertex4D Vertex4D::operator/=(Vertex4D v)
{
	Vertex4D rv;
	rv.x = (this->w * -v.x) + (this->x * v.w) + (this->y * -v.z) - (this->z * -v.y);
	rv.y = (this->w * -v.y) + (this->y * v.w) + (this->z * -v.x) - (this->x * -v.z);
	rv.z = (this->w * -v.z) + (this->z * v.w) + (this->x * -v.y) - (this->y * -v.x);
	rv.w = (this->w * v.w) - (this->x * -v.x) - (this->y * -v.y) - (this->z * -v.z);
	return rv;
};

Vertex4D Vertex4D::operator/=(Vertex4D *v)
{
	// Quat inverse multiply
	Vertex4D rv;
	rv.x = (this->w * -v->x) + (this->x * v->w) + (this->y * -v->z) - (this->z * -v->y);
	rv.y = (this->w * -v->y) + (this->y * v->w) + (this->z * -v->x) - (this->x * -v->z);
	rv.z = (this->w * -v->z) + (this->z * v->w) + (this->x * -v->y) - (this->y * -v->x);
	rv.w = (this->w * v->w) - (this->x * -v->x) - (this->y * -v->y) - (this->z * -v->z);
	return rv;
};

		// float
Vertex4D Vertex4D::operator=(GLfloat v)
{
	this->x = v;
	this->y = v;
	this->z = v;
	this->w = v;
	return (*this);
};

Vertex4D Vertex4D::operator+=(GLfloat v)
{
	this->x += v;
	this->y += v;
	this->z += v;
	this->w += v;
	return (*this);
};

Vertex4D Vertex4D::operator-=(GLfloat v)
{
	this->x -= v;
	this->y -= v;
	this->z -= v;
	this->w -= v;
	return (*this);
};

Vertex4D Vertex4D::operator*=(GLfloat v)
{
	this->x *= v;
	this->y *= v;
	this->z *= v;
	this->w *= v;
	return (*this);
};

Vertex4D Vertex4D::operator/=(GLfloat v)
{
	this->x /= v;
	this->y /= v;
	this->z /= v;
	this->w /= v;
	return (*this);
};

		// arithmatic
Vertex4D Vertex4D::operator+(GLfloat v)
{
	Vertex4D rv;
	rv.x = this->x + v;
	rv.y = this->y + v;
	rv.z = this->z + v;
	rv.w = this->w + v;
	return rv;
};

Vertex4D Vertex4D::operator*(GLfloat v)
{
	Vertex4D rv;
	rv.x = this->x * v;
	rv.y = this->y * v;
	rv.z = this->z * v;
	rv.w = this->w * v;
	return rv;
};

Vertex4D Vertex4D::operator-(GLfloat v)
{
	Vertex4D rv;
	rv.x = this->x - v;
	rv.y = this->y - v;
	rv.z = this->z - v;
	rv.w = this->w - v;
	return rv;
};

Vertex4D Vertex4D::operator/(GLfloat v)
{
	Vertex4D rv;
	rv.x = this->x / v;
	rv.y = this->y / v;
	rv.z = this->z / v;
	rv.w = this->w / v;
	return rv;
};

Vertex4D Vertex4D::operator+(Vertex4D v)
{
	Vertex4D rv;
	rv.x = this->x + v.x;
	rv.y = this->y + v.y;
	rv.z = this->z + v.z;
	rv.w = this->w + v.w;
	return rv;
};

Vertex4D Vertex4D::operator+(Vertex4D *v)
{
	Vertex4D rv;
	rv.x = this->x + v->x;
	rv.y = this->y + v->y;
	rv.z = this->z + v->z;
	rv.w = this->w + v->w;
	return rv;
};

Vertex4D Vertex4D::operator-(Vertex4D v)
{
	Vertex4D rv;
	rv.x = this->x - v.x;
	rv.y = this->y - v.y;
	rv.z = this->z - v.z;
	rv.w = this->z - v.w;
	return rv;
};

Vertex4D Vertex4D::operator-()
{
	Vertex4D rv;
	rv.x = -this->x;
	rv.y = -this->y;
	rv.z = -this->z;
	rv.w = -this->w;
	return rv;
};

Vertex4D Vertex4D::operator-(Vertex4D *v)
{
	Vertex4D rv;
	rv.x = this->x - v->x;
	rv.y = this->y - v->y;
	rv.z = this->z - v->z;
	rv.w = this->w - v->w;
	return rv;
};

Vertex4D Vertex4D::operator*(Vertex4D v)
{
		// Quat multiply
	Vertex4D rv;
	rv.x = (this->w * v.x) + (this->x * v.w) + (this->y * v.z) - (this->z * v.y);
	rv.y = (this->w * v.y) + (this->y * v.w) + (this->z * v.x) - (this->x * v.z);
	rv.z = (this->w * v.z) + (this->z * v.w) + (this->x * v.y) - (this->y * v.x);
	rv.w = (this->w * v.w) - (this->x * v.x) - (this->y * v.y) - (this->z * v.z);
	return rv;
};

Vertex4D Vertex4D::operator*(Vertex4D *v)
{
	// Quat multiply
	Vertex4D rv;
	rv.x = (this->w * v->x) + (this->x * v->w) + (this->y * v->z) - (this->z * v->y);
	rv.y = (this->w * v->y) + (this->y * v->w) + (this->z * v->x) - (this->x * v->z);
	rv.z = (this->w * v->z) + (this->z * v->w) + (this->x * v->y) - (this->y * v->x);
	rv.w = (this->w * v->w) - (this->x * v->x) - (this->y * v->y) - (this->z * v->z);
	return rv;
};

Vertex4D Vertex4D::operator/(Vertex4D v)
{
	// Quat Inverse multiply
	Vertex4D rv;
	rv.x = (this->w * -v.x) + (this->x * v.w) + (this->y * -v.z) - (this->z * -v.y);
	rv.y = (this->w * -v.y) + (this->y * v.w) + (this->z * -v.x) - (this->x * -v.z);
	rv.z = (this->w * -v.z) + (this->z * v.w) + (this->x * -v.y) - (this->y * -v.x);
	rv.w = (this->w * v.w) - (this->x * -v.x) - (this->y * -v.y) - (this->z * -v.z);
	return rv;
};

Vertex4D Vertex4D::operator/(Vertex4D *v)
{
	// Quat multiply
	Vertex4D rv;
	rv.x = (this->w * -v->x) + (this->x * v->w) + (this->y * -v->z) - (this->z * -v->y);
	rv.y = (this->w * -v->y) + (this->y * v->w) + (this->z * -v->x) - (this->x * -v->z);
	rv.z = (this->w * -v->z) + (this->z * v->w) + (this->x * -v->y) - (this->y * -v->x);
	rv.w = (this->w * v->w) - (this->x * -v->x) - (this->y * -v->y) - (this->z * -v->z);
	return rv;
};

GLfloat Vertex4D::operator%(Vertex4D v)
{
	return (this->x * v.x) + (this->y * v.y) + (this->z * v.z) + (this->w * v.w);
};

GLfloat Vertex4D::operator%(Vertex4D *v)
{
	return (this->x * v->x) + (this->y * v->y) + (this->z * v->z) + (this->w * v->w);
};

		// relation
bool Vertex4D::operator==(Vertex4D *v)
{
	return (this->x == v->x) & (this->y == v->y) & (this->z == v->z) & (this->w == v->w);
};

bool Vertex4D::operator==(Vertex4D v)
{
	return (this->x == v.x) & (this->y == v.y) & (this->z == v.z) & (this->w == v.w);
};

bool Vertex4D::operator<(Vertex4D *v)
{
	return (this->length() < v->length());
};

bool Vertex4D::operator<(Vertex4D v)
{
	return (this->length() < v.length());
};

bool Vertex4D::operator>(Vertex4D *v)
{
	return (this->length() > v->length());
};

bool Vertex4D::operator>(Vertex4D v)
{
	return (this->length() > v.length());
};

bool Vertex4D::operator<=(Vertex4D *v)
{
	return (this->length() <= v->length());
};

bool Vertex4D::operator<=(Vertex4D v)
{
	return (this->length() <= v.length());
};

bool Vertex4D::operator>=(Vertex4D *v)
{
	return (this->length() >= v->length());
};

bool Vertex4D::operator>=(Vertex4D v)
{
	return (this->length() >= v.length());
};

		// methods
Vertex4D::Vertex4D()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->w = 1;
};

Vertex4D::Vertex4D(Vertex4D *v)
{
	this->x = v->x;
	this->y = v->y;
	this->z = v->z;
	this->w = v->w;
};

Vertex4D::Vertex4D(const Vertex4D &v)
{
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
	this->w = v.w;
};

GLfloat Vertex4D::length()
{
	return fastmath::sqrtf((this->x * this->x) + (this->y * this->y) + (this->z * this->z) + (this->w * this->w));
};

void Vertex4D::normalizeXYZ()
{
	GLfloat l = fastmath::sqrtf((this->x * this->x) + (this->y * this->y) + (this->z * this->z));
	if(l > 0.0)
	{
		this->x /= l;
		this->y /= l;
		this->z /= l;
	}
};


void Vertex4D::lerpFast(Vertex4D *v1, Vertex4D *v2, GLfloat l)
{
	this->x = v1->x + ((v1->x - v2->x) * l);
	this->y = v1->y + ((v1->y - v2->y) * l);
	this->z = v1->z + ((v1->z - v2->z) * l);
	this->w = v1->w + ((v1->w - v2->w) * l);
};

void Vertex4D::lerpFast(Vertex4D v1, Vertex4D v2, GLfloat l)
{
	this->x = v1.x + ((v2.x - v1.x) * l);
	this->y = v1.y + ((v2.y - v1.y) * l);
	this->z = v1.z + ((v2.z - v1.z) * l);
	this->w = v1.w + ((v2.z - v1.w) * l);
};

void Vertex4D::slerpFast(Vertex4D *v1, Vertex4D *v2, GLfloat l)
{
	{
		GLfloat dot = (*v1) % v2;
		GLfloat x2, y2, z2, w2;

		if(dot < 0.0)
		{
			dot = -dot;
			x2 = -v2->x;
			y2 = -v2->y;
			z2 = -v2->z;
			w2 = -v2->w;
		}
		else
		{
			x2 = v2->x;
			y2 = v2->y;
			z2 = v2->z;
			w2 = v2->w;
		}

		GLfloat t1, t2;
		GLfloat angle = acos(dot);
        GLfloat sinAngle = sin(angle);
        t1 = sin((1.0 - l) * angle) / sinAngle;
        t2 = sin(l * angle) / sinAngle;

		this->x = (v1->x * t1) + (x2 * t2);
		this->y = (v1->y * t1) + (y2 * t2);
		this->z = (v1->z * t1) + (z2 * t2);
		this->w = (v1->w * t1) + (w2 * t2);
	}
};

void Vertex4D::slerpFast(Vertex4D v1, Vertex4D v2, GLfloat l)
{
	{
		GLfloat dot = v1 % v2;
		GLfloat x2, y2, z2, w2;

		if(dot < 0.0)
		{
			dot = -dot;
			x2 = -v2.x;
			y2 = -v2.y;
			z2 = -v2.z;
			w2 = -v2.w;
		}
		else
		{
			x2 = v2.x;
			y2 = v2.y;
			z2 = v2.z;
			w2 = v2.w;
		}

		GLfloat t1, t2;
		GLfloat angle = acos(dot);
        GLfloat sinAngle = sin(angle);
        t1 = sin((1.0 - l) * angle) / sinAngle;
        t2 = sin(l * angle) / sinAngle;

		this->x = (v1.x * t1) + (x2 * t2);
		this->y = (v1.y * t1) + (y2 * t2);
		this->z = (v1.z * t1) + (z2 * t2);
		this->w = (v1.w * t1) + (w2 * t2);
	}
};

		// 4 point
void Vertex4D::bezier(Vertex4D v[], GLfloat t)
{
	GLfloat u = 1.0f - t;
	GLfloat tt = t*t;
	GLfloat uu = u*u;
	GLfloat ttt = tt*t;
	GLfloat uuu = uu*u;

	Vertex4D vt = v[1] - (v[0] - v[1]);
	*this = v[1] * uuu;
	*this += vt * (3.0f * uu * t);
	*this += v[2] * (3.0f * u * tt);
	*this += v[3] * ttt;
};

void Vertex4D::normalize()
{
	GLfloat l = this->length();
	if(l > 0.0000001f) *this /= l;
};

void Vertex4D::rotateByQuaternion(Vertex4D *q)
{
	GLfloat ln = this->length();
	if(ln > 0.0)
	{
		*this /= ln;
		*this = (*this) / q;
		*this = (*q) * this;
		*this *= ln;
	}
};

void Vertex4D::set(GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
};

void Vertex4D::fromAxisAngle(GLfloat x, GLfloat y, GLfloat z, GLfloat a)
{
	double s = sin(a/2);
	this->x = x * s;
	this->y = y * s;
	this->z = z * s;
	this->w = cos(a/2);
};

void Vertex4D::fromEuler(GLfloat x, GLfloat y, GLfloat z)
{
	double c1 = cos(y/2);
    double s1 = sin(y/2);
    double c2 = cos(z/2);
    double s2 = sin(z/2);
    double c3 = cos(x/2);
    double s3 = sin(x/2);
    double c1c2 = c1*c2;
    double s1s2 = s1*s2;
    this->w =c1c2*c3 - s1s2*s3;
  	this->x =c1c2*s3 + s1s2*c3;
	this->y =s1*c2*c3 + c1*s2*s3;
	this->z =c1*s2*c3 - s1*c2*s3;
};

void Vertex4D::fromAxisAngle(Vertex4D *v)
{
	double s = sin(v->w/2);
	this->x = v->x * s;
	this->y = v->y * s;
	this->z = v->z * s;
	this->w = cos(v->w/2);
};

void Vertex4D::fromEuler(Vertex3D *v)
{
	double c1 = cos(v->x/2);
    double s1 = sin(v->x/2);
    double c2 = cos(v->y/2);
    double s2 = sin(v->y/2);
    double c3 = cos(v->z/2);
    double s3 = sin(v->z/2);
    double c1c2 = c1*c2;
    double s1s2 = s1*s2;
    this->w =c1c2*c3 - s1s2*s3;
  	this->x =c1c2*s3 + s1s2*c3;
	this->y =s1*c2*c3 + c1*s2*s3;
	this->z =c1*s2*c3 - s1*c2*s3;
};
