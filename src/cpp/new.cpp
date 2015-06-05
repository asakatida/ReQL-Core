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

#include "./cpp/new.hpp"

#include "./cpp/error.hpp"
#include "./cpp/query.hpp"

#include <algorithm>

namespace ReQL {

namespace _Internal {

ReQL::ReQL(int) : _C::CTypes::object(new _C::ReQL_Obj_t), p_tt(_C::REQL_DATUM) {}

ReQL::ReQL() : ReQL(int(0)) {
  reql_null_init(get());
}

ReQL::ReQL(const double &val) : ReQL(int(0)) {
  reql_number_init(get(), val);
}

ReQL::ReQL(const bool &val) : ReQL(int(0)) {
  reql_bool_init(get(), val);
}

ReQL::ReQL(const Types::string &val) : ReQL(int(0)) {
  if (val.size() > std::numeric_limits<_C::ReQL_Size>::max()) {
    throw ReQLDriverError();
  }

  p_str = val;
  const _C::ReQL_Size size = static_cast<_C::ReQL_Size>(p_str.size());
  _C::ReQL_Byte *buf = reinterpret_cast<_C::ReQL_Byte*>(const_cast<char*>(p_str.c_str()));

  if (size > 0) {
    p_buf.reset(new _C::ReQL_Byte[size]);
  }

  reql_string_init(get(), p_buf.get(), size);
  reql_string_append(get(), buf, size);
}

ReQL::ReQL(const Types::array &array) : ReQL(int(0)) {
  if (array.size() > std::numeric_limits<_C::ReQL_Size>::max()) {
    throw ReQLDriverError();
  }

  const _C::ReQL_Size size = static_cast<_C::ReQL_Size>(array.size());

  if (size > 0) {
    p_array.reset(new _C::ReQL_Obj_t*[size]);
  }

  reql_array_init(get(), p_array.get(), size);
}

ReQL::ReQL(const Types::object &object) : ReQL(int(0)) {
  if (object.size() > std::numeric_limits<_C::ReQL_Size>::max()) {
    throw ReQLDriverError();
  }

  const _C::ReQL_Size size = static_cast<_C::ReQL_Size>(object.size());

  if (size > 0) {
    p_object.reset(new _C::ReQL_Pair_t[size]);
  }

  reql_object_init(get(), p_object.get(), static_cast<_C::ReQL_Size>(size));
}

ReQL::ReQL(_C::ReQL_Obj_t *val) : _C::CTypes::object(val), p_tt(_C::reql_term_type(val)) {}

ReQL::ReQL(const _C::ReQL_AST_Function &f, const Types::array &args) : _C::CTypes::object(new _C::ReQL_Obj_t), p_args(new ReQL(args)) {
}

ReQL::ReQL(const _C::ReQL_AST_Function_Kwargs &f, const Types::array &args, const Types::object &kwargs) : _C::CTypes::object(new _C::ReQL_Obj_t), p_args(new ReQL(args)), p_kwargs(new ReQL(kwargs)) {
  f(get(), p_args.get()->get(), p_kwargs.get()->get());

  p_tt = _C::reql_term_type(get());
}

ReQL::ReQL(const ReQL &other) : ReQL(_C::reql_obj_copy(other.get())) {}

ReQL::ReQL(ReQL &&other) : _C::CTypes::object(std::move(other)), p_tt(std::move(other.p_tt)), p_r_array(std::move(other.p_r_array)), p_r_object(std::move(other.p_r_object)), p_str(std::move(other.p_str)), p_args(std::move(other.p_args)), p_array(std::move(other.p_array)), p_buf(std::move(other.p_buf)), p_kwargs(std::move(other.p_kwargs)), p_object(std::move(other.p_object)) {}

ReQL::~ReQL() {
  for (auto it=p_r_array.begin(); it!=p_r_array.end(); ++it) {
    it->removeOwner();
  }
  for (auto it=p_r_object.begin(); it!=p_r_object.end(); ++it) {
    it->second.removeOwner();
  }
  if (p_args.get() != nullptr) {
    p_args.get()->removeOwner();
  }
  if (p_kwargs.get() != nullptr) {
    p_kwargs.get()->removeOwner();
  }

  if (get() == nullptr) {
    return;
  }

  _C::ReQL_Obj_t *owner = get()->owner;
  get()->owner = nullptr;

  if (owner != nullptr) {
    switch (reql_datum_type(owner)) {
      case _C::REQL_R_ARRAY: {
        const _C::ReQL_Size size = reql_size(owner);
        _C::ReQL_Obj_t **array = owner->obj.datum.json.var.data.array;

        _C::ReQL_Size i;

        for (i=0; i < size; ++i) {
          if (array[i] == get()) {
            reql_array_insert(owner, nullptr, i);
            break;
          }
        }

        break;
      }
      case _C::REQL_R_OBJECT: {
        const _C::ReQL_Size size = reql_size(owner);
        _C::ReQL_Pair_t *pair = owner->obj.datum.json.var.data.pair;

        _C::ReQL_Size i;

        for (i=0; i < size; ++i) {
          if (pair[i].val == get()) {
            pair[i].val = nullptr;
            break;
          } else if (pair[i].key == get()) {
            pair[i].key = nullptr;
            break;
          }
        }

        break;
      }
      case _C::REQL_R_REQL: {
        if (_C::reql_term_args(owner) == get()) {
          owner->obj.args.args = nullptr;
        } else if (_C::reql_term_kwargs(owner) == get()) {
          owner->obj.args.kwargs = nullptr;
        }
        break;
      }
      case _C::REQL_R_BOOL:
      case _C::REQL_R_JSON:
      case _C::REQL_R_NULL:
      case _C::REQL_R_NUM:
      case _C::REQL_R_STR: break;
    }
  }
}

void
ReQL::removeOwner() {
  if (get() != nullptr) {
    get()->owner = nullptr;
  }
}

_C::ReQL_Datum_t
ReQL::_type() const {
  return reql_datum_type(get());
}

bool
ReQL::operator<(const ReQL &other) const {
  _C::ReQL_Datum_t ltype = _type(), rtype = other._type();
  if (ltype == rtype) {
    switch (ltype) {
      case _C::REQL_R_ARRAY:
      case _C::REQL_R_BOOL:
      case _C::REQL_R_JSON:
      case _C::REQL_R_NULL:
      case _C::REQL_R_NUM:
      case _C::REQL_R_OBJECT:
      case _C::REQL_R_REQL: return get() < other.get();
      case _C::REQL_R_STR: {
        return p_str < other.p_str;
      }
    }
  }
  return ltype < rtype;
}

ReQL &
ReQL::operator=(const ReQL &other) {
  if (&other != this) {
    operator=(std::move(ReQL(_C::reql_obj_copy(other.get()))));
  }
  return *this;
}

ReQL &
ReQL::operator=(ReQL &&other) {
  if (&other != this) {
    _C::CTypes::object::operator=(std::move(other));
    p_tt = std::move(other.p_tt);
    p_r_array = std::move(other.p_r_array);
    p_r_object = std::move(other.p_r_object);
    p_str = std::move(other.p_str);
    p_args = std::move(other.p_args);
    p_array = std::move(other.p_array);
    p_buf = std::move(other.p_buf);
    p_kwargs = std::move(other.p_kwargs);
    p_object = std::move(other.p_object);
  }
  return *this;
}

}  // namespace _Internal

}  // namespace ReQL
