/*
Copyright 2014 Adam Grandquist

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

#include "ReQL-ast-CPP.hpp"

#include "ReQL-CPP.hpp"
#include "ReQL.hpp"

#include <cstdlib>

namespace ReQL {

AST init(_ReQL_AST_Function f, std::vector<Query> args, std::map<std::string, Query> kwargs) {
  AST term;

  term.query = new _ReQL_Op_t();

  _ReQL_Op _args = _reql_json_array(new _ReQL_Op_t());

  for (auto it=args.cbegin(); it!=args.cend(); ++it) {
    _reql_array_append(_args, it->query);
  }

  _ReQL_Op _kwargs = _reql_json_object(new _ReQL_Op_t());

  for (auto it=kwargs.cbegin(); it!=kwargs.cend(); ++it) {
    _reql_object_add(_kwargs, expr(it->first).query, it->second.query);
  }

  term.query = f(term.query, _args, _kwargs);

  return term;
}

AST init(_ReQL_AST_Function f, AST *term, std::vector<Query> args, std::map<std::string, Query> kwargs) {
  args.insert(args.begin(), static_cast<Query>(term));
  return init(f, args, kwargs);
}

AST init(_ReQL_AST_Function f, std::vector<Query> args) {
  std::map<std::string, Query> kwargs;
  return init(f, args, kwargs);
}

AST init(_ReQL_AST_Function f, AST *term, std::vector<Query> args) {
  std::map<std::string, Query> kwargs;
  return init(f, term, args, kwargs);
}

/**
 */
AST AST::add(std::vector<Query> args) {
  return init(_reql_ast_add, this, args);
}
AST add(std::vector<Query> args) {
  return init(_reql_ast_add, args);
}

/**
 */
AST AST::all(std::vector<Query> args) {
  return init(_reql_ast_all, this, args);
}
AST all(std::vector<Query> args) {
  return init(_reql_ast_all, args);
}

/**
 */
AST AST::any(std::vector<Query> args) {
  return init(_reql_ast_any, this, args);
}
AST any(std::vector<Query> args) {
  return init(_reql_ast_any, args);
}

/**
 */
AST AST::append(std::vector<Query> args) {
  return init(_reql_ast_append, this, args);
}
AST append(std::vector<Query> args) {
  return init(_reql_ast_append, args);
}

/**
 */
AST AST::april(std::vector<Query> args) {
  return init(_reql_ast_april, this, args);
}
AST april(std::vector<Query> args) {
  return init(_reql_ast_april, args);
}

/**
 */
AST AST::args(std::vector<Query> args) {
  return init(_reql_ast_args, this, args);
}
AST args(std::vector<Query> args) {
  return init(_reql_ast_args, args);
}

/**
 */
AST AST::asc(std::vector<Query> args) {
  return init(_reql_ast_asc, this, args);
}
AST asc(std::vector<Query> args) {
  return init(_reql_ast_asc, args);
}

/**
 */
AST AST::august(std::vector<Query> args) {
  return init(_reql_ast_august, this, args);
}
AST august(std::vector<Query> args) {
  return init(_reql_ast_august, args);
}

/**
 */
AST AST::avg(std::vector<Query> args) {
  return init(_reql_ast_avg, this, args);
}
AST avg(std::vector<Query> args) {
  return init(_reql_ast_avg, args);
}

/**
 */
AST AST::between(std::vector<Query> args) {
  return init(_reql_ast_between, this, args);
}
AST between(std::vector<Query> args) {
  return init(_reql_ast_between, args);
}

/**
 */
AST AST::binary(std::vector<Query> args) {
  return init(_reql_ast_binary, this, args);
}
AST binary(std::vector<Query> args) {
  return init(_reql_ast_binary, args);
}

/**
 */
AST AST::bracket(std::vector<Query> args) {
  return init(_reql_ast_bracket, this, args);
}
AST bracket(std::vector<Query> args) {
  return init(_reql_ast_bracket, args);
}

/**
 */
AST AST::branch(std::vector<Query> args) {
  return init(_reql_ast_branch, this, args);
}
AST branch(std::vector<Query> args) {
  return init(_reql_ast_branch, args);
}

/**
 */
AST AST::changes(std::vector<Query> args) {
  return init(_reql_ast_changes, this, args);
}
AST changes(std::vector<Query> args) {
  return init(_reql_ast_changes, args);
}

/**
 */
AST AST::change_at(std::vector<Query> args) {
  return init(_reql_ast_change_at, this, args);
}
AST change_at(std::vector<Query> args) {
  return init(_reql_ast_change_at, args);
}

/**
 */
AST AST::circle(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(_reql_ast_circle, this, args, kwargs);
}
AST circle(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(_reql_ast_circle, args, kwargs);
}
AST AST::circle(std::vector<Query> args) {
  return init(_reql_ast_circle, this, args);
}
AST circle(std::vector<Query> args) {
  return init(_reql_ast_circle, args);
}

/**
 */
AST AST::coerce_to(std::vector<Query> args) {
  return init(_reql_ast_coerce_to, this, args);
}
AST coerce_to(std::vector<Query> args) {
  return init(_reql_ast_coerce_to, args);
}

