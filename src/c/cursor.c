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

#include "./c/cursor.h"

#include "./c/connection.h"
#include "./c/util/util.h"

#include <stdlib.h>

static void
reql_cursor_lock(ReQL_Cur_t *cur) {
  reql_conn_lock(cur->conn);
}

static void
reql_cursor_unlock(ReQL_Cur_t *cur) {
  reql_conn_unlock(cur->conn);
}

static char
reql_cursor_done(ReQL_Cur_t *cur) {
  reql_cursor_lock(cur);
  const char done = cur->done;
  reql_cursor_unlock(cur);
  return done;
}

static ReQL_Obj_t *
reql_cursor_response(ReQL_Cur_t *cur) {
  reql_cursor_lock(cur);
  ReQL_Obj_t *response = cur->response;
  reql_cursor_unlock(cur);
  return response;
}

extern void
reql_cursor_init(ReQL_Cur_t *cur) {
  cur->done = 0;
  cur->next = cur->prev = cur;
  cur->response = NULL;
}

extern void
reql_set_cur_response(ReQL_Cur_t *cur, ReQL_Obj_t *res) {
  if (reql_cursor_done(cur) == 1) {
    reql_json_destroy(res);
    return;
  }
  reql_cursor_lock(cur);
  if (cur->response != NULL) {
    reql_json_destroy(cur->response);
    cur->response = NULL;
  }
  cur->response = res;
  reql_cursor_unlock(cur);
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
reql_cur_open(ReQL_Cur_t *cur) {
  return !reql_cursor_done(cur);
}

extern void
reql_close_cur(ReQL_Cur_t *cur) {
  if (reql_cur_open(cur)) {
    reql_cursor_lock(cur);
    if (cur->response != NULL) {
      reql_json_destroy(cur->response);
      cur->response = NULL;
    }
    cur->done = 1;
    ReQL_Cur_t *prev = cur->prev;
    ReQL_Cur_t *next = cur->next;
    if (next == cur && prev == cur) {
      cur->conn->cursors = NULL;
    } else {
      prev->next = next == cur ? prev : next;
      next->prev = prev == cur ? next : prev;
    }
    reql_cursor_unlock(cur);
  }
}
