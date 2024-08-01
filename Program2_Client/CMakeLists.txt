cmake_minimum_required(VERSION 3.30.1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Program2_Client)

include_directories(sources)

set(SOURCES
    sources/main.cpp
    sources/client.cpp
    sources/receivehandler.cpp
)

set(HEADERS
    sources/client.h
    sources/receivehandler.h
)

add_executable(Program2_Client ${SOURCES} ${HEADERS})
