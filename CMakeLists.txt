cmake_minimum_required(VERSION 3.5)
project(sev)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98 -miphoneos-version-min=7.0")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}
        /usr/local/cmake/modules)

set(SOURCE_FILES
        src/Utilities.cc
        src/Utilities.hh
        src/core/AbstractRenderable.cc
        src/core/AbstractRenderable.hh
        src/core/AbstractApplication.cc
        src/core/AbstractApplication.hh
        src/core/Window.cc
        src/core/Window.hh
        src/core/Transform.cc
        src/core/Transform.hh
        src/Defs.hh.hh
        src/core/Shader.cc
        src/core/Shader.hh
        src/core/Entity.cc
        src/core/Entity.hh
        src/core/Model.cc
        src/core/Model.hh
        src/core/Camera.cc
        src/core/Camera.hh
        src/core/Game.cc
        src/core/Game.hh
        src/core/event/AbstractEvent.cc
        src/core/event/AbstractEvent.hh
        src/core/event/InputEventHandler.cc
        src/core/event/InputEventHandler.hh
        src/core/event/InputEvent.cc
        src/core/event/InputEvent.hh)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)

add_library(sev ${SOURCE_FILES})
target_include_directories(sev
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
        PUBLIC /usr/local/include)
target_link_libraries(sev ${OPENGL_LIBRARIES})