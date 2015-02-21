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

#include <map>
#include <string>
#include <vector>

namespace ReQL {
extern "C" {
#include "ReQL.h"
}
}

#ifndef REQL_NEW_HPP
#define REQL_NEW_HPP

namespace ReQL {

class ReQL {
public:
  ReQL();
  ReQL(ReQL &&other);

  ReQL_Obj_t *data() const;

  ReQL &operator=(ReQL &&other);

  bool operator<(const ReQL &other) const;

  virtual ReQL &move(ReQL &&other);

private:
  std::unique_ptr<ReQL_Obj_t> p_query;
};

class ReQL_Datum : public ReQL {
public:
  ReQL_Datum();
  ReQL_Datum(double val);
  ReQL_Datum(bool val);

  ReQL_Datum(ReQL_Datum &&other);

  ReQL_Datum &operator=(ReQL_Datum &&other);
};

class ReQL_Array : public ReQL {
public:
  ReQL_Array(std::uint32_t size);

  ReQL_Array(ReQL_Array &&other);

  ReQL_Array &operator=(ReQL_Array &&other);

  ReQL_Array &move(ReQL_Array &&other);

  void add_elem(const ReQL &elem);

private:
  std::unique_ptr<ReQL_Obj_t*> p_array;
};

class ReQL_Object : public ReQL {
public:
  ReQL_Object(std::uint32_t size);

  ReQL_Object(ReQL_Object &&other);

  ReQL_Object &operator=(ReQL_Object &&other);

  ReQL_Object &move(ReQL_Object &&other);

  void add_key(const ReQL &key, const ReQL &value);

private:
  std::unique_ptr<ReQL_Pair_t> p_object;
};

class ReQL_String : public ReQL {
public:
  ReQL_String(std::string val);

  ReQL_String(ReQL_String &&other);

  ReQL_String &operator=(ReQL_String &&other);

  ReQL_String &move(ReQL_String &&other);

private:
  std::unique_ptr<uint8_t> p_buf;
};

class ReQL_Term : public ReQL {
public:
  ReQL_Term(std::uint32_t args_size, std::uint32_t kwargs_size);

  ReQL_Term(ReQL_Term &&other);

  ReQL_Term &operator=(ReQL_Term &&other);

  ReQL_Term &move(ReQL_Term &&other);

  void add_arg(const ReQL &arg);
  void add_kwarg(const ReQL &key, const ReQL &value);
  void finalize(ReQL_AST_Function f);

private:
  std::unique_ptr<ReQL_Obj_t> p_args;
  std::unique_ptr<ReQL_Obj_t*> p_array;
  std::unique_ptr<ReQL_Obj_t> p_kwargs;
  std::unique_ptr<ReQL_Pair_t> p_object;
};

}

#endif
