//
// Created by Eddie Hoyle on 5/10/16.
//

#include "RenderQuad.hh"


RenderQuad::RenderQuad()
        : AbstractRender()
{
    m_type = kQuad;
}

RenderQuad::~RenderQuad()
{
    m_type = kNull;
}