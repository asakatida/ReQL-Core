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

#include "ReQL-new.hpp"

namespace ReQL {

ReQL::ReQL() : p_func(nullptr), p_args(nullptr), p_array(nullptr), p_buf(nullptr), p_kwargs(nullptr), p_object(nullptr), p_query(new ReQL_Obj_t) {
  reql_null_init(data());
}

ReQL::ReQL(const double &val) : ReQL() {
  reql_number_init(data(), val);
}

ReQL::ReQL(const bool &val) : ReQL() {
  reql_bool_init(data(), val);
}

ReQL::ReQL(const std::string &val) : ReQL() {
  p_str = val;
  std::uint32_t size = static_cast<std::uint32_t>(p_str.size());
  std::uint8_t *buf = reinterpret_cast<std::uint8_t*>(const_cast<char*>(p_str.c_str()));
  if (size > 0) {
    p_buf.reset(new uint8_t[size]);
  }
  reql_string_init(data(), p_buf.get(), size);
  reql_string_append(data(), buf, size);
}

ReQL::ReQL(const std::vector<ReQL> &array) : ReQL() {
  p_r_array = array;
  std::size_t size = p_r_array.size();
  if (size > 0) {
    p_array.reset(new ReQL_Obj_t*[size]);
  }
  reql_array_init(data(), p_array.get(), static_cast<std::uint32_t>(size));
  for (auto it=p_r_array.cbegin(); it!=p_r_array.cend(); ++it) {
    reql_array_append(data(), it->data());
  }
}

ReQL::ReQL(const std::map<ReQL, ReQL> &object) : ReQL() {
  p_r_object = object;
  std::size_t size = p_r_object.size();
  if (size > 0) {
    p_object.reset(new ReQL_Pair_t[size]);
  }
  reql_object_init(data(), p_object.get(), static_cast<std::uint32_t>(size));
  for (auto it=p_r_object.cbegin(); it!=p_r_object.cend(); ++it) {
    if (it->first.type() != REQL_R_STR) throw;
    reql_object_add(data(), it->first.data(), it->second.data());
  }
}

ReQL::ReQL(const ReQL_AST_Function &f, const std::vector<ReQL> &args, const std::map<ReQL, ReQL> &kwargs) : ReQL() {
  p_func = f;
  p_r_array = args;
  std::size_t args_size = p_r_array.size();
  if (args_size > 0) {
    p_args.reset(new ReQL_Obj_t);
    p_array.reset(new ReQL_Obj_t*[args_size]);
    reql_array_init(p_args.get(), p_array.get(), static_cast<std::uint32_t>(args_size));
    for (auto it=p_r_array.cbegin(); it!=p_r_array.cend(); ++it) {
      reql_array_append(p_args.get(), it->data());
    }
  }
  p_r_object = kwargs;
  std::size_t kwargs_size = p_r_object.size();
  if (kwargs_size > 0) {
    p_kwargs.reset(new ReQL_Obj_t);
    p_object.reset(new ReQL_Pair_t[kwargs_size]);
    reql_object_init(p_kwargs.get(), p_object.get(), static_cast<std::uint32_t>(kwargs_size));
    for (auto it=p_r_object.cbegin(); it!=p_r_object.cend(); ++it) {
      if (it->first.type() != REQL_R_STR) throw;
      reql_object_add(p_kwargs.get(), it->first.data(), it->second.data());
    }
  }
  p_func(data(), p_args.get(), p_kwargs.get());
}

ReQL::ReQL(const ReQL &other) : ReQL() {
  copy(other);
}

void
ReQL::copy(const ReQL &other) {
  p_str = other.p_str;
  p_func = other.p_func;
  p_r_array = other.p_r_array;
  p_r_object = other.p_r_object;
  switch (other.type()) {
    case REQL_R_ARRAY: {
      std::size_t size = p_r_array.size();
      if (size > 0) {
        p_array.reset(new ReQL_Obj_t*[size]);
      }
      reql_array_init(data(), p_array.get(), static_cast<std::uint32_t>(size));
      for (auto it=p_r_array.cbegin(); it!=p_r_array.cend(); ++it) {
        reql_array_append(data(), it->data());
      }
      break;
    }
    case REQL_R_BOOL: {
      reql_bool_init(data(), reql_to_bool(other.data()));
      break;
    }
    case REQL_R_JSON: throw;
    case REQL_R_NULL: break;
    case REQL_R_NUM: {
      reql_number_init(data(), reql_to_number(other.data()));
      break;
    }
    case REQL_R_OBJECT: {
      std::size_t size = p_r_object.size();
      if (size > 0) {
        p_object.reset(new ReQL_Pair_t[size]);
      }
      reql_object_init(data(), p_object.get(), static_cast<std::uint32_t>(size));
      for (auto it=p_r_object.cbegin(); it!=p_r_object.cend(); ++it) {
        if (it->first.type() != REQL_R_STR) throw;
        reql_object_add(data(), it->first.data(), it->second.data());
      }
      break;
    }
    case REQL_R_REQL: {
      std::size_t args_size = p_r_array.size();
      if (args_size > 0) {
        p_args.reset(new ReQL_Obj_t);
        p_array.reset(new ReQL_Obj_t*[args_size]);
        reql_array_init(p_args.get(), p_array.get(), static_cast<std::uint32_t>(args_size));
        for (auto it=p_r_array.cbegin(); it!=p_r_array.cend(); ++it) {
          reql_array_append(p_args.get(), it->data());
        }
      }
      std::size_t kwargs_size = p_r_object.size();
      if (kwargs_size > 0) {
        p_kwargs.reset(new ReQL_Obj_t);
        p_object.reset(new ReQL_Pair_t[kwargs_size]);
        reql_object_init(p_kwargs.get(), p_object.get(), static_cast<std::uint32_t>(kwargs_size));
        for (auto it=p_r_object.cbegin(); it!=p_r_object.cend(); ++it) {
          if (it->first.type() != REQL_R_STR) throw;
          reql_object_add(p_kwargs.get(), it->first.data(), it->second.data());
        }
      }
      p_func(data(), p_args.get(), p_kwargs.get());
      break;
    }
    case REQL_R_STR: {
      std::uint32_t size = static_cast<std::uint32_t>(p_str.size());
      std::uint8_t *buf = reinterpret_cast<std::uint8_t*>(const_cast<char*>(p_str.c_str()));
      if (size > 0) {
        p_buf.reset(new uint8_t[size]);
      }
      reql_string_init(data(), p_buf.get(), size);
      reql_string_append(data(), buf, size);
      break;
    }
  }
}

ReQL_Obj_t *
ReQL::data() const {
  return p_query.get();
}

ReQL_Datum_t
ReQL::type() const {
  return reql_datum_type(data());
}

bool
ReQL::operator<(const ReQL &other) const {
  ReQL_Datum_t ltype = type(), rtype = other.type();
  if (ltype == rtype) {
    switch (ltype) {
      case REQL_R_ARRAY:
      case REQL_R_BOOL:
      case REQL_R_JSON:
      case REQL_R_NULL:
      case REQL_R_NUM:
      case REQL_R_OBJECT:
      case REQL_R_REQL: return data() < other.data();
      case REQL_R_STR: {
        ReQL_Obj_t *val = data();
        ReQL_Obj_t *o_val = other.data();
        std::string same(reinterpret_cast<char*>(reql_string_buf(val)), reql_size(val));
        std::string diff(reinterpret_cast<char*>(reql_string_buf(o_val)), reql_size(o_val));
        return same < diff;
      }
    }
  }
  return ltype < rtype;
}

ReQL &
ReQL::operator=(const ReQL &other) {
  if (&other != this) {
    p_args.reset(nullptr);
    p_array.reset(nullptr);
    p_buf.reset(nullptr);
    p_kwargs.reset(nullptr);
    p_object.reset(nullptr);
    copy(other);
  }
  return *this;
}

ReQL &
ReQL::operator=(ReQL &&other) {
  if (&other != this) {
    p_str = std::move(other.p_str);
    p_args = std::move(other.p_args);
    p_buf = std::move(other.p_buf);
    p_array = std::move(other.p_array);
    p_func = std::move(other.p_func);
    p_r_array = std::move(other.p_r_array);
    p_r_object = std::move(other.p_r_object);
    p_kwargs = std::move(other.p_kwargs);
    p_object = std::move(other.p_object);
    p_query = std::move(other.p_query);
  }
  return *this;
}

}
