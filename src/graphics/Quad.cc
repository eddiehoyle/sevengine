//
// Created by Eddie Hoyle on 7/10/16.
//

#include "Quad.hh"

Quad::Quad( const int width, const int height )
        : m_translates( glm::vec2( 0.0f ) ),
          m_rotates( 0.0f ),
          m_scales( glm::vec2( 0.0f ) )
{
    m_translates = glm::vec2( 0.0f );
    m_rotates = 0.0f;
    m_scales = glm::vec2( 0.0f );

    bl.set( 0.0f, 0.0f, 0.0f, 0.0f );
    br.set( width, 0.0f, 1, 0.0f );
    tl.set( 0.0f, height, 0.0f, 1 );
    tr.set( width, height, 1, 1 );
}

void Quad::setTranslate( const glm::vec2& vec )
{
    m_translates = vec;

    bl.x += vec.x;
    bl.y += vec.y;

    br.x += vec.x;
    br.y += vec.y;

    tl.x += vec.x;
    tl.y += vec.y;

    tr.x += vec.x;
    tr.y += vec.y;
}

//void Quad::set( float width, float height )
//{
//    // Starts from bottom left.
//    //
//    // tl(0,1)---tr(1,1)
//    //   |         |
//    //   |         |
//    //   |         |
//    // bl(0,0)---br(1,0)
//
//    bl.set( 0.0f, 0.0f, 0.0f, 0.0f );
//    br.set( width, 0.0f, 1, 0.0f );
//    tl.set( 0.0f, height, 0.0f, 1 );
//    tr.set( width, height, 1, 1 );
//};
