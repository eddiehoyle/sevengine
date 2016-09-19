//
// Created by Eddie Hoyle on 8/09/16.
//

#ifndef SEV_MODEL_HH
#define SEV_MODEL_HH

#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>
#include <vector>

typedef std::vector< GLfloat > Vertexes;

class Model {

public:

    void setVertexes( Vertexes vertexes );
    Vertexes getVertexes() const;

private:
    Vertexes m_vertexes;

};


#endif //SEV_MODEL_HH