/**
 */
AST AST::concat_map(std::vector<Query> args) {
  return init(_reql_ast_concat_map, this, args);
}
AST concat_map(std::vector<Query> args) {
  return init(_reql_ast_concat_map, args);
}

/**
 */
AST AST::contains(std::vector<Query> args) {
  return init(_reql_ast_contains, this, args);
}
AST contains(std::vector<Query> args) {
  return init(_reql_ast_contains, args);
}

/**
 */
AST AST::count(std::vector<Query> args) {
  return init(_reql_ast_count, this, args);
}
AST count(std::vector<Query> args) {
  return init(_reql_ast_count, args);
}

/**
 */
AST AST::date(std::vector<Query> args) {
  return init(_reql_ast_date, this, args);
}
AST date(std::vector<Query> args) {
  return init(_reql_ast_date, args);
}

/**
 */
AST AST::datum(std::vector<Query> args) {
  return init(_reql_ast_datum, this, args);
}
AST datum(std::vector<Query> args) {
  return init(_reql_ast_datum, args);
}

/**
 */
AST AST::day(std::vector<Query> args) {
  return init(_reql_ast_day, this, args);
}
AST day(std::vector<Query> args) {
  return init(_reql_ast_day, args);
}

/**
 */
AST AST::day_of_week(std::vector<Query> args) {
  return init(_reql_ast_day_of_week, this, args);
}
AST day_of_week(std::vector<Query> args) {
  return init(_reql_ast_day_of_week, args);
}

/**
 */
AST AST::day_of_year(std::vector<Query> args) {
  return init(_reql_ast_day_of_year, this, args);
}
AST day_of_year(std::vector<Query> args) {
  return init(_reql_ast_day_of_year, args);
}

/**
 */
AST AST::db(std::vector<Query> args) {
  return init(_reql_ast_db, this, args);
}
AST db(std::vector<Query> args) {
  return init(_reql_ast_db, args);
}

/**
 */
AST AST::db_config(std::vector<Query> args) {
  return init(_reql_ast_db_config, this, args);
}
AST db_config(std::vector<Query> args) {
  return init(_reql_ast_db_config, args);
}

/**
 */
AST AST::db_create(std::vector<Query> args) {
  return init(_reql_ast_db_create, this, args);
}
AST db_create(std::vector<Query> args) {
  return init(_reql_ast_db_create, args);
}

/**
 */
AST AST::db_drop(std::vector<Query> args) {
  return init(_reql_ast_db_drop, this, args);
}
AST db_drop(std::vector<Query> args) {
  return init(_reql_ast_db_drop, args);
}

/**
 */
AST AST::db_list(std::vector<Query> args) {
  return init(_reql_ast_db_list, this, args);
}
AST db_list(std::vector<Query> args) {
  return init(_reql_ast_db_list, args);
}

/**
 */
AST AST::december(std::vector<Query> args) {
  return init(_reql_ast_december, this, args);
}
AST december(std::vector<Query> args) {
  return init(_reql_ast_december, args);
}

/**
 */
AST AST::default_(std::vector<Query> args) {
  return init(_reql_ast_default, this, args);
}
AST default_(std::vector<Query> args) {
  return init(_reql_ast_default, args);
}

/**
 */
AST AST::delete_(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(_reql_ast_delete, this, args, kwargs);
}
AST delete_(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(_reql_ast_delete, args, kwargs);
}
AST AST::delete_(std::vector<Query> args) {
  return init(_reql_ast_delete, this, args);
}
AST delete_(std::vector<Query> args) {
  return init(_reql_ast_delete, args);
}

/**
 */
AST AST::delete_at(std::vector<Query> args) {
  return init(_reql_ast_delete_at, this, args);
}
AST delete_at(std::vector<Query> args) {
  return init(_reql_ast_delete_at, args);
}

/**
 */
AST AST::desc(std::vector<Query> args) {
  return init(_reql_ast_desc, this, args);
}
AST desc(std::vector<Query> args) {
  return init(_reql_ast_desc, args);
}

/**
 */
AST AST::difference(std::vector<Query> args) {
  return init(_reql_ast_difference, this, args);
}
AST difference(std::vector<Query> args) {
  return init(_reql_ast_difference, args);
}

/**
 */
AST AST::distance(std::vector<Query> args) {
  return init(_reql_ast_distance, this, args);
}
AST distance(std::vector<Query> args) {
  return init(_reql_ast_distance, args);
}

/**
 */
AST AST::distinct(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(_reql_ast_distinct, this, args, kwargs);
}
AST distinct(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(_reql_ast_distinct, args, kwargs);
}
AST AST::distinct(std::vector<Query> args) {
  return init(_reql_ast_distinct, this, args);
}
AST distinct(std::vector<Query> args) {
  return init(_reql_ast_distinct, args);
}

/**
 */
AST AST::div(std::vector<Query> args) {
  return init(_reql_ast_div, this, args);
}
AST div(std::vector<Query> args) {
  return init(_reql_ast_div, args);
}

/**
 */
