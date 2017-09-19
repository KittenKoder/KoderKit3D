
#include "object_3d_mesh.hpp"

using namespace kk3d::objects;

Object3DMesh::Object3DMesh() : Object3DGL() {
    this->_mat_normal.identity();
    this->_mesh = NULL;
    this->_type |= OBJECT_TYPE_MESH;
};

Object3DMesh::Object3DMesh(Object *parent, int id) : Object3DGL(parent, id) {
    this->_mat_normal.identity();
    this->_mesh = NULL;
    this->_type |= OBJECT_TYPE_MESH;
};

Object3DMesh::Object3DMesh(Object *parent, std::string name) : Object3DGL(parent, name) {
    this->_mat_normal.identity();
    this->_mesh = NULL;
    this->_type |= OBJECT_TYPE_MESH;
};

Object3DMesh::~Object3DMesh() {};

void Object3DMesh::buildGLMatrix() {
    Object3DGL::buildGLMatrix();

    static math::Matrix4x4 tmat;
    tmat /= this->_mat_gl;

    this->_mat_normal.data[0] = tmat.data[0];
    this->_mat_normal.data[1] = tmat.data[4];
    this->_mat_normal.data[2] = tmat.data[8];

    this->_mat_normal.data[3] = tmat.data[1];
    this->_mat_normal.data[4] = tmat.data[5];
    this->_mat_normal.data[5] = tmat.data[9];

    this->_mat_normal.data[6] = tmat.data[2];
    this->_mat_normal.data[7] = tmat.data[6];
    this->_mat_normal.data[8] = tmat.data[10];
};
