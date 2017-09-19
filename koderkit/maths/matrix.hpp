#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "../types.h"
#include <GL/glew.h>
#include <GL/gl.h>
#include "vertex.hpp"

namespace kk3d {
namespace math {

/**
 * A 3x3 matrix in OpenGL order.
 * The matrix is designed to be compatible with OpenGL shaders. Just send it as it is. This matrix can be a
 * 2D transformation or a 3D rotation only matrix.
 */
class Matrix3x3 {
public:
    GLfloat data[9];                            /**< The values of the matrix. */

    /**
     * Retrieve one value from the matrix.
     * A shorthand method to retrieve one value.
     * @param c Column index.
     * @param r Row index.
     */
    GLfloat operator()(int c, int r);
    /**
     * Sets the 2D matrix rotation angle.
     * Sets the upper 2x2 values to match the radian angle provided.
     */
    Matrix3x3 operator=(GLfloat); // Set rotation from angle
    /**
     * Copies a matrix.
     * Copies the values from one matrix to the other.
     */
    Matrix3x3 operator=(Matrix3x3);
    /**
     * Copies a matrix.
     * Copies the values from one matrix to the other.
     */
    Matrix3x3 operator=(Matrix3x3 *);
    /**
     * Copies the transposed matrix.
     * Copies the values from one matrix to the other transposed.
     */
    Matrix3x3 operator-=(Matrix3x3);
    /**
     * Copies the transposed matrix.
     * Copies the values from one matrix to the other transposed.
     */
    Matrix3x3 operator-=(Matrix3x3 *);
    /**
     * Creates a 3D rotation from a quaternion.
     * Treats the vertex as a quaternion and transforms this matrix into a 3D rotation only matrix from that vertex.
     */
    Matrix3x3 operator=(Vertex4D); // Set as rotation from Quaternion
    /**
     * Creates a 3D rotation from a quaternion.
     * Treats the vertex as a quaternion and transforms this matrix into a 3D rotation only matrix from that vertex.
     */
    Matrix3x3 operator=(Vertex4D *); // Set as rotation from Quaternion
    /**
     * Copies the inverse.
     * Sets the values of the matrix to the inverse of another matrix. Both matrixes can be the same matrix.
     */
    Matrix3x3 operator/=(Matrix3x3); // Inverse of
    /**
     * Copies the inverse.
     * Sets the values of the matrix to the inverse of another matrix. Both matrixes can be the same matrix.
     */
    Matrix3x3 operator/=(Matrix3x3 *); // Inverse of
    /**
     * Multiply.
     * Multiplies the matrixes.
     */
    Matrix3x3 operator*=(Matrix3x3);
    /**
     * Multiply.
     * Multiplies the matrixes.
     */
    Matrix3x3 operator*=(Matrix3x3 *);

    /**
     * Multiply.
     * Multiplies the vertex by this matrix. Provides the w value in the z member.
     */
    Vertex3D operator*(Vertex3D);
    /**
     * Multiply.
     * Multiplies the vertex by this matrix. Provides the w value in the z member.
     */
    Vertex3D operator*(Vertex3D *);
    /**
     * Multiply.
     * Multiplies the vertex by this matrix.
     */
    Vertex2D operator*(Vertex2D);
    /**
     * Multiply.
     * Multiplies the vertex by this matrix.
     */
    Vertex2D operator*(Vertex2D *);

    /**
     * Multiply.
     * Multiplies the matrixes.
     */
    Matrix3x3 operator*(Matrix3x3);
    /**
     * Multiply.
     * Multiplies the matrixes.
     */
    Matrix3x3 operator*(Matrix3x3 *);

    /**
     * Transpose in place.
     * Transposes the matrix in place.
     */
    Matrix3x3 operator-(); // Transpose

