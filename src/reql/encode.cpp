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

#include "./reql/encode.hpp"

#include "./reql/char.hpp"

#include "./reql/query.h"
#include "./reql/types.h"

#include <memory>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int
reql_string_t_append(ReQL_String_t *obj, const ReQL_Byte *ext, const ReQL_Size size) {
  if (obj->alloc_size <= (obj->size + size)) {
    obj->alloc_size += size;
    obj->alloc_size *= 1.1;
    ReQL_Byte *str;
    try {
      str = new ReQL_Byte[obj->alloc_size];
    } catch (std::bad_alloc&) {
      delete obj->str; obj->str = nullptr;
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
reql_string_t_append_(ReQL_String_t *json, const ReQL_Byte ext) {
  return reql_string_t_append(json, &ext, 1);
}

static int
reql_escape_string(ReQL_String_t *json, const ReQL_Byte *str, const ReQL_Size size) {
  if (reql_string_t_append_(json, quotation) != 0) {
    return -1;
  }
  ReQL_Size i, ext_size;
  ReQL_Byte chr;
  for (i=0; i < size; ++i) {
    chr = str[i];
    if ((ext_size = reql_json_string_esc_size(chr)) != 0) {
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
      if (reql_string_t_append_(json, left_square_bracket) != 0) {
        return -1;
      }

      ReQL_Iter_t iter = reql_new_iter(obj);

      char first = 1;
      ReQL_Obj_t *elem = nullptr;

      while ((elem = reql_iter_next(&iter)) != nullptr) {
        if (first == 0) {
          if (reql_string_t_append_(json, comma) != 0) {
            return -1;
          }
        }
        if (reql_encode_(elem, json) != 0) {
          return -1;
        }
        first = 0;
      }
      return reql_string_t_append_(json, right_square_bracket);
    }
    case REQL_R_BOOL: {
      if (reql_to_bool(obj)) {
        return reql_string_t_append(json, json_true, 4);
      }
      return reql_string_t_append(json, json_false, 5);
    }
    case REQL_R_JSON: return -1;
    case REQL_R_NULL: return reql_string_t_append(json, json_null, 4);
    case REQL_R_NUM: {
      char *str;
      try {
        str = new char[1];
      } catch (std::bad_alloc&) {
        return -1;
      }

      const double val = reql_to_number(obj);

      const int size = snprintf(str, 0, "%g", val);
      const int size_w_null = size + 1;

      if (static_cast<size_t>(size_w_null) > UINT32_MAX || size_w_null < 0) {
        delete []str;
        return -1;
      }

      delete []str;
      try {
        str = new char[size_w_null];
      } catch (std::bad_alloc&) {
        return -1;
      }

      int err = -1;

      if (size == snprintf(str, size_w_null, "%g", val)) {
        err = reql_string_t_append(json, reinterpret_cast<ReQL_Byte *>(str), static_cast<ReQL_Size>(size));
      }

      delete []str;

      return err;
    }
    case REQL_R_OBJECT: {
      if (reql_string_t_append_(json, left_curly_bracket) != 0) {
        return -1;
      }

      ReQL_Iter_t iter = reql_new_iter(obj);

      char first = 1;
      ReQL_Obj_t *key = nullptr;

      while ((key = reql_iter_next(&iter)) != nullptr) {
        if (first == 0) {
          if (reql_string_t_append_(json, comma) != 0) {
            return -1;
          }
        }
        if (reql_encode_(key, json) != 0) {
          return -1;
        }
        if (reql_string_t_append_(json, colon) != 0) {
          return -1;
        }
        if (reql_encode_(reql_object_get(obj, key), json) != 0) {
          return -1;
        }
        first = 0;
      }
      return reql_string_t_append_(json, right_curly_bracket);
    }
    case REQL_R_REQL: {
      if (reql_string_t_append_(json, left_square_bracket) != 0) {
        return -1;
      }
      char *str;
      try {
        str = new char[1];
      } catch (std::bad_alloc&) {
        return -1;
      }

      const int val = reql_term_type(obj);

      const int size = snprintf(str, 0, "%d", val) + 1;
      const int size_w_null = size + 1;

      if (static_cast<size_t>(size_w_null) > UINT32_MAX || size_w_null < 0) {
        delete []str;
        return -1;
      }

      delete []str;
      try {
        str = new char[size_w_null];
      } catch (std::bad_alloc&) {
        return -1;
      }

      int err = -1;

      if (size == snprintf(str, size_w_null, "%d", val)) {
        err = reql_string_t_append(json, reinterpret_cast<ReQL_Byte *>(str), static_cast<ReQL_Size>(size));
      }

      delete []str;

      if (err != 0) {
        return err;
      }

      if (reql_string_t_append_(json, comma) != 0) {
        return -1;
      }
      return reql_string_t_append_(json, right_square_bracket);
    }
    case REQL_R_STR: return reql_escape_string(json, reql_string_buf(obj), reql_size(obj));
  }

  return -1;
}

extern ReQL_String_t *
reql_encode(ReQL_Obj_t *val) {
  ReQL_String_t *json;
  try {
    json = new ReQL_String_t;
  } catch (std::bad_alloc&) {
    return nullptr;
  }

  try {
    json->str = new ReQL_Byte[100];
  } catch (std::bad_alloc&) {
    delete json;
    return nullptr;
  }

  json->size = 0;
  json->alloc_size = 100;

  if (reql_encode_(val, json) != 0) {
    delete json->str;
    delete json;
    return nullptr;
  }

  return json;
}
