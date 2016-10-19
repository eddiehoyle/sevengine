//
// Created by Eddie Hoyle on 6/08/16.
//

#ifndef SEV_UTILITIES_HH
#define SEV_UTILITIES_HH

#define GL_GLEXT_PROTOTYPES
#include <GLES2/gl2.h>

#include <iostream>

/// Read and parse a shader file
const char* readShaderFile( const char* path );

GLuint compileShader( const char *path, GLenum type );

bool linkProgram( GLuint program, GLuint vertexId, GLuint fragmentId );

#endif //SEV_UTILITIES_HH


