//
// Created by Eddie Hoyle on 7/02/17.
//

#include "ParticleShader.hh"

const static GLchar* kAttributePosition = "in_Position";

const static GLuint kIndexPosition = 0;

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

    link( m_program );

    glDeleteShader( vertex );
    glDeleteShader( fragment );
}

void ParticleShader::enable() {

    glEnableVertexAttribArray( kIndexPosition );

    GLsizei stride = sizeof( Vertex );
    glVertexAttribPointer( kIndexPosition, 2, GL_FLOAT, GL_FALSE, stride, BufferOffset(0) );
}

void ParticleShader::disable() {

    glDisableVertexAttribArray( kIndexPosition );
}
