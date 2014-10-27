#include <sys/socket.h>
#include <unistd.h>

#include "ReQL-ast.h"

#include "ReQL.h"

_ReQL_arg_t *_reql_arg_new() {
  _ReQL_arg_t *arg;
  arg->next_arg = arg;
  return arg;
}

int _reql_arg_append(_ReQL_arg_t *args, _ReQL_Op_t *val) {
  while (args->next_arg != args) {
    args = args->next_arg;
  }
  args->arg = val;
  _ReQL_arg_t *next_arg;
  args->next_arg = next_arg;
  next_arg->next_arg = next_arg;
  return 0;
}

_ReQL_kwarg_t *_reql_kwarg_new() {
  _ReQL_kwarg_t *kwarg;
  kwarg->next_kwarg = kwarg;
  return kwarg;
}

int _reql_kwarg_add(_ReQL_kwarg_t *kwargs, char *key, _ReQL_Op_t *val) {
  while (kwargs->next_kwarg != kwargs) {
    kwargs = kwargs->next_kwarg;
  }
  kwargs->key = key;
  kwargs->val = val;
  _ReQL_kwarg_t *next_kwarg;
  kwargs->next_kwarg = next_kwarg;
  next_kwarg->next_kwarg = next_kwarg;
  return 0;
}

_ReQL_Op_t *_reql_expr_number(double val) {
  _ReQL_Op_t *term = _reql_expr_null();
  term->dt = _REQL_R_NUM;
  term->num = val;
  return term;
}
_ReQL_Op_t *_reql_expr_string(char *val, int str_len) {
  _ReQL_Op_t *term = _reql_expr_null();
  term->dt = _REQL_R_STR;
  term->str = val;
  term->str_len = str_len;
  return term;
}

_ReQL_Op_t *_reql_expr_array(_ReQL_arg_t *val) {
  _ReQL_Op_t *term = _reql_expr_null();
  term->dt = _REQL_R_ARRAY;
  return term;
}

_ReQL_Op_t *_reql_expr_object(_ReQL_kwarg_t *val) {
  _ReQL_Op_t *term = _reql_expr_null();
  term->dt = _REQL_R_OBJECT;
  return term;
}

_ReQL_Op_t *_reql_expr_null() {
  _ReQL_Op_t *term;
  term->tt = _REQL_DATUM;
  term->dt = _REQL_R_NULL;
  term->str_len = 0;
  term->str = 0;
  term->num = 0;
  term->args = 0;
  term->kwargs = 0;
  return term;
}

_ReQL_Op_t *_reql_expr_bool(int val) {
  _ReQL_Op_t *term = _reql_expr_null();
  term->dt = _REQL_R_BOOL;
  return term;
}

int _reql_connect(_ReQL_Conn_t *conn, unsigned char host_len, char *host, unsigned char port) {
  conn->socket = conn->error = socket(PF_INET, SOCK_STREAM, PF_INET);
  if (conn->error > 0) {
    struct sockaddr address = {host_len, port, *host};
    conn->error = connect(conn->socket, &address, 0);
    if (!conn->error) {
      unsigned int version = htonl(_REQL_VERSION);
      char version_buf[4];
      version_buf[0] = (version & 0x000000ff) << 24;
      version_buf[1] = (version & 0x0000ff) << 16;
      version_buf[2] = (version & 0x00ff) << 8;
      version_buf[3] = version & 0xff;
      send(conn->socket, &_REQL_VERSION, 4, 0);
      char key_len_buf[4];
      key_len_buf[0] = 0;
      key_len_buf[1] = 0;
      key_len_buf[2] = 0;
      key_len_buf[3] = 0;
      send(conn->socket, &key_len_buf, 4, 0);
      unsigned int protocol = htonl(_REQL_PROTOCOL);
      char protocol_buf[4];
      protocol_buf[0] = (protocol & 0x000000ff) << 24;
      protocol_buf[1] = (protocol & 0x0000ff) << 16;
      protocol_buf[2] = (protocol & 0x00ff) << 8;
      protocol_buf[3] = protocol & 0xff;
      send(conn->socket, &_REQL_PROTOCOL, 4, 0);
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
  return 0;
}

int _reql_json_encode(_ReQL_Op_t *val, char **json) {
  return 0;
}

_ReQL_Cur_t *_reql_run(_ReQL_Op_t *query, _ReQL_Conn_t *conn, _ReQL_kwarg_t *kwargs) {
  _ReQL_Cur_t *cur;
  return cur;
}

void _reql_next(_ReQL_Cur_t *cur) {
}

void _reql_close_cur(_ReQL_Cur_t *cur) {
}
