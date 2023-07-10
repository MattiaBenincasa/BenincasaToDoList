cmake_minimum_required(VERSION 3.25)
project(BenincasaToDoList)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(test)

set(SOURCE_FILES time.cpp time.h)
add_executable(BenincasaToDoList main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(BenincasaToDoList core)
