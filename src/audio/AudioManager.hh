//
// Created by Eddie Hoyle on 1/03/17.
//

#ifndef SEVENGINE_AUDIOMANAGER_HH
#define SEVENGINE_AUDIOMANAGER_HH

#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include <OpenAL/al.h>
#include <OpenAL/alc.h>
#include <map>
#include <vector>

void checkALErrors( const char* errLocation );

class AudioManager {

public:
    static AudioManager* instance();

    // https://github.com/dilawar/sound/blob/master/include/wav-def.h#L47
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

/*
 * AudioManager2::instance()->acquire();
 */

// https://github.com/dilawar/sound/blob/master/include/wav-def.h#L47


class AudioSourceWav {

    struct WavHeader {
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
    AudioSourceWav( const std::string& path );
    ~AudioSourceWav();

    ALuint getChannels();
    ALuint getBuffer() const;

private:
    WavHeader* m_header;
    ALuint m_buffer;

};

class AudioManager2 {

    /*
     * On iOS there is a maximum of 32 sound sources playing at one time.
     * So at program start, I create 32 ALSources (the ALSourcePool),
     * and when a new sound needs to play, it asks the Pool for a
     * SoundSource to use.
     */

public:
    static AudioManager2 *instance();
    ~AudioManager2();

    // https://github.com/dilawar/sound/blob/master/include/wav-def.h#L47
    struct WaveHeader {
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
    void play( const AudioSourceWav& source );
    void stop( const AudioSourceWav& source );

private:

    // Acquire a source from pool to bind to buffer
    void acquire( ALuint* source );

    // Restore a source to pool
    void restore( ALuint* source );

private:
    static AudioManager2* m_instance;

    glm::vec2 m_position;
    glm::vec2 m_velocity;

    ALCdevice* m_device;
    ALCcontext* m_context;

    // Available sources
    std::vector< ALuint > m_pool;

    // Sources in use
    std::vector< ALuint > m_activeSources;

private:
    AudioManager2();
    AudioManager2( const AudioManager2& );
    AudioManager2& operator=( const AudioManager2& );

};

#endif //SEVENGINE_AUDIOMANAGER_HH
