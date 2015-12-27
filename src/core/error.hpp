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

namespace _ReQL {

enum Error_e {
  CompileError,
  DriverError,
  RuntimeError
};

struct Error_t : public std::exception {
  Error_t(const char *errstr) noexcept;

  Error_t(const Error_e code, const char *errstr) noexcept;

  Error_t(const wchar_t *errstr) noexcept;
  
  Error_t(const Error_e code, const wchar_t *errstr) noexcept;

  virtual const char* what() const noexcept override;

  const wchar_t* wwhat() const noexcept;

  Error_e code() const noexcept;

  bool wide() const noexcept;

  const Error_e _code = DriverError;
  const char *_what;
  const bool _wide = false;
};

Error_t::Error_t(const char *errstr) noexcept :
  _what(errstr) {}

Error_t::Error_t(const Error_e code, const char *errstr) noexcept :
  _code(code),
  _what(errstr) {}

Error_t::Error_t(const wchar_t *errstr) noexcept :
  _what(reinterpret_cast<const char *>(errstr)),
  _wide(true) {}
  
Error_t::Error_t(const Error_e code, const wchar_t *errstr) noexcept :
  _code(code),
  _what(reinterpret_cast<const char *>(errstr)),
  _wide(true) {}

const char *
Error_t::what() const noexcept {
  return _wide ? "unhandled wide error" : _what;
}

const wchar_t *
Error_t::wwhat() const noexcept {
  return _wide ? reinterpret_cast<const wchar_t *>(_what) : L"bad wide error";
}

Error_e
Error_t::code() const noexcept {
  return _code;
}
  
bool
Error_t::wide() const noexcept {
  return _wide;
}

}  // namespace _ReQL

#endif  // REQL_CPP_ERROR_HPP_
