//
// Created by Eddie Hoyle on 7/02/17.
//

#define GL_GLEXT_PROTOTYPES
#include <GLES2/gl2.h>

#include "ParticleShader.hh"
#include "../render/RenderParticle.hh"

const static GLchar* kAttributePosition = "in_Position";
const static GLchar* kAttributeColor = "in_Color";
const static GLchar* kAttributeSize = "in_Size";

const static GLuint kIndexPosition = 0;
const static GLuint kIndexColor = 1;
const static GLuint kIndexSize = 2;

ParticleShader::ParticleShader()
        : Shader() {

    const std::string vertPath = "/Users/eddiehoyle/Code/cpp/game/sevengine/resources/shaders/particle.vert";
    const std::string vertStr = readShaderFile( vertPath );
    GLuint vertex = compile( vertStr.c_str(), GL_VERTEX_SHADER );

    const std::string fragPath = "/Users/eddiehoyle/Code/cpp/game/sevengine/resources/shaders/particle.frag";
    const std::string fragStr = readShaderFile( fragPath );
    GLuint fragment = compile( fragStr.c_str(), GL_FRAGMENT_SHADER );

    glAttachShader( m_program, vertex );
    glAttachShader( m_program, fragment );

    // Bind attributes
    glBindAttribLocation( m_program, kIndexPosition, kAttributePosition );
    glBindAttribLocation( m_program, kIndexColor, kAttributeColor );
    glBindAttribLocation( m_program, kIndexSize, kAttributeSize );

    link( m_program );

    glDeleteShader( vertex );
    glDeleteShader( fragment );
}

void ParticleShader::enable() {

    glEnableVertexAttribArray( kIndexPosition );
    glEnableVertexAttribArray( kIndexColor );
    glEnableVertexAttribArray( kIndexSize );

    GLsizei stride = sizeof( Point );
    glVertexAttribPointer( kIndexPosition, 2, GL_FLOAT, GL_FALSE, stride, BufferOffset(0) );
    glVertexAttribPointer( kIndexColor, 4, GL_UNSIGNED_BYTE, GL_TRUE, stride, BufferOffset(8) );
    glVertexAttribPointer( kIndexSize, 1, GL_FLOAT, GL_TRUE, stride, BufferOffset(12) );
}

void ParticleShader::disable() {

    glDisableVertexAttribArray( kIndexPosition );
    glDisableVertexAttribArray( kIndexColor );
    glDisableVertexAttribArray( kIndexSize );
}
