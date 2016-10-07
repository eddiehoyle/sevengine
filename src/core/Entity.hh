//
// Created by Eddie Hoyle on 4/09/16.
//

#ifndef SEV_ENTITY_HH
#define SEV_ENTITY_HH

#include "Shader.hh"
#include "Transform.hh"
#include "Mesh.hh"
#include "Rect.hh"
#include "BoundingBox.hh"

#include "event/AbstractEvent.hh"


class Entity {

public:
    Entity();
    virtual ~Entity();


    virtual void listen( AbstractEvent* event );
    virtual void update( double elapsed );
    virtual void draw();


    Shader* getShader() const;
    Mesh* getModel() const;
    Transform* getTransform() const;

protected:
    void initializeShader( Shader* shader, Mesh* model );
    void initializeShader( Shader* shader, Quad* rect );

private:
    Shader* m_shader;
    Mesh* m_model;
    Transform* m_transform;
    Quad* m_rect;


};


#endif //SEV_ENTITY_HH
