//
// Created by Eddie Hoyle on 8/09/16.
//

#ifndef SEV_CAMERA_HH
#define SEV_CAMERA_HH

#include "Transform.hh"
//#include "Game.hh"

class Camera {

public:

    Camera();
    ~Camera();

    Transform* getTransform() const;
    void setTransform( Transform* transform );
    void setFocalLength( double focal );
    void setAspectRatio( float aspect );

    glm::mat4 getProjectionMatrix();
    glm::mat4 getOrthographicMatrix();

private:

    Transform* m_transform;

    float m_aspect;

};


#endif //SEV_CAMERA_HH
