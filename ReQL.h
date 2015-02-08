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

#include "ReQL-cursor.h"

#ifndef REQL_H
#define REQL_H

/**
 * @brief connection object
 */
struct ReQL_Conn_s {
  char done;
  int socket;

  uint64_t max_token;
  uint32_t auth_size;

  unsigned long timeout;

  char *port;
  char *addr;

  char *auth;
  ReQL_Cur_t *cursors;

  void *mutex;
};
typedef struct ReQL_Conn_s ReQL_Conn_t;

/**
 * @brief initialize connection to prepare for opening.
 * @param conn allocated connection object.
 */
extern void
reql_connection_init(ReQL_Conn_t *conn);

/**
 * @brief assign an authentication key before opening a connection.
 * @param conn connection object.
 * @param size number of bytes in key.
 * @param auth byte array key.
 */
extern void
reql_conn_set_auth(ReQL_Conn_t *conn, uint32_t size, char *auth);

/**
 * @brief assign an address before opening a connection.
 * @param conn connection object.
 * @param addr address for connection.
 */
extern void
reql_conn_set_addr(ReQL_Conn_t *conn, char *addr);

/**
 * @brief assign a port before opening a connection.
 * @param conn connection object.
 * @param port port for connection.
 */
extern void
reql_conn_set_port(ReQL_Conn_t *conn, char *port);

/**
 * @brief assign a timeout to a connection.
 * @param conn connection object.
 * @param timeout timout in seconds.
 */
extern void
reql_conn_set_timeout(ReQL_Conn_t *conn, unsigned long timeout);

/**
 * @brief reql_connect
 * @param conn connection object.
 * @param buf allocated buffer that will be filled with an error message or `SUCCESS\0`
 * @param size number of bytes in buffer.
 * @return 0 on success. non zero on error.
 */
extern int
reql_connect(ReQL_Conn_t *conn, uint8_t *buf, uint32_t size);

/**
 * @brief Declare a connection ready to be closed.
 * @param conn connection object.
 */
extern void
reql_close_conn(ReQL_Conn_t *conn);

/**
 * @brief Ensure a connection object is cleaned up and ready to be deallocated.
 * @param conn connection object.
 */
extern void
reql_ensure_conn_close(ReQL_Conn_t *conn);

/**
 * @brief Check if a connection object is connected.
 * @param conn connection object.
 * @return 0 if closed or closing. non zero otherwise.
 */
extern char
reql_conn_open(ReQL_Conn_t *conn);

/**
 * @brief Prepare and send a query to the server for evaluation. Set up cur to receive responces.
 * @param cur initalized cursor object or NULL.
 * @param query term object.
 * @param conn connection object.
 * @param kwargs global options or NULL.
 * @return 0 on success. Non zero otherwise.
 */
extern int
reql_run(ReQL_Cur_t *cur, ReQL_Obj_t *query, ReQL_Conn_t *conn, ReQL_Obj_t *kwargs);

#endif
