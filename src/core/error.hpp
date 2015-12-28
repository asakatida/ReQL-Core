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
#include <type_traits>

namespace _ReQL {

enum Error_e {
  CompileError,
  DriverError,
  RuntimeError
};

template <class char_t>
struct Error_t : public std::exception {
  Error_t(const char_t *errstr) noexcept;

  Error_t(const Error_e code, const char_t *errstr) noexcept;

  virtual const char* what() const noexcept override;

  const wchar_t* wwhat() const noexcept;

  Error_e code() const noexcept;

  constexpr static bool wide() noexcept {
    return std::integral_constant<bool, sizeof(char) < sizeof(char_t)>();
  }

  const Error_e _code = DriverError;
  const char_t *_what;
};

template <class char_t>
Error_t<char_t>::Error_t(const char_t *errstr) noexcept :
  _what(errstr) {}
  
template <class char_t>
Error_t<char_t>::Error_t(const Error_e code, const char_t *errstr) noexcept :
  _code(code),
  _what(errstr) {}

template <class char_t>
typename std::enable_if<sizeof(char) == sizeof(char_t), const char *>::value
Error_t<char_t>::what() const noexcept {
  return _what;
}

template <class char_t>
typename std::enable_if<sizeof(char) < sizeof(char_t), const char *>::value
Error_t<char_t>::what() const noexcept {
  return "unhandled wide error";
}

template <class char_t>
const wchar_t *
Error_t<char_t>::wwhat() const noexcept {
  return wide() ? _what : L"bad wide error";
}

template <class char_t>
Error_e
Error_t<char_t>::code() const noexcept {
  return _code;
}

template <class char_t>
void
throw_error(const char_t *errstr) {
  throw Error_t<char_t>(errstr);
}

template <class char_t>
void
throw_error(const Error_e code, const char_t *errstr) {
  throw Error_t<char_t>(code, errstr);
}

}  // namespace _ReQL

#endif  // REQL_CPP_ERROR_HPP_
