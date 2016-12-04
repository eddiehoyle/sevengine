//
// Created by Eddie Hoyle on 28/08/16.
//

#ifndef SEV_TRANSFORM_HH
#define SEV_TRANSFORM_HH

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/vec2.hpp>

class Transform {

public:
    Transform();
    explicit Transform( const glm::vec2& position,
                        float angle,
                        const glm::vec2& scale );
    ~Transform();

    void setPosition( const glm::vec2& position );
    void setPosition( double x, double y );

    void setAngle( double degrees );

    void setScale( const glm::vec2& scale );
    void setScale( double x, double y );

    void setPivot( const glm::vec2& pivot );
    void setPivot( double x, double y );

    glm::vec2 getPosition() const;
    double getAngle() const;
    glm::vec2 getScale() const;
    glm::vec2 getPivot() const;

    glm::mat4 getMatrix();

private:
    glm::vec3 m_position;
    double m_angle;
    glm::vec3 m_scale;
    glm::vec3 m_pivot;

};

#endif //SEV_TRANSFORM_HH
