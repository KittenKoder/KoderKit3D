#include "matrix.hpp"
#include <GL/glew.h>
#include <GL/gl.h>
#include <math.h>
#include <cstring>
#include "fastmath.hpp"

using namespace kk3d::math;

Matrix4x4 Matrix4x4::operator=(Matrix4x4 m) {
    memcpy(this->data, m.data, 16 * sizeof(GLfloat));
    return (*this);
};

Matrix4x4 Matrix4x4::operator=(Matrix4x4 *m) {
    memcpy(this->data, m->data, 16 * sizeof(GLfloat));
    return (*this);
};

Matrix4x4 Matrix4x4::operator-() {
    Matrix4x4 rv;
    for(int r = 0; r < 4; r++)
        for(int c = 0; c < 4; c++)
            rv.data[(r * 4) + c] = this->data[(c * 4) + r];

    return rv;
};

Matrix4x4 Matrix4x4::operator-=(Matrix4x4 m) {
    for(int r = 0; r < 4; r++)
        for(int c = 0; c < 4; c++)
            this->data[(r * 4) + c] = m.data[(c * 4) + r];

    return (*this);
};

Matrix4x4 Matrix4x4::operator-=(Matrix4x4 *m) {
    for(int r = 0; r < 4; r++)
        for(int c = 0; c < 4; c++)
            this->data[(r * 4) + c] = m->data[(c * 4) + r];

    return (*this);
};

GLfloat Matrix4x4::operator()(int c, int r) {
    return (this->data[c + (r * 4)]);
};

Matrix4x4 Matrix4x4::operator/=(Matrix4x4 mt) {
    GLfloat tmp[12], dst[16];

    // calculate pairs for first 8 elements (cofactors)
    tmp[0] = mt.data[10] * mt.data[15];
    tmp[1] = mt.data[14] * mt.data[11];
    tmp[2] = mt.data[6] * mt.data[15];
    tmp[3] = mt.data[14] * mt.data[7];
    tmp[4] = mt.data[6] * mt.data[11];
    tmp[5] = mt.data[10] * mt.data[7];
    tmp[6] = mt.data[2] * mt.data[15];
    tmp[7] = mt.data[14] * mt.data[3];
    tmp[8] = mt.data[2] * mt.data[11];
    tmp[9] = mt.data[10] * mt.data[3];
    tmp[10] = mt.data[2] * mt.data[7];
    tmp[11] = mt.data[6] * mt.data[3];

    // calculate first 8 elements (cofactors)
    dst[0] = tmp[0] * mt.data[5] + tmp[3] * mt.data[9] + tmp[4] * mt.data[13];
    dst[0] -= tmp[1] * mt.data[5] + tmp[2] * mt.data[9] + tmp[5] * mt.data[13];
    dst[1] = tmp[1] * mt.data[1] + tmp[6] * mt.data[9] + tmp[9] * mt.data[13];
    dst[1] -= tmp[0] * mt.data[1] + tmp[7] * mt.data[9] + tmp[8] * mt.data[13];
    dst[2] = tmp[2] * mt.data[1] + tmp[7] * mt.data[5] + tmp[10] * mt.data[13];
    dst[2] -= tmp[3] * mt.data[1] + tmp[6] * mt.data[5] + tmp[11] * mt.data[13];
    dst[3] = tmp[5] * mt.data[1] + tmp[8] * mt.data[5] + tmp[11] * mt.data[9];
    dst[3] -= tmp[4] * mt.data[1] + tmp[9] * mt.data[5] + tmp[10] * mt.data[9];
    dst[4] = tmp[1] * mt.data[4] + tmp[2] * mt.data[8] + tmp[5] * mt.data[12];
    dst[4] -= tmp[0] * mt.data[4] + tmp[3] * mt.data[8] + tmp[4] * mt.data[12];
    dst[5] = tmp[0] * mt.data[0] + tmp[7] * mt.data[8] + tmp[8] * mt.data[12];
    dst[5] -= tmp[1] * mt.data[0] + tmp[6] * mt.data[8] + tmp[9] * mt.data[12];
    dst[6] = tmp[3] * mt.data[0] + tmp[6] * mt.data[4] + tmp[11] * mt.data[12];
    dst[6] -= tmp[2] * mt.data[0] + tmp[7] * mt.data[4] + tmp[10] * mt.data[12];
    dst[7] = tmp[4] * mt.data[0] + tmp[9] * mt.data[4] + tmp[10] * mt.data[8];
    dst[7] -= tmp[5] * mt.data[0] + tmp[8] * mt.data[4] + tmp[11] * mt.data[8];

    // calculate pairs for second 8 elements (cofactors)
    tmp[0] = mt.data[8] * mt.data[13];
    tmp[1] = mt.data[12] * mt.data[9];
    tmp[2] = mt.data[4] * mt.data[13];
    tmp[3] = mt.data[12] * mt.data[5];
    tmp[4] = mt.data[4] * mt.data[9];
    tmp[5] = mt.data[8] * mt.data[5];
    tmp[6] = mt.data[0] * mt.data[13];
    tmp[7] = mt.data[12] * mt.data[1];
    tmp[8] = mt.data[0] * mt.data[9];
    tmp[9] = mt.data[8] * mt.data[1];
    tmp[10] = mt.data[0] * mt.data[5];
    tmp[11] = mt.data[4] * mt.data[1];

    // calculate second 8 elements (cofactors)
    dst[8] = tmp[0] * mt.data[7] + tmp[3] * mt.data[11] + tmp[4] * mt.data[15];
    dst[8] -= tmp[1] * mt.data[7] + tmp[2] * mt.data[11] + tmp[5] * mt.data[15];
    dst[9] = tmp[1] * mt.data[3] + tmp[6] * mt.data[11] + tmp[9] * mt.data[15];
    dst[9] -= tmp[0] * mt.data[3] + tmp[7] * mt.data[11] + tmp[8] * mt.data[15];
    dst[10] = tmp[2] * mt.data[3] + tmp[7] * mt.data[7] + tmp[10] * mt.data[15];
    dst[10] -= tmp[3] * mt.data[3] + tmp[6] * mt.data[7] + tmp[11] * mt.data[15];
    dst[11] = tmp[5] * mt.data[3] + tmp[8] * mt.data[7] + tmp[11] * mt.data[11];
    dst[11] -= tmp[4] * mt.data[3] + tmp[9] * mt.data[7] + tmp[10] * mt.data[11];
    dst[12] = tmp[2] * mt.data[10] + tmp[5] * mt.data[14] + tmp[1] * mt.data[3];
    dst[12] -= tmp[4] * mt.data[14] + tmp[0] * mt.data[6] + tmp[3] * mt.data[10];
    dst[13] = tmp[8] * mt.data[14] + tmp[0] * mt.data[2] + tmp[7] * mt.data[10];
    dst[13] -= tmp[6] * mt.data[10] + tmp[9] * mt.data[14] + tmp[1] * mt.data[2];
    dst[14] = tmp[6] * mt.data[6] + tmp[11] * mt.data[14] + tmp[3] * mt.data[2];
    dst[14] -= tmp[10] * mt.data[14] + tmp[2] * mt.data[2] + tmp[7] * mt.data[6];
    dst[15] = tmp[10] * mt.data[10] + tmp[4] * mt.data[2] + tmp[9] * mt.data[6];
    dst[15] -= tmp[8] * mt.data[6] + tmp[11] * mt.data[10] + tmp[5] * mt.data[2];

    // calculate determinant
    GLfloat det = mt.data[0] * dst[0] + mt.data[4] * dst[1] +
                  mt.data[8] * dst[2] + mt.data[12] * dst[3];

    if (det == 0.0) return (*this);

    // calculate matrix inverse
    det = 1.0 / det;
    int j;
    for (j = 0; j < 16; j++) this->data[j] = dst[j] * det;
    return (*this);
};

