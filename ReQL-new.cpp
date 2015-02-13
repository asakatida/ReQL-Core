/*
Copyright 2014-2015 Adam Grandquist

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

#include <limits>

namespace ReQL {

static ReQL_Obj_t **
reql_alloc_arr(size_t size) {
  return new ReQL_Obj_t *[size]();
}

static ReQL_Pair_t *
reql_alloc_pair(size_t size) {
  return new ReQL_Pair_t[size]();
}

static ReQL_Obj_t *
reql_alloc_term() {
  return new ReQL_Obj_t();
}

static ReQL_Obj_t *
reql_new_array(uint32_t size) {
  ReQL_Obj_t *obj = reql_alloc_term();
  ReQL_Obj_t **arr = reql_alloc_arr(size);
  reql_array_init(obj, arr, size);
  return obj;
}

static ReQL_Obj_t *
reql_new(bool val) {
  ReQL_Obj_t *obj = reql_alloc_term();
  reql_bool_init(obj, val);
  return obj;
}

static ReQL_Obj_t *
reql_new_make_array(ReQL_Obj_t *arg) {
  ReQL_Obj_t *obj = reql_alloc_term();
  reql_ast_make_array(obj, arg, NULL);
  return obj;
}

static ReQL_Obj_t *
reql_new_make_obj(ReQL_Obj_t *arg) {
  ReQL_Obj_t *obj = reql_alloc_term();
  reql_ast_make_obj(obj, NULL, arg);
  return obj;
}

static ReQL_Obj_t *
reql_new() {
  ReQL_Obj_t *obj = reql_alloc_term();
  reql_null_init(obj);
  return obj;
}

static ReQL_Obj_t *
reql_new(double val) {
  ReQL_Obj_t *obj = reql_alloc_term();
  reql_number_init(obj, val);
  return obj;
}

static ReQL_Obj_t *
reql_new_object(uint32_t size) {
  ReQL_Obj_t *obj = reql_alloc_term();
  ReQL_Pair_t *pair = reql_alloc_pair(size);
  reql_object_init(obj, pair, size);
  return obj;
}

static ReQL_Obj_t *
reql_new(std::string val) {
  size_t size = val.size();

  if (size > UINT32_MAX) {
    return NULL;
  }

  uint8_t *str = new uint8_t[size]();

  val.copy((char *)str, size);

  ReQL_Obj_t *obj = reql_alloc_term();

  reql_string_init(obj, str, (uint32_t)size);

  return obj;
}

ReQL::ReQL() {
  query = reql_new();
}

ReQL::ReQL(ReQL_AST_Function f, std::vector<ReQL> args, std::map<ReQL, ReQL> kwargs) {
  query = reql_alloc_term();
}

ReQL::ReQL(std::string val) {
  query = reql_new(val);
}

ReQL::ReQL(double val) {
  query = reql_new(val);
}

ReQL::ReQL(bool val) {
  query = reql_new(val);
}

ReQL::ReQL(std::vector<ReQL> val) {
  std::size_t size = val.size();

  if (size > std::numeric_limits<std::uint32_t>::max()) {
    return;
  }

  array = reql_new_array(static_cast<std::uint32_t>(size));
  query = reql_new_make_array(array);

  for (auto q : val) {
    reql_array_append(query, q.query);
  }
}

ReQL::ReQL(std::map<ReQL, ReQL> val) {
  std::size_t size = val.size();

  if (size > std::numeric_limits<std::uint32_t>::max()) {
    return;
  }

  object = reql_new_object(static_cast<std::uint32_t>(size));
  query = reql_new_make_obj(object);

  for (auto q : val) {
    reql_object_add(query, q.first.query, q.second.query);
  }
}

ReQL::ReQL(const ReQL &other) {
  query = other.query;
  array = other.array;
  object = other.object;
}

ReQL::ReQL(ReQL &&other) {
  query = other.query; other.query = nullptr;
  array = other.array; other.array = nullptr;
  object = other.object; other.object = nullptr;
}

ReQL &ReQL::operator=(const ReQL &other) {
  if (this != &other) {
    query = other.query;
    array = other.array;
    object = other.object;
  }

  return *this;
}

ReQL &ReQL::operator=(ReQL &&other) {
  if (this != &other) {
    query = other.query; other.query = nullptr;
    array = other.array; other.array = nullptr;
    object = other.object; other.object = nullptr;
  }

  return *this;
}

bool ReQL::operator<(const ReQL &other) const {
  ReQL_Datum_t ltype = reql_datum_type(query), rtype = reql_datum_type(other.query);
  if (ltype == rtype) {
    switch (ltype) {
      case REQL_R_ARRAY:
      case REQL_R_BOOL:
      case REQL_R_JSON:
      case REQL_R_NULL:
      case REQL_R_NUM:
      case REQL_R_OBJECT:
      case REQL_R_REQL: {
        return query < other.query;
      }
      case REQL_R_STR: {
        std::string same((char *)reql_string_buf(query), reql_string_size(query));
        std::string diff((char *)reql_string_buf(other.query), reql_string_size(other.query));
        return same < diff;
      }
    }
  }
  return ltype < rtype;
}

ReQL::~ReQL() {
  if (query != nullptr) {
    delete query;
  }
  if (array != nullptr) {
    delete [] array->obj.datum.json.var.data.array;
    delete array;
  }
  if (object != nullptr) {
    delete object->obj.datum.json.var.data.pair;
    delete object;
  }
}

}
