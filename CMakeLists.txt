cmake_minimum_required(VERSION 3.10)

project(MonHealth)

set(CMAKE_CXX_STANDARD 17)

add_executable(MonHealth
    src/main.cpp
    src/cpu.cpp
    src/memory.cpp
    src/process.cpp
)
