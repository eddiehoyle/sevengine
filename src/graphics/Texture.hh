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

    /// Bind a texture to it's target.
    static void bind( Texture* texture );

    /// Unbind a texture from it's target.
    static void unbind( Texture* texture );

public:
    Texture();
    ~Texture();
//    explicit Texture( const char* path );

    bool initialise( GLenum target, const char* path, int width, int height );



    void bind();
    unsigned char* getImage() const;
    GLuint getHandle() const;
    GLenum getTarget() const;
    int getWidth() const;
    int getHeight() const;

private:
    void load( const char* path );

private:

    // Image data
    unsigned char* m_image;

    GLuint m_handle;
    GLenum m_target;

    int m_width;
    int m_height;



};

GLuint loadImage();


#endif //SEV_TEXTURE_HH
