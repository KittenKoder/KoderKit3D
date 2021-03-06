#ifndef OBJECT_3D_HPP
#define OBJECT_3D_HPP

#include "../maths/matrix.hpp"
#include "../types.h"
#include "../bitwise.h"
#include "object.hpp"
#include <string>

namespace kk3d {
namespace objects {

/**
 * The secondary object in KK3D.
 * This object contains 3D transformation data for the objects. Most rendered objects will be derived from this.
 */
class Object3D : public Object {
protected:
    kk3d::math::Matrix4x4 _mat_transform,               /**< The complete transformation matrix. */
         _mat_locscale;                                 /**< The location and scale matrix. */
    kk3d::math::Matrix3x3 _mat_rotation;                /**< The rotation portion of the matrix. */
public:
    /**
     * Basic constructor.
     * No values are set, this creates a blank GL object.
     */
    Object3D();
    /**
     * Basic constructor setting some values.
     * The constructor sets only the parent and ID of the object.
     * @param p The parent object of this object.
     * @param i The ID of the object.
     */
    Object3D(kk3d::Object *p, int i);
    /**
     * Basic constructor setting some values.
     * The constructor sets only the parent object and the name.
     * @param p The parent object of this object.
     * @param n The name of the object.
     */
    Object3D(kk3d::Object *p, std::string n);
    /**
     * Basic destructor.
     * Clears the data generated by the object.
     */
    ~Object3D();

    /**
     * Get the rotation information.
     * The rotation matrix contains only the rotation of the object. When combined with the other
     * matrix it is multiplied by the scale values. This is how you set the rotation.
     * @return The pointer to the rotation matrix.
     */
    kk3d::math::Matrix3x3 * getRotation();
    /**
     * Get the location and scale matrix.
     * This matrix contains scale in the upper three rows and columns and translation in the right most
     * upper three points. This matrix can be used to set the skew values as well.
     * @return The pointer to the location and scale matrix.
     */
    kk3d::math::Matrix4x4 * getLocationScale();
    /**
     * Combine the transformation matrixes.
     * Calling this will combine the rotation matrix with the scale and location matrix.
     */
    virtual void buildMatrix();
    /**
     * Get the completed matrix.
     * This matrix contains all the transformation information after calling buildMatrix(). Can be modified
     * prior to rendoring if desired.
     * @return The pointer to the transformation matrix.
     */
    kk3d::math::Matrix4x4 * getTransforms();
};

}
}

#endif // OBJECT_3D_HPP

