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

#include "./cpp/query.hpp"

#include "./cpp/error.hpp"

#include <algorithm>

namespace ReQL {

_C::ReQL_Obj_t *
buildArray(const Query &query) {
  if (query.p_array.size() > std::numeric_limits<_C::ReQL_Size>::max()) {
    throw ReQLDriverError();
  }

  const _C::ReQL_Size size = static_cast<_C::ReQL_Size>(query.p_array.size());

  _C::ReQL_Obj_t *obj = new _C::ReQL_Obj_t;
  _C::ReQL_Obj_t **buf = nullptr;

  if (size > 0) {
    buf = new _C::ReQL_Obj_t*[size];
  }

  reql_array_init(obj, buf, size);
  for (auto it=query.p_array.cbegin(); it != query.p_array.cend(); ++it) {
    reql_array_append(obj, it->build());
  }
  return obj;
}

_C::ReQL_Obj_t *
buildBool(const Query &query) {
  _C::ReQL_Obj_t *obj = new _C::ReQL_Obj_t;
  reql_bool_init(obj, query.p_bool);
  return obj;
}

_C::ReQL_Obj_t *
buildNumber(const Query &query) {
  _C::ReQL_Obj_t *obj = new _C::ReQL_Obj_t;
  reql_number_init(obj, query.p_number);
  return obj;
}

_C::ReQL_Obj_t *
buildNull(const Query &query) {
  (void)query;
  _C::ReQL_Obj_t *obj = new _C::ReQL_Obj_t;
  reql_null_init(obj);
  return obj;
}

_C::ReQL_Obj_t *
buildObject(const Query &query) {
  if (query.p_object.size() > std::numeric_limits<_C::ReQL_Size>::max()) {
    throw ReQLDriverError();
  }

  const _C::ReQL_Size size = static_cast<_C::ReQL_Size>(query.p_object.size());

  _C::ReQL_Obj_t *obj = new _C::ReQL_Obj_t;
  _C::ReQL_Pair_t *buf = nullptr;

  if (size > 0) {
    buf = new _C::ReQL_Pair_t[size];
  }

  reql_object_init(obj, buf, size);
  for (auto it=query.p_object.cbegin(); it != query.p_object.cend(); ++it) {
    reql_object_add(obj, Query(it->first).build(), it->second.build());
  }
  return obj;
}

_C::ReQL_Obj_t *
buildString(const Query &query) {
  if (query.p_string.size() > std::numeric_limits<_C::ReQL_Size>::max()) {
    throw ReQLDriverError();
  }

  const _C::ReQL_Size size = static_cast<_C::ReQL_Size>(query.p_string.size());

  _C::ReQL_Obj_t *obj = new _C::ReQL_Obj_t;
  _C::ReQL_Byte *buf = nullptr;

  if (size > 0) {
    buf = new _C::ReQL_Byte[size];
  }

  reql_string_init(obj, buf, reinterpret_cast<_C::ReQL_Byte*>(const_cast<char*>(query.p_string.c_str())), size);
  return obj;
}

_C::ReQL_Obj_t *
buildTerm(const Query &query) {
  _C::ReQL_Obj_t *obj = new _C::ReQL_Obj_t;
  query.p_func(obj, buildArray(query));
  return obj;
}

_C::ReQL_Obj_t *
buildTermKwargs(const Query &query) {
  _C::ReQL_Obj_t *obj = new _C::ReQL_Obj_t;
  query.p_func_kwargs(obj, buildArray(query), buildObject(query));
  return obj;
}

static Query
init(const _C::ReQL_AST_Function &f, const Types::array &args) {
  return Query(f, args);
}

static Query
init(const _C::ReQL_AST_Function &f, const Query *term, const Types::array &args) {
  Types::array new_args;
  new_args.push_back(*term);
  new_args.insert(new_args.end(), args.cbegin(), args.cend());
  return init(f, new_args);
}

static Query
init(const _C::ReQL_AST_Function_Kwargs &f, const Types::array &args, const Types::object &kwargs) {
  return Query(f, args, kwargs);
}

static Query
init(const _C::ReQL_AST_Function_Kwargs &f, const Query *term, const Types::array &args, const Types::object &kwargs) {
  Types::array new_args;
  new_args.push_back(*term);
  new_args.insert(new_args.end(), args.cbegin(), args.cend());
  return init(f, new_args, kwargs);
}

static Query
init(const _C::ReQL_AST_Function_Kwargs &f, const Types::array &args) {
  return init(f, args, Types::object());
}

static Query
init(const _C::ReQL_AST_Function_Kwargs &f, const Query *term, const Types::array &args) {
  return init(f, term, args, Types::object());
}

Query::Query() : p_build(buildNull) {}

Query::Query(const _C::ReQL_AST_Function_Kwargs &f, const Types::array &args, const Types::object &kwargs) : p_array(args), p_build(buildTermKwargs), p_func_kwargs(f), p_object(kwargs) {}

Query::Query(const _C::ReQL_AST_Function &f, const Types::array &args) : p_array(args), p_build(buildTerm), p_func(f) {}

Query::Query(const Types::string &val) : p_build(buildString), p_string(val) {}

Query::Query(const double &val) : p_build(buildNumber), p_number(val) {}

Query::Query(const bool &val) : p_bool(val), p_build(buildBool) {}

Query::Query(const Types::array &val) : p_array(val), p_build(buildArray) {}

Query::Query(const Types::object &val) : p_build(buildObject), p_object(val) {}

Query::Query(_C::ReQL_Obj_t *val) {
  (void)val;
}

Query::Query(const Query &other) : p_array(other.p_array), p_bool(other.p_bool), p_build(other.p_build), p_func(other.p_func), p_func_kwargs(other.p_func_kwargs), p_number(other.p_number), p_object(other.p_object), p_string(other.p_string) {}

Query::Query(Query &&other) : p_array(std::move(other.p_array)), p_bool(std::move(other.p_bool)), p_build(std::move(other.p_build)), p_func(std::move(other.p_func)), p_func_kwargs(std::move(other.p_func_kwargs)), p_number(std::move(other.p_number)), p_object(std::move(other.p_object)), p_string(std::move(other.p_string)) {}

Cursor
Query::run(const Connection &conn) const {
  Cursor cur;

  reql_run(cur.get(), build(), conn.get(), nullptr);

  return cur;
}

Query &
Query::operator=(const Query &other) {
  if (this != &other) {
    p_array = other.p_array;
    p_bool = other.p_bool;
    p_build = other.p_build;
    p_func = other.p_func;
    p_func_kwargs = other.p_func_kwargs;
    p_number = other.p_number;
    p_object = other.p_object;
    p_string = other.p_string;
  }
  return *this;
}

Query &
Query::operator=(Query &&other) {
  if (this != &other) {
    p_array = std::move(other.p_array);
    p_bool = std::move(other.p_bool);
    p_build = std::move(other.p_build);
    p_func = std::move(other.p_func);
    p_func_kwargs = std::move(other.p_func_kwargs);
    p_number = std::move(other.p_number);
    p_object = std::move(other.p_object);
    p_string = std::move(other.p_string);
  }
  return *this;
}

_C::ReQL_Obj_t *
Query::build() const {
  return p_build(*this);
}

Query
Query::add(const Types::array &args) const {
  return init(_C::reql_ast_add, this, args);
}
Query
add(const Types::array &args) {
  return init(_C::reql_ast_add, args);
}

Query
Query::and_(const Types::array &args) const {
  return init(_C::reql_ast_and, this, args);
}
Query
and_(const Types::array &args) {
  return init(_C::reql_ast_and, args);
}

Query
Query::append(const Types::array &args) const {
  return init(_C::reql_ast_append, this, args);
}
Query
append(const Types::array &args) {
  return init(_C::reql_ast_append, args);
}

Query
Query::april(const Types::array &args) const {
  return init(_C::reql_ast_april, this, args);
}
Query
april(const Types::array &args) {
  return init(_C::reql_ast_april, args);
}

Query
Query::args(const Types::array &args) const {
  return init(_C::reql_ast_args, this, args);
}
Query
args(const Types::array &args) {
  return init(_C::reql_ast_args, args);
}

Query
Query::asc(const Types::array &args) const {
  return init(_C::reql_ast_asc, this, args);
}
Query
asc(const Types::array &args) {
  return init(_C::reql_ast_asc, args);
}

Query
Query::august(const Types::array &args) const {
  return init(_C::reql_ast_august, this, args);
}
Query
august(const Types::array &args) {
  return init(_C::reql_ast_august, args);
}

Query
Query::avg(const Types::array &args) const {
  return init(_C::reql_ast_avg, this, args);
}
Query
avg(const Types::array &args) {
  return init(_C::reql_ast_avg, args);
}

Query
Query::between(const Types::array &args) const {
  return init(_C::reql_ast_between, this, args);
}
Query
between(const Types::array &args) {
  return init(_C::reql_ast_between, args);
}

Query
Query::between_deprecated(const Types::array &args) const {
  return init(_C::reql_ast_between_deprecated, this, args);
}
Query
between_deprecated(const Types::array &args) {
  return init(_C::reql_ast_between_deprecated, args);
}

Query
Query::binary(const Types::array &args) const {
  return init(_C::reql_ast_binary, this, args);
}
Query
binary(const Types::array &args) {
  return init(_C::reql_ast_binary, args);
}

Query
Query::bracket(const Types::array &args) const {
  return init(_C::reql_ast_bracket, this, args);
}
Query
bracket(const Types::array &args) {
  return init(_C::reql_ast_bracket, args);
}

Query
Query::branch(const Types::array &args) const {
  return init(_C::reql_ast_branch, this, args);
}
Query
branch(const Types::array &args) {
  return init(_C::reql_ast_branch, args);
}

Query
Query::ceil(const Types::array &args) const {
  return init(_C::reql_ast_ceil, this, args);
}
Query
ceil(const Types::array &args) {
  return init(_C::reql_ast_ceil, args);
}

Query
Query::changes(const Types::array &args) const {
  return init(_C::reql_ast_changes, this, args);
}
Query
changes(const Types::array &args) {
  return init(_C::reql_ast_changes, args);
}

Query
Query::change_at(const Types::array &args) const {
  return init(_C::reql_ast_change_at, this, args);
}
Query
change_at(const Types::array &args) {
  return init(_C::reql_ast_change_at, args);
}

Query
Query::circle(const Types::array &args, const Types::object &kwargs) const {
  return init(_C::reql_ast_circle, this, args, kwargs);
}
Query
circle(const Types::array &args, const Types::object &kwargs) {
  return init(_C::reql_ast_circle, args, kwargs);
}
Query
Query::circle(const Types::array &args) const {
  return init(_C::reql_ast_circle, this, args);
}
Query
circle(const Types::array &args) {
  return init(_C::reql_ast_circle, args);
}

Query
Query::coerce_to(const Types::array &args) const {
  return init(_C::reql_ast_coerce_to, this, args);
}
Query
coerce_to(const Types::array &args) {
  return init(_C::reql_ast_coerce_to, args);
}

Query
Query::concat_map(const Types::array &args) const {
  return init(_C::reql_ast_concat_map, this, args);
}
Query
concat_map(const Types::array &args) {
  return init(_C::reql_ast_concat_map, args);
}

Query
Query::config(const Types::array &args) const {
  return init(_C::reql_ast_config, this, args);
}
Query
config(const Types::array &args) {
  return init(_C::reql_ast_config, args);
}

Query
Query::contains(const Types::array &args) const {
  return init(_C::reql_ast_contains, this, args);
}
Query
contains(const Types::array &args) {
  return init(_C::reql_ast_contains, args);
}

Query
Query::count(const Types::array &args) const {
  return init(_C::reql_ast_count, this, args);
}
Query
count(const Types::array &args) {
  return init(_C::reql_ast_count, args);
}

Query
Query::date(const Types::array &args) const {
  return init(_C::reql_ast_date, this, args);
}
Query
date(const Types::array &args) {
  return init(_C::reql_ast_date, args);
}

Query
Query::datum(const Types::array &args) const {
  return init(_C::reql_ast_datum, this, args);
}
Query
datum(const Types::array &args) {
  return init(_C::reql_ast_datum, args);
}

Query
Query::day(const Types::array &args) const {
  return init(_C::reql_ast_day, this, args);
}
Query
day(const Types::array &args) {
  return init(_C::reql_ast_day, args);
}

Query
Query::day_of_week(const Types::array &args) const {
  return init(_C::reql_ast_day_of_week, this, args);
}
Query
day_of_week(const Types::array &args) {
  return init(_C::reql_ast_day_of_week, args);
}

Query
Query::day_of_year(const Types::array &args) const {
  return init(_C::reql_ast_day_of_year, this, args);
}
Query
day_of_year(const Types::array &args) {
  return init(_C::reql_ast_day_of_year, args);
}

Query
Query::db(const Types::array &args) const {
  return init(_C::reql_ast_db, this, args);
}
Query
db(const Types::array &args) {
  return init(_C::reql_ast_db, args);
}

Query
Query::db_create(const Types::array &args) const {
  return init(_C::reql_ast_db_create, this, args);
}
Query
db_create(const Types::array &args) {
  return init(_C::reql_ast_db_create, args);
}

Query
Query::db_drop(const Types::array &args) const {
  return init(_C::reql_ast_db_drop, this, args);
}
Query
db_drop(const Types::array &args) {
  return init(_C::reql_ast_db_drop, args);
}

Query
Query::db_list(const Types::array &args) const {
  return init(_C::reql_ast_db_list, this, args);
}
Query
db_list(const Types::array &args) {
  return init(_C::reql_ast_db_list, args);
}

Query
Query::december(const Types::array &args) const {
  return init(_C::reql_ast_december, this, args);
}
Query
december(const Types::array &args) {
  return init(_C::reql_ast_december, args);
}

Query
Query::default_(const Types::array &args) const {
  return init(_C::reql_ast_default, this, args);
}
Query
default_(const Types::array &args) {
  return init(_C::reql_ast_default, args);
}

Query
Query::delete_(const Types::array &args, const Types::object &kwargs) const {
  return init(_C::reql_ast_delete, this, args, kwargs);
}
Query
delete_(const Types::array &args, const Types::object &kwargs) {
  return init(_C::reql_ast_delete, args, kwargs);
}
Query
Query::delete_(const Types::array &args) const {
  return init(_C::reql_ast_delete, this, args);
}
Query
delete_(const Types::array &args) {
  return init(_C::reql_ast_delete, args);
}

Query
Query::delete_at(const Types::array &args) const {
  return init(_C::reql_ast_delete_at, this, args);
}
Query
delete_at(const Types::array &args) {
  return init(_C::reql_ast_delete_at, args);
}

Query
Query::desc(const Types::array &args) const {
  return init(_C::reql_ast_desc, this, args);
}
Query
desc(const Types::array &args) {
  return init(_C::reql_ast_desc, args);
}

Query
Query::difference(const Types::array &args) const {
  return init(_C::reql_ast_difference, this, args);
}
Query
difference(const Types::array &args) {
  return init(_C::reql_ast_difference, args);
}

Query
Query::distance(const Types::array &args) const {
  return init(_C::reql_ast_distance, this, args);
}
Query
distance(const Types::array &args) {
  return init(_C::reql_ast_distance, args);
}

Query
Query::distinct(const Types::array &args, const Types::object &kwargs) const {
  return init(_C::reql_ast_distinct, this, args, kwargs);
}
Query
distinct(const Types::array &args, const Types::object &kwargs) {
  return init(_C::reql_ast_distinct, args, kwargs);
}
Query
Query::distinct(const Types::array &args) const {
  return init(_C::reql_ast_distinct, this, args);
}
Query
distinct(const Types::array &args) {
  return init(_C::reql_ast_distinct, args);
}

Query
Query::div(const Types::array &args) const {
  return init(_C::reql_ast_div, this, args);
}
Query
div(const Types::array &args) {
  return init(_C::reql_ast_div, args);
}

Query
Query::downcase(const Types::array &args) const {
  return init(_C::reql_ast_downcase, this, args);
}
Query
downcase(const Types::array &args) {
  return init(_C::reql_ast_downcase, args);
}

Query
Query::during(const Types::array &args) const {
  return init(_C::reql_ast_during, this, args);
}
Query
during(const Types::array &args) {
  return init(_C::reql_ast_during, args);
}

Query
Query::epoch_time(const Types::array &args) const {
  return init(_C::reql_ast_epoch_time, this, args);
}
Query
epoch_time(const Types::array &args) {
  return init(_C::reql_ast_epoch_time, args);
}

Query
Query::eq(const Types::array &args) const {
  return init(_C::reql_ast_eq, this, args);
}
Query
eq(const Types::array &args) {
  return init(_C::reql_ast_eq, args);
}

Query
Query::eq_join(const Types::array &args, const Types::object &kwargs) const {
  return init(_C::reql_ast_eq_join, this, args, kwargs);
}
Query
eq_join(const Types::array &args, const Types::object &kwargs) {
  return init(_C::reql_ast_eq_join, args, kwargs);
}
Query
Query::eq_join(const Types::array &args) const {
  return init(_C::reql_ast_eq_join, this, args);
}
Query
eq_join(const Types::array &args) {
  return init(_C::reql_ast_eq_join, args);
}

Query
Query::error(const Types::array &args) const {
  return init(_C::reql_ast_error, this, args);
}
Query
error(const Types::array &args) {
  return init(_C::reql_ast_error, args);
}

Query
Query::february(const Types::array &args) const {
  return init(_C::reql_ast_february, this, args);
}
Query
february(const Types::array &args) {
  return init(_C::reql_ast_february, args);
}

Query
Query::fill(const Types::array &args) const {
  return init(_C::reql_ast_fill, this, args);
}
Query
fill(const Types::array &args) {
  return init(_C::reql_ast_fill, args);
}

Query
Query::filter(const Types::array &args, const Types::object &kwargs) const {
  return init(_C::reql_ast_filter, this, args, kwargs);
}
Query
filter(const Types::array &args, const Types::object &kwargs) {
  return init(_C::reql_ast_filter, args, kwargs);
}
Query
Query::filter(const Types::array &args) const {
  return init(_C::reql_ast_filter, this, args);
}
Query
filter(const Types::array &args) {
  return init(_C::reql_ast_filter, args);
}

Query
Query::floor(const Types::array &args) const {
  return init(_C::reql_ast_floor, this, args);
}
Query
floor(const Types::array &args) {
  return init(_C::reql_ast_floor, args);
}

Query
Query::for_each(const Types::array &args) const {
  return init(_C::reql_ast_for_each, this, args);
}
Query
for_each(const Types::array &args) {
  return init(_C::reql_ast_for_each, args);
}

Query
Query::friday(const Types::array &args) const {
  return init(_C::reql_ast_friday, this, args);
}
Query
friday(const Types::array &args) {
  return init(_C::reql_ast_friday, args);
}

Query
Query::func(const Types::array &args) const {
  return init(_C::reql_ast_func, this, args);
}
Query
func(const Types::array &args) {
  return init(_C::reql_ast_func, args);
}

Query
Query::funcall(const Types::array &args) const {
  return init(_C::reql_ast_funcall, this, args);
}
Query
funcall(const Types::array &args) {
  return init(_C::reql_ast_funcall, args);
}

Query
Query::ge(const Types::array &args) const {
  return init(_C::reql_ast_ge, this, args);
}
Query
ge(const Types::array &args) {
  return init(_C::reql_ast_ge, args);
}

Query
Query::geojson(const Types::array &args) const {
  return init(_C::reql_ast_geojson, this, args);
}
Query
geojson(const Types::array &args) {
  return init(_C::reql_ast_geojson, args);
}

Query
Query::get(const Types::array &args) const {
  return init(_C::reql_ast_get, this, args);
}
Query
get(const Types::array &args) {
  return init(_C::reql_ast_get, args);
}

Query
Query::get_all(const Types::array &args, const Types::object &kwargs) const {
  return init(_C::reql_ast_get_all, this, args, kwargs);
}
Query
get_all(const Types::array &args, const Types::object &kwargs) {
  return init(_C::reql_ast_get_all, args, kwargs);
}
Query
Query::get_all(const Types::array &args) const {
  return init(_C::reql_ast_get_all, this, args);
}
Query
get_all(const Types::array &args) {
  return init(_C::reql_ast_get_all, args);
}

Query
Query::get_field(const Types::array &args) const {
  return init(_C::reql_ast_get_field, this, args);
}
Query
get_field(const Types::array &args) {
  return init(_C::reql_ast_get_field, args);
}

Query
Query::get_intersecting(const Types::array &args, const Types::object &kwargs) const {
  return init(_C::reql_ast_get_intersecting, this, args, kwargs);
}
Query
get_intersecting(const Types::array &args, const Types::object &kwargs) {
  return init(_C::reql_ast_get_intersecting, args, kwargs);
}
Query
Query::get_intersecting(const Types::array &args) const {
  return init(_C::reql_ast_get_intersecting, this, args);
}
Query
get_intersecting(const Types::array &args) {
  return init(_C::reql_ast_get_intersecting, args);
}

Query
Query::get_nearest(const Types::array &args, const Types::object &kwargs) const {
  return init(_C::reql_ast_get_nearest, this, args, kwargs);
}
Query
get_nearest(const Types::array &args, const Types::object &kwargs) {
  return init(_C::reql_ast_get_nearest, args, kwargs);
}
Query
Query::get_nearest(const Types::array &args) const {
  return init(_C::reql_ast_get_nearest, this, args);
}
Query
get_nearest(const Types::array &args) {
  return init(_C::reql_ast_get_nearest, args);
}

Query
Query::group(const Types::array &args, const Types::object &kwargs) const {
  return init(_C::reql_ast_group, this, args, kwargs);
}
Query
group(const Types::array &args, const Types::object &kwargs) {
  return init(_C::reql_ast_group, args, kwargs);
}
Query
Query::group(const Types::array &args) const {
  return init(_C::reql_ast_group, this, args);
}
Query
group(const Types::array &args) {
  return init(_C::reql_ast_group, args);
}

Query
Query::gt(const Types::array &args) const {
  return init(_C::reql_ast_gt, this, args);
}
Query
gt(const Types::array &args) {
  return init(_C::reql_ast_gt, args);
}

Query
Query::has_fields(const Types::array &args) const {
  return init(_C::reql_ast_has_fields, this, args);
}
Query
has_fields(const Types::array &args) {
  return init(_C::reql_ast_has_fields, args);
}

Query
Query::hours(const Types::array &args) const {
  return init(_C::reql_ast_hours, this, args);
}
Query
hours(const Types::array &args) {
  return init(_C::reql_ast_hours, args);
}

Query
Query::http(const Types::array &args, const Types::object &kwargs) const {
  return init(_C::reql_ast_http, this, args, kwargs);
}
Query
http(const Types::array &args, const Types::object &kwargs) {
  return init(_C::reql_ast_http, args, kwargs);
}
Query
Query::http(const Types::array &args) const {
  return init(_C::reql_ast_http, this, args);
}
Query
http(const Types::array &args) {
  return init(_C::reql_ast_http, args);
}

Query
Query::implicit_var(const Types::array &args) const {
  return init(_C::reql_ast_implicit_var, this, args);
}
Query
implicit_var(const Types::array &args) {
  return init(_C::reql_ast_implicit_var, args);
}

Query
Query::includes(const Types::array &args) const {
  return init(_C::reql_ast_includes, this, args);
}
Query
includes(const Types::array &args) {
  return init(_C::reql_ast_includes, args);
}

Query
Query::index_create(const Types::array &args, const Types::object &kwargs) const {
  return init(_C::reql_ast_index_create, this, args, kwargs);
}
Query
index_create(const Types::array &args, const Types::object &kwargs) {
  return init(_C::reql_ast_index_create, args, kwargs);
}
Query
Query::index_create(const Types::array &args) const {
  return init(_C::reql_ast_index_create, this, args);
}
Query
index_create(const Types::array &args) {
  return init(_C::reql_ast_index_create, args);
}

Query
Query::index_drop(const Types::array &args) const {
  return init(_C::reql_ast_index_drop, this, args);
}
Query
index_drop(const Types::array &args) {
  return init(_C::reql_ast_index_drop, args);
}

Query
Query::index_list(const Types::array &args) const {
  return init(_C::reql_ast_index_list, this, args);
}
Query
index_list(const Types::array &args) {
  return init(_C::reql_ast_index_list, args);
}

Query
Query::index_rename(const Types::array &args, const Types::object &kwargs) const {
  return init(_C::reql_ast_index_rename, this, args, kwargs);
}
Query
index_rename(const Types::array &args, const Types::object &kwargs) {
  return init(_C::reql_ast_index_rename, args, kwargs);
}
Query
Query::index_rename(const Types::array &args) const {
  return init(_C::reql_ast_index_rename, this, args);
}
Query
index_rename(const Types::array &args) {
  return init(_C::reql_ast_index_rename, args);
}

Query
Query::index_status(const Types::array &args) const {
  return init(_C::reql_ast_index_status, this, args);
}
Query
index_status(const Types::array &args) {
  return init(_C::reql_ast_index_status, args);
}

Query
Query::index_wait(const Types::array &args) const {
  return init(_C::reql_ast_index_wait, this, args);
}
Query
index_wait(const Types::array &args) {
  return init(_C::reql_ast_index_wait, args);
}

Query
Query::info(const Types::array &args) const {
  return init(_C::reql_ast_info, this, args);
}
Query
info(const Types::array &args) {
  return init(_C::reql_ast_info, args);
}

Query
Query::inner_join(const Types::array &args) const {
  return init(_C::reql_ast_inner_join, this, args);
}
Query
inner_join(const Types::array &args) {
  return init(_C::reql_ast_inner_join, args);
}

Query
Query::insert(const Types::array &args) const {
  return init(_C::reql_ast_insert, this, args);
}
Query
insert(const Types::array &args) {
  return init(_C::reql_ast_insert, args);
}

Query
Query::insert_at(const Types::array &args) const {
  return init(_C::reql_ast_insert_at, this, args);
}
Query
insert_at(const Types::array &args) {
  return init(_C::reql_ast_insert_at, args);
}

Query
Query::intersects(const Types::array &args) const {
  return init(_C::reql_ast_intersects, this, args);
}
Query
intersects(const Types::array &args) {
  return init(_C::reql_ast_intersects, args);
}

Query
Query::in_timezone(const Types::array &args) const {
  return init(_C::reql_ast_in_timezone, this, args);
}
Query
in_timezone(const Types::array &args) {
  return init(_C::reql_ast_in_timezone, args);
}

Query
Query::iso8601(const Types::array &args, const Types::object &kwargs) const {
  return init(_C::reql_ast_iso8601, this, args, kwargs);
}
Query
iso8601(const Types::array &args, const Types::object &kwargs) {
  return init(_C::reql_ast_iso8601, args, kwargs);
}
Query
Query::iso8601(const Types::array &args) const {
  return init(_C::reql_ast_iso8601, this, args);
}
Query
iso8601(const Types::array &args) {
  return init(_C::reql_ast_iso8601, args);
}

Query
Query::is_empty(const Types::array &args) const {
  return init(_C::reql_ast_is_empty, this, args);
}
Query
is_empty(const Types::array &args) {
  return init(_C::reql_ast_is_empty, args);
}

Query
Query::january(const Types::array &args) const {
  return init(_C::reql_ast_january, this, args);
}
Query
january(const Types::array &args) {
  return init(_C::reql_ast_january, args);
}

Query
Query::javascript(const Types::array &args, const Types::object &kwargs) const {
  return init(_C::reql_ast_javascript, this, args, kwargs);
}
Query
javascript(const Types::array &args, const Types::object &kwargs) {
  return init(_C::reql_ast_javascript, args, kwargs);
}
Query
Query::javascript(const Types::array &args) const {
  return init(_C::reql_ast_javascript, this, args);
}
Query
javascript(const Types::array &args) {
  return init(_C::reql_ast_javascript, args);
}

Query
Query::json(const Types::array &args) const {
  return init(_C::reql_ast_json, this, args);
}
Query
json(const Types::array &args) {
  return init(_C::reql_ast_json, args);
}

Query
Query::july(const Types::array &args) const {
  return init(_C::reql_ast_july, this, args);
}
Query
july(const Types::array &args) {
  return init(_C::reql_ast_july, args);
}

Query
Query::june(const Types::array &args) const {
  return init(_C::reql_ast_june, this, args);
}
Query
june(const Types::array &args) {
  return init(_C::reql_ast_june, args);
}

Query
Query::keys(const Types::array &args) const {
  return init(_C::reql_ast_keys, this, args);
}
Query
keys(const Types::array &args) {
  return init(_C::reql_ast_keys, args);
}

Query
Query::le(const Types::array &args) const {
  return init(_C::reql_ast_le, this, args);
}
Query
le(const Types::array &args) {
  return init(_C::reql_ast_le, args);
}

Query
Query::limit(const Types::array &args) const {
  return init(_C::reql_ast_limit, this, args);
}
Query
limit(const Types::array &args) {
  return init(_C::reql_ast_limit, args);
}

Query
Query::line(const Types::array &args) const {
  return init(_C::reql_ast_line, this, args);
}
Query
line(const Types::array &args) {
  return init(_C::reql_ast_line, args);
}

Query
Query::literal(const Types::array &args) const {
  return init(_C::reql_ast_literal, this, args);
}
Query
literal(const Types::array &args) {
  return init(_C::reql_ast_literal, args);
}

Query
Query::lt(const Types::array &args) const {
  return init(_C::reql_ast_lt, this, args);
}
Query
lt(const Types::array &args) {
  return init(_C::reql_ast_lt, args);
}

Query
Query::make_array(const Types::array &args) const {
  return init(_C::reql_ast_make_array, this, args);
}
Query
make_array(const Types::array &args) {
  return init(_C::reql_ast_make_array, args);
}

Query
Query::make_obj(const Types::array &args) const {
  return init(_C::reql_ast_make_obj, this, args);
}
Query
make_obj(const Types::array &args) {
  return init(_C::reql_ast_make_obj, args);
}

Query
Query::map(const Types::array &args) const {
  return init(_C::reql_ast_map, this, args);
}
Query
map(const Types::array &args) {
  return init(_C::reql_ast_map, args);
}

Query
Query::march(const Types::array &args) const {
  return init(_C::reql_ast_march, this, args);
}
Query
march(const Types::array &args) {
  return init(_C::reql_ast_march, args);
}

Query
Query::match(const Types::array &args) const {
  return init(_C::reql_ast_match, this, args);
}
Query
match(const Types::array &args) {
  return init(_C::reql_ast_match, args);
}

Query
Query::max(const Types::array &args) const {
  return init(_C::reql_ast_max, this, args);
}
Query
max(const Types::array &args) {
  return init(_C::reql_ast_max, args);
}

Query
Query::maxval(const Types::array &args) const {
  return init(_C::reql_ast_maxval, this, args);
}
Query
maxval(const Types::array &args) {
  return init(_C::reql_ast_maxval, args);
}

Query
Query::may(const Types::array &args) const {
  return init(_C::reql_ast_may, this, args);
}
Query
may(const Types::array &args) {
  return init(_C::reql_ast_may, args);
}

Query
Query::merge(const Types::array &args) const {
  return init(_C::reql_ast_merge, this, args);
}
Query
merge(const Types::array &args) {
  return init(_C::reql_ast_merge, args);
}

Query
Query::min(const Types::array &args) const {
  return init(_C::reql_ast_min, this, args);
}
Query
min(const Types::array &args) {
  return init(_C::reql_ast_min, args);
}

Query
Query::minutes(const Types::array &args) const {
  return init(_C::reql_ast_minutes, this, args);
}
Query
minutes(const Types::array &args) {
  return init(_C::reql_ast_minutes, args);
}

Query
Query::minval(const Types::array &args) const {
  return init(_C::reql_ast_minval, this, args);
}
Query
minval(const Types::array &args) {
  return init(_C::reql_ast_minval, args);
}

Query
Query::mod(const Types::array &args) const {
  return init(_C::reql_ast_mod, this, args);
}
Query
mod(const Types::array &args) {
  return init(_C::reql_ast_mod, args);
}

Query
Query::monday(const Types::array &args) const {
  return init(_C::reql_ast_monday, this, args);
}
Query
monday(const Types::array &args) {
  return init(_C::reql_ast_monday, args);
}

Query
Query::month(const Types::array &args) const {
  return init(_C::reql_ast_month, this, args);
}
Query
month(const Types::array &args) {
  return init(_C::reql_ast_month, args);
}

Query
Query::mul(const Types::array &args) const {
  return init(_C::reql_ast_mul, this, args);
}
Query
mul(const Types::array &args) {
  return init(_C::reql_ast_mul, args);
}

Query
Query::ne(const Types::array &args) const {
  return init(_C::reql_ast_ne, this, args);
}
Query
ne(const Types::array &args) {
  return init(_C::reql_ast_ne, args);
}

Query
Query::not_(const Types::array &args) const {
  return init(_C::reql_ast_not, this, args);
}
Query
not_(const Types::array &args) {
  return init(_C::reql_ast_not, args);
}

Query
Query::november(const Types::array &args) const {
  return init(_C::reql_ast_november, this, args);
}
Query
november(const Types::array &args) {
  return init(_C::reql_ast_november, args);
}

Query
Query::now(const Types::array &args) const {
  return init(_C::reql_ast_now, this, args);
}
Query
now(const Types::array &args) {
  return init(_C::reql_ast_now, args);
}

Query
Query::nth(const Types::array &args) const {
  return init(_C::reql_ast_nth, this, args);
}
Query
nth(const Types::array &args) {
  return init(_C::reql_ast_nth, args);
}

Query
Query::object(const Types::array &args) const {
  return init(_C::reql_ast_object, this, args);
}
Query
object(const Types::array &args) {
  return init(_C::reql_ast_object, args);
}

Query
Query::october(const Types::array &args) const {
  return init(_C::reql_ast_october, this, args);
}
Query
october(const Types::array &args) {
  return init(_C::reql_ast_october, args);
}

Query
Query::offsets_of(const Types::array &args) const {
  return init(_C::reql_ast_offsets_of, this, args);
}
Query
offsets_of(const Types::array &args) {
  return init(_C::reql_ast_offsets_of, args);
}

Query
Query::or_(const Types::array &args) const {
  return init(_C::reql_ast_or, this, args);
}
Query
or_(const Types::array &args) {
  return init(_C::reql_ast_or, args);
}

Query
Query::order_by(const Types::array &args, const Types::object &kwargs) const {
  return init(_C::reql_ast_order_by, this, args, kwargs);
}
Query
order_by(const Types::array &args, const Types::object &kwargs) {
  return init(_C::reql_ast_order_by, args, kwargs);
}
Query
Query::order_by(const Types::array &args) const {
  return init(_C::reql_ast_order_by, this, args);
}
Query
order_by(const Types::array &args) {
  return init(_C::reql_ast_order_by, args);
}

Query
Query::outer_join(const Types::array &args) const {
  return init(_C::reql_ast_outer_join, this, args);
}
Query
outer_join(const Types::array &args) {
  return init(_C::reql_ast_outer_join, args);
}

Query
Query::pluck(const Types::array &args) const {
  return init(_C::reql_ast_pluck, this, args);
}
Query
pluck(const Types::array &args) {
  return init(_C::reql_ast_pluck, args);
}

Query
Query::point(const Types::array &args) const {
  return init(_C::reql_ast_point, this, args);
}
Query
point(const Types::array &args) {
  return init(_C::reql_ast_point, args);
}

Query
Query::polygon(const Types::array &args) const {
  return init(_C::reql_ast_polygon, this, args);
}
Query
polygon(const Types::array &args) {
  return init(_C::reql_ast_polygon, args);
}

Query
Query::polygon_sub(const Types::array &args) const {
  return init(_C::reql_ast_polygon_sub, this, args);
}
Query
polygon_sub(const Types::array &args) {
  return init(_C::reql_ast_polygon_sub, args);
}

Query
Query::prepend(const Types::array &args) const {
  return init(_C::reql_ast_prepend, this, args);
}
Query
prepend(const Types::array &args) {
  return init(_C::reql_ast_prepend, args);
}

Query
Query::random(const Types::array &args, const Types::object &kwargs) const {
  return init(_C::reql_ast_random, this, args, kwargs);
}
Query
random(const Types::array &args, const Types::object &kwargs) {
  return init(_C::reql_ast_random, args, kwargs);
}
Query
Query::random(const Types::array &args) const {
  return init(_C::reql_ast_random, this, args);
}
Query
random(const Types::array &args) {
  return init(_C::reql_ast_random, args);
}

Query
Query::range(const Types::array &args) const {
  return init(_C::reql_ast_range, this, args);
}
Query
range(const Types::array &args) {
  return init(_C::reql_ast_range, args);
}

Query
Query::rebalance(const Types::array &args) const {
  return init(_C::reql_ast_rebalance, this, args);
}
Query
rebalance(const Types::array &args) {
  return init(_C::reql_ast_rebalance, args);
}

Query
Query::reconfigure(const Types::array &args) const {
  return init(_C::reql_ast_reconfigure, this, args);
}
Query
reconfigure(const Types::array &args) {
  return init(_C::reql_ast_reconfigure, args);
}

Query
Query::reduce(const Types::array &args) const {
  return init(_C::reql_ast_reduce, this, args);
}
Query
reduce(const Types::array &args) {
  return init(_C::reql_ast_reduce, args);
}

Query
Query::replace(const Types::array &args, const Types::object &kwargs) const {
  return init(_C::reql_ast_replace, this, args, kwargs);
}
Query
replace(const Types::array &args, const Types::object &kwargs) {
  return init(_C::reql_ast_replace, args, kwargs);
}
Query
Query::replace(const Types::array &args) const {
  return init(_C::reql_ast_replace, this, args);
}
Query
replace(const Types::array &args) {
  return init(_C::reql_ast_replace, args);
}

Query
Query::round(const Types::array &args) const {
  return init(_C::reql_ast_round, this, args);
}
Query
round(const Types::array &args) {
  return init(_C::reql_ast_round, args);
}

Query
Query::sample(const Types::array &args) const {
  return init(_C::reql_ast_sample, this, args);
}
Query
sample(const Types::array &args) {
  return init(_C::reql_ast_sample, args);
}

Query
Query::saturday(const Types::array &args) const {
  return init(_C::reql_ast_saturday, this, args);
}
Query
saturday(const Types::array &args) {
  return init(_C::reql_ast_saturday, args);
}

Query
Query::seconds(const Types::array &args) const {
  return init(_C::reql_ast_seconds, this, args);
}
Query
seconds(const Types::array &args) {
  return init(_C::reql_ast_seconds, args);
}

Query
Query::september(const Types::array &args) const {
  return init(_C::reql_ast_september, this, args);
}
Query
september(const Types::array &args) {
  return init(_C::reql_ast_september, args);
}

Query
Query::set_difference(const Types::array &args) const {
  return init(_C::reql_ast_set_difference, this, args);
}
Query
set_difference(const Types::array &args) {
  return init(_C::reql_ast_set_difference, args);
}

Query
Query::set_insert(const Types::array &args) const {
  return init(_C::reql_ast_set_insert, this, args);
}
Query
set_insert(const Types::array &args) {
  return init(_C::reql_ast_set_insert, args);
}

Query
Query::set_intersection(const Types::array &args) const {
  return init(_C::reql_ast_set_intersection, this, args);
}
Query
set_intersection(const Types::array &args) {
  return init(_C::reql_ast_set_intersection, args);
}

Query
Query::set_union(const Types::array &args) const {
  return init(_C::reql_ast_set_union, this, args);
}
Query
set_union(const Types::array &args) {
  return init(_C::reql_ast_set_union, args);
}

Query
Query::skip(const Types::array &args) const {
  return init(_C::reql_ast_skip, this, args);
}
Query
skip(const Types::array &args) {
  return init(_C::reql_ast_skip, args);
}

Query
Query::slice(const Types::array &args, const Types::object &kwargs) const {
  return init(_C::reql_ast_slice, this, args, kwargs);
}
Query
slice(const Types::array &args, const Types::object &kwargs) {
  return init(_C::reql_ast_slice, args, kwargs);
}
Query
Query::slice(const Types::array &args) const {
  return init(_C::reql_ast_slice, this, args);
}
Query
slice(const Types::array &args) {
  return init(_C::reql_ast_slice, args);
}

Query
Query::splice_at(const Types::array &args) const {
  return init(_C::reql_ast_splice_at, this, args);
}
Query
splice_at(const Types::array &args) {
  return init(_C::reql_ast_splice_at, args);
}

Query
Query::split(const Types::array &args) const {
  return init(_C::reql_ast_split, this, args);
}
Query
split(const Types::array &args) {
  return init(_C::reql_ast_split, args);
}

Query
Query::status(const Types::array &args) const {
  return init(_C::reql_ast_status, this, args);
}
Query
status(const Types::array &args) {
  return init(_C::reql_ast_status, args);
}

Query
Query::sub(const Types::array &args) const {
  return init(_C::reql_ast_sub, this, args);
}
Query
sub(const Types::array &args) {
  return init(_C::reql_ast_sub, args);
}

Query
Query::sum(const Types::array &args) const {
  return init(_C::reql_ast_sum, this, args);
}
Query
sum(const Types::array &args) {
  return init(_C::reql_ast_sum, args);
}

Query
Query::sunday(const Types::array &args) const {
  return init(_C::reql_ast_sunday, this, args);
}
Query
sunday(const Types::array &args) {
  return init(_C::reql_ast_sunday, args);
}

Query
Query::sync(const Types::array &args) const {
  return init(_C::reql_ast_sync, this, args);
}
Query
sync(const Types::array &args) {
  return init(_C::reql_ast_sync, args);
}

Query
Query::table(const Types::array &args, const Types::object &kwargs) const {
  return init(_C::reql_ast_table, this, args, kwargs);
}
Query
table(const Types::array &args, const Types::object &kwargs) {
  return init(_C::reql_ast_table, args, kwargs);
}
Query
Query::table(const Types::array &args) const {
  return init(_C::reql_ast_table, this, args);
}
Query
table(const Types::array &args) {
  return init(_C::reql_ast_table, args);
}

Query
Query::table_create(const Types::array &args, const Types::object &kwargs) const {
  return init(_C::reql_ast_table_create, this, args, kwargs);
}
Query
table_create(const Types::array &args, const Types::object &kwargs) {
  return init(_C::reql_ast_table_create, args, kwargs);
}
Query
Query::table_create(const Types::array &args) const {
  return init(_C::reql_ast_table_create, this, args);
}
Query
table_create(const Types::array &args) {
  return init(_C::reql_ast_table_create, args);
}

Query
Query::table_drop(const Types::array &args) const {
  return init(_C::reql_ast_table_drop, this, args);
}
Query
table_drop(const Types::array &args) {
  return init(_C::reql_ast_table_drop, args);
}

Query
Query::table_list(const Types::array &args) const {
  return init(_C::reql_ast_table_list, this, args);
}
Query
table_list(const Types::array &args) {
  return init(_C::reql_ast_table_list, args);
}

Query
Query::thursday(const Types::array &args) const {
  return init(_C::reql_ast_thursday, this, args);
}
Query
thursday(const Types::array &args) {
  return init(_C::reql_ast_thursday, args);
}

Query
Query::time(const Types::array &args) const {
  return init(_C::reql_ast_time, this, args);
}
Query
time(const Types::array &args) {
  return init(_C::reql_ast_time, args);
}

Query
Query::timezone_(const Types::array &args) const {
  return init(_C::reql_ast_timezone, this, args);
}
Query
timezone_(const Types::array &args) {
  return init(_C::reql_ast_timezone, args);
}

Query
Query::time_of_day(const Types::array &args) const {
  return init(_C::reql_ast_time_of_day, this, args);
}
Query
time_of_day(const Types::array &args) {
  return init(_C::reql_ast_time_of_day, args);
}

Query
Query::to_epoch_time(const Types::array &args) const {
  return init(_C::reql_ast_to_epoch_time, this, args);
}
Query
to_epoch_time(const Types::array &args) {
  return init(_C::reql_ast_to_epoch_time, args);
}

Query
Query::to_geojson(const Types::array &args) const {
  return init(_C::reql_ast_to_geojson, this, args);
}
Query
to_geojson(const Types::array &args) {
  return init(_C::reql_ast_to_geojson, args);
}

Query
Query::to_iso8601(const Types::array &args) const {
  return init(_C::reql_ast_to_iso8601, this, args);
}
Query
to_iso8601(const Types::array &args) {
  return init(_C::reql_ast_to_iso8601, args);
}

Query
Query::to_json_string(const Types::array &args) const {
  return init(_C::reql_ast_to_json_string, this, args);
}
Query
to_json_string(const Types::array &args) {
  return init(_C::reql_ast_to_json_string, args);
}

Query
Query::tuesday(const Types::array &args) const {
  return init(_C::reql_ast_tuesday, this, args);
}
Query
tuesday(const Types::array &args) {
  return init(_C::reql_ast_tuesday, args);
}

Query
Query::type_of(const Types::array &args) const {
  return init(_C::reql_ast_type_of, this, args);
}
Query
type_of(const Types::array &args) {
  return init(_C::reql_ast_type_of, args);
}

Query
Query::ungroup(const Types::array &args) const {
  return init(_C::reql_ast_ungroup, this, args);
}
Query
ungroup(const Types::array &args) {
  return init(_C::reql_ast_ungroup, args);
}

Query
Query::union_(const Types::array &args) const {
  return init(_C::reql_ast_union, this, args);
}
Query
union_(const Types::array &args) {
  return init(_C::reql_ast_union, args);
}

Query
Query::upcase(const Types::array &args) const {
  return init(_C::reql_ast_upcase, this, args);
}
Query
upcase(const Types::array &args) {
  return init(_C::reql_ast_upcase, args);
}

Query
Query::update(const Types::array &args, const Types::object &kwargs) const {
  return init(_C::reql_ast_update, this, args, kwargs);
}
Query
update(const Types::array &args, const Types::object &kwargs) {
  return init(_C::reql_ast_update, args, kwargs);
}
Query
Query::update(const Types::array &args) const {
  return init(_C::reql_ast_update, this, args);
}
Query
update(const Types::array &args) {
  return init(_C::reql_ast_update, args);
}

Query
Query::uuid(const Types::array &args) const {
  return init(_C::reql_ast_uuid, this, args);
}
Query
uuid(const Types::array &args) {
  return init(_C::reql_ast_uuid, args);
}

Query
Query::var(const Types::array &args) const {
  return init(_C::reql_ast_var, this, args);
}
Query
var(const Types::array &args) {
  return init(_C::reql_ast_var, args);
}

Query
Query::wait(const Types::array &args) const {
  return init(_C::reql_ast_wait, this, args);
}
Query
wait(const Types::array &args) {
  return init(_C::reql_ast_wait, args);
}

Query
Query::wednesday(const Types::array &args) const {
  return init(_C::reql_ast_wednesday, this, args);
}
Query
wednesday(const Types::array &args) {
  return init(_C::reql_ast_wednesday, args);
}

Query
Query::without(const Types::array &args) const {
  return init(_C::reql_ast_without, this, args);
}
Query
without(const Types::array &args) {
  return init(_C::reql_ast_without, args);
}

Query
Query::with_fields(const Types::array &args) const {
  return init(_C::reql_ast_with_fields, this, args);
}
Query
with_fields(const Types::array &args) {
  return init(_C::reql_ast_with_fields, args);
}

Query
Query::year(const Types::array &args) const {
  return init(_C::reql_ast_year, this, args);
}
Query
year(const Types::array &args) {
  return init(_C::reql_ast_year, args);
}

Query
Query::zip(const Types::array &args) const {
  return init(_C::reql_ast_zip, this, args);
}
Query
zip(const Types::array &args) {
  return init(_C::reql_ast_zip, args);
}

}  // namespace ReQL
