//
// Created by Eddie Hoyle on 8/09/16.
//

#include "Model.hh"

void Model::setVertexes( GLfloat* vertexes )
{
    m_vertexes = vertexes;
}

GLfloat* Model::getVertexes() const
{
    return m_vertexes;
}