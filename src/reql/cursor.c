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

#include "./reql/cursor.h"

#include "./reql/connection.h"
#include "./reql/error.h"
#include "./reql/expr.h"

#include <pthread.h>
#include <stdlib.h>
#include <string.h>

enum {
  EACH,
  END,
  ERROR
};

static void
reql_cur_close_(ReQL_Cur_t *cur);

static void
reql_cur_error(const char *msg, const char *trace) {
  reql_error_init(REQL_E_CURSOR, msg, trace);
}

static void
reql_cur_memory_error(const char *trace) {
  reql_cur_error("Insufficient memory", trace);
}

static void
reql_cur_lock(ReQL_Cur_t *cur) {
  pthread_mutex_lock(cur->condition.mutex);
}

static void
reql_cur_unlock(ReQL_Cur_t *cur) {
  if (cur == NULL) {
    return;
  }
  pthread_mutex_unlock(cur->condition.mutex);
}

static char
reql_cur_open_(ReQL_Cur_t *cur) {
  return cur->conn != NULL;
}

extern void
reql_cur_set_end_cb(ReQL_Cur_t *cur, ReQL_End_Function cb, void *arg) {
  cur->cb.end = cb;
  cur->cb.data[END] = arg;
}

extern void
reql_cur_set_error_cb(ReQL_Cur_t *cur, ReQL_Error_Function cb, void *arg) {
  cur->cb.error = cb;
  cur->cb.data[ERROR] = arg;
}

static void
reql_cur_set_response_(ReQL_Cur_t *cur, ReQL_Obj_t *res) {
  if (reql_cur_open_(cur) == 0) {
    reql_json_destroy(res);
    return;
  }
  if (cur->cb.each == NULL) {
    reql_json_destroy(cur->cb.data[EACH]);
    cur->cb.data[EACH] = res;
  } else {
    ReQL_Obj_t key;
    ReQL_Byte buf[1];
    reql_string_init(&key, buf, 1);
    reql_string_append(&key, (ReQL_Byte *)"t", 1);
    ReQL_Obj_t *type = reql_object_get(res, &key);
    if (type == NULL) {
      reql_cur_close_(cur);
    } else {
      int r_type = (int)(reql_to_number(type));
      switch (r_type) {
        case REQL_SUCCESS_PARTIAL: {
          reql_continue_query(cur);
          break;
        }
        case REQL_SUCCESS_ATOM:
        case REQL_SUCCESS_SEQUENCE:
        case REQL_WAIT_COMPLETE: {
          reql_cur_close_(cur);
          break;
        }
        case REQL_CLIENT_ERROR:
        case REQL_COMPILE_ERROR:
        case REQL_RUNTIME_ERROR: {
          reql_cur_close_(cur);
          return;
        }
        default: {
          reql_cur_close_(cur);
          return;
        }
      }
    }
    reql_string_init(&key, buf, 1);
    reql_string_append(&key, (ReQL_Byte *)"r", 1);
    ReQL_Obj_t *r_res = reql_object_get(res, &key);
    if (reql_datum_type(r_res) == REQL_R_ARRAY) {
      ReQL_Iter_t it = reql_new_iter(r_res);
      ReQL_Obj_t *elem = NULL;
      while ((elem = reql_iter_next(&it)) != NULL) {
        if (cur->cb.each == NULL) {
          return;
        }
        cur->cb.each(elem, cur->cb.data[EACH]);
        reql_json_destroy(elem);
      }
    } else {
      cur->cb.each(r_res, cur->cb.data[EACH]);
    }
    reql_json_destroy(res);
  }
}

extern void
reql_cur_set_response(ReQL_Cur_t *cur, ReQL_Obj_t *res) {
  reql_cur_lock(cur);
  reql_cur_set_response_(cur, res);
  reql_cur_unlock(cur);
}

static void
reql_cur_close_(ReQL_Cur_t *cur) {
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
    if (cur->cb.each != NULL) {
      cur->cb.each(NULL, cur->cb.data[EACH]);
    }
    if (cur->cb.end != NULL) {
      cur->cb.end(cur->cb.data[END]);
    }
  }
}