    /**
     * Clears the matrix.
     * Sets the matrix to it's identity.
     */
    void identity();
    /**
     * Get the determinant.
     * Get the determinant.
     * @return The determinant of the matrix.
     */
    GLfloat determinant();
    /**
     * Set a value.
     * Sets the value of the matrix.
     * @param c Column.
     * @param r Row.
     * @param v Value.
     */
    inline void set(int c, int r, GLfloat v);
    /**
     * Create a rotation matrix from axis angle information.
     * Creates a 3D rotation only matrix from an axis angle.
     * @param x X
     * @param y Y
     * @param z Z
     * @param a Angle in radians.
     */
    void createRotationFromAxisAngle(GLfloat x, GLfloat y, GLfloat z, GLfloat a);
    /**
     * Create a rotation matrix from a quaternion.
     * Creates a 3D rotation only matrix from a quaternion.
     * @param x X
     * @param y Y
     * @param z Z
     * @param w W
     */
    void createRotationFromQuaternion(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    /**
     * Sets the scale values.
     * Sets a non-uniform scale value for a 2D matrix.
     * @param x X
     * @param y Y
     */
    void setScale(GLfloat x, GLfloat y);
    /**
     * Scales by.
     * Scales the matrix rotation portion by a non-uniform value for a 2D matrix.
     * @param x X
     * @param y Y
     */
    void scaleBy(GLfloat x, GLfloat y);
    /**
     * Sets the x scale values.
     * Sets the x scale value for a 2D matrix.
     * @param s Scale value.
     */
    void setXScale(GLfloat s);
    /**
     * Sets the y scale values.
     * Sets the y scale value for a 2D matrix.
     * @param s Scale value.
     */
    void setYScale(GLfloat s);
    /**
     * Sets the location.
     * Sets the location values for a 2D matrix.
     * @param x X
     * @param y Y
     */
    void setLocation(GLfloat x, GLfloat y);
    /**
     * Retrieves the scale value.
     * Retrieves the scale value of a 2D matrix.
     * @return The scale value for the x axis.
     */
    GLfloat getXScale();
    /**
     * Retrieves the scale value.
     * Retrieves the scale value of a 2D matrix.
     * @return The scale value for the y axis.
     */
    GLfloat getYScale();
};

/**
 * A 4x4 matrix in OpenGL order.
 * The matrix is designed to be compatible with OpenGL shaders. Just send it as it is.
 */
class Matrix4x4 {
public:
    GLfloat data[16];                           /**< The values of the matrix. */

    /**
     * Retrieve one value from the matrix.
     * A shorthand method to retrieve one value.
     * @param c Column index.
     * @param r Row index.
     */
    GLfloat operator()(int c, int r);
    /**
     * Copies a matrix.
     * Copies the values from one matrix to the other.
     */
    Matrix4x4 operator=(Matrix4x4);
    /**
     * Copies a matrix.
     * Copies the values from one matrix to the other.
     */
    Matrix4x4 operator=(Matrix4x4 *);
    /**
     * Copies the transposed matrix.
     * Copies the values from one matrix to the other transposed.
     */
    Matrix4x4 operator-=(Matrix4x4);
    /**
     * Copies the transposed matrix.
     * Copies the values from one matrix to the other transposed.
     */
    Matrix4x4 operator-=(Matrix4x4 *);
    /**
     * Sets the rotation from a quaternion.
     * Sets the rotation from a quaternion leaving all other values alone.
     */
    Matrix4x4 operator=(Vertex4D); // Set rotation from Quaternion
    /**
     * Sets the rotation from a quaternion.
     * Sets the rotation from a quaternion leaving all other values alone.
     */
    Matrix4x4 operator=(Vertex4D *); // Set rotation from Quaternion
    /**
     * Copies the inverse.
     * Sets the values of the matrix to the inverse of another matrix. Both matrixes can be the same matrix.
     */
    Matrix4x4 operator/=(Matrix4x4); // Inverse of
    /**
     * Copies the inverse.
     * Sets the values of the matrix to the inverse of another matrix. Both matrixes can be the same matrix.
     */
    Matrix4x4 operator/=(Matrix4x4 *); // Inverse of
    /**
     * Multiply.
     * Multiplies the matrixes.
     */
    Matrix4x4 operator*=(Matrix4x4);
    /**
     * Multiply.
     * Multiplies the matrixes.
     */
    Matrix4x4 operator*=(Matrix4x4 *);
    /**
     * Multiply.
     * Multiplies the matrixes using the 3x3 as a rotation only.
     */
    Matrix4x4 operator*=(Matrix3x3);
    /**
     * Multiply.
     * Multiplies the matrixes using the 3x3 as a rotation only.
     */
    Matrix4x4 operator*=(Matrix3x3 *);

    /**
     * Multiply.
     * Multiplies the vertex by this matrix.
     */
    Vertex4D operator*(Vertex4D);
    /**
     * Multiply.
     * Multiplies the vertex by this matrix.
     */
    Vertex4D operator*(Vertex4D *);
    /**
     * Multiply.
     * Multiplies the vertex by this matrix.
     */
    Vertex3D operator*(Vertex3D);
    /**
     * Multiply.
     * Multiplies the vertex by this matrix.
     */
    Vertex3D operator*(Vertex3D *);

