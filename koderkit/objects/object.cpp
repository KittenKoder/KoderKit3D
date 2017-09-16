#include "object.hpp"

using namespace kk3d;

Object::Object()
{
    this->_parent = NULL;
    this->_name = NULL;
    this->_type = 0;
}

Object::Object(Object *par, int id)
{
    this->_parent = par;
    this->_name = NULL;
    this->_type = 0;
    this->_id = id;
}

Object::Object(Object *par, std::string name)
{
    this->_parent = par;
    this->_name = new std::string(name);
    this->_type = 0;
}

Object::~Object()
{
    if(this->_name) delete(this->_name);
};

void Object::setParent(Object *p)
{
    if(p != this) this->_parent = p;
    else this->_parent = NULL;
};

Object *Object::getParent() { return this->_parent; };

void Object::setFlags(uint f)
{
    BITWISE_SET(this->_flags, f);
};

void Object::clearFlags(uint f)
{
    BITWISE_CLEAR(this->_flags, f);
};

uint Object::getFlags() { return this->_flags; };

void Object::setName(std::string name)
{
    if(this->_name) this->_name->assign(name);
    else this->_name = new std::string(name);
};

std::string *Object::getName() { return this->_name; };
uint Object::getTypeFlags() { return this->_type; };
void Object::setID(int i) {this->_id = i; };
int Object::getID() { return this->_id; };
