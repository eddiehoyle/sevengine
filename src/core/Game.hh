//
// Created by Eddie Hoyle on 11/09/16.
//

#ifndef SEV_GAME_HH
#define SEV_GAME_HH

//#include <src/core/observer/ObserverHandler.hh>
#include "Window.hh"
#include "event/InputEventHandler.hh"
#include "observer/ObserverHandler.hh"
#include "Camera.hh"

class Game
{


public:

    static Game* instance();
    ~Game();
    
    void initialize( int width, int height );

    Window* getWindow() { return m_window; }
    InputEventHandler* getInputHandler() { return m_inputEventHandler; }
    ObserverHandler* getObserverHandler() { return m_observerHandler; }
    Camera* getCamera() { return m_camera; }

private:
    static Game *s_instance;
    Game();

    Game( Game const& ) {};
    void operator=( Game const& ) {};

    // Functions to set log_, et. al. ...

//  Log&         getLog()         { return *log_; }
//  FileSystem&  getFileSystem()  { return *fileSystem_; }
//  AudioPlayer& getAudioPlayer() { return *audioPlayer_; }

    Window* m_window;
    InputEventHandler* m_inputEventHandler;
    ObserverHandler* m_observerHandler;
    Camera* m_camera;

//  Log         *log_;
//  FileSystem  *fileSystem_;
//  AudioPlayer *audioPlayer_;
};


#endif //SEV_GAME_HH
