//
// Created by Eddie Hoyle on 5/10/16.
//

#include "Vertex.hh"

#include <glm/glm.hpp>
#include <glm/ext.hpp>

Vertex::Vertex()
{
    set( 0, 0, 0, 0, 0, 0, 0, 0 );
}

void Vertex::set( GLfloat _x, GLfloat _y, GLfloat _s, GLfloat _t,
                  GLubyte _r, GLubyte _g, GLubyte _b, GLubyte _a )
{
    x = _x;
    y = _y;
    s = _s;
    t = _t;
    r = _r;
    g = _g;
    b = _b;
    a = _a;
}