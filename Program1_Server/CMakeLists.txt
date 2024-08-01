cmake_minimum_required(VERSION 3.30.1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Program1_Server)

include_directories(sources)

set(SOURCES
    sources/main.cpp
    sources/server.cpp
    sources/inputhandler.cpp
    sources/bufferprocessor.cpp
)

set(HEADERS
    sources/safebuffer.h
    sources/server.h
    sources/inputhandler.h
    sources/bufferprocessor.h
)

add_executable(Program1_Server ${SOURCES} ${HEADERS})
