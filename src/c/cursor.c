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

#include "./c/connection.h"
#include "./c/dev/error.h"
#include "./c/dev/json.h"

#include <stdlib.h>
#include <string.h>

static void
reql_cursor_error(const char *msg, const char *trace) {
  reql_error_init(REQL_E_CURSOR, msg, trace);
}

static void
reql_cursor_memory_error(const char *trace) {
  reql_cursor_error("Insufficient memory", trace);
}

static void
reql_cursor_mutex_init(ReQL_Cur_t *cur) {
  if (cur->condition.mutex == NULL) {
    pthread_mutexattr_t *attrs = malloc(sizeof(pthread_mutexattr_t));

    if (attrs == NULL) {
      reql_cursor_memory_error(__func__);
      return;
    }

    pthread_mutexattr_init(attrs);
    pthread_mutexattr_settype(attrs, PTHREAD_MUTEX_ERRORCHECK);

    pthread_mutex_t *mutex = malloc(sizeof(pthread_mutex_t));

    pthread_mutex_init(mutex, attrs);

    cur->condition.mutex = mutex;

    pthread_mutexattr_destroy(attrs);

    free(attrs); attrs = NULL;
  }

  if (cur->condition.done == NULL) {
    pthread_condattr_t *attrs = malloc(sizeof(pthread_condattr_t));

    if (attrs == NULL) {
      reql_cursor_memory_error(__func__);
      return;
    }

    pthread_condattr_init(attrs);
    pthread_condattr_setpshared(attrs, PTHREAD_PROCESS_PRIVATE);

    pthread_cond_t *done = malloc(sizeof(pthread_cond_t));

    pthread_cond_init(done, attrs);

    cur->condition.done = done;

    pthread_condattr_destroy(attrs);

    free(attrs); attrs = NULL;
  }

  if (cur->condition.next == NULL) {
    pthread_condattr_t *attrs = malloc(sizeof(pthread_condattr_t));

    if (attrs == NULL) {
      reql_cursor_memory_error(__func__);
      return;
    }

    pthread_condattr_init(attrs);
    pthread_condattr_setpshared(attrs, PTHREAD_PROCESS_PRIVATE);

    pthread_cond_t *done = malloc(sizeof(pthread_cond_t));

    pthread_cond_init(done, attrs);

    cur->condition.next = done;

    pthread_condattr_destroy(attrs);

    free(attrs); attrs = NULL;
  }
}

static void
reql_cursor_mutex_destroy(ReQL_Cur_t *cur) {
  if (cur->condition.mutex != NULL) {
    pthread_mutex_destroy(cur->condition.mutex);
    free(cur->condition.mutex); cur->condition.mutex = NULL;
  }

  if (cur->condition.done != NULL) {
    pthread_cond_destroy(cur->condition.done);
    free(cur->condition.done); cur->condition.done = NULL;
  }

  if (cur->condition.next != NULL) {
    pthread_cond_destroy(cur->condition.next);
    free(cur->condition.next); cur->condition.next = NULL;
  }
}

static void
reql_cursor_lock(ReQL_Cur_t *cur) {
  reql_cursor_mutex_init(cur);
  pthread_mutex_lock(cur->condition.mutex);
}

static void
reql_cursor_unlock(ReQL_Cur_t *cur) {
  if (cur == NULL) {
    return;
  }
  if (cur->condition.mutex == NULL) {
    return;
  }
  pthread_mutex_unlock(cur->condition.mutex);
}

static ReQL_Conn_t *
reql_cursor_conn(const ReQL_Cur_t *cur) {
  return cur->conn;
}

static char
reql_cur_open_(ReQL_Cur_t *cur) {
  return reql_cursor_conn(cur) != NULL;
}

static ReQL_Obj_t *
reql_cursor_response(const ReQL_Cur_t *cur) {
  return cur->response;
}

extern void
reql_cursor_set_response(ReQL_Cur_t *cur, ReQL_Obj_t *res) {
  reql_cursor_lock(cur);
  if (reql_cur_open_(cur) == 0) {
    reql_json_destroy(res);
    return;
  }
  if (cur->response != NULL) {
    reql_json_destroy(cur->old_res);
    cur->old_res = cur->response;
    cur->response = NULL;
  }
  if (cur->cb != NULL) {
    cur->cb(res);
    reql_json_destroy(res);
  } else {
    cur->response = res;
    pthread_cond_signal(cur->condition.next);
  }
  reql_cursor_unlock(cur);
}

