
#include "object_3d_flat.hpp"

using namespace kk3d::objects;

Object3DFlat::Object3DFlat() : Object() {
    this->_mesh = NULL;
    this->_type |= OBJECT_TYPE_MESH_FLAT;
};

Object3DFlat::Object3DFlat(Object *parent, int id) : Object(parent, id) {
    this->_mesh = NULL;
    this->_type |= OBJECT_TYPE_MESH_FLAT;
};

Object3DFlat::Object3DFlat(Object *parent, std::string name) : Object(parent, name) {
    this->_mesh = NULL;
    this->_type |= OBJECT_TYPE_MESH_FLAT;
};

Object3DFlat::~Object3DFlat() {};
void Object3DFlat::setMesh(mesh::MeshFlat *m) { this->_mesh = m; };
kk3d::mesh::MeshFlat * Object3DFlat::getMesh() { return this->_mesh; };

