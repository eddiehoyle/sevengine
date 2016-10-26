//
// Created by Eddie Hoyle on 5/10/16.
//

#include "RenderQuad.hh"


RenderQuad::RenderQuad()
        : AbstractRender()
{
    m_type = kQuad;
}

RenderQuad::~RenderQuad()
{
    // TODO
}

void RenderQuad::begin()
{
    m_buffer->bind();
}

void RenderQuad::render( Texture* texture, Quad* rect )
{
    // Active texture
    m_texture = texture;

    // Buffer elements
    // Elements are used to point to indices in another buffer.
    // Example element buffer:
    //   {0, 1, 2} {0, 2, 3}
    // Could point to this index buffer:
    //   {{0, 0, 0}, {1, 0, 0}, {1, 1, 0}, {0, 1, 0}}
    // This helps with re-using vertices!
    m_elementBuffer[m_elementIndex++] = ( GLushort )( m_vertexIndex );
    m_elementBuffer[m_elementIndex++] = ( GLushort )( m_vertexIndex + 1 );
    m_elementBuffer[m_elementIndex++] = ( GLushort )( m_vertexIndex + 2 );
    m_elementBuffer[m_elementIndex++] = ( GLushort )( m_vertexIndex + 2 );
    m_elementBuffer[m_elementIndex++] = ( GLushort )( m_vertexIndex + 3 );
    m_elementBuffer[m_elementIndex++] = ( GLushort )( m_vertexIndex );

    // Vertex buffers are filled with vertex coordinates
    // from a rect object.
    // These look like this:
    //   {{0, 0}, {1, 0}, {1, 1}, {0, 1}}
    // The element buffer indicates which vertex is to be rendered.
    // The vertex buffer is stored in clockwise order.
    m_vertexBuffer[m_vertexIndex++].set( rect->bl );
    m_vertexBuffer[m_vertexIndex++].set( rect->tl );
    m_vertexBuffer[m_vertexIndex++].set( rect->tr );
    m_vertexBuffer[m_vertexIndex++].set( rect->br );

}

void RenderQuad::end()
{
    glBindTexture( GL_TEXTURE_2D, 0 );
}

void RenderQuad::release()
{
    m_buffer->release();
}

void RenderQuad::flush()
{
    glEnable( GL_TEXTURE_2D );
    glActiveTexture( GL_TEXTURE0 );
    glBindTexture( GL_TEXTURE_2D, m_texture->getHandle() );

    GLuint size = m_vertexIndex * sizeof( Vertex );
    m_buffer->allocate( size, GL_STREAM_DRAW );
    m_buffer->buffer( &m_vertexBuffer, 0, size );
    glDrawElements( GL_TRIANGLES, m_elementIndex, GL_UNSIGNED_SHORT, &m_elementBuffer );

    m_vertexIndex = 0;
    m_elementIndex = 0;
}

