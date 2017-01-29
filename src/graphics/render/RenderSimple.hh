//
// Created by Eddie Hoyle on 28/01/17.
//

#ifndef SEVENGINE_RENDERSIMPLE_HH
#define SEVENGINE_RENDERSIMPLE_HH

#include "../buffer/BufferQuad.hh"
#include "../Vertex.hh"

class RenderSimple {

public:

    RenderSimple();
    ~RenderSimple();

    void buffer( const BufferQuad& buffer );
    void bind();
    void draw();
    void release();

private:
    BufferQuad m_buffer;
};


#endif //SEVENGINE_RENDERSIMPLE_HH
