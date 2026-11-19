cmake_minimum_required(VERSION 3.10)
project(NumberSystemConversion VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Standalone Executable (Turbo C++ / Dev C++ / CodeBlocks compliant)
add_executable(NumberSystemConverter NumberSystemConverter.cpp)

# 2. Modular Multi-File Suite Executable
include_directories(include)

file(GLOB SOURCES 
    src/*.cpp
)

add_executable(NumberConverter ${SOURCES})
