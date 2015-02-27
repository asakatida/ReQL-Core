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
reql_string_t_append(ReQL_String_t *obj, const uint8_t *ext, uint32_t size) {
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
reql_string_t_append_(ReQL_String_t *json, const uint8_t ext) {
  if (json->alloc_size <= (json->size + 1)) {
    uint8_t buf[1] = {ext};
    return reql_string_t_append(json, buf, 1);
  }

  json->str[json->size] = ext;

  json->size += 1;

  return 0;
}

static int
reql_escape_string(ReQL_String_t *json, const uint8_t *str, uint32_t size) {
  if (reql_string_t_append_(json, quotation)) {
    return -1;
  }
  uint32_t i, ext_size;
  uint8_t chr;
  for (i=0; i<size; ++i) {
    chr = str[i];
    if ((ext_size = reql_json_string_esc_size(chr))) {
      reql_string_t_append(json, reql_json_string_esc(chr), ext_size);
    } else {
      reql_string_t_append_(json, chr);
    }
  }
  return reql_string_t_append_(json, quotation);
}

static int
reql_encode_(ReQL_Obj_t *obj, ReQL_String_t *json) {
  switch (reql_datum_type(obj)) {
    case REQL_R_ARRAY: {
      if (reql_string_t_append_(json, left_square_bracket)) {
        return -1;
      }
      uint32_t size = reql_size(obj);
      uint32_t i;
      for (i=0; i<size; ++i) {
        if (i > 0) {
          if (reql_string_t_append_(json, comma)) {
            return -1;
          }
        }
        if (reql_encode_(reql_array_index(obj, i), json)) {
          return -1;
        }
      }
      return reql_string_t_append_(json, right_square_bracket);
    }
    case REQL_R_BOOL: {
      if (reql_to_bool(obj)) {
        if (reql_string_t_append(json, json_true, 4)) {
          return -1;
        }
      } else {
        if (reql_string_t_append(json, json_false, 5)) {
          return -1;
        }
      }
    }
    case REQL_R_REQL:
    case REQL_R_JSON: break;
    case REQL_R_NULL: {
      return reql_string_t_append(json, json_null, 4);
    }
    case REQL_R_NUM: {
      char *str = malloc(sizeof(char) * 1);

      if (!str) {
        return -1;
      }

      double val = reql_to_number(obj);

      ssize_t size = snprintf(str, 1, "%g", val);

      if (size > UINT32_MAX || size < 0) {
        free(str);
        return -1;
      }

      str = realloc(str, sizeof(char) * (size_t)size);

      if (!str) {
        return -1;
      }

      int err = -1;

      if (size == sprintf(str, "%g", val)) {
        err = reql_string_t_append(json, (uint8_t *)str, (uint32_t)size);
      }

      free(str);

      return err;
    }
    case REQL_R_OBJECT: {
      if (reql_string_t_append_(json, left_curly_bracket)) {
        return -1;
      }

      ReQL_Iter_t iter = reql_new_iter(obj);

      char first = 1;
      ReQL_Obj_t *key = NULL;

      while ((key = reql_iter_next(&iter)) != NULL) {
        if (!first) {
          if (reql_string_t_append_(json, comma)) {
            return -1;
          }
        }
        if (reql_encode_(key, json)) {
          return -1;
        }
        if (reql_string_t_append_(json, colon)) {
          return -1;
        }
        if (reql_encode_(reql_object_get(obj, key), json)) {
          return -1;
        }
        first = 0;
      }
      return reql_string_t_append_(json, right_curly_bracket);
    }
    case REQL_R_STR: {
      return reql_escape_string(json, reql_string_buf(obj), reql_size(obj));
    }
  }

  return 0;
}

extern ReQL_String_t *
reql_encode(ReQL_Obj_t *val) {
  ReQL_String_t *json = malloc(sizeof(ReQL_String_t));

  json->str = malloc(sizeof(uint8_t) * 100);

  json->size = 0;
  json->alloc_size = 100;

  if (reql_encode_(val, json)) {
    if (json->str != NULL) {
      free(json->str);
    }
    free(json);
    return NULL;
  }

  return json;
}
