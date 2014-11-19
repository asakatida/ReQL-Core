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
        conn->cursors->response = NULL;
      }
    }
  }
  return conn->error;
}

int _reql_close_conn(_ReQL_Conn_t *conn) {
  return close(conn->socket);
}

int _reql_json_decode(_ReQL_Op_t *val, unsigned long json_len, char *json) {
  val = malloc(sizeof(_ReQL_Op_t));
  _ReQL_Op_t *track = _reql_expr_array();
  _reql_array_append(track, val);
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
  _ReQL_Cur_t *cur;
  _ReQL_Cur_t *cursors = conn->cursors;
  while (cursors->next != cursors) {
    cursors = cursors->next;
  }
  if (cursors->response) {
    cur = malloc(sizeof(_ReQL_Cur_t));
    cur->prev = cursors;
    cursors->next = cur->next = cur;
  } else {
    cur = cursors;
  }
  cur->conn = conn;
  cur->idx = 0;
  cur->response = _reql_expr_array();
  cur->token = conn->max_token++;
  _reql_build(query);
  return cur;
}

void _reql_next(_ReQL_Cur_t *cur) {
  cur->response = _reql_expr_null();
}

void _reql_close_cur(_ReQL_Cur_t *cur) {
  cur->prev->next = cur->next == cur ? cur->prev : cur->next;
  cur->next->prev = cur->prev == cur ? cur->next : cur->prev;
  free(cur); cur = NULL;
}
