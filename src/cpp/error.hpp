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

class ReQLError : public std::exception {
public:
  ReQLError(const char *errstr) noexcept;
  virtual const char* what() const noexcept;
  const char *_what;
};

class ReQLQueryError : public ReQLError {
public:
  using ReQLError::ReQLError;
};

class ReQLClientError : public ReQLQueryError {
public:
  using ReQLError::ReQLError;
};

class ReQLCompileError : public ReQLQueryError {
public:
  using ReQLError::ReQLError;
};

class ReQLRuntimeError : public ReQLQueryError {
public:
  using ReQLError::ReQLError;
};

class ReQLCursorEmpty : public ReQLQueryError {
public:
  using ReQLError::ReQLError;
};

class ReQLDriverError : public ReQLError {
public:
  using ReQLError::ReQLError;
};

}  // namespace ReQL

#endif  // REQL_CPP_ERROR_HPP_
