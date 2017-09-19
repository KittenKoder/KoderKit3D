#ifndef OBJECT_FLAT_HPP
#define OBJECT_FLAT_HPP

#include "../types.h"
#include "../bitwise.h"
#include "object.hpp"
#include "mesh_flat.hpp"
#include <string>

namespace kk3d {
namespace objects {

/**
 * The object holding flat meshes in KK3D.
 *
 */
class Object3DFlat : public Object {
protected:
    mesh::MeshFlat *_mesh;                              /**< The mesh contained in the object. */
    // Texture

public:
    /**
     * Basic constructor.
     * No values are set, this creates a blank GL object.
     */
    Object3DFlat();
    /**
     * Basic constructor setting some values.
     * The constructor sets only the parent and ID of the object.
     * @param p The parent object of this object.
     * @param i The ID of the object.
     */
    Object3DFlat(Object *p, int i);
    /**
     * Basic constructor setting some values.
     * The constructor sets only the parent object and the name.
     * @param p The parent object of this object.
     * @param n The name of the object.
     */
    Object3DFlat(Object *p, std::string n);
    /**
     * Basic destructor. Clears the data generated by the object.
     */
    ~Object3DFlat();

    void setMesh(mesh::MeshFlat *m);
    mesh::MeshFlat * getMesh();
};

}
}
#endif // OBJECT_3D_HPP

