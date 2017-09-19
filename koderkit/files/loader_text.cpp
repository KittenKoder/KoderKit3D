#include "loader_text.hpp"

namespace kk3d {
namespace files {

uint getFileLength(std::ifstream& file) {
    file.seekg(0,std::iostream::end);
    uint len = (uint)file.tellg();
    file.seekg(0,std::iostream::beg);

    return len;
};

uint loadshader(const char* filename, GLchar** src) {
    std::ifstream file(filename);
    if(!file.good()) return -1;
    uint len = getFileLength(file);
    if(len < 1) return len;

    (*src) = new GLchar[len+1];
    if ((*src) == NULL) return -2;

    (*src)[len] = 0;
    int i = 0;
    while (file.good())
    {
        (*src)[i] = (GLchar)file.get();
        if (!file.eof() && i < len) i++;
        else break;
    }

    (*src)[i] = 0;
    file.close();

    return len;
};

};
};
