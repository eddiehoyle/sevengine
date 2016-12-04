//
// Created by Eddie Hoyle on 7/10/16.
//

#include "Texture.hh"
#include <SOIL.h>
#include <iostream>

void Texture2D::bind( Texture2D* texture, GLenum slot )
{
    glActiveTexture( slot );
    glBindTexture( GL_TEXTURE_2D, texture->getHandle() );
}

void Texture2D::release( Texture2D* texture )
{
    glBindTexture( GL_TEXTURE_2D, 0 );
}

Texture2D::Texture2D( const std::string& path )
        : m_handle( 0 )
{
    m_handle = SOIL_load_OGL_texture ( path.c_str(),
                                       SOIL_LOAD_AUTO,
                                       SOIL_CREATE_NEW_ID,
                                       SOIL_FLAG_MIPMAPS
                                       | SOIL_FLAG_INVERT_Y
                                       | SOIL_FLAG_NTSC_SAFE_RGB
                                       | SOIL_FLAG_COMPRESS_TO_DXT );

    // defaults
    setResizeMode( GL_LINEAR, GL_LINEAR );
    setWrapMode( GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE );
}


void Texture2D::setResizeMode( GLenum min, GLenum max )
{
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, min );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, max );
}

void Texture2D::setWrapMode( GLenum s, GLenum t )
{
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, s );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, t );
}


GLuint Texture2D::getHandle() const
{
    return m_handle;
}





// -----------------

void Texture::bind( Texture* texture )
{
    glActiveTexture( GL_TEXTURE0 );
    glBindTexture( texture->getTarget(), texture->getHandle() );
}

void Texture::unbind( Texture* texture )
{
    glBindTexture( texture->getTarget(), 0 );
}

Texture::Texture( GLenum target, const char* path, int width, int height )
        : m_image( 0 ),
          m_handle( 0 ),
          m_target( 0 ),
          m_width( 0 ),
          m_height( 0 )
{
//    // Create a texture buffer
//    glGenTextures(1, &m_handle);
//
//    // Set the target this texture will be bound to
    m_target = target;
//
//    // Bind this texture
//    glBindTexture(m_target, m_handle);
//
//    // Image dimensions
//    m_width = width;
//    m_height = height;

    // Read and store image data
    readImage(path);
}

void Texture::readImage( const char* path )
{
    // Load image data
//    m_image = SOIL_load_image(
//            path,
//            &m_width, &m_height, 0,
//            SOIL_LOAD_RGBA );
//
//
//    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
//    glTexParameteri( m_target, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
//    glTexImage2D( m_target, 0, GL_RGBA, m_width, m_height, 0,
//                  GL_RGBA, GL_UNSIGNED_BYTE, m_image );
//    glGenerateMipmap( m_target );
//    SOIL_free_image_data( m_image );

    m_handle = SOIL_load_OGL_texture (
                    path,
                    SOIL_LOAD_AUTO,
                    SOIL_CREATE_NEW_ID,
                    SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
            );

}

GLuint Texture::getHandle() const
{
    return m_handle;
}

GLenum Texture::getTarget() const
{
    return m_target;
}

unsigned char* Texture::getImage() const
{
    return m_image;
}

int Texture::getWidth() const
{
    return m_width;
}

int Texture::getHeight() const
{
    return m_height;
}


