//
// Created by Eddie Hoyle on 7/01/17.
//

#include "TextureShader.hh"

const static GLchar* kAttributePosition = "in_Position";
const static GLchar* kAttributeTexture = "in_TextureUV";
const static GLchar* kAttributeColor = "in_Color";

const static GLuint kIndexPosition = 0;
const static GLuint kIndexTexture = 1;
const static GLuint kIndexColor = 2;

TextureShader::TextureShader()
        : Shader() {

    const std::string vertPath = "/Users/eddiehoyle/Code/cpp/game/sevengine/resources/shaders/texture.vert";
    const std::string vertStr = readShaderFile( vertPath );
    GLuint vertex = compile( vertStr.c_str(), GL_VERTEX_SHADER );

    const std::string fragPath = "/Users/eddiehoyle/Code/cpp/game/sevengine/resources/shaders/texture.frag";
    const std::string fragStr = readShaderFile( fragPath );
    GLuint fragment = compile( fragStr.c_str(), GL_FRAGMENT_SHADER );

    glAttachShader( m_program, vertex );
    glAttachShader( m_program, fragment );

    // Bind attributes
    glBindAttribLocation( m_program, kIndexPosition, kAttributePosition );
    glBindAttribLocation( m_program, kIndexTexture, kAttributeTexture );
    glBindAttribLocation( m_program, kIndexColor, kAttributeColor );

    link( m_program );

    glDeleteShader( vertex );
    glDeleteShader( fragment );
}

void TextureShader::enable() {

    glEnableVertexAttribArray( kIndexPosition );
    glEnableVertexAttribArray( kIndexTexture );
    glEnableVertexAttribArray( kIndexColor );

    GLsizei stride = sizeof( Vertex );
    glVertexAttribPointer( kIndexPosition, 2, GL_FLOAT, GL_FALSE, stride, BufferOffset(0) );
    glVertexAttribPointer( kIndexTexture, 2, GL_FLOAT, GL_FALSE, stride, BufferOffset(8) );
    glVertexAttribPointer( kIndexColor, 4, GL_UNSIGNED_BYTE, GL_TRUE, stride, BufferOffset(16) );
}

void TextureShader::disable() {

    glDisableVertexAttribArray( kIndexPosition );
    glDisableVertexAttribArray( kIndexTexture );
    glDisableVertexAttribArray( kIndexColor );
}

