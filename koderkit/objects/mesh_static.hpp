#ifndef MESH_MODEL_HPP
#define MESH_MODEL_HPP

#include "../maths/vertex.hpp"
#include "../maths/color.hpp"
#include "../types.h"
#include "../bitwise.h"
#include "mesh_base.hpp"
#include <string>

namespace kk3d {
namespace mesh {

/**
 * The basic camera object in KK3D.
 * This object contains 3D transformation and a view matrix for cameras.
 */
class MeshStatic : public MeshBase {
public:
    /**
     * The vertex class used by the model mesh. This contains the data sent to the shader for static models.
     */
    class Vertex {
    public:
        math::Vertex3D _v;                  /**< Vertex */
        math::Color4F _c;                   /**< Color */
        math::Vertex2D _uv;                 /**< Texture UV */
        math::Vertex3D _n;                  /**< Normal */
        GLfloat _m;                         /**< Material Index */
    };

protected:
    Vertex *_vert;                          /**< Vertex data of the mesh. */
    GLsizei _size,                          /**< Number of vertexes. */
            _count;                         /**< Number of indexes. */
    GLushort *_index;                       /**< Index list. */
    GLuint _buff;                           /**< Buffer object ID. */
    int _flags;                             /**< Internal flags. */

public:
    /**
     * Basic constructor.
     * No values are set, this creates a blank GL object.
     */
    MeshStatic();
    /**
     * Basic constructor setting some values.
     * The constructor sets only the ID of the mesh.
     * @param i The ID of the object.
     */
    MeshStatic(int i);
    /**
     * Basic constructor setting some values.
     * The constructor sets only the name.
     * @param n The name of the object.
     */
    MeshStatic(std::string n);
    /**
     * Basic destructor.
     * Clears the data generated by the object.
     */
    ~MeshStatic();

    void prepareVertex(int c);
    void prepareIndex(int c);
    Vertex * getVertexes();
    GLushort * getIndexes();
    GLsizei getCount();
    GLsizei getSize();
    GLuint getBufferID();
    void createBuffer();
    int getFlags();
};

};
};

#endif

