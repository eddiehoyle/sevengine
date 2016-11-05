//
// Created by Eddie Hoyle on 28/08/16.
//

#ifndef SEV_SHADER_HH
#define SEV_SHADER_HH

#define GL_GLEXT_PROTOTYPES
#include <GLES2/gl2.h>
#include <iostream>
#include <glm/ext.hpp>
#include <glm/vec4.hpp>
#include <map>

//
//struct Attribute;
//typedef std::vector< Attribute > Attributes;
//
//struct Attribute {
//    explicit Attribute( GLuint _index,
//                           const char* _name,
//                           GLsizei _size,
//                           GLenum _type,
//                           GLsizei _offset )
//    {
//        index = _index;
//        name = _name;
//        size = _size;
//        type = _type;
//        offset = _offset;
//    };
//
//    GLuint index;
//    const char* name;
//    GLsizei size;
//    GLenum type;
//    GLsizei offset;
//};

/*
 * - Is Attribute struct useful?
 * - It's only used for VBOs and describing the offset between
 * arrays.
 *
 */

inline const char* BufferOffset( GLsizei offset ) {
    return ( char* )NULL + offset;
}

class Shader {



public:

    Shader();
    explicit Shader( const char* vertex, const char* fragment );
    ~Shader();

public:

    GLuint getProgram() const;
    void use();

    // Attributes
    void bindAttr( GLuint index, const char* name );

    GLint getAttrHandle( const char* name ) const;
    void setAttr( const char* name, GLfloat value );
    void setAttr( const char* name, const glm::vec2& vec );
    void setAttr( const char* name, const glm::vec3& vec );
    void setAttr( const char* name, const glm::vec4& vec );
    void setAttr( const char* name, GLint size, GLenum type,
                  bool normalized, GLsizei stride, void* data );

    void enableAttr( const char* name );
    void disableAttr( const char* name );

    void setAttrOffset( const char* name, GLint size, GLenum type,
                        bool normalized, GLsizei stride, GLsizei offset );

public:

    // Uniforms
    GLint getUnifHandle( const char* name );

    void setUnif( const char* name, GLfloat value );
    void setUnif( const char* name, const glm::vec2& vec );
    void setUnif( const char* name, const glm::vec3 &vec );
    void setUnif( const char* name, const glm::vec4& vec );
    void setUnif( const char* name, bool transpose, const glm::mat2& mat );
    void setUnif( const char* name, bool transpose, const glm::mat3& mat );
    void setUnif( const char* name, bool transpose, const glm::mat4& mat );

private:

    GLuint compile( const char* shader, GLenum type );
    void link();
    void check( const GLuint &id, const GLenum type );

private:

    /// Shader program
    GLuint m_program;

    /// Shader objects
    GLuint m_vertex;
    GLuint m_fragment;

};


#endif //SEV_SHADER_HH
