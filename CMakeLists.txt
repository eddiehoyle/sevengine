cmake_minimum_required(VERSION 3.5)

# Project
project(sevengine)

# Settings
set(LIB_NAME sev)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -miphoneos-version-min=7.0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} /usr/local/cmake/modules)

# Output lib
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)

# Source files
file(GLOB_RECURSE SOURCE_FILES "*.cc" "*.hh")

# Dependencies
find_package(OpenGL REQUIRED)
find_package(glew REQUIRED)

# Output
add_library(${LIB_NAME} ${SOURCE_FILES})
#target_link_libraries(${LIB_NAME} ${OPENGL_LIBRARY})


#target_include_directories(${LIB_NAME}
#        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
#        PUBLIC /usr/local/include)
#
target_link_libraries(${LIB_NAME}
        ${OPENGL_LIBRARIES}
        ${GLEW_LIBRARY})
