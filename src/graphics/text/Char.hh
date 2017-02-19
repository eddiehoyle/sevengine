//
// Created by Eddie Hoyle on 14/02/17.
//

#ifndef SEVENGINE_FONT_HH
#define SEVENGINE_FONT_HH

#include <vector>

#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <iostream>


namespace font {

struct Char;

typedef struct std::vector< Char > Chars;

struct Char {

    int id;
    int x, y;
    int width, height;
    int xOffset, yOffset;
    int xAdvance;
    int page;

    glm::vec4 uvs;

    Char() : id( 0 ),
             x( 0 ),
             y( 0 ),
             width( 0 ),
             height( 0 ),
             xOffset( 0 ),
             yOffset( 0 ),
             xAdvance( 0 ),
             page( 0 )
    {}
};

struct CharSet {

    int lineHeight;
    int base;
    int width, height;
    int pages;
    Chars chars;

    CharSet() : lineHeight( 0 ),
                base( 0 ),
                width( 0 ),
                height( 0 ),
                pages( 0 ),
                chars()
    {};

};

Char fromChar( const CharSet& charSet, int code );

void printChar( const Char& _char );

Chars fromString( const CharSet& charSet );

} // namespace text

#endif //SEVENGINE_FONT_HH
