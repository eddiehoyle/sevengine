//
// Created by Eddie Hoyle on 28/08/16.
//

#ifndef SEV_ABSTRACTSHADER_HH
#define SEV_ABSTRACTSHADER_HH

#define GL_GLEXT_PROTOTYPES
#include <GLES2/gl2.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "../../Utilities.hh"
#include "../Vertex.hh"

#include <iostream>
#include <map>
#include <vector>

GLuint compile( const char* shader, const GLenum type );
void link( GLuint program );

typedef std::map< std::string, GLuint > AttributeMap;

class Shader {

public:
    GLuint getProgram() const;
    const AttributeMap& getAttrs() const;

    bool isValid() const;
    operator bool() const;

    virtual ~Shader();
    virtual void enable();
    virtual void disable();

protected:
    Shader();
    void addAttr( const std::string &string, GLuint handle );

    GLuint m_program;
    AttributeMap m_attributes;

private:
    Shader( const Shader& );
    Shader& operator=( const Shader& );
};

inline const char* BufferOffset( GLsizei offset ) {
    return ( char* )NULL + offset;
}

//
//class Shader {
//
//public:
//
//    Shader();
//    explicit Shader( const std::string& vertex, const std::string& fragment );
//    ~Shader();
//
//public:
//
//    GLuint getProgram() const;
//    void use();
//    void release();
//
//    bool isValid() const;
//
//    // Attributes
//    void bindAttr( GLuint index, const char* name );
//
//    GLint getAttrHandle( const char* name ) const;
//    void addAttr( const char* name, GLfloat value );
//    void addAttr( const char* name, const glm::vec2& vec );
//    void addAttr( const char* name, const glm::vec3& vec );
//    void addAttr( const char* name, const glm::vec4& vec );
//    void addAttr( const char* name, GLint size, GLenum type,
//                  bool normalized, GLsizei stride, void* data );
//
//    void enableAttr( const char* name );
//    void disableAttr( const char* name );
//
//    void setAttrOffset( const char* name, GLint size, GLenum type,
//                        bool normalized, GLsizei stride, GLsizei offset );
//
//public:
//
//    // Uniforms
//    GLint getUnifHandle( const char* name );
//
//    void setUnif( const char* name, GLfloat value );
//    void setUnif( const char* name, const glm::vec2& vec );
//    void setUnif( const char* name, const glm::vec3 &vec );
//    void setUnif( const char* name, const glm::vec4& vec );
//    void setUnif( const char* name, bool transpose, const glm::mat2& mat );
//    void setUnif( const char* name, bool transpose, const glm::mat3& mat );
//    void setUnif( const char* name, bool transpose, const glm::mat4& mat );
//
//private:
//
//    GLuint compile( const char* shader, GLenum type );
//    void link();
//
//private:
//
//    GLuint m_program;
//    GLuint m_vertex;
//    GLuint m_fragment;
//
//    std::string m_id;
//};


#endif //SEV_SHADER_HH