AST AST::downcase(std::vector<Query> args) {
  return init(_reql_ast_downcase, this, args);
}
AST downcase(std::vector<Query> args) {
  return init(_reql_ast_downcase, args);
}

/**
 */
AST AST::during(std::vector<Query> args) {
  return init(_reql_ast_during, this, args);
}
AST during(std::vector<Query> args) {
  return init(_reql_ast_during, args);
}

/**
 */
AST AST::epoch_time(std::vector<Query> args) {
  return init(_reql_ast_epoch_time, this, args);
}
AST epoch_time(std::vector<Query> args) {
  return init(_reql_ast_epoch_time, args);
}

/**
 */
AST AST::eq(std::vector<Query> args) {
  return init(_reql_ast_eq, this, args);
}
AST eq(std::vector<Query> args) {
  return init(_reql_ast_eq, args);
}

/**
 */
AST AST::eq_join(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(_reql_ast_eq_join, this, args, kwargs);
}
AST eq_join(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(_reql_ast_eq_join, args, kwargs);
}
AST AST::eq_join(std::vector<Query> args) {
  return init(_reql_ast_eq_join, this, args);
}
AST eq_join(std::vector<Query> args) {
  return init(_reql_ast_eq_join, args);
}

/**
 */
AST AST::error(std::vector<Query> args) {
  return init(_reql_ast_error, this, args);
}
AST error(std::vector<Query> args) {
  return init(_reql_ast_error, args);
}

/**
 */
AST AST::february(std::vector<Query> args) {
  return init(_reql_ast_february, this, args);
}
AST february(std::vector<Query> args) {
  return init(_reql_ast_february, args);
}

/**
 */
AST AST::fill(std::vector<Query> args) {
  return init(_reql_ast_fill, this, args);
}
AST fill(std::vector<Query> args) {
  return init(_reql_ast_fill, args);
}

/**
 */
AST AST::filter(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(_reql_ast_filter, this, args, kwargs);
}
AST filter(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(_reql_ast_filter, args, kwargs);
}
AST AST::filter(std::vector<Query> args) {
  return init(_reql_ast_filter, this, args);
}
AST filter(std::vector<Query> args) {
  return init(_reql_ast_filter, args);
}

/**
 */
AST AST::for_each(std::vector<Query> args) {
  return init(_reql_ast_for_each, this, args);
}
AST for_each(std::vector<Query> args) {
  return init(_reql_ast_for_each, args);
}

/**
 */
AST AST::friday(std::vector<Query> args) {
  return init(_reql_ast_friday, this, args);
}
AST friday(std::vector<Query> args) {
  return init(_reql_ast_friday, args);
}

/**
 */
AST AST::func(std::vector<Query> args) {
  return init(_reql_ast_func, this, args);
}
AST func(std::vector<Query> args) {
  return init(_reql_ast_func, args);
}

/**
 */
AST AST::funcall(std::vector<Query> args) {
  return init(_reql_ast_funcall, this, args);
}
AST funcall(std::vector<Query> args) {
  return init(_reql_ast_funcall, args);
}

/**
 */
AST AST::ge(std::vector<Query> args) {
  return init(_reql_ast_ge, this, args);
}
AST ge(std::vector<Query> args) {
  return init(_reql_ast_ge, args);
}

/**
 */
AST AST::geojson(std::vector<Query> args) {
  return init(_reql_ast_geojson, this, args);
}
AST geojson(std::vector<Query> args) {
  return init(_reql_ast_geojson, args);
}

/**
 */
AST AST::get(std::vector<Query> args) {
  return init(_reql_ast_get, this, args);
}
AST get(std::vector<Query> args) {
  return init(_reql_ast_get, args);
}

/**
 */
AST AST::get_all(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(_reql_ast_get_all, this, args, kwargs);
}
AST get_all(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(_reql_ast_get_all, args, kwargs);
}
AST AST::get_all(std::vector<Query> args) {
  return init(_reql_ast_get_all, this, args);
}
AST get_all(std::vector<Query> args) {
  return init(_reql_ast_get_all, args);
}

/**
 */
AST AST::get_field(std::vector<Query> args) {
  return init(_reql_ast_get_field, this, args);
}
AST get_field(std::vector<Query> args) {
  return init(_reql_ast_get_field, args);
}

/**
 */
AST AST::get_intersecting(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(_reql_ast_get_intersecting, this, args, kwargs);
}
AST get_intersecting(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(_reql_ast_get_intersecting, args, kwargs);
}
AST AST::get_intersecting(std::vector<Query> args) {
  return init(_reql_ast_get_intersecting, this, args);
}
AST get_intersecting(std::vector<Query> args) {
  return init(_reql_ast_get_intersecting, args);
}

/**
 */
AST AST::get_nearest(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(_reql_ast_get_nearest, this, args, kwargs);
}
AST get_nearest(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(_reql_ast_get_nearest, args, kwargs);
}
AST AST::get_nearest(std::vector<Query> args) {
  return init(_reql_ast_get_nearest, this, args);
}
AST get_nearest(std::vector<Query> args) {
  return init(_reql_ast_get_nearest, args);
}

/**
 */
