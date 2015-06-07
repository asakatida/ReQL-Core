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

#include <stdlib.h>
#include <string.h>

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

static ReQL_Conn_t *
reql_cur_conn(const ReQL_Cur_t *cur) {
  return cur->conn;
}

static char
reql_cur_open_(ReQL_Cur_t *cur) {
  return reql_cur_conn(cur) != NULL;
}

static ReQL_Obj_t *
reql_cur_response(const ReQL_Cur_t *cur) {
  return cur->response;
}

extern void
reql_cur_set_response(ReQL_Cur_t *cur, ReQL_Obj_t *res) {
  reql_cur_lock(cur);
  if (reql_cur_open_(cur) == 0) {
    reql_json_destroy(res);
    return;
  }
  ReQL_Obj_t key;
  ReQL_Byte buf[1];
  const ReQL_Byte *ext = (ReQL_Byte *)"t";
  reql_string_init(&key, buf, 1);
  reql_string_append(&key, ext, 1);
  ReQL_Obj_t *type = reql_object_get(res, &key);
  if (type == NULL) {
    reql_cur_close_(cur);
  } else {
    int r_type = (int)(reql_to_number(type));
    switch (r_type) {
      case REQL_SUCCESS_PARTIAL: {
        break;
      }
      case REQL_SUCCESS_ATOM:
      case REQL_SUCCESS_SEQUENCE:
      case REQL_WAIT_COMPLETE:
      case REQL_CLIENT_ERROR:
      case REQL_COMPILE_ERROR:
      case REQL_RUNTIME_ERROR: {
        reql_cur_close_(cur);
        break;
      }
      default: {
        reql_cur_close_(cur);
        break;
      }
    }
  }
  if (cur->cb.each != NULL) {
    if (reql_cur_open_(cur) != 0) {
      reql_continue_query(cur);
    }
    cur->cb.each(res, cur->cb.each_data);
    reql_json_destroy(res);
  } else {
    reql_json_destroy(cur->old_res);
    cur->old_res = cur->response;
    cur->response = res;
  }
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
      cur->cb.each(NULL, cur->cb.each_data);
    }
    if (cur->cb.end != NULL) {
      cur->cb.end(cur->cb.end_data);
    }
  }
}

extern void
reql_cur_close(ReQL_Cur_t *cur) {
  reql_cur_lock(cur);
  if (cur->conn != NULL) {
    reql_stop_query(cur, cur->conn);
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
  cur->it = reql_new_iter(NULL);
  cur->token = token;
  reql_cur_unlock(cur);
}

extern void
reql_cur_destroy(ReQL_Cur_t *cur) {
  if (cur == NULL) {
    return;
  }
  reql_cur_close(cur);
  reql_cur_lock(cur);
  reql_json_destroy(cur->response);
  reql_json_destroy(cur->old_res);
  reql_cur_unlock(cur);
}

extern ReQL_Obj_t *
reql_cur_next(ReQL_Cur_t *cur) {
  reql_cur_lock(cur);
  if (reql_cur_open_(cur) == 0) {
    return NULL;
  }
  ReQL_Obj_t *res = reql_cur_response(cur);
  if (res == NULL) {
    struct ReQL_Cur_Data_Holder {
      ReQL_Each_Function each;
      void *each_data;
      pthread_cond_t *done;
      ReQL_Obj_t *res;
    };
    struct ReQL_Cur_Data_Holder data;
    data.each = cur->cb.each;
    data.each_data = cur->cb.each_data;
    pthread_cond_t *done = malloc(sizeof(pthread_cond_t));
    pthread_cond_init(done, NULL);
    data.done = done;
    data.res = NULL;
    cur->cb.each = ^(ReQL_Obj_t *a_res, void *arg) {
      struct ReQL_Cur_Data_Holder *p_data = (struct ReQL_Cur_Data_Holder *)arg;
      p_data->res = reql_obj_move(a_res);
      cur->cb.each = p_data->each;
      cur->cb.each_data = p_data->each_data;
      pthread_cond_broadcast(p_data->done);
      return 0;
    };
    cur->cb.each_data = &data;
    int success = 0;
    while (res == NULL && success == 0 && reql_cur_open_(cur)) {
      success = pthread_cond_wait(done, cur->condition.mutex);
    }
    cur->cb.each = data.each;
    cur->cb.each_data = data.each_data;
    res = data.res;
  }
  reql_cur_unlock(cur);
  return res;
}

extern void
reql_cur_each(ReQL_Cur_t *cur, ReQL_Each_Function cb, void *arg) {
  reql_cur_lock(cur);
  cur->cb.each = cb;
  cur->cb.each_data = arg;
  reql_cur_unlock(cur);
}

extern void
reql_cur_drain(ReQL_Cur_t *cur) {
  reql_cur_lock(cur);
  if (cur->cb.each == NULL) {
    cur->cb.each = ^(ReQL_Obj_t *res, void *data) { (void)res; (void)data; return 0; };
  }
  __block pthread_cond_t done;
  ReQL_End_Function end = cur->cb.end;
  cur->cb.end = ^(void *data) {
    if (end != NULL) {
      end(data);
    }
    reql_cur_close_(cur);
    pthread_cond_broadcast(&done);
    return 0;
  };
  int success = 0;
  while (success == 0 && reql_cur_open_(cur)) {
    success = pthread_cond_wait(&done, cur->condition.mutex);
  }
  cur->cb.end = NULL;
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

extern ReQL_Obj_t *
reql_cur_to_array(ReQL_Cur_t *cur) {
  ReQL_Obj_t *array = malloc(sizeof(ReQL_Obj_t));
  ReQL_Obj_t **arr = malloc(sizeof(ReQL_Obj_t *) * 20);
  reql_array_init(array, arr, 20);
  reql_cur_lock(cur);
  cur->cb.each = ^(ReQL_Obj_t *res, void *data) {
    reql_update_array(data, reql_obj_move(res));
    return 0;
  };
  cur->cb.each_data = array;
  reql_cur_unlock(cur);
  reql_cur_drain(cur);
  cur->cb.each = NULL;
  return array;
}
