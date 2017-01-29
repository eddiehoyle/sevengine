//
// Created by Eddie Hoyle on 28/01/17.
//

#ifndef SEVENGINE_BUFFER_HH
#define SEVENGINE_BUFFER_HH

#include "../Vertex.hh"
#include "../Quad.hh"

#include <vector>

#define GL_GLEXT_PROTOTYPES
#include <GLES2/gl2.h>

typedef std::vector< Quad > Quads;
typedef std::vector< Vertex > Vertices;
typedef std::vector< GLuint > Elements;

class BufferQuad {

public:
    void add( const Quad& quad );
    void add( const std::vector< Quad >& quads );

    const Vertices& getData() const;
    const Elements& getElements() const;

    void bind();
    void clear();

private:
    Vertices m_vertices;
    Elements m_elements;

    GLuint m_vbo;
    GLuint m_vao;
};



#endif //SEVENGINE_BUFFER_HH
