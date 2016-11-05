//
// Created by Eddie Hoyle on 31/10/16.
//

#include <algorithm>
#include "RenderQuad.hh"
#include "../Buffer.hh"
#include "../../core/Shader.hh"

RenderQuad::RenderQuad()
        : m_buffer( NULL )
{
    m_buffer = new Buffer( GL_ARRAY_BUFFER );
}

RenderQuad::~RenderQuad()
{
    delete m_buffer;
}

void RenderQuad::buffer( Texture* texture, Quad* quad, Shader* shader )
{
    // Texture to be rendered
    m_texture = texture;

    // Store vertices
    //
    // Vertex buffers are filled with vertex coordinates
    // from a rect object.
    // These look like this:
    //   {{0, 0}, {1, 0}, {1, 1}, {0, 1}}
    // The element buffer indicates which vertex is to be rendered.
    // The vertex buffer is stored in clockwise order.
    m_vertices[m_vertexIndex++].set( quad->bl );
    m_vertices[m_vertexIndex++].set( quad->tl );
    m_vertices[m_vertexIndex++].set( quad->tr );
    m_vertices[m_vertexIndex++].set( quad->br );

    // Store elements
    //
    // Buffer elements
    // Elements are used to point to indices in another buffer.
    // Example element buffer:
    //   {0, 1, 2} {0, 2, 3}
    // Could point to this index buffer:
    //   {{0, 0, 0}, {1, 0, 0}, {1, 1, 0}, {0, 1, 0}}
    // This helps with re-using vertices!
    m_elements[m_elementIndex++] = m_vertexIndex;
    m_elements[m_elementIndex++] = m_vertexIndex + 1;
    m_elements[m_elementIndex++] = m_vertexIndex + 2;
    m_elements[m_elementIndex++] = m_vertexIndex + 2;
    m_elements[m_elementIndex++] = m_vertexIndex + 3;
    m_elements[m_elementIndex++] = m_vertexIndex;

    // TODO
    // Memory layout hint for the shaders vertex pointer
    // * Each vertex carries an x, y and u, v value
    // * Position and Texture data are offset by 8 bytes (sizeof(GLfloat)*2)
    // * This hint is used in
//    shader->setAttr( "in_Position", 2, GL_FLOAT, 0, BufferOffset( 0 ) );
//    shader->setAttr( "in_Texture", 2, GL_FLOAT, 0, BufferOffset( 8 );
//    shader->setAttr( "in_Color", 4, GL_UNSIGNED_BYTE, 0, BufferOffset( 16 ) );

}

void RenderQuad::draw()
{
    // Bind buffer
    m_buffer->bind();

    // Enable textures
    glEnable( GL_TEXTURE_2D );
    glActiveTexture( GL_TEXTURE0 );
    glBindTexture( GL_TEXTURE_2D, m_texture->getHandle() );


    // TODO
    // Read page 154
    // Study the order of operation and how ( const void* )offset is used
    //
    // glBindBuffer(GL_ARRAY_BUFFER, vboIds[0]);
    // glBufferData(GL_ARRAY_BUFFER, vtxStride * numVertices, vtxBuf, GL_STATIC_DRAW);
    // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboIds[1]);
    // glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLushort) * numIndices, indices, GL_STATIC_DRAW);

    // Allocate enough space for vertices;
    GLsizei size = m_vertexIndex * sizeof( Vertex );
    m_buffer->allocate( size, GL_STATIC_DRAW );

    // Fill buffer with vertices
    GLuint offset = 0;
    m_buffer->buffer( offset, size, &m_vertices );

    // Draw elements
    glDrawElements( GL_TRIANGLES, m_elementIndex, GL_UNSIGNED_SHORT, &m_elements );

    // Reset
    m_vertexIndex = 0;
    m_elementIndex = 0;

}

void RenderQuad::release()
{
    m_texture = NULL;
    m_buffer->release();
}
