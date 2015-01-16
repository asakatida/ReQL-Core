/*
Copyright 2014 Adam Grandquist

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

#include "ReQL-new.hpp"

namespace ReQL {

_ReQL_Op *
_reql_alloc_arr(size_t size) {
  return new _ReQL_Op[size]();
}

_ReQL_Pair
_reql_alloc_pair(size_t size) {
  return new _ReQL_Pair_t[size]();
}

_ReQL_Op
_reql_alloc_term() {
  return new _ReQL_Op_t();
}

_ReQL_Op
_reql_new_array(uint32_t size) {
  _ReQL_Op obj = _reql_alloc_term();
  _ReQL_Op *arr = _reql_alloc_arr(size);
  _reql_array_init(obj, arr, size);
  return obj;
}

_ReQL_Op
_reql_new_bool(bool val) {
  _ReQL_Op obj = _reql_alloc_term();
  _reql_bool_init(obj, val);
  return obj;
}

_ReQL_Op
_reql_new_datum(_ReQL_Op arg) {
  _ReQL_Op obj = _reql_alloc_term();
  _reql_ast_datum(obj, arg, NULL);
  return obj;
}

_ReQL_Op
_reql_new_make_array(_ReQL_Op arg) {
  _ReQL_Op obj = _reql_alloc_term();
  _reql_ast_make_array(obj, arg, NULL);
  return obj;
}

_ReQL_Op
_reql_new_make_obj(_ReQL_Op arg) {
  _ReQL_Op obj = _reql_alloc_term();
  _reql_ast_make_obj(obj, NULL, arg);
  return obj;
}

_ReQL_Op
_reql_new_null() {
  _ReQL_Op obj = _reql_alloc_term();
  _reql_null_init(obj);
  return obj;
}

_ReQL_Op
_reql_new_number(double val) {
  _ReQL_Op obj = _reql_alloc_term();
  _reql_number_init(obj, val);
  return obj;
}

_ReQL_Op
_reql_new_object(uint32_t size) {
  _ReQL_Op obj = _reql_alloc_term();
  _ReQL_Pair pair = _reql_alloc_pair(size);
  _reql_object_init(obj, pair, size);
  return obj;
}

_ReQL_Op
_reql_new_string(std::string val) {
  size_t size = val.size();

  if (size > UINT32_MAX) {
    return NULL;
  }

  uint8_t *str = new uint8_t[size]();

  val.copy((char *)str, size);

  _ReQL_Op obj = _reql_alloc_term();

  _reql_string_init(obj, str, (uint32_t)size, (uint32_t)size);

  return obj;
}

}
