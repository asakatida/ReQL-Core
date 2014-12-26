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

#include "ReQL.hpp"

#include <cstdlib>

using namespace ReQL;

AST init(_ReQL_AST_Function_ f, std::vector<AST> args, std::map<std::string, AST> kwargs) {
  AST term;

  term.query = (struct _ReQL_Op_s *)new _ReQL_Op_t();

  _ReQL_Op _args = _reql_json_array(new _ReQL_Op_t());

  for (auto it=args.cbegin(); it!=args.cend(); ++it) {
    _reql_array_append(_args, (_ReQL_Op)it->query);
  }

  _ReQL_Op _kwargs = _reql_json_object(new _ReQL_Op_t());

  for (auto it=kwargs.cbegin(); it!=kwargs.cend(); ++it) {
    _reql_object_add(_kwargs, (_ReQL_Op)expr(it->first).query, (_ReQL_Op)it->second.query);
  }

  term.query = (struct _ReQL_Op_s *)f((_ReQL_Op)term.query, _args, _kwargs);

  return term;
}

AST init(_ReQL_AST_Function_ f, AST *term, std::vector<AST> args, std::map<std::string, AST> kwargs) {
  args.insert(args.begin(), *term);
  return init(f, args, kwargs);
}

AST init(_ReQL_AST_Function_ f, std::vector<AST> args) {
  std::map<std::string, AST> kwargs;
  return init(f, args, kwargs);
}

AST init(_ReQL_AST_Function_ f, AST *term, std::vector<AST> args) {
  std::map<std::string, AST> kwargs;
  return init(f, term, args, kwargs);
}

/**
 */
AST AST::add(std::vector<AST> args) {
  return init(_reql_ast_add_, this, args);
}
AST add(std::vector<AST> args) {
  return init(_reql_ast_add_, args);
}

/**
 */
AST AST::all(std::vector<AST> args) {
  return init(_reql_ast_all_, this, args);
}
AST all(std::vector<AST> args) {
  return init(_reql_ast_all_, args);
}

/**
 */
AST AST::any(std::vector<AST> args) {
  return init(_reql_ast_any_, this, args);
}
AST any(std::vector<AST> args) {
  return init(_reql_ast_any_, args);
}

/**
 */
AST AST::append(std::vector<AST> args) {
  return init(_reql_ast_append_, this, args);
}
AST append(std::vector<AST> args) {
  return init(_reql_ast_append_, args);
}

/**
 */
AST AST::april(std::vector<AST> args) {
  return init(_reql_ast_april_, this, args);
}
AST april(std::vector<AST> args) {
  return init(_reql_ast_april_, args);
}

/**
 */
AST AST::args(std::vector<AST> args) {
  return init(_reql_ast_args_, this, args);
}
AST args(std::vector<AST> args) {
  return init(_reql_ast_args_, args);
}

/**
 */
AST AST::asc(std::vector<AST> args) {
  return init(_reql_ast_asc_, this, args);
}
AST asc(std::vector<AST> args) {
  return init(_reql_ast_asc_, args);
}

/**
 */
AST AST::august(std::vector<AST> args) {
  return init(_reql_ast_august_, this, args);
}
AST august(std::vector<AST> args) {
  return init(_reql_ast_august_, args);
}

/**
 */
AST AST::avg(std::vector<AST> args) {
  return init(_reql_ast_avg_, this, args);
}
AST avg(std::vector<AST> args) {
  return init(_reql_ast_avg_, args);
}

/**
 */
AST AST::between(std::vector<AST> args) {
  return init(_reql_ast_between_, this, args);
}
AST between(std::vector<AST> args) {
  return init(_reql_ast_between_, args);
}

/**
 */
AST AST::binary(std::vector<AST> args) {
  return init(_reql_ast_binary_, this, args);
}
AST binary(std::vector<AST> args) {
  return init(_reql_ast_binary_, args);
}

/**
 */
AST AST::bracket(std::vector<AST> args) {
  return init(_reql_ast_bracket_, this, args);
}
AST bracket(std::vector<AST> args) {
  return init(_reql_ast_bracket_, args);
}

/**
 */
AST AST::branch(std::vector<AST> args) {
  return init(_reql_ast_branch_, this, args);
}
AST branch(std::vector<AST> args) {
  return init(_reql_ast_branch_, args);
}

/**
 */
AST AST::changes(std::vector<AST> args) {
  return init(_reql_ast_changes_, this, args);
}
AST changes(std::vector<AST> args) {
  return init(_reql_ast_changes_, args);
}

/**
 */
AST AST::change_at(std::vector<AST> args) {
  return init(_reql_ast_change_at_, this, args);
}
AST change_at(std::vector<AST> args) {
  return init(_reql_ast_change_at_, args);
}

/**
 */
AST AST::circle(std::vector<AST> args, std::map<std::string, AST> kwargs) {
  return init(_reql_ast_circle_, this, args, kwargs);
}
AST circle(std::vector<AST> args, std::map<std::string, AST> kwargs) {
  return init(_reql_ast_circle_, args, kwargs);
}
AST AST::circle(std::vector<AST> args) {
  return init(_reql_ast_circle_, this, args);
}
AST circle(std::vector<AST> args) {
  return init(_reql_ast_circle_, args);
}

/**
 */
AST AST::coerce_to(std::vector<AST> args) {
  return init(_reql_ast_coerce_to_, this, args);
}
AST coerce_to(std::vector<AST> args) {
  return init(_reql_ast_coerce_to_, args);
}

/**
 */
AST AST::concat_map(std::vector<AST> args) {
  return init(_reql_ast_concat_map_, this, args);
}
AST concat_map(std::vector<AST> args) {
  return init(_reql_ast_concat_map_, args);
}

