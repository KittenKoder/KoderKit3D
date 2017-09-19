#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <GL/glew.h>
#include <GL/gl.h>

namespace kk3d {
namespace math {

/**
 * The basic 2D vertex.
 * A very simple vertex object.
 */
class Vertex2D {
public:
    GLfloat x,
            y;

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
    /**
     * Find the dot product of the vertexes.
     */
    Vertex2D operator*(Vertex2D); // dot product
    /**
     * Find the cross product of the vertexes.
     */
    Vertex2D operator%(Vertex2D); // cross product

    Vertex2D operator+(Vertex2D *);
    Vertex2D operator-(Vertex2D *);
    /**
     * Find the dot product of the vertexes.
     */
    Vertex2D operator*(Vertex2D *); // dot product
    Vertex2D operator/(Vertex2D *);
    Vertex2D operator/(Vertex2D);
    /**
     * Find the cross product of the vertexes.
     */
    Vertex2D operator%(Vertex2D *); // cross product

    Vertex2D operator-();

    /**
     * Compare the length of two vertexes.
     */
    bool operator==(Vertex2D *);
    /**
     * Compare the length of two vertexes.
     */
    bool operator==(Vertex2D);
    /**
     * Compare the length of two vertexes.
     */
    bool operator<(Vertex2D *);
    /**
     * Compare the length of two vertexes.
     */
    bool operator<(Vertex2D);
    /**
     * Compare the length of two vertexes.
     */
    bool operator>(Vertex2D *);
    /**
     * Compare the length of two vertexes.
     */
    bool operator>(Vertex2D);
    /**
     * Compare the length of two vertexes.
     */
    bool operator<=(Vertex2D *);
    /**
     * Compare the length of two vertexes.
     */
    bool operator<=(Vertex2D);
    /**
     * Compare the length of two vertexes.
     */
    bool operator>=(Vertex2D *);
    /**
     * Compare the length of two vertexes.
     */
    bool operator>=(Vertex2D);

    Vertex2D();
    Vertex2D(Vertex2D *);
    Vertex2D(const Vertex2D &);

    GLfloat length();
    void lerpFast(Vertex2D v1, Vertex2D v2, GLfloat t);
    void lerpFast(Vertex2D *v1, Vertex2D *v2, GLfloat t);
    void slerpFast(Vertex2D v1, Vertex2D v2, GLfloat t);
    void slerpFast(Vertex2D *v1, Vertex2D *v2, GLfloat t);
    /**
     * Claculate bezier value.
     *
     * Uses 4 vertex values to calculate the point on a bezier curver. Results are stored in the vertex calling this.
     * @param v Array or pointer to first of four vertexes.
     * @param t The value between 0.0 and 1.0
     */
    void bezier(Vertex2D v[], GLfloat t);
    /**
     * Normalizes the vertex in place.
     */
    void normalize();
    /**
     * Get the angle of the vertex from the center of the world.
     */
    GLfloat toAngle();
    void set(GLfloat x, GLfloat y);
};

/**
 * The basic 3D vertex.
 * A very simple vertex object.
 */
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
    /**
     * Find the dot product of the vertexes.
     */
    GLfloat operator*(Vertex3D); // dot product
    Vertex3D operator/(Vertex3D);
    /**
     * Find the cross product of the vertexes.
     */
    Vertex3D operator%(Vertex3D); // cross product

    Vertex3D operator+(Vertex3D *);
    Vertex3D operator-(Vertex3D *);
    /**
     * Find the dot product of the vertexes.
     */
    GLfloat operator*(Vertex3D *); // dot product
    Vertex3D operator/(Vertex3D *);
    /**
     * Find the cross product of the vertexes.
     */
    Vertex3D operator%(Vertex3D *); // cross product

    Vertex3D operator-();

    bool operator==(Vertex3D *);
    bool operator==(Vertex3D);
    /**
     * Compare the length of two vertexes.
     */
    bool operator<(Vertex3D *);
    /**
     * Compare the length of two vertexes.
     */
    bool operator<(Vertex3D);
    /**
     * Compare the length of two vertexes.
     */
    bool operator>(Vertex3D *);
    /**
     * Compare the length of two vertexes.
     */
    bool operator>(Vertex3D);
    /**
     * Compare the length of two vertexes.
     */
    bool operator<=(Vertex3D *);
    /**
     * Compare the length of two vertexes.
     */
    bool operator<=(Vertex3D);
    /**
     * Compare the length of two vertexes.
     */
    bool operator>=(Vertex3D *);
    /**
     * Compare the length of two vertexes.
     */
    bool operator>=(Vertex3D);

    Vertex3D();
    Vertex3D(Vertex3D *);
    Vertex3D(const Vertex3D &);
    Vertex3D(GLfloat, GLfloat, GLfloat);

