//
// Created by Eddie Hoyle on 30/01/17.
//

#ifndef SEVENGINE_TEXTUREMANAGER_HH
#define SEVENGINE_TEXTUREMANAGER_HH

#define GL_GLEXT_PROTOTYPES
#include <GLES2/gl2.h>
#include <string>
#include <map>

/* Note:
 * 16 slots available on macbook
 */

/*
 * TODO
 * Working on splitting up texture units
 * When to load images and how to store them
 * in the manager.
 */

struct Texture2Da {
    GLuint handle;
};

class TextureManager2D {

public:
    TextureManager2D* instance();
    ~TextureManager2D();

    void load( const std::string& id, const std::string& path );

private:
    static TextureManager2D* m_instance;

    TextureManager2D();
    TextureManager2D( const TextureManager2D& );
    TextureManager2D& operator=( const TextureManager2D& );

    std::map< std::string, GLuint > m_textureMap;

};


#endif //SEVENGINE_TEXTUREMANAGER_HH
