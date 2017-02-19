//
// Created by Eddie Hoyle on 7/12/16.
//

#include <fstream>

#include "SimpleFontMap.hh"

#include <tinyxml2.h>

static const CharPair kCharALower( 'a', glm::vec4( 0.0000, 0.0300, 0.0000, 0.0567 ) );
static const CharPair kCharBLower( 'b', glm::vec4( 0.0300, 0.0600, 0.0000, 0.0567 ) );
static const CharPair kCharCLower( 'c', glm::vec4( 0.0600, 0.0900, 0.0000, 0.0567 ) );
static const CharPair kCharDLower( 'd', glm::vec4( 0.0900, 0.1200, 0.0000, 0.0567 ) );
static const CharPair kCharELower( 'e', glm::vec4( 0.1200, 0.1500, 0.0000, 0.0567 ) );
static const CharPair kCharFLower( 'f', glm::vec4( 0.1500, 0.1800, 0.0000, 0.0567 ) );
static const CharPair kCharGLower( 'g', glm::vec4( 0.1800, 0.2100, 0.0000, 0.0567 ) );
static const CharPair kCharHLower( 'h', glm::vec4( 0.2100, 0.2400, 0.0000, 0.0567 ) );
static const CharPair kCharILower( 'i', glm::vec4( 0.2400, 0.2700, 0.0000, 0.0567 ) );
static const CharPair kCharJLower( 'j', glm::vec4( 0.2700, 0.3000, 0.0000, 0.0567 ) );
static const CharPair kCharKLower( 'k', glm::vec4( 0.3000, 0.3300, 0.0000, 0.0567 ) );
static const CharPair kCharLLower( 'l', glm::vec4( 0.3300, 0.3600, 0.0000, 0.0567 ) );
static const CharPair kCharMLower( 'm', glm::vec4( 0.3600, 0.3900, 0.0000, 0.0567 ) );
static const CharPair kCharNLower( 'n', glm::vec4( 0.3900, 0.4200, 0.0000, 0.0567 ) );
static const CharPair kCharOLower( 'o', glm::vec4( 0.4200, 0.4500, 0.0000, 0.0567 ) );
static const CharPair kCharPLower( 'p', glm::vec4( 0.4500, 0.4800, 0.0000, 0.0567 ) );
static const CharPair kCharQLower( 'q', glm::vec4( 0.4800, 0.5100, 0.0000, 0.0567 ) );
static const CharPair kCharRLower( 'r', glm::vec4( 0.5100, 0.5400, 0.0000, 0.0567 ) );
static const CharPair kCharSLower( 's', glm::vec4( 0.5400, 0.5700, 0.0000, 0.0567 ) );
static const CharPair kCharTLower( 't', glm::vec4( 0.5700, 0.6000, 0.0000, 0.0567 ) );
static const CharPair kCharULower( 'u', glm::vec4( 0.6000, 0.6300, 0.0000, 0.0567 ) );
static const CharPair kCharVLower( 'v', glm::vec4( 0.6300, 0.6600, 0.0000, 0.0567 ) );
static const CharPair kCharWLower( 'w', glm::vec4( 0.6600, 0.6900, 0.0000, 0.0567 ) );
static const CharPair kCharXLower( 'x', glm::vec4( 0.6900, 0.7200, 0.0000, 0.0567 ) );
static const CharPair kCharYLower( 'y', glm::vec4( 0.7200, 0.7500, 0.0000, 0.0567 ) );
static const CharPair kCharZLower( 'z', glm::vec4( 0.7500, 0.7800, 0.0000, 0.0567 ) );
static const CharPair kCharAUpper( 'A', glm::vec4( 0.0000, 0.0300, 0.0567, 0.1133 ) );
static const CharPair kCharBUpper( 'B', glm::vec4( 0.0300, 0.0600, 0.0567, 0.1133 ) );
static const CharPair kCharCUpper( 'C', glm::vec4( 0.0600, 0.0900, 0.0567, 0.1133 ) );
static const CharPair kCharDUpper( 'D', glm::vec4( 0.0900, 0.1200, 0.0567, 0.1133 ) );
static const CharPair kCharEUpper( 'E', glm::vec4( 0.1200, 0.1500, 0.0567, 0.1133 ) );
static const CharPair kCharFUpper( 'F', glm::vec4( 0.1500, 0.1800, 0.0567, 0.1133 ) );
static const CharPair kCharGUpper( 'G', glm::vec4( 0.1800, 0.2100, 0.0567, 0.1133 ) );
static const CharPair kCharHUpper( 'H', glm::vec4( 0.2100, 0.2400, 0.0567, 0.1133 ) );
static const CharPair kCharIUpper( 'I', glm::vec4( 0.2400, 0.2700, 0.0567, 0.1133 ) );
static const CharPair kCharJUpper( 'J', glm::vec4( 0.2700, 0.3000, 0.0567, 0.1133 ) );
static const CharPair kCharKUpper( 'K', glm::vec4( 0.3000, 0.3300, 0.0567, 0.1133 ) );
static const CharPair kCharLUpper( 'L', glm::vec4( 0.3300, 0.3600, 0.0567, 0.1133 ) );
static const CharPair kCharMUpper( 'M', glm::vec4( 0.3600, 0.3900, 0.0567, 0.1133 ) );
static const CharPair kCharNUpper( 'N', glm::vec4( 0.3900, 0.4200, 0.0567, 0.1133 ) );
static const CharPair kCharOUpper( 'O', glm::vec4( 0.4200, 0.4500, 0.0567, 0.1133 ) );
static const CharPair kCharPUpper( 'P', glm::vec4( 0.4500, 0.4800, 0.0567, 0.1133 ) );
static const CharPair kCharQUpper( 'Q', glm::vec4( 0.4800, 0.5100, 0.0567, 0.1133 ) );
static const CharPair kCharRUpper( 'R', glm::vec4( 0.5100, 0.5400, 0.0567, 0.1133 ) );
static const CharPair kCharSUpper( 'S', glm::vec4( 0.5400, 0.5700, 0.0567, 0.1133 ) );
static const CharPair kCharTUpper( 'T', glm::vec4( 0.5700, 0.6000, 0.0567, 0.1133 ) );
static const CharPair kCharUUpper( 'U', glm::vec4( 0.6000, 0.6300, 0.0567, 0.1133 ) );
static const CharPair kCharVUpper( 'V', glm::vec4( 0.6300, 0.6600, 0.0567, 0.1133 ) );
static const CharPair kCharWUpper( 'W', glm::vec4( 0.6600, 0.6900, 0.0567, 0.1133 ) );
static const CharPair kCharXUpper( 'X', glm::vec4( 0.6900, 0.7200, 0.0567, 0.1133 ) );
static const CharPair kCharYUpper( 'Y', glm::vec4( 0.7200, 0.7500, 0.0567, 0.1133 ) );
static const CharPair kCharZUpper( 'Z', glm::vec4( 0.7500, 0.7800, 0.0567, 0.1133 ) );
static const CharPair kCharDigit0( '0', glm::vec4( 0.0000, 0.0300, 0.1133, 0.1700 ) );
static const CharPair kCharDigit1( '1', glm::vec4( 0.0300, 0.0600, 0.1133, 0.1700 ) );
static const CharPair kCharDigit2( '2', glm::vec4( 0.0600, 0.0900, 0.1133, 0.1700 ) );
static const CharPair kCharDigit3( '3', glm::vec4( 0.0900, 0.1200, 0.1133, 0.1700 ) );
static const CharPair kCharDigit4( '4', glm::vec4( 0.1200, 0.1500, 0.1133, 0.1700 ) );
static const CharPair kCharDigit5( '5', glm::vec4( 0.1500, 0.1800, 0.1133, 0.1700 ) );
static const CharPair kCharDigit6( '6', glm::vec4( 0.1800, 0.2100, 0.1133, 0.1700 ) );
static const CharPair kCharDigit7( '7', glm::vec4( 0.2100, 0.2400, 0.1133, 0.1700 ) );
static const CharPair kCharDigit8( '8', glm::vec4( 0.2400, 0.2700, 0.1133, 0.1700 ) );
static const CharPair kCharDigit9( '9', glm::vec4( 0.2700, 0.3000, 0.1133, 0.1700 ) );
static const CharPair kSymbolExclamation( '!', glm::vec4( 0.0000, 0.0300, 0.1700, 0.2267 ) );
static const CharPair kSymbolDoubleQuote( '"', glm::vec4( 0.0300, 0.0600, 0.1700, 0.2267 ) );
static const CharPair kSymbolHash( '#', glm::vec4( 0.0600, 0.0900, 0.1700, 0.2267 ) );
static const CharPair kSymbolDollar( '$', glm::vec4( 0.0900, 0.1200, 0.1700, 0.2267 ) );
static const CharPair kSymbolPercent( '%', glm::vec4( 0.1200, 0.1500, 0.1700, 0.2267 ) );
static const CharPair kSymbolAmpersand( '&', glm::vec4( 0.1500, 0.1800, 0.1700, 0.2267 ) );
static const CharPair kSymbolSingleBack( '\'', glm::vec4( 0.1800, 0.2100, 0.1700, 0.2267 ) );
static const CharPair kSymbolOpenBracket( '(', glm::vec4( 0.2100, 0.2400, 0.1700, 0.2267 ) );
static const CharPair kSymbolCloseBracket( ')', glm::vec4( 0.2400, 0.2700, 0.1700, 0.2267 ) );
static const CharPair kSymbolAsterisk( '*', glm::vec4( 0.2700, 0.3000, 0.1700, 0.2267 ) );
static const CharPair kSymbolPlus( '+', glm::vec4( 0.3000, 0.3300, 0.1700, 0.2267 ) );
static const CharPair kSymbolComma( ',', glm::vec4( 0.3300, 0.3600, 0.1700, 0.2267 ) );
static const CharPair kSymbolMinus( '-', glm::vec4( 0.3600, 0.3900, 0.1700, 0.2267 ) );
static const CharPair kSymbolDot( '.', glm::vec4( 0.3900, 0.4200, 0.1700, 0.2267 ) );
static const CharPair kSymbolSlashForward( '/', glm::vec4( 0.4200, 0.4500, 0.1700, 0.2267 ) );
static const CharPair kSymbolOpenSquareBracket( '[', glm::vec4( 0.4500, 0.4800, 0.1700, 0.2267 ) );
static const CharPair kSymbolSlashBack( '\\', glm::vec4( 0.4800, 0.5100, 0.1700, 0.2267 ) );
static const CharPair kSymbolCloseSquareBracket( ']', glm::vec4( 0.5100, 0.5400, 0.1700, 0.2267 ) );
static const CharPair kSymbolExponential( '^', glm::vec4( 0.5400, 0.5700, 0.1700, 0.2267 ) );
static const CharPair kSymbolUnderscore( '_', glm::vec4( 0.6000, 0.6300, 0.1700, 0.2267 ) );
static const CharPair kSymbolOpenCurlyBracket( '{', glm::vec4( 0.6300, 0.6600, 0.1700, 0.2267 ) );
static const CharPair kSymbolCloseCurlyBracket( '}', glm::vec4( 0.6600, 0.6900, 0.1700, 0.2267 ) );
static const CharPair kSymbolTilde( '~', glm::vec4( 0.6900, 0.7200, 0.1700, 0.2267 ) );
static const CharPair kSymbolAt( '@', glm::vec4( 0.7200, 0.7500, 0.1700, 0.2267 ) );
static const CharPair kSymbolColon( ':', glm::vec4( 0.7500, 0.7800, 0.1700, 0.2267 ) );
static const CharPair kSymbolSemiColon( ';', glm::vec4( 0.7800, 0.8100, 0.1700, 0.2267 ) );
static const CharPair kSymbolLessThan( '<', glm::vec4( 0.8100, 0.8400, 0.1700, 0.2267 ) );
static const CharPair kSymbolEquals( '=', glm::vec4( 0.8400, 0.8700, 0.1700, 0.2267 ) );
static const CharPair kSymbolGreaterThan( '>', glm::vec4( 0.8700, 0.9000, 0.1700, 0.2267 ) );
static const CharPair kSymbolQuestionMark( '?', glm::vec4( 0.9000, 0.9300, 0.1700, 0.2267 ) );

SimpleFontMap::SimpleFontMap()
        : m_data() {


}

SimpleFontMap::~SimpleFontMap() {
    // TODO
}

glm::vec4 SimpleFontMap::getChar( char letter ) {
    CharMap::iterator iter = m_data.find( letter );
    if ( iter != m_data.end() ) {
        return iter->second;
    }
    return glm::vec4( 0.0f, 0.0f, 0.0f, 0.0f );
}
