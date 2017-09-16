#include "camera.hpp"

using namespace kk3d::objects;

Camera3D::Camera3D() : Object3DGL() {
    this->_mat_view.identity();
    this->_type |= OBJECT_TYPE_VIEW;
};

Camera3D::Camera3D(Object *parent, int id) : Object3DGL(parent, id) {
    this->_mat_view.identity();
    this->_type |= OBJECT_TYPE_VIEW;
};

Camera3D::Camera3D(Object *parent, std::string name) : Object3DGL(parent, name) {
    this->_mat_view.identity();
    this->_type |= OBJECT_TYPE_VIEW;
};

Camera3D::~Camera3D() {};

kk3d::math::Matrix4x4 * Camera3D::getView() { return &this->_mat_view; };

void Camera3D::buildView() {
    this->_mat_view /= this->_mat_gl;
};

