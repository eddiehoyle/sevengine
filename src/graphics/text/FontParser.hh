//
// Created by Eddie Hoyle on 14/02/17.
//

#ifndef SEVENGINE_FONTPARSER_HH
#define SEVENGINE_FONTPARSER_HH

#include "Glyph.hh"
#include "../../ext/tinyxml2/tinyxml2.h"

namespace font {

void load( const std::string& path, CharSet& charSet );

}

#endif //SEVENGINE_FONTPARSER_HH
