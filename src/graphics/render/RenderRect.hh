//
// Created by Eddie Hoyle on 31/10/16.
//

#ifndef SEVENGINE_RENDERQUAD_HH
#define SEVENGINE_RENDERQUAD_HH

#include <vector>
#include "../Texture.hh"
#include "../Quad.hh"
#include "../Buffer.hh"
#include "../../core/Shader.hh"

class RenderRect {

public:

    static const unsigned int kVboSize = 1024;   /// Vertex Buffer Object

public:
    explicit RenderRect( Shader* shader );
    ~RenderRect();

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
//    Texture* m_texture;
    Shader* m_shader;

    std::vector< Vertex > m_vertices;
    std::vector< GLfloat > m_translates;
    std::vector< GLuint > m_elements;
    std::vector< GLuint > m_transformeElements;

    GLuint m_vertexIndex;
    GLuint m_elementIndex;

    GLuint m_vbo;
    GLuint m_vao;

};


#endif //SEVENGINE_RENDERQUAD_HH
