//
// Created by Eddie Hoyle on 7/08/16.
//

#ifndef SEV_ABSTRACTRENDERABLE_HH
#define SEV_ABSTRACTRENDERABLE_HH

#include "Transform.hh"

class AbstractRenderable {

public:

    explicit AbstractRenderable();

    virtual void update() = 0;
    virtual void draw() = 0;

    void setTransform( Transform* transform );
    Transform* getTransform() const;

private:

    Transform* m_transform;

};


#endif //SEV_ABSTRACTRENDERABLE_HH