    GLfloat length();
    void lerpFast(Vertex3D v1, Vertex3D v2, GLfloat t);
    void lerpFast(Vertex3D *v1, Vertex3D *v2, GLfloat t);
    void slerpFast(Vertex3D v1, Vertex3D v2, GLfloat t);
    void slerpFast(Vertex3D *v1, Vertex3D *v2, GLfloat t);
    /**
     * Claculate bezier value.
     *
     * Uses 4 vertex values to calculate the point on a bezier curver. Results are stored in the vertex calling this.
     * @param v Array or pointer to first of four vertexes.
     * @param t The value between 0.0 and 1.0
     */
    void bezier(Vertex3D v[], GLfloat t);
    /**
     * Normalizes the vertex in place.
     */
    void normalize();
    /**
     * Gets the angle between vertexes.
     *
     * Retrieves the cos of the angle between the two vertexes.
     * @param v The right hand vertex.
     */
    GLfloat cosAngle(Vertex3D v);
    /**
     * Gets the angle between vertexes.
     *
     * Retrieves the cos of the angle between the two vertexes.
     * @param v The right hand vertex.
     */
    GLfloat cosAngle(Vertex3D *v);
    /**
     * Calculates a normal value.
     *
     * The vertex is filled with the normal value of the three vertexes in the array or pointer to the first.
     * @param v Array or pointer to the first of three vertexes.
     * @param cw If the polygon is clockwise.
     */
    void toNormal(Vertex3D v[], bool cw);
    /**
     * Calculates a normal value.
     *
     * The vertex is filled with the normal value of the three vertexes.
     * @param v1 Vertex 1.
     * @param v2 Vertex 2.
     * @param v3 Vertex 3.
     * @param cw If the polygon is clockwise.
     */
    void toNormal(Vertex3D *v1, Vertex3D *v2, Vertex3D *v3, bool cw);
    void set(GLfloat x, GLfloat y, GLfloat z);
};

/**
 * The basic 2D vertex.
 * Often used for quaternions.
 */
class Vertex4D {
public:
    GLfloat x, y, z, w;

    Vertex4D operator=(Vertex4D);
    Vertex4D operator=(Vertex4D *);
    /**
     * Gets the conjugate of the quaternion.
     */
    Vertex4D operator-=(Vertex4D); // Conjugate
    /**
     * Gets the conjugate of the quaternion.
     */
    Vertex4D operator-=(Vertex4D *); // Conjugate
    Vertex4D operator+=(Vertex4D);
    Vertex4D operator+=(Vertex4D *);
    /**
     * Treats the vertex as a quaternion for multiplication.
     */
    Vertex4D operator*=(Vertex4D); // Quat multiply
    /**
     * Treats the vertex as a quaternion for multiplication.
     */
    Vertex4D operator*=(Vertex4D *); // Quat multiply
    /**
     * Treats the vertex as a quaternion for multiplication.
     */
    Vertex4D operator/=(Vertex4D); // Quat conjugate multiply
    /**
     * Treats the vertex as a quaternion for multiplication.
     */
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
    /**
     * Treats the vertex as a quaternion for multiplication.
     */
    Vertex4D operator*(Vertex4D); // Quat multiply
    /**
     * Treats the vertex as a quaternion for multiplication.
     */
    Vertex4D operator/(Vertex4D); // Quat conjugate multiply
    GLfloat operator%(Vertex4D); // dot product

    Vertex4D operator+(Vertex4D *);
    Vertex4D operator-(Vertex4D *);
    /**
     * Treats the vertex as a quaternion for multiplication.
     */
    Vertex4D operator*(Vertex4D *); // Quat multiply
    /**
     * Treats the vertex as a quaternion for multiplication.
     */
    Vertex4D operator/(Vertex4D *); // Quat conjugate multiply
    /**
     * Gets the dot product of the vertexes.
     */
    GLfloat operator%(Vertex4D *); // dot product

    /**
     * The conjugate of the quaternion.
     */
    Vertex4D operator-();

    bool operator==(Vertex4D *);
    bool operator==(Vertex4D);
    /**
     * Compare the length of two vertexes.
     */
    bool operator<(Vertex4D *);
    /**
     * Compare the length of two vertexes.
     */
    bool operator<(Vertex4D);
    /**
     * Compare the length of two vertexes.
     */
    bool operator>(Vertex4D *);
    /**
     * Compare the length of two vertexes.
     */
    bool operator>(Vertex4D);
    /**
     * Compare the length of two vertexes.
     */
    bool operator<=(Vertex4D *);
    /**
     * Compare the length of two vertexes.
     */
    bool operator<=(Vertex4D);
    /**
     * Compare the length of two vertexes.
     */
    bool operator>=(Vertex4D *);
    /**
     * Compare the length of two vertexes.
     */
    bool operator>=(Vertex4D);

    Vertex4D();
    Vertex4D(Vertex4D *);
    Vertex4D(const Vertex4D &);

    GLfloat length();
    void lerpFast(Vertex4D *v1, Vertex4D *v2, GLfloat t);
    void lerpFast(Vertex4D v1, Vertex4D v2, GLfloat t);
    void slerpFast(Vertex4D *v1, Vertex4D *v2, GLfloat t);
    void slerpFast(Vertex4D v1, Vertex4D v2, GLfloat t);
    /**
     * Claculate bezier value.
     *
     * Uses 4 vertex values to calculate the point on a bezier curver. Results are stored in the vertex calling this.
     * @param v Array or pointer to first of four vertexes.
     * @param t The value between 0.0 and 1.0
     */
    void bezier(Vertex4D v[], GLfloat t);
    /**
     * Normalizes the vertex in place.
     */
    void normalize();
    /**
     * Normalizes the vertex in place ignoring the w value.
     */
    void normalizeXYZ();
    /**
     * Calculates a normal value.
     *
     * The vertex is filled with the normal value of the three vertexes in the array or pointer to the first. Ignores the w value.
     * @param v Array or pointer to the first of three vertexes.
     */
    void toNormal(Vertex4D v[]);
    /**
     * Rotates the vertex.
     *
     * Rotates a 3D vertex by the quaternion provided.
     * @param v The quaternion.
     */
    void rotateByQuaternion(Vertex4D *v);
    void set(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    void fromAxisAngle(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    void fromEuler(GLfloat x, GLfloat y, GLfloat z);
    void fromAxisAngle(Vertex4D *v);
    void fromEuler(Vertex3D *v);
};

};
};

#endif
