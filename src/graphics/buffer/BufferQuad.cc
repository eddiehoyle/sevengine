//
// Created by Eddie Hoyle on 28/01/17.
//

#include "BufferQuad.hh"


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
    GLuint index = ( GLuint )m_vertices.size();
    GLuint elements[6] = {
            index,     index + 1,
            index + 2, index + 2,
            index + 3, index + 1,
    };

    // Copy these arrays into vertex and element vectors
    std::copy( vertices, vertices + 4, std::back_inserter( m_vertices ) );
    std::copy( elements, elements + 6, std::back_inserter( m_elements ) );
}


void BufferQuad::bind() {

    glGenBuffers( 1, &m_vbo );
    glGenBuffers( 1, &m_vao );

    glBindBuffer( GL_ARRAY_BUFFER, m_vbo );
    glBufferData( GL_ARRAY_BUFFER, m_vertices.size() * sizeof( Vertex ), &m_vertices[0], GL_STATIC_DRAW );

    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, m_vao );
    glBufferData( GL_ELEMENT_ARRAY_BUFFER, m_elements.size() * sizeof( GLuint ), &m_elements[0], GL_STATIC_DRAW );
}


const Vertices& BufferQuad::getData() const {
    return m_vertices;
}

const Elements& BufferQuad::getElements() const {
    return m_elements;
}

void BufferQuad::clear() {

    glDeleteBuffers( 1, &m_vbo );
    glDeleteBuffers( 1, &m_vao );

    m_vertices.clear();
    m_elements.clear();
}