Matrix4x4 Matrix4x4::operator/=(Matrix4x4 *m) {
    GLfloat tmp[12], dst[16];

    // calculate pairs for first 8 elements (cofactors)
    tmp[0] = m->data[10] * m->data[15];
    tmp[1] = m->data[14] * m->data[11];
    tmp[2] = m->data[6] * m->data[15];
    tmp[3] = m->data[14] * m->data[7];
    tmp[4] = m->data[6] * m->data[11];
    tmp[5] = m->data[10] * m->data[7];
    tmp[6] = m->data[2] * m->data[15];
    tmp[7] = m->data[14] * m->data[3];
    tmp[8] = m->data[2] * m->data[11];
    tmp[9] = m->data[10] * m->data[3];
    tmp[10] = m->data[2] * m->data[7];
    tmp[11] = m->data[6] * m->data[3];

    // calculate first 8 elements (cofactors)
    dst[0] = tmp[0] * m->data[5] + tmp[3] * m->data[9] + tmp[4] * m->data[13];
    dst[0] -= tmp[1] * m->data[5] + tmp[2] * m->data[9] + tmp[5] * m->data[13];
    dst[1] = tmp[1] * m->data[1] + tmp[6] * m->data[9] + tmp[9] * m->data[13];
    dst[1] -= tmp[0] * m->data[1] + tmp[7] * m->data[9] + tmp[8] * m->data[13];
    dst[2] = tmp[2] * m->data[1] + tmp[7] * m->data[5] + tmp[10] * m->data[13];
    dst[2] -= tmp[3] * m->data[1] + tmp[6] * m->data[5] + tmp[11] * m->data[13];
    dst[3] = tmp[5] * m->data[1] + tmp[8] * m->data[5] + tmp[11] * m->data[9];
    dst[3] -= tmp[4] * m->data[1] + tmp[9] * m->data[5] + tmp[10] * m->data[9];
    dst[4] = tmp[1] * m->data[4] + tmp[2] * m->data[8] + tmp[5] * m->data[12];
    dst[4] -= tmp[0] * m->data[4] + tmp[3] * m->data[8] + tmp[4] * m->data[12];
    dst[5] = tmp[0] * m->data[0] + tmp[7] * m->data[8] + tmp[8] * m->data[12];
    dst[5] -= tmp[1] * m->data[0] + tmp[6] * m->data[8] + tmp[9] * m->data[12];
    dst[6] = tmp[3] * m->data[0] + tmp[6] * m->data[4] + tmp[11] * m->data[12];
    dst[6] -= tmp[2] * m->data[0] + tmp[7] * m->data[4] + tmp[10] * m->data[12];
    dst[7] = tmp[4] * m->data[0] + tmp[9] * m->data[4] + tmp[10] * m->data[8];
    dst[7] -= tmp[5] * m->data[0] + tmp[8] * m->data[4] + tmp[11] * m->data[8];

    // calculate pairs for second 8 elements (cofactors)
    tmp[0] = m->data[8] * m->data[13];
    tmp[1] = m->data[12] * m->data[9];
    tmp[2] = m->data[4] * m->data[13];
    tmp[3] = m->data[12] * m->data[5];
    tmp[4] = m->data[4] * m->data[9];
    tmp[5] = m->data[8] * m->data[5];
    tmp[6] = m->data[0] * m->data[13];
    tmp[7] = m->data[12] * m->data[1];
    tmp[8] = m->data[0] * m->data[9];
    tmp[9] = m->data[8] * m->data[1];
    tmp[10] = m->data[0] * m->data[5];
    tmp[11] = m->data[4] * m->data[1];

    // calculate second 8 elements (cofactors)
    dst[8] = tmp[0] * m->data[7] + tmp[3] * m->data[11] + tmp[4] * m->data[15];
    dst[8] -= tmp[1] * m->data[7] + tmp[2] * m->data[11] + tmp[5] * m->data[15];
    dst[9] = tmp[1] * m->data[3] + tmp[6] * m->data[11] + tmp[9] * m->data[15];
    dst[9] -= tmp[0] * m->data[3] + tmp[7] * m->data[11] + tmp[8] * m->data[15];
    dst[10] = tmp[2] * m->data[3] + tmp[7] * m->data[7] + tmp[10] * m->data[15];
    dst[10] -= tmp[3] * m->data[3] + tmp[6] * m->data[7] + tmp[11] * m->data[15];
    dst[11] = tmp[5] * m->data[3] + tmp[8] * m->data[7] + tmp[11] * m->data[11];
    dst[11] -= tmp[4] * m->data[3] + tmp[9] * m->data[7] + tmp[10] * m->data[11];
    dst[12] = tmp[2] * m->data[10] + tmp[5] * m->data[14] + tmp[1] * m->data[3];
    dst[12] -= tmp[4] * m->data[14] + tmp[0] * m->data[6] + tmp[3] * m->data[10];
    dst[13] = tmp[8] * m->data[14] + tmp[0] * m->data[2] + tmp[7] * m->data[10];
    dst[13] -= tmp[6] * m->data[10] + tmp[9] * m->data[14] + tmp[1] * m->data[2];
    dst[14] = tmp[6] * m->data[6] + tmp[11] * m->data[14] + tmp[3] * m->data[2];
    dst[14] -= tmp[10] * m->data[14] + tmp[2] * m->data[2] + tmp[7] * m->data[6];
    dst[15] = tmp[10] * m->data[10] + tmp[4] * m->data[2] + tmp[9] * m->data[6];
    dst[15] -= tmp[8] * m->data[6] + tmp[11] * m->data[10] + tmp[5] * m->data[2];

    // calculate determinant
    GLfloat det = m->data[0] * dst[0] + m->data[4] * dst[1] +
                  m->data[8] * dst[2] + m->data[12] * dst[3];

    if (det == 0.0) return (*this);

    // calculate matrix inverse
    det = 1.0 / det;
    int j;
    for (j = 0; j < 16; j++) this->data[j] = dst[j] * det;
    return (*this);
};