/**
 */
AST AST::contains(std::vector<AST> args) {
  return init(_reql_ast_contains_, this, args);
}
AST contains(std::vector<AST> args) {
  return init(_reql_ast_contains_, args);
}

/**
 */
AST AST::count(std::vector<AST> args) {
  return init(_reql_ast_count_, this, args);
}
AST count(std::vector<AST> args) {
  return init(_reql_ast_count_, args);
}

/**
 */
AST AST::date(std::vector<AST> args) {
  return init(_reql_ast_date_, this, args);
}
AST date(std::vector<AST> args) {
  return init(_reql_ast_date_, args);
}

/**
 */
AST AST::datum(std::vector<AST> args) {
  return init(_reql_ast_datum_, this, args);
}
AST datum(std::vector<AST> args) {
  return init(_reql_ast_datum_, args);
}

/**
 */
AST AST::day(std::vector<AST> args) {
  return init(_reql_ast_day_, this, args);
}
AST day(std::vector<AST> args) {
  return init(_reql_ast_day_, args);
}

/**
 */
AST AST::day_of_week(std::vector<AST> args) {
  return init(_reql_ast_day_of_week_, this, args);
}
AST day_of_week(std::vector<AST> args) {
  return init(_reql_ast_day_of_week_, args);
}

/**
 */
AST AST::day_of_year(std::vector<AST> args) {
  return init(_reql_ast_day_of_year_, this, args);
}
AST day_of_year(std::vector<AST> args) {
  return init(_reql_ast_day_of_year_, args);
}

/**
 */
AST AST::db(std::vector<AST> args) {
  return init(_reql_ast_db_, this, args);
}
AST db(std::vector<AST> args) {
  return init(_reql_ast_db_, args);
}

/**
 */
AST AST::db_config(std::vector<AST> args) {
  return init(_reql_ast_db_config_, this, args);
}
AST db_config(std::vector<AST> args) {
  return init(_reql_ast_db_config_, args);
}

/**
 */
AST AST::db_create(std::vector<AST> args) {
  return init(_reql_ast_db_create_, this, args);
}
AST db_create(std::vector<AST> args) {
  return init(_reql_ast_db_create_, args);
}

/**
 */
AST AST::db_drop(std::vector<AST> args) {
  return init(_reql_ast_db_drop_, this, args);
}
AST db_drop(std::vector<AST> args) {
  return init(_reql_ast_db_drop_, args);
}

/**
 */
AST AST::db_list(std::vector<AST> args) {
  return init(_reql_ast_db_list_, this, args);
}
AST db_list(std::vector<AST> args) {
  return init(_reql_ast_db_list_, args);
}

/**
 */
AST AST::december(std::vector<AST> args) {
  return init(_reql_ast_december_, this, args);
}
AST december(std::vector<AST> args) {
  return init(_reql_ast_december_, args);
}

/**
 */
AST AST::default_(std::vector<AST> args) {
  return init(_reql_ast_default_, this, args);
}
AST default_(std::vector<AST> args) {
  return init(_reql_ast_default_, args);
}

/**
 */
AST AST::delete_(std::vector<AST> args, std::map<std::string, AST> kwargs) {
  return init(_reql_ast_delete_, this, args, kwargs);
}
AST delete_(std::vector<AST> args, std::map<std::string, AST> kwargs) {
  return init(_reql_ast_delete_, args, kwargs);
}
AST AST::delete_(std::vector<AST> args) {
  return init(_reql_ast_delete_, this, args);
}
AST delete_(std::vector<AST> args) {
  return init(_reql_ast_delete_, args);
}

/**
 */
AST AST::delete_at(std::vector<AST> args) {
  return init(_reql_ast_delete_at_, this, args);
}
AST delete_at(std::vector<AST> args) {
  return init(_reql_ast_delete_at_, args);
}

/**
 */
AST AST::desc(std::vector<AST> args) {
  return init(_reql_ast_desc_, this, args);
}
AST desc(std::vector<AST> args) {
  return init(_reql_ast_desc_, args);
}

/**
 */
AST AST::difference(std::vector<AST> args) {
  return init(_reql_ast_difference_, this, args);
}
AST difference(std::vector<AST> args) {
  return init(_reql_ast_difference_, args);
}

/**
 */
AST AST::distance(std::vector<AST> args) {
  return init(_reql_ast_distance_, this, args);
}
AST distance(std::vector<AST> args) {
  return init(_reql_ast_distance_, args);
}

/**
 */
AST AST::distinct(std::vector<AST> args, std::map<std::string, AST> kwargs) {
  return init(_reql_ast_distinct_, this, args, kwargs);
}
AST distinct(std::vector<AST> args, std::map<std::string, AST> kwargs) {
  return init(_reql_ast_distinct_, args, kwargs);
}
AST AST::distinct(std::vector<AST> args) {
  return init(_reql_ast_distinct_, this, args);
}
AST distinct(std::vector<AST> args) {
  return init(_reql_ast_distinct_, args);
}

/**
 */
AST AST::div(std::vector<AST> args) {
  return init(_reql_ast_div_, this, args);
}
AST div(std::vector<AST> args) {
  return init(_reql_ast_div_, args);
}

/**
 */
AST AST::downcase(std::vector<AST> args) {
  return init(_reql_ast_downcase_, this, args);
}
AST downcase(std::vector<AST> args) {
  return init(_reql_ast_downcase_, args);
}

/**
 */
AST AST::during(std::vector<AST> args) {
  return init(_reql_ast_during_, this, args);
}
AST during(std::vector<AST> args) {
  return init(_reql_ast_during_, args);
}

