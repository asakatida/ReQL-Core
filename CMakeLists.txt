cmake_minimum_required(VERSION 2.8.8)

project(ReQL)

set(EXT_PROJECTS_DIR external)

add_subdirectory(src)
add_subdirectory(test EXCLUDE_FROM_ALL)

# Includes Catch in the project:
add_subdirectory(${EXT_PROJECTS_DIR}/catch)
include_directories(${CATCH_INCLUDE_DIR} ${COMMON_INCLUDES})
enable_testing(true)  # Enables unit-testing.

list(APPEND CMAKE_C_FLAGS "-std=c11 -O0 -Werror -Weverything -Wno-padded ${CMAKE_C_FLAGS}")
list(APPEND CMAKE_CXX_FLAGS "-std=c++14 -O0 -Werror -Weverything -Wno-padded ${CMAKE_CXX_FLAGS}")
