//
// Created by Eddie Hoyle on 8/09/16.
//

#ifndef SEV_MODEL_HH
#define SEV_MODEL_HH

#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>
#include <vector>

#include "BoundingBox.hh"

typedef std::vector< glm::vec3 > Vertexes;
typedef std::vector< GLfloat > FlattenedVertexes;

class Mesh {

public:
    static Vertexes toVertexes( GLfloat* numbers, std::size_t size )
    {
        int count = 0;
        Vertexes vertexes;
        for ( std::size_t index = 0; index < size; index = index + 3 )
        {
            GLfloat x = numbers[count++];
            GLfloat y = numbers[count++];
            GLfloat z = numbers[count++];
            vertexes.push_back( glm::vec3( x, y, z ) );
        }
        printf( "toVert size: %lu\n", vertexes.size() );
        return vertexes;
    }

public:

    Mesh();
    Mesh( const Vertexes& vertexes );
    Mesh( GLfloat numbers[], std::size_t size );
    Mesh( const FlattenedVertexes& vertexes );

    ~Mesh();

    Vertexes getVertexes() const;
    std::vector< GLfloat > flatten() const;
    BoundingBox* getBoundingBox() const;

private:
    Vertexes m_vertexes;
    BoundingBox* m_bbox;

};


#endif //SEV_MODEL_HH