AST AST::group(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(_reql_ast_group, this, args, kwargs);
}
AST group(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(_reql_ast_group, args, kwargs);
}
AST AST::group(std::vector<Query> args) {
  return init(_reql_ast_group, this, args);
}
AST group(std::vector<Query> args) {
  return init(_reql_ast_group, args);
}

/**
 */
AST AST::gt(std::vector<Query> args) {
  return init(_reql_ast_gt, this, args);
}
AST gt(std::vector<Query> args) {
  return init(_reql_ast_gt, args);
}

/**
 */
AST AST::has_fields(std::vector<Query> args) {
  return init(_reql_ast_has_fields, this, args);
}
AST has_fields(std::vector<Query> args) {
  return init(_reql_ast_has_fields, args);
}

/**
 */
AST AST::hours(std::vector<Query> args) {
  return init(_reql_ast_hours, this, args);
}
AST hours(std::vector<Query> args) {
  return init(_reql_ast_hours, args);
}

/**
 */
AST AST::http(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(_reql_ast_http, this, args, kwargs);
}
AST http(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(_reql_ast_http, args, kwargs);
}
AST AST::http(std::vector<Query> args) {
  return init(_reql_ast_http, this, args);
}
AST http(std::vector<Query> args) {
  return init(_reql_ast_http, args);
}

/**
 */
AST AST::implicit_var(std::vector<Query> args) {
  return init(_reql_ast_implicit_var, this, args);
}
AST implicit_var(std::vector<Query> args) {
  return init(_reql_ast_implicit_var, args);
}

/**
 */
AST AST::includes(std::vector<Query> args) {
  return init(_reql_ast_includes, this, args);
}
AST includes(std::vector<Query> args) {
  return init(_reql_ast_includes, args);
}

/**
 */
AST AST::indexes_of(std::vector<Query> args) {
  return init(_reql_ast_indexes_of, this, args);
}
AST indexes_of(std::vector<Query> args) {
  return init(_reql_ast_indexes_of, args);
}

/**
 */
AST AST::index_create(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(_reql_ast_index_create, this, args, kwargs);
}
AST index_create(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(_reql_ast_index_create, args, kwargs);
}
AST AST::index_create(std::vector<Query> args) {
  return init(_reql_ast_index_create, this, args);
}
AST index_create(std::vector<Query> args) {
  return init(_reql_ast_index_create, args);
}

/**
 */
AST AST::index_drop(std::vector<Query> args) {
  return init(_reql_ast_index_drop, this, args);
}
AST index_drop(std::vector<Query> args) {
  return init(_reql_ast_index_drop, args);
}

/**
 */
AST AST::index_list(std::vector<Query> args) {
  return init(_reql_ast_index_list, this, args);
}
AST index_list(std::vector<Query> args) {
  return init(_reql_ast_index_list, args);
}

/**
 */
AST AST::index_rename(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(_reql_ast_index_rename, this, args, kwargs);
}
AST index_rename(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(_reql_ast_index_rename, args, kwargs);
}
AST AST::index_rename(std::vector<Query> args) {
  return init(_reql_ast_index_rename, this, args);
}
AST index_rename(std::vector<Query> args) {
  return init(_reql_ast_index_rename, args);
}

/**
 */
AST AST::index_status(std::vector<Query> args) {
  return init(_reql_ast_index_status, this, args);
}
AST index_status(std::vector<Query> args) {
  return init(_reql_ast_index_status, args);
}

/**
 */
AST AST::index_wait(std::vector<Query> args) {
  return init(_reql_ast_index_wait, this, args);
}
AST index_wait(std::vector<Query> args) {
  return init(_reql_ast_index_wait, args);
}

/**
 */
AST AST::info(std::vector<Query> args) {
  return init(_reql_ast_info, this, args);
}
AST info(std::vector<Query> args) {
  return init(_reql_ast_info, args);
}

/**
 */
AST AST::inner_join(std::vector<Query> args) {
  return init(_reql_ast_inner_join, this, args);
}
AST inner_join(std::vector<Query> args) {
  return init(_reql_ast_inner_join, args);
}

/**
 */
AST AST::insert(std::vector<Query> args) {
  return init(_reql_ast_insert, this, args);
}
AST insert(std::vector<Query> args) {
  return init(_reql_ast_insert, args);
}

/**
 */
AST AST::insert_at(std::vector<Query> args) {
  return init(_reql_ast_insert_at, this, args);
}
AST insert_at(std::vector<Query> args) {
  return init(_reql_ast_insert_at, args);
}

/**
 */
AST AST::intersects(std::vector<Query> args) {
  return init(_reql_ast_intersects, this, args);
}
AST intersects(std::vector<Query> args) {
  return init(_reql_ast_intersects, args);
}

/**
 */
AST AST::in_timezone(std::vector<Query> args) {
  return init(_reql_ast_in_timezone, this, args);
}
AST in_timezone(std::vector<Query> args) {
  return init(_reql_ast_in_timezone, args);
}

/**
 */
AST AST::iso8601(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(_reql_ast_iso8601, this, args, kwargs);
}
AST iso8601(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(_reql_ast_iso8601, args, kwargs);
}
AST AST::iso8601(std::vector<Query> args) {
  return init(_reql_ast_iso8601, this, args);
}
AST iso8601(std::vector<Query> args) {
  return init(_reql_ast_iso8601, args);
}

