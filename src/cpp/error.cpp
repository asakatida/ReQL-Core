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
ReQLError::what() const noexcept {
  return "ReQLError";
}

ReQLQueryError::ReQLQueryError() {
}

const char*
ReQLQueryError::what() const noexcept {
  return "ReQLQueryError";
}

ReQLClientError::ReQLClientError() {
}

const char*
ReQLClientError::what() const noexcept {
  return "ReQLClientError";
}

ReQLCompileError::ReQLCompileError() {
}

const char*
ReQLCompileError::what() const noexcept {
  return "ReQLCompileError";
}

ReQLRuntimeError::ReQLRuntimeError() {
}

const char*
ReQLRuntimeError::what() const noexcept {
  return "ReQLRuntimeError";
}

ReQLCursorEmpty::ReQLCursorEmpty() {
}

const char*
ReQLCursorEmpty::what() const noexcept {
  return "ReQLCursorEmpty";
}

ReQLDriverError::ReQLDriverError() {
}

const char*
ReQLDriverError::what() const noexcept {
  return "ReQLDriverError";
}

}
