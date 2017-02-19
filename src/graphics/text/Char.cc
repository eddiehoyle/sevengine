//
// Created by Eddie Hoyle on 14/02/17.
//

#include "Char.hh"

namespace font {

Char fromChar( const CharSet& charSet, int id ) {
    for ( Chars::const_iterator iter = charSet.chars.begin();
          iter != charSet.chars.end();
          ++iter ) {
        if ( iter->id == id ) {
            return *iter;
        }
    }
    return Char();
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

void printChar( const Char& _char ) {
    std::cerr
    << "Char(char='" << ( char )_char.id
    << "', id=" << _char.id
    << ", x=" << _char.x
    << ", y=" << _char.y
    << ", width=" << _char.width
    << ", height=" << _char.height
    << ", uvs=" << glm::to_string(_char.uvs)
    << ")" << std::endl;
}

};