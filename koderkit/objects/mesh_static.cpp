#include "mesh_static.hpp"

using namespace kk3d::mesh;

MeshStatic::MeshStatic() : MeshBase() {
    this->_vert = NULL;
    this->_index = NULL;
    this->_count = 0;
    this->_size = 0;
    this->_buff = 0;
    this->_flags = 0;
}

MeshStatic::MeshStatic(int id) : MeshBase(id) {
    this->_vert = NULL;
    this->_index = NULL;
    this->_count = 0;
    this->_size = 0;
    this->_buff = 0;
    this->_flags = 0;
}

MeshStatic::MeshStatic(std::string name) : MeshBase(name) {
    this->_vert = NULL;
    this->_index = NULL;
    this->_count = 0;
    this->_size = 0;
    this->_buff = 0;
    this->_flags = 0;
}

MeshStatic::~MeshStatic() {
    if(this->_vert) delete(this->_vert);
    if(this->_index) delete(this->_index);
};

void MeshStatic::prepareVertex(int c) {
    if(this->_vert) delete(this->_vert);
    if((this->_flags & INFLAG_UPLOADED)) this->_flags |= INFLAG_REPLACED;
    this->_vert = new MeshStatic::Vertex[c];
    this->_size = c;
};

void MeshStatic::prepareIndex(int c) {
    if(this->_index) delete(this->_index);
    this->_index = new GLushort[c];
    this->_count = c;
};

MeshStatic::Vertex * MeshStatic::getVertexes() { return this->_vert; };
GLushort * MeshStatic::getIndexes() { return this->_index; };
GLsizei MeshStatic::getCount() { return this->_count; };
GLsizei MeshStatic::getSize() { return this->_size; };
GLuint MeshStatic::getBufferID() { return ((this->_flags & INFLAG_REPLACED) ? 0 : this->_buff); };
int MeshStatic::getFlags() { return this->_flags; };

void MeshStatic::createBuffer() {
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
