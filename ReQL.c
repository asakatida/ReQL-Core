/**
 * @author Adam Grandquist
 */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "ReQL.h"

#ifndef htole32
#ifdef OSSwapHostToLittleConstInt32
#define htole32 OSSwapHostToLittleConstInt32
#endif
#endif

int _reql_connect(_ReQL_Conn_t *conn, char *buf) {
  conn->error = socket(PF_INET, SOCK_STREAM, PF_INET);
  if (conn->error > 0) {
    conn->socket = conn->error;
    conn->error = connect(conn->socket, conn->address, 0);
    if (!conn->error) {
      const unsigned int version = htole32(_REQL_VERSION);
      char *msg_buf = malloc(sizeof(char) * (conn->auth_len + 12));
      unsigned int i = 0;
      unsigned int j = 0;
      for (; j<4; ++j) {
        msg_buf[i++] = (version << (8 * j)) & 0xff;
      }
      const unsigned int auth_len = htole32(conn->auth_len);
      for (j=0; j<4; ++j) {
        msg_buf[i++] = (auth_len << (8 * j)) & 0xff;
      }
      for (j=0; j<conn->auth_len; ++j) {
        msg_buf[i++] = conn->auth[j];
      }
      const unsigned int protocol = htole32(_REQL_PROTOCOL);
      for (j=0; j<4; ++j) {
        msg_buf[i++] = (protocol << (8 * j)) & 0xff;
      }
      send(conn->socket, msg_buf, auth_len + 12, 0);
      recv(conn->socket, buf, 0, MSG_WAITALL);
      if (strcmp(buf, "SUCCESS")) {
        conn->error = -1;
      } else {
        conn->cursors->next = conn->cursors->prev = conn->cursors;
        conn->cursors->cur = NULL;
      }
    }
  }
  return conn->error;
}

int _reql_close_conn(_ReQL_Conn_t *conn) {
  return close(conn->socket);
}

int _reql_json_decode(_ReQL_Op_t *val, unsigned int json_len, char *json) {
  val = malloc(sizeof(_ReQL_Op_t *));
  _ReQL_Op_t *track = val;
  int state = _REQL_R_OBJECT;
  unsigned int i;
  for (i=0; i<json_len; ++i) {
    switch (state) {
      case _REQL_R_OBJECT: {
        switch (json[i]) {
          case '[': {
            break;
          }
          case '{': {
            break;
          }
          case '"':
          case '\'': {
            break;
          }
          case ',': {
            break;
          }
        }
      }
    }
  }
  val->str = json;
  val->str_len = json_len;
  return 0;
}

int _reql_json_encode(_ReQL_Op_t *val, char **json) {
  return 0;
}

_ReQL_Cur_t *_reql_run(_ReQL_Op_t *query, _ReQL_Conn_t *conn, _ReQL_Op_t *kwargs) {
  _ReQL_Cur_t *cur = malloc(sizeof(_ReQL_Cur_t*));
  cur->conn = conn;
  cur->idx = 0;
  cur->response = _reql_expr_null();
  _ReQL_Cur_Arr_t *cursors = conn->cursors;
  while (cursors->next != cursors) {
    cursors = cursors->next;
  }
  if (cursors->cur) {
    _ReQL_Cur_Arr_t *next = malloc(sizeof(_ReQL_Cur_Arr_t*));
    next->prev = cursors;
    cursors->next = next->next = next;
    next->cur = cur;
  } else {
    cursors->cur = cur;
  }
  cur->token = conn->max_token++;
  _reql_build(query);
  return cur;
}

void _reql_next(_ReQL_Cur_t *cur) {
  cur->response = _reql_expr_null();
}

void _reql_close_cur(_ReQL_Cur_t *cur) {
  _ReQL_Cur_Arr_t *cursors = cur->conn->cursors;
  while (cursors->next != cursors) {
    if (cursors->cur == cur) {
      _ReQL_Cur_Arr_t *cursor_match = cursors;
      cursors->next->prev = cursors->prev;
      cursors->prev->next = cursors->next;
      free(cursor_match);
      break;
    }
    cursors = cursors->next;
  }
  free(cur);
}
