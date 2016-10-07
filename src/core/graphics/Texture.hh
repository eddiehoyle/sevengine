//
// Created by Eddie Hoyle on 7/10/16.
//

#ifndef SEV_TEXTURE_HH
#define SEV_TEXTURE_HH


#include <OpenGLES/gltypes.h>

struct Texture {

    void set( int width, int height, GLuint handle );
    GLuint handle;
    int width, height;

};


#endif //SEV_TEXTURE_HH
