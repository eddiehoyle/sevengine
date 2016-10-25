//
// Created by Eddie Hoyle on 7/10/16.
//

#include "Texture.hh"
#include <SOIL.h>

#define GL_GLEXT_PROTOTYPES
#include <GLES2/gl2.h>

GLuint loadImage() {
    long flags = ( SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT );
    GLuint tex_2d = SOIL_load_OGL_texture( "img.png",
                                           SOIL_LOAD_AUTO,
                                           SOIL_CREATE_NEW_ID,
                                           flags );
    return tex_2d;
}