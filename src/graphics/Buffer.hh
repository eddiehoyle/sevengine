//
// Created by Eddie Hoyle on 5/10/16.
//

#ifndef SEV_BUFFER_HH
#define SEV_BUFFER_HH

#define GL_GLEXT_PROTOTYPES
#include <GLES2/gl2.h>
#include <cstddef>

inline char* BufferOffset( GLuint offset ) {
    return ( char* )NULL + offset;
}

class Buffer {

public:

    Buffer();
    ~Buffer();

    explicit Buffer( GLenum target );

public:

    /// Create a buffer
//    void create( GLenum target );

    /// Create a new buffer store bound to m_target
    /// @param size: Size in bytes of the buffer object's new data store.
    /// @param usage: Specifies the expected usage pattern of the data store.
    ///     These may be GL_STATIC_DRAW, GL_DYNAMIC_DRAW or GL_STREAM_DRAW
    void allocate( GLsizei size, GLenum usage );

    /// Fill up the buffer, or parts of the buffer with data.
    /// @param data: Pointer to the new data that will be copied into the data store.
    /// @param offset: Specifies the offset into the buffer object's data store where data
    ///     replacement will begin, measured in bytes.
    /// @param size: Specifies the size in bytes of the data store region being replaced.
    void buffer( GLintptr offset, GLsizei size, void* data );

    /// Bind this buffer to m_target.
    void bind();

    /// Break connection to m_target.
    void unbind();

    /// Delete this buffer.
    void release();

    /// Get the ID.
    /// returns the ID of this buffer.
    GLuint getID() const;

private:

    /// The id of this buffer
    GLuint m_id;

    /// TODO
    GLenum m_target;
};


#endif //SEV_BUFFER_HH
