cmake_minimum_required(VERSION 3.5)

# Project
project(sevengine)

# Settings
set(LIB_NAME sev)

# iOS
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -miphoneos-version-min=7.0")

# OSX
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} /usr/local/cmake/modules)

# Output lib
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)

set(SEV_ROOT /Users/eddiehoyle/Code/cpp/game/sevengine)

# External
set(TINYXML2_INCLUDE ${SEV_ROOT}/include/sev/ext/tinyxml2)

# Source files
file(GLOB_RECURSE SOURCE_FILES "*.cc" "*.cpp")

# Dependencies
find_package(OpenGL REQUIRED)
find_package(glew REQUIRED)
find_package(SOIL REQUIRED)
find_package(OpenAL REQUIRED)

include_directories(
        ${SOIL_INCLUDE_DIR}
        ${TINYXML2_INCLUDE}
        ${OPENAL_INCLUDE_DIR}
)
#include_directories(/opt/local/include)
#message(WARNING ${SOIL_INCLUDE_DIR})

# Output
add_library(${LIB_NAME} ${SOURCE_FILES})

target_link_libraries(${LIB_NAME}
        ${OPENGL_LIBRARIES}
        ${SOIL_LIBRARY}
        ${TINYXML2_LIBRARY}
        ${OPENAL_LIBRARY})

# OpenAL
#message(WARNING "OpenAL found: ${OPENAL_FOUND}")
#message(WARNING "OpenAL lib: ${OPENAL_LIBRARY}")
#message(WARNING "OpenAL headers: ${OPENAL_INCLUDE_DIR}")

#message(WARNING ${SOURCE_FILES})