#ifndef OBJECT_3D_GL_HPP
#define OBJECT_3D_GL_HPP

#include "../maths/matrix.hpp"
#include "../types.h"
#include "../bitwise.h"
#include "object_3d.hpp"
#include <string>

namespace kk3d {
namespace objects {

/**
 * \brief The container that holds OpenGL matrix.
 * Contains the GL matrix on top of the tranformation matrixes.
 */
class Object3DGL : public Object3D {
protected:
    kk3d::math::Matrix4x4 _mat_gl;

public:
    /**
     * \brief Basic constructor.
     * No values are set, this creates a blank GL object.
     */
    Object3DGL();
    /**
     * \brief Basic constructor setting some values.
     * The constructor sets only the parent and ID of the object.
     * @param p The parent object of this object.
     * @param i The ID of the object.
     */
    Object3DGL(kk3d::Object *p, int i);
    /**
     * \brief Basic constructor setting some values.
     * The constructor sets only the parent object and the name.
     * @param p The parent object of this object.
     * @param n The name of the object.
     */
    Object3DGL(kk3d::Object *p, std::string n);
    /**
     * \brief Basic destructor.
     * Clears the data generated by the object.
     */
    ~Object3DGL();

    /**
     * \brief Setup the OpenGL matrix.
     * The GL matrix is derived from the transformation matrix and all parent transformations. This method
     * sets the GL matrix from all transformations.
     */
    void buildGLMatrix();
    /**
     * \brief Get the pointer to the OpenGL matrix.
     * The OpenGL matrix is used to render the objects. This can be modified before the rendering pass as desired.
     * @return The pointer to the OpenGL matrix.
     */
    kk3d::math::Matrix4x4 * getGLMatrix();
};

}
}

#endif // OBJECT_3D_HPP


