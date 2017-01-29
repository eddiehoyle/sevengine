//
// Created by Eddie Hoyle on 21/01/17.
//

#ifndef SEVENGINE_TEXTUREMANAGER_HH
#define SEVENGINE_TEXTUREMANAGER_HH

#include <map>
#include "Shader.hh"

/*
 * TODO
 * Add a ShaderFactory, this handles all shader creation
 * The ShaderManager will be used to track shaders and their lifetimes
 * Shaders will have types, ids and names
 * ShaderDomain will handle function sets for shaders
 */


class ShaderManager {

    typedef std::map< std::string, Shader* > ShaderMap;
    typedef std::pair< std::string, Shader* > ShaderPair;
    typedef std::vector< Shader* > Shaders;

public:
    static ShaderManager* instance();

public:
    void add( const std::string& id, Shader* shader );
    bool has( const std::string& id ) const;
    void remove( const std::string& id );

public:
    ~ShaderManager();
    void use( const std::string& id );
    void release();
    void enable();
    void disable();

    bool setAttr( const char* name, GLfloat value );
    bool setAttr( const char* name, const glm::vec2& vec );
    bool setAttr( const char* name, const glm::vec3& vec );
    bool setAttr( const char* name, const glm::vec4& vec );

    bool setUnif( const char* name, GLfloat value );
    bool setUnif( const char* name, const glm::vec2& vec );
    bool setUnif( const char* name, const glm::vec3& vec );
    bool setUnif( const char* name, const glm::vec4& vec );
    bool setUnif( const char* name, bool transpose, const glm::mat2& mat );
    bool setUnif( const char* name, bool transpose, const glm::mat3& mat );
    bool setUnif( const char* name, bool transpose, const glm::mat4& mat );

private:
    ShaderManager();
    ShaderManager( const ShaderManager& );
    ShaderManager& operator=( const ShaderManager& );

    Shader* getShader(const std::string &id) const;

    GLint getAttrHandle( const char* name ) const;
    GLint getUnifHandle( const char* name ) const;

private:
    static ShaderManager* m_instance;
    ShaderMap m_shaders;
    ShaderPair m_active;
};


#endif //SEVENGINE_TEXTUREMANAGER_HH
