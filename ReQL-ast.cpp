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

#include "ReQL-ast.hpp"

#include "ReQL.hpp"

namespace ReQL {

static Query
init(ReQL_AST_Function f, std::vector<Query> &args, std::map<std::string, Query> &kwargs) {
  return Query(f, args, kwargs);
}

static Query
init(ReQL_AST_Function f, AST *term, std::vector<Query> &args, std::map<std::string, Query> &kwargs) {
  args.insert(args.cbegin(), dynamic_cast<Expr*>(term));
  return init(f, args, kwargs);
}

static Query
init(ReQL_AST_Function f, std::vector<Query> &args) {
  std::map<std::string, Query> kwargs;
  return init(f, args, kwargs);
}

static Query
init(ReQL_AST_Function f, AST *term, std::vector<Query> &args) {
  std::map<std::string, Query> kwargs;
  return init(f, term, args, kwargs);
}

Query
AST::add(std::vector<Query> args) {
  return init(reql_ast_add, this, args);
}
Query
add(std::vector<Query> args) {
  return init(reql_ast_add, args);
}

Query
AST::all(std::vector<Query> args) {
  return init(reql_ast_all, this, args);
}
Query
all(std::vector<Query> args) {
  return init(reql_ast_all, args);
}

Query
AST::any(std::vector<Query> args) {
  return init(reql_ast_any, this, args);
}
Query
any(std::vector<Query> args) {
  return init(reql_ast_any, args);
}

Query
AST::append(std::vector<Query> args) {
  return init(reql_ast_append, this, args);
}
Query
append(std::vector<Query> args) {
  return init(reql_ast_append, args);
}

Query
AST::april(std::vector<Query> args) {
  return init(reql_ast_april, this, args);
}
Query
april(std::vector<Query> args) {
  return init(reql_ast_april, args);
}

Query
AST::args(std::vector<Query> args) {
  return init(reql_ast_args, this, args);
}
Query
args(std::vector<Query> args) {
  return init(reql_ast_args, args);
}

Query
AST::asc(std::vector<Query> args) {
  return init(reql_ast_asc, this, args);
}
Query
asc(std::vector<Query> args) {
  return init(reql_ast_asc, args);
}

Query
AST::august(std::vector<Query> args) {
  return init(reql_ast_august, this, args);
}
Query
august(std::vector<Query> args) {
  return init(reql_ast_august, args);
}

Query
AST::avg(std::vector<Query> args) {
  return init(reql_ast_avg, this, args);
}
Query
avg(std::vector<Query> args) {
  return init(reql_ast_avg, args);
}

Query
AST::between(std::vector<Query> args) {
  return init(reql_ast_between, this, args);
}
Query
between(std::vector<Query> args) {
  return init(reql_ast_between, args);
}

Query
AST::binary(std::vector<Query> args) {
  return init(reql_ast_binary, this, args);
}
Query
binary(std::vector<Query> args) {
  return init(reql_ast_binary, args);
}

Query
AST::bracket(std::vector<Query> args) {
  return init(reql_ast_bracket, this, args);
}
Query
bracket(std::vector<Query> args) {
  return init(reql_ast_bracket, args);
}

Query
AST::branch(std::vector<Query> args) {
  return init(reql_ast_branch, this, args);
}
Query
branch(std::vector<Query> args) {
  return init(reql_ast_branch, args);
}

Query
AST::changes(std::vector<Query> args) {
  return init(reql_ast_changes, this, args);
}
Query
changes(std::vector<Query> args) {
  return init(reql_ast_changes, args);
}

Query
AST::change_at(std::vector<Query> args) {
  return init(reql_ast_change_at, this, args);
}
Query
change_at(std::vector<Query> args) {
  return init(reql_ast_change_at, args);
}

Query
AST::circle(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(reql_ast_circle, this, args, kwargs);
}
Query
circle(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(reql_ast_circle, args, kwargs);
}
Query
AST::circle(std::vector<Query> args) {
  return init(reql_ast_circle, this, args);
}
Query
circle(std::vector<Query> args) {
  return init(reql_ast_circle, args);
}

Query
AST::coerce_to(std::vector<Query> args) {
  return init(reql_ast_coerce_to, this, args);
}
Query
coerce_to(std::vector<Query> args) {
  return init(reql_ast_coerce_to, args);
}

Query
AST::concat_map(std::vector<Query> args) {
  return init(reql_ast_concat_map, this, args);
}
Query
concat_map(std::vector<Query> args) {
  return init(reql_ast_concat_map, args);
}

Query
AST::config(std::vector<Query> args) {
  return init(reql_ast_config, this, args);
}
Query
config(std::vector<Query> args) {
  return init(reql_ast_config, args);
}

Query
AST::contains(std::vector<Query> args) {
  return init(reql_ast_contains, this, args);
}
Query
contains(std::vector<Query> args) {
  return init(reql_ast_contains, args);
}

Query
AST::count(std::vector<Query> args) {
  return init(reql_ast_count, this, args);
}
Query
count(std::vector<Query> args) {
  return init(reql_ast_count, args);
}

Query
AST::date(std::vector<Query> args) {
  return init(reql_ast_date, this, args);
}
Query
date(std::vector<Query> args) {
  return init(reql_ast_date, args);
}

Query
AST::datum(std::vector<Query> args) {
  return init(reql_ast_datum, this, args);
}
Query
datum(std::vector<Query> args) {
  return init(reql_ast_datum, args);
}

Query
AST::day(std::vector<Query> args) {
  return init(reql_ast_day, this, args);
}
Query
day(std::vector<Query> args) {
  return init(reql_ast_day, args);
}

Query
AST::day_of_week(std::vector<Query> args) {
  return init(reql_ast_day_of_week, this, args);
}
Query
day_of_week(std::vector<Query> args) {
  return init(reql_ast_day_of_week, args);
}

Query
AST::day_of_year(std::vector<Query> args) {
  return init(reql_ast_day_of_year, this, args);
}
Query
day_of_year(std::vector<Query> args) {
  return init(reql_ast_day_of_year, args);
}

Query
AST::db(std::vector<Query> args) {
  return init(reql_ast_db, this, args);
}
Query
db(std::vector<Query> args) {
  return init(reql_ast_db, args);
}

Query
AST::db_create(std::vector<Query> args) {
  return init(reql_ast_db_create, this, args);
}
Query
db_create(std::vector<Query> args) {
  return init(reql_ast_db_create, args);
}

Query
AST::db_drop(std::vector<Query> args) {
  return init(reql_ast_db_drop, this, args);
}
Query
db_drop(std::vector<Query> args) {
  return init(reql_ast_db_drop, args);
}

Query
AST::db_list(std::vector<Query> args) {
  return init(reql_ast_db_list, this, args);
}
Query
db_list(std::vector<Query> args) {
  return init(reql_ast_db_list, args);
}

Query
AST::december(std::vector<Query> args) {
  return init(reql_ast_december, this, args);
}
Query
december(std::vector<Query> args) {
  return init(reql_ast_december, args);
}

Query
AST::default_(std::vector<Query> args) {
  return init(reql_ast_default, this, args);
}
Query
default_(std::vector<Query> args) {
  return init(reql_ast_default, args);
}

Query
AST::delete_(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(reql_ast_delete, this, args, kwargs);
}
Query
delete_(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(reql_ast_delete, args, kwargs);
}
Query
AST::delete_(std::vector<Query> args) {
  return init(reql_ast_delete, this, args);
}
Query
delete_(std::vector<Query> args) {
  return init(reql_ast_delete, args);
}

Query
AST::delete_at(std::vector<Query> args) {
  return init(reql_ast_delete_at, this, args);
}
Query
delete_at(std::vector<Query> args) {
  return init(reql_ast_delete_at, args);
}

Query
AST::desc(std::vector<Query> args) {
  return init(reql_ast_desc, this, args);
}
Query
desc(std::vector<Query> args) {
  return init(reql_ast_desc, args);
}

Query
AST::difference(std::vector<Query> args) {
  return init(reql_ast_difference, this, args);
}
Query
difference(std::vector<Query> args) {
  return init(reql_ast_difference, args);
}

Query
AST::distance(std::vector<Query> args) {
  return init(reql_ast_distance, this, args);
}
Query
distance(std::vector<Query> args) {
  return init(reql_ast_distance, args);
}

Query
AST::distinct(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(reql_ast_distinct, this, args, kwargs);
}
Query
distinct(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(reql_ast_distinct, args, kwargs);
}
Query
AST::distinct(std::vector<Query> args) {
  return init(reql_ast_distinct, this, args);
}
Query
distinct(std::vector<Query> args) {
  return init(reql_ast_distinct, args);
}

Query
AST::div(std::vector<Query> args) {
  return init(reql_ast_div, this, args);
}
Query
div(std::vector<Query> args) {
  return init(reql_ast_div, args);
}

Query
AST::downcase(std::vector<Query> args) {
  return init(reql_ast_downcase, this, args);
}
Query
downcase(std::vector<Query> args) {
  return init(reql_ast_downcase, args);
}

Query
AST::during(std::vector<Query> args) {
  return init(reql_ast_during, this, args);
}
Query
during(std::vector<Query> args) {
  return init(reql_ast_during, args);
}

Query
AST::epoch_time(std::vector<Query> args) {
  return init(reql_ast_epoch_time, this, args);
}
Query
epoch_time(std::vector<Query> args) {
  return init(reql_ast_epoch_time, args);
}

Query
AST::eq(std::vector<Query> args) {
  return init(reql_ast_eq, this, args);
}
Query
eq(std::vector<Query> args) {
  return init(reql_ast_eq, args);
}

Query
AST::eq_join(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(reql_ast_eq_join, this, args, kwargs);
}
Query
eq_join(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(reql_ast_eq_join, args, kwargs);
}
Query
AST::eq_join(std::vector<Query> args) {
  return init(reql_ast_eq_join, this, args);
}
Query
eq_join(std::vector<Query> args) {
  return init(reql_ast_eq_join, args);
}

Query
AST::error(std::vector<Query> args) {
  return init(reql_ast_error, this, args);
}
Query
error(std::vector<Query> args) {
  return init(reql_ast_error, args);
}

Query
AST::february(std::vector<Query> args) {
  return init(reql_ast_february, this, args);
}
Query
february(std::vector<Query> args) {
  return init(reql_ast_february, args);
}

Query
AST::fill(std::vector<Query> args) {
  return init(reql_ast_fill, this, args);
}
Query
fill(std::vector<Query> args) {
  return init(reql_ast_fill, args);
}

Query
AST::filter(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(reql_ast_filter, this, args, kwargs);
}
Query
filter(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(reql_ast_filter, args, kwargs);
}
Query
AST::filter(std::vector<Query> args) {
  return init(reql_ast_filter, this, args);
}
Query
filter(std::vector<Query> args) {
  return init(reql_ast_filter, args);
}

Query
AST::for_each(std::vector<Query> args) {
  return init(reql_ast_for_each, this, args);
}
Query
for_each(std::vector<Query> args) {
  return init(reql_ast_for_each, args);
}

Query
AST::friday(std::vector<Query> args) {
  return init(reql_ast_friday, this, args);
}
Query
friday(std::vector<Query> args) {
  return init(reql_ast_friday, args);
}

Query
AST::func(std::vector<Query> args) {
  return init(reql_ast_func, this, args);
}
Query
func(std::vector<Query> args) {
  return init(reql_ast_func, args);
}

Query
AST::funcall(std::vector<Query> args) {
  return init(reql_ast_funcall, this, args);
}
Query
funcall(std::vector<Query> args) {
  return init(reql_ast_funcall, args);
}

Query
AST::ge(std::vector<Query> args) {
  return init(reql_ast_ge, this, args);
}
Query
ge(std::vector<Query> args) {
  return init(reql_ast_ge, args);
}

Query
AST::geojson(std::vector<Query> args) {
  return init(reql_ast_geojson, this, args);
}
Query
geojson(std::vector<Query> args) {
  return init(reql_ast_geojson, args);
}

Query
AST::get(std::vector<Query> args) {
  return init(reql_ast_get, this, args);
}
Query
get(std::vector<Query> args) {
  return init(reql_ast_get, args);
}

Query
AST::get_all(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(reql_ast_get_all, this, args, kwargs);
}
Query
get_all(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(reql_ast_get_all, args, kwargs);
}
Query
AST::get_all(std::vector<Query> args) {
  return init(reql_ast_get_all, this, args);
}
Query
get_all(std::vector<Query> args) {
  return init(reql_ast_get_all, args);
}

Query
AST::get_field(std::vector<Query> args) {
  return init(reql_ast_get_field, this, args);
}
Query
get_field(std::vector<Query> args) {
  return init(reql_ast_get_field, args);
}

Query
AST::get_intersecting(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(reql_ast_get_intersecting, this, args, kwargs);
}
Query
get_intersecting(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(reql_ast_get_intersecting, args, kwargs);
}
Query
AST::get_intersecting(std::vector<Query> args) {
  return init(reql_ast_get_intersecting, this, args);
}
Query
get_intersecting(std::vector<Query> args) {
  return init(reql_ast_get_intersecting, args);
}

Query
AST::get_nearest(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(reql_ast_get_nearest, this, args, kwargs);
}
Query
get_nearest(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(reql_ast_get_nearest, args, kwargs);
}
Query
AST::get_nearest(std::vector<Query> args) {
  return init(reql_ast_get_nearest, this, args);
}
Query
get_nearest(std::vector<Query> args) {
  return init(reql_ast_get_nearest, args);
}

Query
AST::group(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(reql_ast_group, this, args, kwargs);
}
Query
group(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(reql_ast_group, args, kwargs);
}
Query
AST::group(std::vector<Query> args) {
  return init(reql_ast_group, this, args);
}
Query
group(std::vector<Query> args) {
  return init(reql_ast_group, args);
}

Query
AST::gt(std::vector<Query> args) {
  return init(reql_ast_gt, this, args);
}
Query
gt(std::vector<Query> args) {
  return init(reql_ast_gt, args);
}

Query
AST::has_fields(std::vector<Query> args) {
  return init(reql_ast_has_fields, this, args);
}
Query
has_fields(std::vector<Query> args) {
  return init(reql_ast_has_fields, args);
}

Query
AST::hours(std::vector<Query> args) {
  return init(reql_ast_hours, this, args);
}
Query
hours(std::vector<Query> args) {
  return init(reql_ast_hours, args);
}

Query
AST::http(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(reql_ast_http, this, args, kwargs);
}
Query
http(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(reql_ast_http, args, kwargs);
}
Query
AST::http(std::vector<Query> args) {
  return init(reql_ast_http, this, args);
}
Query
http(std::vector<Query> args) {
  return init(reql_ast_http, args);
}

Query
AST::implicit_var(std::vector<Query> args) {
  return init(reql_ast_implicit_var, this, args);
}
Query
implicit_var(std::vector<Query> args) {
  return init(reql_ast_implicit_var, args);
}

Query
AST::includes(std::vector<Query> args) {
  return init(reql_ast_includes, this, args);
}
Query
includes(std::vector<Query> args) {
  return init(reql_ast_includes, args);
}

Query
AST::indexes_of(std::vector<Query> args) {
  return init(reql_ast_indexes_of, this, args);
}
Query
indexes_of(std::vector<Query> args) {
  return init(reql_ast_indexes_of, args);
}

Query
AST::index_create(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(reql_ast_index_create, this, args, kwargs);
}
Query
index_create(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(reql_ast_index_create, args, kwargs);
}
Query
AST::index_create(std::vector<Query> args) {
  return init(reql_ast_index_create, this, args);
}
Query
index_create(std::vector<Query> args) {
  return init(reql_ast_index_create, args);
}

Query
AST::index_drop(std::vector<Query> args) {
  return init(reql_ast_index_drop, this, args);
}
Query
index_drop(std::vector<Query> args) {
  return init(reql_ast_index_drop, args);
}

Query
AST::index_list(std::vector<Query> args) {
  return init(reql_ast_index_list, this, args);
}
Query
index_list(std::vector<Query> args) {
  return init(reql_ast_index_list, args);
}

Query
AST::index_rename(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(reql_ast_index_rename, this, args, kwargs);
}
Query
index_rename(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(reql_ast_index_rename, args, kwargs);
}
Query
AST::index_rename(std::vector<Query> args) {
  return init(reql_ast_index_rename, this, args);
}
Query
index_rename(std::vector<Query> args) {
  return init(reql_ast_index_rename, args);
}

Query
AST::index_status(std::vector<Query> args) {
  return init(reql_ast_index_status, this, args);
}
Query
index_status(std::vector<Query> args) {
  return init(reql_ast_index_status, args);
}

Query
AST::index_wait(std::vector<Query> args) {
  return init(reql_ast_index_wait, this, args);
}
Query
index_wait(std::vector<Query> args) {
  return init(reql_ast_index_wait, args);
}

Query
AST::info(std::vector<Query> args) {
  return init(reql_ast_info, this, args);
}
Query
info(std::vector<Query> args) {
  return init(reql_ast_info, args);
}

Query
AST::inner_join(std::vector<Query> args) {
  return init(reql_ast_inner_join, this, args);
}
Query
inner_join(std::vector<Query> args) {
  return init(reql_ast_inner_join, args);
}

Query
AST::insert(std::vector<Query> args) {
  return init(reql_ast_insert, this, args);
}
Query
insert(std::vector<Query> args) {
  return init(reql_ast_insert, args);
}

Query
AST::insert_at(std::vector<Query> args) {
  return init(reql_ast_insert_at, this, args);
}
Query
insert_at(std::vector<Query> args) {
  return init(reql_ast_insert_at, args);
}

Query
AST::intersects(std::vector<Query> args) {
  return init(reql_ast_intersects, this, args);
}
Query
intersects(std::vector<Query> args) {
  return init(reql_ast_intersects, args);
}

Query
AST::in_timezone(std::vector<Query> args) {
  return init(reql_ast_in_timezone, this, args);
}
Query
in_timezone(std::vector<Query> args) {
  return init(reql_ast_in_timezone, args);
}

Query
AST::iso8601(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(reql_ast_iso8601, this, args, kwargs);
}
Query
iso8601(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(reql_ast_iso8601, args, kwargs);
}
Query
AST::iso8601(std::vector<Query> args) {
  return init(reql_ast_iso8601, this, args);
}
Query
iso8601(std::vector<Query> args) {
  return init(reql_ast_iso8601, args);
}

Query
AST::is_empty(std::vector<Query> args) {
  return init(reql_ast_is_empty, this, args);
}
Query
is_empty(std::vector<Query> args) {
  return init(reql_ast_is_empty, args);
}

Query
AST::january(std::vector<Query> args) {
  return init(reql_ast_january, this, args);
}
Query
january(std::vector<Query> args) {
  return init(reql_ast_january, args);
}

Query
AST::javascript(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(reql_ast_javascript, this, args, kwargs);
}
Query
javascript(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(reql_ast_javascript, args, kwargs);
}
Query
AST::javascript(std::vector<Query> args) {
  return init(reql_ast_javascript, this, args);
}
Query
javascript(std::vector<Query> args) {
  return init(reql_ast_javascript, args);
}

Query
AST::json(std::vector<Query> args) {
  return init(reql_ast_json, this, args);
}
Query
json(std::vector<Query> args) {
  return init(reql_ast_json, args);
}

Query
AST::july(std::vector<Query> args) {
  return init(reql_ast_july, this, args);
}
Query
july(std::vector<Query> args) {
  return init(reql_ast_july, args);
}

Query
AST::june(std::vector<Query> args) {
  return init(reql_ast_june, this, args);
}
Query
june(std::vector<Query> args) {
  return init(reql_ast_june, args);
}

Query
AST::keys(std::vector<Query> args) {
  return init(reql_ast_keys, this, args);
}
Query
keys(std::vector<Query> args) {
  return init(reql_ast_keys, args);
}

Query
AST::le(std::vector<Query> args) {
  return init(reql_ast_le, this, args);
}
Query
le(std::vector<Query> args) {
  return init(reql_ast_le, args);
}

Query
AST::limit(std::vector<Query> args) {
  return init(reql_ast_limit, this, args);
}
Query
limit(std::vector<Query> args) {
  return init(reql_ast_limit, args);
}

Query
AST::line(std::vector<Query> args) {
  return init(reql_ast_line, this, args);
}
Query
line(std::vector<Query> args) {
  return init(reql_ast_line, args);
}

Query
AST::literal(std::vector<Query> args) {
  return init(reql_ast_literal, this, args);
}
Query
literal(std::vector<Query> args) {
  return init(reql_ast_literal, args);
}

Query
AST::lt(std::vector<Query> args) {
  return init(reql_ast_lt, this, args);
}
Query
lt(std::vector<Query> args) {
  return init(reql_ast_lt, args);
}

Query
AST::make_array(std::vector<Query> args) {
  return init(reql_ast_make_array, this, args);
}
Query
make_array(std::vector<Query> args) {
  return init(reql_ast_make_array, args);
}

Query
AST::make_obj(std::vector<Query> args) {
  return init(reql_ast_make_obj, this, args);
}
Query
make_obj(std::vector<Query> args) {
  return init(reql_ast_make_obj, args);
}

Query
AST::map(std::vector<Query> args) {
  return init(reql_ast_map, this, args);
}
Query
map(std::vector<Query> args) {
  return init(reql_ast_map, args);
}

Query
AST::march(std::vector<Query> args) {
  return init(reql_ast_march, this, args);
}
Query
march(std::vector<Query> args) {
  return init(reql_ast_march, args);
}

Query
AST::match(std::vector<Query> args) {
  return init(reql_ast_match, this, args);
}
Query
match(std::vector<Query> args) {
  return init(reql_ast_match, args);
}

Query
AST::max(std::vector<Query> args) {
  return init(reql_ast_max, this, args);
}
Query
max(std::vector<Query> args) {
  return init(reql_ast_max, args);
}

Query
AST::may(std::vector<Query> args) {
  return init(reql_ast_may, this, args);
}
Query
may(std::vector<Query> args) {
  return init(reql_ast_may, args);
}

Query
AST::merge(std::vector<Query> args) {
  return init(reql_ast_merge, this, args);
}
Query
merge(std::vector<Query> args) {
  return init(reql_ast_merge, args);
}

Query
AST::min(std::vector<Query> args) {
  return init(reql_ast_min, this, args);
}
Query
min(std::vector<Query> args) {
  return init(reql_ast_min, args);
}

Query
AST::minutes(std::vector<Query> args) {
  return init(reql_ast_minutes, this, args);
}
Query
minutes(std::vector<Query> args) {
  return init(reql_ast_minutes, args);
}

Query
AST::mod(std::vector<Query> args) {
  return init(reql_ast_mod, this, args);
}
Query
mod(std::vector<Query> args) {
  return init(reql_ast_mod, args);
}

Query
AST::monday(std::vector<Query> args) {
  return init(reql_ast_monday, this, args);
}
Query
monday(std::vector<Query> args) {
  return init(reql_ast_monday, args);
}

Query
AST::month(std::vector<Query> args) {
  return init(reql_ast_month, this, args);
}
Query
month(std::vector<Query> args) {
  return init(reql_ast_month, args);
}

Query
AST::mul(std::vector<Query> args) {
  return init(reql_ast_mul, this, args);
}
Query
mul(std::vector<Query> args) {
  return init(reql_ast_mul, args);
}

Query
AST::ne(std::vector<Query> args) {
  return init(reql_ast_ne, this, args);
}
Query
ne(std::vector<Query> args) {
  return init(reql_ast_ne, args);
}

Query
AST::not_(std::vector<Query> args) {
  return init(reql_ast_not, this, args);
}
Query
not_(std::vector<Query> args) {
  return init(reql_ast_not, args);
}

Query
AST::november(std::vector<Query> args) {
  return init(reql_ast_november, this, args);
}
Query
november(std::vector<Query> args) {
  return init(reql_ast_november, args);
}

Query
AST::now(std::vector<Query> args) {
  return init(reql_ast_now, this, args);
}
Query
now(std::vector<Query> args) {
  return init(reql_ast_now, args);
}

Query
AST::nth(std::vector<Query> args) {
  return init(reql_ast_nth, this, args);
}
Query
nth(std::vector<Query> args) {
  return init(reql_ast_nth, args);
}

Query
AST::object(std::vector<Query> args) {
  return init(reql_ast_object, this, args);
}
Query
object(std::vector<Query> args) {
  return init(reql_ast_object, args);
}

Query
AST::october(std::vector<Query> args) {
  return init(reql_ast_october, this, args);
}
Query
october(std::vector<Query> args) {
  return init(reql_ast_october, args);
}

Query
AST::order_by(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(reql_ast_order_by, this, args, kwargs);
}
Query
order_by(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(reql_ast_order_by, args, kwargs);
}
Query
AST::order_by(std::vector<Query> args) {
  return init(reql_ast_order_by, this, args);
}
Query
order_by(std::vector<Query> args) {
  return init(reql_ast_order_by, args);
}

Query
AST::outer_join(std::vector<Query> args) {
  return init(reql_ast_outer_join, this, args);
}
Query
outer_join(std::vector<Query> args) {
  return init(reql_ast_outer_join, args);
}

Query
AST::pluck(std::vector<Query> args) {
  return init(reql_ast_pluck, this, args);
}
Query
pluck(std::vector<Query> args) {
  return init(reql_ast_pluck, args);
}

Query
AST::point(std::vector<Query> args) {
  return init(reql_ast_point, this, args);
}
Query
point(std::vector<Query> args) {
  return init(reql_ast_point, args);
}

Query
AST::polygon(std::vector<Query> args) {
  return init(reql_ast_polygon, this, args);
}
Query
polygon(std::vector<Query> args) {
  return init(reql_ast_polygon, args);
}

Query
AST::polygon_sub(std::vector<Query> args) {
  return init(reql_ast_polygon_sub, this, args);
}
Query
polygon_sub(std::vector<Query> args) {
  return init(reql_ast_polygon_sub, args);
}

Query
AST::prepend(std::vector<Query> args) {
  return init(reql_ast_prepend, this, args);
}
Query
prepend(std::vector<Query> args) {
  return init(reql_ast_prepend, args);
}

Query
AST::random(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(reql_ast_random, this, args, kwargs);
}
Query
random(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(reql_ast_random, args, kwargs);
}
Query
AST::random(std::vector<Query> args) {
  return init(reql_ast_random, this, args);
}
Query
random(std::vector<Query> args) {
  return init(reql_ast_random, args);
}

Query
AST::range(std::vector<Query> args) {
  return init(reql_ast_range, this, args);
}
Query
range(std::vector<Query> args) {
  return init(reql_ast_range, args);
}

Query
AST::rebalance(std::vector<Query> args) {
  return init(reql_ast_rebalance, this, args);
}
Query
rebalance(std::vector<Query> args) {
  return init(reql_ast_rebalance, args);
}

Query
AST::reconfigure(std::vector<Query> args) {
  return init(reql_ast_reconfigure, this, args);
}
Query
reconfigure(std::vector<Query> args) {
  return init(reql_ast_reconfigure, args);
}

Query
AST::reduce(std::vector<Query> args) {
  return init(reql_ast_reduce, this, args);
}
Query
reduce(std::vector<Query> args) {
  return init(reql_ast_reduce, args);
}

Query
AST::replace(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(reql_ast_replace, this, args, kwargs);
}
Query
replace(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(reql_ast_replace, args, kwargs);
}
Query
AST::replace(std::vector<Query> args) {
  return init(reql_ast_replace, this, args);
}
Query
replace(std::vector<Query> args) {
  return init(reql_ast_replace, args);
}

Query
AST::sample(std::vector<Query> args) {
  return init(reql_ast_sample, this, args);
}
Query
sample(std::vector<Query> args) {
  return init(reql_ast_sample, args);
}

Query
AST::saturday(std::vector<Query> args) {
  return init(reql_ast_saturday, this, args);
}
Query
saturday(std::vector<Query> args) {
  return init(reql_ast_saturday, args);
}

Query
AST::seconds(std::vector<Query> args) {
  return init(reql_ast_seconds, this, args);
}
Query
seconds(std::vector<Query> args) {
  return init(reql_ast_seconds, args);
}

Query
AST::september(std::vector<Query> args) {
  return init(reql_ast_september, this, args);
}
Query
september(std::vector<Query> args) {
  return init(reql_ast_september, args);
}

Query
AST::set_difference(std::vector<Query> args) {
  return init(reql_ast_set_difference, this, args);
}
Query
set_difference(std::vector<Query> args) {
  return init(reql_ast_set_difference, args);
}

Query
AST::set_insert(std::vector<Query> args) {
  return init(reql_ast_set_insert, this, args);
}
Query
set_insert(std::vector<Query> args) {
  return init(reql_ast_set_insert, args);
}

Query
AST::set_intersection(std::vector<Query> args) {
  return init(reql_ast_set_intersection, this, args);
}
Query
set_intersection(std::vector<Query> args) {
  return init(reql_ast_set_intersection, args);
}

Query
AST::set_union(std::vector<Query> args) {
  return init(reql_ast_set_union, this, args);
}
Query
set_union(std::vector<Query> args) {
  return init(reql_ast_set_union, args);
}

Query
AST::skip(std::vector<Query> args) {
  return init(reql_ast_skip, this, args);
}
Query
skip(std::vector<Query> args) {
  return init(reql_ast_skip, args);
}

Query
AST::slice(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(reql_ast_slice, this, args, kwargs);
}
Query
slice(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(reql_ast_slice, args, kwargs);
}
Query
AST::slice(std::vector<Query> args) {
  return init(reql_ast_slice, this, args);
}
Query
slice(std::vector<Query> args) {
  return init(reql_ast_slice, args);
}

Query
AST::splice_at(std::vector<Query> args) {
  return init(reql_ast_splice_at, this, args);
}
Query
splice_at(std::vector<Query> args) {
  return init(reql_ast_splice_at, args);
}

Query
AST::split(std::vector<Query> args) {
  return init(reql_ast_split, this, args);
}
Query
split(std::vector<Query> args) {
  return init(reql_ast_split, args);
}

Query
AST::status(std::vector<Query> args) {
  return init(reql_ast_status, this, args);
}
Query
status(std::vector<Query> args) {
  return init(reql_ast_status, args);
}

Query
AST::sub(std::vector<Query> args) {
  return init(reql_ast_sub, this, args);
}
Query
sub(std::vector<Query> args) {
  return init(reql_ast_sub, args);
}

Query
AST::sum(std::vector<Query> args) {
  return init(reql_ast_sum, this, args);
}
Query
sum(std::vector<Query> args) {
  return init(reql_ast_sum, args);
}

Query
AST::sunday(std::vector<Query> args) {
  return init(reql_ast_sunday, this, args);
}
Query
sunday(std::vector<Query> args) {
  return init(reql_ast_sunday, args);
}

Query
AST::sync(std::vector<Query> args) {
  return init(reql_ast_sync, this, args);
}
Query
sync(std::vector<Query> args) {
  return init(reql_ast_sync, args);
}

Query
AST::table(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(reql_ast_table, this, args, kwargs);
}
Query
table(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(reql_ast_table, args, kwargs);
}
Query
AST::table(std::vector<Query> args) {
  return init(reql_ast_table, this, args);
}
Query
table(std::vector<Query> args) {
  return init(reql_ast_table, args);
}

Query
AST::table_create(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(reql_ast_table_create, this, args, kwargs);
}
Query
table_create(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(reql_ast_table_create, args, kwargs);
}
Query
AST::table_create(std::vector<Query> args) {
  return init(reql_ast_table_create, this, args);
}
Query
table_create(std::vector<Query> args) {
  return init(reql_ast_table_create, args);
}

Query
AST::table_drop(std::vector<Query> args) {
  return init(reql_ast_table_drop, this, args);
}
Query
table_drop(std::vector<Query> args) {
  return init(reql_ast_table_drop, args);
}

Query
AST::table_list(std::vector<Query> args) {
  return init(reql_ast_table_list, this, args);
}
Query
table_list(std::vector<Query> args) {
  return init(reql_ast_table_list, args);
}

Query
AST::thursday(std::vector<Query> args) {
  return init(reql_ast_thursday, this, args);
}
Query
thursday(std::vector<Query> args) {
  return init(reql_ast_thursday, args);
}

Query
AST::time(std::vector<Query> args) {
  return init(reql_ast_time, this, args);
}
Query
time(std::vector<Query> args) {
  return init(reql_ast_time, args);
}

Query
AST::timezone_(std::vector<Query> args) {
  return init(reql_ast_timezone, this, args);
}
Query
timezone_(std::vector<Query> args) {
  return init(reql_ast_timezone, args);
}

Query
AST::time_of_day(std::vector<Query> args) {
  return init(reql_ast_time_of_day, this, args);
}
Query
time_of_day(std::vector<Query> args) {
  return init(reql_ast_time_of_day, args);
}

Query
AST::to_epoch_time(std::vector<Query> args) {
  return init(reql_ast_to_epoch_time, this, args);
}
Query
to_epoch_time(std::vector<Query> args) {
  return init(reql_ast_to_epoch_time, args);
}

Query
AST::to_geojson(std::vector<Query> args) {
  return init(reql_ast_to_geojson, this, args);
}
Query
to_geojson(std::vector<Query> args) {
  return init(reql_ast_to_geojson, args);
}

Query
AST::to_iso8601(std::vector<Query> args) {
  return init(reql_ast_to_iso8601, this, args);
}
Query
to_iso8601(std::vector<Query> args) {
  return init(reql_ast_to_iso8601, args);
}

Query
AST::to_json_string(std::vector<Query> args) {
  return init(reql_ast_to_json_string, this, args);
}
Query
to_json_string(std::vector<Query> args) {
  return init(reql_ast_to_json_string, args);
}

Query
AST::tuesday(std::vector<Query> args) {
  return init(reql_ast_tuesday, this, args);
}
Query
tuesday(std::vector<Query> args) {
  return init(reql_ast_tuesday, args);
}

Query
AST::type_of(std::vector<Query> args) {
  return init(reql_ast_type_of, this, args);
}
Query
type_of(std::vector<Query> args) {
  return init(reql_ast_type_of, args);
}

Query
AST::ungroup(std::vector<Query> args) {
  return init(reql_ast_ungroup, this, args);
}
Query
ungroup(std::vector<Query> args) {
  return init(reql_ast_ungroup, args);
}

Query
AST::union_(std::vector<Query> args) {
  return init(reql_ast_union, this, args);
}
Query
union_(std::vector<Query> args) {
  return init(reql_ast_union, args);
}

Query
AST::upcase(std::vector<Query> args) {
  return init(reql_ast_upcase, this, args);
}
Query
upcase(std::vector<Query> args) {
  return init(reql_ast_upcase, args);
}

Query
AST::update(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(reql_ast_update, this, args, kwargs);
}
Query
update(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(reql_ast_update, args, kwargs);
}
Query
AST::update(std::vector<Query> args) {
  return init(reql_ast_update, this, args);
}
Query
update(std::vector<Query> args) {
  return init(reql_ast_update, args);
}

Query
AST::uuid(std::vector<Query> args) {
  return init(reql_ast_uuid, this, args);
}
Query
uuid(std::vector<Query> args) {
  return init(reql_ast_uuid, args);
}

Query
AST::var(std::vector<Query> args) {
  return init(reql_ast_var, this, args);
}
Query
var(std::vector<Query> args) {
  return init(reql_ast_var, args);
}

Query
AST::wait(std::vector<Query> args) {
  return init(reql_ast_wait, this, args);
}
Query
wait(std::vector<Query> args) {
  return init(reql_ast_wait, args);
}

Query
AST::wednesday(std::vector<Query> args) {
  return init(reql_ast_wednesday, this, args);
}
Query
wednesday(std::vector<Query> args) {
  return init(reql_ast_wednesday, args);
}

Query
AST::without(std::vector<Query> args) {
  return init(reql_ast_without, this, args);
}
Query
without(std::vector<Query> args) {
  return init(reql_ast_without, args);
}

Query
AST::with_fields(std::vector<Query> args) {
  return init(reql_ast_with_fields, this, args);
}
Query
with_fields(std::vector<Query> args) {
  return init(reql_ast_with_fields, args);
}

Query
AST::year(std::vector<Query> args) {
  return init(reql_ast_year, this, args);
}
Query
year(std::vector<Query> args) {
  return init(reql_ast_year, args);
}

Query
AST::zip(std::vector<Query> args) {
  return init(reql_ast_zip, this, args);
}
Query
zip(std::vector<Query> args) {
  return init(reql_ast_zip, args);
}

}
