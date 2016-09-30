//
// Created by Eddie Hoyle on 8/09/16.
//

#include "Camera.hh"


// GLM
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

Camera::Camera()
        : m_transform( NULL ),
          m_aspect( 1 )
{
    m_transform = new Transform();
}

Camera::~Camera() {
    delete m_transform;
}

Transform* Camera::getTransform() const
{
    return m_transform;
}

void Camera::setTransform( Transform* transform )
{
    m_transform = transform;
}

void Camera::setAspectRatio( float aspect )
{
    m_aspect = aspect;
}

void Camera::setFocalLength( double focal )
{
    // TODO
}

glm::mat4 Camera::getOrthographicMatrix( const unsigned int width, const unsigned int height )
{
    glm::mat4 matrix = glm::ortho( 0.0f, ( float )width, ( float )height, 0.0f, -1.0f, 1.0f );
    return matrix;
}

glm::mat4 Camera::getPerspectiveMatrix( const unsigned int width, const unsigned int height )
{
    // Perspective Matrix
    float aspect = ( float )width / height;
    float fov = 45.0f;
    float nearClip = 0.1f;
    float farClip = 100.f;

    glm::mat4 matrix = glm::perspective( glm::radians( fov ),
                                         aspect,
                                         nearClip,
                                         farClip );
    return matrix;
}