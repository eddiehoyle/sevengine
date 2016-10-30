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
    // Starts from bottom left.
    //
    // tl(0,1)---tr(1,1)
    //   |         |
    //   |         |
    //   |         |
    // bl(0,0)---br(1,0)

    bl.set( 0.0f, 0.0f, 0.0f, 0.0f );
    br.set( x, 0.0f, u, 0.0f );
    tl.set( 0.0f, y, 0.0f, v );
    tr.set( x, y, u, v );
};