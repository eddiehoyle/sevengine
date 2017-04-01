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
#include <queue>

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


class AudioBuffer {

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
    AudioBuffer( const std::string& path );
    ~AudioBuffer();

    ALuint getBuffer() const;
    ALuint getHandle() const;
    void setHandle( ALuint );

private:
    AudioBuffer( const AudioBuffer& );
    AudioBuffer& operator=( const AudioBuffer& );

private:
    WavHeader* m_header;
    ALuint m_buffer;
    ALuint m_format;

    ALuint m_handle;
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

public:
    void play( const std::string& buffer );
    void stop( const std::string& buffer );

private:

    // Acquire a source from pool to bind to buffer
    void acquire( const std::string& name );

    // Restore a source to pool
    void release( const std::string& name );

private:
    static AudioManager2* m_instance;

    glm::vec2 m_position;
    glm::vec2 m_velocity;

//    std::map< const AudioBuffer&, ALuint > m_bufferMap;

    ALCdevice* m_device;
    ALCcontext* m_context;

    // Available sources
    std::vector< ALuint > m_pool;
    std::queue< ALuint > m_queue;

    std::map< std::string, AudioBuffer* > m_buffers;
    std::map< std::string, ALuint > m_sourceMap;


private:
    AudioManager2();
    AudioManager2( const AudioManager2& );
    AudioManager2& operator=( const AudioManager2& );

};





#endif //SEVENGINE_AUDIOMANAGER_HH
