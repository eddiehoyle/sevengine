//
// Created by Eddie Hoyle on 11/09/16.
//

#ifndef SEV_ABSTRACTEVENT_HH
#define SEV_ABSTRACTEVENT_HH

enum EventType {
    kNull = 0,
    kTouchPress,
    kTouchMove,
    kTouchRelease,
};

class AbstractEvent {

public:
    AbstractEvent() : m_type( kNull ) {};
    AbstractEvent( EventType type ) : m_type( type ) {};
    virtual ~AbstractEvent() {};

    EventType getType() const
    {
        return m_type;
    }


protected:
    EventType m_type;

};


#endif //SEV_ABSTRACTEVENT_HH
