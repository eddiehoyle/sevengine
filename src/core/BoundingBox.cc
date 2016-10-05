//
// Created by Eddie Hoyle on 1/10/16.
//

#include <glm/ext.hpp>
#include <iostream>
#include "BoundingBox.hh"

BoundingBox::BoundingBox()
            : m_min( 0 ),
              m_max( 0 )
{
    m_min = glm::vec3( 0.0f );
    m_max = glm::vec3( 0.0f );
}

BoundingBox::BoundingBox( const Vertexes& vertexes )
            : m_min( 0 ),
              m_max( 0 )
{
    update( vertexes );
}

BoundingBox::~BoundingBox()
{
    m_min = glm::vec3( 0.0f );
    m_max = glm::vec3( 0.0f );
}

void BoundingBox::update( const Vertexes& vertexes )
{
    Vertexes::const_iterator iter;
    for ( iter = vertexes.begin(); iter != vertexes.end(); iter++ )
    {
        extend( *iter );
    }
}

void BoundingBox::extend( const glm::vec3& point )
{
    m_min = glm::min( point, m_min );
    m_max = glm::max( point, m_max );
}

glm::vec3 BoundingBox::diagonal() const
{
    return m_max - m_min;
}

bool BoundingBox::intersect( const glm::vec3& point ) const
{
//    std::cout << "Checking intersection... " << glm::to_string( point ) << std::endl;
//    std::cout << "X: " << ( m_min.x <= point.x && m_max.x >= point.x ) << ", "
//              << "Y: " << ( m_min.y <= point.y && m_max.y >= point.y ) << ", "
//              << "Z: " << ( m_min.z <= point.z && m_max.z >= point.z ) << std::endl;
    std::cout << glm::to_string( m_min ) << " <= " << glm::to_string( point ) << " <= " << glm::to_string( m_max ) << std::endl;
    return ( m_min.x <= point.x ) && ( m_max.x >= point.x ) &&
           ( m_min.y <= point.y ) && ( m_max.y >= point.y ) &&
           ( m_min.z <= point.z ) && ( m_max.z >= point.z );
}

void BoundingBox::translate( const glm::vec3& point )
{
    m_max = m_max * point;
    m_min = m_min * point;
}

glm::vec3 BoundingBox::center() const
{
    return m_min + ( diagonal() / 0.5f );
}


glm::vec3 BoundingBox::getMin() const
{
    return m_min;
}

glm::vec3 BoundingBox::getMax() const
{
    return m_max;
}

