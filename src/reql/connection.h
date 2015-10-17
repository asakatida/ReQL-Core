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

#ifndef REQL_REQL_CONNECTION_H_
#define REQL_REQL_CONNECTION_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "./reql/cursor.h"
#include "./reql/query.h"
#include "./reql/types.h"

/**
 * @brief initialize connection to prepare for opening.
 * @param conn allocated connection object.
 */
extern void
reql_conn_init(ReQL_Conn_t *conn);

/**
 * @brief assign an authentication key before opening a connection.
 * @param conn connection object.
 * @param size number of bytes in key.
 * @param auth byte array key.
 */
extern void
reql_conn_set_auth(ReQL_Conn_t *conn, ReQL_Size size, char *auth);

/**
 * @brief get authentication key buffer used on connection.
 * @param conn connection object.
 * @return pointer to buffer holding key.
 */
extern char *
reql_conn_auth_key(ReQL_Conn_t *conn);

/**
 * @brief get authentication key size used on connection.
 * @param conn connection object.
 * @return size of authentication key.
 */
extern ReQL_Size
reql_conn_auth_size(ReQL_Conn_t *conn);

/**
 * @brief assign an address before opening a connection.
 * @param conn connection object.
 * @param addr address for connection.
 */
extern void
reql_conn_set_addr(ReQL_Conn_t *conn, char *addr);

/**
 * @brief get address used on connection.
 * @param conn connection object.
 * @return pointer to address buffer.
 */
extern char *
reql_conn_addr(ReQL_Conn_t *conn);

/**
 * @brief assign a port before opening a connection.
 * @param conn connection object.
 * @param port port for connection.
 */
extern void
reql_conn_set_port(ReQL_Conn_t *conn, char *port);

/**
 * @brief get port used on connection.
 * @param conn connection object.
 * @return pointer to port buffer.
 */
extern char *
reql_conn_port(ReQL_Conn_t *conn);

/**
 * @brief assign a timeout to a connection.
 * @param conn connection object.
 * @param s timout in seconds.
 * @param us timout in microseconds.
 */
extern void
reql_conn_set_timeout(ReQL_Conn_t *conn, const ReQL_Token s, const ReQL_Token us);

/**
 * @brief get timeout used on connection.
 * @param conn connection object.
 * @return timeout in seconds.
 */
extern ReQL_Token
reql_conn_timeout(ReQL_Conn_t *conn);

/**
 * @brief reql_connect
 * @param conn connection object.
 * @param buf allocated buffer that will be filled with an error message or `SUCCESS\0`
 * @param size number of bytes in buffer.
 * @return 0 on success. non zero on error.
 */
extern int
reql_conn_connect(ReQL_Conn_t *conn, ReQL_Byte *buf, const ReQL_Size size);

/**
 * @brief Declare a connection ready to be closed.
 * @param conn connection object.
 */
extern void
reql_conn_close(ReQL_Conn_t *conn);

/**
 * @brief Ensure a connection object is cleaned up and ready to be deallocated.
 * @param conn connection object.
 */
extern void
reql_conn_destroy(ReQL_Conn_t *conn);

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
reql_run_query(ReQL_Cur_t *cur, ReQL_Obj_t *query, ReQL_Conn_t *conn, ReQL_Obj_t *kwargs, ReQL_Parse_t (*get_parser)());

/**
 * @brief send a no reply wait query.
 * @param conn connection object.
 * @return 0 on success. Non zero otherwise.
 */
extern int
reql_no_reply_wait_query(ReQL_Conn_t *conn);

extern int
reql_stop_query(ReQL_Cur_t *cur);

extern int
reql_continue_query(ReQL_Cur_t *cur);

#ifdef __cplusplus
}
#endif

#endif  // REQL_REQL_CONNECTION_H_
