//
// Created by Eddie Hoyle on 30/01/17.
//

#include "TextureManager2D.hh"
#include <SOIL.h>

#include <iosfwd>
#include <fstream>
#include <iostream>

TextureManager2D* TextureManager2D::m_instance = 0;

TextureManager2D* TextureManager2D::instance() {
    if ( m_instance == 0 ) {
        m_instance = new TextureManager2D();
    }
    return m_instance;
}

TextureManager2D::~TextureManager2D() {

    if ( m_instance ) {
        delete m_instance;
    }
    m_instance = 0;
}

TextureManager2D::TextureManager2D()
        : m_max( 0 ),
          m_units( std::vector< GLuint >() ) {

    // Initialize max texture units
    GLint size;
    glGetIntegerv( GL_MAX_TEXTURE_IMAGE_UNITS, &size );
    m_max = ( GLsizei )size;

    // Reserve units
    m_units.reserve( ( std::size_t )size );
}

bool TextureManager2D::load( const std::string& id, const std::string& path ) {

    std::ifstream file( path.c_str() );
    if ( !file.good() ) {
        std::cerr << "Texture path doesn't exist: " << path << std::endl;
        return false;
    }

    GLuint handle = SOIL_load_OGL_texture( path.c_str(),
                                      SOIL_LOAD_AUTO,
                                      SOIL_CREATE_NEW_ID,
                                      SOIL_FLAG_MIPMAPS
                                      | SOIL_FLAG_INVERT_Y
                                      | SOIL_FLAG_NTSC_SAFE_RGB
                                      | SOIL_FLAG_COMPRESS_TO_DXT );

    m_textureMap.insert( std::pair< std::string, GLuint >( id, handle ) );
    return true;
}

bool TextureManager2D::unload( const std::string& id ) {

    GLint tmp = getHandle( id );
    if ( tmp < 0 ) {
        return false;
    }

    const GLuint handle = ( GLuint )tmp;
    glDeleteTextures( 1, &handle );

    // Delete
    m_textureMap.erase( id );

    return true;
}

GLint TextureManager2D::getHandle( const std::string& id ) const {

    TextureMap::const_iterator iter = m_textureMap.find( id );
    if ( iter != m_textureMap.end() ) {
        return iter->second;
    }
    return -1;
}

bool TextureManager2D::bind( const std::string& id, GLuint unit ) {

    GLint handle = getHandle( id );
    if ( handle < 0 ) {
        return false;
    }

    glActiveTexture( GL_TEXTURE0 + unit );
    glBindTexture( GL_TEXTURE_2D, ( GLuint )handle );
    return true;
}

void TextureManager2D::setResizeMode( GLenum min, GLenum max )
{
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, min );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, max );
}

void TextureManager2D::setWrapMode( GLenum s, GLenum t )
{
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, s );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, t );
}
void TextureManager2D::enable() {
    glEnable( GL_TEXTURE_2D );

}

void TextureManager2D::disable() {
    glDisable( GL_TEXTURE_2D );
}

