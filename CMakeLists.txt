cmake_minimum_required(VERSION 3.16)

project(KILLRUN VERSION 0.2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(KILLRUN
    src/main.cpp
    src/Game.cpp
    src/Player.cpp
    src/Map.cpp
    src/Target.cpp
)

target_include_directories(KILLRUN PRIVATE include)
