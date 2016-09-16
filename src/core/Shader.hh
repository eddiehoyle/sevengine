//
// Created by Eddie Hoyle on 28/08/16.
//

#ifndef SEV_SHADER_HH
#define SEV_SHADER_HH

#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>

#include <iostream>

class Shader {

public:

    Shader();
    ~Shader();

    explicit Shader( const char* vertex, const char* fragment );

public:

    void setProjectionMatrix( const GLfloat* matrix );
    void setVertexPosition( const GLfloat* vertices );
    GLuint getProgram() const;

private:

    GLuint compile( const char* shader, GLenum type );
    void check( const GLuint &id, const GLenum type );
    void link();

private:
    GLuint m_program;
    GLuint m_vertex;
    GLuint m_fragment;
};


#endif //SEV_SHADER_HH