/**
 */
AST AST::is_empty(std::vector<Query> args) {
  return init(_reql_ast_is_empty, this, args);
}
AST is_empty(std::vector<Query> args) {
  return init(_reql_ast_is_empty, args);
}

/**
 */
AST AST::january(std::vector<Query> args) {
  return init(_reql_ast_january, this, args);
}
AST january(std::vector<Query> args) {
  return init(_reql_ast_january, args);
}

/**
 */
AST AST::javascript(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(_reql_ast_javascript, this, args, kwargs);
}
AST javascript(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(_reql_ast_javascript, args, kwargs);
}
AST AST::javascript(std::vector<Query> args) {
  return init(_reql_ast_javascript, this, args);
}
AST javascript(std::vector<Query> args) {
  return init(_reql_ast_javascript, args);
}

/**
 */
AST AST::json(std::vector<Query> args) {
  return init(_reql_ast_json, this, args);
}
AST json(std::vector<Query> args) {
  return init(_reql_ast_json, args);
}

/**
 */
AST AST::july(std::vector<Query> args) {
  return init(_reql_ast_july, this, args);
}
AST july(std::vector<Query> args) {
  return init(_reql_ast_july, args);
}

/**
 */
AST AST::june(std::vector<Query> args) {
  return init(_reql_ast_june, this, args);
}
AST june(std::vector<Query> args) {
  return init(_reql_ast_june, args);
}

/**
 */
AST AST::keys(std::vector<Query> args) {
  return init(_reql_ast_keys, this, args);
}
AST keys(std::vector<Query> args) {
  return init(_reql_ast_keys, args);
}

/**
 */
AST AST::le(std::vector<Query> args) {
  return init(_reql_ast_le, this, args);
}
AST le(std::vector<Query> args) {
  return init(_reql_ast_le, args);
}

/**
 */
AST AST::limit(std::vector<Query> args) {
  return init(_reql_ast_limit, this, args);
}
AST limit(std::vector<Query> args) {
  return init(_reql_ast_limit, args);
}

/**
 */
AST AST::line(std::vector<Query> args) {
  return init(_reql_ast_line, this, args);
}
AST line(std::vector<Query> args) {
  return init(_reql_ast_line, args);
}

/**
 */
AST AST::literal(std::vector<Query> args) {
  return init(_reql_ast_literal, this, args);
}
AST literal(std::vector<Query> args) {
  return init(_reql_ast_literal, args);
}

/**
 */
AST AST::lt(std::vector<Query> args) {
  return init(_reql_ast_lt, this, args);
}
AST lt(std::vector<Query> args) {
  return init(_reql_ast_lt, args);
}

/**
 */
AST AST::make_array(std::vector<Query> args) {
  return init(_reql_ast_make_array, this, args);
}
AST make_array(std::vector<Query> args) {
  return init(_reql_ast_make_array, args);
}

/**
 */
AST AST::make_obj(std::vector<Query> args) {
  return init(_reql_ast_make_obj, this, args);
}
AST make_obj(std::vector<Query> args) {
  return init(_reql_ast_make_obj, args);
}

/**
 */
AST AST::map(std::vector<Query> args) {
  return init(_reql_ast_map, this, args);
}
AST map(std::vector<Query> args) {
  return init(_reql_ast_map, args);
}

/**
 */
AST AST::march(std::vector<Query> args) {
  return init(_reql_ast_march, this, args);
}
AST march(std::vector<Query> args) {
  return init(_reql_ast_march, args);
}

/**
 */
AST AST::match(std::vector<Query> args) {
  return init(_reql_ast_match, this, args);
}
AST match(std::vector<Query> args) {
  return init(_reql_ast_match, args);
}

/**
 */
AST AST::max(std::vector<Query> args) {
  return init(_reql_ast_max, this, args);
}
AST max(std::vector<Query> args) {
  return init(_reql_ast_max, args);
}

/**
 */
AST AST::may(std::vector<Query> args) {
  return init(_reql_ast_may, this, args);
}
AST may(std::vector<Query> args) {
  return init(_reql_ast_may, args);
}

/**
 */
AST AST::merge(std::vector<Query> args) {
  return init(_reql_ast_merge, this, args);
}
AST merge(std::vector<Query> args) {
  return init(_reql_ast_merge, args);
}

/**
 */
AST AST::min(std::vector<Query> args) {
  return init(_reql_ast_min, this, args);
}
AST min(std::vector<Query> args) {
  return init(_reql_ast_min, args);
}

/**
 */
AST AST::minutes(std::vector<Query> args) {
  return init(_reql_ast_minutes, this, args);
}
AST minutes(std::vector<Query> args) {
  return init(_reql_ast_minutes, args);
}

/**
 */
AST AST::mod(std::vector<Query> args) {
  return init(_reql_ast_mod, this, args);
}
AST mod(std::vector<Query> args) {
  return init(_reql_ast_mod, args);
}

/**
 */
