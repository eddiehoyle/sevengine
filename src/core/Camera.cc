//
// Created by Eddie Hoyle on 8/09/16.
//

#include "Camera.hh"


// GLM
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Camera::Camera()
        : m_transform( NULL ),
          m_width( 0 ),
          m_height( 0 )
{
    m_transform = new Transform();
//    m_width = 0;
//    m_height = 0;
}

//Camera::Camera( unsigned int screenWidth, unsigned int screenHeight )
//        : m_transform( NULL ),
//          m_width( 0 ),
//          m_height( 0 )
//{
//    m_transform = new Transform();
//    m_width = screenWidth;
//    m_height = screenHeight;
//}

Camera::~Camera()
{
    delete m_transform;
    m_width = 0;
    m_height = 0;
}

Transform* Camera::getTransform() const
{
    return m_transform;
}

void Camera::setTransform( Transform* transform )
{
    m_transform = transform;
}

void Camera::setFocalLength( double focal )
{
    // TODO
}

glm::mat4 Camera::getOrthographicMatrix()
{
    float aspectRatio = Game::instance()->getWindow()->getAspectRatio();
    glm::mat4 matrix = glm::ortho( -aspectRatio, aspectRatio, -1.0f, 1.0f, -1.0f, 1.0f );
    return matrix;
}

glm::mat4 Camera::getProjectionMatrix()
{
    // Perspective Matrix
    float fov = 45;
    float aspectRatio = Game::instance()->getWindow()->getAspectRatio();
    float nearClip = 0.1f;
    float farClip = 100.f;

    glm::mat4 matrix = glm::perspective( glm::radians( fov ),
                                        aspectRatio,
                                        nearClip,
                                        farClip );
    return matrix;
}