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

#include "./reql/cursor.hpp"

#include "./reql/connection.hpp"
#include "./reql/decode.hpp"
#include "./reql/error.hpp"
#include "./reql/query.hpp"

#include <future>
#include <memory>
#include <thread>

enum {
  EACH,
  END,
  ERROR
};

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
  if (cur == nullptr) {
    return;
  }
  if (cur->condition.mutex == nullptr) {
    return;
  }
  reinterpret_cast<std::mutex *>(cur->condition.mutex)->lock();
}

static void
reql_cur_unlock(ReQL_Cur_t *cur) {
  if (cur == nullptr) {
    return;
  }
  if (cur->condition.mutex == nullptr) {
    return;
  }
  reinterpret_cast<std::mutex *>(cur->condition.mutex)->unlock();
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
reql_cur_set_response(ReQL_Cur_t *cur, const std::basic_string<ReQL_Byte> res) {
  reql_cur_lock(cur);
  ReQL_Parse_t u_parser = cur->get_parser();
  reql_decode(res, Parser<std::basic_string<ReQL_Byte>>(&u_parser, cur));
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
    void *res = cur->response; cur->response = nullptr;
    int r_type = cur->r_type;
    reql_cur_unlock(cur);
    auto close = false;
    switch (r_type) {
      case REQL_SUCCESS_ATOM:
      case REQL_SUCCESS_SEQUENCE:
      case REQL_WAIT_COMPLETE: {
        close = true;
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
          cur->cb.error(cur->cb.data[ERROR], res);
        }
        reql_cur_unlock(cur);
        reql_cur_close(cur);
      }
    }
    reql_cur_lock(cur);
    while (cur->cb.each == nullptr) {
      reql_cur_unlock(cur);
      if (reql_cur_open(cur) == 0) {
        return nullptr;
      }
      sched_yield();
      reql_cur_lock(cur);
      continue;
    }
    if (cur->cb.each(cur->cb.data[EACH], res) != 0) {
      reql_cur_unlock(cur);
      reql_cur_close(cur);
      return nullptr;
    }
    reql_cur_unlock(cur);
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
reql_cur_init(ReQL_Cur_t *cur, ReQL_Conn_t *conn, ReQL_Token token, ReQL_Parse_t (*get_parser)()) {
  std::mutex *mutex = new std::mutex;

  memset(cur, static_cast<int>(NULL), sizeof(ReQL_Cur_t));

  cur->condition.mutex = mutex;

  reql_cur_lock(cur);
  cur->next = conn->cursors == nullptr ? cur : conn->cursors;
  cur->next->prev = cur;
  cur->prev = cur;
  cur->conn = conn;
  cur->token = token;
  cur->get_parser = get_parser;
  cur->cb.each = nullptr;
  cur->cb.end = nullptr;
  cur->cb.error = nullptr;
  cur->cb.data[EACH] = nullptr;
  cur->cb.data[END] = nullptr;
  cur->cb.data[ERROR] = nullptr;

  cur->condition.thread = new std::thread(reql_cur_loop, cur);

  reql_cur_unlock(cur);
}

extern void
reql_cur_destroy(ReQL_Cur_t *cur) {
  if (cur == nullptr) {
    return;
  }
  reql_cur_lock(cur);
  reql_cur_close_(cur);
  cur->response = nullptr;
  reql_cur_unlock(cur);
  if (cur->condition.thread != nullptr) {
    auto t = reinterpret_cast<std::thread *>(cur->condition.thread);
    cur->condition.thread = nullptr;
    t->join();
    delete t;
  }
}

class ReQL_Cur_Holder {
public:
  ReQL_Cur_Holder(void *a_data) : data(a_data) {}
  auto get() {
    return p_done.get_future().get();
  }
  void set(void *val) {
    return p_done.set_value(val);
  }
  void wait() {
    return p_done.get_future().wait();
  }

  void *data;

private:
  std::promise<void *> p_done;
};

class ReQL_Cur_Next_Data_Holder: public ReQL_Cur_Holder {
public:
  ReQL_Cur_Next_Data_Holder(void *a_data) : ReQL_Cur_Holder(a_data) {}
};

static int
reql_cur_next_cb(void *arg, void *a_res) {
  auto p_data = reinterpret_cast<ReQL_Cur_Next_Data_Holder *>(arg);
  auto cur = reinterpret_cast<ReQL_Cur_t*>(p_data->data);
  cur->cb.each = nullptr;
  p_data->set(a_res);
  return 0;
}

static void
reql_cur_each_(ReQL_Cur_t *cur, ReQL_Each_Function cb, void *arg) {
  cur->cb.each = cb;
  cur->cb.data[EACH] = arg;
}

static void *
reql_cur_next_(ReQL_Cur_t *cur) {
  if (reql_cur_open_(cur) == 0) {
    return nullptr;
  }
  auto each = std::move(cur->cb.each);
  auto cb_data = std::move(cur->cb.data[EACH]);
  ReQL_Cur_Next_Data_Holder data(cur);
  reql_cur_each_(cur, reql_cur_next_cb, &data);
  data.wait();
  std::swap(cur->cb.each, each);
  std::swap(cur->cb.data[EACH], cb_data);
  return data.get();
}

extern void *
reql_cur_next(ReQL_Cur_t *cur) {
  reql_cur_lock(cur);
  void *res = reql_cur_next_(cur);
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
reql_cur_drain_blank_cb(void *, void *) {
  return 0;
}

class ReQL_Cur_Drain_Data_Holder: public ReQL_Cur_Holder {
public:
  ReQL_Cur_Drain_Data_Holder(void *data, ReQL_End_Function end) : ReQL_Cur_Holder(data), p_end(end) {}
  auto end() {
    return p_end;
  }
private:
  ReQL_End_Function p_end;
};

static void
reql_cur_drain_end_cb(void *arg) {
  auto p_data = reinterpret_cast<ReQL_Cur_Drain_Data_Holder *>(arg);
  auto end = p_data->end();
  if (end != nullptr) {
    end(p_data->data);
  }
  p_data->set(nullptr);
}

static void
reql_cur_drain_(ReQL_Cur_t *cur) {
  if (cur->cb.each == nullptr) {
    reql_cur_each_(cur, reql_cur_drain_blank_cb, nullptr);
  }
  ReQL_Cur_Drain_Data_Holder data(cur->cb.data[END], cur->cb.end);
  reql_cur_set_end_cb_(cur, reql_cur_drain_end_cb, &data);
  data.wait();
  cur->cb.end = nullptr;
}

extern void
reql_cur_drain(ReQL_Cur_t *cur) {
  reql_cur_lock(cur);
  reql_cur_drain_(cur);
  reql_cur_unlock(cur);
}
