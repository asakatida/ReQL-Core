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
#include "./reql/query.h"

#include <memory>

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
  if (cur == nullptr) {
    return;
  }
  pthread_mutex_unlock(cur->condition.mutex);
}

static char
reql_cur_open_(ReQL_Cur_t *cur) {
  return cur->conn != nullptr;
}

static void
reql_cur_set_end_cb_(ReQL_Cur_t *cur, ReQL_End_Function cb, void *arg) {
  cur->cb.end = cb;
  cur->cb.data[END] = arg;
}

static void
reql_cur_set_error_cb_(ReQL_Cur_t *cur, ReQL_Error_Function cb, void *arg) {
  cur->cb.error = cb;
  cur->cb.data[ERROR] = arg;
}

extern void
reql_cur_set_end_cb(ReQL_Cur_t *cur, ReQL_End_Function cb, void *arg) {
  reql_cur_lock(cur);
  reql_cur_set_end_cb_(cur, cb, arg);
  reql_cur_unlock(cur);
}

extern void
reql_cur_set_error_cb(ReQL_Cur_t *cur, ReQL_Error_Function cb, void *arg) {
  reql_cur_lock(cur);
  reql_cur_set_error_cb_(cur, cb, arg);
  reql_cur_unlock(cur);
}

extern void
reql_cur_set_response(ReQL_Cur_t *cur, ReQL_Obj_t *res) {
  reql_cur_lock(cur);
  reql_json_destroy(cur->response);
  cur->response = res;
  reql_cur_unlock(cur);
}

static void
reql_cur_close_(ReQL_Cur_t *cur) {
  if (reql_cur_open_(cur) != 0) {
    ReQL_Cur_t *prev = cur->prev == cur ? nullptr : cur->prev;
    ReQL_Cur_t *next = cur->next == cur ? nullptr : cur->next;
    if (next == nullptr && prev == nullptr) {
    } else if (prev == nullptr) {
      next->prev = next;
    } else if (next == nullptr) {
      prev->next = prev;
    } else {
      next->prev = prev;
      prev->next = next;
    }
    cur->conn->cursors = next;
    cur->conn = nullptr;
    if (cur->cb.each != nullptr) {
      cur->cb.each(nullptr, cur->cb.data[EACH]);
    }
    if (cur->cb.end != nullptr) {
      cur->cb.end(cur->cb.data[END]);
    }
    cur->cb.data[EACH] = nullptr;
    cur->cb.data[END] = nullptr;
    cur->cb.data[ERROR] = nullptr;
    cur->cb.each = nullptr;
    cur->cb.end = nullptr;
    cur->cb.error = nullptr;
  }
}

static void *
reql_cur_loop(void *data) {
  ReQL_Cur_t *cur = reinterpret_cast<ReQL_Cur_t *>(data);
  reql_cur_lock(cur);
  while (cur->conn != nullptr) {
    if (cur->response == nullptr) {
      reql_cur_unlock(cur);
      sched_yield();
      reql_cur_lock(cur);
      continue;
    }
    ReQL_Obj_t *res = cur->response; cur->response = nullptr;
    reql_cur_unlock(cur);
    char close = 0;
    ReQL_Obj_t key;
    ReQL_Byte buf[1];
    reql_string_init(&key, buf, reinterpret_cast<ReQL_Byte *>(const_cast<char *>("t")), 1);
    ReQL_Obj_t *type = reql_object_get(res, &key);
    if (type == nullptr) {
      if (cur->cb.error != nullptr) {
        cur->cb.error(res, cur->cb.data[ERROR]);
      }
      reql_json_destroy(res);
      reql_cur_close(cur);
      break;
    } else {
      int r_type = static_cast<int>(reql_to_number(type));
      switch (r_type) {
        case REQL_SUCCESS_ATOM:
        case REQL_SUCCESS_SEQUENCE:
        case REQL_WAIT_COMPLETE: {
          close = 1;
          break;
        }
        case REQL_SUCCESS_PARTIAL: {
          reql_cur_lock(cur);
          if (cur->conn != nullptr) {
            reql_continue_query(cur);
          }
          reql_cur_unlock(cur);
          break;
        }
        case REQL_CLIENT_ERROR:
        case REQL_COMPILE_ERROR:
        case REQL_RUNTIME_ERROR:
        default: {
          reql_cur_lock(cur);
          if (cur->cb.error != nullptr) {
            cur->cb.error(res, cur->cb.data[ERROR]);
          }
          reql_cur_unlock(cur);
          reql_cur_close(cur);
        }
      }
    }
    reql_string_init(&key, buf, reinterpret_cast<ReQL_Byte *>(const_cast<char *>("r")), 1);
    ReQL_Obj_t *r_res = reql_object_get(res, &key);
    ReQL_Iter_t it = reql_new_iter(r_res);
    ReQL_Obj_t *elem = nullptr;
    while ((elem = reql_iter_next(&it)) != nullptr) {
      reql_cur_lock(cur);
      while (cur->cb.each == nullptr) {
        reql_cur_unlock(cur);
        if (reql_cur_open(cur) == 0) {
          reql_json_destroy(res);
          return nullptr;
        }
        sched_yield();
        reql_cur_lock(cur);
      }
      if (cur->cb.each(elem, cur->cb.data[EACH])) {
        reql_cur_unlock(cur);
        reql_cur_close(cur);
        return nullptr;
      }
      reql_cur_unlock(cur);
    }
    reql_json_destroy(res);
    if (close) {
      reql_cur_close(cur);
    }
    reql_cur_lock(cur);
  }
  reql_cur_unlock(cur);
  return nullptr;
}

