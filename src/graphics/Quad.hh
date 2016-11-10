//
// Created by Eddie Hoyle on 7/10/16.
//

#ifndef SEV_RECT_HH
#define SEV_RECT_HH

#include "Vertex.hh"
#include <glm/glm.hpp>

struct Quad {

    explicit Quad( const int width, const int height );

    void setTranslate( const glm::vec2& vec );
    void getTranslate() const;

    void setRotate( const double rot );
    void getRotate() const;

    void setScale( const glm::vec2& vec );
    void getScale() const;

    void set( float width, float height );
    Vertex bl, br, tl, tr;


private:
    glm::vec2 m_translates;
    double m_rotates;
    glm::vec2 m_scales;
};


#endif //SEV_RECT_HH
