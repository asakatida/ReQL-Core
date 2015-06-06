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

#include "./c/cursor.h"

#include "./reql/core.h"

#include <stdlib.h>

struct ReQL_Cursor_s {
  ReQL_Cur_t *cursor;
};

struct ReQL_Result_s {
  ReQL_Obj_t *object;
};

static ReQL_Result_t *
reql_result(ReQL_Obj_t *obj) {
  if (obj == NULL) {
    return NULL;
  }
  ReQL_Result_t *res = malloc(sizeof(ReQL_Result_t));
  if (res == NULL) {
    return NULL;
  }
  res->object = obj;
  return res;
}

static void
reql_result_destroy(ReQL_Result_t *result) {
  reql_json_destroy(result->object);
  free(result);
}

extern void
reql_cursor_close(ReQL_Cursor_t *cur) {
  reql_cur_close(cur->cursor);
}

extern void *
reql_cursor_data(ReQL_Cursor_t *cur) {
  return cur->cursor;
}

extern void
reql_cursor_drain(ReQL_Cursor_t *cur) {
  reql_cur_drain(cur->cursor);
}

extern void
reql_cursor_each(ReQL_Cursor_t *cur, ReQL_Each cb, void *obj) {
  ReQL_Obj_t *next = NULL;
  while ((next = reql_cur_next(cur->cursor)) != NULL) {
    ReQL_Result_t *res = reql_result(next);
    if (res == NULL) {
      reql_json_destroy(next);
    }
    cb(res, obj);
    reql_result_destroy(res); res = NULL;
  }
}

extern void
reql_cursor_each_async(ReQL_Cursor_t *cur, ReQL_Each cb, void *obj) {
  reql_cur_each(cur->cursor, ^int(ReQL_Obj_t *res, void *data) {
    ReQL_Result_t *result = reql_result(res);
    cb(result, data);
    result->object = NULL;
    reql_result_destroy(result);
    return 0;
  }, obj);
}

extern void
reql_result_parse(ReQL_Result_t *result, ReQL_Parse cb, void *obj) {
  switch (reql_datum_type(result->object)) {
    case REQL_R_ARRAY: {
      cb(result, ReQL_Start_Array, obj);
      ReQL_Iter_t it = reql_new_iter(result->object);
      ReQL_Obj_t *r_val = NULL;
      ReQL_Result_t *val = NULL;
      while ((r_val = reql_iter_next(&it)) != NULL) {
        val = reql_result(r_val);
        cb(val, ReQL_Start_Element, obj);
        reql_result_parse(val, cb, obj);
        cb(val, ReQL_End_Element, obj);
        val->object = NULL;
        reql_result_destroy(val); val = NULL;
      }
      cb(result, ReQL_End_Array, obj);
      break;
    }
    case REQL_R_BOOL: {
      cb(result, ReQL_Bool, obj);
      break;
    }
    case REQL_R_JSON: {
      cb(result, ReQL_Error, obj);
      break;
    }
    case REQL_R_NULL: {
      cb(result, ReQL_Null, obj);
      break;
    }
    case REQL_R_NUM: {
      cb(result, ReQL_Number, obj);
      break;
    }
    case REQL_R_OBJECT: {
      cb(result, ReQL_Start_Object, obj);
      ReQL_Iter_t it = reql_new_iter(result->object);
      ReQL_Obj_t *r_key = NULL;
      ReQL_Result_t *key = NULL;
      ReQL_Result_t *val = NULL;
      while ((r_key = reql_iter_next(&it)) != NULL) {
        key = reql_result(r_key);
        cb(key, ReQL_Start_Key_Value, obj);
        val = reql_result(reql_object_get(result->object, r_key));
        reql_result_parse(val, cb, obj);
        val->object = NULL;
        reql_result_destroy(val); val = NULL;
        cb(key, ReQL_End_Key_Value, obj);
        key->object = NULL;
        reql_result_destroy(key); key = NULL;
      }
      cb(result, ReQL_End_Object, obj);
      break;
    }
    case REQL_R_REQL: {
      cb(result, ReQL_Error, obj);
      break;
    }
    case REQL_R_STR: {
      cb(result, ReQL_String, obj);
      break;
    }
  }
}

extern ReQL_Result_t *
reql_result_get(ReQL_Result_t *result, char *key, unsigned long key_size) {
  if (reql_datum_type(result->object) != REQL_R_OBJECT) {
    return NULL;
  }
  ReQL_Obj_t *key_obj = malloc(sizeof(ReQL_Obj_t));
  if (key_obj == NULL) {
    return NULL;
  }
  ReQL_Byte *buf = malloc(sizeof(ReQL_Byte) * key_size);
  if (buf == NULL) {
    free(key_obj);
    return NULL;
  }
  reql_string_init(key_obj, buf, (ReQL_Size)key_size);
  reql_string_append(key_obj, (ReQL_Byte *)key, (ReQL_Size)key_size);
  ReQL_Result_t *val = reql_result(reql_object_get(result->object, key_obj));
  reql_json_destroy(key_obj);
  return val;
}

extern ReQL_Result_t **
reql_result_keys(ReQL_Result_t *result) {
  if (reql_datum_type(result->object) != REQL_R_OBJECT) {
    return NULL;
  }
  const ReQL_Size size = reql_size(result->object) + 1;
  ReQL_Iter_t it = reql_new_iter(result->object);
  ReQL_Result_t **keys = malloc(sizeof(ReQL_Result_t*) * size);
  ReQL_Size i = 0;
  ReQL_Obj_t *next = NULL;
  while ((next = reql_iter_next(&it)) != NULL) {
    keys[i++] = reql_result(next);
  }
  for (; i < size; ++i) {
    keys[i] = NULL;
  }
  keys[size] = NULL;
  return keys;
}

extern unsigned long
reql_result_size(ReQL_Result_t *result) {
  ReQL_Datum_t type = reql_datum_type(result->object);
  if (type == REQL_R_ARRAY || type == REQL_R_OBJECT || type == REQL_R_STR) {
    return reql_size(result->object);
  }
  return 0;
}

extern ReQL_Result_t **
reql_result_to_array(ReQL_Result_t *result) {
  if (reql_datum_type(result->object) != REQL_R_ARRAY) {
    return NULL;
  }
  const ReQL_Size size = reql_size(result->object) + 1;
  ReQL_Iter_t it = reql_new_iter(result->object);
  ReQL_Result_t **array = malloc(sizeof(ReQL_Result_t*) * size);
  ReQL_Size i = 0;
  ReQL_Obj_t *next = NULL;
  while ((next = reql_iter_next(&it)) != NULL) {
    array[i++] = reql_result(next);
  }
  for (; i < size; ++i) {
    array[i] = NULL;
  }
  array[size] = NULL;
  return array;
}

extern int
reql_result_to_bool(ReQL_Result_t *result) {
  if (reql_datum_type(result->object) != REQL_R_BOOL) {
    return -1;
  }
  return reql_to_bool(result->object);
}

extern double
reql_result_to_number(ReQL_Result_t *result) {
  if (reql_datum_type(result->object) != REQL_R_NUM) {
    return 0;
  }
  return reql_to_number(result->object);
}

extern char *
reql_result_to_string(ReQL_Result_t *result) {
  if (reql_datum_type(result->object) != REQL_R_STR) {
    return NULL;
  }
  return (char *)reql_string_buf(result->object);
}
