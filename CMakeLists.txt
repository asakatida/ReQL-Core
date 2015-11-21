cmake_minimum_required(VERSION 2.8)

project(ReQL)

add_subdirectory(src)
add_subdirectory(test EXCLUDE_FROM_ALL)

enable_testing()
add_test(NAME libReQL COMMAND libReQLtest)

list(APPEND CMAKE_C_FLAGS "-std=c11 -O0 -Werror -Weverything -Wno-padded ${CMAKE_C_FLAGS}")
list(APPEND CMAKE_CXX_FLAGS "-std=c++14 -O0 -Werror -Weverything -Wno-padded ${CMAKE_CXX_FLAGS}")
