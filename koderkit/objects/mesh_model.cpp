#include "mesh_model.hpp"

using namespace kk3d::mesh;

MeshModel::MeshModel() : MeshBase() {
    this->_vert = NULL;
    this->_index = NULL;
    this->_count = 0;
    this->_size = 0;
}

MeshModel::MeshModel(int id) : MeshBase(id) {
    this->_vert = NULL;
    this->_index = NULL;
    this->_count = 0;
    this->_size = 0;
}

MeshModel::MeshModel(std::string name) : MeshBase(name) {
    this->_vert = NULL;
    this->_index = NULL;
    this->_count = 0;
    this->_size = 0;
}

MeshModel::~MeshModel() {
    if(this->_vert) delete(this->_vert);
    if(this->_index) delete(this->_index);
};
