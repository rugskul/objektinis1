cmake_minimum_required(VERSION 3.10)
project(obj)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_C_COMPILER "C:/msys64/mingw64/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/msys64/mingw64/bin/g++.exe")

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(obj ${SOURCES})