/**
 */
AST AST::epoch_time(std::vector<AST> args) {
  return init(_reql_ast_epoch_time_, this, args);
}
AST epoch_time(std::vector<AST> args) {
  return init(_reql_ast_epoch_time_, args);
}

/**
 */
AST AST::eq(std::vector<AST> args) {
  return init(_reql_ast_eq_, this, args);
}
AST eq(std::vector<AST> args) {
  return init(_reql_ast_eq_, args);
}

/**
 */
AST AST::eq_join(std::vector<AST> args, std::map<std::string, AST> kwargs) {
  return init(_reql_ast_eq_join_, this, args, kwargs);
}
AST eq_join(std::vector<AST> args, std::map<std::string, AST> kwargs) {
  return init(_reql_ast_eq_join_, args, kwargs);
}
AST AST::eq_join(std::vector<AST> args) {
  return init(_reql_ast_eq_join_, this, args);
}
AST eq_join(std::vector<AST> args) {
  return init(_reql_ast_eq_join_, args);
}

/**
 */
AST AST::error(std::vector<AST> args) {
  return init(_reql_ast_error_, this, args);
}
AST error(std::vector<AST> args) {
  return init(_reql_ast_error_, args);
}

/**
 */
AST AST::february(std::vector<AST> args) {
  return init(_reql_ast_february_, this, args);
}
AST february(std::vector<AST> args) {
  return init(_reql_ast_february_, args);
}

/**
 */
AST AST::fill(std::vector<AST> args) {
  return init(_reql_ast_fill_, this, args);
}
AST fill(std::vector<AST> args) {
  return init(_reql_ast_fill_, args);
}

/**
 */
AST AST::filter(std::vector<AST> args, std::map<std::string, AST> kwargs) {
  return init(_reql_ast_filter_, this, args, kwargs);
}
AST filter(std::vector<AST> args, std::map<std::string, AST> kwargs) {
  return init(_reql_ast_filter_, args, kwargs);
}
AST AST::filter(std::vector<AST> args) {
  return init(_reql_ast_filter_, this, args);
}
AST filter(std::vector<AST> args) {
  return init(_reql_ast_filter_, args);
}

/**
 */
AST AST::for_each(std::vector<AST> args) {
  return init(_reql_ast_for_each_, this, args);
}
AST for_each(std::vector<AST> args) {
  return init(_reql_ast_for_each_, args);
}

/**
 */
AST AST::friday(std::vector<AST> args) {
  return init(_reql_ast_friday_, this, args);
}
AST friday(std::vector<AST> args) {
  return init(_reql_ast_friday_, args);
}

/**
 */
AST AST::func(std::vector<AST> args) {
  return init(_reql_ast_func_, this, args);
}
AST func(std::vector<AST> args) {
  return init(_reql_ast_func_, args);
}

/**
 */
AST AST::funcall(std::vector<AST> args) {
  return init(_reql_ast_funcall_, this, args);
}
AST funcall(std::vector<AST> args) {
  return init(_reql_ast_funcall_, args);
}

/**
 */
AST AST::ge(std::vector<AST> args) {
  return init(_reql_ast_ge_, this, args);
}
AST ge(std::vector<AST> args) {
  return init(_reql_ast_ge_, args);
}

/**
 */
AST AST::geojson(std::vector<AST> args) {
  return init(_reql_ast_geojson_, this, args);
}
AST geojson(std::vector<AST> args) {
  return init(_reql_ast_geojson_, args);
}

/**
 */
AST AST::get(std::vector<AST> args) {
  return init(_reql_ast_get_, this, args);
}
AST get(std::vector<AST> args) {
  return init(_reql_ast_get_, args);
}

/**
 */
AST AST::get_all(std::vector<AST> args, std::map<std::string, AST> kwargs) {
  return init(_reql_ast_get_all_, this, args, kwargs);
}
AST get_all(std::vector<AST> args, std::map<std::string, AST> kwargs) {
  return init(_reql_ast_get_all_, args, kwargs);
}
AST AST::get_all(std::vector<AST> args) {
  return init(_reql_ast_get_all_, this, args);
}
AST get_all(std::vector<AST> args) {
  return init(_reql_ast_get_all_, args);
}

/**
 */
AST AST::get_field(std::vector<AST> args) {
  return init(_reql_ast_get_field_, this, args);
}
AST get_field(std::vector<AST> args) {
  return init(_reql_ast_get_field_, args);
}

/**
 */
AST AST::get_intersecting(std::vector<AST> args, std::map<std::string, AST> kwargs) {
  return init(_reql_ast_get_intersecting_, this, args, kwargs);
}
AST get_intersecting(std::vector<AST> args, std::map<std::string, AST> kwargs) {
  return init(_reql_ast_get_intersecting_, args, kwargs);
}
AST AST::get_intersecting(std::vector<AST> args) {
  return init(_reql_ast_get_intersecting_, this, args);
}
AST get_intersecting(std::vector<AST> args) {
  return init(_reql_ast_get_intersecting_, args);
}

/**
 */
AST AST::get_nearest(std::vector<AST> args, std::map<std::string, AST> kwargs) {
  return init(_reql_ast_get_nearest_, this, args, kwargs);
}
AST get_nearest(std::vector<AST> args, std::map<std::string, AST> kwargs) {
  return init(_reql_ast_get_nearest_, args, kwargs);
}
AST AST::get_nearest(std::vector<AST> args) {
  return init(_reql_ast_get_nearest_, this, args);
}
AST get_nearest(std::vector<AST> args) {
  return init(_reql_ast_get_nearest_, args);
}

/**
 */
