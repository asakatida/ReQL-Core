cmake_minimum_required(VERSION 2.8)

project(lib)

set(SOURCES
 c/connection.c
 c/cursor.c
 c/error.c
 c/query.c
 cpp/connection.cpp
 cpp/cursor.cpp
 cpp/error.cpp
 cpp/parser.cpp
 cpp/query.cpp
)

set(MOC_HEADERS
 c/connection.h
 c/cursor.h
 c/error.h
 c/query.h
 c/types.h
 cpp/connection.hpp
 cpp/cursor.hpp
 cpp/error.hpp
 cpp/parser.hpp
 cpp/query.hpp
 cpp/types.hpp
 reql/btree.hpp
 reql/connection.hpp
 reql/core.hpp
 reql/cursor.hpp
 reql/decode.hpp
 reql/handshake.hpp
 reql/parser.hpp
 reql/pipe.hpp
 reql/protocol.hpp
 reql/query.hpp
 reql/response.hpp
 reql/socket.hpp
 reql/stream.hpp
 reql/string.hpp
 reql/types.hpp
 ReQL.h
 ReQL.hpp
)

add_library(libReQL ${SOURCES} ${MOC_HEADERS})

list(APPEND CMAKE_C_FLAGS "-Isrc ${CMAKE_C_FLAGS}")
list(APPEND CMAKE_CXX_FLAGS "-Isrc ${CMAKE_CXX_FLAGS}")
