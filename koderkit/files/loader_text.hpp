#ifndef LOADER_TEXT_HPP
#define LOADER_TEXT_HPP

#include "../types.h"
#include "../bitwise.h"
#include <GL/glew.h>
#include <GL/gl.h>
#include <iostream>
#include <fstream>
#include <string>

namespace kk3d {
namespace files {

uint getFileLength(std::ifstream& file);
uint loadshader(const char* filename, GLchar** src);

};
};

#endif
