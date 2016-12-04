//
// Created by Eddie Hoyle on 28/08/16.
//

#include "Transform.hh"

#define GLM_SWIZZLE
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <iostream>

Transform::Transform()
        : m_position( glm::vec3() ),
          m_angle( 0.0f ),
          m_scale( glm::vec3( 1.0f ) )
{}

Transform::~Transform()
{}

Transform::Transform( const glm::vec2& position,
                      float angle,
                      const glm::vec2& scale )
        : m_position( glm::vec3() ),
          m_angle( 0.0f ),
          m_scale( glm::vec3( 1.0f ) )
{
    setPosition( position );
    setAngle( angle );
    setScale( scale );
}

void Transform::setPosition( const glm::vec2& position )
{
    m_position = glm::vec3( position.x, position.y, 0.0 );
    m_pivot += glm::vec3( position.x, position.y, 0.0 );
}

void Transform::setPosition( double x, double y )
{
    m_position = glm::vec3( x, y, 0.0 );
    m_pivot += glm::vec3( x, y, 0.0 );
}

void Transform::setAngle( double degrees )
{
    m_angle = degrees;
}

void Transform::setScale( const glm::vec2& scale )
{
    m_scale = glm::vec3( scale.x, scale.y, 0.0 );
}


void Transform::setScale( double x, double y )
{
    m_scale = glm::vec3( x, y, 0.0 );
}

glm::vec2 Transform::getPosition() const
{
    return glm::vec2( m_position.x, m_position.y );
}

double Transform::getAngle() const
{
    return m_angle;
}

glm::vec2 Transform::getScale() const
{
    return glm::vec2( m_scale.x, m_scale.y );
}

void Transform::setPivot( const glm::vec2& pivot )
{
    m_pivot = glm::vec3( pivot.x, pivot.y, 0.0f );
}

void Transform::setPivot( double x, double y )
{
    m_pivot = glm::vec3( x, y, 0.0f );
}

glm::vec2 Transform::getPivot() const
{
    return glm::vec2( m_pivot.x, m_pivot.y );
}

glm::mat4 Transform::getMatrix()
{
    glm::mat4 translate( 1.0f );
    glm::mat4 rotate( 1.0f );
    glm::mat4 scale( 1.0f );

    translate = glm::translate( translate, m_position );

    rotate = glm::translate( rotate, m_pivot );
    rotate = glm::rotate( rotate, glm::radians( -( float )m_angle ), glm::vec3( 0, 0, 1 ) );
    rotate = glm::translate( rotate, -m_pivot );

    scale = glm::translate( scale, m_pivot );
    scale = glm::scale( scale, glm::vec3( m_scale.x, m_scale.y, 1.0f ) );
    scale = glm::translate( scale, -m_pivot );

    return scale * rotate * translate;
}


