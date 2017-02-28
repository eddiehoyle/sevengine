//
// Created by Eddie Hoyle on 22/02/17.
//

#include <cmath>
#include "LineRender.hh"

#include <glm/gtx/matrix_decompose.hpp>

#include <glm/glm.hpp>
#include <glm/ext.hpp>

void print( const Line& line ) {

    std::cerr << "Line(begin=("
    << line.begin.x << ", " << line.begin.y << "), end=("
    << line.end.x << ", " << line.end.y << "), width="
    << line.width << ")" << std::endl;
}

void LineBuffer::add( const Lines& lines ) {
    Lines::const_iterator iter;
    for ( iter = lines.begin(); iter != lines.end(); iter++ ) {
        add( *iter );
    }
}

void LineBuffer::add( const Line& line ) {

    // Line vectors
    const glm::vec2 begin = glm::vec2( line.begin.x, line.begin.y );
    const glm::vec2 end = glm::vec2( line.end.x, line.end.y );
    const glm::vec2 direction = end - begin;
    const glm::vec2 normal = glm::normalize( glm::vec2( -direction.y, direction.x ) );

    // Expand to quad
    float half = line.width / 2.0f;
    glm::vec2 beginA, beginB, endA, endB;
    beginA = begin - half * normal;
    beginB = begin + half * normal;
    endA = end - half * normal;
    endB = end + half * normal;

    // Construct vertices
    Vertex beginVertexA, beginVertexB, endVertexA, endVertexB;
    beginVertexA.set( beginA.x, beginA.y, 0.0f, 0.0f, line.begin.r, line.begin.g, line.begin.b, line.begin.a );
    beginVertexB.set( beginB.x, beginB.y, 0.0f, 0.0f, line.begin.r, line.begin.g, line.begin.b, line.begin.a );
    endVertexA.set( endA.x, endA.y, 0.0f, 0.0f, line.end.r, line.end.g, line.end.b, line.end.a );
    endVertexB.set( endB.x, endB.y, 0.0f, 0.0f, line.end.r, line.end.g, line.end.b, line.end.a );

    // Vertex array
    Vertex vertices[4] = {
            beginVertexA, beginVertexB,
            endVertexA, endVertexB,
    };

//    print( beginVertexA );
//    print( beginVertexB );
//    print( endVertexA );
//    print( endVertexB );
//    std::cerr << std::endl;

    // Element array
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

void LineBuffer::bind() {

    glGenBuffers( 1, &m_vbo );
    glGenBuffers( 1, &m_vao );

    glBindBuffer( GL_ARRAY_BUFFER, m_vbo );
    glBufferData( GL_ARRAY_BUFFER, m_data.size() * sizeof( Vertex ), &m_data[0], GL_STATIC_DRAW );

    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, m_vao );
    glBufferData( GL_ELEMENT_ARRAY_BUFFER, m_elements.size() * sizeof( GLuint ), &m_elements[0], GL_STATIC_DRAW );
}

void LineBuffer::clear() {

    glBindBuffer( GL_ARRAY_BUFFER, 0 );
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0 );

    glDeleteBuffers( 1, &m_vbo );
    glDeleteBuffers( 1, &m_vao );

    m_data.clear();
    m_elements.clear();
}

const Vertices& LineBuffer::getData() const {
    return m_data;
}

const Elements& LineBuffer::getElements() const {
    return m_elements;
}

// --------------------------------------------------------


LineRender::LineRender()
        : m_buffer() {
}

LineRender::LineRender( const LineBuffer& buffer )
        : m_buffer( buffer ) {
}

void LineRender::bind() {
    m_buffer.bind();
}

void LineRender::draw() {

//    // Enable alpha
//    glEnable( GL_BLEND );
//    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    // Draw
    const GLsizei numElements = ( GLsizei )m_buffer.getElements().size();
    glDrawElements( GL_TRIANGLES, numElements, GL_UNSIGNED_INT, 0 );
}

void LineRender::release() {

}

