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

#include "ReQL-decode.h"

#include "ReQL-char.h"

#include <math.h>
#include <stdlib.h>
#include <string.h>

static void
reql_update_array(ReQL_Obj_t *array, ReQL_Obj_t *elem) {
  uint32_t new_alloc = reql_array_append(array, elem);

  if (new_alloc != 0) {
    ReQL_Obj_t **arr = array->obj.datum.json.array;

    arr = realloc(arr, sizeof(ReQL_Obj_t*) * new_alloc);

    if (arr == NULL) {
      array->obj.datum.json.size = array->obj.datum.json.alloc_size = 0;
      free(array->obj.datum.json.array); array->obj.datum.json.array = NULL;
    } else {
      array->obj.datum.json.alloc_size = new_alloc;
      array->obj.datum.json.array = arr;
      reql_array_append(array, elem);
    }
  }
}

static void
reql_update_object(ReQL_Obj_t *obj, ReQL_Obj_t *key, ReQL_Obj_t *val) {
  uint32_t new_alloc = reql_object_add(obj, key, val);

  if (new_alloc != 0) {
    ReQL_Pair_t *pair = obj->obj.datum.json.pair;

    pair = realloc(pair, sizeof(ReQL_Pair_t) * new_alloc);

    if (pair == NULL) {
      obj->obj.datum.json.size = obj->obj.datum.json.alloc_size = 0;
      free(obj->obj.datum.json.pair); obj->obj.datum.json.pair = NULL;
    } else {
      obj->obj.datum.json.alloc_size = new_alloc;
      obj->obj.datum.json.pair = pair;
      reql_object_add(obj, key, val);
    }
  }
}

static ReQL_Datum_t
reql_bad_pair(ReQL_Obj_t *stack, ReQL_Obj_t *key, ReQL_Obj_t *val) {
  reql_update_array(stack, key);
  reql_update_array(stack, val);
  if (reql_datum_type(key) == REQL_R_OBJECT) {
    return REQL_R_OBJECT;
  }
  return REQL_R_JSON;
}

static ReQL_Datum_t
reql_merge_stack_pair(ReQL_Obj_t *stack, ReQL_Obj_t *key, ReQL_Obj_t *val) {
  if (reql_datum_type(key) != REQL_R_STR) {
    return reql_bad_pair(stack, key, val);
  }

  ReQL_Obj_t *obj = reql_array_last(stack);

  if (obj == NULL) {
    return reql_bad_pair(stack, key, val);
  }

  if (reql_datum_type(obj) != REQL_R_OBJECT) {
    return reql_bad_pair(stack, key, val);
  }

  reql_update_object(obj, key, val);
  return REQL_R_OBJECT;
}

static ReQL_Datum_t
reql_merge_stack_val(ReQL_Obj_t *stack, ReQL_Obj_t *val) {
  ReQL_Obj_t *arr = reql_array_last(stack);

  if (arr == NULL) {
    reql_update_array(stack, val);
    return REQL_R_JSON;
  }

  if (reql_datum_type(arr) != REQL_R_ARRAY) {
    return reql_merge_stack_pair(stack, reql_array_pop(stack), val);
  }

  reql_update_array(arr, val);
  return REQL_R_ARRAY;
}

static ReQL_Datum_t
reql_merge_stack(ReQL_Obj_t *stack) {
  ReQL_Obj_t *val = reql_array_pop(stack);

  if (val == NULL) {
    return REQL_RREQL;
  }

  return reql_merge_stack_val(stack, val);
}

