//
// Created by Eddie Hoyle on 3/10/16.
//

#ifndef SEV_RECT_HH
#define SEV_RECT_HH


#include <OpenGLES/gltypes.h>
#include <vector>
#include <glm/vec2.hpp>
#include <glm/gtx/transform.hpp>

class Quad {

public:
    Quad( const float width, const float height )
    {
        m_a = glm::vec2( width / -2, height / 2 );
        m_b = glm::vec2( width / 2, height / 2 );
        m_c = glm::vec2( width / -2, height / -2 );
        m_d = glm::vec2( width / 2, height / -2 );
    }

    std::vector< GLfloat > flatten() const
    {
        std::vector< GLfloat > result;
        result.push_back( m_d.x );
        result.push_back( m_d.y );
        result.push_back( m_b.x );
        result.push_back( m_b.y );
        result.push_back( m_a.x );
        result.push_back( m_a.y );
        result.push_back( m_d.x );
        result.push_back( m_d.y );
        result.push_back( m_c.x );
        result.push_back( m_c.y );
        result.push_back( m_b.x );
        result.push_back( m_b.y );
        return result;
    }

    std::vector< glm::vec2 > getPoints() const
    {
        std::vector< glm::vec2 > result;
        result.push_back( m_a );
        result.push_back( m_b );
        result.push_back( m_c );
        result.push_back( m_d );
        return result;
    }

    void translate( const glm::vec2& point )
    {
        m_a += point;
        m_b += point;
        m_c += point;
        m_d += point;
    }

private:
    glm::vec2 m_a, m_b;
    glm::vec2 m_c, m_d;

};


#endif //SEV_RECT_HH
