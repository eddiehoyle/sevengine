//
// Created by Eddie Hoyle on 7/08/16.
//

#include <iostream>
#include "AbstractApplication.hh"
#include "Window.hh"


// GLM
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace std;


AbstractApplication::AbstractApplication( const unsigned int width, const unsigned int height )
{
//    WindowManager::instance()->setWindowSize( width, height );
}

AbstractApplication::AbstractApplication()
{
    // TODO
}

AbstractApplication::~AbstractApplication()
{
    // TODO
}

void AbstractApplication::update( double elapsed )
{
    // TODO
}

void AbstractApplication::draw()
{
    // TODO
}

void AbstractApplication::changeWindowSize(const int width, const int height)
{
//    WindowManager::instance()->setWindowSize( width, height );
}