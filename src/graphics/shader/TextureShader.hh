//
// Created by Eddie Hoyle on 7/01/17.
//

#ifndef SEVENGINE_TEXTURESHADER_HH
#define SEVENGINE_TEXTURESHADER_HH

#include "Shader.hh"

class TextureShader : public Shader
{

public:
    TextureShader();
    virtual void enable();
    virtual void disable();

};

#endif //SEVENGINE_TEXTURESHADER_HH
