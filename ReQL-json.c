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

#include <math.h>
#include <stdlib.h>
#include <string.h>

_ReQL_Op _reql_json_number(_ReQL_Op obj, double num) {
  obj = _reql_json_null(obj);
  if (obj) {
    obj->dt = _REQL_R_NUM;
    obj->num = num;
  }
  return obj;
}

int _reql_to_number(_ReQL_Op obj, double *num) {
  if (obj) {
    if (obj->dt == _REQL_R_NUM) {
      *num = obj->num;
      return 0;
    }
  }
  return -1;
}

_ReQL_Op _reql_json_string(_ReQL_Op obj, char *str, unsigned long str_len) {
  char *copy = malloc(sizeof(char) * str_len);
  copy = memcpy(copy, str, str_len);

  if (copy) {
    obj = _reql_json_null(obj);

    if (obj) {
      obj->dt = _REQL_R_STR;
      obj->str = _reql_c_string(NULL, str, str_len);
    } else {
      free(copy);
    }

    return obj;
  }

  return NULL;
}

int _reql_to_string(_ReQL_Op obj, _ReQL_C_String_t **str) {
  int err = -1;
  if (obj) {
    if (obj->dt == _REQL_R_STR) {
      if (obj->str) {
        *str = obj->str;
        err = 0;
      }
    }
  }
  return err;
}

_ReQL_Op _reql_iter(_ReQL_Op obj) {
  if (!obj) {
    return NULL;
  }
  _ReQL_Op res = obj;
  while (res->prev != res) {
    res = res->prev;
    if (res == obj) {
      return NULL;
    }
  }
  return res;
}

int _reql_iter_next(_ReQL_Op *obj) {
  if (!obj) {
    return -1;
  }
  if (!*obj) {
    return -1;
  }
  if (*obj == (*obj)->next) {
    return -1;
  }
  *obj = (*obj)->next;
  return 0;
}

_ReQL_Op _reql_json_c_array(_ReQL_Op obj, unsigned long size) {
  if (!obj) {
    obj = malloc(sizeof(_ReQL_Op_t) * size);
  }
  if (obj) {
    unsigned long i;
    for (i=0; i<size; ++i) {
      _reql_json_null(&obj[i]);
      obj[i].tt = _REQL_DATUM;
      obj[i].dt = _REQL_C_ARRAY;
      obj[i].num = size - i;
    }
  }
  return _reql_expr(obj);
}

int _reql_to_c_array(_ReQL_Op obj, unsigned long *size) {
  int err = -1;
  if (obj) {
    if (obj->dt == _REQL_C_ARRAY) {
      *size = obj->num;
      err = 0;
    }
  }
  return err;
}

int _reql_c_array_insert(_ReQL_Op obj, _ReQL_Op val, unsigned long idx) {
  if ((!(obj && val)) || obj->num <= idx) {
    return -1;
  }

  _reql_expr_free(obj[idx].val);

  obj[idx].val = val;

  return 0;
}

_ReQL_Op _reql_c_array_index(_ReQL_Op obj, unsigned long idx) {
  if ((!obj) || obj->num <= idx) {
    return NULL;
  }
  return obj[idx].val;
}

_ReQL_Op _reql_json_array(_ReQL_Op obj) {
  obj = _reql_json_null(obj);
  if (obj) {
    obj->dt = _REQL_R_ARRAY;
    obj->next = obj->prev = obj;
    obj->val = NULL;
  }
  return obj;
}

_ReQL_Op _reql_to_array(_ReQL_Op obj) {
  _ReQL_Op err = NULL;
  if (obj) {
    if (obj->dt == _REQL_R_ARRAY) {
      err = _reql_iter(obj);
    }
  }
  return err;
}

int _reql_array_append(_ReQL_Op obj, _ReQL_Op val) {
  if (!(obj && val)) {
    return -1;
  }

  while (obj->next != obj) {
    obj = obj->next;
  }
  if (obj->val) {
    obj->next = _reql_json_array(NULL);
    obj->next->prev = obj;
    obj = obj->next;
    obj->next = obj;
  }
  obj->val = val;

  return 0;
}

