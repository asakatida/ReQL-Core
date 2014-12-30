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

#include "ReQL-json.h"

#include <math.h>
#include <stdlib.h>
#include <string.h>

_ReQL_Op _reql_json_number(_ReQL_Op obj, double num) {
  obj = _reql_json_null(obj);
  if (obj) {
    obj->obj.datum.dt = _REQL_R_NUM;
    obj->obj.datum.json.number = num;
  }
  return obj;
}

int _reql_to_number(_ReQL_Op obj, double *num) {
  if (obj) {
    if (obj->tt != _REQL_DATUM) {
      return -1;
    }
    if (obj->obj.datum.dt == _REQL_R_NUM) {
      *num = obj->obj.datum.json.number;
      return 0;
    }
  }
  return -1;
}

_ReQL_Op _reql_json_string(_ReQL_Op obj, char *str, unsigned long size) {
  _ReQL_String_t *r_str = _reql_string(NULL, str, size);

  if (!r_str) {
    return NULL;
  }

  obj = _reql_json_null(obj);

  if (obj) {
    obj->obj.datum.dt = _REQL_R_STR;
    obj->obj.datum.json.string = r_str;
  }

  return obj;
}

int _reql_to_string(_ReQL_Op obj, _ReQL_String *str) {
  int err = -1;
  if (obj) {
    if (obj->tt != _REQL_DATUM) {
      return -1;
    }
    if (obj->obj.datum.dt == _REQL_R_STR) {
      if (obj->obj.datum.json.string) {
        *str = obj->obj.datum.json.string;
        err = 0;
      }
    }
  }
  return err;
}

_ReQL_Iter _reql_iter(_ReQL_Op obj) {
  _ReQL_Iter res = malloc(sizeof(_ReQL_Iter_t));

  if (res) {
    res->idx = 0;
    res->obj = obj;
  }

  return res;
}

void _reql_iter_free(_ReQL_Iter obj) {
  free(obj); obj = NULL;
}

_ReQL_Op _reql_json_array_(_ReQL_Op obj, unsigned long size) {
  _ReQL_Op *arr = malloc(sizeof(_ReQL_Op) * size);

  if (!arr) {
    return NULL;
  }

  unsigned long i;

  for (i=0; i<size; ++i) {
    arr[i] = NULL;
  }

  obj = _reql_json_null(obj);

  if (obj) {
    obj->obj.datum.dt = _REQL_R_ARRAY;
    obj->obj.datum.json.array.arr = arr;
    obj->obj.datum.json.array.alloc_size = size;
    obj->obj.datum.json.array.size = 0;
  } else {
    free(arr);
  }

  return obj;
}

int _reql_to_array_(_ReQL_Op obj, unsigned long *size) {
  int err = -1;
  if (obj) {
    if (obj->tt != _REQL_DATUM) {
      return -1;
    }
    if (obj->obj.datum.dt == _REQL_R_ARRAY) {
      if (size) {
        *size = obj->obj.datum.json.array.size;
      }
      err = 0;
    }
  }
  return err;
}

int _reql_array_insert(_ReQL_Op obj, _ReQL_Op val, unsigned long idx) {
  if (!obj) {
    return -1;
  }

  if (idx >= obj->obj.datum.json.array.alloc_size) {
    obj->obj.datum.json.array.alloc_size = idx;
    obj->obj.datum.json.array.alloc_size *= 1.1;

    _ReQL_Op *arr = obj->obj.datum.json.array.arr;
    arr = realloc(arr, obj->obj.datum.json.array.alloc_size);

    if (!arr) {
      obj->obj.datum.json.array.alloc_size = 0;
      obj->obj.datum.json.array.size = 0;
      return -1;
    }

    unsigned long i;

    for (i=obj->obj.datum.json.array.size; i<obj->obj.datum.json.array.alloc_size; ++i) {
      arr[i] = NULL;
    }

    obj->obj.datum.json.array.arr = arr;
  }

  if (idx > obj->obj.datum.json.array.size) {
    obj->obj.datum.json.array.size = idx;
  }

  _reql_expr_free(obj->obj.datum.json.array.arr[idx]);

  obj->obj.datum.json.array.arr[idx] = val;

  return 0;
}

