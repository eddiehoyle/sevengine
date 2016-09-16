//
// Created by Eddie Hoyle on 15/09/16.
//

#ifndef SEV_INPUTEVENT_HH
#define SEV_INPUTEVENT_HH

#include <cmath>
#include <iostream>
#include "AbstractEvent.hh"

class TouchPressEvent : public AbstractEvent {

public:

    TouchPressEvent()
            : AbstractEvent( kTouchPress ),
              x( 0 ),
              y( 0 )
    {};

    explicit TouchPressEvent( const float x, const float y )
            : AbstractEvent( kTouchPress ),
              x( x ),
              y( y )
    {
        std::cout << "TouchPressEvent (" << x << ", " << y << ")" << std::endl;
    }

    ~TouchPressEvent()
    {
        std::cout << "TouchPressEvent delete()" << std::endl;
    };

    const  float x;
    const  float y;
};


class TouchMoveEvent : public AbstractEvent {

public:

    TouchMoveEvent()
            : AbstractEvent( kTouchMove ),
              prevX( 0 ),
              prevY( 0 ),
              x( 0 ),
              y( 0 ),
              magnitude( 0 )
    {};

    explicit TouchMoveEvent( const  float prevX, const  float prevY, const  float x, const  float y )
            : AbstractEvent( kTouchMove ),
              prevX( prevX ),
              prevY( prevY ),
              x( x ),
              y( y ),
              magnitude( computeMagnitude() )
    {
        std::cout << "TouchMoveEvent("
        << prevX << ", " << prevY << ")"
        << " --> ("
        << x << ", " << y << "), magnitude: " << magnitude
        << std::endl;
    }

    ~TouchMoveEvent()
    {
        std::cout << "TouchMoveEvent delete()" << std::endl;
    };

    const  float prevX;
    const  float prevY;
    const  float x;
    const  float y;
    const double magnitude;

private:
    double computeMagnitude()
    {
        double prev = sqrt( pow( prevX, 2 ) + pow( prevY, 2 ) );
        double current = sqrt( pow( x, 2 ) + pow( y, 2 ) );
        return fabs( current - prev );
    }

};

class TouchReleaseEvent : public AbstractEvent {

public:

    TouchReleaseEvent()
            : AbstractEvent( kTouchRelease ),
              x( 0 ),
              y( 0 )
    {};

    explicit TouchReleaseEvent( const  float x, const  float y )
            : AbstractEvent( kTouchRelease ),
              x( 0 ),
              y( 0 )
    {
        std::cout << "TouchReleaseEvent (" << x << ", " << y << ")" << std::endl;
    }

    ~TouchReleaseEvent()
    {
        std::cout << "TouchReleaseEvent delete()" << std::endl;
    };

    const  float x;
    const  float y;
};


#endif //SEV_INPUTEVENT_HH
