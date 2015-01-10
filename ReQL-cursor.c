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

#include <pthread.h>
#include <stdlib.h>

static pthread_mutex_t response_lock = PTHREAD_MUTEX_INITIALIZER;
static pthread_once_t init_lock = PTHREAD_ONCE_INIT;

void _reql_init_cur(void) {
  pthread_mutexattr_t *attrs = malloc(sizeof(pthread_mutexattr_t));

  pthread_mutexattr_init(attrs);
  pthread_mutexattr_settype(attrs, PTHREAD_MUTEX_ERRORCHECK);

  pthread_mutexattr_destroy(attrs);

  free(attrs);
}

void _reql_cursor_init(_ReQL_Cur cur) {
  pthread_once(&init_lock, _reql_init_cur);

  cur->token = 0;
  cur->done = 0;
  cur->next = cur->prev = cur;
  cur->conn = NULL;
  cur->response = NULL;
}

void _reql_set_cur_response(_ReQL_Cur_t *cur, _ReQL_Op res) {
  pthread_mutex_lock(&response_lock);
  cur->response = res;
  pthread_mutex_unlock(&response_lock);
}

_ReQL_Op _reql_get_cur_res(_ReQL_Cur_t *cur) {
  _ReQL_Op res = NULL;

  while (1) {
    pthread_mutex_lock(&response_lock);
    if (cur->response) {
      res = cur->response;
      cur->response = NULL;
      pthread_mutex_unlock(&response_lock);
      break;
    }
    pthread_mutex_unlock(&response_lock);
    //sleep(1);
  }

  return res;
}

void _reql_cursor_next(_ReQL_Cur_t *cur) {
}

void _reql_close_cur(_ReQL_Cur cur) {
  cur->prev->next = cur->next == cur ? cur->prev : cur->next;
  cur->next->prev = cur->prev == cur ? cur->next : cur->prev;
}
