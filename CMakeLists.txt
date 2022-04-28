# Works with 3.11 and tested through 3.23
cmake_minimum_required(VERSION 3.11...3.23)

set(CMAKE_CXX_STANDARD 11)


project("Longbridge OpenSDK"
        VERSION 0.1
        DESCRIPTION "Longbridge OpenSDK for C++ User and the Demo"
        LANGUAGES CXX)


IF (WIN32)
    MESSAGE(STATUS "Now is windows")
ELSEIF (APPLE)
    MESSAGE(STATUS "Now is Apple systems.")
ELSEIF (UNIX)
    MESSAGE(STATUS "Now is UNIX-like OS's.")
ENDIF ()

include_directories(include)

# lib source
add_subdirectory(src)

# use lib demo
add_subdirectory(demo)

