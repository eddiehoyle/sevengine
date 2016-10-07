//
// Created by Eddie Hoyle on 7/10/16.
//

#include "Quad.hh"

Quad::Quad()
    : bl(),
      br(),
      tl(),
      tr()
{
    set( 0.0f, 0.0f, 0.0f, 0.0f );
}

void Quad::set( float x, float y, float u, float v )
{
    bl.set( 0.0f, 0.0f, 0.0f, 0.0f );
    br.set( x, 0.0f, u, 0.0f );
    tl.set( 0.0f, y, 0.0f, v );
    tr.set( x, y, u, v );
};