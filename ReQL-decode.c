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

static _ReQL_Datum_t
_reql_bad_pair(_ReQL_Obj_t *stack, _ReQL_Obj_t *key, _ReQL_Obj_t *val) {
  _reql_array_append(stack, key);
  _reql_array_append(stack, val);
  return _REQL_R_JSON;
}

static _ReQL_Datum_t
_reql_merge_stack_pair(_ReQL_Obj_t *stack, _ReQL_Obj_t *key, _ReQL_Obj_t *val) {
  if (_reql_datum_type(key) != _REQL_R_STR) {
    return _reql_bad_pair(stack, key, val);
  }

  _ReQL_Obj_t *obj = _reql_array_last(stack);

  if (obj == NULL) {
    return _reql_bad_pair(stack, key, val);
  }

  if (_reql_datum_type(obj) != _REQL_R_OBJECT) {
    return _reql_bad_pair(stack, key, val);
  }

  _reql_object_add(obj, key, val);
  return _REQL_R_OBJECT;
}

static _ReQL_Datum_t
_reql_merge_stack_val(_ReQL_Obj_t *stack, _ReQL_Obj_t *val) {
  _ReQL_Obj_t *arr = _reql_array_last(stack);

  if (arr == NULL) {
    _reql_array_append(stack, val);
    return _REQL_R_JSON;
  }

  if (_reql_datum_type(arr) != _REQL_R_ARRAY) {
    return _reql_merge_stack_pair(stack, _reql_array_pop(stack), val);
  }

  _reql_array_append(arr, val);
  return _REQL_R_ARRAY;
}

static _ReQL_Datum_t
_reql_merge_stack(_ReQL_Obj_t *stack) {
  _ReQL_Obj_t *val = _reql_array_pop(stack);

  if (val == NULL) {
    return _REQL_R_REQL;
  }

  return _reql_merge_stack_val(stack, val);
}

static _ReQL_Obj_t *
_reql_string_decode(uint32_t size, uint8_t *json) {
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

  str = realloc(str, sizeof(uint8_t) * j);

  _ReQL_Obj_t *out = malloc(sizeof(_ReQL_Obj_t));

  if (out == NULL) {
    free(str);
    return NULL;
  }

  _reql_string_init(out, str, j);

  return out;
}

