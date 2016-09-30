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
    void setWidth( int width ) { m_width = ( float )width; }
    void setHeight( int height ) { m_height = ( float )height; }

    glm::mat4 getPerspectiveMatrix( const unsigned int width, const unsigned int height );
    glm::mat4 getOrthographicMatrix( const unsigned int width, const unsigned int height );

private:

    Transform* m_transform;

    float m_aspect;
    float m_width;
    float m_height;

};


#endif //SEV_CAMERA_HH
