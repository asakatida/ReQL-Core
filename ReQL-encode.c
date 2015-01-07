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

#include "ReQL-encode.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int _reql_string_append(_ReQL_String_t *obj, char *ext, uint32_t size) {
  if (obj->alloc_size <= (obj->size + size)) {
    obj->alloc_size += size;
    obj->alloc_size *= 1.1;

    obj->str = realloc(obj->str, sizeof(uint8_t) * obj->alloc_size);

    if (!obj->str) {
      obj->alloc_size = 0;
      obj->size = 0;
      return -1;
    }
  }

  memcpy(&obj->str[obj->size + 1], ext, size);

  obj->size += size;

  return 0;
}

int _reql_encode_(_ReQL_Op obj, _ReQL_String_t *json) {
  switch (_reql_datum_type(obj)) {
    case _REQL_R_ARRAY: {
      if (_reql_string_append(json, "[", 1)) {
        return -1;
      }
      uint32_t size = _reql_array_size(obj);
      uint32_t i;
      for (i=0; i<size; ++i) {
        if (i) {
          if (_reql_string_append(json, ",", 1)) {
            return -1;
          }
        }
        if (_reql_encode_(_reql_array_index(obj, i), json)) {
          return -1;
        }
      }
      return _reql_string_append(json, "]", 1);
    }
    case _REQL_R_BOOL: {
      if (_reql_to_bool(obj)) {
        if (_reql_string_append(json, "true", 4)) {
          return -1;
        }
      } else {
        if (_reql_string_append(json, "false", 5)) {
          return -1;
        }
      }
    }
    case _REQL_R_REQL:
    case _REQL_R_JSON: break;
    case _REQL_R_NULL: {
      return _reql_string_append(json, "null", 4);
    }
    case _REQL_R_NUM: {
      double val = _reql_to_number(obj);
      size_t size = sprintf(NULL, "%f", val);

      if (size > UINT32_MAX) {
        return -1;
      }

      char *str = malloc(sizeof(char) * size);

      if (!str) {
        return -1;
      }

      int err = -1;

      if (size == sprintf(str, "%f", val)) {
        err = _reql_string_append(json, str, (uint32_t)size);
      }

      free(str);

      return err;
    }
    case _REQL_R_OBJECT: {
      if (_reql_string_append(json, "{", 1)) {
        return -1;
      }

      _ReQL_Iter_t iter = _reql_new_iter(obj);

      char first = 1;
      _ReQL_Op key = NULL;

      while ((key = _reql_iter_next(&iter))) {
        if (!first) {
          if (_reql_string_append(json, ",", 1)) {
            return -1;
          }
        }
        if (_reql_encode_(key, json)) {
          return -1;
        }
        if (_reql_string_append(json, ":", 1)) {
          return -1;
        }
        if (_reql_encode_(_reql_object_get(obj, key), json)) {
          return -1;
        }
        first = 0;
      }
      return _reql_string_append(json, "}", 1);
    }
    case _REQL_R_STR: {
      if (_reql_string_append(json, "\"", 1)) {
        return -1;
      }
      if (_reql_string_append(json, (char *)_reql_string_buf(obj), _reql_string_size(obj))) {
        return -1;
      }
      return _reql_string_append(json, "\"", 1);
    }
  }

  return -1;
}

_ReQL_String_t *_reql_encode(_ReQL_Op val) {
  _ReQL_String_t *json;

  if (_reql_encode_(val, json)) {
    return NULL;
  }

  return json;
}
