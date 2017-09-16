#include "vertex.hpp"
#include "fastmath.hpp"
#include <math.h>

namespace kk3d {
	namespace math {

		// assignment
Vertex3D Vertex3D::operator=(Vertex3D v)
{
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
	return (*this);
};

Vertex3D Vertex3D::operator=(Vertex3D *v)
{
	this->x = v->x;
	this->y = v->y;
	this->z = v->z;
	return (*this);
};

Vertex3D Vertex3D::operator+=(Vertex3D v)
{
	this->x += v.x;
	this->y += v.y;
	this->z += v.z;
	return (*this);
};

Vertex3D Vertex3D::operator+=(Vertex3D *v)
{
	this->x += v->x;
	this->y += v->y;
	this->z += v->z;
	return (*this);
};

Vertex3D Vertex3D::operator-=(Vertex3D v)
{
	this->x -= v.x;
	this->y -= v.y;
	this->z -= v.z;
	return (*this);
};

Vertex3D Vertex3D::operator-=(Vertex3D *v)
{
	this->x -= v->x;
	this->y -= v->y;
	this->z -= v->z;
	return (*this);
};

Vertex3D Vertex3D::operator*=(Vertex3D v)
{
	this->x *= v.x;
	this->y *= v.y;
	this->z *= v.z;
	return (*this);
};

Vertex3D Vertex3D::operator*=(Vertex3D *v)
{
	this->x *= v->x;
	this->y *= v->y;
	this->z *= v->z;
	return (*this);
};

Vertex3D Vertex3D::operator/=(Vertex3D v)
{
	this->x /= v.x;
	this->y /= v.y;
	this->z /= v.z;
	return (*this);
};

Vertex3D Vertex3D::operator/=(Vertex3D *v)
{
	this->x /= v->x;
	this->y /= v->y;
	this->z /= v->z;
	return (*this);
};

		// float
Vertex3D Vertex3D::operator=(GLfloat v)
{
	this->x = v;
	this->y = v;
	this->z = v;
	return (*this);
};

Vertex3D Vertex3D::operator+=(GLfloat v)
{
	this->x += v;
	this->y += v;
	this->z += v;
	return (*this);
};

Vertex3D Vertex3D::operator-=(GLfloat v)
{
	this->x -= v;
	this->y -= v;
	this->z -= v;
	return (*this);
};

Vertex3D Vertex3D::operator*=(GLfloat v)
{
	this->x *= v;
	this->y *= v;
	this->z *= v;
	return (*this);
};

Vertex3D Vertex3D::operator/=(GLfloat v)
{
	this->x /= v;
	this->y /= v;
	this->z /= v;
	return (*this);
};

		// arithmatic
Vertex3D Vertex3D::operator+(GLfloat v)
{
	Vertex3D rv;
	rv.x = this->x + v;
	rv.y = this->y + v;
	rv.z = this->z + v;
	return rv;
};

Vertex3D Vertex3D::operator*(GLfloat v)
{
	Vertex3D rv;
	rv.x = this->x * v;
	rv.y = this->y * v;
	rv.z = this->z * v;
	return rv;
};

Vertex3D Vertex3D::operator-(GLfloat v)
{
	Vertex3D rv;
	rv.x = this->x - v;
	rv.y = this->y - v;
	rv.z = this->z - v;
	return rv;
};

Vertex3D Vertex3D::operator/(GLfloat v)
{
	Vertex3D rv;
	rv.x = this->x / v;
	rv.y = this->y / v;
	rv.z = this->z / v;
	return rv;
};

Vertex3D Vertex3D::operator+(Vertex3D v)
{
	Vertex3D rv;
	rv.x = this->x + v.x;
	rv.y = this->y + v.y;
	rv.z = this->z + v.z;
	return rv;
};

Vertex3D Vertex3D::operator+(Vertex3D *v)
{
	Vertex3D rv;
	rv.x = this->x + v->x;
	rv.y = this->y + v->y;
	rv.z = this->z + v->z;
	return rv;
};

Vertex3D Vertex3D::operator-(Vertex3D v)
{
	Vertex3D rv;
	rv.x = this->x - v.x;
	rv.y = this->y - v.y;
	rv.z = this->z - v.z;
	return rv;
};

Vertex3D Vertex3D::operator-()
{
	Vertex3D rv;
	rv.x = -this->x;
	rv.y = -this->y;
	rv.z = -this->z;
	return rv;
};

Vertex3D Vertex3D::operator-(Vertex3D *v)
{
	Vertex3D rv;
	rv.x = this->x - v->x;
	rv.y = this->y - v->y;
	rv.z = this->z - v->z;
	return rv;
};

GLfloat Vertex3D::operator*(Vertex3D v)
{
	return (this->x * v.x) + (this->y * v.y) + (this->z * v.z);
};

GLfloat Vertex3D::operator*(Vertex3D *v)
{
	return (this->x * v->x) + (this->y * v->y) + (this->z * v->z);
};

Vertex3D Vertex3D::operator/(Vertex3D v)
{
	Vertex3D rv;
	rv.x = this->x / v.x;
	rv.y = this->y / v.y;
	rv.z = this->z / v.z;
	return rv;
};

Vertex3D Vertex3D::operator/(Vertex3D *v)
{
	Vertex3D rv;
	rv.x = this->x / v->x;
	rv.y = this->y / v->y;
	rv.z = this->z / v->z;
	return rv;
};

Vertex3D Vertex3D::operator%(Vertex3D v)
{
	Vertex3D rv;
	rv.x = (this->y * v.z) - (this->z * v.y);
	rv.y = (this->z * v.x) - (this->x * v.z);
	rv.z = (this->x * v.y) - (this->y * v.x);
	return rv;
};

Vertex3D Vertex3D::operator%(Vertex3D *v)
{
	Vertex3D rv;
	rv.x = (this->y * v->z) - (this->z * v->y);
	rv.y = (this->z * v->x) - (this->x * v->z);
	rv.z = (this->x * v->y) - (this->y * v->x);
	return rv;
};

