//
// Created by Eddie Hoyle on 5/10/16.
//

#include "Vertex.hh"

#include <glm/glm.hpp>
#include <glm/ext.hpp>


void Vertex::set( GLfloat _x, GLfloat _y, GLfloat _s, GLfloat _t,
                  GLubyte _r, GLubyte _g, GLubyte _b, GLubyte _a )
{
    x = _x;
    y = _y;
    s = _s;
    t = GLfloat( 1.0 ) - _t; // Invert Y
    r = _r;
    g = _g;
    b = _b;
    a = _a;
}