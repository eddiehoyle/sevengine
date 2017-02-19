//
// Created by Eddie Hoyle on 12/02/17.
//

#ifndef SEVENGINE_ATLASFONTRENDER_HH
#define SEVENGINE_ATLASFONTRENDER_HH


struct AtlasFontBuffer {

};

class AtlasFontRender {

public:

    AtlasFontRender();
    explicit AtlasFontRender( const AtlasFontBuffer& buffer );

    void bind();
    void draw();
    void release();

private:
    AtlasFontBuffer m_buffer;

};


#endif //SEVENGINE_ATLASFONTRENDER_HH
