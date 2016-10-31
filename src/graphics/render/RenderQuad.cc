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

    // TODO
    // This needs to be larger, I'm only allocating enough memory
    // for a single quad (6 vertices) which is silly.
    GLsizei size = sizeof( Vertex ) * 4;
    m_buffer->allocate( size, GL_STATIC_DRAW );
}

void RenderQuad::buffer( Texture* texture, Quad* quad )
{

    Vertex vertices[6] {
            quad->bl, quad->tl, quad->tr,
            quad->tr, quad->br, quad->bl,
    };

    /// Add a single quad (6 vertices) into the allocator buffer
    m_buffer->buffer( vertices, 0, sizeof( Vertex ) );
}

void RenderQuad::draw()
{
    m_buffer->bind();
}

void RenderQuad::release()
{

}
