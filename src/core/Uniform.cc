//
// Created by Eddie Hoyle on 23/10/16.
//

#include <glm/ext.hpp>
#include "Uniform.hh"


/*
void glUniform1f(GLint location, GLfloat x)
void glUniform1fv(GLint location, GLsizei count, const GLfloat* v)
void glUniform1i(GLint location, GLint x)
void glUniform1iv(GLint location, GLsizei count, const GLint* v)
void glUniform2f(GLint location, GLfloat x, GLfloat y)
void glUniform2fv(GLint location, GLsizei count, const GLfloat* v)
void glUniform2i(GLint location, GLint x, GLint y)
void glUniform2iv(GLint location, GLsizei count, const GLint* v)
void glUniform3f(GLint location, GLfloat x, GLfloat y, GLfloat z)
void glUniform3fv(GLint location, GLsizei count, const GLfloat* v)
void glUniform3i(GLint location, GLint x, GLint y, GLint z)
void glUniform3iv(GLint location, GLsizei count, const GLint* v)
void glUniform4f(GLint location, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void glUniform4fv(GLint location, GLsizei count, const GLfloat* v)
void glUniform4i(GLint location, GLint x, GLint y, GLint z, GLint w)
void glUniform4iv(GLint location, GLsizei count, const GLint* v)
void glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)
void glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)
void glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)
 */

GLint getUnifHandle( GLuint program, const char *name )
{
    return glGetUniformLocation( program, name );
}

void setUnif( GLuint handle, GLfloat value )
{
    glUniform1f( handle, value );
}

void setUnif( GLuint handle, const glm::vec1& vec )
{
    glUniform2fv( handle, 1, glm::value_ptr( vec ) );
}

void setUnif( GLuint handle, const glm::vec2& vec )
{
    glUniform2fv( handle, 1, glm::value_ptr( vec ) );
}

void setUnif( GLuint handle, const glm::vec3 &vec )
{
    glUniform3fv( handle, 1, glm::value_ptr( vec ) );
}

void setUnif( GLuint handle, const glm::vec4& vec )
{
    glUniform4fv( handle, 1, glm::value_ptr( vec ) );
}

void setUnif( GLuint handle, bool transpose, const glm::mat2& mat )
{
    glUniformMatrix2fv( handle, 1, ( GLboolean )transpose, glm::value_ptr( mat ) );
}

void setUnif( GLuint handle, bool transpose, const glm::mat3& mat )
{
    glUniformMatrix3fv( handle, 1, ( GLboolean )transpose, glm::value_ptr( mat ) );
}

void setUnif( GLuint handle, bool transpose, const glm::mat4& mat )
{
    glUniformMatrix4fv( handle, 1, ( GLboolean )transpose, glm::value_ptr( mat ) );
}