AST AST::monday(std::vector<Query> args) {
  return init(_reql_ast_monday, this, args);
}
AST monday(std::vector<Query> args) {
  return init(_reql_ast_monday, args);
}

/**
 */
AST AST::month(std::vector<Query> args) {
  return init(_reql_ast_month, this, args);
}
AST month(std::vector<Query> args) {
  return init(_reql_ast_month, args);
}

/**
 */
AST AST::mul(std::vector<Query> args) {
  return init(_reql_ast_mul, this, args);
}
AST mul(std::vector<Query> args) {
  return init(_reql_ast_mul, args);
}

/**
 */
AST AST::ne(std::vector<Query> args) {
  return init(_reql_ast_ne, this, args);
}
AST ne(std::vector<Query> args) {
  return init(_reql_ast_ne, args);
}

/**
 */
AST AST::not_(std::vector<Query> args) {
  return init(_reql_ast_not, this, args);
}
AST not_(std::vector<Query> args) {
  return init(_reql_ast_not, args);
}

/**
 */
AST AST::november(std::vector<Query> args) {
  return init(_reql_ast_november, this, args);
}
AST november(std::vector<Query> args) {
  return init(_reql_ast_november, args);
}

/**
 */
AST AST::now(std::vector<Query> args) {
  return init(_reql_ast_now, this, args);
}
AST now(std::vector<Query> args) {
  return init(_reql_ast_now, args);
}

/**
 */
AST AST::nth(std::vector<Query> args) {
  return init(_reql_ast_nth, this, args);
}
AST nth(std::vector<Query> args) {
  return init(_reql_ast_nth, args);
}

/**
 */
AST AST::object(std::vector<Query> args) {
  return init(_reql_ast_object, this, args);
}
AST object(std::vector<Query> args) {
  return init(_reql_ast_object, args);
}

/**
 */
AST AST::october(std::vector<Query> args) {
  return init(_reql_ast_october, this, args);
}
AST october(std::vector<Query> args) {
  return init(_reql_ast_october, args);
}

/**
 */
AST AST::order_by(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(_reql_ast_order_by, this, args, kwargs);
}
AST order_by(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(_reql_ast_order_by, args, kwargs);
}
AST AST::order_by(std::vector<Query> args) {
  return init(_reql_ast_order_by, this, args);
}
AST order_by(std::vector<Query> args) {
  return init(_reql_ast_order_by, args);
}

/**
 */
AST AST::outer_join(std::vector<Query> args) {
  return init(_reql_ast_outer_join, this, args);
}
AST outer_join(std::vector<Query> args) {
  return init(_reql_ast_outer_join, args);
}

/**
 */
AST AST::pluck(std::vector<Query> args) {
  return init(_reql_ast_pluck, this, args);
}
AST pluck(std::vector<Query> args) {
  return init(_reql_ast_pluck, args);
}

/**
 */
AST AST::point(std::vector<Query> args) {
  return init(_reql_ast_point, this, args);
}
AST point(std::vector<Query> args) {
  return init(_reql_ast_point, args);
}

/**
 */
AST AST::polygon(std::vector<Query> args) {
  return init(_reql_ast_polygon, this, args);
}
AST polygon(std::vector<Query> args) {
  return init(_reql_ast_polygon, args);
}

/**
 */
AST AST::polygon_sub(std::vector<Query> args) {
  return init(_reql_ast_polygon_sub, this, args);
}
AST polygon_sub(std::vector<Query> args) {
  return init(_reql_ast_polygon_sub, args);
}

/**
 */
AST AST::prepend(std::vector<Query> args) {
  return init(_reql_ast_prepend, this, args);
}
AST prepend(std::vector<Query> args) {
  return init(_reql_ast_prepend, args);
}

/**
 */
AST AST::random(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(_reql_ast_random, this, args, kwargs);
}
AST random(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(_reql_ast_random, args, kwargs);
}
AST AST::random(std::vector<Query> args) {
  return init(_reql_ast_random, this, args);
}
AST random(std::vector<Query> args) {
  return init(_reql_ast_random, args);
}

/**
 */
AST AST::range(std::vector<Query> args) {
  return init(_reql_ast_range, this, args);
}
AST range(std::vector<Query> args) {
  return init(_reql_ast_range, args);
}

/**
 */
AST AST::rebalance(std::vector<Query> args) {
  return init(_reql_ast_rebalance, this, args);
}
AST rebalance(std::vector<Query> args) {
  return init(_reql_ast_rebalance, args);
}

/**
 */
AST AST::reconfigure(std::vector<Query> args) {
  return init(_reql_ast_reconfigure, this, args);
}
AST reconfigure(std::vector<Query> args) {
  return init(_reql_ast_reconfigure, args);
}

/**
 */
AST AST::reduce(std::vector<Query> args) {
  return init(_reql_ast_reduce, this, args);
}
AST reduce(std::vector<Query> args) {
  return init(_reql_ast_reduce, args);
}

/**
 */
AST AST::replace(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(_reql_ast_replace, this, args, kwargs);
}
AST replace(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(_reql_ast_replace, args, kwargs);
}
AST AST::replace(std::vector<Query> args) {
  return init(_reql_ast_replace, this, args);
}
AST replace(std::vector<Query> args) {
  return init(_reql_ast_replace, args);
}