extern void
reql_cur_close(ReQL_Cur_t *cur) {
  reql_cur_lock(cur);
  if (cur->conn != nullptr) {
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
  pthread_mutexattr_t *attrs;
  pthread_mutex_t *mutex;
  try {
    attrs = new pthread_mutexattr_t;
  } catch (std::bad_alloc&) {
    reql_cur_memory_error(__func__);
    return;
  }
  try {
    mutex = new pthread_mutex_t;
  } catch (std::bad_alloc&) {
    delete attrs;
    reql_cur_memory_error(__func__);
    return;
  }
  pthread_mutexattr_init(attrs);
  pthread_mutexattr_settype(attrs, PTHREAD_MUTEX_ERRORCHECK);
  pthread_mutex_init(mutex, attrs);
  pthread_mutexattr_destroy(attrs);
  delete attrs;

  memset(cur, static_cast<int>(NULL), sizeof(ReQL_Cur_t));

  cur->condition.mutex = mutex;

  reql_cur_lock(cur);
  cur->next = conn->cursors == nullptr ? cur : conn->cursors;
  cur->next->prev = cur;
  cur->prev = cur;
  cur->conn = conn;
  cur->token = token;
  cur->cb.each = nullptr;
  cur->cb.end = nullptr;
  cur->cb.error = nullptr;
  cur->cb.data[EACH] = nullptr;
  cur->cb.data[END] = nullptr;
  cur->cb.data[ERROR] = nullptr;

  if (pthread_create(&cur->condition.thread, nullptr, reql_cur_loop, cur) != 0) {
    reql_cur_memory_error(__func__);
  }

  reql_cur_unlock(cur);
}

extern void
reql_cur_destroy(ReQL_Cur_t *cur) {
  if (cur == nullptr) {
    return;
  }
  reql_cur_lock(cur);
  reql_cur_close_(cur);
  reql_json_destroy(cur->response); cur->response = nullptr;
  if (cur->condition.thread != nullptr) {
    reql_cur_unlock(cur);
    pthread_join(cur->condition.thread, nullptr);
    cur->condition.thread = nullptr;
  } else {
    reql_cur_unlock(cur);
  }
}

struct ReQL_Cur_Data_Holder {
  union {
    ReQL_Each_Function each;
    ReQL_End_Function end;
    ReQL_Error_Function error;
  } cb;
  void *cb_data;
  pthread_cond_t *done;
};

static int
reql_cur_next_cb(ReQL_Obj_t *a_res, void *arg) {
  struct ReQL_Cur_Data_Holder *p_data = reinterpret_cast<struct ReQL_Cur_Data_Holder *>(arg);
  ReQL_Cur_t *cur = reinterpret_cast<ReQL_Cur_t*>(p_data->cb_data);
  cur->cb.each = nullptr;
  p_data->cb_data = reql_json_move(a_res);
  pthread_cond_broadcast(p_data->done);
  return 0;
}

static void
reql_cur_each_(ReQL_Cur_t *cur, ReQL_Each_Function cb, void *arg) {
  cur->cb.each = cb;
  cur->cb.data[EACH] = arg;
}

static ReQL_Obj_t *
reql_cur_next_(ReQL_Cur_t *cur) {
  if (reql_cur_open_(cur) == 0) {
    return nullptr;
  }
  ReQL_Each_Function each = cur->cb.each;
  void *cb_data = cur->cb.data[EACH];
  struct ReQL_Cur_Data_Holder data;
  pthread_cond_t *done;
  try {
    done = new pthread_cond_t;
  } catch (std::bad_alloc&) {
    return nullptr;
  }
  pthread_cond_init(done, nullptr);
  data.done = done;
  data.cb_data = cur;
  reql_cur_each_(cur, reql_cur_next_cb, &data);
  int success = 0;
  while (data.cb_data == cur && success == 0 && reql_cur_open_(cur) != 0) {
    success = pthread_cond_wait(done, cur->condition.mutex);
  }
  pthread_cond_destroy(done);
  delete done;
  cur->cb.each = each;
  cur->cb.data[EACH] = cb_data;
  return reinterpret_cast<ReQL_Obj_t *>(data.cb_data);
}

extern ReQL_Obj_t *
reql_cur_next(ReQL_Cur_t *cur) {
  reql_cur_lock(cur);
  ReQL_Obj_t *res = reql_cur_next_(cur);
  reql_cur_unlock(cur);
  return res;
}

extern void
reql_cur_each(ReQL_Cur_t *cur, ReQL_Each_Function cb, void *arg) {
  reql_cur_lock(cur);
  reql_cur_each_(cur, cb, arg);
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
  struct ReQL_Cur_Data_Holder *p_data = reinterpret_cast<struct ReQL_Cur_Data_Holder *>(arg);
  if (p_data->cb.end != nullptr) {
    p_data->cb.end(p_data->cb_data);
  }
  pthread_cond_broadcast(p_data->done);
}

static void
reql_cur_drain_(ReQL_Cur_t *cur) {
  if (cur->cb.each == nullptr) {
    reql_cur_each_(cur, reql_cur_drain_blank_cb, nullptr);
  }
  struct ReQL_Cur_Data_Holder data;
  data.cb.end = cur->cb.end;
  data.cb_data = cur->cb.data[END];
  pthread_cond_t *done;
  try {
    done = new pthread_cond_t;
  } catch (std::bad_alloc&) {
    return;
  }
  pthread_cond_init(done, nullptr);
  data.done = done;
  reql_cur_set_end_cb_(cur, reql_cur_drain_end_cb, &data);
  int success = 0;
  while (success == 0 && reql_cur_open_(cur) != 0) {
    success = pthread_cond_wait(done, cur->condition.mutex);
  }
  pthread_cond_destroy(done);
  delete done;
}

extern void
reql_cur_drain(ReQL_Cur_t *cur) {
  reql_cur_lock(cur);
  reql_cur_drain_(cur);
  reql_cur_unlock(cur);
}

static ReQL_Size
reql_update_array(ReQL_Obj_t *array, ReQL_Obj_t *elem) {
  ReQL_Size new_alloc = reql_array_append(array, elem);

  if (reql_error_type() != REQL_E_NO) {
    return new_alloc;
  }

  if (new_alloc != 0) {
    ReQL_Obj_t **arr;
    try {
      arr = new ReQL_Obj_t*[new_alloc];
      array->obj.datum.json.var.alloc_size = new_alloc;
      memcpy(arr, array->obj.datum.json.var.data.array, sizeof(ReQL_Obj_t*) * array->obj.datum.json.var.size);
      delete []array->obj.datum.json.var.data.array;
      array->obj.datum.json.var.data.array = arr;
      return reql_update_array(array, elem);
    } catch (std::bad_alloc&) {
      array->obj.datum.json.var.size = array->obj.datum.json.var.alloc_size = 0;
      delete []array->obj.datum.json.var.data.array;
      array->obj.datum.json.var.data.array = nullptr;
    }
  }

  return new_alloc;
}

static int
reql_cur_to_array_cb(ReQL_Obj_t *res, void *data) {
  return static_cast<int>(reql_update_array(reinterpret_cast<ReQL_Obj_t *>(data), reql_json_move(res)));
}

extern ReQL_Obj_t *
reql_cur_to_array(ReQL_Cur_t *cur) {
  ReQL_Obj_t *array;
  try {
    array = new ReQL_Obj_t;
  } catch (std::bad_alloc&) {
    return nullptr;
  }
  ReQL_Obj_t **arr;
  try {
    arr = new ReQL_Obj_t*[20];
  } catch (std::bad_alloc&) {
    delete array;
    return nullptr;
  }
  reql_array_init(array, arr, 20);
  reql_cur_each(cur, reql_cur_to_array_cb, array);
  reql_cur_drain(cur);
  return array;
}