    /**
     * Multiply.
     * Multiplies the matrixes.
     */
    Matrix4x4 operator*(Matrix4x4);
    /**
     * Multiply.
     * Multiplies the matrixes.
     */
    Matrix4x4 operator*(Matrix4x4 *);

    /**
     * Transpose in place.
     * Transposes the matrix in place.
     */
    Matrix4x4 operator-(); // Transpose

    /**
     * Clears the matrix.
     * Sets the matrix to it's identity.
     */
    void identity();
    /**
     * Set a value.
     * Sets the value of the matrix.
     * @param c Column.
     * @param r Row.
     * @param v Value.
     */
    void set(int c, int r, GLfloat v);
    // void createRotationFromEuler(GLfloat, GLfloat, GLfloat);
    // void setRotationFromEuler(GLfloat, GLfloat, GLfloat);

    /**
     * Create a rotation matrix from axis angle information.
     * Sets the rotation values clearing any scale information.
     * @param x X
     * @param y Y
     * @param z Z
     * @param a Angle in radians.
     */
    void createRotationFromAxisAngle(GLfloat x, GLfloat y, GLfloat z, GLfloat a);
    /**
     * Create a rotation matrix from axis angle information.
     * Fills the rotation portion of the matric while leaving the rest of the matrix alone.
     * @param x X
     * @param y Y
     * @param z Z
     * @param a Angle in radians.
     */
    void setRotationFromAxisAngle(GLfloat x, GLfloat y, GLfloat z, GLfloat a);
    /**
     * Create a rotation matrix from a quaternion.
     * Sets the rotation values clearing any scale information.
     * @param x X
     * @param y Y
     * @param z Z
     * @param w W
     */
    void createRotationFromQuaternion(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    /**
     * Sets the scale values.
     * This clears all rotation information and previous scale values.
     * @param x X
     * @param y Y
     * @param z Z
     */
    void createScale(GLfloat x, GLfloat y, GLfloat z);
    /**
     * Sets the scale values.
     * Rotation values are preserved.
     * @param x X
     * @param y Y
     * @param z Z
     */
    void setScale(GLfloat x, GLfloat y, GLfloat z);
    /**
     * Sets the scale values.
     * Rotation values are preserved and the previous scale values are added.
     * @param x X
     * @param y Y
     * @param z Z
     */
    void scaleBy(GLfloat x, GLfloat y, GLfloat z);
    /**
     * Sets the scale values.
     * Rotation values are preserved.
     * @param v Vertex holding the xyz values.
     */
    void setScale(Vertex3D v);
    /**
     * Sets the scale values.
     * Rotation values are preserved and previous scale values are added.
     * @param v Vertex holding the xyz values.
     */
    void scaleBy(Vertex3D v);
    /**
     * Sets the scale value.
     * Rotation values are preserved.
     * @param v X
     */
    void setXScale(GLfloat v);
    /**
     * Sets the scale value.
     * Rotation values are preserved.
     * @param v Y
     */
    void setYScale(GLfloat v);
    /**
     * Sets the scale value.
     * Rotation values are preserved.
     * @param v Z
     */
    void setZScale(GLfloat v);
    /**
     * Gets the scale value.
     * Retrieves the scale value for X.
     * @return Value
     */
    GLfloat getXScale();
    /**
     * Gets the scale value.
     * Retrieves the scale value for Y.
     * @return Value
     */
    GLfloat getYScale();
    /**
     * Gets the scale value.
     * Retrieves the scale value for Z.
     * @return Value
     */
    GLfloat getZScale();
    /**
     * Create perspective matrix.
     * Creates a projection matrix for perspective rendering.
     * @param fov Field of View.
     * @param aspect Aspect ratio.
     * @param nnear Near plane.
     * @param nfar Far plane.
     */
    void perspective(GLfloat fov, GLfloat aspect, GLfloat nnear, GLfloat nfar);
    /**
     * Create perspective matrix.
     * Creates a projection matrix for perspective rendering.
     * @param left Left plane.
     * @param right Right plane.
     * @param top Top plane.
     * @param bottom Bottom plane.
     * @param nnear Near plane.
     * @param nfar Far plane.
     */
    void orthographic(GLfloat left, GLfloat right, GLfloat top, GLfloat bottom, GLfloat nnear, GLfloat nfar);
};

};
};

#endif
