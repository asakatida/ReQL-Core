cmake_minimum_required(VERSION 2.8.8)

project(ReQL)

add_library(
  ReQL
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
  connection.cpp
  cursor.cpp
  query.cpp
)
