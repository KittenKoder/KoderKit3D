#include "object_3d_gl.hpp"

using namespace kk3d::objects;

Object3DGL::Object3DGL() : Object3D() {
    this->_mat_gl.identity();
    this->_type |= OBJECT_TYPE_GLMATRIX;
};

Object3DGL::Object3DGL(Object *parent, int id) : Object3D(parent, id) {
    this->_mat_gl.identity();
    this->_type |= OBJECT_TYPE_GLMATRIX;
};

Object3DGL::Object3DGL(Object *parent, std::string name) : Object3D(parent, name) {
    this->_mat_gl.identity();
    this->_type |= OBJECT_TYPE_GLMATRIX;
};

Object3DGL::~Object3DGL() {};

kk3d::math::Matrix4x4 * Object3DGL::getGLMatrix() { return &this->_mat_gl; };

void Object3DGL::buildGLMatrix() {
    Object *tp = this->_parent;
    this->_mat_gl = this->_mat_transform;
    while(tp)
    {
        if((tp->getTypeFlags() & OBJECT_TYPE_TRANSFORMS))
            this->_mat_transform = (*((Object3D*)tp)->getTransforms()) * this->_mat_gl;
        tp = tp->getParent();
    }
};


