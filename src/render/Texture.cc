//
// Created by Eddie Hoyle on 7/10/16.
//

#include "Texture.hh"
#include <SOIL.h>

#define GL_GLEXT_PROTOTYPES
#include <GLES2/gl2.h>


Texture::Texture( const char* path )
        : m_handle( 0 ),
          m_width( 0 ),
          m_height( 0 )
{
    load( path );
}

void Texture::load( const char* path )
{
    m_handle = SOIL_load_OGL_texture( path,
                                      SOIL_LOAD_AUTO,
                                      SOIL_CREATE_NEW_ID,
                                      SOIL_FLAG_MIPMAPS
                                      | SOIL_FLAG_INVERT_Y
                                      | SOIL_FLAG_NTSC_SAFE_RGB
                                      | SOIL_FLAG_COMPRESS_TO_DXT );

    if ( m_handle == 0 )
    {
        printf( "Texture::Error: Error loading OGL texture\n" );
    }

    // Typical Texture Generation Using Data From The Bitmap
    glBindTexture( GL_TEXTURE_2D, m_handle );
    glTexParameteri( GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR );
}

GLuint Texture::getHandle() const
{
    return m_handle;
}

int Texture::getWidth() const
{
    return m_width;
}

int Texture::getHeight() const
{
    return m_height;
}

void Texture::bind()
{

}