static char
reql_cursor_response_wait(ReQL_Cur_t *cur) {
  reql_json_destroy(cur->old_res);
  cur->old_res = cur->response;
  cur->response = NULL;
  int success = 0;
  while (reql_cursor_response(cur) == NULL && success == 0 && reql_cur_open(cur)) {
    success = pthread_cond_wait(cur->condition.next, cur->condition.mutex);
  }
  return reql_cur_open(cur) && (success == 0);
}

static void
reql_close_cur_(ReQL_Cur_t *cur) {
  if (reql_cur_open_(cur) != 0) {
    ReQL_Cur_t *prev = cur->prev == cur ? NULL : cur->prev;
    ReQL_Cur_t *next = cur->next == cur ? NULL : cur->next;
    if (next == NULL && prev == NULL) {
    } else if (prev == NULL) {
      next->prev = next;
    } else if (next == NULL) {
      prev->next = prev;
    } else {
      next->prev = prev;
      prev->next = next;
    }
    cur->conn->cursors = next;
    cur->conn = NULL;
    pthread_cond_broadcast(cur->condition.next);
    pthread_cond_broadcast(cur->condition.done);
  }
}

extern void
reql_close_cur(ReQL_Cur_t *cur) {
  reql_cursor_lock(cur);
  reql_close_cur_(cur);
  reql_cursor_unlock(cur);
}

extern char
reql_cur_open(ReQL_Cur_t *cur) {
  reql_cursor_lock(cur);
  const char open = reql_cur_open_(cur);
  reql_cursor_unlock(cur);
  return open;
}

extern void
reql_cursor_init(ReQL_Cur_t *cur, ReQL_Conn_t *conn, ReQL_Token token) {
  memset(cur, (int)NULL, sizeof(ReQL_Cur_t));
  reql_cursor_lock(cur);
  cur->next = conn->cursors == NULL ? cur : conn->cursors;
  cur->next->prev = cur;
  cur->prev = cur;
  cur->conn = conn;
  cur->it = reql_new_iter(NULL);
  cur->token = token;
  reql_cursor_unlock(cur);
}

extern void
reql_cursor_destroy(ReQL_Cur_t *cur) {
  if (cur == NULL) {
    return;
  }
  reql_close_cur(cur);
  reql_cursor_lock(cur);
  reql_json_destroy(cur->response);
  reql_json_destroy(cur->old_res);
  cur->it = reql_new_iter(NULL);
  cur->response = NULL;
  reql_cursor_mutex_destroy(cur);
  reql_cursor_unlock(cur);
}

extern ReQL_Obj_t *
reql_cursor_next(ReQL_Cur_t *cur) {
  reql_cursor_lock(cur);
  ReQL_Obj_t *res = NULL;
  if (reql_cursor_response_wait(cur) != 0) {
    res = reql_cursor_response(cur);
    ReQL_Obj_t key;
    ReQL_Byte buf[1];
    const ReQL_Byte *ext = (ReQL_Byte *)"t";
    reql_string_init(&key, buf, 1);
    reql_string_append(&key, ext, 1);
    ReQL_Obj_t *type = reql_object_get(res, &key);
    if (type == NULL) {
      reql_close_cur_(cur);
    } else {
      int r_type = (int)(reql_to_number(type));
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
        default: {
          reql_close_cur_(cur);
          break;
        }
      }
    }
  }
  reql_cursor_unlock(cur);
  return res;
}

extern void
reql_cursor_each(ReQL_Cur_t *cur, ReQL_Each_Function cb) {
  reql_cursor_lock(cur);
  cur->cb = cb;
  reql_cursor_unlock(cur);
}

extern void
reql_cur_drain(ReQL_Cur_t *cur) {
  reql_cursor_lock(cur);
  if (cur->cb == NULL) {
    cur->cb = ^(ReQL_Obj_t *res) { (void)res; return 0; };
  }
  pthread_cond_wait(cur->condition.done, cur->condition.mutex);
  reql_cursor_unlock(cur);
}

extern ReQL_Obj_t *
reql_cursor_to_array(ReQL_Cur_t *cur) {
  ReQL_Obj_t *array = malloc(sizeof(ReQL_Obj_t));
  ReQL_Obj_t **arr = malloc(sizeof(ReQL_Obj_t *) * 20);
  reql_array_init(array, arr, 20);
  reql_cursor_lock(cur);
  cur->cb = ^(ReQL_Obj_t *res) {
    reql_array_append(array, res);
    return 0;
  };
  pthread_cond_wait(cur->condition.done, cur->condition.mutex);
  reql_cursor_unlock(cur);
  return array;
}
