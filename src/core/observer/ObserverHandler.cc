//
// Created by Eddie Hoyle on 17/09/16.
//

#include "ObserverHandler.hh"


void ObserverHandler::addContext( ObserverContext* context )
{
    m_contexts.push_back( context );
    if ( m_contexts.size() == 1 )
    {
        setActiveContext( context );
    }
}

void ObserverHandler::setActiveContext( ObserverContext* context )
{
    if ( std::find( m_contexts.begin(), m_contexts.end(), context ) != m_contexts.end() )
    {
        m_active = context;
    }
}

ObserverContext* ObserverHandler::getActiveContext() const
{
    return m_active;
}