Matrix4x4 Matrix4x4::operator*=(Matrix4x4 m) {
    GLfloat m0 = (this->data[0] * m.data[0]) + (this->data[4] * m.data[1]) +
                 (this->data[8] * m.data[2]) + (this->data[12] * m.data[3]);

    GLfloat m1 = (this->data[1] * m.data[0]) + (this->data[5] * m.data[1]) +
                 (this->data[9] * m.data[2]) + (this->data[13] * m.data[3]);

    GLfloat m2 = (this->data[2] * m.data[0]) + (this->data[6] * m.data[1]) +
                 (this->data[10] * m.data[2]) + (this->data[14] * m.data[3]);

    GLfloat m3 = (this->data[3] * m.data[0]) + (this->data[7] * m.data[1]) +
                 (this->data[11] * m.data[2]) + (this->data[15] * m.data[3]);

    GLfloat m4 = (this->data[0] * m.data[4]) + (this->data[4] * m.data[5]) +
                 (this->data[8] * m.data[6]) + (this->data[12] * m.data[7]);

    GLfloat m5 = (this->data[1] * m.data[4]) + (this->data[5] * m.data[5]) +
                 (this->data[9] * m.data[6]) + (this->data[13] * m.data[7]);

    GLfloat m6 = (this->data[2] * m.data[4]) + (this->data[6] * m.data[5]) +
                 (this->data[10] * m.data[6]) + (this->data[14] * m.data[7]);

    GLfloat m7 = (this->data[3] * m.data[4]) + (this->data[7] * m.data[5]) +
                 (this->data[11] * m.data[6]) + (this->data[15] * m.data[7]);

    GLfloat m8 = (this->data[0] * m.data[8]) + (this->data[4] * m.data[9]) +
                 (this->data[8] * m.data[10]) + (this->data[12] * m.data[11]);

    GLfloat m9 = (this->data[1] * m.data[8]) + (this->data[5] * m.data[9]) +
                 (this->data[9] * m.data[10]) + (this->data[13] * m.data[11]);

    GLfloat m10 = (this->data[2] * m.data[8]) + (this->data[6] * m.data[9]) +
                  (this->data[10] * m.data[10]) + (this->data[14] * m.data[11]);

    GLfloat m11 = (this->data[3] * m.data[8]) + (this->data[7] * m.data[9]) +
                  (this->data[11] * m.data[10]) + (this->data[15] * m.data[11]);

    GLfloat m12 = (this->data[0] * m.data[12]) + (this->data[4] * m.data[13]) +
                  (this->data[8] * m.data[14]) + (this->data[12] * m.data[15]);

    GLfloat m13 = (this->data[1] * m.data[12]) + (this->data[5] * m.data[13]) +
                  (this->data[9] * m.data[14]) + (this->data[13] * m.data[15]);

    GLfloat m14 = (this->data[2] * m.data[12]) + (this->data[6] * m.data[13]) +
                  (this->data[10] * m.data[14]) + (this->data[14] * m.data[15]);

    GLfloat m15 = (this->data[3] * m.data[12]) + (this->data[7] * m.data[13]) +
                  (this->data[11] * m.data[14]) + (this->data[15] * m.data[15]);

    this->data[0] = m0;
    this->data[1] = m1;
    this->data[2] = m2;
    this->data[3] = m3;

    this->data[4] = m4;
    this->data[5] = m5;
    this->data[6] = m6;
    this->data[7] = m7;

    this->data[8] = m8;
    this->data[9] = m9;
    this->data[10] = m10;
    this->data[11] = m11;

    this->data[12] = m12;
    this->data[13] = m13;
    this->data[14] = m14;
    this->data[15] = m15;

    return (*this);
};

