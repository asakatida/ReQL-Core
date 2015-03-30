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
 src/cpp/expr.cpp
 src/cpp/new.cpp
 src/ReQL.c
 src/ReQL.cpp
 test/c/ast.cpp
 test/c/decode.cpp
 test/c/encode.cpp
 test/c/expr.cpp
 test/cpp/expr.cpp
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
 src/c/util/portable_pthread.h
 src/c/util/util.h
 src/cpp/ast.hpp
 src/cpp/connection.hpp
 src/cpp/expr.hpp
 src/cpp/new.hpp
 src/ReQL.h
 src/ReQL.hpp
 test/catch.hpp
 test/test.hpp
)

aux_source_directory(./src SRC_LIST)
add_executable(${PROJECT_NAME} ${SOURCES} ${MOC_SRCS})

target_compile_features(${PROJECT_NAME} PRIVATE
  c_function_prototypes
  cxx_nullptr
  cxx_rvalue_references
)

target_include_directories(${PROJECT_NAME} PRIVATE
  test
  src
)