extern void
reql_cur_close(ReQL_Cur_t *cur) {
  reql_cur_lock(cur);
  if (cur->conn != NULL) {
    reql_stop_query(cur);
  }
  reql_cur_close_(cur);
  reql_cur_unlock(cur);
}

extern char
reql_cur_open(ReQL_Cur_t *cur) {
  reql_cur_lock(cur);
  const char open = reql_cur_open_(cur);
  reql_cur_unlock(cur);
  return open;
}

extern void
reql_cur_init(ReQL_Cur_t *cur, ReQL_Conn_t *conn, ReQL_Token token) {
  pthread_mutexattr_t *attrs = malloc(sizeof(pthread_mutexattr_t));
  if (attrs == NULL) {
    reql_cur_memory_error(__func__);
    return;
  }
  pthread_mutexattr_init(attrs);
  pthread_mutexattr_settype(attrs, PTHREAD_MUTEX_ERRORCHECK);
  pthread_mutex_t *mutex = malloc(sizeof(pthread_mutex_t));
  if (mutex == NULL) {
    pthread_mutexattr_destroy(attrs);
    free(attrs); attrs = NULL;
    reql_cur_memory_error(__func__);
    return;
  }
  pthread_mutex_init(mutex, attrs);
  pthread_mutexattr_destroy(attrs);
  free(attrs); attrs = NULL;

  memset(cur, (int)NULL, sizeof(ReQL_Cur_t));

  cur->condition.mutex = mutex;

  reql_cur_lock(cur);
  cur->next = conn->cursors == NULL ? cur : conn->cursors;
  cur->next->prev = cur;
  cur->prev = cur;
  cur->conn = conn;
  cur->token = token;
  reql_cur_unlock(cur);
}

extern void
reql_cur_destroy(ReQL_Cur_t *cur) {
  if (cur == NULL) {
    return;
  }
  reql_cur_lock(cur);
  reql_cur_close_(cur);
  if (cur->cb.each == NULL) {
    reql_json_destroy(cur->cb.data[EACH]);
  }
  reql_cur_unlock(cur);
}

struct ReQL_Cur_Data_Holder {
  union {
    ReQL_Each_Function each;
    ReQL_End_Function end;
    ReQL_Error_Function error;
  } cb;
  void *cb_data;
  ReQL_Cur_t *cursor;
  pthread_cond_t *done;
};

static int
reql_cur_next_cb(ReQL_Obj_t *a_res, void *arg) {
  struct ReQL_Cur_Data_Holder *p_data = (struct ReQL_Cur_Data_Holder *)arg;
  p_data->cursor->cb.each = p_data->cb.each;
  p_data->cursor->cb.data[EACH] = p_data->cb_data;
  p_data->cb_data = reql_json_move(a_res);
  pthread_cond_broadcast(p_data->done);
  return 0;
}

extern ReQL_Obj_t *
reql_cur_next(ReQL_Cur_t *cur) {
  reql_cur_lock(cur);
  if (reql_cur_open_(cur) == 0) {
    return NULL;
  }
  ReQL_Obj_t *res = NULL;
  if (cur->cb.each == NULL && cur->cb.data[EACH] != NULL) {
    res = cur->cb.data[EACH];
    cur->cb.data[EACH] = NULL;
  } else {
    struct ReQL_Cur_Data_Holder data;
    data.cb.each = cur->cb.each;
    data.cb_data = cur->cb.data[EACH];
    pthread_cond_t *done = malloc(sizeof(pthread_cond_t));
    pthread_cond_init(done, NULL);
    data.done = done;
    cur->cb.each = reql_cur_next_cb;
    cur->cb.data[EACH] = &data;
    int success = 0;
    while (data.cb_data == cur->cb.data[EACH] && success == 0 && reql_cur_open_(cur) != 0) {
      success = pthread_cond_wait(done, cur->condition.mutex);
    }
    pthread_cond_destroy(done);
    free(done);
    cur->cb.each = data.cb.each;
    cur->cb.data[EACH] = data.cb_data;
    res = data.cb_data;
  }
  reql_cur_unlock(cur);
  return res;
}

