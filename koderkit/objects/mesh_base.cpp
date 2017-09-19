#include "mesh_base.hpp"

using namespace kk3d::mesh;

MeshBase::MeshBase()
{
    this->_name = NULL;
    this->_type = 0;
}

MeshBase::MeshBase(int id)
{
    this->_name = NULL;
    this->_id = id;
}

MeshBase::MeshBase(std::string name)
{
    this->_name = new std::string(name);
    this->_type = 0;
}

MeshBase::~MeshBase()
{
    if(this->_name) delete(this->_name);
};

void MeshBase::setName(std::string name)
{
    if(this->_name) this->_name->assign(name);
    else this->_name = new std::string(name);
};

std::string *MeshBase::getName() { return this->_name; };
uint MeshBase::getTypeFlags() { return this->_type; };
void MeshBase::setID(int i) {this->_id = i; };
int MeshBase::getID() { return this->_id; };