AST AST::group(std::vector<AST> args, std::map<std::string, AST> kwargs) {
  return init(_reql_ast_group_, this, args, kwargs);
}
AST group(std::vector<AST> args, std::map<std::string, AST> kwargs) {
  return init(_reql_ast_group_, args, kwargs);
}
AST AST::group(std::vector<AST> args) {
  return init(_reql_ast_group_, this, args);
}
AST group(std::vector<AST> args) {
  return init(_reql_ast_group_, args);
}

/**
 */
AST AST::gt(std::vector<AST> args) {
  return init(_reql_ast_gt_, this, args);
}
AST gt(std::vector<AST> args) {
  return init(_reql_ast_gt_, args);
}

/**
 */
AST AST::has_fields(std::vector<AST> args) {
  return init(_reql_ast_has_fields_, this, args);
}
AST has_fields(std::vector<AST> args) {
  return init(_reql_ast_has_fields_, args);
}

/**
 */
AST AST::hours(std::vector<AST> args) {
  return init(_reql_ast_hours_, this, args);
}
AST hours(std::vector<AST> args) {
  return init(_reql_ast_hours_, args);
}

/**
 */
AST AST::http(std::vector<AST> args, std::map<std::string, AST> kwargs) {
  return init(_reql_ast_http_, this, args, kwargs);
}
AST http(std::vector<AST> args, std::map<std::string, AST> kwargs) {
  return init(_reql_ast_http_, args, kwargs);
}
AST AST::http(std::vector<AST> args) {
  return init(_reql_ast_http_, this, args);
}
AST http(std::vector<AST> args) {
  return init(_reql_ast_http_, args);
}

/**
 */
AST AST::implicit_var(std::vector<AST> args) {
  return init(_reql_ast_implicit_var_, this, args);
}
AST implicit_var(std::vector<AST> args) {
  return init(_reql_ast_implicit_var_, args);
}

/**
 */
AST AST::includes(std::vector<AST> args) {
  return init(_reql_ast_includes_, this, args);
}
AST includes(std::vector<AST> args) {
  return init(_reql_ast_includes_, args);
}

/**
 */
AST AST::indexes_of(std::vector<AST> args) {
  return init(_reql_ast_indexes_of_, this, args);
}
AST indexes_of(std::vector<AST> args) {
  return init(_reql_ast_indexes_of_, args);
}

/**
 */
AST AST::index_create(std::vector<AST> args, std::map<std::string, AST> kwargs) {
  return init(_reql_ast_index_create_, this, args, kwargs);
}
AST index_create(std::vector<AST> args, std::map<std::string, AST> kwargs) {
  return init(_reql_ast_index_create_, args, kwargs);
}
AST AST::index_create(std::vector<AST> args) {
  return init(_reql_ast_index_create_, this, args);
}
AST index_create(std::vector<AST> args) {
  return init(_reql_ast_index_create_, args);
}

/**
 */
AST AST::index_drop(std::vector<AST> args) {
  return init(_reql_ast_index_drop_, this, args);
}
AST index_drop(std::vector<AST> args) {
  return init(_reql_ast_index_drop_, args);
}

/**
 */
AST AST::index_list(std::vector<AST> args) {
  return init(_reql_ast_index_list_, this, args);
}
AST index_list(std::vector<AST> args) {
  return init(_reql_ast_index_list_, args);
}

/**
 */
AST AST::index_rename(std::vector<AST> args, std::map<std::string, AST> kwargs) {
  return init(_reql_ast_index_rename_, this, args, kwargs);
}
AST index_rename(std::vector<AST> args, std::map<std::string, AST> kwargs) {
  return init(_reql_ast_index_rename_, args, kwargs);
}
AST AST::index_rename(std::vector<AST> args) {
  return init(_reql_ast_index_rename_, this, args);
}
AST index_rename(std::vector<AST> args) {
  return init(_reql_ast_index_rename_, args);
}

/**
 */
AST AST::index_status(std::vector<AST> args) {
  return init(_reql_ast_index_status_, this, args);
}
AST index_status(std::vector<AST> args) {
  return init(_reql_ast_index_status_, args);
}

/**
 */
AST AST::index_wait(std::vector<AST> args) {
  return init(_reql_ast_index_wait_, this, args);
}
AST index_wait(std::vector<AST> args) {
  return init(_reql_ast_index_wait_, args);
}

/**
 */
AST AST::info(std::vector<AST> args) {
  return init(_reql_ast_info_, this, args);
}
AST info(std::vector<AST> args) {
  return init(_reql_ast_info_, args);
}

/**
 */
AST AST::inner_join(std::vector<AST> args) {
  return init(_reql_ast_inner_join_, this, args);
}
AST inner_join(std::vector<AST> args) {
  return init(_reql_ast_inner_join_, args);
}

/**
 */
AST AST::insert(std::vector<AST> args) {
  return init(_reql_ast_insert_, this, args);
}
AST insert(std::vector<AST> args) {
  return init(_reql_ast_insert_, args);
}

/**
 */
AST AST::insert_at(std::vector<AST> args) {
  return init(_reql_ast_insert_at_, this, args);
}
AST insert_at(std::vector<AST> args) {
  return init(_reql_ast_insert_at_, args);
}

/**
 */
AST AST::intersects(std::vector<AST> args) {
  return init(_reql_ast_intersects_, this, args);
}
AST intersects(std::vector<AST> args) {
  return init(_reql_ast_intersects_, args);
}

/**
 */
AST AST::in_timezone(std::vector<AST> args) {
  return init(_reql_ast_in_timezone_, this, args);
}
AST in_timezone(std::vector<AST> args) {
  return init(_reql_ast_in_timezone_, args);
}

