//
// Created by Eddie Hoyle on 14/02/17.
//

#include <iostream>
#include <vector>
#include "FontParser.hh"
#include "Char.hh"

#define CHECK_XML_STATUS( result )          \
    if ( result != XML_SUCCESS ) {          \
        std::cerr << "XML Error: "          \
                  << result                 \
                  << std::endl;             \
    }                                       \

namespace font {

void load( const std::string& path, CharSet& charSet ) {

    using namespace tinyxml2;
    XMLDocument doc;
    XMLError result = doc.LoadFile( path.c_str() );
    CHECK_XML_STATUS( result );

    // <text> is root
    XMLNode* root = doc.FirstChild();
    if ( !root ) {
        return;
    }

    XMLElement* common = root->FirstChildElement( "common" );
    if ( common ) {
        common->QueryIntAttribute( "lineHeight", &charSet.lineHeight );
        common->QueryIntAttribute( "scaleW", &charSet.width );
        common->QueryIntAttribute( "scaleH", &charSet.height );
        common->QueryIntAttribute( "pages", &charSet.pages );
    }

    XMLElement* character = root->FirstChildElement( "chars" )->FirstChildElement( "char" );

    while ( character ) {

        Char _char;

        character->QueryIntAttribute( "id", &_char.id );
        character->QueryIntAttribute( "x", &_char.x );
        character->QueryIntAttribute( "y", &_char.y );
        character->QueryIntAttribute( "width", &_char.width );
        character->QueryIntAttribute( "height", &_char.height );
        character->QueryIntAttribute( "xOffset", &_char.xOffset );
        character->QueryIntAttribute( "yOffset", &_char.yOffset );
        character->QueryIntAttribute( "xAdvance", &_char.xAdvance );

        // UVs
        float s0 = ( float )_char.x / charSet.width;
        float s1 = ( float )( _char.x + _char.width ) / charSet.width;

        // Note:
        // Image is loaded by soil flipped (invert Y)
        // The 't' coordinates for UVs are subtracted from 1.0 and
        // swapped positions in the vec4 (read up --> down)
        float t0 = 1.0f - ( float )_char.y / charSet.height;
        float t1 = 1.0f - ( float )( _char.y + _char.height ) / charSet.height;
        _char.uvs = glm::vec4( s0, s1, t1, t0 );

        charSet.chars.push_back( _char );

        character = character->NextSiblingElement();
    }
}

}