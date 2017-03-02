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

    m_device = alcOpenDevice( NULL );
    m_context = alcCreateContext( m_device, NULL );
    alcMakeContextCurrent( m_context );
}

void AudioManager::stop() {
    alSourceStop( m_source );
}

void AudioManager::play( const std::string& path ) {

    // Generate buffers
    alGenBuffers( 1, &m_buffer );
    checkALErrors( "alGenBuffers" );

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

    char* buffer = ( char* )malloc( header->dataSize );
    size_t datasize = fread( buffer, header->dataSize, 1, file );
    fclose(file);


    ALuint format = 0;
    switch ( header->bitsPerSample ) {
        case 8: format = ( header->channels == 1 ) ? AL_FORMAT_MONO8
                                                   : AL_FORMAT_STEREO8;
            break;
        case 16: format = ( header->channels == 1 ) ? AL_FORMAT_MONO16
                                                    : AL_FORMAT_STEREO16;
            break;
        default: printf( "ERROR mono/stereo bad format\n");
            break;
    }

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

