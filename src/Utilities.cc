//
// Created by Eddie Hoyle on 6/08/16.
//

#include <iostream>
#include <vector>
#include <cmath>
#include "Utilities.hh"


void test( std::string x ) {
    // TODO
}

const char* readShaderFile( const char* path )
{
    // Try open the file
    FILE* fp = fopen(path, "r");
    if ( fp == NULL )
    {
        return NULL;
    }

    fseek(fp, 0L, SEEK_END);
    long size = ftell(fp);

    fseek(fp, 0L, SEEK_SET);
    char* buf = new char[size + 1];
    fread(buf, 1, size, fp);

    buf[size] = '\0';
    fclose(fp);

    return buf;
}


GLuint compileShader( const char *path, GLenum type )
{
    GLuint id = glCreateShader( type );
    const char* shader = readShaderFile( path );

    glShaderSource( id, 1, &shader, NULL );
    glCompileShader( id );

    GLint result = GL_FALSE;
    GLsizei length;

    // Check the program
    glGetShaderiv( id, GL_COMPILE_STATUS, &result );
    glGetShaderiv( id, GL_INFO_LOG_LENGTH, &length );
    if ( length > 0 ){
        std::vector< char > log( length + 1 );
        glGetShaderInfoLog( id, length, &length, &log[0] );
        printf( "%s\n", &log[0] );
    } else {
        printf( "Shader compiled succesfully: %d\n", id );
    }

    return id;
}

bool linkProgram( GLuint program, GLuint vertexId, GLuint fragmentId )
{
    // Link the program
    printf("Linking program\n");
    glAttachShader( program, vertexId );
    glAttachShader( program, fragmentId );
    glLinkProgram( program );

    GLint Result = GL_FALSE;
    int InfoLogLength;


    // Check the program
    glGetProgramiv( program, GL_LINK_STATUS, &Result);
    glGetProgramiv( program, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if ( InfoLogLength > 0 ){
        std::vector<char> ProgramErrorMessage(InfoLogLength+1);
        glGetProgramInfoLog(program, InfoLogLength, NULL, &ProgramErrorMessage[0]);
        printf("%s\n", &ProgramErrorMessage[0]);
    }

    glDetachShader( program, vertexId );
    glDetachShader( program, fragmentId );

    glDeleteShader( vertexId );
    glDeleteShader( fragmentId );

    printf( "Program %d linked with shaders [%d, %d] successfully!\n", program, vertexId, fragmentId );
    return true;
}

void checkError() {
    GLenum err = glGetError();

    while( err != GL_NO_ERROR ) {
        std::string error;

        switch( err ) {
            case GL_INVALID_OPERATION:
                error = "INVALID_OPERATION";
                break;
            case GL_INVALID_ENUM:
                error = "INVALID_ENUM";
                break;
            case GL_INVALID_VALUE:
                error = "INVALID_VALUE";
                break;
            case GL_OUT_OF_MEMORY:
                error = "OUT_OF_MEMORY";
                break;
            case GL_INVALID_FRAMEBUFFER_OPERATION:
                error = "INVALID_FRAMEBUFFER_OPERATION";
                break;
            default:
                return;
        }

        std::cerr << "GL_" << error.c_str() <<" - " << std::endl;
        err = glGetError();
    }
}