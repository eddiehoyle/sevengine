//
// Created by Eddie Hoyle on 5/10/16.
//

#define GL_GLEXT_PROTOTYPES
#include <GLES2/gl2.h>
#include "Buffer.hh"
#include <stddef.h>


Buffer::Buffer()
        : m_target( 0 ),
          m_id( 0 )
{
    m_id = 0;
    m_target = GL_INVALID_ENUM;
}

Buffer::Buffer( GLenum target )
        : m_target( 0 ),
          m_id( 0 )
{
    m_id = 0;
    m_target = target;
    glGenBuffers( 1, &m_id );
}

Buffer::~Buffer()
{
    m_id = 0;
}

void Buffer::allocate( GLsizei size, GLenum usage )
{
    glBufferData( m_target, size, NULL, usage );
}

void Buffer::buffer( void* data, GLintptr offset, GLsizei size )
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

void Buffer::release()
{
    glDeleteBuffers( 1, &m_id );
}

GLuint Buffer::getID() const
{
    return m_id;
}


