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

# Source files
file(GLOB_RECURSE SOURCE_FILES "*.cc" "*.hh")

# Dependencies
find_package(OpenGL REQUIRED)
find_package(glew REQUIRED)
find_package(SOIL REQUIRED)

include_directories(${SOIL_INCLUDE_DIR})
#include_directories(/opt/local/include)
#message(WARNING ${SOIL_INCLUDE_DIR})

# Output
add_library(${LIB_NAME} ${SOURCE_FILES} src/graphics/render/RenderQuad.cc src/graphics/render/RenderQuad.hh)

target_link_libraries(${LIB_NAME}
        ${OPENGL_LIBRARIES}
        ${SOIL_LIBRARY}
        ${GLEW_LIBRARY})

#message(WARNING ${SOIL_LIBRARY})
#message(WARNING sdf)