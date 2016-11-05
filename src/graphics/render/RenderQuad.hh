//
// Created by Eddie Hoyle on 31/10/16.
//

#ifndef SEVENGINE_RENDERQUAD_HH
#define SEVENGINE_RENDERQUAD_HH

#include "../Texture.hh"
#include "../Quad.hh"
#include "../Buffer.hh"
#include "../../core/Shader.hh"

class RenderQuad {

public:

    static const unsigned int kVboSize = 256;   /// Vertex Buffer Object
    static const unsigned int kEboSize = 256;   /// Element Buffer Object

public:
    RenderQuad();
    ~RenderQuad();

public:

    /// Fill buffer with data
    void buffer( Texture* texture, Quad* quad, Shader* shader );

    /// Draw data
    void draw();

    /// Delete buffer
    void release();

private:
    Buffer* m_buffer;
    Texture* m_texture;

    Vertex m_vertices[kVboSize];
    GLuint m_elements[kEboSize];

    GLuint m_vertexIndex;
    GLuint m_elementIndex;

};


#endif //SEVENGINE_RENDERQUAD_HH
