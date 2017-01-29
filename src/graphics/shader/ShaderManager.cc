//
// Created by Eddie Hoyle on 21/01/17.
//

#include "ShaderManager.hh"

// Shaders
#include "TextureShader.hh"

ShaderManager* ShaderManager::m_instance = 0;

ShaderManager* ShaderManager::instance() {
    if ( m_instance == 0 ) {
        m_instance = new ShaderManager();

        // Register
        m_instance->add( "texture", new TextureShader() );
    }
    return m_instance;
}

ShaderManager::ShaderManager()
        : m_shaders( ShaderMap() ),
          m_active( ShaderPair() ) {
}

ShaderManager::~ShaderManager() {

    ShaderMap::iterator iter;
    for ( iter = m_shaders.begin(); iter != m_shaders.end(); iter++ ) {
        Shader* shader = iter->second;
        if ( shader ) {
            delete shader;
        }
    }
    m_shaders.clear();

    if ( m_instance ) {
        delete m_instance;
    }
    m_instance = 0;
}

void ShaderManager::add( const std::string& id, Shader* shader ) {
    m_shaders.insert( ShaderPair( id, shader ) );
}

bool ShaderManager::has( const std::string& id ) const {
    return m_shaders.find( id ) != m_shaders.end();
}

void ShaderManager::remove( const std::string& id ) {
    ShaderMap::iterator iter = m_shaders.find( id );
    if ( iter != m_shaders.end() ) {
        m_shaders.erase( iter );
    }
}

void ShaderManager::use( const std::string& id ) {
    if ( m_active.first == id ) {
        return;
    }
    Shader* shader = getShader( id );
    if ( shader ) {
        glUseProgram( shader->getProgram() );
        m_active = ShaderPair( id, shader );
    }
}

void ShaderManager::release() {
    if ( m_active.second ) {
        glUseProgram( 0 );
        m_active = ShaderPair();
    }
}

void ShaderManager::enable() {
    if ( m_active.second ) {
        m_active.second->enable();
//        const AttributeMap& attributes = m_active.second->getAttrs();
//        AttributeMap::const_iterator iter;
//        for ( iter = attributes.begin(); iter != attributes.end(); iter++ ) {
//            glEnableVertexAttribArray( iter->second );
//        }
    }
}

void ShaderManager::disable() {
    if ( m_active.second ) {
        m_active.second->disable();
//        const AttributeMap& attributes = m_active.second->getAttrs();
//        AttributeMap::const_iterator iter;
//        for ( iter = attributes.begin(); iter != attributes.end(); iter++ ) {
//            glEnableVertexAttribArray( iter->second );
//        }
    }
}

Shader* ShaderManager::getShader(const std::string &id) const {
    ShaderMap::const_iterator iter = m_shaders.find( id );
    if ( iter != m_shaders.end() )
    {
        return iter->second;
    }
    return NULL;
}

GLint ShaderManager::getAttrHandle( const char* name ) const {
    if ( m_active.second ) {
        return glGetAttribLocation( m_active.second->getProgram(), name );
    }
    return -1;
}

GLint ShaderManager::getUnifHandle( const char* name ) const {
    if ( m_active.second ) {
        return glGetUniformLocation( m_active.second->getProgram(), name );
    }
    return -1;
}

bool ShaderManager::setAttr( const char* name, GLfloat value ) {
    GLint handle = getAttrHandle( name );
    if ( handle < 0 ) {
        return false;
    }
    glVertexAttrib1f( ( GLuint )handle, value);
    return true;
}

bool ShaderManager::setAttr( const char* name, const glm::vec2& vec )
{
    GLint handle = getAttrHandle( name );
    if ( handle < 0 ) {
        return false;
    }
    glVertexAttrib2fv( ( GLuint )handle, glm::value_ptr( vec ) );
    return true;
}

bool ShaderManager::setAttr( const char* name, const glm::vec3& vec )
{
    GLint handle = getAttrHandle( name );
    if ( handle < 0 ) {
        return false;
    }
    glVertexAttrib3fv( ( GLuint )handle, glm::value_ptr( vec ) );
    return true;
}

bool ShaderManager::setAttr( const char* name, const glm::vec4& vec )
{
    GLint handle = getAttrHandle( name );
    if ( handle < 0 ) {
        return false;
    }
    glVertexAttrib4fv( ( GLuint )handle, glm::value_ptr( vec ) );
    return true;
}

bool ShaderManager::setUnif( const char* name, GLfloat value ) {
    GLint handle = getUnifHandle( name );
    if ( handle < 0 ) {
        return false;
    }
    glUniform1f( ( GLuint )handle, value );
    return true;
}

bool ShaderManager::setUnif( const char* name, const glm::vec2& vec ) {
    GLint handle = getUnifHandle( name );
    if ( handle < 0 ) {
        return false;
    }
    glUniform2fv( ( GLuint )handle, 1, glm::value_ptr( vec ) );
    return true;
}

bool ShaderManager::setUnif( const char* name, const glm::vec3& vec ) {
    GLint handle = getUnifHandle( name );
    if ( handle < 0 ) {
        return false;
    }
    glUniform3fv( ( GLuint )handle, 1, glm::value_ptr( vec ) );
    return true;
}

bool ShaderManager::setUnif( const char* name, const glm::vec4& vec ) {
    GLint handle = getUnifHandle( name );
    if ( handle < 0 ) {
        return false;
    }
    glUniform4fv( ( GLuint )handle, 1, glm::value_ptr( vec ) );
    return true;
}

bool ShaderManager::setUnif( const char* name, bool transpose, const glm::mat2& mat ) {
    GLint handle = getUnifHandle( name );
    if ( handle < 0 ) {
        return false;
    }
    glUniformMatrix2fv( ( GLuint )handle, 1, ( GLboolean )transpose, glm::value_ptr( mat ) );
    return true;
}

bool ShaderManager::setUnif( const char* name, bool transpose, const glm::mat3& mat ) {
    GLint handle = getUnifHandle( name );
    if ( handle < 0 ) {
        return false;
    }
    glUniformMatrix3fv( ( GLuint )handle, 1, ( GLboolean )transpose, glm::value_ptr( mat ) );
    return true;
}

bool ShaderManager::setUnif( const char* name, bool transpose, const glm::mat4& mat ) {
    GLint handle = getUnifHandle( name );
    if ( handle < 0 ) {
        return false;
    }
    glUniformMatrix4fv( ( GLuint )handle, 1, ( GLboolean )transpose, glm::value_ptr( mat ) );
    return true;
}