static ReQL_Obj_t *
reql_string_decode(uint32_t size, uint8_t *json) {
  if (size == 0) {
    ReQL_Obj_t *obj = malloc(sizeof(ReQL_Obj_t));

    if (obj == NULL) {
      return NULL;
    }

    reql_string_init(obj, NULL, 0);
    return obj;
  }

  uint8_t res;
  uint8_t *str = malloc(sizeof(uint8_t) * size);

  if (str == NULL) {
    return NULL;
  }

  uint32_t i, j = 0;
  for (i=0; i<size; ++i) {
    res = json[i];
    if (res == 0x5C) { /* \ */
      ++i;
      if (i >= size) {
        free(str);
        return NULL;
      }
      res = json[i];
      switch (json[i]) {
        case 0x08: { /* b */
          res = 0x08;
          break;
        }
        case 0x0C: { /* f */
          res = 0x0C;
          break;
        }
        case 0x0A: { /* n */
          res = 0x0A;
          break;
        }
        case 0x0D: { /* r */
          res = 0x0D;
          break;
        }
        case 't': { /* t */
          res = '\t';
          break;
        }
        case 'u': {
          res = 'u';
          if ((i + 4) < size) {
            char valid = 1;
            uint8_t hex;
            int n;
            for (n=1; n<=4; ++n) {
              hex = json[i + n];
              if (!((hex >= '0' && hex <= '9') ||
                    (hex >= 'a' && hex <= 'f') ||
                    (hex >= 'A' && hex <= 'F'))) {
                valid = 0;
              }
            }
            if (valid) {
              if (json[++i] != '0' || json[++i] != '0') {
                free(str);
                return NULL;
              }
              res = 0;
              for (n=1; n>=0; --n) {
                hex = json[++i];
                if (hex >= '0' && hex <= '9') {
                  hex -= '0';
                } else if (hex >= 'a' && hex <= 'f') {
                  hex -= 'a' - 10;
                } else {
                  hex -= 'A' - 10;
                }
                res += hex * pow(16, n);
              }
            }
          }
          break;
        }
      }
    }
    str[j++] = res;
  }

  ReQL_Obj_t *out = malloc(sizeof(ReQL_Obj_t));

  if (out != NULL) {
    uint8_t *buf = malloc(sizeof(uint8_t) * j);

    if (buf == NULL) {
      free(out); out = NULL;
    } else {
      reql_string_init(out, buf, j);
      reql_string_append(out, str, j);
    }
  }

  free(str);

  return out;
}

static int
reql_number_decode(uint32_t size, uint8_t *json, double *val) {
  double num = 0;
  uint32_t i;
  uint8_t digit = '0';
  for (i=1; i<=size; ++i) {
    digit = json[size - i];
    if (digit == '+') {
    } else if (digit == '-') {
      num *= -1;
    } else if (digit < '0' || digit > '9') {
      break;
    }
    num += (digit - '0') * pow(10, i - 1);
  }
  if (i<=size) {
    uint32_t new_size = size - i - 1;
    if (new_size <= 0) {
      return -1;
    }
    if (digit == 'E' || digit == 'e') {
      double exp = num;
      if (reql_number_decode(new_size, json, &num)) {
        return -1;
      }
      num = pow(num, pow(10, exp));
    } else if (digit == '.') {
      double dec = num;
      if (reql_number_decode(new_size, json, &num)) {
        return -1;
      }
      num += dec * pow(10, -i);
    } else {
      return -1;
    }
  }
  *val = num;
  return 0;
}

