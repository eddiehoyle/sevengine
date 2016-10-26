//
// Created by Eddie Hoyle on 23/10/16.
//

#define GL_GLEXT_PROTOTYPES
#include <GLES2/gl2.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

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

glGetVertexAttribfv (GLuint index, GLenum pname, GLfloat *params);
glGetVertexAttribiv (GLuint index, GLenum pname, GLint *params);
glGetVertexAttribPointerv (GLuint index, GLenum pname, void **pointer);
 */



GLuint getAttrHandle( GLuint program, const char* name )
{
    return glGetAttribLocation( program, name );
}

void setAttr( GLuint program, GLuint handle, const char* name, GLfloat value )
{
    glVertexAttrib1f( handle, value );
}

void setAttr( GLuint program, GLuint handle, const char* name, glm::vec1& vec )
{
    glVertexAttrib1fv( handle, glm::value_ptr( vec ) );
}

void setAttr( GLuint program, GLuint handle, const char* name, glm::vec2& vec )
{
    glVertexAttrib2fv( handle, glm::value_ptr( vec ) );
}

void setAttr( GLuint program, GLuint handle, const char* name, glm::vec3& vec )
{
    glVertexAttrib3fv( handle, glm::value_ptr( vec ) );
}

void setAttr( GLuint program, GLuint handle, const char* name, glm::vec4& vec )
{
    glVertexAttrib4fv( handle, glm::value_ptr( vec ) );
}

template< typename T >
void setAttr( GLuint handle, GLenum type, GLint size, T* data )
{
    GLboolean normalized = GL_FALSE;
    GLsizei stride = 0;
    glVertexAttribPointer( handle, size, type, normalized, stride, data );
}

