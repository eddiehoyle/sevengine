//
// Created by Eddie Hoyle on 5/10/16.
//

#ifndef SEV_VERTEX_HH
#define SEV_VERTEX_HH

#define GL_GLEXT_PROTOTYPES
#include <GLES2/gl2.h>

#include <glm/glm.hpp>
#include <glm/ext.hpp>

struct Vertex {

    Vertex();

    GLfloat x, y;
    GLfloat s, t;
    GLubyte r, g, b, a;

    void set( GLfloat _x, GLfloat _y, GLfloat _s, GLfloat _t,
              GLubyte _r, GLubyte _g, GLubyte _b, GLubyte _a );
};


#endif //SEV_VERTEX_HH
