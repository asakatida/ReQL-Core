/**
 * @author Adam Grandquist
 */

#include "ReQL.h"

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

_ReQL_Conn_t *_reql_new_connection(unsigned int auth_len, struct sockaddr *address, char *auth) {
  _ReQL_Conn_t *conn = malloc(sizeof(_ReQL_Conn_t));
  conn->socket = -1;
  conn->error = 0;
  conn->max_token = 0;
  conn->auth_len = auth_len;
  conn->address = address;
  conn->auth = auth;
  conn->cursors = _reql_new_cursor();
  return conn;
}

int _reql_connect(_ReQL_Conn_t *conn, char *buf) {
  conn->error = socket(PF_INET, SOCK_STREAM, PF_INET);
  if (conn->error > 0) {
    conn->socket = conn->error;
    conn->error = connect(conn->socket, conn->address, 0);
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
      send(conn->socket, msg_buf, auth_len + 12, 0);
      recv(conn->socket, buf, 0, MSG_WAITALL);
      if (strcmp(buf, "SUCCESS")) {
        conn->error = -1;
      }
    }
  }
  return conn->error;
}

int _reql_close_conn(_ReQL_Conn_t *conn) {
  return close(conn->socket);
}

int _reql_merge_stack(_ReQL_Op_t *stack) {
  _ReQL_Op_t *val = _reql_array_pop(stack);
  if (val) {
    _ReQL_Op_t *arr = _reql_array_pop(stack);
    if (arr) {
      if (_reql_to_array(arr)) {
        _reql_array_append(arr, val);
        _reql_array_append(stack, arr);
        return _REQL_R_ARRAY;
      }
      if (!_reql_to_object(arr)) {
        _ReQL_Op_t *key = arr;
        _ReQL_Op_t *obj = _reql_array_pop(stack);
        if (obj) {
          if (_reql_to_object(obj)) {
            _reql_object_add(obj, key, val);
            _reql_array_append(stack, obj);
            return _REQL_R_OBJECT;
          }
        }
      }
    }
    return _REQL_R_JSON;
  }
  return -1;
}

int _reql_json_decode_(_ReQL_Op_t *val, _ReQL_Op_t *stack, unsigned long json_len, char *json) {
  _reql_array_append(stack, val);
  _ReQL_Datum_t state = _REQL_R_JSON;
  char esc = 0;
  unsigned long i, str_start;
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
            return -1;
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
              _reql_array_append(stack, _reql_expr_bool(1));
              state = _reql_merge_stack(stack);
              i += 4;
              break;
            }
          }
          case 'f': {
            if (strncmp(json + i * sizeof(char), "false", 5)) {
              _reql_array_append(stack, _reql_expr_bool(0));
              state = _reql_merge_stack(stack);
              i += 5;
              break;
            }
          }
          case 'n': {
            if (strncmp(json + i * sizeof(char), "null", 4)) {
              _reql_array_append(stack, _reql_expr_null());
              state = _reql_merge_stack(stack);
              i += 4;
              break;
            }
          }
          default: {
            return -1;
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
            _reql_array_append(stack, _reql_expr_number(0.0));
            state = _reql_merge_stack(stack);
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
            return -1;
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
              _reql_array_append(stack, _reql_expr_string("", 0));
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
      default: {
        return -1;
      }
    }
  }
  return 0;
}

int _reql_json_decode(_ReQL_Op_t **val, unsigned long json_len, char *json) {
  *val = malloc(sizeof(_ReQL_Op_t));
  _ReQL_Op_t *stack = _reql_expr_array();
  int res = _reql_json_decode_(*val, stack, json_len, json);
  if (res) {
    free(*val);
  }
  return res;
}

int _reql_json_encode(_ReQL_Op_t *val, char **json) {
  return 0;
}

_ReQL_Cur_t *_reql_run(_ReQL_Op_t *query, _ReQL_Conn_t *conn, _ReQL_Op_t *kwargs) {
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
