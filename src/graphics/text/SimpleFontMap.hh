//
// Created by Eddie Hoyle on 7/12/16.
//

#ifndef SEVENGINE_SIMPLEFONT_HH
#define SEVENGINE_SIMPLEFONT_HH

#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <map>

/*
 * vec4() contains 4 values for now:
 *    x0, x1, y0, y1
 * values are UV coords from bottom left of screen
 */
typedef std::map< char, glm::vec4 > CharMap;

class SimpleFontMap {

public:
    SimpleFontMap();
    ~SimpleFontMap();

    glm::vec4 getChar( char letter );

private:
    CharMap m_map;

    float m_lineATop, m_lineABot;
    float m_lineBTop, m_lineBBot;

};


#endif //SEVENGINE_SIMPLEFONT_HH
