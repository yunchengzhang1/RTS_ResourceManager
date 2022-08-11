cmake_minimum_required(VERSION 3.16)
project(RTS_ResourceManager)

set(CMAKE_CXX_STANDARD 14)

add_executable(RTS_ResourceManager src/main.cpp src/Node.cpp src/Node.h src/Runner.cpp src/Runner.h)