_ReQL_Op _reql_array_index(_ReQL_Op obj, unsigned long idx) {
  if ((!obj) || obj->obj.datum.json.array.alloc_size <= idx) {
    return NULL;
  }

  return obj->obj.datum.json.array.arr[idx];
}

_ReQL_Op _reql_json_array(_ReQL_Op obj) {
  return _reql_json_array_(obj, 10);
}

_ReQL_Iter _reql_to_array(_ReQL_Op obj) {
  if (_reql_to_array_(obj, NULL)) {
    return NULL;
  }
  return _reql_iter(obj);
}

int _reql_array_append(_ReQL_Op obj, _ReQL_Op val) {
  unsigned long size;

  if (_reql_to_array_(obj, &size)) {
    return -1;
  }

  ++size;

  return _reql_array_insert(obj, val, size);
}

int _reql_array_next(_ReQL_Iter obj, _ReQL_Op *val) {
  if (!obj) {
    return -1;
  }

  unsigned long size;

  if (_reql_to_array_(obj->obj, &size)) {
    return -1;
  }

  if (obj->idx >= size) {
    return -1;
  }

  *val = _reql_array_index(obj->obj, obj->idx);

  obj->idx += 1;

  return 0;
}

_ReQL_Op _reql_array_pop(_ReQL_Op obj) {
  _ReQL_Op res = _reql_array_last(obj);

  if (res) {
    obj->obj.datum.json.array.size -= 1;
  }

  return res;
}

_ReQL_Op _reql_array_last(_ReQL_Op obj) {
  unsigned long size;

  if (_reql_to_array_(obj, &size)) {
    return NULL;
  }

  return _reql_array_index(obj, size);
}

_ReQL_Op _reql_json_object(_ReQL_Op obj) {
  _ReQL_Pair_t *pairs = malloc(sizeof(_ReQL_Pair_t) * 10);

  if (!pairs) {
    return NULL;
  }

  unsigned long i;

  for (i=0; i<10; ++i) {
    pairs[i].key = NULL;
    pairs[i].val = NULL;
  }

  obj = _reql_json_null(obj);

  if (obj) {
    obj->obj.datum.dt = _REQL_R_OBJECT;
    obj->obj.datum.json.object.pair = pairs;
    obj->obj.datum.json.object.size = 0;
    obj->obj.datum.json.object.alloc_size = 10;
  } else {
    free(pairs);
  }

  return obj;
}

_ReQL_Iter _reql_to_object(_ReQL_Op obj) {
  if (obj) {
    if (obj->tt == _REQL_DATUM) {
      if (obj->obj.datum.dt == _REQL_R_OBJECT) {
        return _reql_iter(obj);
      }
    }
  }
  return NULL;
}

int _reql_op_eq(_ReQL_Op l, _ReQL_Op r) {
  int res = 0;
  if (l == r) {
    res = 1;
  } else {
    if ((l && r)) {
      if (l->tt == r->tt) {
        if (l->tt == _REQL_DATUM) {
          if (l->obj.datum.dt == r->obj.datum.dt) {
            switch (l->obj.datum.dt) {
              case _REQL_R_ARRAY: {
                unsigned long larr_size, rarr_size;
                if (_reql_to_array_(l, &larr_size) || _reql_to_array_(r, &rarr_size)) {
                  break;
                }
                if (larr_size == rarr_size) {
                  res = 1;
                  unsigned long i;
                  for (i=0; i<larr_size; ++i) {
                    res &= _reql_op_eq(_reql_array_index(l, i), _reql_array_index(r, i));
                  }
                }
                break;
              }
              case _REQL_R_BOOL: {
                char lval, rval;
                if (_reql_to_bool(l, &lval) || _reql_to_bool(r, &rval)) {
                  break;
                }
                res = lval == rval;
                break;
              }
              case _REQL_R_JSON: break;
              case _REQL_R_NULL: {
                res = 1;
                break;
              }
              case _REQL_R_NUM: {
                double lval, rval;
                if (_reql_to_number(l, &lval) || _reql_to_number(r, &rval)) {
                  break;
                }
                res = lval == rval;
                break;
              }
              case _REQL_R_OBJECT: {
                _ReQL_Iter i = _reql_to_object(l);
                if (!i) {
                  break;
                }
                res = 1;
                _ReQL_Op key = NULL;
                _ReQL_Op val = NULL;

                while (!_reql_object_next(i, &key, &val)) {
                  res &= _reql_op_eq(val, _reql_object_get(r, key));
                }

                _reql_iter_free(i); i = _reql_to_object(r);

                while (!_reql_object_next(i, &key, &val)) {
                  res &= _reql_op_eq(val, _reql_object_get(l, key));
                }

                _reql_iter_free(i); i = NULL;
                break;
              }
              case _REQL_R_STR: {
                _ReQL_String_t *rstr;
                _ReQL_String_t *lstr;
                if (_reql_to_string(l, &lstr) || _reql_to_string(r, &rstr)) {
                  break;
                }
                if (lstr->size == rstr->size) {
                  res = !memcmp(lstr->str, rstr->str, lstr->size);
                }
                break;
              }
            }
          }
        } else {
          if (_reql_op_eq(l->obj.args.args, r->obj.args.args)) {
            res = _reql_op_eq(l->obj.args.kwargs, r->obj.args.kwargs);
          }
        }
      }
    }
  }
  return res;
}

