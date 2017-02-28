//
// Created by Eddie Hoyle on 30/01/17.
//

#ifndef SEVENGINE_TEXTUREMANAGER_HH
#define SEVENGINE_TEXTUREMANAGER_HH

#define GL_GLEXT_PROTOTYPES
#include <GLES2/gl2.h>
#include <string>
#include <map>
#include <vector>
#include <iostream>

/* Note:
 * 16 slots available on macbook
 */

/*
 * TODO
 * Working on splitting up texture units
 * When to load images and how to store them
 * in the manager.
 */

class TextureManager2D {

    typedef std::map< std::string, GLuint > TextureMap;

public:
    static TextureManager2D* instance();
    ~TextureManager2D();

    bool load( const std::string& id, const std::string& path, bool invert=true );
    bool unload( const std::string& id );

    GLint getHandle( const std::string& id ) const;

    /// Bind a texture to a unit. Note, you don't need to unbind.
    bool bind( const std::string& id, GLuint unit );

    /// Enable 2D textures. Must be set!
    void enable();

    /// Disable textures and also resets all texture unit bindings
    void disable();

    /// Set resized pixels are displayed
    void setResizeMode( GLenum min, GLenum max );

    /// Set how pixels are displayed outside of UVs
    void setWrapMode( GLenum s, GLenum t );

    void print() const {

        std::cerr << "TextureManager2D: Found " << m_textureMap.size() << " texture(s)" << std::endl;
        for ( TextureMap::const_iterator iter = m_textureMap.begin();
              iter != m_textureMap.end();
              ++iter ) {
            std::cerr << "TextureManager2D: Image(id="
                      << iter->first << ", handle=" << iter->second
                      << std::endl;
        }
    }


    GLint getNextUnit() const;
    std::vector< GLuint > getUnits() const;
    bool isUnitInUse( GLuint unit );


private:
    static TextureManager2D* m_instance;

    TextureManager2D();
    TextureManager2D( const TextureManager2D& );
    TextureManager2D& operator=( const TextureManager2D& );

    TextureMap m_textureMap;

    // Units
    GLsizei m_max;
    std::vector< GLuint > m_units;
};


#endif //SEVENGINE_TEXTUREMANAGER_HH
