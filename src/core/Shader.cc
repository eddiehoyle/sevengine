//
// Created by Eddie Hoyle on 28/08/16.
//

#include <vector>
#include "Shader.hh"


Shader::Shader()
{}

Shader::Shader( const char* vertex, const char* fragment )
        : m_program( 0 ),
          m_vertex( 0 ),
          m_fragment( 0)
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

void Shader::check( const GLuint &id, const GLenum type )
{
    GLsizei length;
    GLint result = GL_FALSE;

    glGetShaderiv( id, type, &result );
    glGetShaderiv( id, GL_INFO_LOG_LENGTH, &length );

    if ( length > 0 )
    {
        char log[length + 1];
        glGetShaderInfoLog( id, length, &length, log );
        printf( "%s\n", log );
    }
}

GLuint Shader::compile( const char* shader, const GLenum type )
{
    GLuint id = glCreateShader( type );
    glShaderSource( id, 1, &shader, NULL );
    glCompileShader( id );

    // Check status
    check( id, GL_COMPILE_STATUS );

    return id;
}

void Shader::link()
{
    // Link the program
    glAttachShader( m_program, m_vertex );
    glAttachShader( m_program, m_fragment );
    glLinkProgram( m_program );

    check( m_program, GL_LINK_STATUS );

    glDetachShader( m_program, m_vertex );
    glDetachShader( m_program, m_fragment);

    glDeleteShader( m_vertex );
    glDeleteShader( m_fragment );
}

void Shader::setProjectionMatrix( const GLfloat *matrix )
{

    GLuint handle = ( GLuint )glGetUniformLocation( m_program, "projection" );
    GLboolean transpose = GL_FALSE;
    GLsizei count = 1;

    glUniformMatrix4fv( handle, count, transpose, matrix );
}

void Shader::setVertexPosition( const GLfloat* vertexes )
{
    GLuint positionHandle = ( GLuint )glGetAttribLocation( m_program, "position" );

    // Enable a handle to the triangle vertices
    glEnableVertexAttribArray( positionHandle );

    // Number of components per attribute, ie: len([x, y, z]) == 3
    // This is confusing, because the 'position' attribute in the
    // vert shader is vec4, implying a size of 4?
    GLsizei size = 3;

    // Stride simply means the amount of bytes between each vertex.
    // In this case: [[x, y, z], [x, y, z], ...] == [12, 12, ...]
    GLint stride = size * sizeof( GLfloat );

    GLenum type = GL_FLOAT;
    GLboolean normalized = GL_FALSE;

    glVertexAttribPointer( positionHandle, size, type, normalized, stride, vertexes );
}