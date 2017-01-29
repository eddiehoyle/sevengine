//
// Created by Eddie Hoyle on 31/10/16.
//

#include <algorithm>
#include "RenderRect.hh"
#include "../Buffer.hh"
#include "../../Utilities.hh"

#include "../shader/ShaderManager.hh"

RenderRect::RenderRect()
        : m_vertexIndex( 0 ),
          m_elementIndex( 0 ),
          m_vertices( 0 ),
          m_elements( 0 ),
          m_vbo( 0 ),
          m_vao( 0 ) {

    // Reserve vertex and element buffers
    m_vertices.reserve( kVboSize );
    m_elements.reserve( kVboSize );
}

RenderRect::~RenderRect() {
}

void RenderRect::buffer( const Quad& quad )
{
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

void RenderRect::bind()
{
    glGenBuffers( 1, &m_vbo );
    glGenBuffers( 1, &m_vao );

    /*
     * See page 154 in GLES book
     * When a GL_ARRAY_BUFFER buffer object is used,
     * the pointer argument in glVertexAttribPointer
     * changes from being a pointer to the actual data
     * to being an offset in bytes into the vertex buffer
     * store allocated using glBufferData.
     *
     * This means this buffer() function needs to be called first,
     * then followed by glVertexAttribPointer() to set attribute
     * pointer and offsets
     */

    glBindBuffer( GL_ARRAY_BUFFER, m_vbo );
    glBufferData( GL_ARRAY_BUFFER, m_vertices.size() * sizeof( Vertex ), &m_vertices[0], GL_STATIC_DRAW );

    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, m_vao );
    glBufferData( GL_ELEMENT_ARRAY_BUFFER, m_elements.size() * sizeof( GLuint ), &m_elements[0], GL_STATIC_DRAW );

    /*
     * TODO
     * The shader needs to have its vertex attribute defined and enabled here
     * Should I link the renderer to the shader? Use a shader manager to track
     * and get active in use shader? I like the putting buffer(), enable() and
     * disable() shader to avoid complication.
     */

    ShaderManager::instance()->enable();

}

void RenderRect::draw()
{
    // Enable alpha
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    // Draw
    glDrawElements( GL_TRIANGLES, ( GLsizei )m_elements.size(), GL_UNSIGNED_INT, 0 );
}

void RenderRect::release()
{
    glBindBuffer( GL_ARRAY_BUFFER, 0 );
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0 );

    ShaderManager::instance()->disable();
    ShaderManager::instance()->release();

    glDeleteBuffers( 1, &m_vbo );
    glDeleteBuffers( 1, &m_vao );

    m_vertices.clear();
    m_elements.clear();
}