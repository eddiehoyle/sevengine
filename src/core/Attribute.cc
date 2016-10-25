//
// Created by Eddie Hoyle on 23/10/16.
//

#define GL_GLEXT_PROTOTYPES
#include <GLES2/gl2.h>
#include <glm/glm.hpp>

#include "Attribute.hh"

/*
glVertexAttrib1f (GLuint index, GLfloat x);
glVertexAttrib1fv (GLuint index, const GLfloat *v);
glVertexAttrib2f (GLuint index, GLfloat x, GLfloat y);
glVertexAttrib2fv (GLuint index, const GLfloat *v);
glVertexAttrib3f (GLuint index, GLfloat x, GLfloat y, GLfloat z);
glVertexAttrib3fv (GLuint index, const GLfloat *v);
glVertexAttrib4f (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
glVertexAttrib4fv (GLuint index, const GLfloat *v);
 */

GLuint getAttrHandle( GLuint program, const char* name )
{
    return glGetAttribLocation( program, name );
}

GLfloat getAttr( GLuint program, GLuint handle, const char* name )
{
    GLfloat result = 0.0f;
    glVertexAttrib1f( handle, result );
    return result;
}

void getAttr( GLuint program, GLuint handle, const char* name, glm::vec1& vec )
{
    GLfloat* array;
    glVertexAttrib1fv( handle, array );
    vec = glm::vec1( *array );
}

void getAttr( GLuint program, GLuint handle, const char* name, glm::vec2& vec )
{
    GLfloat x, y;
    glVertexAttrib2f( handle, x, y );
    vec = glm::vec2( x, y );
}

void getAttr( GLuint program, GLuint handle, const char* name, glm::vec3& vec )
{
    GLfloat x, y, z;
    glVertexAttrib3f( handle, x, y, z );
    vec = glm::vec3( x, y, z );
}

void getAttr( GLuint program, GLuint handle, const char* name, glm::vec4& vec )
{
    GLfloat x, y, z, w;

    glVertexAttrib4f( handle, x, y, z, w );
    vec = glm::vec4( x, y, z, w );
}

template< typename T >
void setAttr( GLuint handle, GLenum type, GLint size, T* data )
{
    GLboolean normalized = GL_FALSE;
    GLsizei stride = 0;
    glVertexAttribPointer( handle, size, type, normalized, stride, data );
}

