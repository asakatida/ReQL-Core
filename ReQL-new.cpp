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

#include <cstddef>
#include <cstdint>

namespace ReQL {

_ReQL_Obj_t **
_reql_alloc_arr(size_t size) {
  return new _ReQL_Obj_t *[size]();
}

_ReQL_Pair_t *
_reql_alloc_pair(size_t size) {
  return new _ReQL_Pair_t[size]();
}

_ReQL_Obj_t *
_reql_alloc_term() {
  return new _ReQL_Obj_t();
}

_ReQL_Obj_t *
_reql_new_array(uint32_t size) {
  _ReQL_Obj_t *obj = _reql_alloc_term();
  _ReQL_Obj_t **arr = _reql_alloc_arr(size);
  _reql_array_init(obj, arr, size);
  return obj;
}

_ReQL_Obj_t *
_reql_new_bool(bool val) {
  _ReQL_Obj_t *obj = _reql_alloc_term();
  _reql_bool_init(obj, val);
  return obj;
}

_ReQL_Obj_t *
_reql_new_datum(_ReQL_Obj_t *arg) {
  _ReQL_Obj_t *obj = _reql_alloc_term();
  _reql_ast_datum(obj, arg, NULL);
  return obj;
}

_ReQL_Obj_t *
_reql_new_make_array(_ReQL_Obj_t *arg) {
  _ReQL_Obj_t *obj = _reql_alloc_term();
  _reql_ast_make_array(obj, arg, NULL);
  return obj;
}

_ReQL_Obj_t *
_reql_new_make_obj(_ReQL_Obj_t *arg) {
  _ReQL_Obj_t *obj = _reql_alloc_term();
  _reql_ast_make_obj(obj, NULL, arg);
  return obj;
}

_ReQL_Obj_t *
_reql_new_null() {
  _ReQL_Obj_t *obj = _reql_alloc_term();
  _reql_null_init(obj);
  return obj;
}

_ReQL_Obj_t *
_reql_new_number(double val) {
  _ReQL_Obj_t *obj = _reql_alloc_term();
  _reql_number_init(obj, val);
  return obj;
}

_ReQL_Obj_t *
_reql_new_object(uint32_t size) {
  _ReQL_Obj_t *obj = _reql_alloc_term();
  _ReQL_Pair_t *pair = _reql_alloc_pair(size);
  _reql_object_init(obj, pair, size);
  return obj;
}

_ReQL_Obj_t *
_reql_new_string(std::string val) {
  size_t size = val.size();

  if (size > UINT32_MAX) {
    return NULL;
  }

  uint8_t *str = new uint8_t[size]();

  val.copy((char *)str, size);

  _ReQL_Obj_t *obj = _reql_alloc_term();

  _reql_string_init(obj, str, (uint32_t)size);

  return obj;
}

ReQL::ReQL() {
  query = _reql_new_null();
}

ReQL::ReQL(_ReQL_AST_Function f, std::vector<ReQL> args, std::map<std::string, ReQL> kwargs) {
  query = _reql_alloc_term();
}

ReQL::ReQL(std::string val) {
}

ReQL::ReQL(double val) {
}

ReQL::ReQL(bool val) {
}

ReQL::ReQL(std::vector<ReQL> val) {
}

ReQL::ReQL(std::map<std::string, ReQL> val) {
}

ReQL::ReQL(const ReQL &other) {
  query = other.query;
  array = other.array;
  object = other.object;
  args = other.args;
  kwargs = other.kwargs;
}

ReQL::ReQL(const ReQL &&other) {
  query = other.query;
  array = other.array;
  object = other.object;
  args = other.args;
  kwargs = other.kwargs;
}

ReQL &ReQL::operator=(const ReQL &other) {
  if (this != &other) {
    query = other.query;
    array = other.array;
    object = other.object;
    args = other.args;
    kwargs = other.kwargs;
  }

  return *this;
}

ReQL &ReQL::operator=(const ReQL &&other) {
  if (this != &other) {
    query = other.query;
    array = other.array;
    object = other.object;
    args = other.args;
    kwargs = other.kwargs;
  }

  return *this;
}

ReQL::~ReQL() {
  if (query != nullptr) {
    delete query;
  }
  if (array != nullptr) {
    delete [] array;
  }
  if (object != nullptr) {
    delete object;
  }
  if (args != nullptr) {
    delete args;
  }
  if (kwargs != nullptr) {
    delete kwargs;
  }
}
  
}
