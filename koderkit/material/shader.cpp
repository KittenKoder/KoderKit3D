#include "shader.hpp"

using namespace kk3d::material;

Shader::Shader() {
    this->_vert_str = NULL;
    this->_frag_str = NULL;
    this->_prog_id = 0;
};

Shader::Shader(int id) {
    this->_vert_str = NULL;
    this->_frag_str = NULL;
    this->_prog_id = 0;
    this->_id = id;
};

Shader::Shader(int id, GLchar *vstr, GLchar *fstr) {
    this->_vert_str = vstr;
    this->_frag_str = fstr;
    this->_prog_id = 0;
    this->_id = id;
};

GLchar * Shader::compile() {
    if(!this->_vert_str && !this->_frag_str) return NULL;
    GLuint tvert = glCreateShader(GL_VERTEX_SHADER);
    GLuint tfrag = glCreateShader(GL_FRAGMENT_SHADER);

    GLint result = GL_TRUE, infolen;

    if(tvert) {
        glShaderSource(tvert, 1, &this->_vert_str, NULL);
        glCompileShader(tvert);
        glGetShaderiv(tvert, GL_COMPILE_STATUS, &result);
        if(result == GL_FALSE) {
            glGetShaderiv(tvert, GL_INFO_LOG_LENGTH, &infolen);
            if(infolen > 0) {
                GLchar *tmpstr = new GLchar[infolen+1];
                glGetShaderInfoLog(tvert, infolen, NULL, &tmpstr[0]);
                tmpstr[infolen] = 0;

                glDeleteShader(tvert);

                return tmpstr;
            }
        }
    }

    if(this->_frag_str) {
        glShaderSource(tfrag, 1, &this->_frag_str, NULL);
        glCompileShader(tfrag);
        glGetShaderiv(tfrag, GL_COMPILE_STATUS, &result);
        if(result == GL_FALSE) {
            glGetShaderiv(tfrag, GL_INFO_LOG_LENGTH, &infolen);
            if(infolen > 0) {
                GLchar *tmpstr = new GLchar[infolen+1];
                glGetShaderInfoLog(tfrag, infolen, NULL, &tmpstr[0]);
                tmpstr[infolen] = 0;

                glDeleteShader(tvert);
                glDeleteShader(tfrag);

                return tmpstr;
            }
        }
    }

    if(tvert && tfrag) {
        if(!this->_prog_id) this->_prog_id = glCreateProgram();
        glAttachShader(this->_prog_id, tvert);
        glAttachShader(this->_prog_id, tfrag);
        glLinkProgram(this->_prog_id);

        glGetShaderiv(this->_prog_id, GL_COMPILE_STATUS, &result);
        if(result == GL_FALSE) {
            glGetShaderiv(this->_prog_id, GL_INFO_LOG_LENGTH, &infolen);
            if(infolen > 0) {
                GLchar *tmpstr = new GLchar[infolen+1];
                glGetShaderInfoLog(this->_prog_id, infolen, NULL, &tmpstr[0]);
                tmpstr[infolen] = 0;

                glDetachShader(this->_prog_id, tvert);
                glDetachShader(this->_prog_id, tfrag);
                glDeleteShader(tvert);
                glDeleteShader(tfrag);

                return tmpstr;
            }
        }
    }

    glDetachShader(this->_prog_id, tvert);
	glDetachShader(this->_prog_id, tfrag);
	glDeleteShader(tvert);
	glDeleteShader(tfrag);

    return NULL;
};

void Shader::setSource(GLchar *vstr, GLchar *fstr) {
    this->_vert_str = vstr;
    this->_frag_str = fstr;
};

int Shader::getID() { return this->_id; };
GLuint Shader::getProgam() { return this->_prog_id; };

void Shader::clearData() {
    if(this->_vert_str) delete(this->_vert_str);
    if(this->_frag_str) delete(this->_frag_str);
    this->_vert_str = NULL;
    this->_frag_str = NULL;
};
