//
// Created by Eddie Hoyle on 14/08/16.
//

#include "Window.hh"
#include <iostream>
#include <cmath>

Window::Window()
        : m_width( 0 ),
          m_height( 0 )
{}

float Window::getAspectRatio() const
{
    return ( float )m_width/m_height;
}

void Window::update( int width, int height )
{
    m_width = width;
    m_height = height;
}

int Window::getWidth() const {
    return m_width;
}

void Window::setWidth( int width ) {
    m_width = width;
}

int Window::getHeight() const {
    return m_height;
}

void Window::setHeight( int height ) {
    m_height = height;
}

//WindowManager* WindowManager::s_instance = 0;
//
//WindowManager::WindowManager()
//{}
//
//WindowManager::~WindowManager()
//{
//    m_width = 0;
//    m_height = 0;
//
//    s_instance = 0;
//}
//
//WindowManager* WindowManager::instance()
//{
//    if ( s_instance == 0 )
//    {
//        s_instance = new WindowManager();
//    }
//    return s_instance;
//}
//
//void WindowManager::setWindowSize( const int width, const int height )
//{
//    m_width = width;
//    m_height = height;
//
//    m_orientation = width > height ? kLandscape : kPortrait;
//
//    computeOrthographicProjectionMatrix();
//    computePerspectiveProjectionMatrix();
//}
//
//int WindowManager::getWidth() const
//{
//    return m_width;
//}
//
//int WindowManager::getHeight() const
//{
//    return m_height;
//}
//
//glm::mat4 WindowManager::getOrthographicProjectionMatrix() const
//{
//return m_orthographicProjectionMatrix;
//}
//
//glm::mat4 WindowManager::getPerspectiveProjectionMatrix() const
//{
//return m_perspectiveProjectionMatrix;
//}
//
//void WindowManager::setOrthographicProjectionMatrix( const glm::mat4 &matrix )
//{
//    m_orthographicProjectionMatrix = matrix;
//}
//
//void WindowManager::setPerspectiveProjectionMatrix( const glm::mat4 &matrix )
//{
//    m_perspectiveProjectionMatrix = matrix;
//}
//
//WindowManager::Orientation WindowManager::getOrientation() const
//{
//    return m_orientation;
//}
//
//void WindowManager::computeOrthographicProjectionMatrix()
//{
//    // Orthographic Matrix
//    float left = ( float )-m_width/m_height;
//    float right = ( float )m_width/m_height;
////    std::cout << "Sev: " << width << ", " << height << ", " << left << ", " << right << std::endl;
//    m_orthographicProjectionMatrix = glm::ortho( left, right, -1.0f, 1.0f, -1.0f, 1.0f );
//
//}
//void WindowManager::computePerspectiveProjectionMatrix()
//{
//    // Perspective Matrix
//    float fov = 45;
//    float aspectRatio = ( float )m_width/m_height;
//    float nearClip = 0.1f;
//    float farClip = 100.f;
//    m_perspectiveProjectionMatrix = glm::perspective(glm::radians(45.0f), aspectRatio, nearClip, farClip );
//
//}