/**
 */
AST AST::iso8601(std::vector<AST> args, std::map<std::string, AST> kwargs) {
  return init(_reql_ast_iso8601_, this, args, kwargs);
}
AST iso8601(std::vector<AST> args, std::map<std::string, AST> kwargs) {
  return init(_reql_ast_iso8601_, args, kwargs);
}
AST AST::iso8601(std::vector<AST> args) {
  return init(_reql_ast_iso8601_, this, args);
}
AST iso8601(std::vector<AST> args) {
  return init(_reql_ast_iso8601_, args);
}

/**
 */
AST AST::is_empty(std::vector<AST> args) {
  return init(_reql_ast_is_empty_, this, args);
}
AST is_empty(std::vector<AST> args) {
  return init(_reql_ast_is_empty_, args);
}

/**
 */
AST AST::january(std::vector<AST> args) {
  return init(_reql_ast_january_, this, args);
}
AST january(std::vector<AST> args) {
  return init(_reql_ast_january_, args);
}

/**
 */
AST AST::javascript(std::vector<AST> args, std::map<std::string, AST> kwargs) {
  return init(_reql_ast_javascript_, this, args, kwargs);
}
AST javascript(std::vector<AST> args, std::map<std::string, AST> kwargs) {
  return init(_reql_ast_javascript_, args, kwargs);
}
AST AST::javascript(std::vector<AST> args) {
  return init(_reql_ast_javascript_, this, args);
}
AST javascript(std::vector<AST> args) {
  return init(_reql_ast_javascript_, args);
}

/**
 */
AST AST::json(std::vector<AST> args) {
  return init(_reql_ast_json_, this, args);
}
AST json(std::vector<AST> args) {
  return init(_reql_ast_json_, args);
}

/**
 */
AST AST::july(std::vector<AST> args) {
  return init(_reql_ast_july_, this, args);
}
AST july(std::vector<AST> args) {
  return init(_reql_ast_july_, args);
}

/**
 */
AST AST::june(std::vector<AST> args) {
  return init(_reql_ast_june_, this, args);
}
AST june(std::vector<AST> args) {
  return init(_reql_ast_june_, args);
}

/**
 */
AST AST::keys(std::vector<AST> args) {
  return init(_reql_ast_keys_, this, args);
}
AST keys(std::vector<AST> args) {
  return init(_reql_ast_keys_, args);
}

/**
 */
AST AST::le(std::vector<AST> args) {
  return init(_reql_ast_le_, this, args);
}
AST le(std::vector<AST> args) {
  return init(_reql_ast_le_, args);
}

/**
 */
AST AST::limit(std::vector<AST> args) {
  return init(_reql_ast_limit_, this, args);
}
AST limit(std::vector<AST> args) {
  return init(_reql_ast_limit_, args);
}

/**
 */
AST AST::line(std::vector<AST> args) {
  return init(_reql_ast_line_, this, args);
}
AST line(std::vector<AST> args) {
  return init(_reql_ast_line_, args);
}

/**
 */
AST AST::literal(std::vector<AST> args) {
  return init(_reql_ast_literal_, this, args);
}
AST literal(std::vector<AST> args) {
  return init(_reql_ast_literal_, args);
}

/**
 */
AST AST::lt(std::vector<AST> args) {
  return init(_reql_ast_lt_, this, args);
}
AST lt(std::vector<AST> args) {
  return init(_reql_ast_lt_, args);
}

/**
 */
AST AST::make_array(std::vector<AST> args) {
  return init(_reql_ast_make_array_, this, args);
}
AST make_array(std::vector<AST> args) {
  return init(_reql_ast_make_array_, args);
}

/**
 */
AST AST::make_obj(std::vector<AST> args) {
  return init(_reql_ast_make_obj_, this, args);
}
AST make_obj(std::vector<AST> args) {
  return init(_reql_ast_make_obj_, args);
}

/**
 */
AST AST::map(std::vector<AST> args) {
  return init(_reql_ast_map_, this, args);
}
AST map(std::vector<AST> args) {
  return init(_reql_ast_map_, args);
}

/**
 */
AST AST::march(std::vector<AST> args) {
  return init(_reql_ast_march_, this, args);
}
AST march(std::vector<AST> args) {
  return init(_reql_ast_march_, args);
}

/**
 */
AST AST::match(std::vector<AST> args) {
  return init(_reql_ast_match_, this, args);
}
AST match(std::vector<AST> args) {
  return init(_reql_ast_match_, args);
}

/**
 */
AST AST::max(std::vector<AST> args) {
  return init(_reql_ast_max_, this, args);
}
AST max(std::vector<AST> args) {
  return init(_reql_ast_max_, args);
}

/**
 */
AST AST::may(std::vector<AST> args) {
  return init(_reql_ast_may_, this, args);
}
AST may(std::vector<AST> args) {
  return init(_reql_ast_may_, args);
}

/**
 */
AST AST::merge(std::vector<AST> args) {
  return init(_reql_ast_merge_, this, args);
}
AST merge(std::vector<AST> args) {
  return init(_reql_ast_merge_, args);
}

/**
 */
AST AST::min(std::vector<AST> args) {
  return init(_reql_ast_min_, this, args);
}
AST min(std::vector<AST> args) {
  return init(_reql_ast_min_, args);
}

/**
 */
AST AST::minutes(std::vector<AST> args) {
  return init(_reql_ast_minutes_, this, args);
}
AST minutes(std::vector<AST> args) {
  return init(_reql_ast_minutes_, args);
}

/**
 */
AST AST::mod(std::vector<AST> args) {
  return init(_reql_ast_mod_, this, args);
}
AST mod(std::vector<AST> args) {
  return init(_reql_ast_mod_, args);
}

