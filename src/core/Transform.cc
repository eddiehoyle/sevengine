//
// Created by Eddie Hoyle on 28/08/16.
//

#include "Transform.hh"


Transform::Transform() :
    m_translate( glm::vec3() ),
    m_rotate( glm::vec3() ),
    m_scale( glm::vec3() )
{
    // TODO
}


Transform::Transform( const glm::vec3 translate,
                      const glm::vec3 rotate,
                      const glm::vec3 scale,
                      Transform::RotateOrder order ) :
    m_translate( glm::vec3() ),
    m_rotate( glm::vec3() ),
    m_scale( glm::vec3() )
{
    m_translate = translate;
    m_rotate = rotate;
    m_scale = scale;
}

Transform::Transform( const glm::mat4 matrix ) :
    m_translate( glm::vec3() ),
    m_rotate( glm::vec3() ),
    m_scale( glm::vec3() )
{
    // TODO
}

Transform::~Transform()
{
    m_translate = glm::vec3();
    m_rotate = glm::vec3();
    m_scale = glm::vec3();
}

void Transform::setTranslate( const glm::vec3 translate )
{
    m_translate = translate;
}

void Transform::setRotate( const glm::vec3 rotate )
{
    m_rotate = rotate;
}

void Transform::setScale( const glm::vec3 scale )
{
    m_scale = scale;
}

glm::vec3& Transform::getTranslate()
{
    return m_translate;
}

glm::vec3& Transform::getRotate()
{
    return m_rotate;
}

glm::vec3& Transform::getScale()
{
    return m_scale;
}

glm::mat4 Transform::getMatrix()
{
    return glm::mat4();
}


