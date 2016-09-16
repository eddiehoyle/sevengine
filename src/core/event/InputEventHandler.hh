//
// Created by Eddie Hoyle on 14/09/16.
//

#ifndef SEV_INPUTHANDLER_HH
#define SEV_INPUTHANDLER_HH

#include <iostream>
#include <vector>
#include <queue>
#include "AbstractEvent.hh"

typedef std::queue  < AbstractEvent* > EventQueue;

class InputEventHandler {

public:

    InputEventHandler()
    {
        m_events = EventQueue();
    };
    ~InputEventHandler() {};

    void push( AbstractEvent* event );
    void push( int index );

    AbstractEvent* next()
    {
        AbstractEvent* event = m_events.front();
        m_events.pop();
        return event;
    };

    void flush()
    {
        // TODO
    }

    bool empty()
    {
        return m_events.empty();
    
    }
    
    std::vector< int > m_nums;

    EventQueue m_events;
//    std::queue< AbstractEvent* > m_events;

//private:
    

};


#endif //SEV_INPUTHANDLER_HH