Matrix4x4 Matrix4x4::operator*=(Matrix4x4 *m) {
    GLfloat m0 = (this->data[0] * m->data[0]) + (this->data[4] * m->data[1]) +
                 (this->data[8] * m->data[2]) + (this->data[12] * m->data[3]);

    GLfloat m1 = (this->data[1] * m->data[0]) + (this->data[5] * m->data[1]) +
                 (this->data[9] * m->data[2]) + (this->data[13] * m->data[3]);

    GLfloat m2 = (this->data[2] * m->data[0]) + (this->data[6] * m->data[1]) +
                 (this->data[10] * m->data[2]) + (this->data[14] * m->data[3]);

    GLfloat m3 = (this->data[3] * m->data[0]) + (this->data[7] * m->data[1]) +
                 (this->data[11] * m->data[2]) + (this->data[15] * m->data[3]);

    GLfloat m4 = (this->data[0] * m->data[4]) + (this->data[4] * m->data[5]) +
                 (this->data[8] * m->data[6]) + (this->data[12] * m->data[7]);

    GLfloat m5 = (this->data[1] * m->data[4]) + (this->data[5] * m->data[5]) +
                 (this->data[9] * m->data[6]) + (this->data[13] * m->data[7]);

    GLfloat m6 = (this->data[2] * m->data[4]) + (this->data[6] * m->data[5]) +
                 (this->data[10] * m->data[6]) + (this->data[14] * m->data[7]);

    GLfloat m7 = (this->data[3] * m->data[4]) + (this->data[7] * m->data[5]) +
                 (this->data[11] * m->data[6]) + (this->data[15] * m->data[7]);

    GLfloat m8 = (this->data[0] * m->data[8]) + (this->data[4] * m->data[9]) +
                 (this->data[8] * m->data[10]) + (this->data[12] * m->data[11]);

    GLfloat m9 = (this->data[1] * m->data[8]) + (this->data[5] * m->data[9]) +
                 (this->data[9] * m->data[10]) + (this->data[13] * m->data[11]);

    GLfloat m10 = (this->data[2] * m->data[8]) + (this->data[6] * m->data[9]) +
                  (this->data[10] * m->data[10]) + (this->data[14] * m->data[11]);

    GLfloat m11 = (this->data[3] * m->data[8]) + (this->data[7] * m->data[9]) +
                  (this->data[11] * m->data[10]) + (this->data[15] * m->data[11]);

    GLfloat m12 = (this->data[0] * m->data[12]) + (this->data[4] * m->data[13]) +
                  (this->data[8] * m->data[14]) + (this->data[12] * m->data[15]);

    GLfloat m13 = (this->data[1] * m->data[12]) + (this->data[5] * m->data[13]) +
                  (this->data[9] * m->data[14]) + (this->data[13] * m->data[15]);

    GLfloat m14 = (this->data[2] * m->data[12]) + (this->data[6] * m->data[13]) +
                  (this->data[10] * m->data[14]) + (this->data[14] * m->data[15]);

    GLfloat m15 = (this->data[3] * m->data[12]) + (this->data[7] * m->data[13]) +
                  (this->data[11] * m->data[14]) + (this->data[15] * m->data[15]);

    this->data[0] = m0;
    this->data[1] = m1;
    this->data[2] = m2;
    this->data[3] = m3;

    this->data[4] = m4;
    this->data[5] = m5;
    this->data[6] = m6;
    this->data[7] = m7;

    this->data[8] = m8;
    this->data[9] = m9;
    this->data[10] = m10;
    this->data[11] = m11;

    this->data[12] = m12;
    this->data[13] = m13;
    this->data[14] = m14;
    this->data[15] = m15;

    return (*this);
};

Matrix4x4 Matrix4x4::operator*=(Matrix3x3 m) {
    this->data[0] *= m.data[0];
    this->data[1] *= m.data[1];
    this->data[2] *= m.data[2];

    this->data[4] *= m.data[3];
    this->data[5] *= m.data[4];
    this->data[6] *= m.data[5];

    this->data[8] *= m.data[6];
    this->data[9] *= m.data[7];
    this->data[10] *= m.data[8];

    return (*this);
};

Matrix4x4 Matrix4x4::operator*=(Matrix3x3 *m) {
    this->data[0] *= m->data[0];
    this->data[1] *= m->data[1];
    this->data[2] *= m->data[2];

    this->data[4] *= m->data[3];
    this->data[5] *= m->data[4];
    this->data[6] *= m->data[5];

    this->data[8] *= m->data[6];
    this->data[9] *= m->data[7];
    this->data[10] *= m->data[8];

    return (*this);
};

