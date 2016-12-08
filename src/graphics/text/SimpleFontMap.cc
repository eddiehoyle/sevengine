//
// Created by Eddie Hoyle on 7/12/16.
//

#include "SimpleFontMap.hh"


static const glm::vec4 s_charA = glm::vec4( );

SimpleFontMap::SimpleFontMap()
{
    m_map = CharMap();
    m_map.insert( std::pair< char, glm::vec4 >( 'a', glm::vec4( 0.0000, 0.0300, 0.0000, 0.0567 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'b', glm::vec4( 0.0300, 0.0600, 0.0000, 0.0567 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'c', glm::vec4( 0.0600, 0.0900, 0.0000, 0.0567 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'd', glm::vec4( 0.0900, 0.1200, 0.0000, 0.0567 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'e', glm::vec4( 0.1200, 0.1500, 0.0000, 0.0567 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'f', glm::vec4( 0.1500, 0.1800, 0.0000, 0.0567 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'g', glm::vec4( 0.1800, 0.2100, 0.0000, 0.0567 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'h', glm::vec4( 0.2100, 0.2400, 0.0000, 0.0567 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'i', glm::vec4( 0.2400, 0.2700, 0.0000, 0.0567 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'j', glm::vec4( 0.2700, 0.3000, 0.0000, 0.0567 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'k', glm::vec4( 0.3000, 0.3300, 0.0000, 0.0567 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'l', glm::vec4( 0.3300, 0.3600, 0.0000, 0.0567 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'm', glm::vec4( 0.3600, 0.3900, 0.0000, 0.0567 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'n', glm::vec4( 0.3900, 0.4200, 0.0000, 0.0567 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'o', glm::vec4( 0.4200, 0.4500, 0.0000, 0.0567 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'p', glm::vec4( 0.4500, 0.4800, 0.0000, 0.0567 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'q', glm::vec4( 0.4800, 0.5100, 0.0000, 0.0567 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'r', glm::vec4( 0.5100, 0.5400, 0.0000, 0.0567 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 's', glm::vec4( 0.5400, 0.5700, 0.0000, 0.0567 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 't', glm::vec4( 0.5700, 0.6000, 0.0000, 0.0567 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'u', glm::vec4( 0.6000, 0.6300, 0.0000, 0.0567 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'v', glm::vec4( 0.6300, 0.6600, 0.0000, 0.0567 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'w', glm::vec4( 0.6600, 0.6900, 0.0000, 0.0567 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'x', glm::vec4( 0.6900, 0.7200, 0.0000, 0.0567 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'y', glm::vec4( 0.7200, 0.7500, 0.0000, 0.0567 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'z', glm::vec4( 0.7500, 0.7800, 0.0000, 0.0567 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'A', glm::vec4( 0.0000, 0.0300, 0.0567, 0.1133 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'B', glm::vec4( 0.0300, 0.0600, 0.0567, 0.1133 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'C', glm::vec4( 0.0600, 0.0900, 0.0567, 0.1133 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'D', glm::vec4( 0.0900, 0.1200, 0.0567, 0.1133 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'E', glm::vec4( 0.1200, 0.1500, 0.0567, 0.1133 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'F', glm::vec4( 0.1500, 0.1800, 0.0567, 0.1133 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'G', glm::vec4( 0.1800, 0.2100, 0.0567, 0.1133 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'H', glm::vec4( 0.2100, 0.2400, 0.0567, 0.1133 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'I', glm::vec4( 0.2400, 0.2700, 0.0567, 0.1133 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'J', glm::vec4( 0.2700, 0.3000, 0.0567, 0.1133 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'K', glm::vec4( 0.3000, 0.3300, 0.0567, 0.1133 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'L', glm::vec4( 0.3300, 0.3600, 0.0567, 0.1133 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'M', glm::vec4( 0.3600, 0.3900, 0.0567, 0.1133 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'N', glm::vec4( 0.3900, 0.4200, 0.0567, 0.1133 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'O', glm::vec4( 0.4200, 0.4500, 0.0567, 0.1133 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'P', glm::vec4( 0.4500, 0.4800, 0.0567, 0.1133 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'Q', glm::vec4( 0.4800, 0.5100, 0.0567, 0.1133 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'R', glm::vec4( 0.5100, 0.5400, 0.0567, 0.1133 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'S', glm::vec4( 0.5400, 0.5700, 0.0567, 0.1133 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'T', glm::vec4( 0.5700, 0.6000, 0.0567, 0.1133 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'U', glm::vec4( 0.6000, 0.6300, 0.0567, 0.1133 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'V', glm::vec4( 0.6300, 0.6600, 0.0567, 0.1133 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'W', glm::vec4( 0.6600, 0.6900, 0.0567, 0.1133 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'X', glm::vec4( 0.6900, 0.7200, 0.0567, 0.1133 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'Y', glm::vec4( 0.7200, 0.7500, 0.0567, 0.1133 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( 'Z', glm::vec4( 0.7500, 0.7800, 0.0567, 0.1133 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( '0', glm::vec4( 0.0000, 0.0300, 0.1133, 0.1700 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( '1', glm::vec4( 0.0300, 0.0600, 0.1133, 0.1700 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( '2', glm::vec4( 0.0600, 0.0900, 0.1133, 0.1700 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( '3', glm::vec4( 0.0900, 0.1200, 0.1133, 0.1700 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( '4', glm::vec4( 0.1200, 0.1500, 0.1133, 0.1700 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( '5', glm::vec4( 0.1500, 0.1800, 0.1133, 0.1700 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( '6', glm::vec4( 0.1800, 0.2100, 0.1133, 0.1700 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( '7', glm::vec4( 0.2100, 0.2400, 0.1133, 0.1700 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( '8', glm::vec4( 0.2400, 0.2700, 0.1133, 0.1700 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( '9', glm::vec4( 0.2700, 0.3000, 0.1133, 0.1700 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( '!', glm::vec4( 0.0000, 0.0300, 0.1700, 0.2267 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( '"', glm::vec4( 0.0300, 0.0600, 0.1700, 0.2267 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( '#', glm::vec4( 0.0600, 0.0900, 0.1700, 0.2267 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( '$', glm::vec4( 0.0900, 0.1200, 0.1700, 0.2267 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( '%', glm::vec4( 0.1200, 0.1500, 0.1700, 0.2267 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( '&', glm::vec4( 0.1500, 0.1800, 0.1700, 0.2267 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( '\'', glm::vec4( 0.1800, 0.2100, 0.1700, 0.2267 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( '(', glm::vec4( 0.2100, 0.2400, 0.1700, 0.2267 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( ')', glm::vec4( 0.2400, 0.2700, 0.1700, 0.2267 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( '*', glm::vec4( 0.2700, 0.3000, 0.1700, 0.2267 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( '+', glm::vec4( 0.3000, 0.3300, 0.1700, 0.2267 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( ',', glm::vec4( 0.3300, 0.3600, 0.1700, 0.2267 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( '-', glm::vec4( 0.3600, 0.3900, 0.1700, 0.2267 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( '.', glm::vec4( 0.3900, 0.4200, 0.1700, 0.2267 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( '/', glm::vec4( 0.4200, 0.4500, 0.1700, 0.2267 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( '[', glm::vec4( 0.4500, 0.4800, 0.1700, 0.2267 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( '\\', glm::vec4( 0.4800, 0.5100, 0.1700, 0.2267 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( ']', glm::vec4( 0.5100, 0.5400, 0.1700, 0.2267 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( '^', glm::vec4( 0.5400, 0.5700, 0.1700, 0.2267 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( '^', glm::vec4( 0.5700, 0.6000, 0.1700, 0.2267 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( '_', glm::vec4( 0.6000, 0.6300, 0.1700, 0.2267 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( '{', glm::vec4( 0.6300, 0.6600, 0.1700, 0.2267 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( '}', glm::vec4( 0.6600, 0.6900, 0.1700, 0.2267 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( '~', glm::vec4( 0.6900, 0.7200, 0.1700, 0.2267 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( '@', glm::vec4( 0.7200, 0.7500, 0.1700, 0.2267 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( ':', glm::vec4( 0.7500, 0.7800, 0.1700, 0.2267 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( ';', glm::vec4( 0.7800, 0.8100, 0.1700, 0.2267 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( '<', glm::vec4( 0.8100, 0.8400, 0.1700, 0.2267 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( '=', glm::vec4( 0.8400, 0.8700, 0.1700, 0.2267 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( '>', glm::vec4( 0.8700, 0.9000, 0.1700, 0.2267 ) ) );
    m_map.insert( std::pair< char, glm::vec4 >( '?', glm::vec4( 0.9000, 0.9300, 0.1700, 0.2267 ) ) );
}

SimpleFontMap::~SimpleFontMap()
{
    // TODO
}

glm::vec4 SimpleFontMap::getChar( char letter ) {
    CharMap::iterator iter = m_map.find( 'A' );
    if ( iter != m_map.end() ) {
        return iter->second;
    }
    return glm::vec4( 0.0f, 0.0f, 0.0f, 0.0f );
}
