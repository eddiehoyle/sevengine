//
// Created by Eddie Hoyle on 31/10/16.
//

#include "RenderQuad.hh"
#include "../Buffer.hh"

RenderQuad::RenderQuad()
        : m_buffer( NULL )
{
    // TODO
}

RenderQuad::~RenderQuad()
{
    delete m_buffer;
}

void RenderQuad::allocate()
{
    // Vertex array buffer
    m_buffer = new Buffer( GL_ARRAY_BUFFER );

    // Allocate enough space for 1024 vertices
    GLsizei size = sizeof( Vertex ) * 4 * 256;
    m_buffer->allocate( size, GL_STATIC_DRAW );
}

void RenderQuad::buffer( Texture* texture, Quad* quad )
{
    // Texture to be rendered
    m_texture = texture;

    Vertex vertices[6] {
            quad->bl, quad->tl, quad->tr,
            quad->tr, quad->br, quad->bl,
    };

    /// Add a single quad (4 vertices) into the allocator buffer
    m_buffer->buffer( 0, sizeof( Vertex ), vertices );
}

void RenderQuad::draw()
{
    // Bind buffer
    m_buffer->bind();

    glEnable( GL_TEXTURE_2D );
    glActiveTexture( GL_TEXTURE0 );
    glBindTexture( GL_TEXTURE_2D, m_texture->getHandle() );

//    glDrawElements( GL_TRIANGLES, m_elementIndex, GL_UNSIGNED_SHORT, &m_elementBuffer );
}

void RenderQuad::release()
{
    m_texture = NULL;
    m_buffer->release();
}
