//
// Created by Eddie Hoyle on 14/02/17.
//

#include "Glyph.hh"

namespace font {

Glyph fromChar( const CharSet& charSet, char _char ) {
    int id = ( int )_char;
    for ( Chars::const_iterator iter = charSet.chars.begin();
          iter != charSet.chars.end();
          ++iter ) {
        if ( iter->id == id ) {
            return *iter;
        }
    }
    return Glyph();
}

Chars fromString( const CharSet& charSet, const std::string& text ) {

    Chars chars;
    for ( std::string::const_iterator iter = text.begin();
          iter != text.end();
          ++iter ) {
        chars.push_back( fromChar( charSet, ( int )( *iter ) ) );
    }
    return chars;
}

void printChar( const Glyph& glyph ) {
    std::cerr
    << "Char(char='" << ( char )glyph.id
    << "', id=" << glyph.id
    << ", x=" << glyph.x
    << ", y=" << glyph.y
    << ", xAdvance=" << glyph.xAdvance
    << ", width=" << glyph.width
    << ", height=" << glyph.height
    << ", uvs=" << glm::to_string(glyph.uvs)
    << ")" << std::endl;
}

};