int _reql_object_add(_ReQL_Op obj, _ReQL_Op key, _ReQL_Op val) {
  if (!(obj && key)) {
    return -1;
  }

  _ReQL_Pair_t *pair = obj->obj.datum.json.object.pair;

  unsigned long idx;

  for (idx=0; idx<obj->obj.datum.json.object.size; ++idx) {
    if (_reql_op_eq(pair[idx].key, key)) {
      _reql_expr_free(pair[idx].key); pair[idx].key = NULL;
      break;
    }
  }

  if (pair[idx].key) {
    ++idx;
  }

  if (idx >= obj->obj.datum.json.object.alloc_size) {
    obj->obj.datum.json.object.alloc_size *= 1.1;

    pair = realloc(pair, obj->obj.datum.json.object.alloc_size);

    if (!pair) {
      obj->obj.datum.json.object.alloc_size = 0;
      obj->obj.datum.json.object.size = 0;
      return -1;
    }

    unsigned long i;

    for (i=obj->obj.datum.json.array.size; i<obj->obj.datum.json.array.alloc_size; ++i) {
      pair[i].key = NULL;
      pair[i].val = NULL;
    }

    obj->obj.datum.json.object.pair = pair;
  }

  if (idx > obj->obj.datum.json.object.size) {
    obj->obj.datum.json.object.size = idx;
  }

  pair[idx].key = key;
  pair[idx].val = val;

  return 0;
}

int _reql_object_next(_ReQL_Iter obj, _ReQL_Op *key, _ReQL_Op *val) {
  if (!obj) {
    return -1;
  }

  if (!obj) {
    return -1;
  }

  unsigned long size = obj->obj->obj.datum.json.object.size;

  if (obj->idx >= size) {
    return -1;
  }

  if (obj->obj->obj.datum.json.object.pair[obj->idx].key) {
    if (key && val) {
      *key = obj->obj->obj.datum.json.object.pair[obj->idx].key;
      *val = obj->obj->obj.datum.json.object.pair[obj->idx].val;
    }
  }

  obj->idx += 1;

  return 0;
}

_ReQL_Op _reql_object_get(_ReQL_Op obj, _ReQL_Op key) {
  if (!key) {
    return NULL;
  }

  _ReQL_Iter iter = _reql_to_object(obj);

  if (!iter) {
    return NULL;
  }

  _ReQL_Op _key = NULL, val = NULL;

  while (!_reql_object_next(iter, &_key, &val)) {
    if (_reql_op_eq(key, _key)) {
      return val;
    }
  }

  return NULL;
}

_ReQL_Op _reql_json_null(_ReQL_Op obj) {
  if (!obj) {
    obj = malloc(sizeof(_ReQL_Op_t));
  }
  if (obj) {
    obj->tt = _REQL_DATUM;
    obj->obj.datum.dt = _REQL_R_NULL;
  }
  return obj;
}

int _reql_to_null(_ReQL_Op obj) {
  if (!obj) {
    return -1;
  }
  if (obj->tt != _REQL_DATUM) {
    return -1;
  }
  if (obj->obj.datum.dt == _REQL_R_NULL) {
    return 0;
  }
  return -1;
}

_ReQL_Op _reql_json_bool(_ReQL_Op obj, char val) {
  obj = _reql_json_null(obj);
  if (obj) {
    obj->obj.datum.dt = _REQL_R_BOOL;
    obj->obj.datum.json.boolean = val;
  }
  return obj;
}

