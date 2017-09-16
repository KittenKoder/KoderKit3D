#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "../types.h"
#include <GL/gl.h>
#include "vertex.hpp"

namespace kk3d {
namespace math {

class Matrix3x3 {
public:
    GLfloat data[9];

    GLfloat operator()(int, int);
    Matrix3x3 operator=(GLfloat); // Set rotation from angle
    Matrix3x3 operator=(Matrix3x3);
    Matrix3x3 operator=(Matrix3x3 *);
    Matrix3x3 operator-=(Matrix3x3);
    Matrix3x3 operator-=(Matrix3x3 *);
    Matrix3x3 operator=(Vertex4D); // Set as rotation from Quaternion
    Matrix3x3 operator=(Vertex4D *); // Set as rotation from Quaternion
    Matrix3x3 operator/=(Matrix3x3); // Inverse of
    Matrix3x3 operator/=(Matrix3x3 *); // Inverse of
    Matrix3x3 operator*=(Matrix3x3);
    Matrix3x3 operator*=(Matrix3x3 *);

    Vertex3D operator*(Vertex3D);
    Vertex3D operator*(Vertex3D *);
    Vertex2D operator*(Vertex2D);
    Vertex2D operator*(Vertex2D *);

    Matrix3x3 operator*(Matrix3x3);
    Matrix3x3 operator*(Matrix3x3 *);

    Matrix3x3 operator-(); // Transpose

    void identity();
    GLfloat determinant();
    inline void set(int, int, GLfloat);
    void createRotationFromAxisAngle(GLfloat, GLfloat, GLfloat, GLfloat);
    void createRotationFromQuaternion(GLfloat, GLfloat, GLfloat, GLfloat);
    void setScale(GLfloat, GLfloat);
    void scaleBy(GLfloat, GLfloat);
    void setXScale(GLfloat);
    void setYScale(GLfloat);
    void setLocation(GLfloat, GLfloat);
    GLfloat getXScale();
    GLfloat getYScale();
};

class Matrix4x4 {
public:
    GLfloat data[16];

    GLfloat operator()(int, int);
    Matrix4x4 operator=(Matrix4x4);
    Matrix4x4 operator=(Matrix4x4 *);
    Matrix4x4 operator-=(Matrix4x4);
    Matrix4x4 operator-=(Matrix4x4 *);
    Matrix4x4 operator=(Vertex4D); // Set rotation from Quaternion
    Matrix4x4 operator=(Vertex4D *); // Set rotation from Quaternion
    Matrix4x4 operator/=(Matrix4x4); // Inverse of
    Matrix4x4 operator/=(Matrix4x4 *); // Inverse of
    Matrix4x4 operator*=(Matrix4x4);
    Matrix4x4 operator*=(Matrix4x4 *);
    Matrix4x4 operator*=(Matrix3x3);
    Matrix4x4 operator*=(Matrix3x3 *);

    Vertex4D operator*(Vertex4D);
    Vertex4D operator*(Vertex4D *);
    Vertex3D operator*(Vertex3D);
    Vertex3D operator*(Vertex3D *);

    Matrix4x4 operator*(Matrix4x4);
    Matrix4x4 operator*(Matrix4x4 *);

    Matrix4x4 operator-(); // Transpose

    void identity();
    void set(int, int, GLfloat);
    // void createRotationFromEuler(GLfloat, GLfloat, GLfloat);
    // void setRotationFromEuler(GLfloat, GLfloat, GLfloat);

    void createRotationFromAxisAngle(GLfloat, GLfloat, GLfloat, GLfloat);
    void setRotationFromAxisAngle(GLfloat, GLfloat, GLfloat, GLfloat);
    void createRotationFromQuaternion(GLfloat, GLfloat, GLfloat, GLfloat);
    void createScale(GLfloat, GLfloat, GLfloat);
    void setScale(GLfloat, GLfloat, GLfloat);
    void scaleBy(GLfloat, GLfloat, GLfloat);
    void setScale(Vertex3D);
    void scaleBy(Vertex3D);
    void setXScale(GLfloat);
    void setYScale(GLfloat);
    void setZScale(GLfloat);
    GLfloat getXScale();
    GLfloat getYScale();
    GLfloat getZScale();
    void perspective(GLfloat, GLfloat, GLfloat, GLfloat);
    void orthographic(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
};

};
};

#endif
