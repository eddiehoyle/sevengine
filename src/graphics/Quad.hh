//
// Created by Eddie Hoyle on 7/10/16.
//

#ifndef SEV_RECT_HH
#define SEV_RECT_HH

#include "Vertex.hh"

struct Quad {

    Quad();

    void set( float width, float height );
    Vertex bl, br, tl, tr;
    GLfloat x, y;

};


#endif //SEV_RECT_HH
