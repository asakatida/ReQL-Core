/**
 * @author Adam Grandquist
 */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "ReQL.h"

int _reql_connect(_ReQL_Conn_t *conn, unsigned char host_len, char *host, unsigned char port) {
  conn->socket = conn->error = socket(PF_INET, SOCK_STREAM, PF_INET);
  if (conn->error > 0) {
    struct sockaddr address = {host_len, port, *host};
    conn->error = connect(conn->socket, &address, 0);
    if (!conn->error) {
      unsigned int version = htole32(_REQL_VERSION);
      char msg_buf[12];
      msg_buf[0] = version & 0xff;
      msg_buf[1] = (version << 8) & 0xff;
      msg_buf[2] = (version << 16) & 0xff;
      msg_buf[3] = (version << 24) & 0xff;
      msg_buf[4] = 0;
      msg_buf[5] = 0;
      msg_buf[6] = 0;
      msg_buf[7] = 0;
      unsigned int protocol = htole32(_REQL_PROTOCOL);
      msg_buf[8] = protocol & 0xff;
      msg_buf[9] = (protocol << 8) & 0xff;
      msg_buf[10] = (protocol << 16) & 0xff;
      msg_buf[11] = (protocol << 24) & 0xff;
      send(conn->socket, msg_buf, 12, 0);
      conn->buf = malloc(sizeof(char) * 100);
      recv(conn->socket, conn->buf, 0, MSG_WAITALL);
      if (strcmp(conn->buf, "SUCCESS")) {
        conn->error = -1;
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
  for (unsigned int i=0; i<json_len; ++i) {
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
