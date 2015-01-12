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
_reql_merge_stack_val(_ReQL_Op stack, _ReQL_Op val) {
  _ReQL_Datum_t state = _REQL_R_REQL;
  if (val != NULL) {
    state = _REQL_R_JSON;
    _ReQL_Op arr = _reql_array_last(stack);
    if (arr == NULL) {
    } else if (_reql_datum_type(arr) == _REQL_R_ARRAY) {
      _reql_array_append(arr, val);
      state = _REQL_R_ARRAY;
    } else if (_reql_datum_type(arr) == _REQL_R_STR) {
      _ReQL_Op key = _reql_array_pop(stack);
      _ReQL_Op obj = _reql_array_last(stack);
      if (_reql_datum_type(obj) == _REQL_R_OBJECT) {
        _reql_object_add(obj, key, val);
        state = _REQL_R_OBJECT;
      } else {
        _reql_array_append(stack, arr);
        _reql_array_append(stack, val);
      }
    } else {
      _reql_array_append(stack, val);
    }
  }
  return state;
}

static int
_reql_merge_stack(_ReQL_Op stack) {
  return _reql_merge_stack_val(stack, _reql_array_pop(stack));
}

static uint32_t
_reql_string_decode(uint32_t size, uint8_t *json) {
  uint8_t res;
  uint32_t i, j = -1;
  for (i=0; i<size; ++i) {
    res = json[i];
    if (res == 0x5C) { /* \ */
      ++i;
      if (i >= size) {
        return size;
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
            char hex, valid = 1;
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
              res = 0;
              for (n=3; n>=0; --n) {
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
    json[++j] = res;
  }
  return j;
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

static _ReQL_Op
_reql_decode_(_ReQL_Op stack, uint8_t *json, uint32_t size) {
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
            _ReQL_Op obj = malloc(sizeof(_ReQL_Op_t));
            _ReQL_Op *_intern = malloc(sizeof(_ReQL_Op) * 10);
            _reql_array_init(obj, _intern, 10);
            _reql_array_append(stack, obj);
            state = _REQL_R_ARRAY;
            break;
          }
          case 0x7B: { /* { */
            _ReQL_Op obj = malloc(sizeof(_ReQL_Op_t));
            _ReQL_Pair _intern = malloc(sizeof(_ReQL_Pair_t) * 10);
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
            if (strncmp((char *)&json[i], (char *)json_true, 4)) {
              _ReQL_Op obj = malloc(sizeof(_ReQL_Op_t));
              _reql_bool_init(obj, 1);
              state = _reql_merge_stack_val(stack, obj);
              i += 4;
              break;
            }
          }
          case 'f': {
            if (strncmp((char *)&json[i], (char *)json_false, 5)) {
              _ReQL_Op obj = malloc(sizeof(_ReQL_Op_t));
              _reql_bool_init(obj, 1);
              state = _reql_merge_stack_val(stack, obj);
              i += 5;
              break;
            }
          }
          case 'n': {
            if (strncmp((char *)&json[i], (char *)json_null, 4)) {
              _ReQL_Op obj = malloc(sizeof(_ReQL_Op_t));
              _reql_null_init(obj);
              state = _reql_merge_stack_val(stack, obj);
              i += 4;
              break;
            }
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
            _ReQL_Op obj = malloc(sizeof(_ReQL_Op_t));
            _reql_number_init(obj, num);
            state = _reql_merge_stack_val(stack, obj);
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
              _ReQL_Op obj = malloc(sizeof(_ReQL_Op_t));
              _reql_string_init(obj, &json[str_start], _reql_string_decode(i - str_start - 1, &json[str_start]));
              state = _reql_merge_stack_val(stack, obj);
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
  if (state != _REQL_R_JSON || _reql_merge_stack(stack) != _REQL_R_JSON) {
    return NULL;
  }

  _ReQL_Op res = _reql_array_pop(stack);

  if (_reql_array_last(stack)) {
    _reql_json_destroy(res); res = NULL;
  }

  return res;
}

extern _ReQL_Op
_reql_decode(uint8_t *json, uint32_t size) {
  _ReQL_Op stack = malloc(sizeof(_ReQL_Op_t));
  _ReQL_Op *arr = malloc(sizeof(_ReQL_Op) * 10);
  _reql_array_init(stack, arr, 10);

  _ReQL_Op val = _reql_decode_(stack, json, size);

  _reql_json_destroy(stack);

  return val;
}

static void
_reql_arr_destroy(_ReQL_Op *arr, int32_t size) {
  if (arr == NULL) {
    return;
  }

  int32_t i;

  for (i=0; i<size; ++i) {
    _reql_json_destroy(arr[i]);
  }

  free(arr);
}

static void
_reql_pair_destroy(_ReQL_Pair pair, int32_t size) {
  if (pair == NULL) {
    return;
  }

  int32_t i;

  for (i=0; i<size; ++i) {
    _reql_json_destroy(pair[i].key);
    _reql_json_destroy(pair[i].val);
  }
  
  free(pair);
}

extern void
_reql_json_destroy(_ReQL_Op json) {
  if (json == NULL) {
    return;
  }

  switch (_reql_datum_type(json)) {
    case _REQL_R_ARRAY: {
      _reql_arr_destroy(json->obj.datum.json.array.arr, json->obj.datum.json.array.alloc_size);
      break;
    }
    case _REQL_R_BOOL:
    case _REQL_R_JSON:
    case _REQL_R_NULL:
    case _REQL_R_NUM: break;
    case _REQL_R_OBJECT: {
      _reql_pair_destroy(json->obj.datum.json.object.pair, json->obj.datum.json.object.alloc_size);
      break;
    }
    case _REQL_R_REQL: {
      _reql_json_destroy(json->obj.args.args);
      _reql_json_destroy(json->obj.args.kwargs);
      break;
    }
    case _REQL_R_STR: {
      if (json->obj.datum.json.string.str != NULL) {
        free(json->obj.datum.json.string.str);
      }
      break;
    }
  }

  free(json);
}