int _reql_to_bool(_ReQL_Op obj, char *val) {
  if (obj) {
    if (obj->tt != _REQL_DATUM) {
      return -1;
    }
    if (obj->obj.datum.dt == _REQL_R_BOOL) {
      *val = obj->obj.datum.json.number;
      return 0;
    }
  }
  return -1;
}

_ReQL_Op _reql_expr_copy(_ReQL_Op obj) {
  if (!obj) {
    return NULL;
  }

  _ReQL_Op res = NULL;

  if (obj->tt == _REQL_DATUM) {
    switch (obj->obj.datum.dt) {
      case _REQL_R_ARRAY: {
        unsigned long size;
        if (_reql_to_array_(obj, &size)) {
          break;
        }
        res = _reql_json_array_(NULL, size);
        unsigned long i;
        for (i=0; i<size; ++i) {
          _reql_array_insert(obj, _reql_expr_copy(_reql_array_index(obj, i)), i);
        }
        break;
      }
      case _REQL_R_BOOL: {
        char val;
        if (_reql_to_bool(obj, &val)) {
          break;
        }
        res = _reql_json_bool(NULL, val);
        break;
      }
      case _REQL_R_JSON: {
        break;
      }
      case _REQL_R_NULL: {
        obj = _reql_json_null(NULL);
        break;
      }
      case _REQL_R_NUM: {
        double val;
        if (_reql_to_number(obj, &val)) {
          break;
        }
        res = _reql_json_number(NULL, val);
        break;
      }
      case _REQL_R_OBJECT: {
        _ReQL_Iter iter = _reql_to_object(obj);
        if (!iter) {
          break;
        }
        res = _reql_json_object(NULL);
        _ReQL_Op key;
        _ReQL_Op val;
        while (!_reql_object_next(iter, &key, &val)) {
          _reql_object_add(res, _reql_expr_copy(key), _reql_expr_copy(val));
        }
        break;
      }
      case _REQL_R_STR: {
        _ReQL_String_t *str;
        if (_reql_to_string(obj, &str)) {
          break;
        }
        res = _reql_json_string(NULL, str->str, str->size);
        break;
      }
    }
  } else {
    res = _reql_json_null(NULL);
    res->tt = obj->tt;
    res->obj.args.args = _reql_expr_copy(obj->obj.args.args);
    res->obj.args.kwargs = _reql_expr_copy(obj->obj.args.kwargs);
  }
  return res;
}

void _reql_expr_free(_ReQL_Op obj) {
  if (!obj) {
    return;
  }

  if (obj->tt == _REQL_DATUM) {
    switch (obj->obj.datum.dt) {
      case _REQL_R_ARRAY: {
        unsigned long i;

        for (i=0; i<obj->obj.datum.json.array.alloc_size; ++i) {
          _reql_expr_free(obj->obj.datum.json.array.arr[i]);
        }

        free(obj->obj.datum.json.array.arr);
        break;
      }
      case _REQL_R_BOOL:
      case _REQL_R_JSON:
      case _REQL_R_NULL:
      case _REQL_R_NUM: break;
      case _REQL_R_OBJECT: {
        unsigned long i;

        for (i=0; i<obj->obj.datum.json.object.alloc_size; ++i) {
          _reql_expr_free(obj->obj.datum.json.object.pair[i].key);
          _reql_expr_free(obj->obj.datum.json.object.pair[i].val);
        }

        free(obj->obj.datum.json.object.pair);
        break;
      }
      case _REQL_R_STR: {
        _reql_string_free(obj->obj.datum.json.string);
        break;
      }
    }
  } else {
    _reql_expr_free(obj->obj.args.args);
    _reql_expr_free(obj->obj.args.args);
  }

  free(obj);
}

