//
// Created by Eddie Hoyle on 28/08/16.
//

#ifndef SEV_SHADER_HH
#define SEV_SHADER_HH
#define GL_GLEXT_PROTOTYPES
#include <GLES2/gl2.h>

#include <iostream>

class Shader {

public:

//    Shader();
//    ~Shader();

    explicit Shader( const char* vertex, const char* fragment );

public:

    GLuint getProgram() const;
    void link();

private:

    GLuint compile( const char* shader, GLenum type );
    void check( const GLuint &id, const GLenum type );

private:
    GLuint m_program;
    GLuint m_other;
    GLuint m_vertex;
    GLuint m_fragment;
};


#endif //SEV_SHADER_HH
