//
// Created by Eddie Hoyle on 28/01/17.
//

#ifndef SEVENGINE_RENDERSIMPLE_HH
#define SEVENGINE_RENDERSIMPLE_HH

#include "../Vertex.hh"
#include <vector>

struct Quad {

    explicit Quad( float width, float height );

    void setMatrix( const glm::mat4& matrix );
    void setUV( float sa, float sb, float ta, float tb );
    void setColor( GLubyte r, GLubyte g, GLubyte b, GLubyte a );

    Vertex bl, br, tl, tr;

private:

    // TODO
    void* m_transform;

    glm::vec2 m_translates;
    double m_rotates;
    glm::vec2 m_scales;
};

typedef std::vector< Quad > Quads;
typedef std::vector< Vertex > Vertices;
typedef std::vector< GLuint > Elements;

class QuadBuffer {

public:
    QuadBuffer();
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

class QuadRender {

public:

    QuadRender();
    explicit QuadRender( const QuadBuffer& buffer );

    void bind();
    void draw();
    void release();

private:
    QuadBuffer m_buffer;
};

void print( const Vertex& vertex );


#endif //SEVENGINE_RENDERSIMPLE_HH
