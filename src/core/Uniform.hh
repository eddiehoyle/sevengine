//
// Created by Eddie Hoyle on 23/10/16.
//

#ifndef SEVENGINE_UNIFORM_HH
#define SEVENGINE_UNIFORM_HH

#define GL_GLEXT_PROTOTYPES
#include <GLES2/gl2.h>
#include <glm/glm.hpp>
#include <glm/gtc/vec1.hpp>

GLint getUnifHandle( GLuint program, const char* name );
void setUnif( GLuint handle, GLfloat value );
void setUnif( GLuint handle, const glm::vec1& vec );
void setUnif( GLuint handle, const glm::vec2& vec );
void setUnif( GLuint handle, const glm::vec3 &vec );
void setUnif( GLuint handle, const glm::vec4& vec );
void setUnif( GLuint handle, bool transpose, const glm::mat2& mat );
void setUnif( GLuint handle, bool transpose, const glm::mat3& mat );
void setUnif( GLuint handle, bool transpose, const glm::mat4& mat );

#endif //SEVENGINE_UNIFORM_HH
