//
// Created by Eddie Hoyle on 28/08/16.
//

#include <vector>
#include "Shader.hh"
//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//#include <GLFW/glfw3.h>
//Shader::Shader()
//{}

Shader::Shader( const char* vertex, const char* fragment )
        : m_program( 0 ),
          m_vertex( 0 ),
          m_fragment( 0)
{
    m_program = glCreateProgram();
    m_vertex = compile( vertex, GL_VERTEX_SHADER );
    m_fragment = compile( fragment, GL_FRAGMENT_SHADER );
}

//Shader::~Shader()
//{
//    m_program = 0;
//    m_vertex = 0;
//    m_fragment = 0;
//}

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
    }
}