/**
 */
AST AST::monday(std::vector<AST> args) {
  return init(_reql_ast_monday_, this, args);
}
AST monday(std::vector<AST> args) {
  return init(_reql_ast_monday_, args);
}

/**
 */
AST AST::month(std::vector<AST> args) {
  return init(_reql_ast_month_, this, args);
}
AST month(std::vector<AST> args) {
  return init(_reql_ast_month_, args);
}

/**
 */
AST AST::mul(std::vector<AST> args) {
  return init(_reql_ast_mul_, this, args);
}
AST mul(std::vector<AST> args) {
  return init(_reql_ast_mul_, args);
}

/**
 */
AST AST::ne(std::vector<AST> args) {
  return init(_reql_ast_ne_, this, args);
}
AST ne(std::vector<AST> args) {
  return init(_reql_ast_ne_, args);
}

/**
 */
AST AST::not_(std::vector<AST> args) {
  return init(_reql_ast_not_, this, args);
}
AST not_(std::vector<AST> args) {
  return init(_reql_ast_not_, args);
}

/**
 */
AST AST::november(std::vector<AST> args) {
  return init(_reql_ast_november_, this, args);
}
AST november(std::vector<AST> args) {
  return init(_reql_ast_november_, args);
}

/**
 */
AST AST::now(std::vector<AST> args) {
  return init(_reql_ast_now_, this, args);
}
AST now(std::vector<AST> args) {
  return init(_reql_ast_now_, args);
}

/**
 */
AST AST::nth(std::vector<AST> args) {
  return init(_reql_ast_nth_, this, args);
}
AST nth(std::vector<AST> args) {
  return init(_reql_ast_nth_, args);
}

/**
 */
AST AST::object(std::vector<AST> args) {
  return init(_reql_ast_object_, this, args);
}
AST object(std::vector<AST> args) {
  return init(_reql_ast_object_, args);
}

/**
 */
AST AST::october(std::vector<AST> args) {
  return init(_reql_ast_october_, this, args);
}
AST october(std::vector<AST> args) {
  return init(_reql_ast_october_, args);
}

/**
 */
AST AST::order_by(std::vector<AST> args, std::map<std::string, AST> kwargs) {
  return init(_reql_ast_order_by_, this, args, kwargs);
}
AST order_by(std::vector<AST> args, std::map<std::string, AST> kwargs) {
  return init(_reql_ast_order_by_, args, kwargs);
}
AST AST::order_by(std::vector<AST> args) {
  return init(_reql_ast_order_by_, this, args);
}
AST order_by(std::vector<AST> args) {
  return init(_reql_ast_order_by_, args);
}

/**
 */
AST AST::outer_join(std::vector<AST> args) {
  return init(_reql_ast_outer_join_, this, args);
}
AST outer_join(std::vector<AST> args) {
  return init(_reql_ast_outer_join_, args);
}

/**
 */
AST AST::pluck(std::vector<AST> args) {
  return init(_reql_ast_pluck_, this, args);
}
AST pluck(std::vector<AST> args) {
  return init(_reql_ast_pluck_, args);
}

/**
 */
AST AST::point(std::vector<AST> args) {
  return init(_reql_ast_point_, this, args);
}
AST point(std::vector<AST> args) {
  return init(_reql_ast_point_, args);
}

/**
 */
AST AST::polygon(std::vector<AST> args) {
  return init(_reql_ast_polygon_, this, args);
}
AST polygon(std::vector<AST> args) {
  return init(_reql_ast_polygon_, args);
}

/**
 */
AST AST::polygon_sub(std::vector<AST> args) {
  return init(_reql_ast_polygon_sub_, this, args);
}
AST polygon_sub(std::vector<AST> args) {
  return init(_reql_ast_polygon_sub_, args);
}

/**
 */
AST AST::prepend(std::vector<AST> args) {
  return init(_reql_ast_prepend_, this, args);
}
AST prepend(std::vector<AST> args) {
  return init(_reql_ast_prepend_, args);
}

/**
 */
AST AST::random(std::vector<AST> args, std::map<std::string, AST> kwargs) {
  return init(_reql_ast_random_, this, args, kwargs);
}
AST random(std::vector<AST> args, std::map<std::string, AST> kwargs) {
  return init(_reql_ast_random_, args, kwargs);
}
AST AST::random(std::vector<AST> args) {
  return init(_reql_ast_random_, this, args);
}
AST random(std::vector<AST> args) {
  return init(_reql_ast_random_, args);
}

/**
 */
AST AST::range(std::vector<AST> args) {
  return init(_reql_ast_range_, this, args);
}
AST range(std::vector<AST> args) {
  return init(_reql_ast_range_, args);
}

/**
 */
AST AST::rebalance(std::vector<AST> args) {
  return init(_reql_ast_rebalance_, this, args);
}
AST rebalance(std::vector<AST> args) {
  return init(_reql_ast_rebalance_, args);
}

/**
 */
AST AST::reconfigure(std::vector<AST> args) {
  return init(_reql_ast_reconfigure_, this, args);
}
AST reconfigure(std::vector<AST> args) {
  return init(_reql_ast_reconfigure_, args);
}

/**
 */
AST AST::reduce(std::vector<AST> args) {
  return init(_reql_ast_reduce_, this, args);
}
AST reduce(std::vector<AST> args) {
  return init(_reql_ast_reduce_, args);
}

/**
 */
