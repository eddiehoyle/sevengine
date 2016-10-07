//
// Created by Eddie Hoyle on 7/10/16.
//

#ifndef SEV_RECT_HH
#define SEV_RECT_HH

#include "Vertex.hh"

struct Rect {

    Rect();

    void set( float x, float y, float u, float v );
    Vertex bl, br, tl, tr;

};


#endif //SEV_RECT_HH
