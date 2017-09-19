
#ifndef SHADER_HPP
#define SHADER_HPP

#include "../types.h"
#include "../bitwise.h"
#include <GL/glew.h>
#include <GL/gl.h>
#include <string>

namespace kk3d {
namespace material {

class Shader {
protected:
    int _id;                            /**< The object ID. */
    GLuint _prog_id;                    /**< Program ID. */
    GLchar *_vert_str,                  /**< Vertex shader string. */
    *_frag_str;                         /**< Fragment shader string. */

public:
    /**
     * Basic constructor. Creates an empty container for a shader program.
     */
    Shader();
    /**
     * Basic constructor. Creates an empty container for a shader program setting the ID of the program.
     * @param id The identification value of the shader.
     */
    Shader(int id);
    /**
     * Constructor setting the source strings. Sets the source code for the shaders used in the program.
     * @param id The ID of the shader.
     * @param vstr The vertex shader source.
     * @param fstr The fragment shader source.
     */
    Shader(int id, GLchar *vstr, GLchar *fstr);

    /**
     * Compile the shader program. Call only within an opengl context.
     * @return Error string or NULL if no error.
     */
    GLchar * compile();
    /**
     * Set the shader sources.
     * @param vstr The vertex shader source.
     * @param fstr The fragment shader source.
     */
    void setSource(GLchar *vstr, GLchar *fstr);
    /**
     * Retrieve the ID set for the shader object.
     * @return The ID value set.
     */
    int getID();
    /**
     * Retrieve the OpenGL id of the progam.
     */
    GLuint getProgam();
    /**
     * Clears the strings set. This deletes the pointers of the source codes set.
     */
    void clearData();
};

};
};

#endif