extern void
reql_cur_each(ReQL_Cur_t *cur, ReQL_Each_Function cb, void *arg) {
  reql_cur_lock(cur);
  if (cur->cb.each == NULL && cur->cb.data[EACH] != NULL) {
    ReQL_Obj_t *res = cur->cb.data[EACH];
    cur->cb.each = cb;
    cur->cb.data[EACH] = arg;
    reql_cur_set_response_(cur, res);
  } else {
    cur->cb.each = cb;
    cur->cb.data[EACH] = arg;
  }
  reql_cur_unlock(cur);
}

static int
reql_cur_drain_blank_cb(ReQL_Obj_t *res, void *data) {
  (void)res;
  (void)data;
  return 0;
}

static void
reql_cur_drain_end_cb(void *arg) {
  struct ReQL_Cur_Data_Holder *p_data = (struct ReQL_Cur_Data_Holder *)arg;
  if (p_data->cb.end != NULL) {
    p_data->cb.end(p_data->cb_data);
  }
  pthread_cond_broadcast(p_data->done);
}

extern void
reql_cur_drain(ReQL_Cur_t *cur) {
  reql_cur_lock(cur);
  if (cur->cb.each == NULL) {
    cur->cb.each = reql_cur_drain_blank_cb;
    if (cur->cb.data[EACH] != NULL) {
      reql_cur_set_response_(cur, cur->cb.data[EACH]);
    }
  }
  struct ReQL_Cur_Data_Holder data;
  data.cb.end = cur->cb.end;
  data.cb_data = cur->cb.data[END];
  pthread_cond_t *done = malloc(sizeof(pthread_cond_t));
  pthread_cond_init(done, NULL);
  data.done = done;
  cur->cb.end = reql_cur_drain_end_cb;
  cur->cb.data[END] = &data;
  int success = 0;
  while (success == 0 && reql_cur_open_(cur) != 0) {
    success = pthread_cond_wait(done, cur->condition.mutex);
  }
  pthread_cond_destroy(done);
  free(done);
  cur->cb.end = NULL;
  cur->cb.each = NULL;
  cur->cb.data[END] = NULL;
  reql_cur_unlock(cur);
}

static ReQL_Size
reql_update_array(ReQL_Obj_t *array, ReQL_Obj_t *elem) {
  ReQL_Size new_alloc = reql_array_append(array, elem);

  if (reql_error_type() != REQL_E_NO) {
    return new_alloc;
  }

  if (new_alloc != 0) {
    ReQL_Obj_t **arr = array->obj.datum.json.var.data.array;

    arr = realloc(arr, sizeof(ReQL_Obj_t*) * new_alloc);

    if (arr == NULL) {
      array->obj.datum.json.var.size = array->obj.datum.json.var.alloc_size = 0;
      free(array->obj.datum.json.var.data.array);
      array->obj.datum.json.var.data.array = NULL;
    } else {
      array->obj.datum.json.var.alloc_size = new_alloc;
      array->obj.datum.json.var.data.array = arr;
      return reql_update_array(array, elem);
    }
  }

  return new_alloc;
}

static int
reql_cur_to_array_cb(ReQL_Obj_t *res, void *data) {
  reql_update_array(data, reql_json_move(res));
  return 0;
}

extern ReQL_Obj_t *
reql_cur_to_array(ReQL_Cur_t *cur) {
  ReQL_Obj_t *array = malloc(sizeof(ReQL_Obj_t));
  ReQL_Obj_t **arr = malloc(sizeof(ReQL_Obj_t *) * 20);
  reql_array_init(array, arr, 20);
  reql_cur_lock(cur);
  cur->cb.each = reql_cur_to_array_cb;
  cur->cb.data[EACH] = array;
  reql_cur_unlock(cur);
  reql_cur_drain(cur);
  return array;
}
