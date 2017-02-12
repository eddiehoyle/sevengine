//
// Created by Eddie Hoyle on 28/01/17.
//

#include <iostream>
#include "QuadRender.hh"


Quad::Quad( float width, float height ) {

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
    bl.t = GLfloat( 1.0 ) - ta; // Invert Y

    br.s = sb;
    br.t = GLfloat( 1.0 ) - ta; // Invert Y

    tl.s = sa;
    tl.t = GLfloat( 1.0 ) - tb; // Invert Y

    tr.s = sb;
    tr.t = GLfloat( 1.0 ) - tb; // Invert Y
}

void Quad::setColor( GLubyte r, GLubyte g, GLubyte b, GLubyte a ) {

    bl.r = r;
    bl.g = g;
    bl.b = b;
    bl.a = a;

    br.r = r;
    br.g = g;
    br.b = b;
    br.a = a;

    tl.r = r;
    tl.g = g;
    tl.b = b;
    tl.a = a;

    tr.r = r;
    tr.g = g;
    tr.b = b;
    tr.a = a;
}

// ----------------------------------------------------------------------

void BufferQuad::add( const std::vector< Quad >& quads ) {
    std::vector< Quad >::const_iterator iter;
    for ( iter = quads.begin(); iter != quads.end(); iter++ ) {
        add( *iter );
    }
}

void BufferQuad::add( const Quad &quad ) {

    // Vertex array for this quad
    Vertex vertices[4] = {
            quad.bl, quad.tl,
            quad.br, quad.tr,
    };

    // Element array for this quad
    GLuint index = ( GLuint )m_data.size();
    GLuint elements[6] = {
            index,     index + 1,
            index + 2, index + 2,
            index + 3, index + 1,
    };

    // Copy these arrays into vertex and element vectors
    std::copy( vertices, vertices + 4, std::back_inserter( m_data ) );
    std::copy( elements, elements + 6, std::back_inserter( m_elements ) );
}


void BufferQuad::bind() {

    glGenBuffers( 1, &m_vbo );
    glGenBuffers( 1, &m_vao );

    glBindBuffer( GL_ARRAY_BUFFER, m_vbo );
    glBufferData( GL_ARRAY_BUFFER, m_data.size() * sizeof( Vertex ), &m_data[0], GL_STATIC_DRAW );

    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, m_vao );
    glBufferData( GL_ELEMENT_ARRAY_BUFFER, m_elements.size() * sizeof( GLuint ), &m_elements[0], GL_STATIC_DRAW );
}

void BufferQuad::clear() {

    glBindBuffer( GL_ARRAY_BUFFER, 0 );
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0 );

    glDeleteBuffers( 1, &m_vbo );
    glDeleteBuffers( 1, &m_vao );

    m_data.clear();
    m_elements.clear();
}

const Vertices& BufferQuad::getData() const {
    return m_data;
}

const Elements& BufferQuad::getElements() const {
    return m_elements;
}

// ---------------------------------------------------------------------- //

QuadRender::QuadRender()
        : m_buffer() {
}

QuadRender::QuadRender( const BufferQuad& buffer )
        : m_buffer( buffer ) {
}

void QuadRender::bind() {
    m_buffer.bind();
}

void QuadRender::draw()
{
    // Enable alpha
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    // Draw
    const GLsizei numElements = ( GLsizei )m_buffer.getElements().size();
    glDrawElements( GL_TRIANGLES, numElements, GL_UNSIGNED_INT, 0 );
}

void QuadRender::release() {
    // TODO
}

