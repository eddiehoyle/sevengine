//
// Created by Eddie Hoyle on 11/09/16.
//

#include "Game.hh"


Game* Game::s_instance = 0;

Game::Game()
    : m_window( NULL ),
      m_inputEventHandler( NULL ),
      m_observerHandler( NULL ),
      m_camera( NULL )
{}

void Game::initialize( int width, int height )
{
    m_window = new Window();
    m_window->update( width, height );

    m_camera = new Camera();
    m_camera->setAspectRatio( m_window->getAspectRatio() );
    m_camera->setWidth( width );
    m_camera->setHeight( height );

    m_inputEventHandler = new InputEventHandler();
    m_observerHandler = new ObserverHandler();
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