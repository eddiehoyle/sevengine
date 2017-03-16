//
// Created by Eddie Hoyle on 1/03/17.
//

#include "AudioManager.hh"
#include <OpenAL/al.h>
#include <OpenAL/alc.h>

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

#include <iostream>
#include <vector>

static const ALuint kMaxSources = 32;

void checkALErrors( const char* errLocation ) {
    ALenum err = alGetError();
    if (err == AL_NO_ERROR)
        return;

    switch(err) {
        case AL_INVALID_NAME: printf("%s: AL_INVALID_NAME\n", errLocation); break;
        case AL_INVALID_ENUM: printf("%s: AL_INVALID_ENUM\n", errLocation); break;
        case AL_INVALID_VALUE: printf("%s: AL_INVALID_VALUE\n", errLocation); break;
        case AL_INVALID_OPERATION: printf("%s: AL_INVALID_OPERATION\n", errLocation); break;
        case AL_OUT_OF_MEMORY: printf("%s: AL_OUT_OF_MEMORY\n", errLocation); break;
        default: printf("%s: UNKNOWN ERROR\n", errLocation); break;
    }
}

AudioManager* AudioManager::m_instance = 0;

AudioManager* AudioManager::instance() {
    if ( m_instance == 0 ) {
        m_instance = new AudioManager();
    }
    return m_instance;
}


AudioManager::AudioManager()
        : m_device( NULL ),
          m_context( NULL ) {

    // Get default device
    m_device = alcOpenDevice( NULL );
    checkALErrors( "alcOpenDevice()" );

    // Create context
    m_context = alcCreateContext( m_device, NULL );
    checkALErrors( "alcOpenDevice()" );

    //
    alcMakeContextCurrent( m_context );
    checkALErrors( "alcOpenDevice()" );

}

void AudioManager::stop() {
    alSourceStop( m_source );
}

void AudioManager::play( const std::string& path ) {

//    // Generate buffers
//    alGenBuffers( 1, &m_buffer );
//    checkALErrors( "alGenBuffers" );

    FILE* file = fopen( path.c_str(), "rb" );
    if (!file) {
        printf( "ERROR reading file\n" );
    }

    wave_header_t* header = ( wave_header_t* )malloc( sizeof( wave_header_t ) );
    if ( !fread( header, sizeof( wave_header_t ), 1, file ) ) {
        printf( "ERROR bad file\n" );
    }

    if ( ( memcmp( "RIFF", header->riff, 4 ) ||
           memcmp( "WAVE", header->wave, 4 ) ||
           memcmp( "fmt ", header->fmt, 4 ) ||
           memcmp( "data", header->data, 4 ) ) ) {
        printf( "ERROR bad format\n" );
    }

    std::cerr << "dataSize: " << header->dataSize << std::endl;

    char* buffer = ( char* )malloc( header->dataSize );
    size_t datasize = fread( buffer, header->dataSize, 1, file );
    fclose(file);

    ALuint format = 0;
    switch ( header->bitsPerSample ) {
        case 8: format = ( header->channels == 1 ) ? AL_FORMAT_MONO8 : AL_FORMAT_STEREO8;
            break;
        case 16: format = ( header->channels == 1 ) ? AL_FORMAT_MONO16 : AL_FORMAT_STEREO16;
            break;
        default: printf( "ERROR mono/stereo bad format\n");
            break;
    }

    // Generate buffers
    alGenBuffers( 1, &m_buffer );
    checkALErrors( "alGenBuffers" );

    alBufferData( m_buffer, format, buffer, header->dataSize, header->samplesPerSec );
    checkALErrors( "alBufferData" );
    free(buffer);
    free(header);

    // Generate source
    alGenSources( 1, &m_source );
    checkALErrors( "alGenSources" );
    alSourcef( m_source, AL_PITCH, 1.0f );
    alSourcef( m_source, AL_GAIN, 1.0f );
    alSourcei( m_source, AL_BUFFER, m_buffer );
    alSourcei( m_source, AL_LOOPING, AL_FALSE );

    alSourcePlay( m_source );
}


