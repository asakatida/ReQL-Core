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

#include "ReQL-cursor.h"

#include "ReQL.h"
#include "ReQL-util.h"

#include <stdlib.h>

static int
reql_cur_lock(ReQL_Cur_t *cur) {
  return pthread_mutex_lock(cur->mutex);
}

static int
reql_cur_unlock(ReQL_Cur_t *cur) {
  return pthread_mutex_unlock(cur->mutex);
}

extern void
reql_cursor_init(ReQL_Cur_t *cur) {
  pthread_mutexattr_t *attrs = malloc(sizeof(pthread_mutexattr_t));

  pthread_mutexattr_init(attrs);
  pthread_mutexattr_settype(attrs, PTHREAD_MUTEX_ERRORCHECK);

  pthread_mutex_t *mutex = malloc(sizeof(pthread_mutex_t));

  pthread_mutex_init(mutex, attrs);

  cur->mutex = mutex;

  pthread_mutexattr_destroy(attrs);

  free(attrs); attrs = NULL;

  cur->token = 0;
  cur->done = 0;
  cur->next = cur->prev = cur;
  cur->conn = NULL;
  cur->response = NULL;
}

extern void
reql_set_cur_response(ReQL_Cur_t *cur, ReQL_Obj_t *res) {
  reql_cur_lock(cur);
  cur->response = res;
  reql_cur_unlock(cur);
}

extern ReQL_Obj_t *
reql_cursor_next(ReQL_Cur_t *cur) {
  ReQL_Obj_t *res = NULL;

  while (1) {
    reql_cur_lock(cur);
    if (cur->response != NULL || cur->done == 1) {
      res = cur->response;
      cur->response = NULL;
      reql_cur_unlock(cur);
      break;
    }
    reql_cur_unlock(cur);
    //sleep(1);
  }

  return res;
}

extern char
reql_cur_open(ReQL_Cur_t *cur) {
  reql_cur_lock(cur);
  const char done = cur->done;
  reql_cur_unlock(cur);
  return !done;
}

extern void
reql_close_cur(ReQL_Cur_t *cur) {
  if (!reql_cur_open(cur)) {
    return;
  }
  reql_cur_lock(cur);
  reql_json_destroy(cur->response); cur->response = NULL;
  cur->done = 1;
  ReQL_Cur_t *prev = cur->prev;
  ReQL_Cur_t *next = cur->next;
  if (next == cur && prev == cur) {
    cur->conn->cursors = NULL;
  } else { // TODO this has deadlock/access issues
    reql_cur_lock(prev);
    prev->next = next == cur ? prev : next;
    reql_cur_unlock(prev);
    reql_cur_lock(next);
    next->prev = prev == cur ? next : prev;
    reql_cur_unlock(next);
  }
  cur->conn = NULL;
  reql_cur_unlock(cur);
}
