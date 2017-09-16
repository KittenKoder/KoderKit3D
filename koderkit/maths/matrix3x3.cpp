#include "matrix.hpp"
#include <math.h>
#include "fastmath.hpp"

using namespace kk3d::math;

Matrix3x3 Matrix3x3::operator=(GLfloat a) {
    GLfloat lenx = this->getXScale();
    GLfloat leny = this->getYScale();

    if(lenx == 0.0) lenx = 1;
    if(leny == 0.0) leny = 1;

    GLfloat s = sin(a);
    GLfloat c = cos(a);

    this->data[0] = c * lenx;
    this->data[1] = (-s) * lenx;

    this->data[3] = s * leny;
    this->data[4] = c * leny;

    return (*this);
};

Matrix3x3 Matrix3x3::operator=(Matrix3x3 m) {
    memcpy(this->data, m.data, 9 * sizeof(GLfloat));
    return (*this);
};

Matrix3x3 Matrix3x3::operator=(Matrix3x3 *m) {
    memcpy(this->data, m->data, 9 * sizeof(GLfloat));
    return (*this);
};

Matrix3x3 Matrix3x3::operator-=(Matrix3x3 m) {
    for(int r = 0; r < 3; r++)
        for(int c = 0; c < 3; c++)
            this->data[(r * 3) + c] = m.data[(c * 3) + r];

    return (*this);
};

Matrix3x3 Matrix3x3::operator-=(Matrix3x3 *m) {
    for(int r = 0; r < 3; r++)
        for(int c = 0; c < 3; c++)
            this->data[(r * 3) + c] = m->data[(c * 3) + r];

    return (*this);
};

Matrix3x3 Matrix3x3::operator-() {
    Matrix3x3 rv;
    for(int r = 0; r < 3; r++)
        for(int c = 0; c < 3; c++)
            rv.data[(r * 3) + c] = this->data[(c * 3) + r];

    return rv;
};

GLfloat Matrix3x3::operator()(int c, int r) {
    return (this->data[c + (r * 3)]);
};

Matrix3x3 Matrix3x3::operator/=(Matrix3x3 mt) {
    Matrix3x3 *m = &mt;
    GLfloat m1122 = (*m)(1, 1) * (*m)(2, 2);
    GLfloat m2112 = (*m)(2, 1) * (*m)(1, 2);
    GLfloat m1022 = (*m)(1, 0) * (*m)(2, 2);
    GLfloat m1220 = (*m)(1, 2) * (*m)(2, 0);
    GLfloat m1021 = (*m)(1, 0) * (*m)(2, 1);
    GLfloat m1120 = (*m)(1, 1) * (*m)(2, 0);
    GLfloat m0221 = (*m)(0, 2) * (*m)(2, 1);
    GLfloat m0122 = (*m)(0, 1) * (*m)(2, 2);
    GLfloat m0112 = (*m)(0, 1) * (*m)(1, 2);
    GLfloat m0211 = (*m)(0, 2) * (*m)(1, 1);
    GLfloat m0022 = (*m)(0, 0) * (*m)(2, 2);
    GLfloat m0220 = (*m)(0, 2) * (*m)(2, 0);
    GLfloat m1002 = (*m)(1, 0) * (*m)(0, 2);
    GLfloat m0012 = (*m)(0, 0) * (*m)(1, 2);
    GLfloat m2001 = (*m)(2, 0) * (*m)(0, 1);
    GLfloat m0021 = (*m)(0, 0) * (*m)(2, 1);
    GLfloat m0011 = (*m)(0, 0) * (*m)(1, 1);
    GLfloat m2011 = (*m)(2, 0) * (*m)(1, 1);
    GLfloat m1001 = (*m)(1, 0) * (*m)(0, 1);

    GLfloat d = 1.0f / ((*m)(0, 0) * (m1122 - m2112) -
                        (*m)(0, 1) * (m1022 - m1220) +
                        (*m)(0, 2) * (m1021 - m1120));

    this->set(0, 0, (m1122 - m2112) * d);
    this->set(0, 1, (m0221 - m0122) * d);
    this->set(0, 2, (m0112 - m0211) * d);
    this->set(1, 0, (m1220 - m1022) * d);
    this->set(1, 1, (m0022 - m0220) * d);
    this->set(1, 2, (m1002 - m0012) * d);
    this->set(2, 0, (m1021 - m2011) * d);
    this->set(2, 1, (m2001 - m0021) * d);
    this->set(2, 2, (m0011 - m1001) * d);
    return (*this);
};

