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

    Shader();
    explicit Shader( const char* vertex, const char* fragment );
    ~Shader();

public:

    GLuint getProgram() const;
    void use();

public:

    // Attributes
    void bindAttr( GLuint index, const char* name );

    GLint getAttrHandle( const char* name ) const;
    void setAttr( const char* name, GLfloat value );
    void setAttr( const char* name, const glm::vec2& vec );
    void setAttr( const char* name, const glm::vec3& vec );
    void setAttr( const char* name, const glm::vec4& vec );

    void setAttr( const char* name, GLenum type, GLint size, GLfloat* data );

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
