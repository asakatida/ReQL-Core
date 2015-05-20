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

#include "./cpp/ast.hpp"

#include "./cpp/query.hpp"

#include <algorithm>

namespace ReQL {

static Query
init(const _C::ReQL_AST_Function &f, const Types::array &args) {
  return Query(f, args);
}

static Query
init(const _C::ReQL_AST_Function &f, const _Internal::AST *term, const Types::array &args) {
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
init(const _C::ReQL_AST_Function_Kwargs &f, const _Internal::AST *term, const Types::array &args, const Types::object &kwargs) {
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
init(const _C::ReQL_AST_Function_Kwargs &f, const _Internal::AST *term, const Types::array &args) {
  return init(f, term, args, Types::object());
}

namespace _Internal {

AST::AST() : Expr() {}

AST::AST(const _C::ReQL_AST_Function &f, const Types::array &args) : Expr(f, args) {}

AST::AST(const _C::ReQL_AST_Function_Kwargs &f, const Types::array &args, const Types::object &kwargs) : Expr(f, args, kwargs) {}

AST::AST(const Types::string &val) : Expr(val) {}

AST::AST(const double &val) : Expr(val) {}

AST::AST(const bool &val) : Expr(val) {}

AST::AST(const Types::array &val) : Expr(val) {}

AST::AST(const Types::object &val) : Expr(val) {}

AST::AST(_C::ReQL_Obj_t *val) : Expr(val) {}

AST::AST(const AST &other) : Expr(other) {}

AST::AST(AST &&other) : Expr(std::move(other)) {}

}  // namespace _Internal

Query
_Internal::AST::add(const Types::array &args) const {
  return init(_C::reql_ast_add, this, args);
}
Query
add(const Types::array &args) {
  return init(_C::reql_ast_add, args);
}

Query
_Internal::AST::and_(const Types::array &args) const {
  return init(_C::reql_ast_and, this, args);
}
Query
and_(const Types::array &args) {
  return init(_C::reql_ast_and, args);
}

Query
_Internal::AST::append(const Types::array &args) const {
  return init(_C::reql_ast_append, this, args);
}
Query
append(const Types::array &args) {
  return init(_C::reql_ast_append, args);
}

Query
_Internal::AST::april(const Types::array &args) const {
  return init(_C::reql_ast_april, this, args);
}
Query
april(const Types::array &args) {
  return init(_C::reql_ast_april, args);
}

Query
_Internal::AST::args(const Types::array &args) const {
  return init(_C::reql_ast_args, this, args);
}
Query
args(const Types::array &args) {
  return init(_C::reql_ast_args, args);
}

Query
_Internal::AST::asc(const Types::array &args) const {
  return init(_C::reql_ast_asc, this, args);
}
Query
asc(const Types::array &args) {
  return init(_C::reql_ast_asc, args);
}

Query
_Internal::AST::august(const Types::array &args) const {
  return init(_C::reql_ast_august, this, args);
}
Query
august(const Types::array &args) {
  return init(_C::reql_ast_august, args);
}

Query
_Internal::AST::avg(const Types::array &args) const {
  return init(_C::reql_ast_avg, this, args);
}
Query
avg(const Types::array &args) {
  return init(_C::reql_ast_avg, args);
}

Query
_Internal::AST::between(const Types::array &args) const {
  return init(_C::reql_ast_between, this, args);
}
Query
between(const Types::array &args) {
  return init(_C::reql_ast_between, args);
}

Query
_Internal::AST::between_deprecated(const Types::array &args) const {
  return init(_C::reql_ast_between_deprecated, this, args);
}
Query
between_deprecated(const Types::array &args) {
  return init(_C::reql_ast_between_deprecated, args);
}

Query
_Internal::AST::binary(const Types::array &args) const {
  return init(_C::reql_ast_binary, this, args);
}
Query
binary(const Types::array &args) {
  return init(_C::reql_ast_binary, args);
}

Query
_Internal::AST::bracket(const Types::array &args) const {
  return init(_C::reql_ast_bracket, this, args);
}
Query
bracket(const Types::array &args) {
  return init(_C::reql_ast_bracket, args);
}

Query
_Internal::AST::branch(const Types::array &args) const {
  return init(_C::reql_ast_branch, this, args);
}
Query
branch(const Types::array &args) {
  return init(_C::reql_ast_branch, args);
}

Query
_Internal::AST::ceil(const Types::array &args) const {
  return init(_C::reql_ast_ceil, this, args);
}
Query
ceil(const Types::array &args) {
  return init(_C::reql_ast_ceil, args);
}

Query
_Internal::AST::changes(const Types::array &args) const {
  return init(_C::reql_ast_changes, this, args);
}
Query
changes(const Types::array &args) {
  return init(_C::reql_ast_changes, args);
}

Query
_Internal::AST::change_at(const Types::array &args) const {
  return init(_C::reql_ast_change_at, this, args);
}
Query
change_at(const Types::array &args) {
  return init(_C::reql_ast_change_at, args);
}

Query
_Internal::AST::circle(const Types::array &args, const Types::object &kwargs) const {
  return init(_C::reql_ast_circle, this, args, kwargs);
}
Query
circle(const Types::array &args, const Types::object &kwargs) {
  return init(_C::reql_ast_circle, args, kwargs);
}
Query
_Internal::AST::circle(const Types::array &args) const {
  return init(_C::reql_ast_circle, this, args);
}
Query
circle(const Types::array &args) {
  return init(_C::reql_ast_circle, args);
}

Query
_Internal::AST::coerce_to(const Types::array &args) const {
  return init(_C::reql_ast_coerce_to, this, args);
}
Query
coerce_to(const Types::array &args) {
  return init(_C::reql_ast_coerce_to, args);
}

Query
_Internal::AST::concat_map(const Types::array &args) const {
  return init(_C::reql_ast_concat_map, this, args);
}
Query
concat_map(const Types::array &args) {
  return init(_C::reql_ast_concat_map, args);
}

Query
_Internal::AST::config(const Types::array &args) const {
  return init(_C::reql_ast_config, this, args);
}
Query
config(const Types::array &args) {
  return init(_C::reql_ast_config, args);
}

Query
_Internal::AST::contains(const Types::array &args) const {
  return init(_C::reql_ast_contains, this, args);
}
Query
contains(const Types::array &args) {
  return init(_C::reql_ast_contains, args);
}

Query
_Internal::AST::count(const Types::array &args) const {
  return init(_C::reql_ast_count, this, args);
}
Query
count(const Types::array &args) {
  return init(_C::reql_ast_count, args);
}

Query
_Internal::AST::date(const Types::array &args) const {
  return init(_C::reql_ast_date, this, args);
}
Query
date(const Types::array &args) {
  return init(_C::reql_ast_date, args);
}

Query
_Internal::AST::datum(const Types::array &args) const {
  return init(_C::reql_ast_datum, this, args);
}
Query
datum(const Types::array &args) {
  return init(_C::reql_ast_datum, args);
}

Query
_Internal::AST::day(const Types::array &args) const {
  return init(_C::reql_ast_day, this, args);
}
Query
day(const Types::array &args) {
  return init(_C::reql_ast_day, args);
}

Query
_Internal::AST::day_of_week(const Types::array &args) const {
  return init(_C::reql_ast_day_of_week, this, args);
}
Query
day_of_week(const Types::array &args) {
  return init(_C::reql_ast_day_of_week, args);
}

Query
_Internal::AST::day_of_year(const Types::array &args) const {
  return init(_C::reql_ast_day_of_year, this, args);
}
Query
day_of_year(const Types::array &args) {
  return init(_C::reql_ast_day_of_year, args);
}

Query
_Internal::AST::db(const Types::array &args) const {
  return init(_C::reql_ast_db, this, args);
}
Query
db(const Types::array &args) {
  return init(_C::reql_ast_db, args);
}

Query
_Internal::AST::db_create(const Types::array &args) const {
  return init(_C::reql_ast_db_create, this, args);
}
Query
db_create(const Types::array &args) {
  return init(_C::reql_ast_db_create, args);
}

Query
_Internal::AST::db_drop(const Types::array &args) const {
  return init(_C::reql_ast_db_drop, this, args);
}
Query
db_drop(const Types::array &args) {
  return init(_C::reql_ast_db_drop, args);
}

Query
_Internal::AST::db_list(const Types::array &args) const {
  return init(_C::reql_ast_db_list, this, args);
}
Query
db_list(const Types::array &args) {
  return init(_C::reql_ast_db_list, args);
}

Query
_Internal::AST::december(const Types::array &args) const {
  return init(_C::reql_ast_december, this, args);
}
Query
december(const Types::array &args) {
  return init(_C::reql_ast_december, args);
}

Query
_Internal::AST::default_(const Types::array &args) const {
  return init(_C::reql_ast_default, this, args);
}
Query
default_(const Types::array &args) {
  return init(_C::reql_ast_default, args);
}

Query
_Internal::AST::delete_(const Types::array &args, const Types::object &kwargs) const {
  return init(_C::reql_ast_delete, this, args, kwargs);
}
Query
delete_(const Types::array &args, const Types::object &kwargs) {
  return init(_C::reql_ast_delete, args, kwargs);
}
Query
_Internal::AST::delete_(const Types::array &args) const {
  return init(_C::reql_ast_delete, this, args);
}
Query
delete_(const Types::array &args) {
  return init(_C::reql_ast_delete, args);
}

Query
_Internal::AST::delete_at(const Types::array &args) const {
  return init(_C::reql_ast_delete_at, this, args);
}
Query
delete_at(const Types::array &args) {
  return init(_C::reql_ast_delete_at, args);
}

Query
_Internal::AST::desc(const Types::array &args) const {
  return init(_C::reql_ast_desc, this, args);
}
Query
desc(const Types::array &args) {
  return init(_C::reql_ast_desc, args);
}

Query
_Internal::AST::difference(const Types::array &args) const {
  return init(_C::reql_ast_difference, this, args);
}
Query
difference(const Types::array &args) {
  return init(_C::reql_ast_difference, args);
}

Query
_Internal::AST::distance(const Types::array &args) const {
  return init(_C::reql_ast_distance, this, args);
}
Query
distance(const Types::array &args) {
  return init(_C::reql_ast_distance, args);
}

Query
_Internal::AST::distinct(const Types::array &args, const Types::object &kwargs) const {
  return init(_C::reql_ast_distinct, this, args, kwargs);
}
Query
distinct(const Types::array &args, const Types::object &kwargs) {
  return init(_C::reql_ast_distinct, args, kwargs);
}
Query
_Internal::AST::distinct(const Types::array &args) const {
  return init(_C::reql_ast_distinct, this, args);
}
Query
distinct(const Types::array &args) {
  return init(_C::reql_ast_distinct, args);
}

Query
_Internal::AST::div(const Types::array &args) const {
  return init(_C::reql_ast_div, this, args);
}
Query
div(const Types::array &args) {
  return init(_C::reql_ast_div, args);
}

Query
_Internal::AST::downcase(const Types::array &args) const {
  return init(_C::reql_ast_downcase, this, args);
}
Query
downcase(const Types::array &args) {
  return init(_C::reql_ast_downcase, args);
}

Query
_Internal::AST::during(const Types::array &args) const {
  return init(_C::reql_ast_during, this, args);
}
Query
during(const Types::array &args) {
  return init(_C::reql_ast_during, args);
}

Query
_Internal::AST::epoch_time(const Types::array &args) const {
  return init(_C::reql_ast_epoch_time, this, args);
}
Query
epoch_time(const Types::array &args) {
  return init(_C::reql_ast_epoch_time, args);
}

Query
_Internal::AST::eq(const Types::array &args) const {
  return init(_C::reql_ast_eq, this, args);
}
Query
eq(const Types::array &args) {
  return init(_C::reql_ast_eq, args);
}

Query
_Internal::AST::eq_join(const Types::array &args, const Types::object &kwargs) const {
  return init(_C::reql_ast_eq_join, this, args, kwargs);
}
Query
eq_join(const Types::array &args, const Types::object &kwargs) {
  return init(_C::reql_ast_eq_join, args, kwargs);
}
Query
_Internal::AST::eq_join(const Types::array &args) const {
  return init(_C::reql_ast_eq_join, this, args);
}
Query
eq_join(const Types::array &args) {
  return init(_C::reql_ast_eq_join, args);
}

Query
_Internal::AST::error(const Types::array &args) const {
  return init(_C::reql_ast_error, this, args);
}
Query
error(const Types::array &args) {
  return init(_C::reql_ast_error, args);
}

Query
_Internal::AST::february(const Types::array &args) const {
  return init(_C::reql_ast_february, this, args);
}
Query
february(const Types::array &args) {
  return init(_C::reql_ast_february, args);
}

Query
_Internal::AST::fill(const Types::array &args) const {
  return init(_C::reql_ast_fill, this, args);
}
Query
fill(const Types::array &args) {
  return init(_C::reql_ast_fill, args);
}

Query
_Internal::AST::filter(const Types::array &args, const Types::object &kwargs) const {
  return init(_C::reql_ast_filter, this, args, kwargs);
}
Query
filter(const Types::array &args, const Types::object &kwargs) {
  return init(_C::reql_ast_filter, args, kwargs);
}
Query
_Internal::AST::filter(const Types::array &args) const {
  return init(_C::reql_ast_filter, this, args);
}
Query
filter(const Types::array &args) {
  return init(_C::reql_ast_filter, args);
}

Query
_Internal::AST::floor(const Types::array &args) const {
  return init(_C::reql_ast_floor, this, args);
}
Query
floor(const Types::array &args) {
  return init(_C::reql_ast_floor, args);
}

Query
_Internal::AST::for_each(const Types::array &args) const {
  return init(_C::reql_ast_for_each, this, args);
}
Query
for_each(const Types::array &args) {
  return init(_C::reql_ast_for_each, args);
}

Query
_Internal::AST::friday(const Types::array &args) const {
  return init(_C::reql_ast_friday, this, args);
}
Query
friday(const Types::array &args) {
  return init(_C::reql_ast_friday, args);
}

Query
_Internal::AST::func(const Types::array &args) const {
  return init(_C::reql_ast_func, this, args);
}
Query
func(const Types::array &args) {
  return init(_C::reql_ast_func, args);
}

Query
_Internal::AST::funcall(const Types::array &args) const {
  return init(_C::reql_ast_funcall, this, args);
}
Query
funcall(const Types::array &args) {
  return init(_C::reql_ast_funcall, args);
}

Query
_Internal::AST::ge(const Types::array &args) const {
  return init(_C::reql_ast_ge, this, args);
}
Query
ge(const Types::array &args) {
  return init(_C::reql_ast_ge, args);
}

Query
_Internal::AST::geojson(const Types::array &args) const {
  return init(_C::reql_ast_geojson, this, args);
}
Query
geojson(const Types::array &args) {
  return init(_C::reql_ast_geojson, args);
}

Query
_Internal::AST::get(const Types::array &args) const {
  return init(_C::reql_ast_get, this, args);
}
Query
get(const Types::array &args) {
  return init(_C::reql_ast_get, args);
}

Query
_Internal::AST::get_all(const Types::array &args, const Types::object &kwargs) const {
  return init(_C::reql_ast_get_all, this, args, kwargs);
}
Query
get_all(const Types::array &args, const Types::object &kwargs) {
  return init(_C::reql_ast_get_all, args, kwargs);
}
Query
_Internal::AST::get_all(const Types::array &args) const {
  return init(_C::reql_ast_get_all, this, args);
}
Query
get_all(const Types::array &args) {
  return init(_C::reql_ast_get_all, args);
}

Query
_Internal::AST::get_field(const Types::array &args) const {
  return init(_C::reql_ast_get_field, this, args);
}
Query
get_field(const Types::array &args) {
  return init(_C::reql_ast_get_field, args);
}

Query
_Internal::AST::get_intersecting(const Types::array &args, const Types::object &kwargs) const {
  return init(_C::reql_ast_get_intersecting, this, args, kwargs);
}
Query
get_intersecting(const Types::array &args, const Types::object &kwargs) {
  return init(_C::reql_ast_get_intersecting, args, kwargs);
}
Query
_Internal::AST::get_intersecting(const Types::array &args) const {
  return init(_C::reql_ast_get_intersecting, this, args);
}
Query
get_intersecting(const Types::array &args) {
  return init(_C::reql_ast_get_intersecting, args);
}

Query
_Internal::AST::get_nearest(const Types::array &args, const Types::object &kwargs) const {
  return init(_C::reql_ast_get_nearest, this, args, kwargs);
}
Query
get_nearest(const Types::array &args, const Types::object &kwargs) {
  return init(_C::reql_ast_get_nearest, args, kwargs);
}
Query
_Internal::AST::get_nearest(const Types::array &args) const {
  return init(_C::reql_ast_get_nearest, this, args);
}
Query
get_nearest(const Types::array &args) {
  return init(_C::reql_ast_get_nearest, args);
}

Query
_Internal::AST::group(const Types::array &args, const Types::object &kwargs) const {
  return init(_C::reql_ast_group, this, args, kwargs);
}
Query
group(const Types::array &args, const Types::object &kwargs) {
  return init(_C::reql_ast_group, args, kwargs);
}
Query
_Internal::AST::group(const Types::array &args) const {
  return init(_C::reql_ast_group, this, args);
}
Query
group(const Types::array &args) {
  return init(_C::reql_ast_group, args);
}

Query
_Internal::AST::gt(const Types::array &args) const {
  return init(_C::reql_ast_gt, this, args);
}
Query
gt(const Types::array &args) {
  return init(_C::reql_ast_gt, args);
}

Query
_Internal::AST::has_fields(const Types::array &args) const {
  return init(_C::reql_ast_has_fields, this, args);
}
Query
has_fields(const Types::array &args) {
  return init(_C::reql_ast_has_fields, args);
}

Query
_Internal::AST::hours(const Types::array &args) const {
  return init(_C::reql_ast_hours, this, args);
}
Query
hours(const Types::array &args) {
  return init(_C::reql_ast_hours, args);
}

Query
_Internal::AST::http(const Types::array &args, const Types::object &kwargs) const {
  return init(_C::reql_ast_http, this, args, kwargs);
}
Query
http(const Types::array &args, const Types::object &kwargs) {
  return init(_C::reql_ast_http, args, kwargs);
}
Query
_Internal::AST::http(const Types::array &args) const {
  return init(_C::reql_ast_http, this, args);
}
Query
http(const Types::array &args) {
  return init(_C::reql_ast_http, args);
}

Query
_Internal::AST::implicit_var(const Types::array &args) const {
  return init(_C::reql_ast_implicit_var, this, args);
}
Query
implicit_var(const Types::array &args) {
  return init(_C::reql_ast_implicit_var, args);
}

Query
_Internal::AST::includes(const Types::array &args) const {
  return init(_C::reql_ast_includes, this, args);
}
Query
includes(const Types::array &args) {
  return init(_C::reql_ast_includes, args);
}

Query
_Internal::AST::index_create(const Types::array &args, const Types::object &kwargs) const {
  return init(_C::reql_ast_index_create, this, args, kwargs);
}
Query
index_create(const Types::array &args, const Types::object &kwargs) {
  return init(_C::reql_ast_index_create, args, kwargs);
}
Query
_Internal::AST::index_create(const Types::array &args) const {
  return init(_C::reql_ast_index_create, this, args);
}
Query
index_create(const Types::array &args) {
  return init(_C::reql_ast_index_create, args);
}

Query
_Internal::AST::index_drop(const Types::array &args) const {
  return init(_C::reql_ast_index_drop, this, args);
}
Query
index_drop(const Types::array &args) {
  return init(_C::reql_ast_index_drop, args);
}

Query
_Internal::AST::index_list(const Types::array &args) const {
  return init(_C::reql_ast_index_list, this, args);
}
Query
index_list(const Types::array &args) {
  return init(_C::reql_ast_index_list, args);
}

Query
_Internal::AST::index_rename(const Types::array &args, const Types::object &kwargs) const {
  return init(_C::reql_ast_index_rename, this, args, kwargs);
}
Query
index_rename(const Types::array &args, const Types::object &kwargs) {
  return init(_C::reql_ast_index_rename, args, kwargs);
}
Query
_Internal::AST::index_rename(const Types::array &args) const {
  return init(_C::reql_ast_index_rename, this, args);
}
Query
index_rename(const Types::array &args) {
  return init(_C::reql_ast_index_rename, args);
}

Query
_Internal::AST::index_status(const Types::array &args) const {
  return init(_C::reql_ast_index_status, this, args);
}
Query
index_status(const Types::array &args) {
  return init(_C::reql_ast_index_status, args);
}

Query
_Internal::AST::index_wait(const Types::array &args) const {
  return init(_C::reql_ast_index_wait, this, args);
}
Query
index_wait(const Types::array &args) {
  return init(_C::reql_ast_index_wait, args);
}

Query
_Internal::AST::info(const Types::array &args) const {
  return init(_C::reql_ast_info, this, args);
}
Query
info(const Types::array &args) {
  return init(_C::reql_ast_info, args);
}

Query
_Internal::AST::inner_join(const Types::array &args) const {
  return init(_C::reql_ast_inner_join, this, args);
}
Query
inner_join(const Types::array &args) {
  return init(_C::reql_ast_inner_join, args);
}

Query
_Internal::AST::insert(const Types::array &args) const {
  return init(_C::reql_ast_insert, this, args);
}
Query
insert(const Types::array &args) {
  return init(_C::reql_ast_insert, args);
}

Query
_Internal::AST::insert_at(const Types::array &args) const {
  return init(_C::reql_ast_insert_at, this, args);
}
Query
insert_at(const Types::array &args) {
  return init(_C::reql_ast_insert_at, args);
}

Query
_Internal::AST::intersects(const Types::array &args) const {
  return init(_C::reql_ast_intersects, this, args);
}
Query
intersects(const Types::array &args) {
  return init(_C::reql_ast_intersects, args);
}

Query
_Internal::AST::in_timezone(const Types::array &args) const {
  return init(_C::reql_ast_in_timezone, this, args);
}
Query
in_timezone(const Types::array &args) {
  return init(_C::reql_ast_in_timezone, args);
}

Query
_Internal::AST::iso8601(const Types::array &args, const Types::object &kwargs) const {
  return init(_C::reql_ast_iso8601, this, args, kwargs);
}
Query
iso8601(const Types::array &args, const Types::object &kwargs) {
  return init(_C::reql_ast_iso8601, args, kwargs);
}
Query
_Internal::AST::iso8601(const Types::array &args) const {
  return init(_C::reql_ast_iso8601, this, args);
}
Query
iso8601(const Types::array &args) {
  return init(_C::reql_ast_iso8601, args);
}

Query
_Internal::AST::is_empty(const Types::array &args) const {
  return init(_C::reql_ast_is_empty, this, args);
}
Query
is_empty(const Types::array &args) {
  return init(_C::reql_ast_is_empty, args);
}

Query
_Internal::AST::january(const Types::array &args) const {
  return init(_C::reql_ast_january, this, args);
}
Query
january(const Types::array &args) {
  return init(_C::reql_ast_january, args);
}

Query
_Internal::AST::javascript(const Types::array &args, const Types::object &kwargs) const {
  return init(_C::reql_ast_javascript, this, args, kwargs);
}
Query
javascript(const Types::array &args, const Types::object &kwargs) {
  return init(_C::reql_ast_javascript, args, kwargs);
}
Query
_Internal::AST::javascript(const Types::array &args) const {
  return init(_C::reql_ast_javascript, this, args);
}
Query
javascript(const Types::array &args) {
  return init(_C::reql_ast_javascript, args);
}

Query
_Internal::AST::json(const Types::array &args) const {
  return init(_C::reql_ast_json, this, args);
}
Query
json(const Types::array &args) {
  return init(_C::reql_ast_json, args);
}

Query
_Internal::AST::july(const Types::array &args) const {
  return init(_C::reql_ast_july, this, args);
}
Query
july(const Types::array &args) {
  return init(_C::reql_ast_july, args);
}

Query
_Internal::AST::june(const Types::array &args) const {
  return init(_C::reql_ast_june, this, args);
}
Query
june(const Types::array &args) {
  return init(_C::reql_ast_june, args);
}

Query
_Internal::AST::keys(const Types::array &args) const {
  return init(_C::reql_ast_keys, this, args);
}
Query
keys(const Types::array &args) {
  return init(_C::reql_ast_keys, args);
}

Query
_Internal::AST::le(const Types::array &args) const {
  return init(_C::reql_ast_le, this, args);
}
Query
le(const Types::array &args) {
  return init(_C::reql_ast_le, args);
}

Query
_Internal::AST::limit(const Types::array &args) const {
  return init(_C::reql_ast_limit, this, args);
}
Query
limit(const Types::array &args) {
  return init(_C::reql_ast_limit, args);
}

Query
_Internal::AST::line(const Types::array &args) const {
  return init(_C::reql_ast_line, this, args);
}
Query
line(const Types::array &args) {
  return init(_C::reql_ast_line, args);
}

Query
_Internal::AST::literal(const Types::array &args) const {
  return init(_C::reql_ast_literal, this, args);
}
Query
literal(const Types::array &args) {
  return init(_C::reql_ast_literal, args);
}

Query
_Internal::AST::lt(const Types::array &args) const {
  return init(_C::reql_ast_lt, this, args);
}
Query
lt(const Types::array &args) {
  return init(_C::reql_ast_lt, args);
}

Query
_Internal::AST::make_array(const Types::array &args) const {
  return init(_C::reql_ast_make_array, this, args);
}
Query
make_array(const Types::array &args) {
  return init(_C::reql_ast_make_array, args);
}

Query
_Internal::AST::make_obj(const Types::array &args) const {
  return init(_C::reql_ast_make_obj, this, args);
}
Query
make_obj(const Types::array &args) {
  return init(_C::reql_ast_make_obj, args);
}

Query
_Internal::AST::map(const Types::array &args) const {
  return init(_C::reql_ast_map, this, args);
}
Query
map(const Types::array &args) {
  return init(_C::reql_ast_map, args);
}

Query
_Internal::AST::march(const Types::array &args) const {
  return init(_C::reql_ast_march, this, args);
}
Query
march(const Types::array &args) {
  return init(_C::reql_ast_march, args);
}

Query
_Internal::AST::match(const Types::array &args) const {
  return init(_C::reql_ast_match, this, args);
}
Query
match(const Types::array &args) {
  return init(_C::reql_ast_match, args);
}

Query
_Internal::AST::max(const Types::array &args) const {
  return init(_C::reql_ast_max, this, args);
}
Query
max(const Types::array &args) {
  return init(_C::reql_ast_max, args);
}

Query
_Internal::AST::maxval(const Types::array &args) const {
  return init(_C::reql_ast_maxval, this, args);
}
Query
maxval(const Types::array &args) {
  return init(_C::reql_ast_maxval, args);
}

Query
_Internal::AST::may(const Types::array &args) const {
  return init(_C::reql_ast_may, this, args);
}
Query
may(const Types::array &args) {
  return init(_C::reql_ast_may, args);
}

Query
_Internal::AST::merge(const Types::array &args) const {
  return init(_C::reql_ast_merge, this, args);
}
Query
merge(const Types::array &args) {
  return init(_C::reql_ast_merge, args);
}

Query
_Internal::AST::min(const Types::array &args) const {
  return init(_C::reql_ast_min, this, args);
}
Query
min(const Types::array &args) {
  return init(_C::reql_ast_min, args);
}

Query
_Internal::AST::minutes(const Types::array &args) const {
  return init(_C::reql_ast_minutes, this, args);
}
Query
minutes(const Types::array &args) {
  return init(_C::reql_ast_minutes, args);
}

Query
_Internal::AST::minval(const Types::array &args) const {
  return init(_C::reql_ast_minval, this, args);
}
Query
minval(const Types::array &args) {
  return init(_C::reql_ast_minval, args);
}

Query
_Internal::AST::mod(const Types::array &args) const {
  return init(_C::reql_ast_mod, this, args);
}
Query
mod(const Types::array &args) {
  return init(_C::reql_ast_mod, args);
}

Query
_Internal::AST::monday(const Types::array &args) const {
  return init(_C::reql_ast_monday, this, args);
}
Query
monday(const Types::array &args) {
  return init(_C::reql_ast_monday, args);
}

Query
_Internal::AST::month(const Types::array &args) const {
  return init(_C::reql_ast_month, this, args);
}
Query
month(const Types::array &args) {
  return init(_C::reql_ast_month, args);
}

Query
_Internal::AST::mul(const Types::array &args) const {
  return init(_C::reql_ast_mul, this, args);
}
Query
mul(const Types::array &args) {
  return init(_C::reql_ast_mul, args);
}

Query
_Internal::AST::ne(const Types::array &args) const {
  return init(_C::reql_ast_ne, this, args);
}
Query
ne(const Types::array &args) {
  return init(_C::reql_ast_ne, args);
}

Query
_Internal::AST::not_(const Types::array &args) const {
  return init(_C::reql_ast_not, this, args);
}
Query
not_(const Types::array &args) {
  return init(_C::reql_ast_not, args);
}

Query
_Internal::AST::november(const Types::array &args) const {
  return init(_C::reql_ast_november, this, args);
}
Query
november(const Types::array &args) {
  return init(_C::reql_ast_november, args);
}

Query
_Internal::AST::now(const Types::array &args) const {
  return init(_C::reql_ast_now, this, args);
}
Query
now(const Types::array &args) {
  return init(_C::reql_ast_now, args);
}

Query
_Internal::AST::nth(const Types::array &args) const {
  return init(_C::reql_ast_nth, this, args);
}
Query
nth(const Types::array &args) {
  return init(_C::reql_ast_nth, args);
}

Query
_Internal::AST::object(const Types::array &args) const {
  return init(_C::reql_ast_object, this, args);
}
Query
object(const Types::array &args) {
  return init(_C::reql_ast_object, args);
}

Query
_Internal::AST::october(const Types::array &args) const {
  return init(_C::reql_ast_october, this, args);
}
Query
october(const Types::array &args) {
  return init(_C::reql_ast_october, args);
}

Query
_Internal::AST::offsets_of(const Types::array &args) const {
  return init(_C::reql_ast_offsets_of, this, args);
}
Query
offsets_of(const Types::array &args) {
  return init(_C::reql_ast_offsets_of, args);
}

Query
_Internal::AST::or_(const Types::array &args) const {
  return init(_C::reql_ast_or, this, args);
}
Query
or_(const Types::array &args) {
  return init(_C::reql_ast_or, args);
}

Query
_Internal::AST::order_by(const Types::array &args, const Types::object &kwargs) const {
  return init(_C::reql_ast_order_by, this, args, kwargs);
}
Query
order_by(const Types::array &args, const Types::object &kwargs) {
  return init(_C::reql_ast_order_by, args, kwargs);
}
Query
_Internal::AST::order_by(const Types::array &args) const {
  return init(_C::reql_ast_order_by, this, args);
}
Query
order_by(const Types::array &args) {
  return init(_C::reql_ast_order_by, args);
}

Query
_Internal::AST::outer_join(const Types::array &args) const {
  return init(_C::reql_ast_outer_join, this, args);
}
Query
outer_join(const Types::array &args) {
  return init(_C::reql_ast_outer_join, args);
}

Query
_Internal::AST::pluck(const Types::array &args) const {
  return init(_C::reql_ast_pluck, this, args);
}
Query
pluck(const Types::array &args) {
  return init(_C::reql_ast_pluck, args);
}

Query
_Internal::AST::point(const Types::array &args) const {
  return init(_C::reql_ast_point, this, args);
}
Query
point(const Types::array &args) {
  return init(_C::reql_ast_point, args);
}

Query
_Internal::AST::polygon(const Types::array &args) const {
  return init(_C::reql_ast_polygon, this, args);
}
Query
polygon(const Types::array &args) {
  return init(_C::reql_ast_polygon, args);
}

Query
_Internal::AST::polygon_sub(const Types::array &args) const {
  return init(_C::reql_ast_polygon_sub, this, args);
}
Query
polygon_sub(const Types::array &args) {
  return init(_C::reql_ast_polygon_sub, args);
}

Query
_Internal::AST::prepend(const Types::array &args) const {
  return init(_C::reql_ast_prepend, this, args);
}
Query
prepend(const Types::array &args) {
  return init(_C::reql_ast_prepend, args);
}

Query
_Internal::AST::random(const Types::array &args, const Types::object &kwargs) const {
  return init(_C::reql_ast_random, this, args, kwargs);
}
Query
random(const Types::array &args, const Types::object &kwargs) {
  return init(_C::reql_ast_random, args, kwargs);
}
Query
_Internal::AST::random(const Types::array &args) const {
  return init(_C::reql_ast_random, this, args);
}
Query
random(const Types::array &args) {
  return init(_C::reql_ast_random, args);
}

Query
_Internal::AST::range(const Types::array &args) const {
  return init(_C::reql_ast_range, this, args);
}
Query
range(const Types::array &args) {
  return init(_C::reql_ast_range, args);
}

Query
_Internal::AST::rebalance(const Types::array &args) const {
  return init(_C::reql_ast_rebalance, this, args);
}
Query
rebalance(const Types::array &args) {
  return init(_C::reql_ast_rebalance, args);
}

Query
_Internal::AST::reconfigure(const Types::array &args) const {
  return init(_C::reql_ast_reconfigure, this, args);
}
Query
reconfigure(const Types::array &args) {
  return init(_C::reql_ast_reconfigure, args);
}

Query
_Internal::AST::reduce(const Types::array &args) const {
  return init(_C::reql_ast_reduce, this, args);
}
Query
reduce(const Types::array &args) {
  return init(_C::reql_ast_reduce, args);
}

Query
_Internal::AST::replace(const Types::array &args, const Types::object &kwargs) const {
  return init(_C::reql_ast_replace, this, args, kwargs);
}
Query
replace(const Types::array &args, const Types::object &kwargs) {
  return init(_C::reql_ast_replace, args, kwargs);
}
Query
_Internal::AST::replace(const Types::array &args) const {
  return init(_C::reql_ast_replace, this, args);
}
Query
replace(const Types::array &args) {
  return init(_C::reql_ast_replace, args);
}

Query
_Internal::AST::round(const Types::array &args) const {
  return init(_C::reql_ast_round, this, args);
}
Query
round(const Types::array &args) {
  return init(_C::reql_ast_round, args);
}

Query
_Internal::AST::sample(const Types::array &args) const {
  return init(_C::reql_ast_sample, this, args);
}
Query
sample(const Types::array &args) {
  return init(_C::reql_ast_sample, args);
}

Query
_Internal::AST::saturday(const Types::array &args) const {
  return init(_C::reql_ast_saturday, this, args);
}
Query
saturday(const Types::array &args) {
  return init(_C::reql_ast_saturday, args);
}

Query
_Internal::AST::seconds(const Types::array &args) const {
  return init(_C::reql_ast_seconds, this, args);
}
Query
seconds(const Types::array &args) {
  return init(_C::reql_ast_seconds, args);
}

Query
_Internal::AST::september(const Types::array &args) const {
  return init(_C::reql_ast_september, this, args);
}
Query
september(const Types::array &args) {
  return init(_C::reql_ast_september, args);
}

Query
_Internal::AST::set_difference(const Types::array &args) const {
  return init(_C::reql_ast_set_difference, this, args);
}
Query
set_difference(const Types::array &args) {
  return init(_C::reql_ast_set_difference, args);
}

Query
_Internal::AST::set_insert(const Types::array &args) const {
  return init(_C::reql_ast_set_insert, this, args);
}
Query
set_insert(const Types::array &args) {
  return init(_C::reql_ast_set_insert, args);
}

Query
_Internal::AST::set_intersection(const Types::array &args) const {
  return init(_C::reql_ast_set_intersection, this, args);
}
Query
set_intersection(const Types::array &args) {
  return init(_C::reql_ast_set_intersection, args);
}

Query
_Internal::AST::set_union(const Types::array &args) const {
  return init(_C::reql_ast_set_union, this, args);
}
Query
set_union(const Types::array &args) {
  return init(_C::reql_ast_set_union, args);
}

Query
_Internal::AST::skip(const Types::array &args) const {
  return init(_C::reql_ast_skip, this, args);
}
Query
skip(const Types::array &args) {
  return init(_C::reql_ast_skip, args);
}

Query
_Internal::AST::slice(const Types::array &args, const Types::object &kwargs) const {
  return init(_C::reql_ast_slice, this, args, kwargs);
}
Query
slice(const Types::array &args, const Types::object &kwargs) {
  return init(_C::reql_ast_slice, args, kwargs);
}
Query
_Internal::AST::slice(const Types::array &args) const {
  return init(_C::reql_ast_slice, this, args);
}
Query
slice(const Types::array &args) {
  return init(_C::reql_ast_slice, args);
}

Query
_Internal::AST::splice_at(const Types::array &args) const {
  return init(_C::reql_ast_splice_at, this, args);
}
Query
splice_at(const Types::array &args) {
  return init(_C::reql_ast_splice_at, args);
}

Query
_Internal::AST::split(const Types::array &args) const {
  return init(_C::reql_ast_split, this, args);
}
Query
split(const Types::array &args) {
  return init(_C::reql_ast_split, args);
}

Query
_Internal::AST::status(const Types::array &args) const {
  return init(_C::reql_ast_status, this, args);
}
Query
status(const Types::array &args) {
  return init(_C::reql_ast_status, args);
}

Query
_Internal::AST::sub(const Types::array &args) const {
  return init(_C::reql_ast_sub, this, args);
}
Query
sub(const Types::array &args) {
  return init(_C::reql_ast_sub, args);
}

Query
_Internal::AST::sum(const Types::array &args) const {
  return init(_C::reql_ast_sum, this, args);
}
Query
sum(const Types::array &args) {
  return init(_C::reql_ast_sum, args);
}

Query
_Internal::AST::sunday(const Types::array &args) const {
  return init(_C::reql_ast_sunday, this, args);
}
Query
sunday(const Types::array &args) {
  return init(_C::reql_ast_sunday, args);
}

Query
_Internal::AST::sync(const Types::array &args) const {
  return init(_C::reql_ast_sync, this, args);
}
Query
sync(const Types::array &args) {
  return init(_C::reql_ast_sync, args);
}

Query
_Internal::AST::table(const Types::array &args, const Types::object &kwargs) const {
  return init(_C::reql_ast_table, this, args, kwargs);
}
Query
table(const Types::array &args, const Types::object &kwargs) {
  return init(_C::reql_ast_table, args, kwargs);
}
Query
_Internal::AST::table(const Types::array &args) const {
  return init(_C::reql_ast_table, this, args);
}
Query
table(const Types::array &args) {
  return init(_C::reql_ast_table, args);
}

Query
_Internal::AST::table_create(const Types::array &args, const Types::object &kwargs) const {
  return init(_C::reql_ast_table_create, this, args, kwargs);
}
Query
table_create(const Types::array &args, const Types::object &kwargs) {
  return init(_C::reql_ast_table_create, args, kwargs);
}
Query
_Internal::AST::table_create(const Types::array &args) const {
  return init(_C::reql_ast_table_create, this, args);
}
Query
table_create(const Types::array &args) {
  return init(_C::reql_ast_table_create, args);
}

Query
_Internal::AST::table_drop(const Types::array &args) const {
  return init(_C::reql_ast_table_drop, this, args);
}
Query
table_drop(const Types::array &args) {
  return init(_C::reql_ast_table_drop, args);
}

Query
_Internal::AST::table_list(const Types::array &args) const {
  return init(_C::reql_ast_table_list, this, args);
}
Query
table_list(const Types::array &args) {
  return init(_C::reql_ast_table_list, args);
}

Query
_Internal::AST::thursday(const Types::array &args) const {
  return init(_C::reql_ast_thursday, this, args);
}
Query
thursday(const Types::array &args) {
  return init(_C::reql_ast_thursday, args);
}

Query
_Internal::AST::time(const Types::array &args) const {
  return init(_C::reql_ast_time, this, args);
}
Query
time(const Types::array &args) {
  return init(_C::reql_ast_time, args);
}

Query
_Internal::AST::timezone_(const Types::array &args) const {
  return init(_C::reql_ast_timezone, this, args);
}
Query
timezone_(const Types::array &args) {
  return init(_C::reql_ast_timezone, args);
}

Query
_Internal::AST::time_of_day(const Types::array &args) const {
  return init(_C::reql_ast_time_of_day, this, args);
}
Query
time_of_day(const Types::array &args) {
  return init(_C::reql_ast_time_of_day, args);
}

Query
_Internal::AST::to_epoch_time(const Types::array &args) const {
  return init(_C::reql_ast_to_epoch_time, this, args);
}
Query
to_epoch_time(const Types::array &args) {
  return init(_C::reql_ast_to_epoch_time, args);
}

Query
_Internal::AST::to_geojson(const Types::array &args) const {
  return init(_C::reql_ast_to_geojson, this, args);
}
Query
to_geojson(const Types::array &args) {
  return init(_C::reql_ast_to_geojson, args);
}

Query
_Internal::AST::to_iso8601(const Types::array &args) const {
  return init(_C::reql_ast_to_iso8601, this, args);
}
Query
to_iso8601(const Types::array &args) {
  return init(_C::reql_ast_to_iso8601, args);
}

Query
_Internal::AST::to_json_string(const Types::array &args) const {
  return init(_C::reql_ast_to_json_string, this, args);
}
Query
to_json_string(const Types::array &args) {
  return init(_C::reql_ast_to_json_string, args);
}

Query
_Internal::AST::tuesday(const Types::array &args) const {
  return init(_C::reql_ast_tuesday, this, args);
}
Query
tuesday(const Types::array &args) {
  return init(_C::reql_ast_tuesday, args);
}

Query
_Internal::AST::type_of(const Types::array &args) const {
  return init(_C::reql_ast_type_of, this, args);
}
Query
type_of(const Types::array &args) {
  return init(_C::reql_ast_type_of, args);
}

Query
_Internal::AST::ungroup(const Types::array &args) const {
  return init(_C::reql_ast_ungroup, this, args);
}
Query
ungroup(const Types::array &args) {
  return init(_C::reql_ast_ungroup, args);
}

Query
_Internal::AST::union_(const Types::array &args) const {
  return init(_C::reql_ast_union, this, args);
}
Query
union_(const Types::array &args) {
  return init(_C::reql_ast_union, args);
}

Query
_Internal::AST::upcase(const Types::array &args) const {
  return init(_C::reql_ast_upcase, this, args);
}
Query
upcase(const Types::array &args) {
  return init(_C::reql_ast_upcase, args);
}

Query
_Internal::AST::update(const Types::array &args, const Types::object &kwargs) const {
  return init(_C::reql_ast_update, this, args, kwargs);
}
Query
update(const Types::array &args, const Types::object &kwargs) {
  return init(_C::reql_ast_update, args, kwargs);
}
Query
_Internal::AST::update(const Types::array &args) const {
  return init(_C::reql_ast_update, this, args);
}
Query
update(const Types::array &args) {
  return init(_C::reql_ast_update, args);
}

Query
_Internal::AST::uuid(const Types::array &args) const {
  return init(_C::reql_ast_uuid, this, args);
}
Query
uuid(const Types::array &args) {
  return init(_C::reql_ast_uuid, args);
}

Query
_Internal::AST::var(const Types::array &args) const {
  return init(_C::reql_ast_var, this, args);
}
Query
var(const Types::array &args) {
  return init(_C::reql_ast_var, args);
}

Query
_Internal::AST::wait(const Types::array &args) const {
  return init(_C::reql_ast_wait, this, args);
}
Query
wait(const Types::array &args) {
  return init(_C::reql_ast_wait, args);
}

Query
_Internal::AST::wednesday(const Types::array &args) const {
  return init(_C::reql_ast_wednesday, this, args);
}
Query
wednesday(const Types::array &args) {
  return init(_C::reql_ast_wednesday, args);
}

Query
_Internal::AST::without(const Types::array &args) const {
  return init(_C::reql_ast_without, this, args);
}
Query
without(const Types::array &args) {
  return init(_C::reql_ast_without, args);
}

Query
_Internal::AST::with_fields(const Types::array &args) const {
  return init(_C::reql_ast_with_fields, this, args);
}
Query
with_fields(const Types::array &args) {
  return init(_C::reql_ast_with_fields, args);
}

Query
_Internal::AST::year(const Types::array &args) const {
  return init(_C::reql_ast_year, this, args);
}
Query
year(const Types::array &args) {
  return init(_C::reql_ast_year, args);
}

Query
_Internal::AST::zip(const Types::array &args) const {
  return init(_C::reql_ast_zip, this, args);
}
Query
zip(const Types::array &args) {
  return init(_C::reql_ast_zip, args);
}

}  // namespace ReQL
