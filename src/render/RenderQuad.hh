//
// Created by Eddie Hoyle on 5/10/16.
//

#ifndef SEV_QUADRENDERER_HH
#define SEV_QUADRENDERER_HH

#include "AbstractRender.hh"
#include "Buffer.hh"
#include "Texture.hh"
#include "Quad.hh"

class RenderQuad : public AbstractRender {

public:

    static const unsigned int kVboSize = 256;
    static const unsigned int kEboSize = 256;

    RenderQuad();
    virtual ~RenderQuad();

public:
    virtual void begin();
    virtual void render( Texture* texture, Quad* rect );
    virtual void end();
    virtual void release();

private:
    virtual void flush();

    /// Supports primitive type
    RenderType m_type;

    /// Primitive buffer
    Buffer* m_buffer;

    /// Active texture
    Texture* m_texture;

    Vertex m_vertexBuffer[kVboSize];
    GLushort m_elementBuffer[kEboSize];

    GLint m_vertexIndex;
    GLint m_elementIndex;

};


#endif //SEV_QUADRENDERER_HH