Matrix4x4 Matrix4x4::operator*(Matrix4x4 m) {
    Matrix4x4 rv;

    GLfloat m0 = (this->data[0] * m.data[0]) + (this->data[4] * m.data[1]) +
                 (this->data[8] * m.data[2]) + (this->data[12] * m.data[3]);

    GLfloat m1 = (this->data[1] * m.data[0]) + (this->data[5] * m.data[1]) +
                 (this->data[9] * m.data[2]) + (this->data[13] * m.data[3]);

    GLfloat m2 = (this->data[2] * m.data[0]) + (this->data[6] * m.data[1]) +
                 (this->data[10] * m.data[2]) + (this->data[14] * m.data[3]);

    GLfloat m3 = (this->data[3] * m.data[0]) + (this->data[7] * m.data[1]) +
                 (this->data[11] * m.data[2]) + (this->data[15] * m.data[3]);

    GLfloat m4 = (this->data[0] * m.data[4]) + (this->data[4] * m.data[5]) +
                 (this->data[8] * m.data[6]) + (this->data[12] * m.data[7]);

    GLfloat m5 = (this->data[1] * m.data[4]) + (this->data[5] * m.data[5]) +
                 (this->data[9] * m.data[6]) + (this->data[13] * m.data[7]);

    GLfloat m6 = (this->data[2] * m.data[4]) + (this->data[6] * m.data[5]) +
                 (this->data[10] * m.data[6]) + (this->data[14] * m.data[7]);

    GLfloat m7 = (this->data[3] * m.data[4]) + (this->data[7] * m.data[5]) +
                 (this->data[11] * m.data[6]) + (this->data[15] * m.data[7]);

    GLfloat m8 = (this->data[0] * m.data[8]) + (this->data[4] * m.data[9]) +
                 (this->data[8] * m.data[10]) + (this->data[12] * m.data[11]);

    GLfloat m9 = (this->data[1] * m.data[8]) + (this->data[5] * m.data[9]) +
                 (this->data[9] * m.data[10]) + (this->data[13] * m.data[11]);

    GLfloat m10 = (this->data[2] * m.data[8]) + (this->data[6] * m.data[9]) +
                  (this->data[10] * m.data[10]) + (this->data[14] * m.data[11]);

    GLfloat m11 = (this->data[3] * m.data[8]) + (this->data[7] * m.data[9]) +
                  (this->data[11] * m.data[10]) + (this->data[15] * m.data[11]);

    GLfloat m12 = (this->data[0] * m.data[12]) + (this->data[4] * m.data[13]) +
                  (this->data[8] * m.data[14]) + (this->data[12] * m.data[15]);

    GLfloat m13 = (this->data[1] * m.data[12]) + (this->data[5] * m.data[13]) +
                  (this->data[9] * m.data[14]) + (this->data[13] * m.data[15]);

    GLfloat m14 = (this->data[2] * m.data[12]) + (this->data[6] * m.data[13]) +
                  (this->data[10] * m.data[14]) + (this->data[14] * m.data[15]);

    GLfloat m15 = (this->data[3] * m.data[12]) + (this->data[7] * m.data[13]) +
                  (this->data[11] * m.data[14]) + (this->data[15] * m.data[15]);

    rv.data[0] = m0;
    rv.data[1] = m1;
    rv.data[2] = m2;
    rv.data[3] = m3;

    rv.data[4] = m4;
    rv.data[5] = m5;
    rv.data[6] = m6;
    rv.data[7] = m7;

    rv.data[8] = m8;
    rv.data[9] = m9;
    rv.data[10] = m10;
    rv.data[11] = m11;

    rv.data[12] = m12;
    rv.data[13] = m13;
    rv.data[14] = m14;
    rv.data[15] = m15;

    return rv;
};

