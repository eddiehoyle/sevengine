//
// Created by Eddie Hoyle on 7/10/16.
//

#ifndef SEV_RECT_HH
#define SEV_RECT_HH

#include "Vertex.hh"
#include <glm/glm.hpp>

struct Quad {

    explicit Quad( float width, float height );

    void setMatrix( const glm::mat4& matrix );
    void setUV( float sa, float sb, float ta, float tb );

//    void setTranslate( const glm::vec2& vec );
//    void getTranslate() const;

    void set( float width, float height );
    Vertex bl, br, tl, tr;


private:

    // TODO
    void* m_transform;

    glm::vec2 m_translates;
    double m_rotates;
    glm::vec2 m_scales;
};


#endif //SEV_RECT_HH
