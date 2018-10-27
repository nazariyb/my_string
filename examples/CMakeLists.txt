cmake_minimum_required(VERSION 3.5)
project(my_string C)

set(CMAKE_C_STANDARD 99)

link_directories(../library/bin)
add_library(my_string SHARED IMPORTED)

add_executable(examples examples.c)
target_include_directories(examples PUBLIC ../library)
target_link_libraries(examples _my_string)