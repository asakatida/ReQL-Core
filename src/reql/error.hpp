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

#ifndef REQL_CPP_ERROR_HPP_
#define REQL_CPP_ERROR_HPP_

#include <exception>

namespace ReQL {

struct ReQLError : public std::exception {
  ReQLError(const char *errstr) noexcept :
    _what(errstr) {}

  ReQLError(const wchar_t *errstr) :
    _what(reinterpret_cast<const char *>(errstr)) {}

  virtual const char* what() const noexcept override { return _what; }
  const char *_what;
};

struct ReQLQueryError : public ReQLError {
  using ReQLError::ReQLError;
};

struct ReQLClientError : public ReQLQueryError {
  using ReQLError::ReQLError;
};

struct ReQLCompileError : public ReQLQueryError {
  using ReQLError::ReQLError;
};

struct ReQLRuntimeError : public ReQLQueryError {
  using ReQLError::ReQLError;
};

struct ReQLCursorEmpty : public ReQLQueryError {
  using ReQLError::ReQLError;
};

struct ReQLDriverError : public ReQLError {
  using ReQLError::ReQLError;
};

}  // namespace ReQL

#endif  // REQL_CPP_ERROR_HPP_
