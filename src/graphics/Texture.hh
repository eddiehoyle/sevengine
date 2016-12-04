//
// Created by Eddie Hoyle on 7/10/16.
//

#ifndef SEV_TEXTURE_HH
#define SEV_TEXTURE_HH

#define GL_GLEXT_PROTOTYPES
#include <GLES2/gl2.h>
#include <png.h>
#include <string>

class Texture2D
{

public:

    /// Bind a texture to it's target
    /// @param texture - A texture
    static void bind( Texture2D* texture, unsigned int index );

    /// Unbind a texture from it's target
    /// @param texture - A texture
    static void release( Texture2D* texture );

public:

    explicit Texture2D( const std::string& path );
    void setResizeMode( GLenum min, GLenum max );
    void setWrapMode( GLenum s, GLenum t );
    GLuint getHandle() const;

private:

    GLuint m_handle;
};

class Texture {

public:

    /// Bind a texture to it's target
    /// @param texture - A texture
    static void bind( Texture* texture );

    /// Unbind a texture from it's target
    /// @param texture - A texture
    static void unbind( Texture* texture );

public:

    /// Construct a texture
    /// @param target - A texture target to bind to, eg: GL_TEXTURE_2D
    /// @param path - Image file path
    /// @param width - Image width
    /// @param height - Image height
    explicit Texture( GLenum target, const char* path, int width, int height );

    /// Get the image data read into memory
    /// @returns Byte array of image data
    unsigned char* getImage() const;

    /// Get the texture handle generated with glGenTextures
    /// @returns This textures handle
    GLuint getHandle() const;

    /// Get the target this texture is bound to
    /// @returns The designated target
    GLenum getTarget() const;

    /// Get the width of this image
    /// @returns The image width
    int getWidth() const;

    /// Get the width of this image
    /// @returns The image height
    int getHeight() const;

private:

    /// Read image data into memory.
    /// @param path - Image file path.
    void readImage( const char* path );

private:

    unsigned char* m_image; /// Image data
    GLuint m_handle;        /// Texture handle
    GLenum m_target;        /// Texture target
    int m_width;            /// Image width
    int m_height;           /// Image height
};

#endif //SEV_TEXTURE_HH
