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

#include "./cpp/error.hpp"

namespace ReQL {

ReQLError::ReQLError() {
}

const char*
ReQLError::what() const _NOEXCEPT {
  return "ReQLError";
}

ReQLQueryError::ReQLQueryError() {
}

const char*
ReQLQueryError::what() const _NOEXCEPT {
  return "ReQLQueryError";
}

ReQLClientError::ReQLClientError() {
}

const char*
ReQLClientError::what() const _NOEXCEPT {
  return "ReQLClientError";
}

ReQLCompileError::ReQLCompileError() {
}

const char*
ReQLCompileError::what() const _NOEXCEPT {
  return "ReQLCompileError";
}

ReQLRuntimeError::ReQLRuntimeError() {
}

const char*
ReQLRuntimeError::what() const _NOEXCEPT {
  return "ReQLRuntimeError";
}

ReQLCursorEmpty::ReQLCursorEmpty() {
}

const char*
ReQLCursorEmpty::what() const _NOEXCEPT {
  return "ReQLCursorEmpty";
}

ReQLDriverError::ReQLDriverError() {
}

const char*
ReQLDriverError::what() const _NOEXCEPT {
  return "ReQLDriverError";
}

}