static ReQL_Obj_t *
reql_decode_(ReQL_Obj_t *stack, uint8_t *json, uint32_t size) {
  if (json[size - 1] == 0) {
    --size;
  }
  ReQL_Datum_t state = REQL_R_JSON;
  char esc = 0, arr_open = 0, obj_open = 0;
  uint32_t i, str_start = 0;
  for (i=0; i<size; ++i) {
    switch (state) {
      case REQL_R_NUM: {
        switch (json[i]) {
          case '-':
          case '0':
          case '1':
          case '2':
          case '3':
          case '4':
          case '5':
          case '6':
          case '7':
          case '8':
          case '9':
          case '.':
          case '+':
          case 'e':
          case 'E': {
            if (i < size - 1) {
              break;
            } else {
              ++i;
            }
          }
          default: {
            double num;
            if (reql_number_decode(i - str_start, &json[str_start], &num) != 0) {
              return NULL;
            }
            ReQL_Obj_t *obj = malloc(sizeof(ReQL_Obj_t));
            reql_number_init(obj, num);
            reql_array_append(stack, obj);
            state = reql_merge_stack(stack);
            --i;
            break;
          }
        }
        break;
      }
      case REQL_R_STR: {
        switch (json[i]) {
          case '\\': {
            esc = 1;
            break;
          }
          case '"': {
            if (!esc) {
              uint32_t orig_size = i - str_start;

              ReQL_Obj_t *obj = reql_string_decode(orig_size, &json[str_start]);

              if (obj == NULL) {
                return NULL;
              }

              reql_array_append(stack, obj);
              state = reql_merge_stack(stack);
            }
          }
          default: {
            esc = 0;
            break;
          }
        }
        break;
      }
      default: {
        switch (json[i]) {
          case '\t':
          case '\n':
          case '\r':
          case ' ': {
            break;
          }
          case ',': {
            switch (state) {
              case REQL_R_OBJECT:
              case REQL_R_ARRAY: {
                state = REQL_R_JSON;
                break;
              }
              default: return NULL;
            }
            break;
          }
          case ':': {
            switch (state) {
              case REQL_R_OBJECT: {
                state = REQL_R_JSON;
                break;
              }
              default: return NULL;
            }
            break;
          }
          case '[': {
            switch (state) {
              case REQL_R_JSON: {
                ReQL_Obj_t *obj = malloc(sizeof(ReQL_Obj_t));
                ReQL_Obj_t **array = malloc(sizeof(ReQL_Obj_t*) * 10);
                reql_array_init(obj, array, 10);
                reql_array_append(stack, obj);
                ++arr_open;
                break;
              }
              default: return NULL;
            }
            break;
          }
          case '{': {
            switch (state) {
              case REQL_R_JSON: {
                ReQL_Obj_t *obj = malloc(sizeof(ReQL_Obj_t));
                ReQL_Pair_t *pairs = malloc(sizeof(ReQL_Pair_t) * 10);
                reql_object_init(obj, pairs, 10);
                reql_array_append(stack, obj);
                ++obj_open;
                break;
              }
              default: return NULL;
            }
            break;
          }
          case '"': {
            switch (state) {
              case REQL_R_JSON: {
                state = REQL_R_STR;
                str_start = i + 1;
                break;
              }
              default: return NULL;
            }
            break;
          }
          case '-':
          case '0':
          case '1':
          case '2':
          case '3':
          case '4':
          case '5':
          case '6':
          case '7':
          case '8':
          case '9': {
            switch (state) {
              case REQL_R_JSON: {
                state = REQL_R_NUM;
                str_start = i;
                break;
              }
              default: return NULL;
            }
            break;
          }
          case '.':
          case '+':
          case 'e':
          case 'E': {
            switch (state) {
              default: return NULL;
            }
            break;
          }
          case 't': {
            switch (state) {
              case REQL_R_JSON: {
                if (size - i < 4) {
                  return NULL;
                }
                if (memcmp(&json[i], json_true, 4) == 0) {
                  ReQL_Obj_t *obj = malloc(sizeof(ReQL_Obj_t));
                  reql_bool_init(obj, 1);
                  reql_array_append(stack, obj);
                  state = reql_merge_stack(stack);
                  i += 3;
                  break;
                }
                return NULL;
              }
              default: return NULL;
            }
            break;
          }
          case 'f': {
            switch (state) {
              case REQL_R_JSON: {
                if (size - i < 5) {
                  return NULL;
                }
                if (memcmp(&json[i], json_false, 5) == 0) {
                  ReQL_Obj_t *obj = malloc(sizeof(ReQL_Obj_t));
                  reql_bool_init(obj, 0);
                  reql_array_append(stack, obj);
                  state = reql_merge_stack(stack);
                  i += 4;
                  break;
                }
                return NULL;
              }
              default: return NULL;
            }
            break;
          }
          case 'n': {
            switch (state) {
              case REQL_R_JSON: {
                if (size - i < 4) {
                  return NULL;
                }
                if (memcmp(&json[i], json_null, 4) == 0) {
                  ReQL_Obj_t *obj = malloc(sizeof(ReQL_Obj_t));
                  reql_null_init(obj);
                  reql_array_append(stack, obj);
                  state = reql_merge_stack(stack);
                  i += 3;
                  break;
                }
                return NULL;
              }
              default: return NULL;
            }
            break;
          }
          case ']': {
            switch (state) {
              case REQL_R_JSON: {
                if (arr_open == 0) {
                  return NULL;
                }
                if (reql_datum_type(reql_array_last(stack)) != REQL_R_ARRAY) {
                  return NULL;
                }
              }
              case REQL_R_ARRAY: {
                state = reql_merge_stack(stack);
                --arr_open;
                break;
              }
              default: return NULL;
            }
            break;
          }
          case '}': {
            switch (state) {
              case REQL_R_JSON: {
                if (obj_open == 0) {
                  return NULL;
                }
                if (reql_datum_type(reql_array_last(stack)) != REQL_R_OBJECT) {
                  return NULL;
                }
              }
              case REQL_R_OBJECT: {
                state = reql_merge_stack(stack);
                --obj_open;
                break;
              }
              default: return NULL;
            }
            break;
          }
          default: return NULL;
        }
      }
    }
  }

  if (arr_open != 0) {
    return NULL;
  }
  if (obj_open != 0) {
    return NULL;
  }

  ReQL_Obj_t *res = reql_array_pop(stack);

  if (reql_array_last(stack) != NULL) {
    reql_json_destroy(res); res = NULL;
  }

  return res;
}

extern ReQL_Obj_t *
reql_decode(uint8_t *json, uint32_t size) {
  ReQL_Obj_t *stack = malloc(sizeof(ReQL_Obj_t));
  ReQL_Obj_t **arr = malloc(sizeof(ReQL_Obj_t*) * 10);
  reql_array_init(stack, arr, 10);

  ReQL_Obj_t *val = reql_decode_(stack, json, size);

  reql_json_destroy(stack);

  return val;
}
