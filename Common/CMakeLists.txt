project("CppTest")
cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

include_directories(.)

file(GLOB_RECURSE all_script FileSystem/*.c)

add_executable(Test 
    CppTest/FileReadTest.c
    ${all_script}
)