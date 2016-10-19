//
// Created by Eddie Hoyle on 5/10/16.
//

#include "AbstractRender.hh"
#include "Buffer.hh"

AbstractRender::AbstractRender()
        : m_type( kNull ),
          m_buffer( NULL )
{
    m_type = kNull;
    m_buffer = new Buffer( GL_ARRAY_BUFFER );
}

AbstractRender::~AbstractRender()
{
    delete m_buffer;
}
