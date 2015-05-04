project(libReQLtest)
cmake_minimum_required(VERSION 2.8)

set(SOURCES
 src/c/ast.c
 src/c/char.c
 src/c/connection.c
 src/c/cursor.c
 src/c/decode.c
 src/c/encode.c
 src/c/error.c
 src/c/expr.c
 src/c/json.c
 src/cpp/ast.cpp
 src/cpp/connection.cpp
 src/cpp/cursor.cpp
 src/cpp/expr.cpp
 src/cpp/new.cpp
 src/cpp/query.cpp
 src/cpp/result.cpp
 src/cpp/wrapper.cpp
 src/ReQL.c
 src/ReQL.cpp
 test/c/connection.cpp
 test/c/decode.cpp
 test/c/encode.cpp
 test/c/expr.cpp
 test/cpp/connection.cpp
 test/test.cpp
)

set(MOC_HEADERS
 src/c/ast.h
 src/c/char.h
 src/c/connection.h
 src/c/cursor.h
 src/c/decode.h
 src/c/encode.h
 src/c/error.h
 src/c/expr.h
 src/c/json.h
 src/c/util/portable_endian.h
 src/cpp/ast.hpp
 src/cpp/connection.hpp
 src/cpp/expr.hpp
 src/cpp/new.hpp
 src/cpp/query.hpp
 src/cpp/result.hpp
 src/cpp/wrapper.hpp
 src/ReQL.h
 src/ReQL.hpp
 test/catch.hpp
 test/test.hpp
)

aux_source_directory(./src SRC_LIST)
add_executable(${PROJECT_NAME} ${SOURCES} ${MOC_SRCS})

list(APPEND CMAKE_C_FLAGS "-std=c11 -fblocks -Isrc -O0 -Weverything -Wno-padded ${CMAKE_C_FLAGS}")
list(APPEND CMAKE_CXX_FLAGS "-std=c++11 -Isrc -Itest -O0 -Weverything -Wno-padded -Wno-exit-time-destructors -Wno-c++98-compat ${CMAKE_CXX_FLAGS}")
