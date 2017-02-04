//
// Created by Eddie Hoyle on 28/01/17.
//

#ifndef SEVENGINE_RENDERSIMPLE_HH
#define SEVENGINE_RENDERSIMPLE_HH

#include "../Vertex.hh"
#include "../Quad.hh"
#include <vector>



typedef std::vector< Quad > Quads;
typedef std::vector< Vertex > Vertices;
typedef std::vector< GLuint > Elements;

class BufferQuad {

public:
    void add( const Quads& quad );
    void add( const Quad& quad );
    void bind();
    void clear();

    const Vertices& getData() const;
    const Elements& getElements() const;

private:
    Vertices m_data;
    Elements m_elements;

    GLuint m_vbo;
    GLuint m_vao;
};

class RenderQuad {

public:

    RenderQuad();
    explicit RenderQuad( const BufferQuad& buffer );

    void bind();
    void draw();
    void release();

private:
    BufferQuad m_buffer;
};


#endif //SEVENGINE_RENDERSIMPLE_HH
