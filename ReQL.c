/**
 * @author Adam Grandquist
 */

#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#include "ReQL.h"

int _reql_connect(_ReQL_Conn_t *conn, unsigned char host_len, char *host, unsigned char port) {
  conn->socket = conn->error = socket(PF_INET, SOCK_STREAM, PF_INET);
  if (conn->error > 0) {
    struct sockaddr address = {host_len, port, *host};
    conn->error = connect(conn->socket, &address, 0);
    if (!conn->error) {
      unsigned int version = htonl(_REQL_VERSION);
      char msg_buf[12];
      msg_buf[0] = (version & 0x000000ff) << 24;
      msg_buf[1] = (version & 0x0000ff) << 16;
      msg_buf[2] = (version & 0x00ff) << 8;
      msg_buf[3] = version & 0xff;
      msg_buf[4] = 0;
      msg_buf[5] = 0;
      msg_buf[6] = 0;
      msg_buf[7] = 0;
      unsigned int protocol = htonl(_REQL_PROTOCOL);
      msg_buf[8] = (protocol & 0x000000ff) << 24;
      msg_buf[9] = (protocol & 0x0000ff) << 16;
      msg_buf[10] = (protocol & 0x00ff) << 8;
      msg_buf[11] = protocol & 0xff;
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
  return 0;
}

int _reql_json_encode(_ReQL_Op_t *val, char **json) {
  return 0;
}

_ReQL_Cur_t *_reql_run(_ReQL_Op_t *query, _ReQL_Conn_t *conn, _ReQL_Op_t *kwargs) {
  _ReQL_Cur_t *cur;
  return cur;
}

void _reql_next(_ReQL_Cur_t *cur) {
}

void _reql_close_cur(_ReQL_Cur_t *cur) {
}