/**
 */
AST AST::sample(std::vector<Query> args) {
  return init(_reql_ast_sample, this, args);
}
AST sample(std::vector<Query> args) {
  return init(_reql_ast_sample, args);
}

/**
 */
AST AST::saturday(std::vector<Query> args) {
  return init(_reql_ast_saturday, this, args);
}
AST saturday(std::vector<Query> args) {
  return init(_reql_ast_saturday, args);
}

/**
 */
AST AST::seconds(std::vector<Query> args) {
  return init(_reql_ast_seconds, this, args);
}
AST seconds(std::vector<Query> args) {
  return init(_reql_ast_seconds, args);
}

/**
 */
AST AST::september(std::vector<Query> args) {
  return init(_reql_ast_september, this, args);
}
AST september(std::vector<Query> args) {
  return init(_reql_ast_september, args);
}

/**
 */
AST AST::set_difference(std::vector<Query> args) {
  return init(_reql_ast_set_difference, this, args);
}
AST set_difference(std::vector<Query> args) {
  return init(_reql_ast_set_difference, args);
}

/**
 */
AST AST::set_insert(std::vector<Query> args) {
  return init(_reql_ast_set_insert, this, args);
}
AST set_insert(std::vector<Query> args) {
  return init(_reql_ast_set_insert, args);
}

/**
 */
AST AST::set_intersection(std::vector<Query> args) {
  return init(_reql_ast_set_intersection, this, args);
}
AST set_intersection(std::vector<Query> args) {
  return init(_reql_ast_set_intersection, args);
}

/**
 */
AST AST::set_union(std::vector<Query> args) {
  return init(_reql_ast_set_union, this, args);
}
AST set_union(std::vector<Query> args) {
  return init(_reql_ast_set_union, args);
}

/**
 */
AST AST::skip(std::vector<Query> args) {
  return init(_reql_ast_skip, this, args);
}
AST skip(std::vector<Query> args) {
  return init(_reql_ast_skip, args);
}

/**
 */
AST AST::slice(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(_reql_ast_slice, this, args, kwargs);
}
AST slice(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(_reql_ast_slice, args, kwargs);
}
AST AST::slice(std::vector<Query> args) {
  return init(_reql_ast_slice, this, args);
}
AST slice(std::vector<Query> args) {
  return init(_reql_ast_slice, args);
}

/**
 */
AST AST::splice_at(std::vector<Query> args) {
  return init(_reql_ast_splice_at, this, args);
}
AST splice_at(std::vector<Query> args) {
  return init(_reql_ast_splice_at, args);
}

/**
 */
AST AST::split(std::vector<Query> args) {
  return init(_reql_ast_split, this, args);
}
AST split(std::vector<Query> args) {
  return init(_reql_ast_split, args);
}

/**
 */
AST AST::sub(std::vector<Query> args) {
  return init(_reql_ast_sub, this, args);
}
AST sub(std::vector<Query> args) {
  return init(_reql_ast_sub, args);
}

/**
 */
AST AST::sum(std::vector<Query> args) {
  return init(_reql_ast_sum, this, args);
}
AST sum(std::vector<Query> args) {
  return init(_reql_ast_sum, args);
}

/**
 */
AST AST::sunday(std::vector<Query> args) {
  return init(_reql_ast_sunday, this, args);
}
AST sunday(std::vector<Query> args) {
  return init(_reql_ast_sunday, args);
}

/**
 */
AST AST::sync(std::vector<Query> args) {
  return init(_reql_ast_sync, this, args);
}
AST sync(std::vector<Query> args) {
  return init(_reql_ast_sync, args);
}

/**
 */
AST AST::table(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(_reql_ast_table, this, args, kwargs);
}
AST table(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(_reql_ast_table, args, kwargs);
}
AST AST::table(std::vector<Query> args) {
  return init(_reql_ast_table, this, args);
}
AST table(std::vector<Query> args) {
  return init(_reql_ast_table, args);
}

/**
 */
AST AST::table_config(std::vector<Query> args) {
  return init(_reql_ast_table_config, this, args);
}
AST table_config(std::vector<Query> args) {
  return init(_reql_ast_table_config, args);
}

/**
 */
AST AST::table_create(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(_reql_ast_table_create, this, args, kwargs);
}
AST table_create(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(_reql_ast_table_create, args, kwargs);
}
AST AST::table_create(std::vector<Query> args) {
  return init(_reql_ast_table_create, this, args);
}
AST table_create(std::vector<Query> args) {
  return init(_reql_ast_table_create, args);
}

/**
 */
AST AST::table_drop(std::vector<Query> args) {
  return init(_reql_ast_table_drop, this, args);
}
AST table_drop(std::vector<Query> args) {
  return init(_reql_ast_table_drop, args);
}

/**
 */
AST AST::table_list(std::vector<Query> args) {
  return init(_reql_ast_table_list, this, args);
}
AST table_list(std::vector<Query> args) {
  return init(_reql_ast_table_list, args);
}

/**
 */
