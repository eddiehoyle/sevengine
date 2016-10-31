//
// Created by Eddie Hoyle on 31/10/16.
//

#ifndef SEVENGINE_RENDERQUAD_HH
#define SEVENGINE_RENDERQUAD_HH

#include "../Texture.hh"
#include "../Quad.hh"
#include "../Buffer.hh"

class RenderQuad {

public:
    RenderQuad();
    ~RenderQuad();

public:

    /// Create a buffer
    void allocate();

    /// Fill buffer with data
    void buffer( Texture* texture, Quad* quad );

    /// Draw data
    void draw();

    /// Delete buffer
    void release();

private:
    Buffer* m_buffer;

};


#endif //SEVENGINE_RENDERQUAD_HH
