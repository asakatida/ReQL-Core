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

ReQL::ReQL() : p_query(new ReQL_Obj_t) {}

ReQL::ReQL(ReQL &&other) { move(std::move(other)); }

ReQL_Obj_t *
ReQL::data() const {
  return p_query.get();
}

ReQL_Datum_t
ReQL::type() const {
  return reql_datum_type(data());
}

ReQL &
ReQL::operator=(ReQL &&other) { return move(std::move(other)); }

bool
ReQL::operator<(const ReQL &other) const {
  ReQL_Datum_t ltype = reql_datum_type(data()), rtype = reql_datum_type(other.data());
  if (ltype == rtype) {
    switch (ltype) {
      case REQL_R_ARRAY:
      case REQL_R_BOOL:
      case REQL_R_JSON:
      case REQL_R_NULL:
      case REQL_R_NUM:
      case REQL_R_OBJECT:
      case REQL_R_REQL: {
        return data() < other.data();
      }
      case REQL_R_STR: {
        std::string same((char *)reql_string_buf(data()), reql_size(data()));
        std::string diff((char *)reql_string_buf(other.data()), reql_size(other.data()));
        return same < diff;
      }
    }
  }
  return ltype < rtype;
}

ReQL &
ReQL::move(ReQL &&other) {
  if (&other != this) {
    p_query = std::move(other.p_query);
  }

  return *this;
}

ReQL_Datum::ReQL_Datum() : ReQL() {
  reql_null_init(data());
}

ReQL_Datum::ReQL_Datum(double val) : ReQL() {
  reql_number_init(data(), val);
}

ReQL_Datum::ReQL_Datum(bool val) : ReQL() {
  reql_bool_init(data(), val);
}

ReQL_Array::ReQL_Array(std::uint32_t size) : ReQL(), p_array(new ReQL_Obj_t*[size]) {
  reql_array_init(data(), p_array.get(), static_cast<std::uint32_t>(size));
}

void
ReQL_Array::add_elem(const ReQL &elem) {
  reql_array_append(data(), elem.data());
}

ReQL_Array &
ReQL_Array::move(ReQL_Array &&other) {
  ReQL::move(std::move(other));
  if (&other != this) {
    p_array = std::move(other.p_array);
  }
  return *this;
}

ReQL_Object::ReQL_Object(std::uint32_t size) : ReQL(), p_object(new ReQL_Pair_t[size]) {
  reql_object_init(data(), p_object.get(), static_cast<std::uint32_t>(size));
}

void
ReQL_Object::add_key(const ReQL &key, const ReQL &value) {
  reql_object_add(data(), key.data(), value.data());
}

ReQL_Object &
ReQL_Object::move(ReQL_Object &&other) {
  ReQL::move(std::move(other));
  if (&other != this) {
    p_object = std::move(other.p_object);
  }
  return *this;
}

ReQL_String::ReQL_String(std::string val) : ReQL(), p_buf(new uint8_t[val.size()]) {
  std::uint32_t size = static_cast<std::uint32_t>(val.size());
  std::uint8_t *buf = (std::uint8_t*)val.c_str();

  reql_string_init(data(), p_buf.get(), size);
  reql_string_append(data(), buf, size);
}

ReQL_String &
ReQL_String::move(ReQL_String &&other) {
  ReQL::move(std::move(other));
  if (&other != this) {
    p_buf = std::move(other.p_buf);
  }
  return *this;
}

ReQL_Term::ReQL_Term(std::uint32_t args_size, std::uint32_t kwargs_size) : ReQL() {
  if (args_size > 0) {
    p_args.reset(new ReQL_Obj_t);
    p_array.reset(new ReQL_Obj_t*[args_size]);
    reql_array_init(p_args.get(), p_array.get(), args_size);
  }
  if (kwargs_size > 0) {
    p_kwargs.reset(new ReQL_Obj_t);
    p_object.reset(new ReQL_Pair_t[kwargs_size]);
    reql_object_init(p_kwargs.get(), p_object.get(), kwargs_size);
  }
}

void
ReQL_Term::add_arg(const ReQL &elem) {
  reql_array_append(p_args.get(), elem.data());
}

void
ReQL_Term::add_kwarg(const ReQL &key, const ReQL &value) {
  reql_object_add(p_kwargs.get(), key.data(), value.data());
}

void
ReQL_Term::finalize(ReQL_AST_Function f) {
  f(data(), p_args.get(), p_kwargs.get());
}
  
ReQL_Term &
ReQL_Term::move(ReQL_Term &&other) {
  ReQL::move(std::move(other));
  if (&other != this) {
    p_args = std::move(other.p_args);
    p_array = std::move(other.p_array);
    p_kwargs = std::move(other.p_kwargs);
    p_object = std::move(other.p_object);
  }
  return *this;
}

}
