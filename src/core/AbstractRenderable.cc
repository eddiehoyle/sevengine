//
// Created by Eddie Hoyle on 7/08/16.
//

#include <iostream>
#include "AbstractRenderable.hh"

AbstractRenderable::AbstractRenderable() :
    m_transform( NULL )
{
    m_transform = new Transform();
}

void AbstractRenderable::setTransform( Transform* transform )
{
    m_transform = transform;
}

Transform* AbstractRenderable::getTransform() const
{
    return m_transform;
}