static int
_reql_number_decode(uint32_t size, uint8_t *json, double *val) {
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
      if (_reql_number_decode(new_size, json, &num)) {
        return -1;
      }
      num = pow(num, pow(10, exp));
    } else if (digit == '.') {
      double dec = num;
      if (_reql_number_decode(new_size, json, &num)) {
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

static _ReQL_Obj_t *
_reql_decode_(_ReQL_Obj_t *stack, uint8_t *json, uint32_t size) {
  if (json[size - 1] == 0) {
    --size;
  }
  _ReQL_Datum_t state = _REQL_R_JSON;
  char esc = 0;
  uint32_t i, str_start = 0;
  for (i=0; i<size; ++i) {
    switch (state) {
      case _REQL_R_ARRAY: {
        switch (json[i]) {
          case 0x2C: { /* , */
            state = _REQL_R_JSON;
            break;
          }
          case 0x5D: { /* ] */
            state = _reql_merge_stack(stack);
            break;
          }
          default: {
            return NULL;
          }
        }
        break;
      }
      case _REQL_R_JSON: {
        switch (json[i]) {
          case '\t':
          case '\n':
          case '\r':
          case ' ': {
            break;
          }
          case 0x5B: { /* [ */
            _ReQL_Obj_t *obj = malloc(sizeof(_ReQL_Obj_t));
            _ReQL_Obj_t **_intern = malloc(sizeof(_ReQL_Obj_t*) * 10);
            _reql_array_init(obj, _intern, 10);
            _reql_array_append(stack, obj);
            state = _REQL_R_ARRAY;
            break;
          }
          case 0x7B: { /* { */
            _ReQL_Obj_t *obj = malloc(sizeof(_ReQL_Obj_t));
            _ReQL_Pair_t *_intern = malloc(sizeof(_ReQL_Pair_t) * 10);
            _reql_object_init(obj, _intern, 10);
            _reql_array_append(stack, obj);
            state = _REQL_R_OBJECT;
            break;
          }
          case 0x22: { /* " */
            state = _REQL_R_STR;
            str_start = i + 1;
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
            state = _REQL_R_NUM;
            str_start = i;
            break;
          }
          case 't': {
            if (memcmp(&json[i], json_true, 4) == 0) {
              _ReQL_Obj_t *obj = malloc(sizeof(_ReQL_Obj_t));
              _reql_bool_init(obj, 1);
              _reql_array_append(stack, obj);
              state = _reql_merge_stack(stack);
              i += 4;
              break;
            }
            return NULL;
          }
          case 'f': {
            if (memcmp(&json[i], json_false, 5) == 0) {
              _ReQL_Obj_t *obj = malloc(sizeof(_ReQL_Obj_t));
              _reql_bool_init(obj, 1);
              _reql_array_append(stack, obj);
              state = _reql_merge_stack(stack);
              i += 5;
              break;
            }
            return NULL;
          }
          case 'n': {
            if (memcmp(&json[i], json_null, 4) == 0) {
              _ReQL_Obj_t *obj = malloc(sizeof(_ReQL_Obj_t));
              _reql_null_init(obj);
              _reql_array_append(stack, obj);
              state = _reql_merge_stack(stack);
              i += 4;
              break;
            }
            return NULL;
          }
          default: {
            return NULL;
          }
        }
        break;
      }
      case _REQL_R_NUM: {
        switch (json[i]) {
          case '-':
          case '.':
          case '+':
          case 'e':
          case 'E':
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
            break;
          }
          default: {
            double num;
            if (_reql_number_decode(i - str_start - 1, &json[str_start], &num)) {
              return NULL;
            }
            _ReQL_Obj_t *obj = malloc(sizeof(_ReQL_Obj_t));
            _reql_number_init(obj, num);
            _reql_array_append(stack, obj);
            state = _reql_merge_stack(stack);
            --i;
          }
        }
        break;
      }
      case _REQL_R_OBJECT: {
        switch (json[i]) {
          case 0x2C: /* , */
          case 0x3A: { /* : */
            state = _REQL_R_JSON;
            break;
          }
          case 0x7D: { /* } */
            state = _reql_merge_stack(stack);
            break;
          }
          default: {
            return NULL;
          }
        }
        break;
      }
      case _REQL_R_STR: {
        switch (json[i]) {
          case '\\': {
            esc = 1;
            break;
          }
          case 0x22: { /* " */
            if (!esc) {
              uint32_t orig_size = i - str_start - 1;

              _ReQL_Obj_t *obj = _reql_string_decode(orig_size, &json[str_start]);

              if (obj == NULL) {
                return NULL;
              }

              _reql_array_append(stack, obj);
              state = _reql_merge_stack(stack);
              break;
            }
          }
          default: {
            esc = 0;
          }
        }
        break;
      }
      case _REQL_R_NULL:
      case _REQL_R_BOOL:
      case _REQL_R_REQL: return NULL;
    }
  }
  switch (state) {
    case _REQL_R_NUM: {
      double num;
      if (_reql_number_decode(i - str_start, &json[str_start], &num) == 0) {
        _ReQL_Obj_t *obj = malloc(sizeof(_ReQL_Obj_t));
        _reql_number_init(obj, num);
        _reql_array_append(stack, obj);
        state = _reql_merge_stack(stack);
      }
    }
    case _REQL_R_JSON: break;
    case _REQL_R_ARRAY:
    case _REQL_R_BOOL:
    case _REQL_R_NULL:
    case _REQL_R_OBJECT:
    case _REQL_R_REQL:
    case _REQL_R_STR: return NULL;
  }

  _ReQL_Obj_t *res = _reql_array_pop(stack);

  if (_reql_array_last(stack)) {
    _reql_json_destroy(res); res = NULL;
  }

  return res;
}

extern _ReQL_Obj_t *
_reql_decode(uint8_t *json, uint32_t size) {
  _ReQL_Obj_t *stack = malloc(sizeof(_ReQL_Obj_t));
  _ReQL_Obj_t **arr = malloc(sizeof(_ReQL_Obj_t*) * 10);
  _reql_array_init(stack, arr, 10);

  _ReQL_Obj_t *val = _reql_decode_(stack, json, size);

  _reql_json_destroy(stack);

  return val;
}