Matrix3x3 Matrix3x3::operator/=(Matrix3x3 *m) {
    GLfloat m1122 = (*m)(1, 1) * (*m)(2, 2);
    GLfloat m2112 = (*m)(2, 1) * (*m)(1, 2);
    GLfloat m1022 = (*m)(1, 0) * (*m)(2, 2);
    GLfloat m1220 = (*m)(1, 2) * (*m)(2, 0);
    GLfloat m1021 = (*m)(1, 0) * (*m)(2, 1);
    GLfloat m1120 = (*m)(1, 1) * (*m)(2, 0);
    GLfloat m0221 = (*m)(0, 2) * (*m)(2, 1);
    GLfloat m0122 = (*m)(0, 1) * (*m)(2, 2);
    GLfloat m0112 = (*m)(0, 1) * (*m)(1, 2);
    GLfloat m0211 = (*m)(0, 2) * (*m)(1, 1);
    GLfloat m0022 = (*m)(0, 0) * (*m)(2, 2);
    GLfloat m0220 = (*m)(0, 2) * (*m)(2, 0);
    GLfloat m1002 = (*m)(1, 0) * (*m)(0, 2);
    GLfloat m0012 = (*m)(0, 0) * (*m)(1, 2);
    GLfloat m2001 = (*m)(2, 0) * (*m)(0, 1);
    GLfloat m0021 = (*m)(0, 0) * (*m)(2, 1);
    GLfloat m0011 = (*m)(0, 0) * (*m)(1, 1);
    GLfloat m2011 = (*m)(2, 0) * (*m)(1, 1);
    GLfloat m1001 = (*m)(1, 0) * (*m)(0, 1);

    GLfloat d = 1.0f / ((*m)(0, 0) * (m1122 - m2112) -
                        (*m)(0, 1) * (m1022 - m1220) +
                        (*m)(0, 2) * (m1021 - m1120));

    this->set(0, 0, (m1122 - m2112) * d);
    this->set(0, 1, (m0221 - m0122) * d);
    this->set(0, 2, (m0112 - m0211) * d);
    this->set(1, 0, (m1220 - m1022) * d);
    this->set(1, 1, (m0022 - m0220) * d);
    this->set(1, 2, (m1002 - m0012) * d);
    this->set(2, 0, (m1021 - m2011) * d);
    this->set(2, 1, (m2001 - m0021) * d);
    this->set(2, 2, (m0011 - m1001) * d);
    return (*this);
};

Matrix3x3 Matrix3x3::operator*=(Matrix3x3 m) {
    float m0 = (this->data[0] * m.data[0]) +
               (this->data[3] * m.data[1]) +
               (this->data[6] * m.data[2]);
    float m1 = (this->data[1] * m.data[0]) +
               (this->data[4] * m.data[1]) +
               (this->data[7] * m.data[2]);
    float m2 = (this->data[2] * m.data[0]) +
               (this->data[5] * m.data[1]) +
               (this->data[8] * m.data[2]);

    float m3 = (this->data[0] * m.data[3]) +
               (this->data[3] * m.data[4]) +
               (this->data[6] * m.data[5]);
    float m4 = (this->data[1] * m.data[3]) +
               (this->data[4] * m.data[4]) +
               (this->data[7] * m.data[5]);
    float m5 = (this->data[2] * m.data[3]) +
               (this->data[5] * m.data[4]) +
               (this->data[8] * m.data[5]);

    float m6 = (this->data[0] * m.data[6]) +
               (this->data[3] * m.data[7]) +
               (this->data[6] * m.data[8]);
    float m7 = (this->data[1] * m.data[6]) +
               (this->data[4] * m.data[7]) +
               (this->data[7] * m.data[8]);
    float m8 = (this->data[2] * m.data[6]) +
               (this->data[5] * m.data[7]) +
               (this->data[8] * m.data[8]);

    this->data[0] = m0;
    this->data[1] = m1;
    this->data[2] = m2;

    this->data[3] = m3;
    this->data[4] = m4;
    this->data[5] = m5;

    this->data[6] = m6;
    this->data[7] = m7;
    this->data[8] = m8;
    return (*this);
};

