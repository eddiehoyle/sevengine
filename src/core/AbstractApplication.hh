//
// Created by Eddie Hoyle on 7/08/16.
//

#ifndef SEV_GAME_HH
#define SEV_GAME_HH

#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>

class AbstractApplication {

public:

    AbstractApplication( const unsigned int width, const unsigned int height );
    AbstractApplication();
    ~AbstractApplication();

    virtual void update( double elapsed );
    virtual void draw();
    virtual void changeWindowSize( const int width, const int height );

};


#endif //SEV_GAME_HH
