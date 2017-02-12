//
// Created by Eddie Hoyle on 7/02/17.
//

#include "RenderParticle.hh"

#define GL_GLEXT_PROTOTYPES
#include <GLES2/gl2.h>
#include <iostream>


void Particle::setPosition( const glm::vec2& vec ) {

    point.x = vec.x;
    point.y = vec.y;
}

void Particle::setSize( GLfloat size ) {

    point.size = size;
}

void Particle::setColor( GLchar r, GLchar g, GLchar b, GLchar a ) {

    point.r = r;
    point.g = g;
    point.b = b;
    point.a = a;
}

// ----------------------------------------------------------------------

void BufferParticle::add( const Particles& particles ) {

    for ( Particles::const_iterator iter = particles.begin();
          iter != particles.end();
          iter++ ) {
        add( *iter );
    }
}

void BufferParticle::add( const Particle& particle ) {

    m_data.push_back( particle.point );
    m_elements.push_back( ( GLuint )( m_data.size() - 1 ) );
}

void BufferParticle::bind() {

    glGenBuffers( 1, &m_vbo );
    glGenBuffers( 1, &m_vao );

    glBindBuffer( GL_ARRAY_BUFFER, m_vbo );
    glBufferData( GL_ARRAY_BUFFER, m_data.size() * sizeof( Point ), &m_data[0], GL_STATIC_DRAW );

    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, m_vao );
    glBufferData( GL_ELEMENT_ARRAY_BUFFER, m_elements.size() * sizeof( GLuint ), &m_elements[0], GL_STATIC_DRAW );
}

void BufferParticle::clear() {

    glBindBuffer( GL_ARRAY_BUFFER, 0 );
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0 );

    glDeleteBuffers( 1, &m_vbo );
    glDeleteBuffers( 1, &m_vao );

    m_data.clear();
    m_elements.clear();
}

const Points& BufferParticle::getData() const {
    return m_data;
}

const Elements& BufferParticle::getElements() const {
    return m_elements;
}

// ----------------------------------------------------------------------

RenderParticle::RenderParticle()
        : m_buffer() {
}

RenderParticle::RenderParticle( const BufferParticle& buffer )
        : m_buffer( buffer ) {
}

void RenderParticle::bind() {
    m_buffer.bind();


    // Enable point size to be set within vertex shader
    // to 'gl_PointSize' unique var
    // https://forums.khronos.org/showthread.php/5984-gl_PointSize-problem?p=19252&viewfull=1#post19252
    glEnable( 0x8642 );
}

void RenderParticle::draw() {

    // Enable alpha
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    // Draw
    const GLsizei numElements = ( GLsizei )m_buffer.getElements().size();
    glDrawElements( GL_POINTS, numElements, GL_UNSIGNED_INT, 0 );
}

void RenderParticle::release() {

    // Disable point size
    glDisable( 0x8642 );
}






