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

typedef std::map< const char*, int > AttributeMap;

class Shader {

public:

//    Shader();
//    ~Shader();

    explicit Shader( const char* vertex, const char* fragment );

public:

    GLuint getProgram() const;
    void setAttr( GLuint index, const char* name );
    GLuint getAttr( const char* name );
    void link();

public:

    void bindAttr( GLuint index, const char* name );

    // Attributes
    void setAttr( GLuint handle, const char* name, GLfloat value );
    void setAttr( GLuint handle, const char* name, const glm::vec2& vec );
    void setAttr( GLuint handle, const char* name, const glm::vec3& vec );
    void setAttr( GLuint handle, const char* name, const glm::vec4& vec );

    template< typename T >
    void setAttr( GLuint handle, GLenum type, GLint size, T* data );

public:

    // Uniforms
    GLint getUnifHandle( const char* name );

    void setUnif( GLuint handle, GLfloat value );
    void setUnif( GLuint handle, const glm::vec2& vec );
    void setUnif( GLuint handle, const glm::vec3 &vec );
    void setUnif( GLuint handle, const glm::vec4& vec );
    void setUnif( GLuint handle, bool transpose, const glm::mat2& mat );
    void setUnif( GLuint handle, bool transpose, const glm::mat3& mat );
    void setUnif( GLuint handle, bool transpose, const glm::mat4& mat );

private:

    GLuint compile( const char* shader, GLenum type );
    void check( const GLuint &id, const GLenum type );

private:
    GLuint m_program;

    /// Shader handles
    GLuint m_vertex;
    GLuint m_fragment;

};


#endif //SEV_SHADER_HH
