#include "mesh_flat.hpp"

using namespace kk3d::mesh;

MeshFlat::MeshFlat() : MeshBase() {
    this->_vert = NULL;
    this->_index = NULL;
    this->_count = 0;
    this->_size = 0;
    this->_buff = 0;
    this->_flags = 0;
}

MeshFlat::MeshFlat(int id) : MeshBase(id) {
    this->_vert = NULL;
    this->_index = NULL;
    this->_count = 0;
    this->_size = 0;
    this->_buff = 0;
    this->_flags = 0;
}

MeshFlat::MeshFlat(std::string name) : MeshBase(name) {
    this->_vert = NULL;
    this->_index = NULL;
    this->_count = 0;
    this->_size = 0;
    this->_buff = 0;
    this->_flags = 0;
}

MeshFlat::~MeshFlat() {
    if(this->_vert) delete(this->_vert);
    if(this->_index) delete(this->_index);
};

void MeshFlat::prepareVertex(int c) {
    if(this->_vert) delete(this->_vert);
    if((this->_flags & INFLAG_UPLOADED)) this->_flags |= INFLAG_REPLACED;
    this->_vert = new MeshFlat::Vertex[c];
    this->_size = c;
};

void MeshFlat::prepareIndex(int c) {
    if(this->_index) delete(this->_index);
    this->_index = new GLushort[c];
    this->_count = c;
};

MeshFlat::Vertex * MeshFlat::getVertexes() { return this->_vert; };
GLushort * MeshFlat::getIndexes() { return this->_index; };
GLsizei MeshFlat::getCount() { return this->_count; };
GLsizei MeshFlat::getSize() { return this->_size; };
GLuint MeshFlat::getBufferID() { return ((this->_flags & INFLAG_REPLACED) ? 0 : this->_buff); };
int MeshFlat::getFlags() { return this->_flags; };

void MeshFlat::createBuffer() {
    if(!this->_vert) return;
    if((this->_flags & INFLAG_UPLOADED) && (this->_flags & INFLAG_REPLACED)) {
        glDeleteBuffers(1, &this->_buff);
        this->_buff = 0;
    }
    glGenBuffers(1, &this->_buff);
    glBindBuffer(GL_ARRAY_BUFFER, this->_buff);
    glBufferData(GL_ARRAY_BUFFER, this->_size * sizeof(Vertex), this->_vert, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    this->_flags |= INFLAG_UPLOADED;
    BITWISE_CLEAR(this->_flags, INFLAG_REPLACED);
};

void MeshFlat::clearData() {
    if(this->_vert) delete(this->_vert);
    this->_vert = NULL;
};
