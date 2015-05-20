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

namespace _C {

extern "C" {

#include "./c/dev/json.h"

}

}  // namespace _C

namespace _Internal {

ReQL::ReQL() : _C::CTypes::object(new _C::ReQL_Obj_t), p_tt(_C::REQL_DATUM), p_args(nullptr), p_array(nullptr), p_buf(nullptr), p_kwargs(nullptr), p_object(nullptr) {
  reql_null_init(get());
}

ReQL::ReQL(const double &val) : ReQL() {
  reql_number_init(get(), val);
}

ReQL::ReQL(const bool &val) : ReQL() {
  reql_bool_init(get(), val);
}

ReQL::ReQL(const Types::string &val) : ReQL() {
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

ReQL::ReQL(const Types::array &array) : ReQL() {
  if (array.size() > std::numeric_limits<_C::ReQL_Size>::max()) {
    throw ReQLDriverError();
  }

  const _C::ReQL_Size size = static_cast<_C::ReQL_Size>(array.size());

  if (size > 0) {
    p_array.reset(new _C::ReQL_Obj_t*[size]);
  }

  reql_array_init(get(), p_array.get(), size);
  for (auto it=array.cbegin(); it != array.cend(); ++it) {
    p_r_array.push_back(it->_internal());
    reql_array_append(get(), it->_data());
  }
}

ReQL::ReQL(const Types::object &object) : ReQL() {
  if (object.size() > std::numeric_limits<_C::ReQL_Size>::max()) {
    throw ReQLDriverError();
  }

  const _C::ReQL_Size size = static_cast<_C::ReQL_Size>(object.size());

  if (size > 0) {
    p_object.reset(new _C::ReQL_Pair_t[size]);
  }

  reql_object_init(get(), p_object.get(), static_cast<_C::ReQL_Size>(size));
  for (auto it=object.cbegin(); it != object.cend(); ++it) {
    ReQL key = ReQL(it->first);
    p_r_object.insert({key, it->second._internal()});
    reql_object_add(get(), key.get(), it->second._data());
  }
}

ReQL::ReQL(_C::ReQL_Obj_t *val) : ReQL() {
  reset(val);
  switch (_C::reql_datum_type(val)) {
    case _C::REQL_R_ARRAY: {
      p_array.reset(val->obj.datum.json.var.data.array);
      p_r_array.reserve(_C::reql_size(val));

      _C::ReQL_Iter_t it = _C::reql_new_iter(val);
      _C::ReQL_Obj_t *elem = nullptr;

      while ((elem = _C::reql_iter_next(&it)) != nullptr) {
        p_r_array.push_back(ReQL(elem));
      }

      break;
    }
    case _C::REQL_R_BOOL: {
      break;
    }
    case _C::REQL_R_JSON: {
      break;
    }
    case _C::REQL_R_NULL: {
      break;
    }
    case _C::REQL_R_NUM: {
      break;
    }
    case _C::REQL_R_OBJECT: {
      p_object.reset(val->obj.datum.json.var.data.pair);

      _C::ReQL_Iter_t it = _C::reql_new_iter(val);
      _C::ReQL_Obj_t *key = nullptr;

      while ((key = _C::reql_iter_next(&it)) != nullptr) {
        p_r_object.insert({ReQL(key), ReQL(_C::reql_object_get(val, key))});
      }
      
      break;
    }
    case _C::REQL_R_REQL: {
      break;
    }
    case _C::REQL_R_STR: {
      break;
    }
  }
}

ReQL::ReQL(const _C::ReQL_AST_Function &f, const Types::array &args) : ReQL() {
  if (args.size() > std::numeric_limits<_C::ReQL_Size>::max()) {
    throw ReQLDriverError();
  }

  const _C::ReQL_Size args_size = static_cast<_C::ReQL_Size>(args.size());

  if (args_size > 0) {
    p_array.reset(new _C::ReQL_Obj_t*[args_size]);
  }

  p_args.reset(new _C::ReQL_Obj_t);
  reql_array_init(p_args.get(), p_array.get(), args_size);
  for (auto it=args.cbegin(); it != args.cend(); ++it) {
    p_r_array.push_back(it->_internal());
    reql_array_append(p_args.get(), it->_data());
  }

  f(get(), p_args.get());
}

ReQL::ReQL(const _C::ReQL_AST_Function_Kwargs &f, const Types::array &args, const Types::object &kwargs) : ReQL() {
  if (args.size() > std::numeric_limits<_C::ReQL_Size>::max()) {
    throw ReQLDriverError();
  }

  if (kwargs.size() > std::numeric_limits<_C::ReQL_Size>::max()) {
    throw ReQLDriverError();
  }

  const _C::ReQL_Size args_size = static_cast<_C::ReQL_Size>(args.size());

  if (args_size > 0) {
    p_array.reset(new _C::ReQL_Obj_t*[args_size]);
  }

  p_args.reset(new _C::ReQL_Obj_t);
  reql_array_init(p_args.get(), p_array.get(), args_size);
  for (auto it=args.cbegin(); it != args.cend(); ++it) {
    p_r_array.push_back(it->_internal());
    reql_array_append(p_args.get(), it->_data());
  }

  const _C::ReQL_Size kwargs_size = static_cast<_C::ReQL_Size>(kwargs.size());

  if (kwargs_size > 0) {
    p_object.reset(new _C::ReQL_Pair_t[kwargs_size]);
  }

  p_kwargs.reset(new _C::ReQL_Obj_t);
  reql_object_init(p_kwargs.get(), p_object.get(), kwargs_size);
  for (auto it=kwargs.cbegin(); it != kwargs.cend(); ++it) {
    ReQL key(it->first);
    p_r_object.insert({key, it->second._internal()});
    reql_object_add(p_kwargs.get(), key.get(), it->second._data());
  }

  f(get(), p_args.get(), p_kwargs.get());
}

ReQL::ReQL(const ReQL &other) : ReQL() {
  copy(other);
}

ReQL::ReQL(ReQL &&other) : ReQL() {
  move(std::move(other));
}

ReQL::~ReQL() {
  for (auto it=p_r_array.begin(); it!=p_r_array.end(); ++it) {
    it->get()->owner = nullptr;
  }
  for (auto it=p_r_object.begin(); it!=p_r_object.end(); ++it) {
    it->first.get()->owner = nullptr;
    it->second.get()->owner = nullptr;
  }
  if (p_args.get() != nullptr) {
    p_args->owner = nullptr;
  }
  if (p_kwargs.get() != nullptr) {
    p_kwargs->owner = nullptr;
  }

  _C::ReQL_Obj_t *owner = get()->owner;

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
            pair[i].val->owner = nullptr;
            pair[i].val = nullptr;
            pair[i].key = nullptr;
            break;
          }
        }

