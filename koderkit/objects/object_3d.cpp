#include "object_3d.hpp"

using namespace kk3d::objects;

Object3D::Object3D() : Object() {
    this->_mat_transform.identity();
    this->_mat_rotation.identity();
    this->_mat_locscale.identity();
    this->_type |= OBJECT_TYPE_TRANSFORMS;
};

Object3D::Object3D(Object *parent, int id) : Object(parent, id) {
    this->_mat_transform.identity();
    this->_mat_rotation.identity();
    this->_mat_locscale.identity();
    this->_type |= OBJECT_TYPE_TRANSFORMS;
};

Object3D::Object3D(Object *parent, std::string name) : Object(parent, name) {
    this->_mat_transform.identity();
    this->_mat_rotation.identity();
    this->_mat_locscale.identity();
    this->_type |= OBJECT_TYPE_TRANSFORMS;
};

Object3D::~Object3D() {};

kk3d::math::Matrix3x3 * Object3D::getRotation() {
    return &this->_mat_rotation;
};
kk3d::math::Matrix4x4 * Object3D::getLocationScale() {
    return &this->_mat_locscale;
};
kk3d::math::Matrix4x4 * Object3D::getTransforms() {
    return &this->_mat_transform;
};

void Object3D::buildMatrix() {
    this->_mat_transform = this->_mat_locscale;
    this->_mat_transform *= this->_mat_rotation;
};
