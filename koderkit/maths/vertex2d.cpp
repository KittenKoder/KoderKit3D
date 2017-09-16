#include "vertex.hpp"
#include "fastmath.hpp"
#include <math.h>

namespace kk3d {
	namespace math {

		// assignment
Vertex2D Vertex2D::operator=(Vertex2D v)
{
	this->x = v.x;
	this->y = v.y;
	return (*this);
};

Vertex2D Vertex2D::operator=(Vertex2D *v)
{
	this->x = v->x;
	this->y = v->y;
	return (*this);
};

Vertex2D Vertex2D::operator+=(Vertex2D v)
{
	this->x += v.x;
	this->y += v.y;
	return (*this);
};

Vertex2D Vertex2D::operator+=(Vertex2D *v)
{
	this->x += v->x;
	this->y += v->y;
	return (*this);
};

Vertex2D Vertex2D::operator-=(Vertex2D v)
{
	this->x -= v.x;
	this->y -= v.y;
	return (*this);
};

Vertex2D Vertex2D::operator-=(Vertex2D *v)
{
	this->x -= v->x;
	this->y -= v->y;
	return (*this);
};

Vertex2D Vertex2D::operator*=(Vertex2D v)
{
	this->x *= v.x;
	this->y *= v.y;
	return (*this);
};

Vertex2D Vertex2D::operator*=(Vertex2D *v)
{
	this->x *= v->x;
	this->y *= v->y;
	return (*this);
};

Vertex2D Vertex2D::operator/=(Vertex2D v)
{
	this->x /= v.x;
	this->y /= v.y;
	return (*this);
};

Vertex2D Vertex2D::operator/=(Vertex2D *v)
{
	this->x /= v->x;
	this->y /= v->y;
	return (*this);
};

		// float
Vertex2D Vertex2D::operator=(GLfloat v)
{
	this->x = v;
	this->y = v;
	return (*this);
};

Vertex2D Vertex2D::operator+=(GLfloat v)
{
	this->x += v;
	this->y += v;
	return (*this);
};

Vertex2D Vertex2D::operator-=(GLfloat v)
{
	this->x -= v;
	this->y -= v;
	return (*this);
};

Vertex2D Vertex2D::operator*=(GLfloat v)
{
	this->x *= v;
	this->y *= v;
	return (*this);
};

Vertex2D Vertex2D::operator/=(GLfloat v)
{
	this->x /= v;
	this->y /= v;
	return (*this);
};

		// arithmatic
Vertex2D Vertex2D::operator+(GLfloat v)
{
	Vertex2D rv;
	rv.x = this->x + v;
	rv.y = this->y + v;
	return rv;
};

Vertex2D Vertex2D::operator*(GLfloat v)
{
	Vertex2D rv;
	rv.x = this->x * v;
	rv.y = this->y * v;
	return rv;
};

Vertex2D Vertex2D::operator-(GLfloat v)
{
	Vertex2D rv;
	rv.x = this->x - v;
	rv.y = this->y - v;
	return rv;
};

Vertex2D Vertex2D::operator/(GLfloat v)
{
	Vertex2D rv;
	rv.x = this->x / v;
	rv.y = this->y / v;
	return rv;
};

Vertex2D Vertex2D::operator+(Vertex2D v)
{
	Vertex2D rv;
	rv.x = this->x + v.x;
	rv.y = this->y + v.y;
	return rv;
};

Vertex2D Vertex2D::operator+(Vertex2D *v)
{
	Vertex2D rv;
	rv.x = this->x + v->x;
	rv.y = this->y + v->y;
	return rv;
};

Vertex2D Vertex2D::operator-(Vertex2D v)
{
	Vertex2D rv;
	rv.x = this->x - v.x;
	rv.y = this->y - v.y;
	return rv;
};

Vertex2D Vertex2D::operator-()
{
	Vertex2D rv;
	rv.x = -this->x;
	rv.y = -this->y;
	return rv;
};

Vertex2D Vertex2D::operator-(Vertex2D *v)
{
	Vertex2D rv;
	rv.x = this->x - v->x;
	rv.y = this->y - v->y;
	return rv;
};

Vertex2D Vertex2D::operator*(Vertex2D v)
{
	Vertex2D rv;
	rv.x = this->x * v.x;
	rv.y = this->y * v.y;
	return rv;
};

Vertex2D Vertex2D::operator*(Vertex2D *v)
{
	Vertex2D rv;
	rv.x = this->x * v->x;
	rv.y = this->y * v->y;
	return rv;
};

Vertex2D Vertex2D::operator/(Vertex2D v)
{
	Vertex2D rv;
	rv.x = this->x / v.x;
	rv.y = this->y / v.y;
	return rv;
};

Vertex2D Vertex2D::operator/(Vertex2D *v)
{
	Vertex2D rv;
	rv.x = this->x / v->x;
	rv.y = this->y / v->y;
	return rv;
};

Vertex2D Vertex2D::operator%(Vertex2D v)
{
	Vertex2D rv;
	rv.x = this->x / v.x;
	rv.y = this->y / v.y;
	return rv;
};

Vertex2D Vertex2D::operator%(Vertex2D *v)
{
	Vertex2D rv;
	rv.x = this->x / v->x;
	rv.y = this->y / v->y;
	return rv;
};