AST AST::table_status(std::vector<Query> args) {
  return init(_reql_ast_table_status, this, args);
}
AST table_status(std::vector<Query> args) {
  return init(_reql_ast_table_status, args);
}

/**
 */
AST AST::table_wait(std::vector<Query> args) {
  return init(_reql_ast_table_wait, this, args);
}
AST table_wait(std::vector<Query> args) {
  return init(_reql_ast_table_wait, args);
}

/**
 */
AST AST::thursday(std::vector<Query> args) {
  return init(_reql_ast_thursday, this, args);
}
AST thursday(std::vector<Query> args) {
  return init(_reql_ast_thursday, args);
}

/**
 */
AST AST::time(std::vector<Query> args) {
  return init(_reql_ast_time, this, args);
}
AST time(std::vector<Query> args) {
  return init(_reql_ast_time, args);
}

/**
 */
AST AST::timezone_(std::vector<Query> args) {
  return init(_reql_ast_timezone, this, args);
}
AST timezone_(std::vector<Query> args) {
  return init(_reql_ast_timezone, args);
}

/**
 */
AST AST::time_of_day(std::vector<Query> args) {
  return init(_reql_ast_time_of_day, this, args);
}
AST time_of_day(std::vector<Query> args) {
  return init(_reql_ast_time_of_day, args);
}

/**
 */
AST AST::to_epoch_time(std::vector<Query> args) {
  return init(_reql_ast_to_epoch_time, this, args);
}
AST to_epoch_time(std::vector<Query> args) {
  return init(_reql_ast_to_epoch_time, args);
}

/**
 */
AST AST::to_geojson(std::vector<Query> args) {
  return init(_reql_ast_to_geojson, this, args);
}
AST to_geojson(std::vector<Query> args) {
  return init(_reql_ast_to_geojson, args);
}

/**
 */
AST AST::to_iso8601(std::vector<Query> args) {
  return init(_reql_ast_to_iso8601, this, args);
}
AST to_iso8601(std::vector<Query> args) {
  return init(_reql_ast_to_iso8601, args);
}

/**
 */
AST AST::to_json_string(std::vector<Query> args) {
  return init(_reql_ast_to_json_string, this, args);
}
AST to_json_string(std::vector<Query> args) {
  return init(_reql_ast_to_json_string, args);
}

/**
 */
AST AST::tuesday(std::vector<Query> args) {
  return init(_reql_ast_tuesday, this, args);
}
AST tuesday(std::vector<Query> args) {
  return init(_reql_ast_tuesday, args);
}

/**
 */
AST AST::type_of(std::vector<Query> args) {
  return init(_reql_ast_type_of, this, args);
}
AST type_of(std::vector<Query> args) {
  return init(_reql_ast_type_of, args);
}

/**
 */
AST AST::ungroup(std::vector<Query> args) {
  return init(_reql_ast_ungroup, this, args);
}
AST ungroup(std::vector<Query> args) {
  return init(_reql_ast_ungroup, args);
}

/**
 */
AST AST::union_(std::vector<Query> args) {
  return init(_reql_ast_union, this, args);
}
AST union_(std::vector<Query> args) {
  return init(_reql_ast_union, args);
}

/**
 */
AST AST::upcase(std::vector<Query> args) {
  return init(_reql_ast_upcase, this, args);
}
AST upcase(std::vector<Query> args) {
  return init(_reql_ast_upcase, args);
}

/**
 */
AST AST::update(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(_reql_ast_update, this, args, kwargs);
}
AST update(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(_reql_ast_update, args, kwargs);
}
AST AST::update(std::vector<Query> args) {
  return init(_reql_ast_update, this, args);
}
AST update(std::vector<Query> args) {
  return init(_reql_ast_update, args);
}

/**
 */
AST AST::uuid(std::vector<Query> args) {
  return init(_reql_ast_uuid, this, args);
}
AST uuid(std::vector<Query> args) {
  return init(_reql_ast_uuid, args);
}

/**
 */
AST AST::var(std::vector<Query> args) {
  return init(_reql_ast_var, this, args);
}
AST var(std::vector<Query> args) {
  return init(_reql_ast_var, args);
}

/**
 */
AST AST::wednesday(std::vector<Query> args) {
  return init(_reql_ast_wednesday, this, args);
}
AST wednesday(std::vector<Query> args) {
  return init(_reql_ast_wednesday, args);
}

/**
 */
AST AST::without(std::vector<Query> args) {
  return init(_reql_ast_without, this, args);
}
AST without(std::vector<Query> args) {
  return init(_reql_ast_without, args);
}

/**
 */
AST AST::with_fields(std::vector<Query> args) {
  return init(_reql_ast_with_fields, this, args);
}
AST with_fields(std::vector<Query> args) {
  return init(_reql_ast_with_fields, args);
}

/**
 */
AST AST::year(std::vector<Query> args) {
  return init(_reql_ast_year, this, args);
}
AST year(std::vector<Query> args) {
  return init(_reql_ast_year, args);
}

/**
 */
AST AST::zip(std::vector<Query> args) {
  return init(_reql_ast_zip, this, args);
}
AST zip(std::vector<Query> args) {
  return init(_reql_ast_zip, args);
}

}
