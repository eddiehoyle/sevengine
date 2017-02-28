//
// Created by Eddie Hoyle on 22/02/17.
//

#ifndef SEVENGINE_LINERENDER_HH
#define SEVENGINE_LINERENDER_HH

#define GL_GLEXT_PROTOTYPES
#include <GLES2/gl2.h>

#include <glm/glm.hpp>
#include <vector>
#include <iostream>
#include "QuadRender.hh"


struct Line;

typedef std::vector< Line > Lines;
typedef std::vector< GLuint > Elements;

struct Line {

    void set( const glm::vec2& _begin, const glm::vec2& _end,
              GLubyte _r, GLubyte _g, GLubyte _b, GLubyte _a,
              GLfloat _width ) {

        begin.set( _begin.x, _begin.y, 0.0f, 0.0f,
                   _r, _g, _b, _a );
        end.set( _end.x, _end.y, 0.0f, 0.0f,
                   _r, _g, _b, _a );
        width = _width;

    }
    Vertex begin, end;
    GLfloat width;
};

class LineBuffer {

public:
    void add( const Line& line );
    void add( const Lines& lines );
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

class LineRender {

public:

    LineRender();
    explicit LineRender( const LineBuffer& buffer );

    void bind();
    void draw();
    void release();

private:
    LineBuffer m_buffer;
};

void print( const Line& line );

#endif //SEVENGINE_LINERENDER_HH
