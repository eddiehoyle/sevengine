//
// Created by Eddie Hoyle on 31/10/16.
//

#include <algorithm>
#include "Block.hh"
#include "../Buffer.hh"
#include "../../Utilities.hh"
#include "../../core/Transform.hh"


TextBlock::TextBlock()
        : m_width( 32 ),
          m_height( 32 ),
          m_text( std::string() ),
          m_matrix( 1.0 ),
          m_glyphScale( 1 ),
          m_spaceScale( 1 ) {
}

void TextBlock::setText( const std::string& text ) {
    m_text = text;
}

void TextBlock::setMatrix( const glm::mat4& mat ) {
    m_matrix = mat;
}

void TextBlock::setGlyphScale( double scale ) {
    m_glyphScale = scale;
}

void TextBlock::setSpaceScale( double scale ) {
    m_spaceScale = scale;
}

void TextBlock::getQuads( const font::CharSet& charSet, Quads& quads ) const {

    Transform transform;

    int numChar = 0;
    int caretX = 0;
    int caretY = 0;

    for ( std::string::const_iterator iter = m_text.begin();
          iter != m_text.end();
          ++iter ) {

        font::Glyph glyph = font::fromChar( charSet, *iter );

        Quad quad( glyph.width * m_glyphScale, glyph.height * m_glyphScale );
        quad.setUV( glyph.uvs[0], glyph.uvs[1], glyph.uvs[2], glyph.uvs[3] );

        int posX = caretX + glyph.xOffset * m_glyphScale;
        int posY = caretY * -1 * m_glyphScale;
        transform.setPosition( posX, posY );

        quad.setMatrix(  transform.getMatrix() * m_matrix );

        quads.push_back( quad );

        // Increment caret
        if ( ( char )glyph.id == ' ' ) {
            caretX += ( glyph.xAdvance * m_glyphScale * m_spaceScale );
        } else {
            caretX += ( glyph.xAdvance * m_glyphScale );
        }

        // Increment character
        ++numChar;

        if ( numChar > m_width ) {

            // Drop down a line
            caretY += charSet.base;

            // Reset line characters
            caretX = 0;
            numChar = 0;
        }
    }
}

void TextBlock::setLineWidth( unsigned int width ) {
    m_width = width;
}


void TextBlock::setLineHeight( unsigned int height ) {
    m_height = height;
}



