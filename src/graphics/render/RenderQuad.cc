//
// Created by Eddie Hoyle on 28/01/17.
//

#include <iostream>
#include "RenderQuad.hh"

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

RenderQuad::RenderQuad()
        : m_buffer( BufferQuad() ) {
}

RenderQuad::RenderQuad( const BufferQuad& buffer )
        : m_buffer( buffer ) {
}

void RenderQuad::bind() {
    m_buffer.bind();
}

void RenderQuad::draw()
{
    // Enable alpha
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    // Draw
    const GLsizei numElements = ( GLsizei )m_buffer.getElements().size();
    glDrawElements( GL_TRIANGLES, numElements, GL_UNSIGNED_INT, 0 );
}

void RenderQuad::release() {
    // TODO
}

