cmake_minimum_required(VERSION 3.17 FATAL_ERROR)
project(lc3vm)

file(GLOB _sources src/*.c)

add_executable(${CMAKE_PROJECT_NAME} ${_sources})