Matrix3x3 Matrix3x3::operator*=(Matrix3x3 *m) {
    float m0 = (this->data[0] * m->data[0]) +
               (this->data[3] * m->data[1]) +
               (this->data[6] * m->data[2]);
    float m1 = (this->data[1] * m->data[0]) +
               (this->data[4] * m->data[1]) +
               (this->data[7] * m->data[2]);
    float m2 = (this->data[2] * m->data[0]) +
               (this->data[5] * m->data[1]) +
               (this->data[8] * m->data[2]);

    float m3 = (this->data[0] * m->data[3]) +
               (this->data[3] * m->data[4]) +
               (this->data[6] * m->data[5]);
    float m4 = (this->data[1] * m->data[3]) +
               (this->data[4] * m->data[4]) +
               (this->data[7] * m->data[5]);
    float m5 = (this->data[2] * m->data[3]) +
               (this->data[5] * m->data[4]) +
               (this->data[8] * m->data[5]);

    float m6 = (this->data[0] * m->data[6]) +
               (this->data[3] * m->data[7]) +
               (this->data[6] * m->data[8]);
    float m7 = (this->data[1] * m->data[6]) +
               (this->data[4] * m->data[7]) +
               (this->data[7] * m->data[8]);
    float m8 = (this->data[2] * m->data[6]) +
               (this->data[5] * m->data[7]) +
               (this->data[8] * m->data[8]);

    this->data[0] = m0;
    this->data[1] = m1;
    this->data[2] = m2;

    this->data[3] = m3;
    this->data[4] = m4;
    this->data[5] = m5;

    this->data[6] = m6;
    this->data[7] = m7;
    this->data[8] = m8;
    return (*this);
};

Matrix3x3 Matrix3x3::operator*(Matrix3x3 m) {
    Matrix3x3 rv;
    float m0 = (this->data[0] * m.data[0]) +
               (this->data[3] * m.data[1]) +
               (this->data[6] * m.data[2]);
    float m1 = (this->data[1] * m.data[0]) +
               (this->data[4] * m.data[1]) +
               (this->data[7] * m.data[2]);
    float m2 = (this->data[2] * m.data[0]) +
               (this->data[5] * m.data[1]) +
               (this->data[8] * m.data[2]);

    float m3 = (this->data[0] * m.data[3]) +
               (this->data[3] * m.data[4]) +
               (this->data[6] * m.data[5]);
    float m4 = (this->data[1] * m.data[3]) +
               (this->data[4] * m.data[4]) +
               (this->data[7] * m.data[5]);
    float m5 = (this->data[2] * m.data[3]) +
               (this->data[5] * m.data[4]) +
               (this->data[8] * m.data[5]);

    float m6 = (this->data[0] * m.data[6]) +
               (this->data[3] * m.data[7]) +
               (this->data[6] * m.data[8]);
    float m7 = (this->data[1] * m.data[6]) +
               (this->data[4] * m.data[7]) +
               (this->data[7] * m.data[8]);
    float m8 = (this->data[2] * m.data[6]) +
               (this->data[5] * m.data[7]) +
               (this->data[8] * m.data[8]);

    rv.data[0] = m0;
    rv.data[1] = m1;
    rv.data[2] = m2;

    rv.data[3] = m3;
    rv.data[4] = m4;
    rv.data[5] = m5;

    rv.data[6] = m6;
    rv.data[7] = m7;
    rv.data[8] = m8;
    return rv;
};

Matrix3x3 Matrix3x3::operator*(Matrix3x3 *m) {
    Matrix3x3 rv;
    float m0 = (this->data[0] * m->data[0]) +
               (this->data[3] * m->data[1]) +
               (this->data[6] * m->data[2]);
    float m1 = (this->data[1] * m->data[0]) +
               (this->data[4] * m->data[1]) +
               (this->data[7] * m->data[2]);
    float m2 = (this->data[2] * m->data[0]) +
               (this->data[5] * m->data[1]) +
               (this->data[8] * m->data[2]);

    float m3 = (this->data[0] * m->data[3]) +
               (this->data[3] * m->data[4]) +
               (this->data[6] * m->data[5]);
    float m4 = (this->data[1] * m->data[3]) +
               (this->data[4] * m->data[4]) +
               (this->data[7] * m->data[5]);
    float m5 = (this->data[2] * m->data[3]) +
               (this->data[5] * m->data[4]) +
               (this->data[8] * m->data[5]);

    float m6 = (this->data[0] * m->data[6]) +
               (this->data[3] * m->data[7]) +
               (this->data[6] * m->data[8]);
    float m7 = (this->data[1] * m->data[6]) +
               (this->data[4] * m->data[7]) +
               (this->data[7] * m->data[8]);
    float m8 = (this->data[2] * m->data[6]) +
               (this->data[5] * m->data[7]) +
               (this->data[8] * m->data[8]);

    rv.data[0] = m0;
    rv.data[1] = m1;
    rv.data[2] = m2;

    rv.data[3] = m3;
    rv.data[4] = m4;
    rv.data[5] = m5;

    rv.data[6] = m6;
    rv.data[7] = m7;
    rv.data[8] = m8;
    return rv;
};

