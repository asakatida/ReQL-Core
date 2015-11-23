cmake_minimum_required(VERSION 2.8)

project(ReQL)

add_subdirectory(src)
add_subdirectory(test EXCLUDE_FROM_ALL)

add_custom_target(spec COMMAND ./test/libReQLtest DEPENDS libReQLtest)

list(APPEND CMAKE_C_FLAGS "-std=c11 -O0 -Werror -Weverything -Wno-padded ${CMAKE_C_FLAGS}")
list(APPEND CMAKE_CXX_FLAGS "-std=c++14 -O0 -Werror -Weverything -Wno-padded ${CMAKE_CXX_FLAGS}")
