cmake_minimum_required(VERSION 2.8)

project(ReQL)

set(SOURCES
 cpp/connection.cpp
 cpp/cursor.cpp
 cpp/error.cpp
 cpp/parser.cpp
 cpp/query.cpp
)

set(MOC_HEADERS
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

add_library(ReQL ${SOURCES} ${MOC_HEADERS})

list(APPEND CMAKE_CXX_FLAGS "-std=c++14 -O0 -Werror -Weverything -Wno-padded -Wno-c++98-compat -I. ${CMAKE_CXX_FLAGS}")
