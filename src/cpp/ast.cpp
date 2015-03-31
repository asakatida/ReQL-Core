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

#include "./cpp/connection.hpp"

#include <algorithm>
#include <map>
#include <string>
#include <vector>

namespace ReQL {

static Query
init(const ReQL_AST_Function &f, const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) {
  return Query(f, args, kwargs);
}

static Query
init(const ReQL_AST_Function &f, const AST *term, const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) {
  std::vector<Query> new_args;
  new_args.push_back(*term);
  new_args.insert(new_args.end(), args.cbegin(), args.cend());
  return init(f, new_args, kwargs);
}

static Query
init(const ReQL_AST_Function &f, const std::vector<Query> &args) {
  return init(f, args, std::map<std::string, Query>());
}

static Query
init(const ReQL_AST_Function &f, const AST *term, const std::vector<Query> &args) {
  return init(f, term, args, std::map<std::string, Query>());
}

AST::AST() : Expr() {}

AST::AST(const ReQL_AST_Function &f, const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) : Expr(f, args, kwargs) {}

AST::AST(const std::string &val) : Expr(val) {}

AST::AST(const double &val) : Expr(val) {}

AST::AST(const bool &val) : Expr(val) {}

AST::AST(const std::vector<Query> &val) : Expr(val) {}

AST::AST(const std::map<std::string, Query> &val) : Expr(val) {}

AST::AST(const AST &other) : Expr(other) {}

AST::AST(AST &&other) : Expr(std::move(other)) {}

Query
AST::add(const std::vector<Query> &args) const {
  return init(reql_ast_add, this, args);
}
Query
add(const std::vector<Query> &args) {
  return init(reql_ast_add, args);
}

Query
AST::and_(const std::vector<Query> &args) const {
  return init(reql_ast_and, this, args);
}
Query
and_(const std::vector<Query> &args) {
  return init(reql_ast_and, args);
}

Query
AST::append(const std::vector<Query> &args) const {
  return init(reql_ast_append, this, args);
}
Query
append(const std::vector<Query> &args) {
  return init(reql_ast_append, args);
}

Query
AST::april(const std::vector<Query> &args) const {
  return init(reql_ast_april, this, args);
}
Query
april(const std::vector<Query> &args) {
  return init(reql_ast_april, args);
}

Query
AST::args(const std::vector<Query> &args) const {
  return init(reql_ast_args, this, args);
}
Query
args(const std::vector<Query> &args) {
  return init(reql_ast_args, args);
}

Query
AST::asc(const std::vector<Query> &args) const {
  return init(reql_ast_asc, this, args);
}
Query
asc(const std::vector<Query> &args) {
  return init(reql_ast_asc, args);
}

Query
AST::august(const std::vector<Query> &args) const {
  return init(reql_ast_august, this, args);
}
Query
august(const std::vector<Query> &args) {
  return init(reql_ast_august, args);
}

Query
AST::avg(const std::vector<Query> &args) const {
  return init(reql_ast_avg, this, args);
}
Query
avg(const std::vector<Query> &args) {
  return init(reql_ast_avg, args);
}

Query
AST::between(const std::vector<Query> &args) const {
  return init(reql_ast_between, this, args);
}
Query
between(const std::vector<Query> &args) {
  return init(reql_ast_between, args);
}

Query
AST::between_deprecated(const std::vector<Query> &args) const {
  return init(reql_ast_between_deprecated, this, args);
}
Query
between_deprecated(const std::vector<Query> &args) {
  return init(reql_ast_between_deprecated, args);
}

Query
AST::binary(const std::vector<Query> &args) const {
  return init(reql_ast_binary, this, args);
}
Query
binary(const std::vector<Query> &args) {
  return init(reql_ast_binary, args);
}

Query
AST::bracket(const std::vector<Query> &args) const {
  return init(reql_ast_bracket, this, args);
}
Query
bracket(const std::vector<Query> &args) {
  return init(reql_ast_bracket, args);
}

Query
AST::branch(const std::vector<Query> &args) const {
  return init(reql_ast_branch, this, args);
}
Query
branch(const std::vector<Query> &args) {
  return init(reql_ast_branch, args);
}

Query
AST::ceil(const std::vector<Query> &args) const {
  return init(reql_ast_ceil, this, args);
}
Query
ceil(const std::vector<Query> &args) {
  return init(reql_ast_ceil, args);
}

Query
AST::changes(const std::vector<Query> &args) const {
  return init(reql_ast_changes, this, args);
}
Query
changes(const std::vector<Query> &args) {
  return init(reql_ast_changes, args);
}

Query
AST::change_at(const std::vector<Query> &args) const {
  return init(reql_ast_change_at, this, args);
}
Query
change_at(const std::vector<Query> &args) {
  return init(reql_ast_change_at, args);
}

Query
AST::circle(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) const {
  return init(reql_ast_circle, this, args, kwargs);
}
Query
circle(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) {
  return init(reql_ast_circle, args, kwargs);
}
Query
AST::circle(const std::vector<Query> &args) const {
  return init(reql_ast_circle, this, args);
}
Query
circle(const std::vector<Query> &args) {
  return init(reql_ast_circle, args);
}

Query
AST::coerce_to(const std::vector<Query> &args) const {
  return init(reql_ast_coerce_to, this, args);
}
Query
coerce_to(const std::vector<Query> &args) {
  return init(reql_ast_coerce_to, args);
}

Query
AST::concat_map(const std::vector<Query> &args) const {
  return init(reql_ast_concat_map, this, args);
}
Query
concat_map(const std::vector<Query> &args) {
  return init(reql_ast_concat_map, args);
}

Query
AST::config(const std::vector<Query> &args) const {
  return init(reql_ast_config, this, args);
}
Query
config(const std::vector<Query> &args) {
  return init(reql_ast_config, args);
}

Query
AST::contains(const std::vector<Query> &args) const {
  return init(reql_ast_contains, this, args);
}
Query
contains(const std::vector<Query> &args) {
  return init(reql_ast_contains, args);
}

Query
AST::count(const std::vector<Query> &args) const {
  return init(reql_ast_count, this, args);
}
Query
count(const std::vector<Query> &args) {
  return init(reql_ast_count, args);
}

Query
AST::date(const std::vector<Query> &args) const {
  return init(reql_ast_date, this, args);
}
Query
date(const std::vector<Query> &args) {
  return init(reql_ast_date, args);
}

Query
AST::datum(const std::vector<Query> &args) const {
  return init(reql_ast_datum, this, args);
}
Query
datum(const std::vector<Query> &args) {
  return init(reql_ast_datum, args);
}

Query
AST::day(const std::vector<Query> &args) const {
  return init(reql_ast_day, this, args);
}
Query
day(const std::vector<Query> &args) {
  return init(reql_ast_day, args);
}

Query
AST::day_of_week(const std::vector<Query> &args) const {
  return init(reql_ast_day_of_week, this, args);
}
Query
day_of_week(const std::vector<Query> &args) {
  return init(reql_ast_day_of_week, args);
}

Query
AST::day_of_year(const std::vector<Query> &args) const {
  return init(reql_ast_day_of_year, this, args);
}
Query
day_of_year(const std::vector<Query> &args) {
  return init(reql_ast_day_of_year, args);
}

Query
AST::db(const std::vector<Query> &args) const {
  return init(reql_ast_db, this, args);
}
Query
db(const std::vector<Query> &args) {
  return init(reql_ast_db, args);
}

Query
AST::db_create(const std::vector<Query> &args) const {
  return init(reql_ast_db_create, this, args);
}
Query
db_create(const std::vector<Query> &args) {
  return init(reql_ast_db_create, args);
}

Query
AST::db_drop(const std::vector<Query> &args) const {
  return init(reql_ast_db_drop, this, args);
}
Query
db_drop(const std::vector<Query> &args) {
  return init(reql_ast_db_drop, args);
}

Query
AST::db_list(const std::vector<Query> &args) const {
  return init(reql_ast_db_list, this, args);
}
Query
db_list(const std::vector<Query> &args) {
  return init(reql_ast_db_list, args);
}

Query
AST::december(const std::vector<Query> &args) const {
  return init(reql_ast_december, this, args);
}
Query
december(const std::vector<Query> &args) {
  return init(reql_ast_december, args);
}

Query
AST::default_(const std::vector<Query> &args) const {
  return init(reql_ast_default, this, args);
}
Query
default_(const std::vector<Query> &args) {
  return init(reql_ast_default, args);
}

Query
AST::delete_(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) const {
  return init(reql_ast_delete, this, args, kwargs);
}
Query
delete_(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) {
  return init(reql_ast_delete, args, kwargs);
}
Query
AST::delete_(const std::vector<Query> &args) const {
  return init(reql_ast_delete, this, args);
}
Query
delete_(const std::vector<Query> &args) {
  return init(reql_ast_delete, args);
}

Query
AST::delete_at(const std::vector<Query> &args) const {
  return init(reql_ast_delete_at, this, args);
}
Query
delete_at(const std::vector<Query> &args) {
  return init(reql_ast_delete_at, args);
}

Query
AST::desc(const std::vector<Query> &args) const {
  return init(reql_ast_desc, this, args);
}
Query
desc(const std::vector<Query> &args) {
  return init(reql_ast_desc, args);
}

Query
AST::difference(const std::vector<Query> &args) const {
  return init(reql_ast_difference, this, args);
}
Query
difference(const std::vector<Query> &args) {
  return init(reql_ast_difference, args);
}

Query
AST::distance(const std::vector<Query> &args) const {
  return init(reql_ast_distance, this, args);
}
Query
distance(const std::vector<Query> &args) {
  return init(reql_ast_distance, args);
}

Query
AST::distinct(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) const {
  return init(reql_ast_distinct, this, args, kwargs);
}
Query
distinct(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) {
  return init(reql_ast_distinct, args, kwargs);
}
Query
AST::distinct(const std::vector<Query> &args) const {
  return init(reql_ast_distinct, this, args);
}
Query
distinct(const std::vector<Query> &args) {
  return init(reql_ast_distinct, args);
}

Query
AST::div(const std::vector<Query> &args) const {
  return init(reql_ast_div, this, args);
}
Query
div(const std::vector<Query> &args) {
  return init(reql_ast_div, args);
}

Query
AST::downcase(const std::vector<Query> &args) const {
  return init(reql_ast_downcase, this, args);
}
Query
downcase(const std::vector<Query> &args) {
  return init(reql_ast_downcase, args);
}

Query
AST::during(const std::vector<Query> &args) const {
  return init(reql_ast_during, this, args);
}
Query
during(const std::vector<Query> &args) {
  return init(reql_ast_during, args);
}

Query
AST::epoch_time(const std::vector<Query> &args) const {
  return init(reql_ast_epoch_time, this, args);
}
Query
epoch_time(const std::vector<Query> &args) {
  return init(reql_ast_epoch_time, args);
}

Query
AST::eq(const std::vector<Query> &args) const {
  return init(reql_ast_eq, this, args);
}
Query
eq(const std::vector<Query> &args) {
  return init(reql_ast_eq, args);
}

Query
AST::eq_join(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) const {
  return init(reql_ast_eq_join, this, args, kwargs);
}
Query
eq_join(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) {
  return init(reql_ast_eq_join, args, kwargs);
}
Query
AST::eq_join(const std::vector<Query> &args) const {
  return init(reql_ast_eq_join, this, args);
}
Query
eq_join(const std::vector<Query> &args) {
  return init(reql_ast_eq_join, args);
}

Query
AST::error(const std::vector<Query> &args) const {
  return init(reql_ast_error, this, args);
}
Query
error(const std::vector<Query> &args) {
  return init(reql_ast_error, args);
}

Query
AST::february(const std::vector<Query> &args) const {
  return init(reql_ast_february, this, args);
}
Query
february(const std::vector<Query> &args) {
  return init(reql_ast_february, args);
}

Query
AST::fill(const std::vector<Query> &args) const {
  return init(reql_ast_fill, this, args);
}
Query
fill(const std::vector<Query> &args) {
  return init(reql_ast_fill, args);
}

Query
AST::filter(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) const {
  return init(reql_ast_filter, this, args, kwargs);
}
Query
filter(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) {
  return init(reql_ast_filter, args, kwargs);
}
Query
AST::filter(const std::vector<Query> &args) const {
  return init(reql_ast_filter, this, args);
}
Query
filter(const std::vector<Query> &args) {
  return init(reql_ast_filter, args);
}

Query
AST::floor(const std::vector<Query> &args) const {
  return init(reql_ast_floor, this, args);
}
Query
floor(const std::vector<Query> &args) {
  return init(reql_ast_floor, args);
}

Query
AST::for_each(const std::vector<Query> &args) const {
  return init(reql_ast_for_each, this, args);
}
Query
for_each(const std::vector<Query> &args) {
  return init(reql_ast_for_each, args);
}

Query
AST::friday(const std::vector<Query> &args) const {
  return init(reql_ast_friday, this, args);
}
Query
friday(const std::vector<Query> &args) {
  return init(reql_ast_friday, args);
}

Query
AST::func(const std::vector<Query> &args) const {
  return init(reql_ast_func, this, args);
}
Query
func(const std::vector<Query> &args) {
  return init(reql_ast_func, args);
}

Query
AST::funcall(const std::vector<Query> &args) const {
  return init(reql_ast_funcall, this, args);
}
Query
funcall(const std::vector<Query> &args) {
  return init(reql_ast_funcall, args);
}

Query
AST::ge(const std::vector<Query> &args) const {
  return init(reql_ast_ge, this, args);
}
Query
ge(const std::vector<Query> &args) {
  return init(reql_ast_ge, args);
}

Query
AST::geojson(const std::vector<Query> &args) const {
  return init(reql_ast_geojson, this, args);
}
Query
geojson(const std::vector<Query> &args) {
  return init(reql_ast_geojson, args);
}

Query
AST::get(const std::vector<Query> &args) const {
  return init(reql_ast_get, this, args);
}
Query
get(const std::vector<Query> &args) {
  return init(reql_ast_get, args);
}

Query
AST::get_all(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) const {
  return init(reql_ast_get_all, this, args, kwargs);
}
Query
get_all(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) {
  return init(reql_ast_get_all, args, kwargs);
}
Query
AST::get_all(const std::vector<Query> &args) const {
  return init(reql_ast_get_all, this, args);
}
Query
get_all(const std::vector<Query> &args) {
  return init(reql_ast_get_all, args);
}

Query
AST::get_field(const std::vector<Query> &args) const {
  return init(reql_ast_get_field, this, args);
}
Query
get_field(const std::vector<Query> &args) {
  return init(reql_ast_get_field, args);
}

Query
AST::get_intersecting(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) const {
  return init(reql_ast_get_intersecting, this, args, kwargs);
}
Query
get_intersecting(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) {
  return init(reql_ast_get_intersecting, args, kwargs);
}
Query
AST::get_intersecting(const std::vector<Query> &args) const {
  return init(reql_ast_get_intersecting, this, args);
}
Query
get_intersecting(const std::vector<Query> &args) {
  return init(reql_ast_get_intersecting, args);
}

Query
AST::get_nearest(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) const {
  return init(reql_ast_get_nearest, this, args, kwargs);
}
Query
get_nearest(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) {
  return init(reql_ast_get_nearest, args, kwargs);
}
Query
AST::get_nearest(const std::vector<Query> &args) const {
  return init(reql_ast_get_nearest, this, args);
}
Query
get_nearest(const std::vector<Query> &args) {
  return init(reql_ast_get_nearest, args);
}

Query
AST::group(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) const {
  return init(reql_ast_group, this, args, kwargs);
}
Query
group(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) {
  return init(reql_ast_group, args, kwargs);
}
Query
AST::group(const std::vector<Query> &args) const {
  return init(reql_ast_group, this, args);
}
Query
group(const std::vector<Query> &args) {
  return init(reql_ast_group, args);
}

Query
AST::gt(const std::vector<Query> &args) const {
  return init(reql_ast_gt, this, args);
}
Query
gt(const std::vector<Query> &args) {
  return init(reql_ast_gt, args);
}

Query
AST::has_fields(const std::vector<Query> &args) const {
  return init(reql_ast_has_fields, this, args);
}
Query
has_fields(const std::vector<Query> &args) {
  return init(reql_ast_has_fields, args);
}

Query
AST::hours(const std::vector<Query> &args) const {
  return init(reql_ast_hours, this, args);
}
Query
hours(const std::vector<Query> &args) {
  return init(reql_ast_hours, args);
}

Query
AST::http(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) const {
  return init(reql_ast_http, this, args, kwargs);
}
Query
http(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) {
  return init(reql_ast_http, args, kwargs);
}
Query
AST::http(const std::vector<Query> &args) const {
  return init(reql_ast_http, this, args);
}
Query
http(const std::vector<Query> &args) {
  return init(reql_ast_http, args);
}

Query
AST::implicit_var(const std::vector<Query> &args) const {
  return init(reql_ast_implicit_var, this, args);
}
Query
implicit_var(const std::vector<Query> &args) {
  return init(reql_ast_implicit_var, args);
}

Query
AST::includes(const std::vector<Query> &args) const {
  return init(reql_ast_includes, this, args);
}
Query
includes(const std::vector<Query> &args) {
  return init(reql_ast_includes, args);
}

Query
AST::index_create(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) const {
  return init(reql_ast_index_create, this, args, kwargs);
}
Query
index_create(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) {
  return init(reql_ast_index_create, args, kwargs);
}
Query
AST::index_create(const std::vector<Query> &args) const {
  return init(reql_ast_index_create, this, args);
}
Query
index_create(const std::vector<Query> &args) {
  return init(reql_ast_index_create, args);
}

Query
AST::index_drop(const std::vector<Query> &args) const {
  return init(reql_ast_index_drop, this, args);
}
Query
index_drop(const std::vector<Query> &args) {
  return init(reql_ast_index_drop, args);
}

Query
AST::index_list(const std::vector<Query> &args) const {
  return init(reql_ast_index_list, this, args);
}
Query
index_list(const std::vector<Query> &args) {
  return init(reql_ast_index_list, args);
}

Query
AST::index_rename(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) const {
  return init(reql_ast_index_rename, this, args, kwargs);
}
Query
index_rename(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) {
  return init(reql_ast_index_rename, args, kwargs);
}
Query
AST::index_rename(const std::vector<Query> &args) const {
  return init(reql_ast_index_rename, this, args);
}
Query
index_rename(const std::vector<Query> &args) {
  return init(reql_ast_index_rename, args);
}

Query
AST::index_status(const std::vector<Query> &args) const {
  return init(reql_ast_index_status, this, args);
}
Query
index_status(const std::vector<Query> &args) {
  return init(reql_ast_index_status, args);
}

Query
AST::index_wait(const std::vector<Query> &args) const {
  return init(reql_ast_index_wait, this, args);
}
Query
index_wait(const std::vector<Query> &args) {
  return init(reql_ast_index_wait, args);
}

Query
AST::info(const std::vector<Query> &args) const {
  return init(reql_ast_info, this, args);
}
Query
info(const std::vector<Query> &args) {
  return init(reql_ast_info, args);
}

Query
AST::inner_join(const std::vector<Query> &args) const {
  return init(reql_ast_inner_join, this, args);
}
Query
inner_join(const std::vector<Query> &args) {
  return init(reql_ast_inner_join, args);
}

Query
AST::insert(const std::vector<Query> &args) const {
  return init(reql_ast_insert, this, args);
}
Query
insert(const std::vector<Query> &args) {
  return init(reql_ast_insert, args);
}

Query
AST::insert_at(const std::vector<Query> &args) const {
  return init(reql_ast_insert_at, this, args);
}
Query
insert_at(const std::vector<Query> &args) {
  return init(reql_ast_insert_at, args);
}

Query
AST::intersects(const std::vector<Query> &args) const {
  return init(reql_ast_intersects, this, args);
}
Query
intersects(const std::vector<Query> &args) {
  return init(reql_ast_intersects, args);
}

Query
AST::in_timezone(const std::vector<Query> &args) const {
  return init(reql_ast_in_timezone, this, args);
}
Query
in_timezone(const std::vector<Query> &args) {
  return init(reql_ast_in_timezone, args);
}

Query
AST::iso8601(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) const {
  return init(reql_ast_iso8601, this, args, kwargs);
}
Query
iso8601(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) {
  return init(reql_ast_iso8601, args, kwargs);
}
Query
AST::iso8601(const std::vector<Query> &args) const {
  return init(reql_ast_iso8601, this, args);
}
Query
iso8601(const std::vector<Query> &args) {
  return init(reql_ast_iso8601, args);
}

Query
AST::is_empty(const std::vector<Query> &args) const {
  return init(reql_ast_is_empty, this, args);
}
Query
is_empty(const std::vector<Query> &args) {
  return init(reql_ast_is_empty, args);
}

Query
AST::january(const std::vector<Query> &args) const {
  return init(reql_ast_january, this, args);
}
Query
january(const std::vector<Query> &args) {
  return init(reql_ast_january, args);
}

Query
AST::javascript(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) const {
  return init(reql_ast_javascript, this, args, kwargs);
}
Query
javascript(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) {
  return init(reql_ast_javascript, args, kwargs);
}
Query
AST::javascript(const std::vector<Query> &args) const {
  return init(reql_ast_javascript, this, args);
}
Query
javascript(const std::vector<Query> &args) {
  return init(reql_ast_javascript, args);
}

Query
AST::json(const std::vector<Query> &args) const {
  return init(reql_ast_json, this, args);
}
Query
json(const std::vector<Query> &args) {
  return init(reql_ast_json, args);
}

Query
AST::july(const std::vector<Query> &args) const {
  return init(reql_ast_july, this, args);
}
Query
july(const std::vector<Query> &args) {
  return init(reql_ast_july, args);
}

Query
AST::june(const std::vector<Query> &args) const {
  return init(reql_ast_june, this, args);
}
Query
june(const std::vector<Query> &args) {
  return init(reql_ast_june, args);
}

Query
AST::keys(const std::vector<Query> &args) const {
  return init(reql_ast_keys, this, args);
}
Query
keys(const std::vector<Query> &args) {
  return init(reql_ast_keys, args);
}

Query
AST::le(const std::vector<Query> &args) const {
  return init(reql_ast_le, this, args);
}
Query
le(const std::vector<Query> &args) {
  return init(reql_ast_le, args);
}

Query
AST::limit(const std::vector<Query> &args) const {
  return init(reql_ast_limit, this, args);
}
Query
limit(const std::vector<Query> &args) {
  return init(reql_ast_limit, args);
}

Query
AST::line(const std::vector<Query> &args) const {
  return init(reql_ast_line, this, args);
}
Query
line(const std::vector<Query> &args) {
  return init(reql_ast_line, args);
}

Query
AST::literal(const std::vector<Query> &args) const {
  return init(reql_ast_literal, this, args);
}
Query
literal(const std::vector<Query> &args) {
  return init(reql_ast_literal, args);
}

Query
AST::lt(const std::vector<Query> &args) const {
  return init(reql_ast_lt, this, args);
}
Query
lt(const std::vector<Query> &args) {
  return init(reql_ast_lt, args);
}

Query
AST::make_array(const std::vector<Query> &args) const {
  return init(reql_ast_make_array, this, args);
}
Query
make_array(const std::vector<Query> &args) {
  return init(reql_ast_make_array, args);
}

Query
AST::make_obj(const std::vector<Query> &args) const {
  return init(reql_ast_make_obj, this, args);
}
Query
make_obj(const std::vector<Query> &args) {
  return init(reql_ast_make_obj, args);
}

Query
AST::map(const std::vector<Query> &args) const {
  return init(reql_ast_map, this, args);
}
Query
map(const std::vector<Query> &args) {
  return init(reql_ast_map, args);
}

Query
AST::march(const std::vector<Query> &args) const {
  return init(reql_ast_march, this, args);
}
Query
march(const std::vector<Query> &args) {
  return init(reql_ast_march, args);
}

Query
AST::match(const std::vector<Query> &args) const {
  return init(reql_ast_match, this, args);
}
Query
match(const std::vector<Query> &args) {
  return init(reql_ast_match, args);
}

Query
AST::max(const std::vector<Query> &args) const {
  return init(reql_ast_max, this, args);
}
Query
max(const std::vector<Query> &args) {
  return init(reql_ast_max, args);
}

Query
AST::maxval(const std::vector<Query> &args) const {
  return init(reql_ast_maxval, this, args);
}
Query
maxval(const std::vector<Query> &args) {
  return init(reql_ast_maxval, args);
}

Query
AST::may(const std::vector<Query> &args) const {
  return init(reql_ast_may, this, args);
}
Query
may(const std::vector<Query> &args) {
  return init(reql_ast_may, args);
}

Query
AST::merge(const std::vector<Query> &args) const {
  return init(reql_ast_merge, this, args);
}
Query
merge(const std::vector<Query> &args) {
  return init(reql_ast_merge, args);
}

Query
AST::min(const std::vector<Query> &args) const {
  return init(reql_ast_min, this, args);
}
Query
min(const std::vector<Query> &args) {
  return init(reql_ast_min, args);
}

Query
AST::minutes(const std::vector<Query> &args) const {
  return init(reql_ast_minutes, this, args);
}
Query
minutes(const std::vector<Query> &args) {
  return init(reql_ast_minutes, args);
}

Query
AST::minval(const std::vector<Query> &args) const {
  return init(reql_ast_minval, this, args);
}
Query
minval(const std::vector<Query> &args) {
  return init(reql_ast_minval, args);
}

Query
AST::mod(const std::vector<Query> &args) const {
  return init(reql_ast_mod, this, args);
}
Query
mod(const std::vector<Query> &args) {
  return init(reql_ast_mod, args);
}

Query
AST::monday(const std::vector<Query> &args) const {
  return init(reql_ast_monday, this, args);
}
Query
monday(const std::vector<Query> &args) {
  return init(reql_ast_monday, args);
}

Query
AST::month(const std::vector<Query> &args) const {
  return init(reql_ast_month, this, args);
}
Query
month(const std::vector<Query> &args) {
  return init(reql_ast_month, args);
}

Query
AST::mul(const std::vector<Query> &args) const {
  return init(reql_ast_mul, this, args);
}
Query
mul(const std::vector<Query> &args) {
  return init(reql_ast_mul, args);
}

Query
AST::ne(const std::vector<Query> &args) const {
  return init(reql_ast_ne, this, args);
}
Query
ne(const std::vector<Query> &args) {
  return init(reql_ast_ne, args);
}

Query
AST::not_(const std::vector<Query> &args) const {
  return init(reql_ast_not, this, args);
}
Query
not_(const std::vector<Query> &args) {
  return init(reql_ast_not, args);
}

Query
AST::november(const std::vector<Query> &args) const {
  return init(reql_ast_november, this, args);
}
Query
november(const std::vector<Query> &args) {
  return init(reql_ast_november, args);
}

Query
AST::now(const std::vector<Query> &args) const {
  return init(reql_ast_now, this, args);
}
Query
now(const std::vector<Query> &args) {
  return init(reql_ast_now, args);
}

Query
AST::nth(const std::vector<Query> &args) const {
  return init(reql_ast_nth, this, args);
}
Query
nth(const std::vector<Query> &args) {
  return init(reql_ast_nth, args);
}

Query
AST::object(const std::vector<Query> &args) const {
  return init(reql_ast_object, this, args);
}
Query
object(const std::vector<Query> &args) {
  return init(reql_ast_object, args);
}

Query
AST::october(const std::vector<Query> &args) const {
  return init(reql_ast_october, this, args);
}
Query
october(const std::vector<Query> &args) {
  return init(reql_ast_october, args);
}

Query
AST::offsets_of(const std::vector<Query> &args) const {
  return init(reql_ast_offsets_of, this, args);
}
Query
offsets_of(const std::vector<Query> &args) {
  return init(reql_ast_offsets_of, args);
}

Query
AST::or_(const std::vector<Query> &args) const {
  return init(reql_ast_or, this, args);
}
Query
or_(const std::vector<Query> &args) {
  return init(reql_ast_or, args);
}

Query
AST::order_by(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) const {
  return init(reql_ast_order_by, this, args, kwargs);
}
Query
order_by(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) {
  return init(reql_ast_order_by, args, kwargs);
}
Query
AST::order_by(const std::vector<Query> &args) const {
  return init(reql_ast_order_by, this, args);
}
Query
order_by(const std::vector<Query> &args) {
  return init(reql_ast_order_by, args);
}

Query
AST::outer_join(const std::vector<Query> &args) const {
  return init(reql_ast_outer_join, this, args);
}
Query
outer_join(const std::vector<Query> &args) {
  return init(reql_ast_outer_join, args);
}

Query
AST::pluck(const std::vector<Query> &args) const {
  return init(reql_ast_pluck, this, args);
}
Query
pluck(const std::vector<Query> &args) {
  return init(reql_ast_pluck, args);
}

Query
AST::point(const std::vector<Query> &args) const {
  return init(reql_ast_point, this, args);
}
Query
point(const std::vector<Query> &args) {
  return init(reql_ast_point, args);
}

Query
AST::polygon(const std::vector<Query> &args) const {
  return init(reql_ast_polygon, this, args);
}
Query
polygon(const std::vector<Query> &args) {
  return init(reql_ast_polygon, args);
}

Query
AST::polygon_sub(const std::vector<Query> &args) const {
  return init(reql_ast_polygon_sub, this, args);
}
Query
polygon_sub(const std::vector<Query> &args) {
  return init(reql_ast_polygon_sub, args);
}

Query
AST::prepend(const std::vector<Query> &args) const {
  return init(reql_ast_prepend, this, args);
}
Query
prepend(const std::vector<Query> &args) {
  return init(reql_ast_prepend, args);
}

Query
AST::random(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) const {
  return init(reql_ast_random, this, args, kwargs);
}
Query
random(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) {
  return init(reql_ast_random, args, kwargs);
}
Query
AST::random(const std::vector<Query> &args) const {
  return init(reql_ast_random, this, args);
}
Query
random(const std::vector<Query> &args) {
  return init(reql_ast_random, args);
}

Query
AST::range(const std::vector<Query> &args) const {
  return init(reql_ast_range, this, args);
}
Query
range(const std::vector<Query> &args) {
  return init(reql_ast_range, args);
}

Query
AST::rebalance(const std::vector<Query> &args) const {
  return init(reql_ast_rebalance, this, args);
}
Query
rebalance(const std::vector<Query> &args) {
  return init(reql_ast_rebalance, args);
}

Query
AST::reconfigure(const std::vector<Query> &args) const {
  return init(reql_ast_reconfigure, this, args);
}
Query
reconfigure(const std::vector<Query> &args) {
  return init(reql_ast_reconfigure, args);
}

Query
AST::reduce(const std::vector<Query> &args) const {
  return init(reql_ast_reduce, this, args);
}
Query
reduce(const std::vector<Query> &args) {
  return init(reql_ast_reduce, args);
}

Query
AST::replace(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) const {
  return init(reql_ast_replace, this, args, kwargs);
}
Query
replace(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) {
  return init(reql_ast_replace, args, kwargs);
}
Query
AST::replace(const std::vector<Query> &args) const {
  return init(reql_ast_replace, this, args);
}
Query
replace(const std::vector<Query> &args) {
  return init(reql_ast_replace, args);
}

Query
AST::round(const std::vector<Query> &args) const {
  return init(reql_ast_round, this, args);
}
Query
round(const std::vector<Query> &args) {
  return init(reql_ast_round, args);
}

Query
AST::sample(const std::vector<Query> &args) const {
  return init(reql_ast_sample, this, args);
}
Query
sample(const std::vector<Query> &args) {
  return init(reql_ast_sample, args);
}

Query
AST::saturday(const std::vector<Query> &args) const {
  return init(reql_ast_saturday, this, args);
}
Query
saturday(const std::vector<Query> &args) {
  return init(reql_ast_saturday, args);
}

Query
AST::seconds(const std::vector<Query> &args) const {
  return init(reql_ast_seconds, this, args);
}
Query
seconds(const std::vector<Query> &args) {
  return init(reql_ast_seconds, args);
}

Query
AST::september(const std::vector<Query> &args) const {
  return init(reql_ast_september, this, args);
}
Query
september(const std::vector<Query> &args) {
  return init(reql_ast_september, args);
}

Query
AST::set_difference(const std::vector<Query> &args) const {
  return init(reql_ast_set_difference, this, args);
}
Query
set_difference(const std::vector<Query> &args) {
  return init(reql_ast_set_difference, args);
}

Query
AST::set_insert(const std::vector<Query> &args) const {
  return init(reql_ast_set_insert, this, args);
}
Query
set_insert(const std::vector<Query> &args) {
  return init(reql_ast_set_insert, args);
}

Query
AST::set_intersection(const std::vector<Query> &args) const {
  return init(reql_ast_set_intersection, this, args);
}
Query
set_intersection(const std::vector<Query> &args) {
  return init(reql_ast_set_intersection, args);
}

Query
AST::set_union(const std::vector<Query> &args) const {
  return init(reql_ast_set_union, this, args);
}
Query
set_union(const std::vector<Query> &args) {
  return init(reql_ast_set_union, args);
}

Query
AST::skip(const std::vector<Query> &args) const {
  return init(reql_ast_skip, this, args);
}
Query
skip(const std::vector<Query> &args) {
  return init(reql_ast_skip, args);
}

Query
AST::slice(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) const {
  return init(reql_ast_slice, this, args, kwargs);
}
Query
slice(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) {
  return init(reql_ast_slice, args, kwargs);
}
Query
AST::slice(const std::vector<Query> &args) const {
  return init(reql_ast_slice, this, args);
}
Query
slice(const std::vector<Query> &args) {
  return init(reql_ast_slice, args);
}

Query
AST::splice_at(const std::vector<Query> &args) const {
  return init(reql_ast_splice_at, this, args);
}
Query
splice_at(const std::vector<Query> &args) {
  return init(reql_ast_splice_at, args);
}

Query
AST::split(const std::vector<Query> &args) const {
  return init(reql_ast_split, this, args);
}
Query
split(const std::vector<Query> &args) {
  return init(reql_ast_split, args);
}

Query
AST::status(const std::vector<Query> &args) const {
  return init(reql_ast_status, this, args);
}
Query
status(const std::vector<Query> &args) {
  return init(reql_ast_status, args);
}

Query
AST::sub(const std::vector<Query> &args) const {
  return init(reql_ast_sub, this, args);
}
Query
sub(const std::vector<Query> &args) {
  return init(reql_ast_sub, args);
}

Query
AST::sum(const std::vector<Query> &args) const {
  return init(reql_ast_sum, this, args);
}
Query
sum(const std::vector<Query> &args) {
  return init(reql_ast_sum, args);
}

Query
AST::sunday(const std::vector<Query> &args) const {
  return init(reql_ast_sunday, this, args);
}
Query
sunday(const std::vector<Query> &args) {
  return init(reql_ast_sunday, args);
}

Query
AST::sync(const std::vector<Query> &args) const {
  return init(reql_ast_sync, this, args);
}
Query
sync(const std::vector<Query> &args) {
  return init(reql_ast_sync, args);
}

Query
AST::table(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) const {
  return init(reql_ast_table, this, args, kwargs);
}
Query
table(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) {
  return init(reql_ast_table, args, kwargs);
}
Query
AST::table(const std::vector<Query> &args) const {
  return init(reql_ast_table, this, args);
}
Query
table(const std::vector<Query> &args) {
  return init(reql_ast_table, args);
}

Query
AST::table_create(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) const {
  return init(reql_ast_table_create, this, args, kwargs);
}
Query
table_create(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) {
  return init(reql_ast_table_create, args, kwargs);
}
Query
AST::table_create(const std::vector<Query> &args) const {
  return init(reql_ast_table_create, this, args);
}
Query
table_create(const std::vector<Query> &args) {
  return init(reql_ast_table_create, args);
}

Query
AST::table_drop(const std::vector<Query> &args) const {
  return init(reql_ast_table_drop, this, args);
}
Query
table_drop(const std::vector<Query> &args) {
  return init(reql_ast_table_drop, args);
}

Query
AST::table_list(const std::vector<Query> &args) const {
  return init(reql_ast_table_list, this, args);
}
Query
table_list(const std::vector<Query> &args) {
  return init(reql_ast_table_list, args);
}

Query
AST::thursday(const std::vector<Query> &args) const {
  return init(reql_ast_thursday, this, args);
}
Query
thursday(const std::vector<Query> &args) {
  return init(reql_ast_thursday, args);
}

Query
AST::time(const std::vector<Query> &args) const {
  return init(reql_ast_time, this, args);
}
Query
time(const std::vector<Query> &args) {
  return init(reql_ast_time, args);
}

Query
AST::timezone_(const std::vector<Query> &args) const {
  return init(reql_ast_timezone, this, args);
}
Query
timezone_(const std::vector<Query> &args) {
  return init(reql_ast_timezone, args);
}

Query
AST::time_of_day(const std::vector<Query> &args) const {
  return init(reql_ast_time_of_day, this, args);
}
Query
time_of_day(const std::vector<Query> &args) {
  return init(reql_ast_time_of_day, args);
}

Query
AST::to_epoch_time(const std::vector<Query> &args) const {
  return init(reql_ast_to_epoch_time, this, args);
}
Query
to_epoch_time(const std::vector<Query> &args) {
  return init(reql_ast_to_epoch_time, args);
}

Query
AST::to_geojson(const std::vector<Query> &args) const {
  return init(reql_ast_to_geojson, this, args);
}
Query
to_geojson(const std::vector<Query> &args) {
  return init(reql_ast_to_geojson, args);
}

Query
AST::to_iso8601(const std::vector<Query> &args) const {
  return init(reql_ast_to_iso8601, this, args);
}
Query
to_iso8601(const std::vector<Query> &args) {
  return init(reql_ast_to_iso8601, args);
}

Query
AST::to_json_string(const std::vector<Query> &args) const {
  return init(reql_ast_to_json_string, this, args);
}
Query
to_json_string(const std::vector<Query> &args) {
  return init(reql_ast_to_json_string, args);
}

Query
AST::tuesday(const std::vector<Query> &args) const {
  return init(reql_ast_tuesday, this, args);
}
Query
tuesday(const std::vector<Query> &args) {
  return init(reql_ast_tuesday, args);
}

Query
AST::type_of(const std::vector<Query> &args) const {
  return init(reql_ast_type_of, this, args);
}
Query
type_of(const std::vector<Query> &args) {
  return init(reql_ast_type_of, args);
}

Query
AST::ungroup(const std::vector<Query> &args) const {
  return init(reql_ast_ungroup, this, args);
}
Query
ungroup(const std::vector<Query> &args) {
  return init(reql_ast_ungroup, args);
}

Query
AST::union_(const std::vector<Query> &args) const {
  return init(reql_ast_union, this, args);
}
Query
union_(const std::vector<Query> &args) {
  return init(reql_ast_union, args);
}

Query
AST::upcase(const std::vector<Query> &args) const {
  return init(reql_ast_upcase, this, args);
}
Query
upcase(const std::vector<Query> &args) {
  return init(reql_ast_upcase, args);
}

Query
AST::update(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) const {
  return init(reql_ast_update, this, args, kwargs);
}
Query
update(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) {
  return init(reql_ast_update, args, kwargs);
}
Query
AST::update(const std::vector<Query> &args) const {
  return init(reql_ast_update, this, args);
}
Query
update(const std::vector<Query> &args) {
  return init(reql_ast_update, args);
}

Query
AST::uuid(const std::vector<Query> &args) const {
  return init(reql_ast_uuid, this, args);
}
Query
uuid(const std::vector<Query> &args) {
  return init(reql_ast_uuid, args);
}

Query
AST::var(const std::vector<Query> &args) const {
  return init(reql_ast_var, this, args);
}
Query
var(const std::vector<Query> &args) {
  return init(reql_ast_var, args);
}

Query
AST::wait(const std::vector<Query> &args) const {
  return init(reql_ast_wait, this, args);
}
Query
wait(const std::vector<Query> &args) {
  return init(reql_ast_wait, args);
}

Query
AST::wednesday(const std::vector<Query> &args) const {
  return init(reql_ast_wednesday, this, args);
}
Query
wednesday(const std::vector<Query> &args) {
  return init(reql_ast_wednesday, args);
}

Query
AST::without(const std::vector<Query> &args) const {
  return init(reql_ast_without, this, args);
}
Query
without(const std::vector<Query> &args) {
  return init(reql_ast_without, args);
}

Query
AST::with_fields(const std::vector<Query> &args) const {
  return init(reql_ast_with_fields, this, args);
}
Query
with_fields(const std::vector<Query> &args) {
  return init(reql_ast_with_fields, args);
}

Query
AST::year(const std::vector<Query> &args) const {
  return init(reql_ast_year, this, args);
}
Query
year(const std::vector<Query> &args) {
  return init(reql_ast_year, args);
}

Query
AST::zip(const std::vector<Query> &args) const {
  return init(reql_ast_zip, this, args);
}
Query
zip(const std::vector<Query> &args) {
  return init(reql_ast_zip, args);
}

}  // namespace ReQL
