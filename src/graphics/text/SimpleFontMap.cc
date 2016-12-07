//
// Created by Eddie Hoyle on 7/12/16.
//

#include "SimpleFontMap.hh"



SimpleFontMap::SimpleFontMap()
{
    m_map = CharMap();
    m_map.insert( std::pair< char, glm::vec4 >( 'A', glm::vec4( 0.0f, 6.25, 9.765625f, 17.578125f ) ) );
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
