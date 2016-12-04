//
// Created by Eddie Hoyle on 7/10/16.
//

#include "Quad.hh"

#include <glm/gtx/matrix_decompose.hpp>
#include <iostream>

Quad::Quad( float width, float height )
        : m_transform( NULL ),
          m_translates( glm::vec2( 0.0f ) ),
          m_rotates( 0.0f ),
          m_scales( glm::vec2( 0.0f ) )
{
    m_translates = glm::vec2( 0.0f );
    m_rotates = 0.0f;
    m_scales = glm::vec2( 0.0f );

    GLubyte r, g, b, a;
    r = 255;
    g = 255;
    b = 255;
    a = 255;

    bl.set( 0.0f, 0.0f, 0.0f, 0.0f, r, g, b, a );
    br.set( width, 0.0f, 1, 0.0f, r, g, b, a );
    tl.set( 0.0f, height, 0.0f, 1, r, g, b, a );
    tr.set( width, height, 1, 1, r, g, b, a );
}
void Quad::setMatrix( const glm::mat4& matrix )
{
    glm::vec4 posA( bl.x, bl.y, 0.0, 1.0 );
    glm::vec4 posB( br.x, br.y, 0.0, 1.0 );
    glm::vec4 posC( tl.x, tl.y, 0.0, 1.0 );
    glm::vec4 posD( tr.x, tr.y, 0.0, 1.0 );

    posA = matrix * posA;
    posB = matrix * posB;
    posC = matrix * posC;
    posD = matrix * posD;

    bl.x = posA.x;
    bl.y = posA.y;

    br.x = posB.x;
    br.y = posB.y;

    tl.x = posC.x;
    tl.y = posC.y;

    tr.x = posD.x;
    tr.y = posD.y;
}

void Quad::setUV( float sa, float sb, float ta, float tb )
{
    bl.s = sa;
    bl.t = ta;

    br.s = sb;
    br.t = ta;

    tl.s = sa;
    tl.t = tb;

    tr.s = sb;
    tr.t = tb;
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
