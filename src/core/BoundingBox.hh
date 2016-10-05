//
// Created by Eddie Hoyle on 1/10/16.
//

#ifndef SEV_BOUNDINGBOX_HH
#define SEV_BOUNDINGBOX_HH


#include <vector>
#include <glm/vec3.hpp>

typedef std::vector< glm::vec3 > Vertexes;

class BoundingBox {

public:
    BoundingBox();
    BoundingBox( const Vertexes& vertexes );
    ~BoundingBox();

    void update( const Vertexes& vertexes );
    void extend( const glm::vec3& point );
    glm::vec3 diagonal() const;
    bool intersect( const glm::vec3& point ) const;
    void translate( const glm::vec3& point );
    glm::vec3 center() const;

    glm::vec3 getMin() const;
    glm::vec3 getMax() const;

private:
    glm::vec3 m_min;
    glm::vec3 m_max;

};




#endif //SEV_BOUNDINGBOX_HH
