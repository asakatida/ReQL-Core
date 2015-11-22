/*
Copyright 2015 Adam Grandquist

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
 */
/**
 * @author Adam Grandquist
 * @copyright Apache
 */

#ifndef REQL_REQL_TYPES_HPP_
#define REQL_REQL_TYPES_HPP_

#include <cstdint>

namespace _ReQL {

template <class result_t, class str_t>
class Conn_t;

template <class str_t>
class Query_t;

typedef char ReQL_Byte;
typedef std::uint32_t ReQL_Size;
typedef std::uint64_t ReQL_Token;

template <class byte_t>
ReQL_Size
get_size(const byte_t *buf) {
  return (static_cast<ReQL_Size>(buf[0]) << 0) |
         (static_cast<ReQL_Size>(buf[1]) << 8) |
         (static_cast<ReQL_Size>(buf[2]) << 16) |
         (static_cast<ReQL_Size>(buf[3]) << 24);
}

template <class byte_t>
void
make_size(byte_t *buf, const ReQL_Size magic) {
  buf[0] = static_cast<byte_t>((magic >> 0) & 0xFF);
  buf[1] = static_cast<byte_t>((magic >> 8) & 0xFF);
  buf[2] = static_cast<byte_t>((magic >> 16) & 0xFF);
  buf[3] = static_cast<byte_t>((magic >> 24) & 0xFF);
}

template <class byte_t>
ReQL_Token
get_token(const byte_t *buf) {
  return (static_cast<ReQL_Token>(buf[0]) << 0) |
         (static_cast<ReQL_Token>(buf[1]) << 8) |
         (static_cast<ReQL_Token>(buf[2]) << 16) |
         (static_cast<ReQL_Token>(buf[3]) << 24) |
         (static_cast<ReQL_Token>(buf[4]) << 32) |
         (static_cast<ReQL_Token>(buf[5]) << 40) |
         (static_cast<ReQL_Token>(buf[6]) << 48) |
         (static_cast<ReQL_Token>(buf[7]) << 56);
}

template <class byte_t>
void
make_token(byte_t *buf, const ReQL_Token magic) {
  buf[0] = static_cast<byte_t>((magic >> 0) & 0xFF);
  buf[1] = static_cast<byte_t>((magic >> 8) & 0xFF);
  buf[2] = static_cast<byte_t>((magic >> 16) & 0xFF);
  buf[3] = static_cast<byte_t>((magic >> 24) & 0xFF);
  buf[4] = static_cast<byte_t>((magic >> 32) & 0xFF);
  buf[5] = static_cast<byte_t>((magic >> 40) & 0xFF);
  buf[6] = static_cast<byte_t>((magic >> 48) & 0xFF);
  buf[7] = static_cast<byte_t>((magic >> 56) & 0xFF);
}

}  // namespace _ReQL

#endif  // REQL_REQL_TYPES_HPP_
