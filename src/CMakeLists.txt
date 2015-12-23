cmake_minimum_required(VERSION 2.8)

project(ReQL)

set(SOURCES
)

set(MOC_HEADERS
 reql/connection.hpp
 reql/cursor.hpp
 reql/error.hpp
 reql/query.hpp
 reql/result.hpp
 reql/core/array.hpp
 reql/core/connection.hpp
 reql/core/decode.hpp
 reql/core/handshake.hpp
 reql/core/null.hpp
 reql/core/object.hpp
 reql/core/protocol.hpp
 reql/core/query.hpp
 reql/core/socket.hpp
 ReQL.hpp
)

add_library(ReQL ${SOURCES} ${MOC_HEADERS})

list(APPEND CMAKE_CXX_FLAGS "-std=c++14 -O0 -Werror -Weverything -Wno-padded -Wno-c++98-compat -I. ${CMAKE_CXX_FLAGS}")
