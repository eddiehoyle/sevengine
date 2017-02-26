//
// Created by Eddie Hoyle on 31/10/16.
//

#ifndef SEVENGINE_BLOCK_HH
#define SEVENGINE_BLOCK_HH

#include <vector>
#include <zconf.h>
#include "../render/QuadRender.hh"
#include "Glyph.hh"



class TextBlock {

public:

    TextBlock();

    void setText( const std::string& text );
    void getQuads( const font::CharSet& charSet, Quads& quads ) const;
    void setLineWidth( unsigned int width );
    void setLineHeight( unsigned int height );
    void setMatrix( const glm::mat4& mat );
    void setGlyphScale( double scale );
    void setSpaceScale( double scale );

private:
    unsigned int m_width;
    unsigned int m_height;
    std::string m_text;
    glm::mat4 m_matrix;
    double m_glyphScale;
    double m_spaceScale;

};



#endif //SEVENGINE_RENDERTEXT_HH
