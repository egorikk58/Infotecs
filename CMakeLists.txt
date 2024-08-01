cmake_minimum_required(VERSION 3.30.1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Infotecs)
set(PROJECTS
	Program1_Server
	Program2_Client
)

add_subdirectory(Program1_Server)
add_subdirectory(Program2_Client)