Matrix4x4 Matrix4x4::operator*(Matrix4x4 *m) {
    Matrix4x4 rv;

    GLfloat m0 = (this->data[0] * m->data[0]) + (this->data[4] * m->data[1]) +
                 (this->data[8] * m->data[2]) + (this->data[12] * m->data[3]);

    GLfloat m1 = (this->data[1] * m->data[0]) + (this->data[5] * m->data[1]) +
                 (this->data[9] * m->data[2]) + (this->data[13] * m->data[3]);

    GLfloat m2 = (this->data[2] * m->data[0]) + (this->data[6] * m->data[1]) +
                 (this->data[10] * m->data[2]) + (this->data[14] * m->data[3]);

    GLfloat m3 = (this->data[3] * m->data[0]) + (this->data[7] * m->data[1]) +
                 (this->data[11] * m->data[2]) + (this->data[15] * m->data[3]);

    GLfloat m4 = (this->data[0] * m->data[4]) + (this->data[4] * m->data[5]) +
                 (this->data[8] * m->data[6]) + (this->data[12] * m->data[7]);

    GLfloat m5 = (this->data[1] * m->data[4]) + (this->data[5] * m->data[5]) +
                 (this->data[9] * m->data[6]) + (this->data[13] * m->data[7]);

    GLfloat m6 = (this->data[2] * m->data[4]) + (this->data[6] * m->data[5]) +
                 (this->data[10] * m->data[6]) + (this->data[14] * m->data[7]);

    GLfloat m7 = (this->data[3] * m->data[4]) + (this->data[7] * m->data[5]) +
                 (this->data[11] * m->data[6]) + (this->data[15] * m->data[7]);

    GLfloat m8 = (this->data[0] * m->data[8]) + (this->data[4] * m->data[9]) +
                 (this->data[8] * m->data[10]) + (this->data[12] * m->data[11]);

    GLfloat m9 = (this->data[1] * m->data[8]) + (this->data[5] * m->data[9]) +
                 (this->data[9] * m->data[10]) + (this->data[13] * m->data[11]);

    GLfloat m10 = (this->data[2] * m->data[8]) + (this->data[6] * m->data[9]) +
                  (this->data[10] * m->data[10]) + (this->data[14] * m->data[11]);

    GLfloat m11 = (this->data[3] * m->data[8]) + (this->data[7] * m->data[9]) +
                  (this->data[11] * m->data[10]) + (this->data[15] * m->data[11]);

    GLfloat m12 = (this->data[0] * m->data[12]) + (this->data[4] * m->data[13]) +
                  (this->data[8] * m->data[14]) + (this->data[12] * m->data[15]);

    GLfloat m13 = (this->data[1] * m->data[12]) + (this->data[5] * m->data[13]) +
                  (this->data[9] * m->data[14]) + (this->data[13] * m->data[15]);

    GLfloat m14 = (this->data[2] * m->data[12]) + (this->data[6] * m->data[13]) +
                  (this->data[10] * m->data[14]) + (this->data[14] * m->data[15]);

    GLfloat m15 = (this->data[3] * m->data[12]) + (this->data[7] * m->data[13]) +
                  (this->data[11] * m->data[14]) + (this->data[15] * m->data[15]);

    rv.data[0] = m0;
    rv.data[1] = m1;
    rv.data[2] = m2;
    rv.data[3] = m3;

    rv.data[4] = m4;
    rv.data[5] = m5;
    rv.data[6] = m6;
    rv.data[7] = m7;

    rv.data[8] = m8;
    rv.data[9] = m9;
    rv.data[10] = m10;
    rv.data[11] = m11;

    rv.data[12] = m12;
    rv.data[13] = m13;
    rv.data[14] = m14;
    rv.data[15] = m15;

    return rv;
};

Vertex4D Matrix4x4::operator*(Vertex4D v) {
    Vertex4D rv;
    rv.x = (this->data[0] * v.x) + (this->data[4] * v.y) + (this->data[8] * v.z) + (this->data[12] * v.w);
    rv.y = (this->data[1] * v.x) + (this->data[5] * v.y) + (this->data[9] * v.z) + (this->data[13] * v.w);
    rv.z = (this->data[2] * v.x) + (this->data[6] * v.y) + (this->data[10] * v.z) + (this->data[14] * v.w);
    rv.w = (this->data[3] * v.x) + (this->data[7] * v.y) + (this->data[11] * v.z) + (this->data[15] * v.w);
    return rv;
};

Vertex4D Matrix4x4::operator*(Vertex4D *v) {
    Vertex4D rv;
    rv.x = (this->data[0] * v->x) + (this->data[4] * v->y) + (this->data[8] * v->z) + (this->data[12] * v->w);
    rv.y = (this->data[1] * v->x) + (this->data[5] * v->y) + (this->data[9] * v->z) + (this->data[13] * v->w);
    rv.z = (this->data[2] * v->x) + (this->data[6] * v->y) + (this->data[10] * v->z) + (this->data[14] * v->w);
    rv.w = (this->data[3] * v->x) + (this->data[7] * v->y) + (this->data[11] * v->z) + (this->data[15] * v->w);
    return rv;
};

Vertex3D Matrix4x4::operator*(Vertex3D v) {
    Vertex3D rv;
    rv.x = (this->data[0] * v.x) + (this->data[4] * v.y) + (this->data[8] * v.z) + this->data[12];
    rv.y = (this->data[1] * v.x) + (this->data[5] * v.y) + (this->data[9] * v.z) + this->data[13];
    rv.z = (this->data[2] * v.x) + (this->data[6] * v.y) + (this->data[10] * v.z) + this->data[14];
    return rv;
};

Vertex3D Matrix4x4::operator*(Vertex3D *v) {
    Vertex3D rv;
    rv.x = (this->data[0] * v->x) + (this->data[4] * v->y) + (this->data[8] * v->z) + this->data[12];
    rv.y = (this->data[1] * v->x) + (this->data[5] * v->y) + (this->data[9] * v->z) + this->data[13];
    rv.z = (this->data[2] * v->x) + (this->data[6] * v->y) + (this->data[10] * v->z) + this->data[14];
    return rv;
};

void Matrix4x4::set(int c, int r, GLfloat v) {
    this->data[c + (r * 4)] = v;
};

void Matrix4x4::identity() {
    for(int i = 0; i < 16; i++) this->data[i] = 0;
    this->data[0] = 1.0f;
    this->data[5] = 1.0f;
    this->data[10] = 1.0f;
    this->data[15] = 1.0f;

};

void Matrix4x4::createRotationFromQuaternion(GLfloat qx, GLfloat qy, GLfloat qz, GLfloat qw) {
    this->data[0] = (1.0 - (2.0 * (qy * qy)) - (2.0 * (qz * qz)));
    this->data[4] = ((2.0 * qx * qy) - (2.0 * qz * qw));
    this->data[8] = ((2.0 * qx * qz) + (2.0 * qy * qw));

    this->data[1] = ((2.0 * qx * qy) + (2.0 * qz * qw));
    this->data[5] = (1.0 - (2.0 * (qx * qx)) - (2.0 * (qz * qz)));
    this->data[9] = ((2.0 * qz * qy) - (2.0 * qx * qw));

    this->data[2] = ((2.0 * qx * qz) - (2.0 * qy * qw));
    this->data[6] = ((2.0 * qy * qz) + (2.0 * qx * qw));
    this->data[10] = (1.0 - (2.0 * (qx * qx)) - (2.0 * (qy * qy)));
};

