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

#include "./reql/decode.h"

#include "./reql/char.h"
#include "./reql/error.h"
#include "./reql/expr.h"
#include "./reql/types.h"

#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

static int
reql_space(ReQL_Byte **pos, ReQL_Byte *end) {
  while (*pos != end) {
    if (!isspace(**pos)) {
      return 0;
    }
    ++(*pos);
  }
  return -1;
}

static int
reql_next_char(ReQL_Byte **pos, ReQL_Byte *end, ReQL_Byte expect) {
  if (reql_space(pos, end)) {
    return 0;
  }
  if (**pos == expect) {
    ++(*pos);
    return 1;
  }
  return 0;
}

static void
reql_destroy_stack(ReQL_Obj_t *obj) {
  while (obj != NULL) {
    ReQL_Obj_t *top = obj->owner;
    obj->owner = NULL;
    reql_json_destroy(obj);
    obj = top;
  }
}

static ReQL_Obj_t *
reql_decode_(ReQL_Byte **pos, ReQL_Byte *end) {
  if (reql_space(pos, end)) {
    return NULL;
  }
  switch (**pos) {
    case '"': {
      ++(*pos);
      int esc = 0;
      ReQL_Byte *start = *pos;
      ReQL_Byte *track = *pos;
      ReQL_Byte res;
      while (*pos != end) {
        res = **pos;
        if (esc == 1) {
          switch (res) {
            case 'b': { /* b */
              res = '\b';
              break;
            }
            case 'f': { /* f */
              res = '\f';
              break;
            }
            case 'n': { /* n */
              res = '\n';
              break;
            }
            case 'r': { /* r */
              res = '\r';
              break;
            }
            case 't': { /* t */
              res = '\t';
              break;
            }
            case 'u': {
              if ((*pos) + 4 >= end) {
                return NULL;
              }
              if (!(*(++(*pos)) == '0' && *(++(*pos)) == '0')) {
                return NULL;
              }
              ++(*pos);
              if (!(ishexnumber(*((*pos) + 1)) && ishexnumber(**pos))) {
                return NULL;
              }
              ReQL_Byte hex = **pos;
              if (hex >= '0' && hex <= '9') {
                hex -= '0';
              } else if (hex >= 'a' && hex <= 'f') {
                hex -= 'a' - 10;
              } else {
                hex -= 'A' - 10;
              }
              res = hex * 16;
              ++(*pos);
              hex = **pos;
              if (hex >= '0' && hex <= '9') {
                hex -= '0';
              } else if (hex >= 'a' && hex <= 'f') {
                hex -= 'a' - 10;
              } else {
                hex -= 'A' - 10;
              }
              res += hex;
              break;
            }
          }
          esc = 0;
        } else if (**pos == '\\') {
          esc = 1;
        } else if (**pos == '"') {
          ++(*pos);
          ReQL_Size size = (ReQL_Size)(track - start);
          if (size == 0) {
            ReQL_Obj_t *obj = malloc(sizeof(ReQL_Obj_t));

            if (obj == NULL) {
              return NULL;
            }

            reql_string_init(obj, NULL, 0);
            return obj;
          }

          ReQL_Obj_t *out = malloc(sizeof(ReQL_Obj_t));

          if (out == NULL) {
            return NULL;
          }

          ReQL_Byte *buf = malloc(sizeof(ReQL_Byte) * size);

          if (buf == NULL) {
            free(out);
            return NULL;
          }

          reql_string_init(out, buf, size);
          reql_string_append(out, start, size);

          return out;
        }
        *track = res;
        ++track;
        ++(*pos);
      }
      break;
    }
    case '[': {
      ++(*pos);
      ReQL_Obj_t *elem = NULL;
      ReQL_Obj_t *top = NULL;
      ReQL_Size i = 0;
      while (*pos != end) {
        if (reql_next_char(pos, end, ']')) {
          ReQL_Obj_t *obj = malloc(sizeof(ReQL_Obj_t));
          if (obj == NULL) {
            reql_destroy_stack(elem);
            return NULL;
          }
          if (i == 0) {
            reql_array_init(obj, NULL, 0);
          } else  {
            ReQL_Obj_t **array = malloc(sizeof(ReQL_Obj_t*) * i);
            if (array == NULL) {
              free(obj);
              reql_destroy_stack(elem);
              return NULL;
            }
            reql_array_init(obj, array, i);
            while (elem != NULL) {
              ReQL_Obj_t *val = elem;
              elem = elem->owner;
              val->owner = NULL;
              reql_array_insert(obj, val, --i);
            }
          }
          return obj;
        }
        top = reql_decode_(pos, end);
        if (top == NULL) {
          reql_destroy_stack(elem);
          return NULL;
        }
        top->owner = elem;
        elem = top;
        if (!reql_next_char(pos, end, ',')) {
          if (**pos != ']') {
            reql_destroy_stack(elem);
            return NULL;
          }
        }
        ++i;
      }
      break;
    }
    case '{': {
      ++(*pos);
      ReQL_Obj_t *elem = NULL;
      ReQL_Obj_t *top = NULL;
      ReQL_Size i = 0;
      while (*pos != end) {
        if (reql_next_char(pos, end, '}')) {
          ReQL_Obj_t *obj = malloc(sizeof(ReQL_Obj_t));
          if (obj == NULL) {
            reql_destroy_stack(elem);
            return NULL;
          }
          if (i == 0) {
            reql_object_init(obj, NULL, 0);
          } else  {
            ReQL_Pair_t *pair = malloc(sizeof(ReQL_Pair_t) * i);
            if (pair == NULL) {
              free(obj);
              reql_destroy_stack(elem);
              return NULL;
            }
            reql_object_init(obj, pair, i);
            while (elem != NULL) {
              if (elem->owner == NULL) {
                reql_json_destroy(obj);
                reql_destroy_stack(elem);
                return NULL;
              }
              ReQL_Obj_t *val = elem;
              elem = elem->owner;
              ReQL_Obj_t *key = elem;
              elem = elem->owner;
              key->owner = NULL;
              val->owner = NULL;
              reql_object_add(obj, key, val);
            }
          }
          return obj;
        }
        top = reql_decode_(pos, end);
        if (top == NULL) {
          reql_destroy_stack(elem);
          return NULL;
        }
        top->owner = elem;
        elem = top;
        if (!reql_next_char(pos, end, ':')) {
          reql_destroy_stack(elem);
          return NULL;
        }
        top = reql_decode_(pos, end);
        if (top == NULL) {
          reql_destroy_stack(elem);
          return NULL;
        }
        top->owner = elem;
        elem = top;
        if (!reql_next_char(pos, end, ',')) {
          if (**pos != '}') {
            reql_destroy_stack(elem);
            return NULL;
          }
        }
        ++i;
      }
      break;
    }
    case 'f': {
      if ((*pos) + 5 >= end) {
        return NULL;
      }
      if (memcmp(*pos, json_false, 5) == 0) {
        ReQL_Obj_t *obj = malloc(sizeof(ReQL_Obj_t));
        if (obj != NULL) {
          reql_bool_init(obj, 0);
          *pos += 5;
        }
        return obj;
      }
      break;
    }
    case 'n': {
      if ((*pos) + 4 >= end) {
        return NULL;
      }
      if (memcmp(*pos, json_null, 4) == 0) {
        ReQL_Obj_t *obj = malloc(sizeof(ReQL_Obj_t));
        if (obj != NULL) {
          reql_null_init(obj);
          *pos += 4;
        }
        return obj;
      }
      break;
    }
    case 't': {
      if ((*pos) + 4 >= end) {
        return NULL;
      }
      if (memcmp(*pos, json_true, 4) == 0) {
        ReQL_Obj_t *obj = malloc(sizeof(ReQL_Obj_t));
        if (obj != NULL) {
          reql_bool_init(obj, 1);
          *pos += 4;
        }
        return obj;
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
      double num = strtod((char *)*pos, (char **)pos);
      if (pos == NULL) {
        return NULL;
      }
      ReQL_Obj_t *obj = malloc(sizeof(ReQL_Obj_t));
      if (obj != NULL) {
        reql_number_init(obj, num);
      }
      return obj;
    }
  }
  return NULL;
}

extern ReQL_Obj_t *
reql_decode(ReQL_Byte *json, ReQL_Size size) {
  return reql_decode_(&json, json + size);
}
