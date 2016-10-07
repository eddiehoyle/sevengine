//
// Created by Eddie Hoyle on 5/10/16.
//

#ifndef SEV_QUADRENDERER_HH
#define SEV_QUADRENDERER_HH

#include "AbstractRender.hh"
#include "src/core/graphics/Quad.hh"

class RenderQuad : public AbstractRender {

public:
    RenderQuad();
    virtual ~RenderQuad();

public:
    virtual void begin() {};
    virtual void render( void* Texture, Quad* rect) {};
    virtual void end() {};

private:
    virtual void flush() {};

};


#endif //SEV_QUADRENDERER_HH