int _reql_array_next(_ReQL_Op *obj, _ReQL_Op *val) {
  int err = -1;

  if (val) {
    if (!_reql_iter_next(obj)) {
      if ((*obj)->val) {
        *val = (*obj)->val;
        err = 0;
      }
    }
  }

  return err;
}

_ReQL_Op _reql_array_pop(_ReQL_Op obj) {
  _ReQL_Op res = NULL;

  obj = _reql_to_array(obj);

  if (obj) {
    while (!_reql_array_next(&obj, &res)) ;

    obj->val = NULL;
    if (obj->prev != obj) {
      obj->prev->next = obj->prev;
      obj->next = NULL;
      obj->prev = NULL;
      _reql_expr_free(obj);
    }
  }

  return res;
}

_ReQL_Op _reql_array_last(_ReQL_Op obj) {
  _ReQL_Op res = NULL;

  obj = _reql_to_array(obj);

  if (obj) {
    while (!_reql_array_next(&obj, &res)) ;
  }

  return res;
}

_ReQL_Op _reql_json_object(_ReQL_Op obj) {
  obj = _reql_json_null(obj);
  if (obj) {
    obj->dt = _REQL_R_OBJECT;
    obj->next = obj->prev = obj;
    obj->key = NULL;
    obj->val = NULL;
  }
  return obj;
}

_ReQL_Op _reql_to_object(_ReQL_Op obj) {
  _ReQL_Op err = NULL;
  if (obj) {
    if (obj->dt == _REQL_R_OBJECT) {
      err = _reql_iter(obj);
    }
  }
  return err;
}