void Matrix4x4::createRotationFromAxisAngle(GLfloat x, GLfloat y, GLfloat z, GLfloat a) {
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
    this->data[5] = (y*y*nc) + c;
    this->data[10] = (z*z*nc) + c;

    this->data[4] = (xy*nc) - zs;
    this->data[1] = (xy*nc) + zs;

    this->data[8] = (zx*nc) + ys;
    this->data[2] = (zx*nc) - ys;

    this->data[9] = (yz*nc) - xs;
    this->data[6] = (yz*nc) + xs;
};

void Matrix4x4::setRotationFromAxisAngle(GLfloat x, GLfloat y, GLfloat z, GLfloat a) {
    GLfloat lenx = abs(this->getXScale());
    GLfloat leny = abs(this->getYScale());
    GLfloat lenz = abs(this->getZScale());

    if(lenx == 0.0) lenx = 1;
    if(leny == 0.0) leny = 1;
    if(lenz == 0.0) lenz = 1;

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

    this->data[0] = ((x*x*nc) + c) * lenx;
    this->data[5] = ((y*y*nc) + c) * leny;
    this->data[10] = ((z*z*nc) + c) * lenz;

    this->data[4] = ((xy*nc) - zs) * leny;
    this->data[1] = ((xy*nc) + zs) * lenx;

    this->data[8] = ((zx*nc) + ys) * lenz;
    this->data[2] = ((zx*nc) - ys) * lenx;

    this->data[9] = ((yz*nc) - xs) * lenz;
    this->data[6] = ((yz*nc) + xs) * leny;
};

Matrix4x4 Matrix4x4::operator=(Vertex4D v) {
    this->data[0] = (1.0 - (2.0 * (v.y * v.y)) - (2.0 * (v.z * v.z)));
    this->data[4] = ((2.0 * v.x * v.y) - (2.0 * v.z * v.w));
    this->data[8] = ((2.0 * v.x * v.z) + (2.0 * v.y * v.w));

    this->data[1] = ((2.0 * v.x * v.y) + (2.0 * v.z * v.w));
    this->data[5] = (1.0 - (2.0 * (v.x * v.x)) - (2.0 * (v.z * v.z)));
    this->data[9] = ((2.0 * v.z * v.y) - (2.0 * v.x * v.w));

    this->data[2] = ((2.0 * v.x * v.z) - (2.0 * v.y * v.w));
    this->data[6] = ((2.0 * v.y * v.z) + (2.0 * v.x * v.w));
    this->data[10] = (1.0 - (2.0 * (v.x * v.x)) - (2.0 * (v.y * v.y)));
    return (*this);
};

Matrix4x4 Matrix4x4::operator=(Vertex4D *v) {
    this->data[0] = (1.0 - (2.0 * (v->y * v->y)) - (2.0 * (v->z * v->z)));
    this->data[4] = ((2.0 * v->x * v->y) - (2.0 * v->z * v->w));
    this->data[8] = ((2.0 * v->x * v->z) + (2.0 * v->y * v->w));

    this->data[1] = ((2.0 * v->x * v->y) + (2.0 * v->z * v->w));
    this->data[5] = (1.0 - (2.0 * (v->x * v->x)) - (2.0 * (v->z * v->z)));
    this->data[9] = ((2.0 * v->z * v->y) - (2.0 * v->x * v->w));

    this->data[2] = ((2.0 * v->x * v->z) - (2.0 * v->y * v->w));
    this->data[6] = ((2.0 * v->y * v->z) + (2.0 * v->x * v->w));
    this->data[10] = (1.0 - (2.0 * (v->x * v->x)) - (2.0 * (v->y * v->y)));
    return (*this);
};

void Matrix4x4::setScale(GLfloat x, GLfloat y, GLfloat z) {
    GLfloat lenx = this->getXScale();
    GLfloat leny = this->getYScale();
    GLfloat lenz = this->getZScale();

    if(lenx == 0.0) lenx = 1;
    if(leny == 0.0) leny = 1;
    if(lenz == 0.0) lenz = 1;

    this->data[0] = (this->data[0] / lenx) * x;
    this->data[1] = (this->data[1] / lenx) * x;
    this->data[2] = (this->data[2] / lenx) * x;

    this->data[4] = (this->data[4] / leny) * y;
    this->data[5] = (this->data[5] / leny) * y;
    this->data[6] = (this->data[6] / leny) * y;

    this->data[8] = (this->data[8] / lenz) * z;
    this->data[9] = (this->data[9] / lenz) * z;
    this->data[10] = (this->data[10] / lenz) * z;
};

void Matrix4x4::scaleBy(GLfloat x, GLfloat y, GLfloat z) {
    this->data[0] = this->data[0] * x;
    this->data[1] = this->data[1] * x;
    this->data[2] = this->data[2] * x;

    this->data[4] = this->data[4] * y;
    this->data[5] = this->data[5] * y;
    this->data[6] = this->data[6] * y;

    this->data[8] = this->data[8] * z;
    this->data[9] = this->data[9] * z;
    this->data[10] = this->data[10] * z;
};

