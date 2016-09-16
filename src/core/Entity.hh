//
// Created by Eddie Hoyle on 4/09/16.
//

#ifndef SEV_ENTITY_HH
#define SEV_ENTITY_HH

#include "Shader.hh"
#include "Transform.hh"
#include "Model.hh"

// Hmmm
#include "Camera.hh"

class Entity {

public:
    Entity();
    explicit Entity( const char* name, Shader* shader, Model* model );

    Shader* getShader() const;
    Transform* getTransform() const;
    Model* getModel() const;
    void draw( Camera* camera );

private:
    const char* m_name;

    Shader* m_shader;
    Model* m_model;
    Transform* m_transform;


};


#endif //SEV_ENTITY_HH
