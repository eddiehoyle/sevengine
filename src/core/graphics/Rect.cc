//
// Created by Eddie Hoyle on 7/10/16.
//

#include "Rect.hh"

Rect::Rect()
    : bl(),
      br(),
      tl(),
      tr()
{
    set( 0.0f, 0.0f, 0.0f, 0.0f );
}

void Rect::set( float x, float y, float u, float v )
{
    bl.set( 0.0f, 0.0f, 0.0f, 0.0f );
    br.set( x, 0.0f, u, 0.0f );
    tl.set( 0.0f, y, 0.0f, v );
    tr.set( x, y, u, v );
};