void Matrix4x4::setScale(Vertex3D v) {
    GLfloat lenx = this->getXScale();
    GLfloat leny = this->getYScale();
    GLfloat lenz = this->getZScale();

    if(lenx == 0.0) lenx = 1;
    if(leny == 0.0) leny = 1;
    if(lenz == 0.0) lenz = 1;

    this->data[0] = (this->data[0] / lenx) * v.x;
    this->data[1] = (this->data[1] / lenx) * v.x;
    this->data[2] = (this->data[2] / lenx) * v.x;

    this->data[4] = (this->data[4] / leny) * v.y;
    this->data[5] = (this->data[5] / leny) * v.y;
    this->data[6] = (this->data[6] / leny) * v.y;

    this->data[8] = (this->data[8] / lenz) * v.z;
    this->data[9] = (this->data[9] / lenz) * v.z;
    this->data[10] = (this->data[10] / lenz) * v.z;
};

void Matrix4x4::scaleBy(Vertex3D v) {
    this->data[0] = this->data[0] * v.x;
    this->data[1] = this->data[1] * v.x;
    this->data[2] = this->data[2] * v.x;

    this->data[4] = this->data[4] * v.y;
    this->data[5] = this->data[5] * v.y;
    this->data[6] = this->data[6] * v.y;

    this->data[8] = this->data[8] * v.z;
    this->data[9] = this->data[9] * v.z;
    this->data[10] = this->data[10] * v.z;
};

void Matrix4x4::setXScale(GLfloat v) {
    GLfloat lenx = this->getXScale();

    if(lenx == 0.0) lenx = 1;

    this->data[0] = (this->data[0] / lenx) * v;
    this->data[1] = (this->data[1] / lenx) * v;
    this->data[2] = (this->data[2] / lenx) * v;
};

void Matrix4x4::setYScale(GLfloat v) {
    GLfloat leny = this->getYScale();

    if(leny == 0.0) leny = 1;

    this->data[4] = (this->data[4] / leny) * v;
    this->data[5] = (this->data[5] / leny) * v;
    this->data[6] = (this->data[6] / leny) * v;
};

void Matrix4x4::setZScale(GLfloat v) {
    GLfloat lenz = this->getZScale();

    if(lenz == 0.0) lenz = 1;

    this->data[8] = (this->data[8] / lenz) * v;
    this->data[9] = (this->data[9] / lenz) * v;
    this->data[10] = (this->data[10] / lenz) * v;
};

GLfloat Matrix4x4::getXScale() {
    GLfloat val = fastmath::sqrtf((this->data[0] * this->data[0]) + (this->data[1] * this->data[1]) + (this->data[2] * this->data[2]));
    //if(this->data[0] < 0.0) return -val;
    return val;
};

GLfloat Matrix4x4::getYScale() {
    GLfloat val = fastmath::sqrtf((this->data[4] * this->data[4]) + (this->data[5] * this->data[5]) + (this->data[6] * this->data[6]));
    //if(this->data[5] < 0.0) return -val;
    return val;
};

GLfloat Matrix4x4::getZScale() {
    GLfloat val = fastmath::sqrtf((this->data[8] * this->data[8]) + (this->data[9] * this->data[9]) + (this->data[10] * this->data[10]));
    //if(this->data[10] < 0.0) return -val;
    return val;
};

void Matrix4x4::perspective(GLfloat fov, GLfloat aspect, GLfloat nnear, GLfloat nfar) {
    GLfloat f = 1.0 / tan(fov * PI / 360.0);
    GLfloat rangeReciprocal = 1.0 / (nnear - nfar);

    this->data[0] = f / aspect;
    this->data[1] = 0.0;
    this->data[2] = 0.0;
    this->data[3] = 0.0;

    this->data[4] = 0.0;
    this->data[5] = f;
    this->data[6] = 0.0;
    this->data[7] = 0.0;

    this->data[8] = 0.0;
    this->data[9] = 0.0;
    this->data[10] = (nfar - nnear) * rangeReciprocal;
    this->data[11] = -1.0f;

    this->data[12] = 0.0;
    this->data[13] = 0.0;
    this->data[14] = 2.0 * nfar * nnear * rangeReciprocal;
    this->data[15] = 0.0;
};

void Matrix4x4::orthographic(GLfloat left, GLfloat right, GLfloat top, GLfloat bottom, GLfloat nnear, GLfloat nfar) {
    if(right == left) return;
    if(top == bottom) return;
    if(nfar == nnear) return;
    GLfloat r_width  = 1.0 / (right - left);
    GLfloat r_height = 1.0 / (top - bottom);
    GLfloat r_depth  = 1.0 / (nfar - nnear);
    GLfloat x =  2.0 * r_width;
    GLfloat y =  2.0 * r_height;
    GLfloat z = -2.0 * r_depth;
    GLfloat tx = -(right + left) * r_width;
    GLfloat ty = -(top + bottom) * r_height;
    GLfloat tz = -(nfar + nnear) * r_depth;
    this->data[0] = x;
    this->data[5] = y;
    this->data[10] = z;
    this->data[12] = tx;
    this->data[13] = ty;
    this->data[14] = tz;
    this->data[15] = 1.0;
    this->data[1] = 0.0;
    this->data[2] = 0.0;
    this->data[3] = 0.0;
    this->data[4] = 0.0;
    this->data[6] = 0.0;
    this->data[7] = 0.0;
    this->data[8] = 0.0;
    this->data[9] = 0.0;
    this->data[11] = 0.0;
};

void Matrix4x4::createScale(GLfloat x, GLfloat y, GLfloat z) {
    this->data[0] = x;
    this->data[1] = 0;
    this->data[2] = 0;

    this->data[4] = 0;
    this->data[5] = y;
    this->data[6] = 0;

    this->data[8] = 0;
    this->data[9] = 0;
    this->data[10] = z;
};
