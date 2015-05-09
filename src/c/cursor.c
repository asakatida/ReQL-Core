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
  if (cur->condition.mutex == NULL) {
    return;
  }
  pthread_mutex_lock(cur->condition.mutex);
}

static void
reql_cursor_unlock(const ReQL_Cur_t *cur) {
  if (cur->condition.mutex == NULL) {
    return;
  }
  pthread_mutex_unlock(cur->condition.mutex);
}

static char
reql_cursor_done(const ReQL_Cur_t *cur) {
  return cur->done;
}

static ReQL_Conn_t *
reql_cursor_conn(const ReQL_Cur_t *cur) {
  return cur->conn;
}

static ReQL_Obj_t *
reql_cursor_response(const ReQL_Cur_t *cur) {
  return cur->response;
}

extern void
reql_cursor_set_response(ReQL_Cur_t *cur, ReQL_Obj_t *res) {
  reql_cursor_lock(cur);
  if (reql_cur_open(cur) == 0) {
    reql_json_destroy(res);
    return;
  }
  if (cur->response != NULL) {
    reql_json_destroy(cur->response);
    cur->response = NULL;
  }
  if (cur->cb != NULL) {
    cur->cb(res);
    reql_json_destroy(res);
  } else {
    cur->response = res;
  }
  reql_cursor_unlock(cur);
}

static char
reql_cursor_response_wait(ReQL_Cur_t *cur) {
  int success = 0;
  while (reql_cursor_response(cur) == NULL && success == 0) {
    success = pthread_cond_wait(cur->condition.next, cur->condition.mutex);
  }
  return reql_cur_open(cur) && (success == 0);
}

static void
reql_close_cur_(ReQL_Cur_t *cur) {
  if (reql_cur_open(cur) != 0) {
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
    pthread_cond_broadcast(cur->condition.next);
    pthread_cond_broadcast(cur->condition.done);
  }
}

extern void
reql_close_cur(ReQL_Cur_t *cur) {
  pthread_mutex_lock(cur->condition.mutex);
  reql_close_cur_(cur);
  pthread_mutex_unlock(cur->condition.mutex);
}

extern char
reql_cur_open(const ReQL_Cur_t *cur) {
  pthread_mutex_lock(cur->condition.mutex);
  const char open = reql_cursor_done(cur) == 0 && reql_cursor_conn(cur) != NULL;
  pthread_mutex_unlock(cur->condition.mutex);
  return open;
}

extern void
reql_cursor_init(ReQL_Cur_t *cur, uint64_t token) {
  pthread_mutex_lock(cur->condition.mutex);
  cur->cb = NULL;
  cur->done = 0;
  cur->next = cur->prev = cur;
  cur->response = NULL;
  cur->token = token;
  pthread_mutex_unlock(cur->condition.mutex);
}

extern ReQL_Obj_t *
reql_cursor_next(ReQL_Cur_t *cur) {
  pthread_mutex_lock(cur->condition.mutex);
  ReQL_Obj_t *res = NULL;
  if (reql_cursor_response_wait(cur) != 0) {
    res = reql_cursor_response(cur);
    cur->response = NULL;
    ReQL_Obj_t key;
    uint8_t buf[1];
    const uint8_t *ext = (uint8_t *)"t";
    reql_string_init(&key, buf, 1);
    reql_string_append(&key, ext, 1);
    ReQL_Obj_t *type = reql_object_get(res, &key);
    if (type == NULL) {
      reql_close_cur_(cur);
    } else {
      ReQL_Response_t r_type = (ReQL_Response_t)(reql_to_number(type));
      switch (r_type) {
        case REQL_SUCCESS_PARTIAL: break;
        case REQL_SUCCESS_ATOM:
        case REQL_SUCCESS_SEQUENCE:
        case REQL_WAIT_COMPLETE:
        case REQL_CLIENT_ERROR:
        case REQL_COMPILE_ERROR:
        case REQL_RUNTIME_ERROR: {
          reql_close_cur_(cur);
          break;
        }
      }
    }
  }
  pthread_mutex_unlock(cur->condition.mutex);
  return res;
}

extern void
reql_cursor_each(ReQL_Cur_t *cur, ReQL_Each_Function cb) {
  pthread_mutex_lock(cur->condition.mutex);
  cur->cb = cb;
  pthread_mutex_unlock(cur->condition.mutex);
}

extern void
reql_cur_drain(ReQL_Cur_t *cur) {
  reql_cursor_each(cur, ^(ReQL_Obj_t *res) { (void)res; return 0; });
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
