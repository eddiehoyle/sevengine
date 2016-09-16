//
// Created by Eddie Hoyle on 14/09/16.
//

#include "InputEventHandler.hh"

void InputEventHandler::push( AbstractEvent *event )
{
    m_events.push( event );
}

void InputEventHandler::push( int index )
{
    m_nums.push_back( index );
}