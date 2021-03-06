cmake_minimum_required(VERSION 3.0)
project (3dGraphics)

macro(use_cxx11)
    if (CMAKE_VERSION VERSION_LESS "3.1")
        if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
            set (CMAKE_CXX_FLAGS "--std=gnu++11 ${CMAKE_CXX_FLAGS}")
        endif ()
    else ()
        set (CMAKE_CXX_STANDARD 11)
    endif ()
endmacro(use_cxx11)

use_cxx11()

# add compiler flags
add_definitions (
    -c
    -Wall
    )

# Header files
file(GLOB_RECURSE HDRS ${3dGraphics_SOURCE_DIR}/src/*.h)

# Source files
file(GLOB_RECURSE SRCS
    ${3dGraphics_SOURCE_DIR}/src/*.cpp
    ${3dGraphics_SOURCE_DIR}/src/*.c
    )

# Define the executable
add_executable(3dGraphics ${HDRS} ${SRCS})

# We need a CMAKE_DIR with some code to find external dependencies
SET(3dGraphics_CMAKE_DIR "${3dGraphics_SOURCE_DIR}/cmake")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${3dGraphics_SOURCE_DIR}/cmake")

#######################################
# LOOK for the packages that we need! #
#######################################

# OpenGL
find_package(OpenGL REQUIRED)

# GLEW
find_package(GLEW REQUIRED)
#INCLUDE(${3dGraphics_CMAKE_DIR}/FindGLEW.cmake)

# SDL2
INCLUDE(${3dGraphics_CMAKE_DIR}/FindSDL2.cmake)

# GLM
INCLUDE(${3dGraphics_CMAKE_DIR}/FindGLM.cmake)

# Define the include DIRs
include_directories(
    ${3dGraphics_SOURCE_DIR}/headers
    ${3dGraphics_SOURCE_DIR}/sources
    ${OPENGL_INCLUDE_DIRS}
    ${GLEW_INCLUDE_DIRS}
    ${SDL2_INCLUDE_DIRS}
    ${GLM_INCLUDE_DIRS}
    )

# Define the link libraries
target_link_libraries( 3dGraphics
    ${OPENGL_LIBRARIES}
    ${GLEW_LIBRARIES}
    ${SDL2_LIBRARIES}
    ${GLM_LIBRARIES}
    )
