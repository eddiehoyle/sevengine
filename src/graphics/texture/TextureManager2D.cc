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


void TextureManager2D::load( const std::string& id, const std::string& path ) {

    std::ifstream file( path.c_str() );
    if ( !file.good() ) {
        std::cerr << "Texture path doesn't exist: " << path << std::endl;
        return;
    }

    GLuint handle = SOIL_load_OGL_texture( path.c_str(),
                                      SOIL_LOAD_AUTO,
                                      SOIL_CREATE_NEW_ID,
                                      SOIL_FLAG_MIPMAPS
                                      | SOIL_FLAG_INVERT_Y
                                      | SOIL_FLAG_NTSC_SAFE_RGB
                                      | SOIL_FLAG_COMPRESS_TO_DXT );

    m_textureMap.insert( std::pair< std::string, GLuint >( id, handle ) );
}