AST AST::replace(std::vector<AST> args, std::map<std::string, AST> kwargs) {
  return init(_reql_ast_replace_, this, args, kwargs);
}
AST replace(std::vector<AST> args, std::map<std::string, AST> kwargs) {
  return init(_reql_ast_replace_, args, kwargs);
}
AST AST::replace(std::vector<AST> args) {
  return init(_reql_ast_replace_, this, args);
}
AST replace(std::vector<AST> args) {
  return init(_reql_ast_replace_, args);
}

/**
 */
AST AST::sample(std::vector<AST> args) {
  return init(_reql_ast_sample_, this, args);
}
AST sample(std::vector<AST> args) {
  return init(_reql_ast_sample_, args);
}

/**
 */
AST AST::saturday(std::vector<AST> args) {
  return init(_reql_ast_saturday_, this, args);
}
AST saturday(std::vector<AST> args) {
  return init(_reql_ast_saturday_, args);
}

/**
 */
AST AST::seconds(std::vector<AST> args) {
  return init(_reql_ast_seconds_, this, args);
}
AST seconds(std::vector<AST> args) {
  return init(_reql_ast_seconds_, args);
}

/**
 */
AST AST::september(std::vector<AST> args) {
  return init(_reql_ast_september_, this, args);
}
AST september(std::vector<AST> args) {
  return init(_reql_ast_september_, args);
}

/**
 */
AST AST::set_difference(std::vector<AST> args) {
  return init(_reql_ast_set_difference_, this, args);
}
AST set_difference(std::vector<AST> args) {
  return init(_reql_ast_set_difference_, args);
}

/**
 */
AST AST::set_insert(std::vector<AST> args) {
  return init(_reql_ast_set_insert_, this, args);
}
AST set_insert(std::vector<AST> args) {
  return init(_reql_ast_set_insert_, args);
}

/**
 */
AST AST::set_intersection(std::vector<AST> args) {
  return init(_reql_ast_set_intersection_, this, args);
}
AST set_intersection(std::vector<AST> args) {
  return init(_reql_ast_set_intersection_, args);
}

/**
 */
AST AST::set_union(std::vector<AST> args) {
  return init(_reql_ast_set_union_, this, args);
}
AST set_union(std::vector<AST> args) {
  return init(_reql_ast_set_union_, args);
}

/**
 */
AST AST::skip(std::vector<AST> args) {
  return init(_reql_ast_skip_, this, args);
}
AST skip(std::vector<AST> args) {
  return init(_reql_ast_skip_, args);
}

/**
 */
AST AST::slice(std::vector<AST> args, std::map<std::string, AST> kwargs) {
  return init(_reql_ast_slice_, this, args, kwargs);
}
AST slice(std::vector<AST> args, std::map<std::string, AST> kwargs) {
  return init(_reql_ast_slice_, args, kwargs);
}
AST AST::slice(std::vector<AST> args) {
  return init(_reql_ast_slice_, this, args);
}
AST slice(std::vector<AST> args) {
  return init(_reql_ast_slice_, args);
}

/**
 */
AST AST::splice_at(std::vector<AST> args) {
  return init(_reql_ast_splice_at_, this, args);
}
AST splice_at(std::vector<AST> args) {
  return init(_reql_ast_splice_at_, args);
}

/**
 */
AST AST::split(std::vector<AST> args) {
  return init(_reql_ast_split_, this, args);
}
AST split(std::vector<AST> args) {
  return init(_reql_ast_split_, args);
}

/**
 */
AST AST::sub(std::vector<AST> args) {
  return init(_reql_ast_sub_, this, args);
}
AST sub(std::vector<AST> args) {
  return init(_reql_ast_sub_, args);
}

/**
 */
AST AST::sum(std::vector<AST> args) {
  return init(_reql_ast_sum_, this, args);
}
AST sum(std::vector<AST> args) {
  return init(_reql_ast_sum_, args);
}

/**
 */
AST AST::sunday(std::vector<AST> args) {
  return init(_reql_ast_sunday_, this, args);
}
AST sunday(std::vector<AST> args) {
  return init(_reql_ast_sunday_, args);
}

/**
 */
AST AST::sync(std::vector<AST> args) {
  return init(_reql_ast_sync_, this, args);
}
AST sync(std::vector<AST> args) {
  return init(_reql_ast_sync_, args);
}

/**
 */
AST AST::table(std::vector<AST> args, std::map<std::string, AST> kwargs) {
  return init(_reql_ast_table_, this, args, kwargs);
}
AST table(std::vector<AST> args, std::map<std::string, AST> kwargs) {
  return init(_reql_ast_table_, args, kwargs);
}
AST AST::table(std::vector<AST> args) {
  return init(_reql_ast_table_, this, args);
}
AST table(std::vector<AST> args) {
  return init(_reql_ast_table_, args);
}

/**
 */
AST AST::table_config(std::vector<AST> args) {
  return init(_reql_ast_table_config_, this, args);
}
AST table_config(std::vector<AST> args) {
  return init(_reql_ast_table_config_, args);
}

/**
 */
AST AST::table_create(std::vector<AST> args, std::map<std::string, AST> kwargs) {
  return init(_reql_ast_table_create_, this, args, kwargs);
}
AST table_create(std::vector<AST> args, std::map<std::string, AST> kwargs) {
  return init(_reql_ast_table_create_, args, kwargs);
}
AST AST::table_create(std::vector<AST> args) {
  return init(_reql_ast_table_create_, this, args);
}
AST table_create(std::vector<AST> args) {
  return init(_reql_ast_table_create_, args);
}

/**
 */
AST AST::table_drop(std::vector<AST> args) {
  return init(_reql_ast_table_drop_, this, args);
}
AST table_drop(std::vector<AST> args) {
  return init(_reql_ast_table_drop_, args);
}

/**
 */
