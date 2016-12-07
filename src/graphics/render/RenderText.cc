//
// Created by Eddie Hoyle on 31/10/16.
//

#include <algorithm>
#include "RenderText.hh"
#include "../Buffer.hh"
#include "../../core/Shader.hh"
#include "../../Utilities.hh"

RenderText::RenderText( Shader* shader )
        : m_buffer( NULL ),
          m_vertexIndex( 0 ),
          m_elementIndex( 0 ),
          m_vertices( 0 ),
          m_elements( 0 )
{
    m_shader = shader;

    // Reserve vertex and element buffers
    m_vertices.reserve( kVboSize );
    m_elements.reserve( kVboSize );
}

RenderText::~RenderText()
{
    delete m_buffer;
}

void RenderText::buffer( const Quad& quad )
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

void RenderText::allocate()
{
    glGenBuffers( 1, &m_vbo );
    glGenBuffers( 1, &m_vao );

    glBindBuffer( GL_ARRAY_BUFFER, m_vbo );
    glBufferData( GL_ARRAY_BUFFER, m_vertices.size() * sizeof( Vertex ), &m_vertices[0], GL_STATIC_DRAW );

    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, m_vao );
    glBufferData( GL_ELEMENT_ARRAY_BUFFER, m_elements.size() * sizeof( GLuint ), &m_elements[0], GL_STATIC_DRAW );

    // Setup attributes
    m_shader->bindAttr( 0, "in_Position" );
    m_shader->bindAttr( 1, "in_TextureUV" );
    m_shader->bindAttr( 2, "in_Color" );

    GLsizei stride = sizeof( Vertex );
    m_shader->setAttrOffset( "in_Position", 2, GL_FLOAT, false, stride, 0 );
    m_shader->setAttrOffset( "in_TextureUV", 2, GL_FLOAT, false, stride, 8 );
    m_shader->setAttrOffset( "in_Color", 4, GL_UNSIGNED_BYTE, true, stride, 16 );

    m_shader->enableAttr( "in_Position" );
    m_shader->enableAttr( "in_TextureUV" );
    m_shader->enableAttr( "in_Color" );
}

void RenderText::draw()
{
    // Enable alpha
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    // Draw
    glDrawElements( GL_TRIANGLES, ( GLsizei )m_elements.size(), GL_UNSIGNED_INT, 0 );
}

void RenderText::release()
{
    glBindBuffer( GL_ARRAY_BUFFER, 0 );
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0 );

    glDeleteBuffers( 1, &m_vbo );
    glDeleteBuffers( 1, &m_vao );

    m_vertices.clear();
    m_elements.clear();
}