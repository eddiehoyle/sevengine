//
// Created by Eddie Hoyle on 31/10/16.
//

#include <algorithm>
#include "RenderRect.hh"
#include "../Buffer.hh"
#include "../../core/Shader.hh"
#include "../../Utilities.hh"

RenderRect::RenderRect( Shader* shader, Texture* texture )
        : m_buffer( NULL ),
          m_texture( NULL ),
          m_vertexIndex( 0 ),
          m_elementIndex( 0 ),
          m_vertices( 0 ),
          m_elements( 0 )
{
//    m_buffer = new Buffer( GL_ARRAY_BUFFER );

    m_shader = shader;
    m_texture = texture;

    // Reserve vertex and element buffers
    m_vertices.reserve( kVboSize );
    m_elements.reserve( kVboSize );
}

RenderRect::~RenderRect()
{

    delete m_buffer;
}

void RenderRect::buffer( const Quad& quad )
{
    // Vertex array for this quad
    Vertex vertices[4] = {
            quad.bl, quad.tl,
            quad.br, quad.tr,
    };

    // Element array for this quad
//    GLuint index = ( GLuint )m_vertices.size() + ( ( GLuint )m_vertices.size() / 2 );
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

void RenderRect::draw()
{
    // -------------------------------------------------------------------------------------
//    std::vector< GLuint >::iterator eIter;
//    std::cerr << "Elements: ";
//    for ( eIter = m_elements.begin(); eIter != m_elements.end(); eIter++ ) {
//        std::cerr << *eIter << ", ";
//    }
//    std::cerr << std::endl;
//
//    std::vector< Vertex >::iterator vIter;
//    std::cerr << "Vertices: ";
//    for ( vIter = m_vertices.begin(); vIter != m_vertices.end(); vIter++ ) {
//        Vertex v = *vIter;
//        std::cerr << "((" << vIter->x << ", " << vIter->y << "), "
//                  << "(" << vIter->u << ", " << vIter->v << ")), ";
//    }
//    std::cerr << std::endl;

//    std::cerr << "Vertices length and size: " << m_vertices.size() << ", " << sizeof(Vertex) * m_vertices.size() << std::endl;
//    std::cerr << "Vertex size: " << sizeof( struct Vertex) << std::endl;
    // -------------------------------------------------------------------------------------


    GLuint vbo, ebo;
    glGenBuffers( 1, &vbo );
    glGenBuffers( 1, &ebo );

    glBindBuffer( GL_ARRAY_BUFFER, vbo );
    glBufferData( GL_ARRAY_BUFFER, m_vertices.size() * sizeof( Vertex ), &m_vertices[0], GL_STATIC_DRAW );

    GLuint stride = sizeof( Vertex );
    glVertexAttribPointer( m_shader->getAttrHandle( "in_Position" ), 2, GL_FLOAT, GL_FALSE, stride, ( void * ) + 0 );
    glEnableVertexAttribArray( m_shader->getAttrHandle( "in_Position" ) );

    glVertexAttribPointer( m_shader->getAttrHandle( "in_TextureUV" ), 2, GL_FLOAT, GL_FALSE, stride, ( void * ) + 2 );
    glEnableVertexAttribArray( m_shader->getAttrHandle( "in_TextureUV" ) );

    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, ebo );
    glBufferData( GL_ELEMENT_ARRAY_BUFFER, m_elements.size() * sizeof( GLuint ), &m_elements[0], GL_STATIC_DRAW );

    checkError();

    glEnable( GL_TEXTURE_2D );
    glActiveTexture( GL_TEXTURE0 );
//    m_shader->setUnif( "uf_Texture", 0 );

//    glBindBuffer( GL_ARRAY_BUFFER, 0 );
//    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0 );



//    glEnableVertexAttribArray( m_shader->getAttrHandle( "in_Texture" ) );
//    glEnableVertexAttribArray( m_shader->getAttrHandle( "in_Color" ) );

//    m_shader->enableAttr( "in_Position" );
//    m_shader->enableAttr( "in_Texture" );
//    m_shader->enableAttr( "in_Color" );

//    m_shader->setAttrOffset( "in_Position", 2, GL_FLOAT, false, 0, 0 );
//    m_shader->setAttrOffset( "in_Texture", 2, GL_FLOAT, false, 0, 8 );
//    m_shader->setAttrOffset( "in_Color", 4, GL_UNSIGNED_BYTE, false, 0, 16 );

    glDrawElements( GL_TRIANGLES, ( GLsizei )m_elements.size(), GL_UNSIGNED_INT, 0 );

    glDeleteBuffers( 1, &vbo );
    glDeleteBuffers( 1, &ebo );
    Texture::unbind( m_texture );

    m_vertices.clear();
    m_elements.clear();
}

void RenderRect::release()
{
    // TODO
    printf( "RenderRect::release()\n" );
}