AST AST::table_list(std::vector<AST> args) {
  return init(_reql_ast_table_list_, this, args);
}
AST table_list(std::vector<AST> args) {
  return init(_reql_ast_table_list_, args);
}

/**
 */
AST AST::table_status(std::vector<AST> args) {
  return init(_reql_ast_table_status_, this, args);
}
AST table_status(std::vector<AST> args) {
  return init(_reql_ast_table_status_, args);
}

/**
 */
AST AST::table_wait(std::vector<AST> args) {
  return init(_reql_ast_table_wait_, this, args);
}
AST table_wait(std::vector<AST> args) {
  return init(_reql_ast_table_wait_, args);
}

/**
 */
AST AST::thursday(std::vector<AST> args) {
  return init(_reql_ast_thursday_, this, args);
}
AST thursday(std::vector<AST> args) {
  return init(_reql_ast_thursday_, args);
}

/**
 */
AST AST::time(std::vector<AST> args) {
  return init(_reql_ast_time_, this, args);
}
AST time(std::vector<AST> args) {
  return init(_reql_ast_time_, args);
}

/**
 */
AST AST::timezone_(std::vector<AST> args) {
  return init(_reql_ast_timezone_, this, args);
}
AST timezone_(std::vector<AST> args) {
  return init(_reql_ast_timezone_, args);
}

/**
 */
AST AST::time_of_day(std::vector<AST> args) {
  return init(_reql_ast_time_of_day_, this, args);
}
AST time_of_day(std::vector<AST> args) {
  return init(_reql_ast_time_of_day_, args);
}

/**
 */
AST AST::to_epoch_time(std::vector<AST> args) {
  return init(_reql_ast_to_epoch_time_, this, args);
}
AST to_epoch_time(std::vector<AST> args) {
  return init(_reql_ast_to_epoch_time_, args);
}

/**
 */
AST AST::to_geojson(std::vector<AST> args) {
  return init(_reql_ast_to_geojson_, this, args);
}
AST to_geojson(std::vector<AST> args) {
  return init(_reql_ast_to_geojson_, args);
}

/**
 */
AST AST::to_iso8601(std::vector<AST> args) {
  return init(_reql_ast_to_iso8601_, this, args);
}
AST to_iso8601(std::vector<AST> args) {
  return init(_reql_ast_to_iso8601_, args);
}

/**
 */
AST AST::to_json_string(std::vector<AST> args) {
  return init(_reql_ast_to_json_string_, this, args);
}
AST to_json_string(std::vector<AST> args) {
  return init(_reql_ast_to_json_string_, args);
}

/**
 */
AST AST::tuesday(std::vector<AST> args) {
  return init(_reql_ast_tuesday_, this, args);
}
AST tuesday(std::vector<AST> args) {
  return init(_reql_ast_tuesday_, args);
}

/**
 */
AST AST::type_of(std::vector<AST> args) {
  return init(_reql_ast_type_of_, this, args);
}
AST type_of(std::vector<AST> args) {
  return init(_reql_ast_type_of_, args);
}

/**
 */
AST AST::ungroup(std::vector<AST> args) {
  return init(_reql_ast_ungroup_, this, args);
}
AST ungroup(std::vector<AST> args) {
  return init(_reql_ast_ungroup_, args);
}

/**
 */
AST AST::union_(std::vector<AST> args) {
  return init(_reql_ast_union_, this, args);
}
AST union_(std::vector<AST> args) {
  return init(_reql_ast_union_, args);
}

/**
 */
AST AST::upcase(std::vector<AST> args) {
  return init(_reql_ast_upcase_, this, args);
}
AST upcase(std::vector<AST> args) {
  return init(_reql_ast_upcase_, args);
}

/**
 */
AST AST::update(std::vector<AST> args, std::map<std::string, AST> kwargs) {
  return init(_reql_ast_update_, this, args, kwargs);
}
AST update(std::vector<AST> args, std::map<std::string, AST> kwargs) {
  return init(_reql_ast_update_, args, kwargs);
}
AST AST::update(std::vector<AST> args) {
  return init(_reql_ast_update_, this, args);
}
AST update(std::vector<AST> args) {
  return init(_reql_ast_update_, args);
}

/**
 */
AST AST::uuid(std::vector<AST> args) {
  return init(_reql_ast_uuid_, this, args);
}
AST uuid(std::vector<AST> args) {
  return init(_reql_ast_uuid_, args);
}

/**
 */
AST AST::var(std::vector<AST> args) {
  return init(_reql_ast_var_, this, args);
}
AST var(std::vector<AST> args) {
  return init(_reql_ast_var_, args);
}

/**
 */
AST AST::wednesday(std::vector<AST> args) {
  return init(_reql_ast_wednesday_, this, args);
}
AST wednesday(std::vector<AST> args) {
  return init(_reql_ast_wednesday_, args);
}

/**
 */
AST AST::without(std::vector<AST> args) {
  return init(_reql_ast_without_, this, args);
}
AST without(std::vector<AST> args) {
  return init(_reql_ast_without_, args);
}

/**
 */
AST AST::with_fields(std::vector<AST> args) {
  return init(_reql_ast_with_fields_, this, args);
}
AST with_fields(std::vector<AST> args) {
  return init(_reql_ast_with_fields_, args);
}

/**
 */
AST AST::year(std::vector<AST> args) {
  return init(_reql_ast_year_, this, args);
}
AST year(std::vector<AST> args) {
  return init(_reql_ast_year_, args);
}

/**
 */
AST AST::zip(std::vector<AST> args) {
  return init(_reql_ast_zip_, this, args);
}
AST zip(std::vector<AST> args) {
  return init(_reql_ast_zip_, args);
}
