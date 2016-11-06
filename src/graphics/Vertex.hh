//
// Created by Eddie Hoyle on 5/10/16.
//

#ifndef SEV_VERTEX_HH
#define SEV_VERTEX_HH

#define GL_GLEXT_PROTOTYPES
#include <GLES2/gl2.h>

struct Vertex {

    GLfloat x, y;
    GLfloat u, v;

    void set( GLfloat _x, GLfloat _y, GLfloat _u, GLfloat _v );
};


#endif //SEV_VERTEX_HH
