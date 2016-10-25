//
// Created by Eddie Hoyle on 7/10/16.
//

#ifndef SEV_TEXTURE_HH
#define SEV_TEXTURE_HH


#define GL_GLEXT_PROTOTYPES
#include <GLES2/gl2.h>
#include <png.h>

struct Texture {

    GLuint handle;
    GLuint width, height;

};

GLuint loadImage();


#endif //SEV_TEXTURE_HH
