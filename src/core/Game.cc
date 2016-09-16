//
// Created by Eddie Hoyle on 11/09/16.
//

#include "Game.hh"


Game* Game::s_instance = 0;

Game::Game()
    : m_window( NULL )
{
    m_window = new Window();
    m_inputEventHandler = new InputEventHandler();
}

Game::~Game()
{
    s_instance = NULL;
}

Game* Game::instance()
{
    if ( s_instance == 0 )
    {
        s_instance = new Game();
    }
    return s_instance;
}