//
// Created by Eddie Hoyle on 4/09/16.
//

#ifndef SEV_ENTITY_HH
#define SEV_ENTITY_HH

#include "Shader.hh"
#include "Transform.hh"
#include "Model.hh"

#include "event/AbstractEvent.hh"


class Entity {

public:
    Entity();
    virtual ~Entity();

    virtual void draw();
    virtual void listen( AbstractEvent* event );

    Shader* getShader() const;
    Model* getModel() const;
    Transform* getTransform() const;

protected:
    void initializeShader( Shader* shader, Model* model );

private:
    Shader* m_shader;
    Model* m_model;
    Transform* m_transform;

};


#endif //SEV_ENTITY_HH
