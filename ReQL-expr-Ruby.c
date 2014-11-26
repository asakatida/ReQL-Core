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

#include "ReQL-expr-Ruby.h"

static VALUE _reql_rb_expr(int argn, VALUE *args, VALUE self) {
  rb_Integer(args[1]);
  const long nesting_depth = 20;

  return _reql_to_rb(_reql_from_rb(args[0], nesting_depth));
}

static _ReQL_Op_t *_reql_from_rb(VALUE obj, long nesting_depth) {
  if (nesting_depth <= 0) {
    return NULL;
  }

  return NULL;
}

static VALUE _reql_to_rb(_ReQL_Op_t *query) {
  VALUE res = NULL;
  switch (query->dt) {
    case _REQL_C_ARRAY: {
      unsigned long size;
      if (_reql_to_c_array(query, &size)) {
        break;
      }

      unsigned long i;

      for (i=0; i<size; ++i) {
        _reql_to_rb(_reql_c_array_index(query, i));
      }
      break;
    }
    case _REQL_R_ARRAY: {
      _ReQL_Op_t *iter = _reql_to_array(query);
      if (!iter) {
        break;
      }

      _ReQL_Op_t *elem;

      while (_reql_array_next(&iter, &elem)) {
        _reql_to_rb(elem);
      }
      break;
    }
    case _REQL_R_BOOL: {
      int value;
      if (_reql_to_bool(query, &value)) {
        break;
      }
      break;
    }
    case _REQL_R_JSON: {
      break;
    }
    case _REQL_R_NULL: {
      break;
    }
    case _REQL_R_NUM: {
      double value;
      if (_reql_to_number(query, &value)) {
        break;
      }
      break;
    }
    case _REQL_R_OBJECT: {
      _ReQL_Op_t *iter = _reql_to_object(query);
      if (!iter) {
        break;
      }

      _ReQL_Op_t *key;
      _ReQL_Op_t *val;

      while (_reql_object_next(&iter, &key, &val)) {
        _reql_to_rb(key);
        _reql_to_rb(val);
      }
      break;
    }
    case _REQL_R_STR: {
      unsigned long str_len;
      const char *str;
      if (_reql_to_string(query, &str, &str_len)) {
        break;
      }
      break;
    }
  }
  return res;
}