Vertex3D Matrix3x3::operator*(Vertex3D v) {
    Vertex3D rv;
    rv.x = (this->data[0] * v.x) + (this->data[3] * v.y) + (this->data[6] * v.z);
    rv.y = (this->data[1] * v.x) + (this->data[4] * v.y) + (this->data[7] * v.z);
    rv.z = (this->data[2] * v.x) + (this->data[5] * v.y) + (this->data[8] * v.z);
    return rv;
};

Vertex3D Matrix3x3::operator*(Vertex3D *v) {
    Vertex3D rv;
    rv.x = (this->data[0] * v->x) + (this->data[3] * v->y) + (this->data[6] * v->z);
    rv.y = (this->data[1] * v->x) + (this->data[4] * v->y) + (this->data[7] * v->z);
    rv.z = (this->data[2] * v->x) + (this->data[5] * v->y) + (this->data[8] * v->z);
    return rv;
};

Vertex2D Matrix3x3::operator*(Vertex2D v) {
    Vertex2D rv;
    rv.x = (this->data[0] * v.x) + (this->data[3] * v.y) + this->data[6];
    rv.y = (this->data[1] * v.x) + (this->data[4] * v.y) + this->data[7];
    return rv;
};

Vertex2D Matrix3x3::operator*(Vertex2D *v) {
    Vertex2D rv;
    rv.x = (this->data[0] * v->x) + (this->data[3] * v->y) + this->data[6];
    rv.y = (this->data[1] * v->x) + (this->data[4] * v->y) + this->data[7];
    return rv;
};

void Matrix3x3::set(int c, int r, GLfloat v) {
    this->data[c + (r * 3)] = v;
};

GLfloat Matrix3x3::determinant() {
    return (*this)(0, 0) * ((*this)(1, 1) * (*this)(2, 2) - (*this)(2, 1) * (*this)(1, 2)) -
           (*this)(0, 1) * ((*this)(1, 0) * (*this)(2, 2) - (*this)(1, 2) * (*this)(2, 0)) +
           (*this)(0, 2) * ((*this)(1, 0) * (*this)(2, 1) - (*this)(1, 1) * (*this)(2, 0));
};

void Matrix3x3::identity() {
    for(int i = 0; i < 9; i++) this->data[i] = 0;
    this->data[0] = 1.0f;
    this->data[4] = 1.0f;
    this->data[8] = 1.0f;

};

void Matrix3x3::createRotationFromQuaternion(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    this->data[0] = (1.0 - (2.0 * (y * y)) - (2.0 * (z * z)));
    this->data[3] = ((2.0 * x * y) - (2.0 * z * w));
    this->data[6] = ((2.0 * x * z) + (2.0 * y * w));

    this->data[1] = ((2.0 * x * y) + (2.0 * z * w));
    this->data[4] = (1.0 - (2.0 * (x * x)) - (2.0 * (z * z)));
    this->data[7] = ((2.0 * z * y) - (2.0 * x * w));

    this->data[2] = ((2.0 * x * z) - (2.0 * y * w));
    this->data[5] = ((2.0 * y * z) + (2.0 * x * w));
    this->data[8] = (1.0 - (2.0 * (x * x)) - (2.0 * (y * y)));
};

void Matrix3x3::createRotationFromAxisAngle(GLfloat x, GLfloat y, GLfloat z, GLfloat a) {
    GLfloat s = sin(a);
    GLfloat c = cos(a);
    GLfloat len = fastmath::sqrtf((x * x) + (y * y) + (z * z));

    if(len == 0.0) return;

    x /= len;
    y /= len;
    z /= len;

    GLfloat nc = 1.0 - c;
    GLfloat xy = x * y;
    GLfloat yz = y * z;
    GLfloat zx = z * x;
    GLfloat xs = x * s;
    GLfloat ys = y * s;
    GLfloat zs = z * s;

    this->data[0] = (x*x*nc) + c;
    this->data[4] = (y*y*nc) + c;
    this->data[8] = (z*z*nc) + c;

    this->data[3] = (xy*nc) - zs;
    this->data[1] = (xy*nc) + zs;

    this->data[6] = (zx*nc) + ys;
    this->data[2] = (zx*nc) - ys;

    this->data[7] = (yz*nc) - xs;
    this->data[5] = (yz*nc) + xs;
};

