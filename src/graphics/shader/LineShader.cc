//
// Created by Eddie Hoyle on 22/02/17.
//

#include "LineShader.hh"
#include "../render/QuadRender.hh"

const static GLchar* kAttributePosition = "in_Position";
const static GLchar* kAttributeNormal = "in_Normal";
const static GLchar* kAttributeColor = "in_Color";
const static GLchar* kAttributeWidth = "in_Width";

const static GLuint kIndexPosition = 0;
const static GLuint kIndexNormal = 1;
const static GLuint kIndexColor = 2;
const static GLuint kIndexWidth = 3;

LineShader::LineShader() {

    const std::string vertPath = "/Users/eddiehoyle/Code/cpp/game/sevengine/resources/shaders/line.vert";
    const std::string vertStr = readShaderFile( vertPath );
    GLuint vertex = compile( vertStr.c_str(), GL_VERTEX_SHADER );

    const std::string fragPath = "/Users/eddiehoyle/Code/cpp/game/sevengine/resources/shaders/line.frag";
    const std::string fragStr = readShaderFile( fragPath );
    GLuint fragment = compile( fragStr.c_str(), GL_FRAGMENT_SHADER );

    glAttachShader( m_program, vertex );
    glAttachShader( m_program, fragment );

    // Bind attributes
    glBindAttribLocation( m_program, kIndexPosition, kAttributePosition );
    glBindAttribLocation( m_program, kIndexNormal, kAttributeNormal);
    glBindAttribLocation( m_program, kIndexColor, kAttributeColor );
    glBindAttribLocation( m_program, kIndexWidth, kAttributeWidth );

    link( m_program );

    glDeleteShader( vertex );
    glDeleteShader( fragment );
}

void LineShader::enable() {

    glEnableVertexAttribArray( kIndexPosition );
    glEnableVertexAttribArray( kIndexNormal );
    glEnableVertexAttribArray( kIndexColor );
    glEnableVertexAttribArray( kIndexWidth );

    GLsizei stride = sizeof( Vertex );
    glVertexAttribPointer( kIndexPosition, 2, GL_FLOAT, GL_FALSE, stride, BufferOffset(0) );
    glVertexAttribPointer( kIndexNormal, 2, GL_FLOAT, GL_FALSE, stride, BufferOffset(8) );
    glVertexAttribPointer( kIndexColor, 4, GL_UNSIGNED_BYTE, GL_TRUE, stride, BufferOffset(16) );
    glVertexAttribPointer( kIndexWidth, 1, GL_FLOAT, GL_FALSE, stride, BufferOffset(20) );
}

void LineShader::disable() {

    glDisableVertexAttribArray( kIndexPosition );
    glDisableVertexAttribArray( kIndexNormal );
    glDisableVertexAttribArray( kIndexColor );
    glDisableVertexAttribArray( kIndexWidth );
}


