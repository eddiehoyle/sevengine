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
#include <map>
#include <set>

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
//
//AudioManager* AudioManager::m_instance = 0;
//
//AudioManager* AudioManager::instance() {
//    if ( m_instance == 0 ) {
//        m_instance = new AudioManager();
//    }
//    return m_instance;
//}
//
//
//AudioManager::AudioManager()
//        : m_device( NULL ),
//          m_context( NULL ) {
//
//    // Get default device
//    m_device = alcOpenDevice( NULL );
//    checkALErrors( "alcOpenDevice()" );
//
//    // Create context
//    m_context = alcCreateContext( m_device, NULL );
//    checkALErrors( "alcOpenDevice()" );
//
//    //
//    alcMakeContextCurrent( m_context );
//    checkALErrors( "alcOpenDevice()" );
//
//}
//
//void AudioManager::stop() {
//    alSourceStop( m_source );
//}
//
//void AudioManager::play( const std::string& path ) {
//
////    // Generate buffers
////    alGenBuffers( 1, &m_buffer );
////    checkALErrors( "alGenBuffers" );
//
//    FILE* file = fopen( path.c_str(), "rb" );
//    if (!file) {
//        printf( "ERROR reading file\n" );
//    }
//
//    wave_header_t* header = ( wave_header_t* )malloc( sizeof( wave_header_t ) );
//    if ( !fread( header, sizeof( wave_header_t ), 1, file ) ) {
//        printf( "ERROR bad file\n" );
//    }
//
//    if ( ( memcmp( "RIFF", header->riff, 4 ) ||
//           memcmp( "WAVE", header->wave, 4 ) ||
//           memcmp( "fmt ", header->fmt, 4 ) ||
//           memcmp( "data", header->data, 4 ) ) ) {
//        printf( "ERROR bad format\n" );
//    }
//
//    std::cerr << "dataSize: " << header->dataSize << std::endl;
//
//    char* buffer = ( char* )malloc( header->dataSize );
//    size_t datasize = fread( buffer, header->dataSize, 1, file );
//    fclose(file);
//
//    ALuint format = 0;
//    switch ( header->bitsPerSample ) {
//        case 8: format = ( header->channels == 1 ) ? AL_FORMAT_MONO8 : AL_FORMAT_STEREO8;
//            break;
//        case 16: format = ( header->channels == 1 ) ? AL_FORMAT_MONO16 : AL_FORMAT_STEREO16;
//            break;
//        default: printf( "ERROR mono/stereo bad format\n");
//            break;
//    }
//
//    // Generate buffers
//    alGenBuffers( 1, &m_buffer );
//    checkALErrors( "alGenBuffers" );
//
//    alBufferData( m_buffer, format, buffer, header->dataSize, header->samplesPerSec );
//    checkALErrors( "alBufferData" );
//    free(buffer);
//    free(header);
//
//    // Generate source
//    alGenSources( 1, &m_source );
//    checkALErrors( "alGenSources" );
//    alSourcef( m_source, AL_PITCH, 1.0f );
//    alSourcef( m_source, AL_GAIN, 1.0f );
//    alSourcei( m_source, AL_BUFFER, m_buffer );
//    alSourcei( m_source, AL_LOOPING, AL_FALSE );
//
//    alSourcePlay( m_source );
//}


// ------------------------------------------------------------------------------------------------------------ //



AudioBuffer::AudioBuffer( const std::string& path )
          : m_buffer( 0 ),
            m_format( 0 ) {

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
    if ( ( memcmp( "RIFF", m_header->riff, 4 ) ||
           memcmp( "WAVE", m_header->wave, 4 ) ||
           memcmp( "fmt ", m_header->fmt, 4 ) ||
           memcmp( "data", m_header->data, 4 ) ) ) {
        printf( "ERROR bad format\n" );
    }

    // Read file into buffer
    char* buffer = new char[m_header->dataSize];
    fread( buffer, m_header->dataSize, 1, file );
    fclose( file );

    // Set format
    m_format = 0;
    switch ( m_header->bitsPerSample ) {
        case 8:
            m_format = ( m_header->channels == 1 ) ? AL_FORMAT_MONO8 : AL_FORMAT_STEREO8;
            break;
        case 16:
            m_format = ( m_header->channels == 1 ) ? AL_FORMAT_MONO16 : AL_FORMAT_STEREO16;
            break;
        default:
            printf( "ERROR mono/stereo bad format\n");
            break;
    }

    // Generate buffers
    alGenBuffers( 1, &m_buffer );
    alBufferData( m_buffer, m_format, buffer, m_header->dataSize, m_header->samplesPerSec );

    // Cleanup
    delete[] buffer;
}

