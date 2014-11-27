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

#include "ReQL.h"

#include <math.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static const unsigned int _REQL_VERSION = 0x5f75e83e;
static const unsigned int _REQL_PROTOCOL = 0x7e6970c7;

enum {
  _REQL_CONTINUE = 2,
  _REQL_NOREPLY_WAIT = 4,
  _REQL_START = 1,
  _REQL_STOP = 3
};

#ifndef htole32
#define htole32
#endif

_ReQL_Cur_t *_reql_new_cursor() {
  _ReQL_Cur_t *cur = malloc(sizeof(_ReQL_Cur_t));
  cur->token = 0;
  cur->idx = 0;
  cur->next = cur->prev = cur;
  cur->conn = NULL;
  cur->response = NULL;
  cur->array = _reql_expr_array();
  cur->iter = _reql_to_array(cur->array);
  return cur;
}

_ReQL_Conn_t *_reql_new_connection(unsigned int auth_len, unsigned short port, unsigned char *addr, char *auth) {
  _ReQL_Conn_t *conn = malloc(sizeof(_ReQL_Conn_t));
  conn->socket = -1;
  conn->error = 0;
  conn->max_token = 0;
  conn->auth_len = auth_len;
  conn->auth = auth;
  conn->cursors = _reql_new_cursor();
  conn->port = port;
  conn->addr = addr;
  return conn;
}

int _reql_connect(_ReQL_Conn_t *conn, char *buf) {
  conn->error = socket(PF_INET, SOCK_STREAM, PF_INET);
  if (conn->error > 0) {
    conn->socket = conn->error;

    struct sockaddr_in address;

    bzero(&address, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = htons(conn->port);
    address.sin_addr.s_addr = htonl((((((conn->addr[0] << 8) | conn->addr[1]) << 8) | conn->addr[2]) << 8) | conn->addr[3]);

    conn->error = connect(conn->socket, (struct sockaddr *)&address, 0);
    if (!conn->error) {
      const unsigned int version = htole32(_REQL_VERSION);
      char *msg_buf = malloc(sizeof(char) * (conn->auth_len + 12));
      unsigned int i = -1;
      unsigned int j = 0;
      for (; j<4; ++j) {
        msg_buf[++i] = (version << (8 * j)) & 0xff;
      }
      const unsigned int auth_len = htole32(conn->auth_len);
      for (j=0; j<4; ++j) {
        msg_buf[++i] = (auth_len << (8 * j)) & 0xff;
      }
      for (j=0; j<conn->auth_len; ++j) {
        msg_buf[++i] = conn->auth[j];
      }
      const unsigned int protocol = htole32(_REQL_PROTOCOL);
      for (j=0; j<4; ++j) {
        msg_buf[++i] = (protocol << (8 * j)) & 0xff;
      }
      write(conn->socket, msg_buf, auth_len + 12);
      recvfrom(conn->socket, buf, 8, MSG_WAITALL, NULL, NULL);
      if (strcmp(buf, "SUCCESS")) {
        conn->error = -1;
        recvfrom(conn->socket, buf, 0, MSG_WAITALL, NULL, NULL);
        close(conn->socket);
      }
    }
  }
  return conn->error;
}

void _reql_free_cur(_ReQL_Cur_t *cur) {
  while (cur != cur->prev) {
    cur = cur->prev;
  }
  while (cur != cur->next) {
    cur = cur->next;
    _reql_close_cur(cur->prev);
  }
  _reql_close_cur(cur);
}

int _reql_close_conn(_ReQL_Conn_t *conn) {
  conn->max_token = 0;
  _reql_free_cur(conn->cursors);
  conn->cursors = _reql_new_cursor();
  return conn->error = close(conn->socket);
}

void _reql_free_conn(_ReQL_Conn_t *conn) {
  _reql_free_cur(conn->cursors);
  free(conn); conn = NULL;
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
  _ReQL_Op str = _reql_expr_string(utf8_str, j);
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

_ReQL_Op _reql_json_decode_(_ReQL_Op stack, unsigned long json_len, char *json) {
  _ReQL_Datum_t state = _REQL_R_JSON;
  char esc = 0;
  unsigned long i, str_start = 0;
  for (i=0; i<json_len; ++i) {
    switch (state) {
      case _REQL_R_ARRAY: {
        switch (json[i]) {
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
        switch (json[i]) {
          case '\t':
          case '\n':
          case '\r':
          case ' ': {
            break;
          }
          case '[': {
            _reql_array_append(stack, _reql_expr_array());
            state = _REQL_R_ARRAY;
            break;
          }
          case '{': {
            _reql_array_append(stack, _reql_expr_object());
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
            if (strncmp(json + i * sizeof(char), "true", 4)) {
              state = _reql_merge_stack_val(stack, _reql_expr_bool(1));
              i += 4;
              break;
            }
          }
          case 'f': {
            if (strncmp(json + i * sizeof(char), "false", 5)) {
              state = _reql_merge_stack_val(stack, _reql_expr_bool(0));
              i += 5;
              break;
            }
          }
          case 'n': {
            if (strncmp(json + i * sizeof(char), "null", 4)) {
              state = _reql_merge_stack_val(stack, _reql_expr_null());
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
            if (_reql_number_decode(i - str_start - 1, json + str_start * sizeof(char), &num)) {
              return NULL;
            }
            state = _reql_merge_stack_val(stack, _reql_expr_number(num));
            --i;
          }
        }
        break;
      }
      case _REQL_R_OBJECT: {
        switch (json[i]) {
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
        switch (json[i]) {
          case '\\': {
            esc = 1;
            break;
          }
          case '"': {
            if (!esc) {
              _ReQL_Op str = _reql_string_decode(i - str_start - 1, json + str_start * sizeof(char));
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

int _reql_json_decode(_ReQL_Op *val, unsigned long json_len, char *json) {
  _ReQL_Op stack = _reql_expr_array();
  *val = _reql_json_decode_(stack, json_len, json);
  _reql_expr_free(stack);

  if (val) {
    return 0;
  }

  return -1;
}

int _reql_json_encode(_ReQL_Op val, char **json) {
  return 0;
}

_ReQL_Cur_t *_reql_run(_ReQL_Op query, _ReQL_Conn_t *conn, _ReQL_Op kwargs) {
  _ReQL_Cur_t *cur = conn->cursors;

  while (cur->next != cur) {
    cur = cur->next;
  }

  if (cur->response) {
    cur->next = _reql_new_cursor();
    cur->next->prev = cur;
    cur = cur->next;
  }

  cur->conn = conn;
  cur->token = conn->max_token++;

  _reql_build(query);

  return cur;
}

void _reql_cursor_next(_ReQL_Cur_t *cur) {
  cur->response = _reql_expr_null();
}

void _reql_close_cur(_ReQL_Cur_t *cur) {
  cur->prev->next = cur->next == cur ? cur->prev : cur->next;
  cur->next->prev = cur->prev == cur ? cur->next : cur->prev;
  free(cur); cur = NULL;
}
