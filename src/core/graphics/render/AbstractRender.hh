//
// Created by Eddie Hoyle on 5/10/16.
//

#ifndef SEV_ABSTRACTRENDERER_HH
#define SEV_ABSTRACTRENDERER_HH

#include <cstddef>
#include "../Vertex.hh"
#include "../Buffer.hh"
#include "../../../Defs.hh"
/*
 * class RendererQuad {
  public:
    static const int kAboSize = 256;
    static const int kEboSize = kAboSize + (kAboSize / 2);

    void Init ();
    void Begin ();
    void Render (Texture* texture, float x, float y, float x_end, float y_end, float tex_x, float tex_y, float tex_x_end, float tex_y_end, uchar r, uchar b, uchar g, uchar a);
    void End ();
    void Destroy ();

  private:
    void Flush ();
    Texture* last_texture_;
    Vertex vertex_buffer_ [kAboSize];
    GLushort element_buffer_ [kEboSize];
    int vertex_index_;
    int element_index_;
    BufferObject abo_;
};

}
 */
class AbstractRender {

public:
    virtual ~AbstractRender();

public:
    virtual void begin();
    virtual void render();
    virtual void end();

private:
    virtual void flush();

protected:
    Buffer m_buffer;
    Vertex m_vertexes[256];
    std::size_t m_index;

};


#endif //SEV_ABSTRACTRENDERER_HH
