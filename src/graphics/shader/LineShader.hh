//
// Created by Eddie Hoyle on 22/02/17.
//

#ifndef SEVENGINE_LINESHADER_HH
#define SEVENGINE_LINESHADER_HH


#define GL_GLEXT_PROTOTYPES
#include <GLES2/gl2.h>
#include "Shader.hh"

class LineShader : public Shader
{

public:
    LineShader();
    virtual void enable();
    virtual void disable();

};


#endif //SEVENGINE_LINESHADER_HH