int _reql_merge_stack_val(_ReQL_Op stack, _ReQL_Op val) {
  int state = -1;
  if (val) {
    state = _REQL_R_JSON;
    _ReQL_Op arr = _reql_array_last(stack);
    if (_reql_to_array(arr)) {
      _reql_array_append(arr, val);
      state = _REQL_R_ARRAY;
    } else if (arr && !_reql_to_object(arr)) {
      _ReQL_Op key = _reql_array_pop(stack);
      _ReQL_Op obj = _reql_array_last(stack);
      if (_reql_to_object(obj)) {
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

int _reql_merge_stack(_ReQL_Op stack) {
  return _reql_merge_stack_val(stack, _reql_array_pop(stack));
}

_ReQL_Op _reql_string_decode(unsigned long size, char *json) {
  char *utf8_str = malloc(sizeof(char) * size);
  char res;
  unsigned long i, j = 0;
  for (i=0; i<size; ++i) {
    res = json[i];
    if (res == '\\') {
      ++i;
      if (i >= size) {
        free(utf8_str);
        return NULL;
      }
      switch (json[i]) {
        case 'b': {
          res = '\b';
          break;
        }
        case 'f': {
          res = '\f';
          break;
        }
        case 'n': {
          res = '\n';
          break;
        }
        case 'r': {
          res = '\r';
          break;
        }
        case 't': {
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
    utf8_str[j++] = res;
  }
  _ReQL_Op str = _reql_json_string(NULL, utf8_str, j);
  free(utf8_str);
  return str;
}

int _reql_number_decode(unsigned long size, char *json, double *val) {
  double num = 0;
  unsigned long i;
  char digit = '0';
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
    long new_size = size - i - 1;
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

_ReQL_Op _reql_json_decode_(_ReQL_Op stack, _ReQL_String_t *json) {
  _ReQL_Datum_t state = _REQL_R_JSON;
  char esc = 0;
  unsigned long i, str_start = 0;
  for (i=0; i<json->size; ++i) {
    switch (state) {
      case _REQL_R_ARRAY: {
        switch (json->str[i]) {
          case ',': {
            state = _REQL_R_JSON;
            break;
          }
          case ']': {
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
        switch (json->str[i]) {
          case '\t':
          case '\n':
          case '\r':
          case ' ': {
            break;
          }
          case '[': {
            _reql_array_append(stack, _reql_json_array(NULL));
            state = _REQL_R_ARRAY;
            break;
          }
          case '{': {
            _reql_array_append(stack, _reql_json_object(NULL));
            state = _REQL_R_OBJECT;
            break;
          }
          case '"': {
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
            if (strncmp(&json->str[i], "true", 4)) {
              state = _reql_merge_stack_val(stack, _reql_json_bool(NULL, 1));
              i += 4;
              break;
            }
          }
          case 'f': {
            if (strncmp(&json->str[i], "false", 5)) {
              state = _reql_merge_stack_val(stack, _reql_json_bool(NULL, 0));
              i += 5;
              break;
            }
          }
          case 'n': {
            if (strncmp(&json->str[i], "null", 4)) {
              state = _reql_merge_stack_val(stack, _reql_json_null(NULL));
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
        switch (json->str[i]) {
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
            if (_reql_number_decode(i - str_start - 1, &json->str[str_start], &num)) {
              return NULL;
            }
            state = _reql_merge_stack_val(stack, _reql_json_number(NULL, num));
            --i;
          }
        }
        break;
      }
      case _REQL_R_OBJECT: {
        switch (json->str[i]) {
          case ',':
          case ':': {
            state = _REQL_R_JSON;
            break;
          }
          case '}': {
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
        switch (json->str[i]) {
          case '\\': {
            esc = 1;
            break;
          }
          case '"': {
            if (!esc) {
              _ReQL_Op str = _reql_string_decode(i - str_start - 1, &json->str[str_start]);
              if (!str) {
                return NULL;
              }
              state = _reql_merge_stack_val(stack, str);
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
      default: {
        return NULL;
      }
    }
  }
  if (state != _REQL_R_JSON || _reql_merge_stack(stack) != _REQL_R_JSON) {
    return NULL;
  }

  _ReQL_Op res = _reql_array_pop(stack);

  _ReQL_Op extra = _reql_array_pop(stack);

  if (extra) {
    _reql_expr_free(extra); extra = NULL;
    _reql_expr_free(res); res = NULL;
  }

  return res;
}

_ReQL_Op _reql_json_decode(_ReQL_String_t *json) {
  _ReQL_Op stack = _reql_json_array(NULL);
  _ReQL_Op val = _reql_json_decode_(stack, json);
  _reql_expr_free(stack);

  return val;
}

_ReQL_String_t *_reql_string(_ReQL_String_t *str, char *buf, unsigned long size) {
  if (!str) {
    str = malloc(sizeof(_ReQL_String_t));
  }
  if (str) {
    str->size = 0;
    str->alloc_size = size;
    if (!str->alloc_size) {
      str->alloc_size = 100;
    }
    str->str = malloc(sizeof(char) * str->alloc_size);
    if (!str->str) {
      free(str); str = NULL;
    }
    if (buf) {
      if (_reql_string_append(str, buf, size)) {
        free(str); str = NULL;
      }
    }
  }
  return str;
}

int _reql_string_append(_ReQL_String_t *orig, char *ext, unsigned long size) {
  if (!orig) {
    return -1;
  }

  if ((orig->size + size) > orig->alloc_size) {
    orig->alloc_size *= 1.1;
    orig->alloc_size += size;
    orig->str = realloc(orig->str, orig->alloc_size);
    if (!orig->str) {
      orig->alloc_size = 0;
      orig->size = 0;
      return -1;
    }
  }

  orig->str = memcpy(&orig->str[orig->size + 1], ext, sizeof(char) * size);

  orig->size += size;

  return 0;
}

void _reql_string_free(_ReQL_String_t *str) {
  if (!str) {
    return;
  }

  if (str->str) {
    free(str->str);
  }

  free(str);
}

int _reql_string_append_(_ReQL_String_t *orig, char ext) {
  if (!orig) {
    return -1;
  }

  if (orig->size >= orig->alloc_size) {
    char new[1] = {ext};
    return _reql_string_append(orig, new, 1);
  }

  orig->size += 1;

  orig->str[orig->size] = ext;

  return 0;
}

int _reql_json_encode_(_ReQL_Op obj, _ReQL_String_t *json) {
  if (!json) {
    return -1;
  }

  int err = -1;

  switch (obj->obj.datum.dt) {
    case _REQL_R_ARRAY: {
      unsigned long size;
      if (_reql_to_array_(obj, &size)) {
        break;
      }
      err = 0;
      unsigned long i;
      for (i=0; i<size; ++i) {
        if (i) {
          if (_reql_string_append_(json, ',')) {
            err = -1;
            break;
          }
        }
        if (_reql_json_encode_(_reql_array_index(obj, i), json)) {
          err = -1;
          break;
        }
      }
      break;
    }
    case _REQL_R_BOOL: {
      char val;
      if (_reql_to_bool(obj, &val)) {
        break;
      }
      if (val) {
        if (_reql_string_append(json, "true", 4)) {
          break;
        }
      } else {
        if (_reql_string_append(json, "false", 5)) {
          break;
        }
      }
      err = 0;
      break;
    }
    case _REQL_R_JSON: {
      break;
    }
    case _REQL_R_NULL: {
      err = _reql_string_append(json, "null", 4);
      break;
    }
    case _REQL_R_NUM: {
      double val;
      if (_reql_to_number(obj, &val)) {
        break;
      }
      err = 0;
      break;
    }
    case _REQL_R_OBJECT: {
      _ReQL_Iter iter = _reql_to_object(obj);
      if (!iter) {
        break;
      }
      char first = 1;
      _ReQL_Op key;
      _ReQL_Op val;
      err = 0;
      while (!_reql_object_next(iter, &key, &val)) {
        if (!first) {
          if (_reql_string_append_(json, ',')) {
            err = -1;
            break;
          }
        }
        if (_reql_json_encode_(key, json)) {
          err = -1;
          break;
        }
        if (_reql_string_append_(json, ':')) {
          err = -1;
          break;
        }
        if (_reql_json_encode_(val, json)) {
          err = -1;
          break;
        }
        first = 0;
      }
      break;
    }
    case _REQL_R_STR: {
      if (_reql_string_append_(json, '"')) {
        break;
      }
      _ReQL_String_t *str;
      if (_reql_to_string(obj, &str)) {
        break;
      }
      if (_reql_string_append(json, str->str, str->size)) {
        break;
      }
      if (_reql_string_append_(json, '"')) {
        break;
      }
      err = 0;
      break;
    }
  }

  return err;
}

_ReQL_String_t *_reql_json_encode(_ReQL_Op val) {
  _ReQL_String_t *json = _reql_string(NULL, NULL, 0);

  if (_reql_json_encode_(val, json)) {
    _reql_string_free(json);
    return NULL;
  }

  return json;
}
