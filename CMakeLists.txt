cmake_minimum_required(VERSION 3.26)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build/bin)

add_compile_options(-Wall)

project(AOCTWENTYTHREE VERSION 1.0 LANGUAGES CXX)

add_subdirectory(src)
