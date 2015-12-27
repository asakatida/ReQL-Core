cmake_minimum_required(VERSION 2.8)

project(ReQL)

set(SOURCES
 connection.cpp
 cursor.cpp
 query.cpp
)

set(MOC_HEADERS
 core/array.hpp
 core/connection.hpp
 core/decode.hpp
 core/error.hpp
 core/handshake.hpp
 core/null.hpp
 core/object.hpp
 core/protocol.hpp
 core/query.hpp
 core/socket.hpp
 connection.h
 connection.hpp
 cursor.h
 cursor.hpp
 query.h
 query.hpp
 ReQL.h
 ReQL.hpp
 result.hpp
 types.h
)

add_library(ReQL ${SOURCES} ${MOC_HEADERS})

list(APPEND CMAKE_CXX_FLAGS "-std=c++14 -O0 -Werror -Weverything -Wno-padded -Wno-c++98-compat -I. ${CMAKE_CXX_FLAGS}")