Matrix3x3 Matrix3x3::operator=(Vertex4D v) {
    this->data[0] = (1.0 - (2.0 * (v.y * v.y)) - (2.0 * (v.z * v.z)));
    this->data[3] = ((2.0 * v.x * v.y) - (2.0 * v.z * v.w));
    this->data[6] = ((2.0 * v.x * v.z) + (2.0 * v.y * v.w));

    this->data[1] = ((2.0 * v.x * v.y) + (2.0 * v.z * v.w));
    this->data[4] = (1.0 - (2.0 * (v.x * v.x)) - (2.0 * (v.z * v.z)));
    this->data[7] = ((2.0 * v.z * v.y) - (2.0 * v.x * v.w));

    this->data[2] = ((2.0 * v.x * v.z) - (2.0 * v.y * v.w));
    this->data[5] = ((2.0 * v.y * v.z) + (2.0 * v.x * v.w));
    this->data[8] = (1.0 - (2.0 * (v.x * v.x)) - (2.0 * (v.y * v.y)));
    return (*this);
};

Matrix3x3 Matrix3x3::operator=(Vertex4D *v) {
    this->data[0] = (1.0 - (2.0 * (v->y * v->y)) - (2.0 * (v->z * v->z)));
    this->data[3] = ((2.0 * v->x * v->y) - (2.0 * v->z * v->w));
    this->data[6] = ((2.0 * v->x * v->z) + (2.0 * v->y * v->w));

    this->data[1] = ((2.0 * v->x * v->y) + (2.0 * v->z * v->w));
    this->data[4] = (1.0 - (2.0 * (v->x * v->x)) - (2.0 * (v->z * v->z)));
    this->data[7] = ((2.0 * v->z * v->y) - (2.0 * v->x * v->w));

    this->data[2] = ((2.0 * v->x * v->z) - (2.0 * v->y * v->w));
    this->data[5] = ((2.0 * v->y * v->z) + (2.0 * v->x * v->w));
    this->data[8] = (1.0 - (2.0 * (v->x * v->x)) - (2.0 * (v->y * v->y)));
    return (*this);
};

void Matrix3x3::setScale(GLfloat x, GLfloat y) {
    GLfloat lenx = this->getXScale();
    GLfloat leny = this->getYScale();

    if(lenx == 0.0) lenx = 1;
    if(leny == 0.0) leny = 1;

    this->data[0] = (this->data[0] / lenx) * x;
    this->data[1] = (this->data[1] / lenx) * x;

    this->data[3] = (this->data[3] / leny) * y;
    this->data[4] = (this->data[4] / leny) * y;
};

void Matrix3x3::scaleBy(GLfloat x, GLfloat y) {
    this->data[0] = this->data[0] * x;
    this->data[1] = this->data[1] * x;

    this->data[3] = this->data[3] * y;
    this->data[4] = this->data[4] * y;
};

void Matrix3x3::setXScale(GLfloat v) {
    GLfloat lenx = this->getXScale();

    if(lenx == 0.0) lenx = 1;

    this->data[0] = (this->data[0] / lenx) * v;
    this->data[1] = (this->data[1] / lenx) * v;
};

void Matrix3x3::setYScale(GLfloat v) {
    GLfloat leny = this->getYScale();

    if(leny == 0.0) leny = 1;

    this->data[3] = (this->data[3] / leny) * v;
    this->data[4] = (this->data[4] / leny) * v;
};

GLfloat Matrix3x3::getXScale() {
    GLfloat val = fastmath::sqrtf((this->data[0] * this->data[0]) + (this->data[1] * this->data[1]));
    //if(this->data[0] < 0) return -val;
    return val;
};

void Matrix3x3::setLocation(GLfloat x, GLfloat y) {
    this->data[6] = x;
    this->data[7] = y;
};

GLfloat Matrix3x3::getYScale() {
    GLfloat val = fastmath::sqrtf((this->data[3] * this->data[3]) + (this->data[4] * this->data[4]));
    //if(this->data[4] < 0) return -val;
    return val;
};
