/*
Copyright 2015 Adam Grandquist

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

#include "./c/dev/cursor.h"

#include "./c/dev/connection.h"

#include <stdlib.h>

static void
reql_cursor_lock(const ReQL_Cur_t *cur) {
  reql_conn_lock(cur->conn);
}

static void
reql_cursor_unlock(const ReQL_Cur_t *cur) {
  reql_conn_unlock(cur->conn);
}

static char
reql_cursor_done(const ReQL_Cur_t *cur) {
  reql_cursor_lock(cur);
  const char done = cur->done;
  reql_cursor_unlock(cur);
  return done;
}

static ReQL_Conn_t *
reql_cursor_conn(const ReQL_Cur_t *cur) {
  reql_cursor_lock(cur);
  ReQL_Conn_t *conn = cur->conn;
  reql_cursor_unlock(cur);
  return conn;
}

static ReQL_Obj_t *
reql_cursor_response(ReQL_Cur_t *cur) {
  reql_cursor_lock(cur);
  ReQL_Obj_t *response = cur->response;
  reql_cursor_unlock(cur);
  return response;
}

extern void
reql_cursor_init(ReQL_Cur_t *cur, uint64_t token) {
  cur->cb = NULL;
  cur->done = 0;
  cur->next = cur->prev = cur;
  cur->response = NULL;
  cur->token = token;
}

extern void
reql_cur_drain(ReQL_Cur_t *cur) {
  if (cur->cb == NULL) {
    cur->cb = ^(ReQL_Obj_t *res) { return res == NULL; };
  }
  reql_cursor_next(cur);
}

extern ReQL_Obj_t *
reql_cursor_next(ReQL_Cur_t *cur) {
  while (reql_cursor_response(cur) == NULL || reql_cursor_done(cur) == 0) {}
  reql_cursor_lock(cur);
  ReQL_Obj_t *res = cur->response;
  cur->response = NULL;
  reql_cursor_unlock(cur);
  return res;
}

extern void
reql_cursor_each(ReQL_Cur_t *cur, ReQL_Each_Function cb) {
  ReQL_Obj_t *res;
  while ((res = reql_cursor_next(cur)) != NULL) {
    cb(res);
  }
}

extern ReQL_Obj_t *
reql_cursor_to_array(ReQL_Cur_t *cur) {
  ReQL_Obj_t *array = malloc(sizeof(ReQL_Obj_t));
  reql_cursor_each(cur, ^(ReQL_Obj_t *res) {
    reql_array_append(array, res);
    return 0;
  });
  return array;
}

extern char
reql_cur_open(const ReQL_Cur_t *cur) {
  return reql_cursor_done(cur) == 0 && reql_cursor_conn(cur) != NULL;
}

extern void
reql_close_cur(ReQL_Cur_t *cur) {
  if (reql_cur_open(cur) != 0) {
    reql_cursor_lock(cur);
    if (cur->response != NULL) {
      reql_json_destroy(cur->response);
      cur->response = NULL;
    }
    cur->done = 1;
    ReQL_Cur_t *prev = cur->prev;
    ReQL_Cur_t *next = cur->next;
    if (next == cur && prev == cur) {
      if (cur->conn != NULL) {
        cur->conn->cursors = NULL;
      }
    } else {
      prev->next = next == cur ? prev : next;
      next->prev = prev == cur ? next : prev;
    }
    cur->conn = NULL;
    reql_cursor_unlock(cur);
  }
}
