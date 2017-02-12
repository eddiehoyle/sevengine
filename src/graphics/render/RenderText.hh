//
// Created by Eddie Hoyle on 31/10/16.
//

#ifndef SEVENGINE_RENDERTEXT_HH
#define SEVENGINE_RENDERTEXT_HH

#include <vector>
#include "../Texture.hh"
#include "../Buffer.hh"
#include "QuadRender.hh"

class RenderText {

public:

    static const unsigned int kVboSize = 1024;   /// Vertex Buffer Object

public:
//    explicit RenderText( Shader* shader );
    RenderText();
    ~RenderText();

public:

    /// Fill buffer with data
    void buffer( const Quad& quad );

    /// Create buffers
    void allocate();

    /// Draw data
    void draw();

    /// Delete buffer
    void release();

private:
    Buffer* m_buffer;
//    Shader* m_shader;

    std::vector< Vertex > m_vertices;
    std::vector< GLfloat > m_translates;
    std::vector< GLuint > m_elements;
    std::vector< GLuint > m_transformeElements;

    GLuint m_vertexIndex;
    GLuint m_elementIndex;

    GLuint m_vbo;
    GLuint m_vao;

};


#endif //SEVENGINE_RENDERTEXT_HH