        break;
      }
      case _C::REQL_R_REQL: {
        if (_C::reql_args(owner) == get()) {
          owner->obj.args.args = nullptr;
        } else if (_C::reql_kwargs(owner) == get()) {
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

  get()->owner = nullptr;

  p_tt = _C::REQL_DATUM;
  p_r_array.clear();
  p_r_object.clear();
  p_str.clear();
  p_args.reset();
  p_array.reset();
  p_buf.reset();
  p_kwargs.reset();
  p_object.reset();
  reset();
}

void
ReQL::copy(const ReQL &other) {
  p_tt = other.p_tt;
  p_r_array = other.p_r_array;
  p_r_object = other.p_r_object;
  p_str = other.p_str;
  p_args.reset();
  p_array.reset();
  p_buf.reset();
  p_kwargs.reset();
  p_object.reset();
  switch (other._type()) {
    case _C::REQL_R_ARRAY: {
      std::size_t size = p_r_array.size();
      if (size > 0) {
        p_array.reset(new _C::ReQL_Obj_t*[size]);
      }
      reql_array_init(get(), p_array.get(), static_cast<_C::ReQL_Size>(size));
      for (auto it=p_r_array.cbegin(); it != p_r_array.cend(); ++it) {
        reql_array_append(get(), it->get());
      }
      break;
    }
    case _C::REQL_R_BOOL: {
      reql_bool_init(get(), reql_to_bool(other.get()));
      break;
    }
    case _C::REQL_R_JSON: throw ReQLDriverError();
    case _C::REQL_R_NULL: break;
    case _C::REQL_R_NUM: {
      reql_number_init(get(), reql_to_number(other.get()));
      break;
    }
    case _C::REQL_R_OBJECT: {
      std::size_t size = p_r_object.size();
      if (size > 0) {
        p_object.reset(new _C::ReQL_Pair_t[size]);
      }
      reql_object_init(get(), p_object.get(), static_cast<_C::ReQL_Size>(size));
      for (auto it=p_r_object.cbegin(); it != p_r_object.cend(); ++it) {
        if (it->first._type() != _C::REQL_R_STR) throw ReQLDriverError();
        reql_object_add(get(), it->first.get(), it->second.get());
      }
      break;
    }
    case _C::REQL_R_REQL: {
      std::size_t args_size = p_r_array.size();
      if (args_size > 0) {
        p_args.reset(new _C::ReQL_Obj_t);
        p_array.reset(new _C::ReQL_Obj_t*[args_size]);
        reql_array_init(p_args.get(), p_array.get(), static_cast<_C::ReQL_Size>(args_size));
        for (auto it=p_r_array.cbegin(); it != p_r_array.cend(); ++it) {
          reql_array_append(p_args.get(), it->get());
        }
      }
      std::size_t kwargs_size = p_r_object.size();
      if (kwargs_size > 0) {
        p_kwargs.reset(new _C::ReQL_Obj_t);
        p_object.reset(new _C::ReQL_Pair_t[kwargs_size]);
        reql_object_init(p_kwargs.get(), p_object.get(), static_cast<_C::ReQL_Size>(kwargs_size));
        for (auto it=p_r_object.cbegin(); it != p_r_object.cend(); ++it) {
          if (it->first._type() != _C::REQL_R_STR) throw ReQLDriverError();
          reql_object_add(p_kwargs.get(), it->first.get(), it->second.get());
        }
      }
      _C::reql_term_init(get(), p_tt, p_args.get(), p_kwargs.get());
      break;
    }
    case _C::REQL_R_STR: {
      _C::ReQL_Size size = static_cast<_C::ReQL_Size>(p_str.size());
      _C::ReQL_Byte *buf = reinterpret_cast<_C::ReQL_Byte*>(const_cast<char*>(p_str.c_str()));
      if (size > 0) {
        p_buf.reset(new _C::ReQL_Byte[size]);
      }
      reql_string_init(get(), p_buf.get(), size);
      reql_string_append(get(), buf, size);
      break;
    }
  }
}

void
ReQL::move(ReQL &&other) {
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
        _C::ReQL_Obj_t *val = get();
        _C::ReQL_Obj_t *o_val = other.get();
        Types::string same(reinterpret_cast<char*>(reql_string_buf(val)), reql_size(val));
        Types::string diff(reinterpret_cast<char*>(reql_string_buf(o_val)), reql_size(o_val));
        return same < diff;
      }
    }
  }
  return ltype < rtype;
}

ReQL &
ReQL::operator=(const ReQL &other) {
  if (&other != this) {
    copy(other);
  }
  return *this;
}

ReQL &
ReQL::operator=(ReQL &&other) {
  if (&other != this) {
    move(std::move(other));
  }
  return *this;
}

}  // namespace _Internal

}  // namespace ReQL
