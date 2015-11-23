/*
Copyright 2014-2015 Adam Grandquist

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

#include "./cpp/cursor.hpp"

#include "./cpp/error.hpp"
#include "./cpp/query.hpp"

#include <array>
#include <mutex>
#include <queue>

namespace ReQL {

Cursor::Cursor() {}

Cursor::Cursor(std::function<void()> func) {}

Cursor::Cursor(Cursor &&other) {
  std::lock_guard<std::mutex> lock(*p_mutex);
  std::lock_guard<std::mutex> other_lock(*(other.p_mutex));
  p_func = std::move(other.p_func);
  p_mutex = std::move(other.p_mutex);
  p_queue = std::move(other.p_queue);
}

Cursor &
Cursor::operator=(Cursor &&other) {
  if (this != &other) {
    std::lock(*p_mutex, *(other.p_mutex));
    std::lock_guard<std::mutex> lock(*p_mutex, std::adopt_lock);
    std::lock_guard<std::mutex> other_lock(*(other.p_mutex), std::adopt_lock);
    p_func = std::move(other.p_func);
    p_mutex = std::move(other.p_mutex);
    p_queue = std::move(other.p_queue);
  }
  return *this;
}

Cursor &
Cursor::begin() noexcept {
  return *this;
}

Cursor &
Cursor::cbegin() noexcept {
  return *this;
}

const Cursor &
Cursor::end() const {
  return *p_end;
}

const Cursor &
Cursor::cend() const {
  return *p_end;
}

void
Cursor::swap(Cursor &other) {
  std::swap(p_func, other.p_func);
  std::swap(p_mutex, other.p_mutex);
  std::swap(p_queue, other.p_queue);
}

Cursor &
Cursor::operator >>(Result &result) {
  std::lock_guard<std::mutex> lock(*p_mutex);
  if (p_queue->empty()) {
    p_cond->wait()
    p_mutex->unlock();
    std::this_thread::yield();
    p_mutex->lock();
  }
  result = p_queue->back();
  p_queue->pop();
  return *this;
}

void swap(Cursor &c1, Cursor &c2) {
  c1.swap(c2);
}

}  // namespace ReQL
