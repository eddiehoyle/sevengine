//
// Created by Eddie Hoyle on 7/10/16.
//

#ifndef SEV_TEXTURE_HH
#define SEV_TEXTURE_HH


#define GL_GLEXT_PROTOTYPES
#include <GLES2/gl2.h>
#include <png.h>


class Texture {

public:
    Texture() {}
    explicit Texture( const char* path );

    ~Texture() {}

    void bind();
    GLuint getHandle() const;
    int getWidth() const;
    int getHeight() const;

private:
    void load( const char* path );

private:
    GLuint m_handle;
    int m_width;
    int m_height;

};

GLuint loadImage();


#endif //SEV_TEXTURE_HH
