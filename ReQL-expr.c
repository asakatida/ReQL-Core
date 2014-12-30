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

#include "ReQL-expr.h"

#include <stdlib.h>

_ReQL_Op _reql_expr(_ReQL_Op val) {
  if (val) {
    switch (val->obj.datum.dt) {
      case _REQL_R_ARRAY: {
        val = _reql_ast_make_array(val, NULL);
        break;
      }
      case _REQL_R_OBJECT: {
        val = _reql_ast_make_obj(NULL, val);
        break;
      }
      case _REQL_R_BOOL:
      case _REQL_R_NULL:
      case _REQL_R_NUM:
      case _REQL_R_STR: {
        val = _reql_ast_datum(val, NULL);
        break;
      }
      case _REQL_R_JSON: break;
    }
  }

  return val;
}

_ReQL_Op _reql_expr_number(double num) {
  return _reql_number(NULL, num);
}

_ReQL_Op _reql_number(_ReQL_Op obj, double num) {
  return _reql_expr(_reql_json_number(obj, num));
}

_ReQL_Op _reql_expr_string(char *str, unsigned long size) {
  return _reql_string_(NULL, str, size);
}

_ReQL_Op _reql_string_(_ReQL_Op obj, char *str, unsigned long size) {
  return _reql_expr(_reql_json_string(obj, str, size));
}

_ReQL_Op _reql_expr_null() {
  return _reql_null(NULL);
}

_ReQL_Op _reql_null(_ReQL_Op obj) {
  return _reql_expr(_reql_json_null(obj));
}

_ReQL_Op _reql_expr_bool(int val) {
  return _reql_bool(NULL, val);
}

_ReQL_Op _reql_bool(_ReQL_Op obj, int val) {
  return _reql_expr(_reql_json_bool(obj, val));
}

_ReQL_Op _reql_build(_ReQL_Op query) {
  if (!query) {
    return NULL;
  }
  if (query->tt == _REQL_DATUM) {
    return query;
  }

  _ReQL_Op res = _reql_json_array_(NULL, 3);

  if (!res) {
    return NULL;
  }

  _reql_array_insert(res, _reql_json_number(NULL, query->tt), 0);
  unsigned long size;
  _ReQL_Iter iter;
  _ReQL_Op arr = NULL;

  if ((iter = _reql_to_array(query->obj.args.args))) {
    _ReQL_Op arr = _reql_json_array_(NULL, size);

    unsigned long i;

    for (i=0; i<size; ++i) {
      _reql_array_insert(arr, _reql_build(_reql_array_index(query->obj.args.args, i)), i);
    }
  } else {
    _reql_expr_free(res); res = NULL;
  }

  if (arr && _reql_array_insert(res, arr, 1)) {
    _reql_expr_free(arr);
    _reql_expr_free(res);
  }

  _reql_iter_free(iter);
  iter = _reql_to_object(query->obj.args.kwargs);

  if (iter) {
    _ReQL_Op key = NULL;
    _ReQL_Op val = NULL;
    _ReQL_Op obj = _reql_json_object(NULL);

    char has_kwargs = 0;

    while (_reql_object_next(iter, &key, &val)) {
      _reql_object_add(obj, _reql_build(key), _reql_build(val));
      has_kwargs = 1;
    }

    if (has_kwargs) {
      _reql_array_insert(res, obj, 2);
    } else {
      _reql_expr_free(obj);
    }
  }

  return res;
}