AudioBuffer::~AudioBuffer() {
    alDeleteBuffers( 1, &m_buffer );
    delete m_header;
}

ALuint AudioBuffer::getBuffer() const {
    return m_buffer;
}

ALuint AudioBuffer::getHandle() const {
    return m_handle;
}

void AudioBuffer::setHandle( ALuint handle ) {
    m_handle = handle;
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
          m_bufferMap(),
          m_pool(),
          m_active(),
          m_sourceMap() {

    // Get default device
    m_device = alcOpenDevice( NULL );
    m_context = alcCreateContext( m_device, NULL );
    alcMakeContextCurrent( m_context );

    // Generate sources
    m_pool.reserve( 32 );
//    alGenSources( kMaxSources, &m_pool[0] );
    ALuint sources[32];
    alGenSources( 32, sources );
    m_pool = std::vector< ALuint >( sources, sources + 32 );

    std::cerr << "Sources: ";
    for ( std::size_t i  = 0; i < m_pool.size(); ++i ) {
        std::cerr << m_pool[i] << ", ";
    }
    std::cerr << std::endl;

    const std::string bellPath = "/Users/eddiehoyle/Code/cpp/game/sevengine-workshop/resources/audio/bell.wav";
    AudioBuffer* bell = new AudioBuffer( bellPath );

    const std::string boingPath = "/Users/eddiehoyle/Code/cpp/game/sevengine-workshop/resources/audio/boing.wav";
    AudioBuffer* boing = new AudioBuffer( boingPath );

    m_bufferMap.insert( std::pair< std::string, AudioBuffer* >( "bell", bell ) );
    m_bufferMap.insert( std::pair< std::string, AudioBuffer* >( "boing", boing ) );
}

void AudioManager2::acquire( const std::string& name ) {

    // Does name have a source?
    SourceMapIter findSourceIter = m_sourceMap.find( name );
    if ( findSourceIter != m_sourceMap.end() ) {
        std::cerr << "AudioManager2::acquire() : Found existing source: " << findSourceIter->second << std::endl;
        return;
    }

    ALuint source = 0;

    std::size_t sourcesInUse = m_sourceMap.size();
    std::size_t availableSources = m_pool.size();

    if ( !( sourcesInUse == 0 || availableSources == 0 ) &&
         ( availableSources == sourcesInUse ) ) {

        // All sources in use, need to pop one
        source = m_active.front();
        std::cerr << "Ran out of sources! Popping oldest id: " << source << std::endl;

        for ( SourceMapIter sourceIter = m_sourceMap.begin();
              sourceIter != m_sourceMap.end();
              ++sourceIter ) {

            // Stop source and remove entry
            if ( source == sourceIter->second ) {
                stop( sourceIter->first );
                break;
            }
        }

        // Remove source
        m_active.erase( std::find( m_active.begin(), m_active.end(), source ) );

    } else {

        std::vector< ALuint > inUse;

        // Loop through all sources in use
        for ( SourceMapIter sourceIter = m_sourceMap.begin();
              sourceIter != m_sourceMap.end();
              ++sourceIter ) {
            inUse.push_back( sourceIter->second );
        }

        if ( inUse.empty() ) {
            std::cerr << "AudioManager2::acquire() : First source!" << std::endl;
            // New source! Grab front of pool
            source = m_pool.front();

        } else {

            std::cerr << "AudioManager2::acquire() : Looking for source..." << std::endl;

            for ( std::size_t index = 0; index < m_pool.size(); ++index ) {

//                std::cerr << "AudioManager2::acquire() : Looking for source: " << m_pool[ index ] << std::endl;

                // Check each source in pool if it's in use
                typedef std::vector< ALuint >::iterator PoolIter;
                PoolIter inUseIter = std::find( inUse.begin(), inUse.end(), m_pool[ index ] );

                // Pool source is not in use, we can use it!
                if ( inUseIter == inUse.end() ) {
                    source = m_pool[ index ];
                    break;
                }
            }
        }
    }

    typedef std::map< std::string, AudioBuffer* >::iterator BufferMapIterator;
    BufferMapIterator bufferIter = m_bufferMap.find( name );
    AudioBuffer* bufferPtr = bufferIter->second;

    // Insert into queue
//    m_active.push_back( source );
    m_sourceMap.insert( std::make_pair( name, source ) );

    std::cerr << "AudioManager2::acquire() : Acquired source: " << source << std::endl;
}

void AudioManager2::release( const std::string& name ) {

    // Remove source name
    typedef std::map< std::string, ALuint >::iterator SourceMapIter;
    SourceMapIter sourceIter = m_sourceMap.find( name );
    if ( sourceIter != m_sourceMap.end() ) {

        std::cerr << "AudioManager2::release() : Releasing source: " << sourceIter->second << std::endl;

        // Remove from named map
        m_sourceMap.erase( sourceIter );
    }
}

void AudioManager2::play( const std::string& name ) {

    std::cerr << "AudioManager2::play()" << std::endl;

    SourceMapIter sourceIter = m_sourceMap.find( name );
    if ( sourceIter == m_sourceMap.end() ) {
        std::cerr << "AudioManager2::play() : Not a valid source: " << name << std::endl;
        return;
    }

    BufferMapIter bufferIter = m_bufferMap.find( name );
    if ( bufferIter == m_bufferMap.end() ) {
        std::cerr << "AudioManager2::play() : Not a valid buffer: " << name << std::endl;
        return;
    }

    // Unpack
    ALuint id = sourceIter->second;
    AudioBuffer* buffer = bufferIter->second;

    // Generate source
    alSourcef( id, AL_PITCH, 1.0f );
    alSourcef( id, AL_GAIN, 1.0f );
    alSourcei( id, AL_BUFFER, buffer->getBuffer() );
    alSourcei( id, AL_LOOPING, AL_FALSE );

    alSourcePlay( id );
}

void AudioManager2::stop( const std::string& name ) {

    SourceMapIter sourceIter = m_sourceMap.find( name );
    if ( sourceIter == m_sourceMap.end() ) {
        std::cerr << "AudioManager2::stop() : Not a valid source: " << name << std::endl;
        return;
    }

    std::cerr << "AudioManager2::stop() : Stopping source: " << sourceIter->second << std::endl;

    // Unpack
    ALuint id = sourceIter->second;
    alSourceStop( id );
}

//
//void AudioManager2::acquire( ALuint& source ) {

    //



//    typedef std::vector< ALuint >::const_iterator SourceIterator;
//    typedef std::map< const AudioBuffer&, ALuint >::const_iterator BufferIterator;

//    for ( SourceIterator sourceIter = m_pool.begin();
//          sourceIter != m_pool.end();
//          ++sourceIter ) {
//
//        ALuint checkSource = *sourceIter;
//
//        for ( BufferIterator bufferIter = m_bufferMap.begin();
//              bufferIter != m_bufferMap.end();
//              ++bufferIter ) {
//
//            if ( bufferIter->second == source ) {
//
//            }
//        }
//
//        // Is this source active?
//        SourceIterator activeIter =
//                std::find( m_activeSources.begin(), m_activeSources.end(), checkSource );
//
//        // Found a free source
//        if ( activeIter != m_activeSources.end() ) {
//            m_activeSources.push_back( checkSource );
//            buffer = checkSource;
//        }
//    }
//}

//void AudioManager2::restore( ALuint& source ) {

//    // Is this source active?
//    typedef std::vector< ALuint >::const_iterator SourceIterator;
//    SourceIterator activeIter = std::find( m_activeSources.begin(),
//                                           m_activeSources.end(),
//                                           source );
//
//    // Found a free source
//    if ( activeIter != m_activeSources.end() ) {
//        m_activeSources.erase( activeIter );
//    }
//}


AudioManager2::~AudioManager2() {

    alcMakeContextCurrent( NULL );
    alcDestroyContext( m_context );
    alcCloseDevice( m_device );

    // Clean up
    for ( std::map< std::string, AudioBuffer*>::iterator iter = m_bufferMap.begin();
          iter != m_bufferMap.end();
          ++iter ) {
        delete iter->second;
    }
}

