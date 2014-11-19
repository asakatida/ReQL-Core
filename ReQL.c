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
  return -1;
}

int _reql_json_decode_(_ReQL_Op_t *val, _ReQL_Op_t *stack, unsigned long json_len, char *json) {
  _reql_array_append(stack, val);
  _ReQL_Datum_t state = _REQL_R_JSON;
  char quote = '\0';
  unsigned long i, str_start;
  for (i=0; i<json_len; ++i) {
    switch (state) {
      case _REQL_R_ARRAY: {
        switch (json[i]) {
          case ',': {
            _ReQL_Op_t *obj = _reql_array_pop(stack);
            _ReQL_Op_t *arr = _reql_array_pop(stack);
            _reql_array_append(arr, obj);
            _reql_array_append(stack, arr);
            state = _REQL_R_JSON;
            break;
          }
          case ']': {
            _ReQL_Op_t *arr = _reql_array_pop(stack);
            if (arr) {
              _ReQL_Op_t *obj = _reql_array_pop(stack);
              if (obj) {
                if (_reql_to_array(obj)) {
                  _reql_array_append(obj, arr);
                } else {
                  _ReQL_Op_t *key = obj;
                  obj = _reql_array_pop(stack);
                  if (obj) {
                    if (_reql_to_object(obj)) {
                      _reql_object_add(obj, key, arr);
                    } else {
                      return -1;
                    }
                  } else {
                    return -1;
                  }
                  state = _REQL_R_OBJECT;
                }
              } else {
                state = _REQL_R_JSON;
              }
              _reql_array_append(stack, obj);
              break;
            }
            return -1;
          }
          default: {
            return -1;
          }
        }
      }
      case _REQL_R_BOOL: {
        switch (json[i]) {
          default: {
            return -1;
          }
        }
      }
      case _REQL_R_JSON: {
        switch (json[i]) {
          case '[': {
            state = _REQL_R_ARRAY;
            break;
          }
          case '{': {
            state = _REQL_R_OBJECT;
            break;
          }
          case '"':
          case '\'': {
            state = _REQL_R_STR;
            quote = json[i];
            break;
          }
          default: {
            return -1;
          }
        }
      }
      case _REQL_R_NULL: {
        return -1;
      }
      case _REQL_R_NUM: {
        switch (json[i]) {
          default: {
            return -1;
          }
        }
      }
      case _REQL_R_OBJECT: {
        switch (json[i]) {
          default: {
            return -1;
          }
        }
      }
      case _REQL_R_STR: {
        if (quote != '\'' && quote != '"') {
          return -1;
        }
        switch (json[i]) {
          default: {
            return -1;
          }
        }
      }
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
