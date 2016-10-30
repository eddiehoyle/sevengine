//
// Created by Eddie Hoyle on 28/08/16.
//

#include <vector>
#include <glm/ext.hpp>
#include <glm/vec4.hpp>
#include "Shader.hh"

Shader::Shader()
        : m_program( 0 ),
          m_vertex( 0 ),
          m_fragment( 0 )
{
    m_program = 0;
    m_vertex = 0;
    m_fragment = 0;
}

Shader::Shader( const char* vertex, const char* fragment )
        : m_program( 0 ),
          m_vertex( 0 ),
          m_fragment( 0 )
{
    m_program = glCreateProgram();
    m_vertex = compile( vertex, GL_VERTEX_SHADER );
    m_fragment = compile( fragment, GL_FRAGMENT_SHADER );
    link();
}

Shader::~Shader()
{
    m_program = 0;
    m_vertex = 0;
    m_fragment = 0;
}


GLuint Shader::getProgram() const
{
    return m_program;
}

GLuint Shader::compile( const char* shader, const GLenum type )
{
    // Compile shader
    GLuint id = glCreateShader( type );
    glShaderSource( id, 1, &shader, NULL );
    glCompileShader( id );

    // Check compile result
    GLint result = GL_FALSE;
    glGetShaderiv( id, GL_COMPILE_STATUS, &result );
    if ( !result )
    {
        GLsizei logLength;
        glGetShaderiv( id, GL_INFO_LOG_LENGTH, &logLength );
        if ( logLength )
        {
            char log[logLength - 1];
            glGetShaderInfoLog( id, logLength, &logLength, log );
            printf( "Shader::Error::Compile: %s\n", log );
        }
    } else
    {
        printf( "Shader::Success::Compile: Shader compiled successfully\n" );
    }
    return id;
}

void Shader::link() {

    // Link the program
    glAttachShader( m_program, m_vertex );
    glAttachShader( m_program, m_fragment );
    glLinkProgram( m_program );

    // Check the link status
    GLint linked = GL_FALSE;
    glGetProgramiv( m_program, GL_LINK_STATUS, &linked );
    if ( !linked )
    {
        GLint logLength = 0;
        glGetProgramiv( m_program, GL_INFO_LOG_LENGTH, &logLength );
        if (logLength > 0)
        {
            GLchar log[logLength - 1];
            glGetProgramInfoLog( m_program, logLength, NULL, log );
            printf( "Shader::Error::Link: %s\n", log );
            glDeleteProgram( m_program );
        }
    } else
    {
        printf( "Shader::Success::Link: Shader linked successfully\n" );
    }
}

void Shader::use()
{
    glUseProgram( m_program );
}

void Shader::bindAttr( GLuint index, const char *name )
{
    glBindAttribLocation( m_program, index, name );
}

GLint Shader::getAttrHandle( const char* name ) const
{
    return glGetAttribLocation( m_program, name );
}

void Shader::setAttr( const char* name, GLfloat value )
{
    glVertexAttrib1f( glGetAttribLocation( m_program, name ), value );
}

void Shader::setAttr( const char* name, const glm::vec2& vec )
{
    glVertexAttrib2fv( glGetAttribLocation( m_program, name ), glm::value_ptr( vec ) );
}

void Shader::setAttr( const char* name, const glm::vec3& vec )
{
    glVertexAttrib3fv( glGetAttribLocation( m_program, name ), glm::value_ptr( vec ) );
}

void Shader::setAttr( const char* name, const glm::vec4& vec )
{
    glVertexAttrib4fv( glGetAttribLocation( m_program, name ), glm::value_ptr( vec ) );
}

void Shader::setAttr( const char* name, GLenum type, GLint size, GLfloat* data )
{
    GLboolean normalized = GL_FALSE;
    GLsizei stride = 0;
    glVertexAttribPointer( glGetAttribLocation( m_program, name ), size, type, normalized, stride, data );
}

GLint Shader::getUnifHandle( const char *name )
{
    return glGetUniformLocation( m_program, name );
}

void Shader::setUnif( const char* name, GLfloat value )
{
    glUniform1f( getUnifHandle( name ), value );
}

void Shader::setUnif( const char* name, const glm::vec2& vec )
{
    glUniform2fv( getUnifHandle( name ), 1, glm::value_ptr( vec ) );
}

void Shader::setUnif( const char* name, const glm::vec3 &vec )
{
    glUniform3fv( getUnifHandle( name ), 1, glm::value_ptr( vec ) );
}

void Shader::setUnif( const char* name, const glm::vec4& vec )
{
    glUniform4fv( getUnifHandle( name ), 1, glm::value_ptr( vec ) );
}

void Shader::setUnif( const char* name, bool transpose, const glm::mat2& mat )
{
    glUniformMatrix2fv( getUnifHandle( name ), 1, ( GLboolean )transpose, glm::value_ptr( mat ) );
}

void Shader::setUnif( const char* name, bool transpose, const glm::mat3& mat )
{
    glUniformMatrix3fv( getUnifHandle( name ), 1, ( GLboolean )transpose, glm::value_ptr( mat ) );
}

void Shader::setUnif( const char* name, bool transpose, const glm::mat4& mat )
{
    glUniformMatrix4fv( getUnifHandle( name ), 1, ( GLboolean )transpose, glm::value_ptr( mat ) );
}