		// relation
bool Vertex2D::operator==(Vertex2D *v)
{
	return (this->x == v->x) & (this->y == v->y);
};

bool Vertex2D::operator==(Vertex2D v)
{
	return (this->x == v.x) & (this->y == v.y);
};

bool Vertex2D::operator<(Vertex2D *v)
{
	return (this->length() < v->length());
};

bool Vertex2D::operator<(Vertex2D v)
{
	return (this->length() < v.length());
};
		
bool Vertex2D::operator>(Vertex2D *v)
{
	return (this->length() > v->length());
};

bool Vertex2D::operator>(Vertex2D v)
{
	return (this->length() > v.length());
};

bool Vertex2D::operator<=(Vertex2D *v)
{
	return (this->length() <= v->length());
};

bool Vertex2D::operator<=(Vertex2D v)
{
	return (this->length() <= v.length());
};
		
bool Vertex2D::operator>=(Vertex2D *v)
{
	return (this->length() >= v->length());
};

bool Vertex2D::operator>=(Vertex2D v)
{
	return (this->length() >= v.length());
};

		// methods
Vertex2D::Vertex2D()
{
	this->x = 0;
	this->y = 0;
};

Vertex2D::Vertex2D(Vertex2D *v)
{
	this->x = v->x;
	this->y = v->y;
};

Vertex2D::Vertex2D(const Vertex2D &v)
{
	this->x = v.x;
	this->y = v.y;
};

GLfloat Vertex2D::length()
{
	return fastmath::sqrtf((this->x * this->x) + (this->y * this->y));
};

void Vertex2D::lerpFast(Vertex2D *v1, Vertex2D *v2, GLfloat l)
{
	this->x = v1->x + ((v1->x - v2->x) * l);
	this->y = v1->y + ((v1->y - v2->y) * l);
};

void Vertex2D::lerpFast(Vertex2D v1, Vertex2D v2, GLfloat l)
{
	this->x = v1.x + ((v1.x - v2.x) * l);
	this->y = v1.y + ((v1.y - v2.y) * l);
};

void Vertex2D::slerpFast(Vertex2D *v1, Vertex2D *v2, GLfloat l)
{
	GLfloat ft = l * PI;
	GLfloat f = (1.0 - cos(ft)) * 0.5;
	this->x = v1->x + ((v1->x - v2->x) * (f + l) * 0.5);
	this->y = v1->y + ((v1->y - v2->y) * (f + l) * 0.5);
};

void Vertex2D::slerpFast(Vertex2D v1, Vertex2D v2, GLfloat l)
{
	GLfloat ft = l * PI;
	GLfloat f = (((1.0 - cos(ft)) * 0.5) + l) * 0.5;
	this->x = v1.x + ((v1.x - v2.x) * f);
	this->y = v1.y + ((v1.y - v2.y) * f);
};

		// 4 point
void Vertex2D::bezier(Vertex2D v[], GLfloat t)
{
	GLfloat u = 1.0f - t;
	GLfloat tt = t*t;
	GLfloat uu = u*u;
	GLfloat ttt = tt*t;
	GLfloat uuu = uu*u;
	
	Vertex2D vt = v[1] - (v[0] - v[1]);
	*this = v[1] * uuu;
	*this += vt * (3.0f * uu * t);
	*this += v[2] * (3.0f * u * tt);
	*this += v[3] * ttt;
};

void Vertex2D::normalize()
{
	GLfloat l = this->length();
	if(l > 0.0f) *this /= l;
};

GLfloat Vertex2D::toAngle()
{
	return atan2(this->y, this->x);
};

void Vertex2D::set(GLfloat x, GLfloat y)
{
	this->x = x;
	this->y = y;
};

	};
};

