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

#include "ReQL-encode.h"

#include "ReQL-char.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int
_reql_string_t_append(_ReQL_String_t *obj, const uint8_t *ext, uint32_t size) {
  if (obj->alloc_size <= (obj->size + size)) {
    obj->alloc_size += size;
    obj->alloc_size *= 1.1;

    uint8_t *str = realloc(obj->str, sizeof(uint8_t) * obj->alloc_size);

    if (!str) {
      free(obj->str); obj->str = NULL;
      obj->alloc_size = 0;
      obj->size = 0;
      return -1;
    }

    obj->str = str;
  }

  memcpy(&obj->str[obj->size], ext, size);

  obj->size += size;

  return 0;
}

static int
_reql_string_t_append_(_ReQL_String_t *json, const uint8_t ext) {
  if (json->alloc_size <= (json->size + 1)) {
    uint8_t _ext[1] = {ext};
    return _reql_string_t_append(json, _ext, 1);
  }

  json->str[json->size] = ext;

  json->size += 1;

  return 0;
}

static int
_reql_escape_string(_ReQL_String_t *json, const uint8_t *str, uint32_t size) {
  if (_reql_string_t_append_(json, quotation)) {
    return -1;
  }
  uint32_t i, ext_size;
  uint8_t chr;
  for (i=0; i<size; ++i) {
    chr = str[i];
    if ((ext_size = _reql_json_string_esc_size(chr))) {
      _reql_string_t_append(json, _reql_json_string_esc(chr), ext_size);
    } else {
      _reql_string_t_append_(json, chr);
    }
  }
  return _reql_string_t_append_(json, quotation);
}

static int
_reql_encode_(_ReQL_Obj_t *obj, _ReQL_String_t *json) {
  switch (_reql_datum_type(obj)) {
    case _REQL_R_ARRAY: {
      if (_reql_string_t_append_(json, left_square_bracket)) {
        return -1;
      }
      uint32_t size = _reql_array_size(obj);
      uint32_t i;
      for (i=0; i<size; ++i) {
        if (i > 0) {
          if (_reql_string_t_append_(json, comma)) {
            return -1;
          }
        }
        if (_reql_encode_(_reql_array_index(obj, i), json)) {
          return -1;
        }
      }
      return _reql_string_t_append_(json, right_square_bracket);
    }
    case _REQL_R_BOOL: {
      if (_reql_to_bool(obj)) {
        if (_reql_string_t_append(json, json_true, 4)) {
          return -1;
        }
      } else {
        if (_reql_string_t_append(json, json_false, 5)) {
          return -1;
        }
      }
    }
    case _REQL_R_REQL:
    case _REQL_R_JSON: break;
    case _REQL_R_NULL: {
      return _reql_string_t_append(json, json_null, 4);
    }
    case _REQL_R_NUM: {
      double val = _reql_to_number(obj);

      size_t size = sprintf(NULL, "%f", val);

      if (size > UINT32_MAX) {
        return -1;
      }

      uint8_t *str = malloc(sizeof(uint8_t) * size);

      if (!str) {
        return -1;
      }

      int err = -1;

      if (size == sprintf((char *)str, "%f", val)) {
        err = _reql_string_t_append(json, str, (uint32_t)size);
      }

      free(str);

      return err;
    }
    case _REQL_R_OBJECT: {
      if (_reql_string_t_append_(json, left_curly_bracket)) {
        return -1;
      }

      _ReQL_Iter_t iter = _reql_new_iter(obj);

      char first = 1;
      _ReQL_Obj_t *key = NULL;

      while ((key = _reql_iter_next(&iter)) != NULL) {
        if (!first) {
          if (_reql_string_t_append_(json, comma)) {
            return -1;
          }
        }
        if (_reql_encode_(key, json)) {
          return -1;
        }
        if (_reql_string_t_append_(json, colon)) {
          return -1;
        }
        if (_reql_encode_(_reql_object_get(obj, key), json)) {
          return -1;
        }
        first = 0;
      }
      return _reql_string_t_append_(json, right_curly_bracket);
    }
    case _REQL_R_STR: {
      return _reql_escape_string(json, _reql_string_buf(obj), _reql_string_size(obj));
    }
  }

  return 0;
}

extern _ReQL_String_t *
_reql_encode(_ReQL_Obj_t *val) {
  _ReQL_String_t *json = malloc(sizeof(_ReQL_String_t));

  json->str = malloc(sizeof(uint8_t) * 100);

  json->size = 0;
  json->alloc_size = 100;

  if (_reql_encode_(val, json)) {
    if (json->str != NULL) {
      free(json->str);
    }
    free(json);
    return NULL;
  }

  return json;
}
