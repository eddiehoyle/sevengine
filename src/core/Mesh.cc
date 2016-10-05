//
// Created by Eddie Hoyle on 8/09/16.
//

#include "Mesh.hh"


Mesh::Mesh()
        : m_bbox( NULL ),
          m_vertexes( Vertexes() )
{
    // TODO
}

Mesh::Mesh( const Vertexes& vertexes )
        : m_bbox( NULL ),
          m_vertexes( vertexes )
{
    m_vertexes = vertexes;
    m_bbox = new BoundingBox( m_vertexes );
}

Mesh::Mesh( GLfloat* numbers, std::size_t size )
        : m_bbox( NULL ),
          m_vertexes( Vertexes() )
{
    m_vertexes = toVertexes( numbers, size );
    m_bbox = new BoundingBox( m_vertexes );
}

Mesh::Mesh( const FlattenedVertexes& vertexes )
        : m_bbox( NULL ),
          m_vertexes( Vertexes() )
{
    // TODO
    m_bbox = new BoundingBox( m_vertexes );
}

Mesh::~Mesh()
{
    delete m_bbox;
}

Vertexes Mesh::getVertexes() const
{
    return m_vertexes;
}

FlattenedVertexes Mesh::flatten() const
{
    FlattenedVertexes flattened;
    flattened.reserve( m_vertexes.size() * 3 );
    for ( std::size_t index = 0; index != m_vertexes.size(); index++ )
    {
        flattened.push_back( m_vertexes[index].x );
        flattened.push_back( m_vertexes[index].y );
        flattened.push_back( m_vertexes[index].z );
    }
    return flattened;
}


BoundingBox* Mesh::getBoundingBox() const
{
    return m_bbox;
}

