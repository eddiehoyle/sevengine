//
// Created by Eddie Hoyle on 28/08/16.
//

#define GL_GLEXT_PROTOTYPES
#include <GLES2/gl2.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "Shader.hh"

#include <vector>

Shader::Shader()
        : m_program( 0 ),
          m_attributes() {
    m_program = glCreateProgram();
}

Shader::~Shader() {
    glDeleteProgram( m_program );
}

GLuint Shader::getProgram() const {
    return m_program;
}

bool Shader::isValid() const {
    return m_program > 0;
}

void Shader::enable() {
}

void Shader::disable() {
}

Shader::operator bool() const {
    return this->isValid();
}

const AttributeMap& Shader::getAttrs() const {
    return m_attributes;
}

void Shader::addAttr( const std::string& name, GLuint handle ) {
    m_attributes.insert( std::pair< std::string, GLuint >( name, handle ) );
}

GLuint compile( const char* shader, const GLenum type ) {

    // Compile shader
    GLuint id = glCreateShader( type );
    glShaderSource( id, 1, &shader, NULL );
    glCompileShader( id );

    // Check compile result
    GLint result = GL_FALSE;
    glGetShaderiv( id, GL_COMPILE_STATUS, &result );
    if ( result == GL_TRUE ) {
        printf("Shader Compile : Compiled successfully\n");
    } else {
        GLsizei logLength;
        glGetShaderiv( id, GL_INFO_LOG_LENGTH, &logLength );
        if ( logLength )
        {
            char log[logLength - 1];
            glGetShaderInfoLog( id, logLength, &logLength, log );
            printf( "Shader Compile : %s\n", log );
        }
    }
    return id;
}

void link( GLuint program ) {

    // Link the program
    glLinkProgram( program );

    // Check the link status
    GLint linked = GL_FALSE;
    glGetProgramiv( program, GL_LINK_STATUS, &linked );
    if ( linked == GL_TRUE ) {
        printf("Shader Program : Linked successfully\n");
    } else {
        GLint logLength = 0;
        glGetProgramiv( program, GL_INFO_LOG_LENGTH, &logLength );
        if ( logLength > 0 ) {
            GLchar log[logLength - 1];
            glGetProgramInfoLog( program, logLength, NULL, log );
            printf("Shader Program Error: %s\n", log);
            glDeleteProgram( program );
        }
    }
}
