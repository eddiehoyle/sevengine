//
// Created by Eddie Hoyle on 7/02/17.
//

#ifndef SEVENGINE_PARTICLESHADER_HH
#define SEVENGINE_PARTICLESHADER_HH

#include "Shader.hh"

class ParticleShader : public Shader
{

public:
    ParticleShader();
    virtual void enable();
    virtual void disable();

};

#endif //SEVENGINE_PARTICLESHADER_HH