// ------------------------------------------------------------------------------------------------------------ //



AudioSourceWav::AudioSourceWav( const std::string& path )
          : m_buffer( 0 ) {

    // Open file
    FILE* file = fopen( path.c_str(), "rb" );
    if ( !file ) {
        printf( "ERROR reading file\n" );
    }

    // Read file into header
    m_header = new WavHeader();
    if ( !fread( m_header, sizeof( WavHeader ), 1, file ) ) {
        printf( "ERROR bad file\n" );
    }

    // Check header is valid wav
    if ( ( strcmp( "RIFF", m_header->riff ) ||
           strcmp( "WAVE", m_header->wave ) ||
           strcmp( "fmt ", m_header->fmt ) ||
           strcmp( "data", m_header->data ) ) ) {
        printf( "ERROR bad format\n" );
    }

    // Read file into buffer
    char* buffer = new char[m_header->dataSize];
    fread( buffer, m_header->dataSize, 1, file );
    fclose( file );

    // Generate buffers
    alGenBuffers( 1, &m_buffer );
    alBufferData( m_buffer, getChannels(), buffer, m_header->dataSize, m_header->samplesPerSec );

    // Cleanup
    delete[] buffer;
}

AudioSourceWav::~AudioSourceWav() {
    delete m_header;
}

ALuint AudioSourceWav::getBuffer() const {
    return m_buffer;
}

ALuint AudioSourceWav::getChannels() {

    ALuint format = 0;
    switch ( m_header->bitsPerSample ) {
        case 8:
            format = ( m_header->channels == 1 ) ? AL_FORMAT_MONO8 : AL_FORMAT_STEREO8;
            break;
        case 16:
            format = ( m_header->channels == 1 ) ? AL_FORMAT_MONO16 : AL_FORMAT_STEREO16;
            break;
        default:
            printf( "ERROR mono/stereo bad format\n");
            break;
    }
    return format;
}


AudioManager2* AudioManager2::m_instance = 0;

AudioManager2* AudioManager2::instance() {
    if ( m_instance == 0 ) {
        m_instance = new AudioManager2();
    }
    return m_instance;
}

AudioManager2::AudioManager2()
        : m_device( NULL ),
          m_context( NULL ),
          m_pool() {

    // Get default device
    m_device = alcOpenDevice( NULL );
    m_context = alcCreateContext( m_device, NULL );
    alcMakeContextCurrent( m_context );

    // Generate sources
    ALuint sources[ kMaxSources ];
    alGenSources( kMaxSources, sources );

    // Store in vector
    m_pool.reserve( kMaxSources );
    std::copy( sources, sources + kMaxSources, std::back_inserter( m_pool ) );
}

void AudioManager2::play( const AudioSourceWav& source ) {

//    ALuint source = 0;
//    acquire( &source );
}

void AudioManager2::stop( const AudioSourceWav& source ) {

}

void AudioManager2::acquire( ALuint* source ) {

    typedef std::vector< ALuint >::const_iterator SourceIterator;
    for ( SourceIterator iter = m_pool.begin();
          iter != m_pool.end();
          ++iter ) {

        ALuint checkSource = *iter;

        // Is this source active?
        SourceIterator activeIter =
                std::find( m_activeSources.begin(), m_activeSources.end(), checkSource );

        // Found a free source
        if ( activeIter != m_activeSources.end() ) {
            m_activeSources.push_back( checkSource );
            *source = checkSource;
        }
    }
}

void AudioManager2::restore( ALuint* source ) {

    // Is this source active?
    typedef std::vector< ALuint >::const_iterator SourceIterator;
    SourceIterator activeIter = std::find( m_activeSources.begin(),
                                           m_activeSources.end(),
                                           *source );

    // Found a free source
    if ( activeIter != m_activeSources.end() ) {
        m_activeSources.erase( activeIter );
    }
}


AudioManager2::~AudioManager2() {

    alcMakeContextCurrent( NULL );
    alcDestroyContext( m_context );
    alcCloseDevice( m_device );
}