		// relation
bool Vertex3D::operator==(Vertex3D *v)
{
	return (this->x == v->x) & (this->y == v->y) & (this->z == v->z);
};

bool Vertex3D::operator==(Vertex3D v)
{
	return (this->x == v.x) & (this->y == v.y) & (this->z == v.z);
};

bool Vertex3D::operator<(Vertex3D *v)
{
	return (this->length() < v->length());
};

bool Vertex3D::operator<(Vertex3D v)
{
	return (this->length() < v.length());
};

bool Vertex3D::operator>(Vertex3D *v)
{
	return (this->length() > v->length());
};

bool Vertex3D::operator>(Vertex3D v)
{
	return (this->length() > v.length());
};

bool Vertex3D::operator<=(Vertex3D *v)
{
	return (this->length() <= v->length());
};

bool Vertex3D::operator<=(Vertex3D v)
{
	return (this->length() <= v.length());
};

bool Vertex3D::operator>=(Vertex3D *v)
{
	return (this->length() >= v->length());
};

bool Vertex3D::operator>=(Vertex3D v)
{
	return (this->length() >= v.length());
};

		// methods
Vertex3D::Vertex3D()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
};

Vertex3D::Vertex3D(Vertex3D *v)
{
	this->x = v->x;
	this->y = v->y;
	this->z = v->z;
};

Vertex3D::Vertex3D(const Vertex3D &v)
{
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
};

Vertex3D::Vertex3D(GLfloat x, GLfloat y, GLfloat z)
{
	this->x = x;
	this->y = y;
	this->z = z;
};

GLfloat Vertex3D::length()
{
	return fastmath::sqrtf((this->x * this->x) + (this->y * this->y) + (this->z * this->z));
};

void Vertex3D::lerpFast(Vertex3D *v1, Vertex3D *v2, GLfloat l)
{
	this->x = v1->x + ((v1->x - v2->x) * l);
	this->y = v1->y + ((v1->y - v2->y) * l);
	this->z = v1->z + ((v1->z - v2->z) * l);
};

void Vertex3D::lerpFast(Vertex3D v1, Vertex3D v2, GLfloat l)
{
	this->x = v1.x + ((v2.x - v1.x) * l);
	this->y = v1.y + ((v2.y - v1.y) * l);
	this->z = v1.z + ((v2.z - v1.z) * l);
};

void Vertex3D::slerpFast(Vertex3D *v1, Vertex3D *v2, GLfloat l)
{
	GLfloat ft = l * PI;
	GLfloat f = ((1.0 - cos(ft)) * 0.5 + l) * 0.5;
	this->x = v1->x + ((v2->x - v1->x) * f);
	this->y = v1->y + ((v2->y - v1->y) * f);
	this->z = v1->z + ((v2->z - v1->z) * f);
};

void Vertex3D::slerpFast(Vertex3D v1, Vertex3D v2, GLfloat l)
{
	GLfloat ft = l * PI;
	GLfloat f = ((1.0 - cos(ft)) * 0.5 + l) * 0.5;
	this->x = v1.x + ((v2.x - v1.x) * f);
	this->y = v1.y + ((v2.y - v1.y) * f);
	this->z = v1.z + ((v2.z - v1.z) * f);
};
		// 4 point
void Vertex3D::bezier(Vertex3D v[], GLfloat t)
{
	GLfloat u = 1.0f - t;
	GLfloat tt = t*t;
	GLfloat uu = u*u;
	GLfloat ttt = tt*t;
	GLfloat uuu = uu*u;

	Vertex3D vt = v[1] - (v[0] - v[1]);
	*this = v[1] * uuu;
	*this += vt * (3.0f * uu * t);
	*this += v[2] * (3.0f * u * tt);
	*this += v[3] * ttt;
};

void Vertex3D::normalize()
{
	GLfloat l = this->length();
	if(l > 0.0000001f) *this /= l;
};

GLfloat Vertex3D::cosAngle(Vertex3D v1, Vertex3D v2)
{
	GLfloat l1 = v1.length();
	GLfloat l2 = v2.length();

	if(l1 < 0.0000001f) l1 = 1.0f;
	if(l2 < 0.0000001f) l2 = 1.0f;

	return ((v1 * v2) / (l1 * l2));
};

GLfloat Vertex3D::cosAngle(Vertex3D *v1, Vertex3D *v2)
{
	GLfloat l1 = v1->length();
	GLfloat l2 = v2->length();

	if(l1 < 0.0000001f) l1 = 1.0f;
	if(l2 < 0.0000001f) l2 = 1.0f;

	return (((*v1) * v2) / (l1 * l2));
};

void Vertex3D::toNormal(Vertex3D v[], bool cw)
{
	static Vertex3D va;
	static Vertex3D vb;

	va = v[1] - v[0];
	vb = v[2] - v[0];

	(*this) = va % vb;

	if(!cw) (*this) = -(*this);

	this->normalize();
};

void Vertex3D::toNormal(Vertex3D *v1, Vertex3D *v2, Vertex3D *v3, bool cw)
{
	static Vertex3D va;
	static Vertex3D vb;

	va = (*v2) - (*v1);
	vb = (*v3) - (*v1);

	(*this) = va % vb;

	if(!cw) (*this) = -(*this);

	this->normalize();
};

void Vertex3D::set(GLfloat x, GLfloat y, GLfloat z)
{
	this->x = x;
	this->y = y;
	this->z = z;
};

	};
};