int _reql_op_eq(_ReQL_Op l, _ReQL_Op r) {
  int res = 0;
  if (l == r) {
    res = 1;
  } else {
    if ((l && r)) {
      if (l->tt == r->tt && l->dt == r->dt) {
        switch (l->dt) {
          case _REQL_C_ARRAY: {
            unsigned long larr_len, rarr_len;
            if (_reql_to_c_array(l, &larr_len) || _reql_to_c_array(r, &rarr_len)) {
              break;
            }
            if (larr_len == rarr_len) {
              res = 1;
              unsigned long i;
              for (i=0; i<larr_len; ++i) {
                res &= _reql_op_eq(_reql_c_array_index(l, i), _reql_c_array_index(r, i));
              }
            }
            break;
          }
          case _REQL_R_ARRAY: {
            l = _reql_to_array(l);
            r = _reql_to_array(r);
            if (!(l && r)) {
              break;
            }
            res = 1;
            _ReQL_Op lelem = NULL;
            _ReQL_Op relem = NULL;
            while (!(_reql_array_next(&l, &lelem) || _reql_array_next(&r, &relem))) {
              res &= _reql_op_eq(lelem, relem);
            }
            if (!(_reql_array_next(&l, &lelem) && _reql_array_next(&r, &relem))) {
              res = 0;
            }
            break;
          }
          case _REQL_R_BOOL: {
            int lval, rval;
            if (_reql_to_bool(l, &lval) || _reql_to_bool(r, &rval)) {
              break;
            }
            res = lval == rval;
            break;
          }
          case _REQL_R_JSON: {
            res = _reql_op_eq(l->args, r->args) && _reql_op_eq(l->kwargs, r->kwargs);
            break;
          }
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
            l = _reql_to_object(l);
            r = _reql_to_object(r);
            if (!(l && r)) {
              break;
            }
            res = 1;
            _ReQL_Op lkey = NULL;
            _ReQL_Op lval = NULL;
            _ReQL_Op rkey = NULL;
            _ReQL_Op rval = NULL;
            while (!(_reql_object_next(&l, &lkey, &lval) || _reql_object_next(&r, &rkey, &rval))) {
              res &= _reql_op_eq(lkey, rkey) && _reql_op_eq(lval, rval);
            }
            if (!(_reql_object_next(&l, &lkey, &lval) && _reql_object_next(&r, &rkey, &rval))) {
              res = 0;
            }
            break;
          }
          case _REQL_R_STR: {
            _ReQL_C_String_t *rstr;
            _ReQL_C_String_t *lstr;
            if (_reql_to_string(l, &lstr) || _reql_to_string(r, &rstr)) {
              break;
            }
            if (lstr->len == rstr->len) {
              res = !memcmp(lstr->str, rstr->str, lstr->len);
            }
            break;
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
  while (obj->next != obj && !_reql_op_eq(obj->key, key)) {
    obj = obj->next;
  }
  if (obj->key && !_reql_op_eq(obj->key, key)) {
    obj->next = _reql_json_object(NULL);
    if (!obj->next) {
      obj->next = obj;
      return -1;
    }
    obj->next->prev = obj;
    obj = obj->next;
    obj->next = obj;
  }
  obj->key = key;
  obj->val = val;

  return 0;
}

int _reql_object_next(_ReQL_Op *obj, _ReQL_Op *key, _ReQL_Op *val) {
  int err = -1;

  if (key && val) {
    if (!_reql_iter_next(obj)) {
      if ((*obj)->key) {
        *key = (*obj)->key;
        *val = (*obj)->val;
        err = 0;
      }
    }
  }

  return err;
}

_ReQL_Op _reql_object_get(_ReQL_Op obj, _ReQL_Op key) {
  if (!key) {
    return NULL;
  }

  obj = _reql_to_object(obj);

  if (!obj) {
    return NULL;
  }

  _ReQL_Op _key = NULL, val = NULL;

  while (!_reql_object_next(&obj, &_key, &val)) {
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
    obj->dt = _REQL_R_NULL;
    obj->args = obj->kwargs = obj->key = obj->val = NULL;
    obj->next = obj->prev = obj;
    obj->num = 0.0;
    obj->str = NULL;
  }
  return obj;
}

int _reql_to_null(_ReQL_Op obj) {
  if (!obj) {
    return -1;
  }
  if (obj->dt == _REQL_R_NULL) {
    return 0;
  }
  return -1;
}

_ReQL_Op _reql_json_bool(_ReQL_Op obj, int val) {
  obj = _reql_json_null(obj);
  if (obj) {
    obj->dt = _REQL_R_BOOL;
    obj->num = val;
  }
  return obj;
}

int _reql_to_bool(_ReQL_Op obj, int *val) {
  if (obj) {
    if (obj->dt == _REQL_R_BOOL) {
      *val = obj->num;
      return 0;
    }
  }
  return -1;
}

_ReQL_Op _reql_expr_copy(_ReQL_Op obj) {
  _ReQL_Op res = NULL;
  switch (obj->dt) {
    case _REQL_C_ARRAY: {
      unsigned long size;
      if (_reql_to_c_array(obj, &size)) {
        break;
      }
      res = _reql_json_c_array(NULL, size);
      unsigned long i;
      for (i=0; i<size; ++i) {
        _reql_c_array_insert(obj, _reql_expr_copy(_reql_c_array_index(obj, i)), i);
      }
      break;
    }
    case _REQL_R_ARRAY: {
      obj = _reql_to_array(obj);
      if (!obj) {
        break;
      }
      res = _reql_json_array(NULL);
      _ReQL_Op elem;
      while (!_reql_array_next(&obj, &elem)) {
        _reql_array_append(res, _reql_expr_copy(elem));
      }
      break;
    }
    case _REQL_R_BOOL: {
      int val;
      if (_reql_to_bool(obj, &val)) {
        break;
      }
      res = _reql_json_bool(NULL, val);
      break;
    }
    case _REQL_R_JSON: {
      res = _reql_json_null(NULL);
      res->tt = obj->tt;
      res->dt = obj->dt;
      res->args = _reql_expr_copy(obj->args);
      res->kwargs = _reql_expr_copy(obj->kwargs);
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
      obj = _reql_to_object(obj);
      if (!obj) {
        break;
      }
      res = _reql_json_object(NULL);
      _ReQL_Op key;
      _ReQL_Op val;
      while (!_reql_object_next(&obj, &key, &val)) {
        _reql_object_add(res, _reql_expr_copy(key), _reql_expr_copy(val));
      }
      break;
    }
    case _REQL_R_STR: {
      _ReQL_C_String_t *str;
      if (_reql_to_string(obj, &str)) {
        break;
      }
      res = _reql_json_string(NULL, str->str, str->len);
      break;
    }
  }
  return res;
}

void _reql_expr_free(_ReQL_Op obj) {
  if (!obj) {
    return;
  }

  if (obj->str) {
    free((char *)obj->str); obj->str = NULL;
  }

  unsigned long size;

  if (!_reql_to_c_array(obj, &size)) {
    unsigned long i;
    for (i=0; i<size; ++i) {
      _reql_expr_free(_reql_c_array_index(obj, i));
    }
  }

  _reql_expr_free(obj->key); obj->key = NULL;
  _reql_expr_free(obj->val); obj->val = NULL;
  _reql_expr_free(obj->args); obj->args = NULL;
  _reql_expr_free(obj->kwargs); obj->kwargs = NULL;
  _reql_expr_free(obj->next); obj->next = NULL;
  _reql_expr_free(obj->prev); obj->prev = NULL;

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

_ReQL_Op _reql_string_decode(unsigned long json_len, char *json) {
  char *utf8_str = malloc(sizeof(char) * json_len);
  char res;
  unsigned long i, j = 0;
  for (i=0; i<json_len; ++i) {
    res = json[i];
    if (res == '\\') {
      ++i;
      if (i >= json_len) {
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
          if ((i + 4) < json_len) {
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

int _reql_number_decode(unsigned long json_len, char *json, double *val) {
  double num = 0;
  unsigned long i;
  char digit = '0';
  for (i=1; i<=json_len; ++i) {
    digit = json[json_len - i];
    if (digit == '+') {
    } else if (digit == '-') {
      num *= -1;
    } else if (digit < '0' || digit > '9') {
      break;
    }
    num += (digit - '0') * pow(10, i - 1);
  }
  if (i<=json_len) {
    long new_len = json_len - i - 1;
    if (new_len <= 0) {
      return -1;
    }
    if (digit == 'E' || digit == 'e') {
      double exp = num;
      if (_reql_number_decode(new_len, json, &num)) {
        return -1;
      }
      num = pow(num, pow(10, exp));
    } else if (digit == '.') {
      double dec = num;
      if (_reql_number_decode(new_len, json, &num)) {
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

_ReQL_Op _reql_json_decode_(_ReQL_Op stack, _ReQL_C_String_t *json) {
  _ReQL_Datum_t state = _REQL_R_JSON;
  char esc = 0;
  unsigned long i, str_start = 0;
  for (i=0; i<json->len; ++i) {
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

_ReQL_Op _reql_json_decode(_ReQL_C_String_t *json) {
  _ReQL_Op stack = _reql_json_array(NULL);
  _ReQL_Op val = _reql_json_decode_(stack, json);
  _reql_expr_free(stack);

  return val;
}

_ReQL_C_String_t *_reql_c_string(_ReQL_C_String_t *str, char *buf, unsigned long len) {
  if (!str) {
    str = malloc(sizeof(_ReQL_C_String_t));
  }
  if (str) {
    str->len = len;
    str->alloc_len = len;
    if (!str->alloc_len) {
      str->alloc_len = 100;
    }
    str->str = malloc(sizeof(char) * str->alloc_len);
    if (!str->str) {
      str = NULL;
    }
    if (buf) {
      if (_reql_c_string_append(str, buf, len)) {
        str = NULL;
      }
    }
  }
  return str;
}

int _reql_c_string_append(_ReQL_C_String_t *orig, char *ext, unsigned long ext_len) {
  if (!orig) {
    return -1;
  }

  if ((orig->len + ext_len) > orig->alloc_len) {
    orig->alloc_len *= 1.1;
    orig->alloc_len += ext_len;
    orig->str = realloc(orig->str, orig->alloc_len);
    if (!orig->str) {
      return -1;
    }
  }

  orig->str = memcpy(&orig->str[orig->len + 1], ext, sizeof(char) * ext_len);

  orig->len += ext_len;

  return 0;
}

void _reql_c_string_free(_ReQL_C_String_t *str) {
  if (!str) {
    return;
  }

  if (str->str) {
    free(str->str); str->str = NULL;
  }

  str->alloc_len = 0;
  str->len = 0;
}

int _reql_c_string_append_(_ReQL_C_String_t *orig, char ext) {
  if (!orig) {
    return -1;
  }

  if (orig->len >= orig->alloc_len) {
    char new[1] = {ext};
    return _reql_c_string_append(orig, new, 1);
  }

  orig->len += 1;

  orig->str[orig->len] = ext;

  return 0;
}

int _reql_json_encode_(_ReQL_Op obj, _ReQL_C_String_t *json) {
  if (!json) {
    return -1;
  }

  int err = -1;

  switch (obj->dt) {
    case _REQL_C_ARRAY: {
      unsigned long size;
      if (_reql_to_c_array(obj, &size)) {
        break;
      }
      err = 0;
      for (unsigned long i=0; i<size; ++i) {
        if (i) {
          if (_reql_c_string_append_(json, ',')) {
            err = -1;
            break;
          }
        }
        if (_reql_json_encode_(_reql_c_array_index(obj, i), json)) {
          err = -1;
          break;
        }
      }
      break;
    }
    case _REQL_R_ARRAY: {
      obj = _reql_to_array(obj);
      if (!obj) {
        break;
      }
      char first = 1;
      _ReQL_Op elem;
      err = 0;
      while (!_reql_array_next(&obj, &elem)) {
        if (!first) {
          if (_reql_c_string_append_(json, ',')) {
            err = -1;
            break;
          }
        }
        if (_reql_json_encode_(elem, json)) {
          err = -1;
          break;
        }
        first = 0;
      }
      break;
    }
    case _REQL_R_BOOL: {
      int val;
      if (_reql_to_bool(obj, &val)) {
        break;
      }
      if (val) {
        if (_reql_c_string_append(json, "true", 4)) {
          break;
        }
      } else {
        if (_reql_c_string_append(json, "false", 5)) {
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
      err = _reql_c_string_append(json, "null", 4);
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
      obj = _reql_to_object(obj);
      if (!obj) {
        break;
      }
      char first = 1;
      _ReQL_Op key;
      _ReQL_Op val;
      err = 0;
      while (!_reql_object_next(&obj, &key, &val)) {
        if (!first) {
          if (_reql_c_string_append_(json, ',')) {
            err = -1;
            break;
          }
        }
        if (_reql_json_encode_(key, json)) {
          err = -1;
          break;
        }
        if (_reql_c_string_append_(json, ':')) {
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
      if (_reql_c_string_append_(json, '"')) {
        break;
      }
      _ReQL_C_String_t *str;
      if (_reql_to_string(obj, &str)) {
        break;
      }
      if (_reql_c_string_append(json, str->str, str->len)) {
        break;
      }
      if (_reql_c_string_append_(json, '"')) {
        break;
      }
      err = 0;
      break;
    }
  }

  return err;
}

_ReQL_C_String_t *_reql_json_encode(_ReQL_Op val) {
  _ReQL_C_String_t *json = _reql_c_string(NULL, NULL, 0);

  if (_reql_json_encode_(val, json)) {
    _reql_c_string_free(json);
    return NULL;
  }

  return json;
}
