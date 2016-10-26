//
// Created by Eddie Hoyle on 23/10/16.
//

#ifndef SEVENGINE_ATTRIBUTE_HH
#define SEVENGINE_ATTRIBUTE_HH

#define GL_GLEXT_PROTOTYPES
#include <GLES2/gl2.h>
#include <glm/glm.hpp>
#include <glm/gtc/vec1.hpp>

GLuint getAttrHandle( GLuint program, const char* name );

void setAttr( GLuint program, GLuint handle, const char* name, GLfloat value );
void setAttr( GLuint program, GLuint handle, const char* name, glm::vec1& vec );
void setAttr( GLuint program, GLuint handle, const char* name, glm::vec2& vec );
void setAttr( GLuint program, GLuint handle, const char* name, glm::vec3& vec );
void setAttr( GLuint program, GLuint handle, const char* name, glm::vec4& vec );

/// Specify the location and data format of an array of generic vertex
/// attributes for input attribute handle.
///
/// @param handle - Attribute handle.
/// @param type - The data type of each component.
/// @param size - The number of components per attribute, must be 1, 2, 3, or 4.
/// @param data - A pointer to the first component of the first generic
///     vertex attribute in the array.
template< typename T >
void setAttr( GLuint handle, GLenum type, GLint size, T* data );

#endif //SEVENGINE_ATTRIBUTE_HH
