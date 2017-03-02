//
// Created by Eddie Hoyle on 1/03/17.
//

#ifndef SEVENGINE_AUDIOMANAGER_HH
#define SEVENGINE_AUDIOMANAGER_HH

#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include <OpenAL/al.h>
#include <OpenAL/alc.h>

void checkALErrors( const char* errLocation );

class AudioManager {

public:
    static AudioManager* instance();

    struct wave_header_t {
        char riff[4]; //'RIFF'
        unsigned int riffSize;
        char wave[4]; //'WAVE'
        char fmt[4]; //'fmt '
        unsigned int fmtSize;
        unsigned short format;
        unsigned short channels;
        unsigned int samplesPerSec;
        unsigned int bytesPerSec;
        unsigned short blockAlign;
        unsigned short bitsPerSample;
        char data[4]; //'data'
        unsigned int dataSize;
    };

public:
    void play( const std::string& path2 );
    void stop();

private:
    AudioManager();
    AudioManager( const AudioManager& );
    AudioManager& operator=( const AudioManager& );

private:
    static AudioManager* m_instance;

private:
    ALuint m_buffer;
    ALuint m_source;
    glm::vec2 m_position;
    glm::vec2 m_velocity;

    ALCdevice* m_device;
    ALCcontext* m_context;

};


#endif //SEVENGINE_AUDIOMANAGER_HH
