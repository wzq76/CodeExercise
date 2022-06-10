cmake_minimum_required(VERSION 3.21)
project(CodeExercise)

set(CMAKE_CXX_STANDARD 11)

add_executable(CodeExercise main.cpp)

add_executable(ch02_test wangdao/ch02/ch02_test.cpp)
add_executable(search_test search/search_test.cpp)