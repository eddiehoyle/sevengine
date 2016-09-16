//
// Created by Eddie Hoyle on 8/09/16.
//

#ifndef SEV_CAMERA_HH
#define SEV_CAMERA_HH

#include "Transform.hh"
#include "Game.hh"

class Camera {

public:

    Camera();
//    Camera( unsigned int screenWidth, unsigned int screenHeight );
    ~Camera();

    Transform* getTransform() const;
    void setTransform( Transform* transform );
//    void update( int screenWidth, int screenHeight );
    void setFocalLength( double focal );

    glm::mat4 getProjectionMatrix();
    glm::mat4 getOrthographicMatrix();

private:

    unsigned int m_width;
    unsigned int m_height;
    Transform* m_transform;

};


#endif //SEV_CAMERA_HH
