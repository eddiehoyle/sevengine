//
// Created by Eddie Hoyle on 5/10/16.
//

#include <OpenGLES/ES2/gl.h>
#include "Buffer.hh"
#include <stddef.h>

void Buffer::create( GLenum target )
{
    m_target = target;
    glGenBuffers( 1, &m_id );
}

void Buffer::allocate( GLsizei size, GLenum usage )
{
    glBufferData( m_target, size, NULL, usage );
}

void Buffer::buffer( void *data, GLintptr offset, GLsizei size )
{
    glBufferSubData( m_target, offset, size, data );
}

void Buffer::bind()
{
    glBindBuffer( m_target, m_id );
}

void Buffer::unbind()
{
    glBindBuffer( m_target, 0 );
}

void Buffer::destroy()
{
    glDeleteBuffers( 1, &m_id );
}

