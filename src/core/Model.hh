//
// Created by Eddie Hoyle on 8/09/16.
//

#ifndef SEV_MODEL_HH
#define SEV_MODEL_HH

#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>

class Model {

public:

    void setVertexes( GLfloat* vertexes );
    GLfloat* getVertexes() const;

private:
    GLfloat* m_vertexes;

};


#endif //SEV_MODEL_HH
