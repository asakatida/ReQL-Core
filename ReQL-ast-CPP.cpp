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

#include <cstdlib>

#include "ReQL.hpp"

ReQL_ast init(_ReQL_AST_Function_ f, std::vector<ReQL_ast> args, std::map<std::string, ReQL_ast> kwargs) {
  ReQL_ast term;

  term.val = new _ReQL_Op_t();

  _ReQL_Op _args = _reql_json_array(new _ReQL_Op_t());

  for (auto it=args.cbegin(); it!=args.cend(); ++it) {
    _reql_array_append(_args, it->val);
  }

  _ReQL_Op _kwargs = _reql_json_object(new _ReQL_Op_t());

  for (auto it=kwargs.cbegin(); it!=kwargs.cend(); ++it) {
    _reql_object_add(_kwargs, expr(it->first).val, it->second.val);
  }

  term.val = f(term.val, _args, _kwargs);

  return term;
}

ReQL_ast init(_ReQL_AST_Function_ f, ReQL_ast *term, std::vector<ReQL_ast> args, std::map<std::string, ReQL_ast> kwargs) {
  args.insert(args.begin(), *term);
  return init(f, args, kwargs);
}

ReQL_ast init(_ReQL_AST_Function_ f, std::vector<ReQL_ast> args) {
  std::map<std::string, ReQL_ast> kwargs;
  return init(f, args, kwargs);
}

ReQL_ast init(_ReQL_AST_Function_ f, ReQL_ast *term, std::vector<ReQL_ast> args) {
  std::map<std::string, ReQL_ast> kwargs;
  return init(f, term, args, kwargs);
}

/**
 */
ReQL_ast ReQL_ast::add(std::vector<ReQL_ast> args) {
  return init(_reql_ast_add_, this, args);
}
ReQL_ast add(std::vector<ReQL_ast> args) {
  return init(_reql_ast_add_, args);
}

/**
 */
ReQL_ast ReQL_ast::all(std::vector<ReQL_ast> args) {
  return init(_reql_ast_all_, this, args);
}
ReQL_ast all(std::vector<ReQL_ast> args) {
  return init(_reql_ast_all_, args);
}

/**
 */
ReQL_ast ReQL_ast::any(std::vector<ReQL_ast> args) {
  return init(_reql_ast_any_, this, args);
}
ReQL_ast any(std::vector<ReQL_ast> args) {
  return init(_reql_ast_any_, args);
}

/**
 */
ReQL_ast ReQL_ast::append(std::vector<ReQL_ast> args) {
  return init(_reql_ast_append_, this, args);
}
ReQL_ast append(std::vector<ReQL_ast> args) {
  return init(_reql_ast_append_, args);
}

/**
 */
ReQL_ast ReQL_ast::april(std::vector<ReQL_ast> args) {
  return init(_reql_ast_april_, this, args);
}
ReQL_ast april(std::vector<ReQL_ast> args) {
  return init(_reql_ast_april_, args);
}

/**
 */
ReQL_ast ReQL_ast::args(std::vector<ReQL_ast> args) {
  return init(_reql_ast_args_, this, args);
}
ReQL_ast args(std::vector<ReQL_ast> args) {
  return init(_reql_ast_args_, args);
}

/**
 */
ReQL_ast ReQL_ast::asc(std::vector<ReQL_ast> args) {
  return init(_reql_ast_asc_, this, args);
}
ReQL_ast asc(std::vector<ReQL_ast> args) {
  return init(_reql_ast_asc_, args);
}

/**
 */
ReQL_ast ReQL_ast::august(std::vector<ReQL_ast> args) {
  return init(_reql_ast_august_, this, args);
}
ReQL_ast august(std::vector<ReQL_ast> args) {
  return init(_reql_ast_august_, args);
}

/**
 */
ReQL_ast ReQL_ast::avg(std::vector<ReQL_ast> args) {
  return init(_reql_ast_avg_, this, args);
}
ReQL_ast avg(std::vector<ReQL_ast> args) {
  return init(_reql_ast_avg_, args);
}

/**
 */
ReQL_ast ReQL_ast::between(std::vector<ReQL_ast> args) {
  return init(_reql_ast_between_, this, args);
}
ReQL_ast between(std::vector<ReQL_ast> args) {
  return init(_reql_ast_between_, args);
}

/**
 */
ReQL_ast ReQL_ast::binary(std::vector<ReQL_ast> args) {
  return init(_reql_ast_binary_, this, args);
}
ReQL_ast binary(std::vector<ReQL_ast> args) {
  return init(_reql_ast_binary_, args);
}

/**
 */
ReQL_ast ReQL_ast::bracket(std::vector<ReQL_ast> args) {
  return init(_reql_ast_bracket_, this, args);
}
ReQL_ast bracket(std::vector<ReQL_ast> args) {
  return init(_reql_ast_bracket_, args);
}

/**
 */
ReQL_ast ReQL_ast::branch(std::vector<ReQL_ast> args) {
  return init(_reql_ast_branch_, this, args);
}
ReQL_ast branch(std::vector<ReQL_ast> args) {
  return init(_reql_ast_branch_, args);
}

/**
 */
ReQL_ast ReQL_ast::changes(std::vector<ReQL_ast> args) {
  return init(_reql_ast_changes_, this, args);
}
ReQL_ast changes(std::vector<ReQL_ast> args) {
  return init(_reql_ast_changes_, args);
}

/**
 */
ReQL_ast ReQL_ast::change_at(std::vector<ReQL_ast> args) {
  return init(_reql_ast_change_at_, this, args);
}
ReQL_ast change_at(std::vector<ReQL_ast> args) {
  return init(_reql_ast_change_at_, args);
}

/**
 */
ReQL_ast ReQL_ast::circle(std::vector<ReQL_ast> args, std::map<std::string, ReQL_ast> kwargs) {
  return init(_reql_ast_circle_, this, args, kwargs);
}
ReQL_ast circle(std::vector<ReQL_ast> args, std::map<std::string, ReQL_ast> kwargs) {
  return init(_reql_ast_circle_, args, kwargs);
}
ReQL_ast ReQL_ast::circle(std::vector<ReQL_ast> args) {
  return init(_reql_ast_circle_, this, args);
}
ReQL_ast circle(std::vector<ReQL_ast> args) {
  return init(_reql_ast_circle_, args);
}

/**
 */
ReQL_ast ReQL_ast::coerce_to(std::vector<ReQL_ast> args) {
  return init(_reql_ast_coerce_to_, this, args);
}
ReQL_ast coerce_to(std::vector<ReQL_ast> args) {
  return init(_reql_ast_coerce_to_, args);
}

/**
 */
ReQL_ast ReQL_ast::concat_map(std::vector<ReQL_ast> args) {
  return init(_reql_ast_concat_map_, this, args);
}
ReQL_ast concat_map(std::vector<ReQL_ast> args) {
  return init(_reql_ast_concat_map_, args);
}

/**
 */
ReQL_ast ReQL_ast::contains(std::vector<ReQL_ast> args) {
  return init(_reql_ast_contains_, this, args);
}
ReQL_ast contains(std::vector<ReQL_ast> args) {
  return init(_reql_ast_contains_, args);
}

/**
 */
ReQL_ast ReQL_ast::count(std::vector<ReQL_ast> args) {
  return init(_reql_ast_count_, this, args);
}
ReQL_ast count(std::vector<ReQL_ast> args) {
  return init(_reql_ast_count_, args);
}

/**
 */
ReQL_ast ReQL_ast::date(std::vector<ReQL_ast> args) {
  return init(_reql_ast_date_, this, args);
}
ReQL_ast date(std::vector<ReQL_ast> args) {
  return init(_reql_ast_date_, args);
}

/**
 */
ReQL_ast ReQL_ast::datum(std::vector<ReQL_ast> args) {
  return init(_reql_ast_datum_, this, args);
}
ReQL_ast datum(std::vector<ReQL_ast> args) {
  return init(_reql_ast_datum_, args);
}

/**
 */
ReQL_ast ReQL_ast::day(std::vector<ReQL_ast> args) {
  return init(_reql_ast_day_, this, args);
}
ReQL_ast day(std::vector<ReQL_ast> args) {
  return init(_reql_ast_day_, args);
}

/**
 */
ReQL_ast ReQL_ast::day_of_week(std::vector<ReQL_ast> args) {
  return init(_reql_ast_day_of_week_, this, args);
}
ReQL_ast day_of_week(std::vector<ReQL_ast> args) {
  return init(_reql_ast_day_of_week_, args);
}

/**
 */
ReQL_ast ReQL_ast::day_of_year(std::vector<ReQL_ast> args) {
  return init(_reql_ast_day_of_year_, this, args);
}
ReQL_ast day_of_year(std::vector<ReQL_ast> args) {
  return init(_reql_ast_day_of_year_, args);
}

/**
 */
ReQL_ast ReQL_ast::db(std::vector<ReQL_ast> args) {
  return init(_reql_ast_db_, this, args);
}
ReQL_ast db(std::vector<ReQL_ast> args) {
  return init(_reql_ast_db_, args);
}

/**
 */
ReQL_ast ReQL_ast::db_config(std::vector<ReQL_ast> args) {
  return init(_reql_ast_db_config_, this, args);
}
ReQL_ast db_config(std::vector<ReQL_ast> args) {
  return init(_reql_ast_db_config_, args);
}

/**
 */
ReQL_ast ReQL_ast::db_create(std::vector<ReQL_ast> args) {
  return init(_reql_ast_db_create_, this, args);
}
ReQL_ast db_create(std::vector<ReQL_ast> args) {
  return init(_reql_ast_db_create_, args);
}

/**
 */
ReQL_ast ReQL_ast::db_drop(std::vector<ReQL_ast> args) {
  return init(_reql_ast_db_drop_, this, args);
}
ReQL_ast db_drop(std::vector<ReQL_ast> args) {
  return init(_reql_ast_db_drop_, args);
}

/**
 */
ReQL_ast ReQL_ast::db_list(std::vector<ReQL_ast> args) {
  return init(_reql_ast_db_list_, this, args);
}
ReQL_ast db_list(std::vector<ReQL_ast> args) {
  return init(_reql_ast_db_list_, args);
}

/**
 */
ReQL_ast ReQL_ast::december(std::vector<ReQL_ast> args) {
  return init(_reql_ast_december_, this, args);
}
ReQL_ast december(std::vector<ReQL_ast> args) {
  return init(_reql_ast_december_, args);
}

/**
 */
ReQL_ast ReQL_ast::default_(std::vector<ReQL_ast> args) {
  return init(_reql_ast_default_, this, args);
}
ReQL_ast default_(std::vector<ReQL_ast> args) {
  return init(_reql_ast_default_, args);
}

/**
 */
ReQL_ast ReQL_ast::delete_(std::vector<ReQL_ast> args, std::map<std::string, ReQL_ast> kwargs) {
  return init(_reql_ast_delete_, this, args, kwargs);
}
ReQL_ast delete_(std::vector<ReQL_ast> args, std::map<std::string, ReQL_ast> kwargs) {
  return init(_reql_ast_delete_, args, kwargs);
}
ReQL_ast ReQL_ast::delete_(std::vector<ReQL_ast> args) {
  return init(_reql_ast_delete_, this, args);
}
ReQL_ast delete_(std::vector<ReQL_ast> args) {
  return init(_reql_ast_delete_, args);
}

/**
 */
ReQL_ast ReQL_ast::delete_at(std::vector<ReQL_ast> args) {
  return init(_reql_ast_delete_at_, this, args);
}
ReQL_ast delete_at(std::vector<ReQL_ast> args) {
  return init(_reql_ast_delete_at_, args);
}

/**
 */
ReQL_ast ReQL_ast::desc(std::vector<ReQL_ast> args) {
  return init(_reql_ast_desc_, this, args);
}
ReQL_ast desc(std::vector<ReQL_ast> args) {
  return init(_reql_ast_desc_, args);
}

/**
 */
ReQL_ast ReQL_ast::difference(std::vector<ReQL_ast> args) {
  return init(_reql_ast_difference_, this, args);
}
ReQL_ast difference(std::vector<ReQL_ast> args) {
  return init(_reql_ast_difference_, args);
}

/**
 */
ReQL_ast ReQL_ast::distance(std::vector<ReQL_ast> args) {
  return init(_reql_ast_distance_, this, args);
}
ReQL_ast distance(std::vector<ReQL_ast> args) {
  return init(_reql_ast_distance_, args);
}

/**
 */
ReQL_ast ReQL_ast::distinct(std::vector<ReQL_ast> args, std::map<std::string, ReQL_ast> kwargs) {
  return init(_reql_ast_distinct_, this, args, kwargs);
}
ReQL_ast distinct(std::vector<ReQL_ast> args, std::map<std::string, ReQL_ast> kwargs) {
  return init(_reql_ast_distinct_, args, kwargs);
}
ReQL_ast ReQL_ast::distinct(std::vector<ReQL_ast> args) {
  return init(_reql_ast_distinct_, this, args);
}
ReQL_ast distinct(std::vector<ReQL_ast> args) {
  return init(_reql_ast_distinct_, args);
}

/**
 */
ReQL_ast ReQL_ast::div(std::vector<ReQL_ast> args) {
  return init(_reql_ast_div_, this, args);
}
ReQL_ast div(std::vector<ReQL_ast> args) {
  return init(_reql_ast_div_, args);
}

/**
 */
ReQL_ast ReQL_ast::downcase(std::vector<ReQL_ast> args) {
  return init(_reql_ast_downcase_, this, args);
}
ReQL_ast downcase(std::vector<ReQL_ast> args) {
  return init(_reql_ast_downcase_, args);
}

/**
 */
ReQL_ast ReQL_ast::during(std::vector<ReQL_ast> args) {
  return init(_reql_ast_during_, this, args);
}
ReQL_ast during(std::vector<ReQL_ast> args) {
  return init(_reql_ast_during_, args);
}

/**
 */
ReQL_ast ReQL_ast::epoch_time(std::vector<ReQL_ast> args) {
  return init(_reql_ast_epoch_time_, this, args);
}
ReQL_ast epoch_time(std::vector<ReQL_ast> args) {
  return init(_reql_ast_epoch_time_, args);
}

/**
 */
ReQL_ast ReQL_ast::eq(std::vector<ReQL_ast> args) {
  return init(_reql_ast_eq_, this, args);
}
ReQL_ast eq(std::vector<ReQL_ast> args) {
  return init(_reql_ast_eq_, args);
}

/**
 */
ReQL_ast ReQL_ast::eq_join(std::vector<ReQL_ast> args, std::map<std::string, ReQL_ast> kwargs) {
  return init(_reql_ast_eq_join_, this, args, kwargs);
}
ReQL_ast eq_join(std::vector<ReQL_ast> args, std::map<std::string, ReQL_ast> kwargs) {
  return init(_reql_ast_eq_join_, args, kwargs);
}
ReQL_ast ReQL_ast::eq_join(std::vector<ReQL_ast> args) {
  return init(_reql_ast_eq_join_, this, args);
}
ReQL_ast eq_join(std::vector<ReQL_ast> args) {
  return init(_reql_ast_eq_join_, args);
}

/**
 */
ReQL_ast ReQL_ast::error(std::vector<ReQL_ast> args) {
  return init(_reql_ast_error_, this, args);
}
ReQL_ast error(std::vector<ReQL_ast> args) {
  return init(_reql_ast_error_, args);
}

/**
 */
ReQL_ast ReQL_ast::february(std::vector<ReQL_ast> args) {
  return init(_reql_ast_february_, this, args);
}
ReQL_ast february(std::vector<ReQL_ast> args) {
  return init(_reql_ast_february_, args);
}

/**
 */
ReQL_ast ReQL_ast::fill(std::vector<ReQL_ast> args) {
  return init(_reql_ast_fill_, this, args);
}
ReQL_ast fill(std::vector<ReQL_ast> args) {
  return init(_reql_ast_fill_, args);
}

/**
 */
ReQL_ast ReQL_ast::filter(std::vector<ReQL_ast> args, std::map<std::string, ReQL_ast> kwargs) {
  return init(_reql_ast_filter_, this, args, kwargs);
}
ReQL_ast filter(std::vector<ReQL_ast> args, std::map<std::string, ReQL_ast> kwargs) {
  return init(_reql_ast_filter_, args, kwargs);
}
ReQL_ast ReQL_ast::filter(std::vector<ReQL_ast> args) {
  return init(_reql_ast_filter_, this, args);
}
ReQL_ast filter(std::vector<ReQL_ast> args) {
  return init(_reql_ast_filter_, args);
}

/**
 */
ReQL_ast ReQL_ast::for_each(std::vector<ReQL_ast> args) {
  return init(_reql_ast_for_each_, this, args);
}
ReQL_ast for_each(std::vector<ReQL_ast> args) {
  return init(_reql_ast_for_each_, args);
}

/**
 */
ReQL_ast ReQL_ast::friday(std::vector<ReQL_ast> args) {
  return init(_reql_ast_friday_, this, args);
}
ReQL_ast friday(std::vector<ReQL_ast> args) {
  return init(_reql_ast_friday_, args);
}

/**
 */
ReQL_ast ReQL_ast::func(std::vector<ReQL_ast> args) {
  return init(_reql_ast_func_, this, args);
}
ReQL_ast func(std::vector<ReQL_ast> args) {
  return init(_reql_ast_func_, args);
}

/**
 */
ReQL_ast ReQL_ast::funcall(std::vector<ReQL_ast> args) {
  return init(_reql_ast_funcall_, this, args);
}
ReQL_ast funcall(std::vector<ReQL_ast> args) {
  return init(_reql_ast_funcall_, args);
}

/**
 */
ReQL_ast ReQL_ast::ge(std::vector<ReQL_ast> args) {
  return init(_reql_ast_ge_, this, args);
}
ReQL_ast ge(std::vector<ReQL_ast> args) {
  return init(_reql_ast_ge_, args);
}

/**
 */
ReQL_ast ReQL_ast::geojson(std::vector<ReQL_ast> args) {
  return init(_reql_ast_geojson_, this, args);
}
ReQL_ast geojson(std::vector<ReQL_ast> args) {
  return init(_reql_ast_geojson_, args);
}

/**
 */
ReQL_ast ReQL_ast::get(std::vector<ReQL_ast> args) {
  return init(_reql_ast_get_, this, args);
}
ReQL_ast get(std::vector<ReQL_ast> args) {
  return init(_reql_ast_get_, args);
}

/**
 */
ReQL_ast ReQL_ast::get_all(std::vector<ReQL_ast> args, std::map<std::string, ReQL_ast> kwargs) {
  return init(_reql_ast_get_all_, this, args, kwargs);
}
ReQL_ast get_all(std::vector<ReQL_ast> args, std::map<std::string, ReQL_ast> kwargs) {
  return init(_reql_ast_get_all_, args, kwargs);
}
ReQL_ast ReQL_ast::get_all(std::vector<ReQL_ast> args) {
  return init(_reql_ast_get_all_, this, args);
}
ReQL_ast get_all(std::vector<ReQL_ast> args) {
  return init(_reql_ast_get_all_, args);
}

/**
 */
ReQL_ast ReQL_ast::get_field(std::vector<ReQL_ast> args) {
  return init(_reql_ast_get_field_, this, args);
}
ReQL_ast get_field(std::vector<ReQL_ast> args) {
  return init(_reql_ast_get_field_, args);
}

/**
 */
ReQL_ast ReQL_ast::get_intersecting(std::vector<ReQL_ast> args, std::map<std::string, ReQL_ast> kwargs) {
  return init(_reql_ast_get_intersecting_, this, args, kwargs);
}
ReQL_ast get_intersecting(std::vector<ReQL_ast> args, std::map<std::string, ReQL_ast> kwargs) {
  return init(_reql_ast_get_intersecting_, args, kwargs);
}
ReQL_ast ReQL_ast::get_intersecting(std::vector<ReQL_ast> args) {
  return init(_reql_ast_get_intersecting_, this, args);
}
ReQL_ast get_intersecting(std::vector<ReQL_ast> args) {
  return init(_reql_ast_get_intersecting_, args);
}

/**
 */
ReQL_ast ReQL_ast::get_nearest(std::vector<ReQL_ast> args, std::map<std::string, ReQL_ast> kwargs) {
  return init(_reql_ast_get_nearest_, this, args, kwargs);
}
ReQL_ast get_nearest(std::vector<ReQL_ast> args, std::map<std::string, ReQL_ast> kwargs) {
  return init(_reql_ast_get_nearest_, args, kwargs);
}
ReQL_ast ReQL_ast::get_nearest(std::vector<ReQL_ast> args) {
  return init(_reql_ast_get_nearest_, this, args);
}
ReQL_ast get_nearest(std::vector<ReQL_ast> args) {
  return init(_reql_ast_get_nearest_, args);
}

/**
 */
ReQL_ast ReQL_ast::group(std::vector<ReQL_ast> args, std::map<std::string, ReQL_ast> kwargs) {
  return init(_reql_ast_group_, this, args, kwargs);
}
ReQL_ast group(std::vector<ReQL_ast> args, std::map<std::string, ReQL_ast> kwargs) {
  return init(_reql_ast_group_, args, kwargs);
}
ReQL_ast ReQL_ast::group(std::vector<ReQL_ast> args) {
  return init(_reql_ast_group_, this, args);
}
ReQL_ast group(std::vector<ReQL_ast> args) {
  return init(_reql_ast_group_, args);
}

/**
 */
ReQL_ast ReQL_ast::gt(std::vector<ReQL_ast> args) {
  return init(_reql_ast_gt_, this, args);
}
ReQL_ast gt(std::vector<ReQL_ast> args) {
  return init(_reql_ast_gt_, args);
}

/**
 */
ReQL_ast ReQL_ast::has_fields(std::vector<ReQL_ast> args) {
  return init(_reql_ast_has_fields_, this, args);
}
ReQL_ast has_fields(std::vector<ReQL_ast> args) {
  return init(_reql_ast_has_fields_, args);
}

/**
 */
ReQL_ast ReQL_ast::hours(std::vector<ReQL_ast> args) {
  return init(_reql_ast_hours_, this, args);
}
ReQL_ast hours(std::vector<ReQL_ast> args) {
  return init(_reql_ast_hours_, args);
}

/**
 */
ReQL_ast ReQL_ast::http(std::vector<ReQL_ast> args, std::map<std::string, ReQL_ast> kwargs) {
  return init(_reql_ast_http_, this, args, kwargs);
}
ReQL_ast http(std::vector<ReQL_ast> args, std::map<std::string, ReQL_ast> kwargs) {
  return init(_reql_ast_http_, args, kwargs);
}
ReQL_ast ReQL_ast::http(std::vector<ReQL_ast> args) {
  return init(_reql_ast_http_, this, args);
}
ReQL_ast http(std::vector<ReQL_ast> args) {
  return init(_reql_ast_http_, args);
}

/**
 */
ReQL_ast ReQL_ast::implicit_var(std::vector<ReQL_ast> args) {
  return init(_reql_ast_implicit_var_, this, args);
}
ReQL_ast implicit_var(std::vector<ReQL_ast> args) {
  return init(_reql_ast_implicit_var_, args);
}

/**
 */
ReQL_ast ReQL_ast::includes(std::vector<ReQL_ast> args) {
  return init(_reql_ast_includes_, this, args);
}
ReQL_ast includes(std::vector<ReQL_ast> args) {
  return init(_reql_ast_includes_, args);
}

/**
 */
ReQL_ast ReQL_ast::indexes_of(std::vector<ReQL_ast> args) {
  return init(_reql_ast_indexes_of_, this, args);
}
ReQL_ast indexes_of(std::vector<ReQL_ast> args) {
  return init(_reql_ast_indexes_of_, args);
}

/**
 */
ReQL_ast ReQL_ast::index_create(std::vector<ReQL_ast> args, std::map<std::string, ReQL_ast> kwargs) {
  return init(_reql_ast_index_create_, this, args, kwargs);
}
ReQL_ast index_create(std::vector<ReQL_ast> args, std::map<std::string, ReQL_ast> kwargs) {
  return init(_reql_ast_index_create_, args, kwargs);
}
ReQL_ast ReQL_ast::index_create(std::vector<ReQL_ast> args) {
  return init(_reql_ast_index_create_, this, args);
}
ReQL_ast index_create(std::vector<ReQL_ast> args) {
  return init(_reql_ast_index_create_, args);
}

/**
 */
ReQL_ast ReQL_ast::index_drop(std::vector<ReQL_ast> args) {
  return init(_reql_ast_index_drop_, this, args);
}
ReQL_ast index_drop(std::vector<ReQL_ast> args) {
  return init(_reql_ast_index_drop_, args);
}

/**
 */
ReQL_ast ReQL_ast::index_list(std::vector<ReQL_ast> args) {
  return init(_reql_ast_index_list_, this, args);
}
ReQL_ast index_list(std::vector<ReQL_ast> args) {
  return init(_reql_ast_index_list_, args);
}

/**
 */
ReQL_ast ReQL_ast::index_rename(std::vector<ReQL_ast> args, std::map<std::string, ReQL_ast> kwargs) {
  return init(_reql_ast_index_rename_, this, args, kwargs);
}
ReQL_ast index_rename(std::vector<ReQL_ast> args, std::map<std::string, ReQL_ast> kwargs) {
  return init(_reql_ast_index_rename_, args, kwargs);
}
ReQL_ast ReQL_ast::index_rename(std::vector<ReQL_ast> args) {
  return init(_reql_ast_index_rename_, this, args);
}
ReQL_ast index_rename(std::vector<ReQL_ast> args) {
  return init(_reql_ast_index_rename_, args);
}

/**
 */
ReQL_ast ReQL_ast::index_status(std::vector<ReQL_ast> args) {
  return init(_reql_ast_index_status_, this, args);
}
ReQL_ast index_status(std::vector<ReQL_ast> args) {
  return init(_reql_ast_index_status_, args);
}

/**
 */
ReQL_ast ReQL_ast::index_wait(std::vector<ReQL_ast> args) {
  return init(_reql_ast_index_wait_, this, args);
}
ReQL_ast index_wait(std::vector<ReQL_ast> args) {
  return init(_reql_ast_index_wait_, args);
}

/**
 */
ReQL_ast ReQL_ast::info(std::vector<ReQL_ast> args) {
  return init(_reql_ast_info_, this, args);
}
ReQL_ast info(std::vector<ReQL_ast> args) {
  return init(_reql_ast_info_, args);
}

/**
 */
ReQL_ast ReQL_ast::inner_join(std::vector<ReQL_ast> args) {
  return init(_reql_ast_inner_join_, this, args);
}
ReQL_ast inner_join(std::vector<ReQL_ast> args) {
  return init(_reql_ast_inner_join_, args);
}

/**
 */
ReQL_ast ReQL_ast::insert(std::vector<ReQL_ast> args) {
  return init(_reql_ast_insert_, this, args);
}
ReQL_ast insert(std::vector<ReQL_ast> args) {
  return init(_reql_ast_insert_, args);
}

/**
 */
ReQL_ast ReQL_ast::insert_at(std::vector<ReQL_ast> args) {
  return init(_reql_ast_insert_at_, this, args);
}
ReQL_ast insert_at(std::vector<ReQL_ast> args) {
  return init(_reql_ast_insert_at_, args);
}

/**
 */
ReQL_ast ReQL_ast::intersects(std::vector<ReQL_ast> args) {
  return init(_reql_ast_intersects_, this, args);
}
ReQL_ast intersects(std::vector<ReQL_ast> args) {
  return init(_reql_ast_intersects_, args);
}

/**
 */
ReQL_ast ReQL_ast::in_timezone(std::vector<ReQL_ast> args) {
  return init(_reql_ast_in_timezone_, this, args);
}
ReQL_ast in_timezone(std::vector<ReQL_ast> args) {
  return init(_reql_ast_in_timezone_, args);
}

/**
 */
ReQL_ast ReQL_ast::iso8601(std::vector<ReQL_ast> args, std::map<std::string, ReQL_ast> kwargs) {
  return init(_reql_ast_iso8601_, this, args, kwargs);
}
ReQL_ast iso8601(std::vector<ReQL_ast> args, std::map<std::string, ReQL_ast> kwargs) {
  return init(_reql_ast_iso8601_, args, kwargs);
}
ReQL_ast ReQL_ast::iso8601(std::vector<ReQL_ast> args) {
  return init(_reql_ast_iso8601_, this, args);
}
ReQL_ast iso8601(std::vector<ReQL_ast> args) {
  return init(_reql_ast_iso8601_, args);
}

/**
 */
ReQL_ast ReQL_ast::is_empty(std::vector<ReQL_ast> args) {
  return init(_reql_ast_is_empty_, this, args);
}
ReQL_ast is_empty(std::vector<ReQL_ast> args) {
  return init(_reql_ast_is_empty_, args);
}

/**
 */
ReQL_ast ReQL_ast::january(std::vector<ReQL_ast> args) {
  return init(_reql_ast_january_, this, args);
}
ReQL_ast january(std::vector<ReQL_ast> args) {
  return init(_reql_ast_january_, args);
}

/**
 */
ReQL_ast ReQL_ast::javascript(std::vector<ReQL_ast> args, std::map<std::string, ReQL_ast> kwargs) {
  return init(_reql_ast_javascript_, this, args, kwargs);
}
ReQL_ast javascript(std::vector<ReQL_ast> args, std::map<std::string, ReQL_ast> kwargs) {
  return init(_reql_ast_javascript_, args, kwargs);
}
ReQL_ast ReQL_ast::javascript(std::vector<ReQL_ast> args) {
  return init(_reql_ast_javascript_, this, args);
}
ReQL_ast javascript(std::vector<ReQL_ast> args) {
  return init(_reql_ast_javascript_, args);
}

/**
 */
ReQL_ast ReQL_ast::json(std::vector<ReQL_ast> args) {
  return init(_reql_ast_json_, this, args);
}
ReQL_ast json(std::vector<ReQL_ast> args) {
  return init(_reql_ast_json_, args);
}

/**
 */
ReQL_ast ReQL_ast::july(std::vector<ReQL_ast> args) {
  return init(_reql_ast_july_, this, args);
}
ReQL_ast july(std::vector<ReQL_ast> args) {
  return init(_reql_ast_july_, args);
}

/**
 */
ReQL_ast ReQL_ast::june(std::vector<ReQL_ast> args) {
  return init(_reql_ast_june_, this, args);
}
ReQL_ast june(std::vector<ReQL_ast> args) {
  return init(_reql_ast_june_, args);
}

/**
 */
ReQL_ast ReQL_ast::keys(std::vector<ReQL_ast> args) {
  return init(_reql_ast_keys_, this, args);
}
ReQL_ast keys(std::vector<ReQL_ast> args) {
  return init(_reql_ast_keys_, args);
}

/**
 */
ReQL_ast ReQL_ast::le(std::vector<ReQL_ast> args) {
  return init(_reql_ast_le_, this, args);
}
ReQL_ast le(std::vector<ReQL_ast> args) {
  return init(_reql_ast_le_, args);
}

/**
 */
ReQL_ast ReQL_ast::limit(std::vector<ReQL_ast> args) {
  return init(_reql_ast_limit_, this, args);
}
ReQL_ast limit(std::vector<ReQL_ast> args) {
  return init(_reql_ast_limit_, args);
}

/**
 */
ReQL_ast ReQL_ast::line(std::vector<ReQL_ast> args) {
  return init(_reql_ast_line_, this, args);
}
ReQL_ast line(std::vector<ReQL_ast> args) {
  return init(_reql_ast_line_, args);
}

/**
 */
ReQL_ast ReQL_ast::literal(std::vector<ReQL_ast> args) {
  return init(_reql_ast_literal_, this, args);
}
ReQL_ast literal(std::vector<ReQL_ast> args) {
  return init(_reql_ast_literal_, args);
}

/**
 */
ReQL_ast ReQL_ast::lt(std::vector<ReQL_ast> args) {
  return init(_reql_ast_lt_, this, args);
}
ReQL_ast lt(std::vector<ReQL_ast> args) {
  return init(_reql_ast_lt_, args);
}

/**
 */
ReQL_ast ReQL_ast::make_array(std::vector<ReQL_ast> args) {
  return init(_reql_ast_make_array_, this, args);
}
ReQL_ast make_array(std::vector<ReQL_ast> args) {
  return init(_reql_ast_make_array_, args);
}

/**
 */
ReQL_ast ReQL_ast::make_obj(std::vector<ReQL_ast> args) {
  return init(_reql_ast_make_obj_, this, args);
}
ReQL_ast make_obj(std::vector<ReQL_ast> args) {
  return init(_reql_ast_make_obj_, args);
}

/**
 */
ReQL_ast ReQL_ast::map(std::vector<ReQL_ast> args) {
  return init(_reql_ast_map_, this, args);
}
ReQL_ast map(std::vector<ReQL_ast> args) {
  return init(_reql_ast_map_, args);
}

/**
 */
ReQL_ast ReQL_ast::march(std::vector<ReQL_ast> args) {
  return init(_reql_ast_march_, this, args);
}
ReQL_ast march(std::vector<ReQL_ast> args) {
  return init(_reql_ast_march_, args);
}

/**
 */
ReQL_ast ReQL_ast::match(std::vector<ReQL_ast> args) {
  return init(_reql_ast_match_, this, args);
}
ReQL_ast match(std::vector<ReQL_ast> args) {
  return init(_reql_ast_match_, args);
}

/**
 */
ReQL_ast ReQL_ast::max(std::vector<ReQL_ast> args) {
  return init(_reql_ast_max_, this, args);
}
ReQL_ast max(std::vector<ReQL_ast> args) {
  return init(_reql_ast_max_, args);
}

/**
 */
ReQL_ast ReQL_ast::may(std::vector<ReQL_ast> args) {
  return init(_reql_ast_may_, this, args);
}
ReQL_ast may(std::vector<ReQL_ast> args) {
  return init(_reql_ast_may_, args);
}

/**
 */
ReQL_ast ReQL_ast::merge(std::vector<ReQL_ast> args) {
  return init(_reql_ast_merge_, this, args);
}
ReQL_ast merge(std::vector<ReQL_ast> args) {
  return init(_reql_ast_merge_, args);
}

/**
 */
ReQL_ast ReQL_ast::min(std::vector<ReQL_ast> args) {
  return init(_reql_ast_min_, this, args);
}
ReQL_ast min(std::vector<ReQL_ast> args) {
  return init(_reql_ast_min_, args);
}

/**
 */
ReQL_ast ReQL_ast::minutes(std::vector<ReQL_ast> args) {
  return init(_reql_ast_minutes_, this, args);
}
ReQL_ast minutes(std::vector<ReQL_ast> args) {
  return init(_reql_ast_minutes_, args);
}

/**
 */
ReQL_ast ReQL_ast::mod(std::vector<ReQL_ast> args) {
  return init(_reql_ast_mod_, this, args);
}
ReQL_ast mod(std::vector<ReQL_ast> args) {
  return init(_reql_ast_mod_, args);
}

/**
 */
ReQL_ast ReQL_ast::monday(std::vector<ReQL_ast> args) {
  return init(_reql_ast_monday_, this, args);
}
ReQL_ast monday(std::vector<ReQL_ast> args) {
  return init(_reql_ast_monday_, args);
}

/**
 */
ReQL_ast ReQL_ast::month(std::vector<ReQL_ast> args) {
  return init(_reql_ast_month_, this, args);
}
ReQL_ast month(std::vector<ReQL_ast> args) {
  return init(_reql_ast_month_, args);
}

/**
 */
ReQL_ast ReQL_ast::mul(std::vector<ReQL_ast> args) {
  return init(_reql_ast_mul_, this, args);
}
ReQL_ast mul(std::vector<ReQL_ast> args) {
  return init(_reql_ast_mul_, args);
}

/**
 */
ReQL_ast ReQL_ast::ne(std::vector<ReQL_ast> args) {
  return init(_reql_ast_ne_, this, args);
}
ReQL_ast ne(std::vector<ReQL_ast> args) {
  return init(_reql_ast_ne_, args);
}

/**
 */
ReQL_ast ReQL_ast::not_(std::vector<ReQL_ast> args) {
  return init(_reql_ast_not_, this, args);
}
ReQL_ast not_(std::vector<ReQL_ast> args) {
  return init(_reql_ast_not_, args);
}

/**
 */
ReQL_ast ReQL_ast::november(std::vector<ReQL_ast> args) {
  return init(_reql_ast_november_, this, args);
}
ReQL_ast november(std::vector<ReQL_ast> args) {
  return init(_reql_ast_november_, args);
}

/**
 */
ReQL_ast ReQL_ast::now(std::vector<ReQL_ast> args) {
  return init(_reql_ast_now_, this, args);
}
ReQL_ast now(std::vector<ReQL_ast> args) {
  return init(_reql_ast_now_, args);
}

/**
 */
ReQL_ast ReQL_ast::nth(std::vector<ReQL_ast> args) {
  return init(_reql_ast_nth_, this, args);
}
ReQL_ast nth(std::vector<ReQL_ast> args) {
  return init(_reql_ast_nth_, args);
}

/**
 */
ReQL_ast ReQL_ast::object(std::vector<ReQL_ast> args) {
  return init(_reql_ast_object_, this, args);
}
ReQL_ast object(std::vector<ReQL_ast> args) {
  return init(_reql_ast_object_, args);
}

/**
 */
ReQL_ast ReQL_ast::october(std::vector<ReQL_ast> args) {
  return init(_reql_ast_october_, this, args);
}
ReQL_ast october(std::vector<ReQL_ast> args) {
  return init(_reql_ast_october_, args);
}

/**
 */
ReQL_ast ReQL_ast::order_by(std::vector<ReQL_ast> args, std::map<std::string, ReQL_ast> kwargs) {
  return init(_reql_ast_order_by_, this, args, kwargs);
}
ReQL_ast order_by(std::vector<ReQL_ast> args, std::map<std::string, ReQL_ast> kwargs) {
  return init(_reql_ast_order_by_, args, kwargs);
}
ReQL_ast ReQL_ast::order_by(std::vector<ReQL_ast> args) {
  return init(_reql_ast_order_by_, this, args);
}
ReQL_ast order_by(std::vector<ReQL_ast> args) {
  return init(_reql_ast_order_by_, args);
}

/**
 */
ReQL_ast ReQL_ast::outer_join(std::vector<ReQL_ast> args) {
  return init(_reql_ast_outer_join_, this, args);
}
ReQL_ast outer_join(std::vector<ReQL_ast> args) {
  return init(_reql_ast_outer_join_, args);
}

/**
 */
ReQL_ast ReQL_ast::pluck(std::vector<ReQL_ast> args) {
  return init(_reql_ast_pluck_, this, args);
}
ReQL_ast pluck(std::vector<ReQL_ast> args) {
  return init(_reql_ast_pluck_, args);
}

/**
 */
ReQL_ast ReQL_ast::point(std::vector<ReQL_ast> args) {
  return init(_reql_ast_point_, this, args);
}
ReQL_ast point(std::vector<ReQL_ast> args) {
  return init(_reql_ast_point_, args);
}

/**
 */
ReQL_ast ReQL_ast::polygon(std::vector<ReQL_ast> args) {
  return init(_reql_ast_polygon_, this, args);
}
ReQL_ast polygon(std::vector<ReQL_ast> args) {
  return init(_reql_ast_polygon_, args);
}

/**
 */
ReQL_ast ReQL_ast::polygon_sub(std::vector<ReQL_ast> args) {
  return init(_reql_ast_polygon_sub_, this, args);
}
ReQL_ast polygon_sub(std::vector<ReQL_ast> args) {
  return init(_reql_ast_polygon_sub_, args);
}

/**
 */
ReQL_ast ReQL_ast::prepend(std::vector<ReQL_ast> args) {
  return init(_reql_ast_prepend_, this, args);
}
ReQL_ast prepend(std::vector<ReQL_ast> args) {
  return init(_reql_ast_prepend_, args);
}

/**
 */
ReQL_ast ReQL_ast::random(std::vector<ReQL_ast> args, std::map<std::string, ReQL_ast> kwargs) {
  return init(_reql_ast_random_, this, args, kwargs);
}
ReQL_ast random(std::vector<ReQL_ast> args, std::map<std::string, ReQL_ast> kwargs) {
  return init(_reql_ast_random_, args, kwargs);
}
ReQL_ast ReQL_ast::random(std::vector<ReQL_ast> args) {
  return init(_reql_ast_random_, this, args);
}
ReQL_ast random(std::vector<ReQL_ast> args) {
  return init(_reql_ast_random_, args);
}

/**
 */
ReQL_ast ReQL_ast::range(std::vector<ReQL_ast> args) {
  return init(_reql_ast_range_, this, args);
}
ReQL_ast range(std::vector<ReQL_ast> args) {
  return init(_reql_ast_range_, args);
}

/**
 */
ReQL_ast ReQL_ast::rebalance(std::vector<ReQL_ast> args) {
  return init(_reql_ast_rebalance_, this, args);
}
ReQL_ast rebalance(std::vector<ReQL_ast> args) {
  return init(_reql_ast_rebalance_, args);
}

/**
 */
ReQL_ast ReQL_ast::reconfigure(std::vector<ReQL_ast> args) {
  return init(_reql_ast_reconfigure_, this, args);
}
ReQL_ast reconfigure(std::vector<ReQL_ast> args) {
  return init(_reql_ast_reconfigure_, args);
}

/**
 */
ReQL_ast ReQL_ast::reduce(std::vector<ReQL_ast> args) {
  return init(_reql_ast_reduce_, this, args);
}
ReQL_ast reduce(std::vector<ReQL_ast> args) {
  return init(_reql_ast_reduce_, args);
}

/**
 */
ReQL_ast ReQL_ast::replace(std::vector<ReQL_ast> args, std::map<std::string, ReQL_ast> kwargs) {
  return init(_reql_ast_replace_, this, args, kwargs);
}
ReQL_ast replace(std::vector<ReQL_ast> args, std::map<std::string, ReQL_ast> kwargs) {
  return init(_reql_ast_replace_, args, kwargs);
}
ReQL_ast ReQL_ast::replace(std::vector<ReQL_ast> args) {
  return init(_reql_ast_replace_, this, args);
}
ReQL_ast replace(std::vector<ReQL_ast> args) {
  return init(_reql_ast_replace_, args);
}

/**
 */
ReQL_ast ReQL_ast::sample(std::vector<ReQL_ast> args) {
  return init(_reql_ast_sample_, this, args);
}
ReQL_ast sample(std::vector<ReQL_ast> args) {
  return init(_reql_ast_sample_, args);
}

/**
 */
ReQL_ast ReQL_ast::saturday(std::vector<ReQL_ast> args) {
  return init(_reql_ast_saturday_, this, args);
}
ReQL_ast saturday(std::vector<ReQL_ast> args) {
  return init(_reql_ast_saturday_, args);
}

/**
 */
ReQL_ast ReQL_ast::seconds(std::vector<ReQL_ast> args) {
  return init(_reql_ast_seconds_, this, args);
}
ReQL_ast seconds(std::vector<ReQL_ast> args) {
  return init(_reql_ast_seconds_, args);
}

/**
 */
ReQL_ast ReQL_ast::september(std::vector<ReQL_ast> args) {
  return init(_reql_ast_september_, this, args);
}
ReQL_ast september(std::vector<ReQL_ast> args) {
  return init(_reql_ast_september_, args);
}

/**
 */
ReQL_ast ReQL_ast::set_difference(std::vector<ReQL_ast> args) {
  return init(_reql_ast_set_difference_, this, args);
}
ReQL_ast set_difference(std::vector<ReQL_ast> args) {
  return init(_reql_ast_set_difference_, args);
}

/**
 */
ReQL_ast ReQL_ast::set_insert(std::vector<ReQL_ast> args) {
  return init(_reql_ast_set_insert_, this, args);
}
ReQL_ast set_insert(std::vector<ReQL_ast> args) {
  return init(_reql_ast_set_insert_, args);
}

/**
 */
ReQL_ast ReQL_ast::set_intersection(std::vector<ReQL_ast> args) {
  return init(_reql_ast_set_intersection_, this, args);
}
ReQL_ast set_intersection(std::vector<ReQL_ast> args) {
  return init(_reql_ast_set_intersection_, args);
}

/**
 */
ReQL_ast ReQL_ast::set_union(std::vector<ReQL_ast> args) {
  return init(_reql_ast_set_union_, this, args);
}
ReQL_ast set_union(std::vector<ReQL_ast> args) {
  return init(_reql_ast_set_union_, args);
}

/**
 */
ReQL_ast ReQL_ast::skip(std::vector<ReQL_ast> args) {
  return init(_reql_ast_skip_, this, args);
}
ReQL_ast skip(std::vector<ReQL_ast> args) {
  return init(_reql_ast_skip_, args);
}

/**
 */
ReQL_ast ReQL_ast::slice(std::vector<ReQL_ast> args, std::map<std::string, ReQL_ast> kwargs) {
  return init(_reql_ast_slice_, this, args, kwargs);
}
ReQL_ast slice(std::vector<ReQL_ast> args, std::map<std::string, ReQL_ast> kwargs) {
  return init(_reql_ast_slice_, args, kwargs);
}
ReQL_ast ReQL_ast::slice(std::vector<ReQL_ast> args) {
  return init(_reql_ast_slice_, this, args);
}
ReQL_ast slice(std::vector<ReQL_ast> args) {
  return init(_reql_ast_slice_, args);
}

/**
 */
ReQL_ast ReQL_ast::splice_at(std::vector<ReQL_ast> args) {
  return init(_reql_ast_splice_at_, this, args);
}
ReQL_ast splice_at(std::vector<ReQL_ast> args) {
  return init(_reql_ast_splice_at_, args);
}

/**
 */
ReQL_ast ReQL_ast::split(std::vector<ReQL_ast> args) {
  return init(_reql_ast_split_, this, args);
}
ReQL_ast split(std::vector<ReQL_ast> args) {
  return init(_reql_ast_split_, args);
}

/**
 */
ReQL_ast ReQL_ast::sub(std::vector<ReQL_ast> args) {
  return init(_reql_ast_sub_, this, args);
}
ReQL_ast sub(std::vector<ReQL_ast> args) {
  return init(_reql_ast_sub_, args);
}

/**
 */
ReQL_ast ReQL_ast::sum(std::vector<ReQL_ast> args) {
  return init(_reql_ast_sum_, this, args);
}
ReQL_ast sum(std::vector<ReQL_ast> args) {
  return init(_reql_ast_sum_, args);
}

/**
 */
ReQL_ast ReQL_ast::sunday(std::vector<ReQL_ast> args) {
  return init(_reql_ast_sunday_, this, args);
}
ReQL_ast sunday(std::vector<ReQL_ast> args) {
  return init(_reql_ast_sunday_, args);
}

/**
 */
ReQL_ast ReQL_ast::sync(std::vector<ReQL_ast> args) {
  return init(_reql_ast_sync_, this, args);
}
ReQL_ast sync(std::vector<ReQL_ast> args) {
  return init(_reql_ast_sync_, args);
}

/**
 */
ReQL_ast ReQL_ast::table(std::vector<ReQL_ast> args, std::map<std::string, ReQL_ast> kwargs) {
  return init(_reql_ast_table_, this, args, kwargs);
}
ReQL_ast table(std::vector<ReQL_ast> args, std::map<std::string, ReQL_ast> kwargs) {
  return init(_reql_ast_table_, args, kwargs);
}
ReQL_ast ReQL_ast::table(std::vector<ReQL_ast> args) {
  return init(_reql_ast_table_, this, args);
}
ReQL_ast table(std::vector<ReQL_ast> args) {
  return init(_reql_ast_table_, args);
}

/**
 */
ReQL_ast ReQL_ast::table_config(std::vector<ReQL_ast> args) {
  return init(_reql_ast_table_config_, this, args);
}
ReQL_ast table_config(std::vector<ReQL_ast> args) {
  return init(_reql_ast_table_config_, args);
}

/**
 */
ReQL_ast ReQL_ast::table_create(std::vector<ReQL_ast> args, std::map<std::string, ReQL_ast> kwargs) {
  return init(_reql_ast_table_create_, this, args, kwargs);
}
ReQL_ast table_create(std::vector<ReQL_ast> args, std::map<std::string, ReQL_ast> kwargs) {
  return init(_reql_ast_table_create_, args, kwargs);
}
ReQL_ast ReQL_ast::table_create(std::vector<ReQL_ast> args) {
  return init(_reql_ast_table_create_, this, args);
}
ReQL_ast table_create(std::vector<ReQL_ast> args) {
  return init(_reql_ast_table_create_, args);
}

/**
 */
ReQL_ast ReQL_ast::table_drop(std::vector<ReQL_ast> args) {
  return init(_reql_ast_table_drop_, this, args);
}
ReQL_ast table_drop(std::vector<ReQL_ast> args) {
  return init(_reql_ast_table_drop_, args);
}

/**
 */
ReQL_ast ReQL_ast::table_list(std::vector<ReQL_ast> args) {
  return init(_reql_ast_table_list_, this, args);
}
ReQL_ast table_list(std::vector<ReQL_ast> args) {
  return init(_reql_ast_table_list_, args);
}

/**
 */
ReQL_ast ReQL_ast::table_status(std::vector<ReQL_ast> args) {
  return init(_reql_ast_table_status_, this, args);
}
ReQL_ast table_status(std::vector<ReQL_ast> args) {
  return init(_reql_ast_table_status_, args);
}

/**
 */
ReQL_ast ReQL_ast::table_wait(std::vector<ReQL_ast> args) {
  return init(_reql_ast_table_wait_, this, args);
}
ReQL_ast table_wait(std::vector<ReQL_ast> args) {
  return init(_reql_ast_table_wait_, args);
}

/**
 */
ReQL_ast ReQL_ast::thursday(std::vector<ReQL_ast> args) {
  return init(_reql_ast_thursday_, this, args);
}
ReQL_ast thursday(std::vector<ReQL_ast> args) {
  return init(_reql_ast_thursday_, args);
}

/**
 */
ReQL_ast ReQL_ast::time(std::vector<ReQL_ast> args) {
  return init(_reql_ast_time_, this, args);
}
ReQL_ast time(std::vector<ReQL_ast> args) {
  return init(_reql_ast_time_, args);
}

/**
 */
ReQL_ast ReQL_ast::timezone_(std::vector<ReQL_ast> args) {
  return init(_reql_ast_timezone_, this, args);
}
ReQL_ast timezone_(std::vector<ReQL_ast> args) {
  return init(_reql_ast_timezone_, args);
}

/**
 */
ReQL_ast ReQL_ast::time_of_day(std::vector<ReQL_ast> args) {
  return init(_reql_ast_time_of_day_, this, args);
}
ReQL_ast time_of_day(std::vector<ReQL_ast> args) {
  return init(_reql_ast_time_of_day_, args);
}

/**
 */
ReQL_ast ReQL_ast::to_epoch_time(std::vector<ReQL_ast> args) {
  return init(_reql_ast_to_epoch_time_, this, args);
}
ReQL_ast to_epoch_time(std::vector<ReQL_ast> args) {
  return init(_reql_ast_to_epoch_time_, args);
}

/**
 */
ReQL_ast ReQL_ast::to_geojson(std::vector<ReQL_ast> args) {
  return init(_reql_ast_to_geojson_, this, args);
}
ReQL_ast to_geojson(std::vector<ReQL_ast> args) {
  return init(_reql_ast_to_geojson_, args);
}

/**
 */
ReQL_ast ReQL_ast::to_iso8601(std::vector<ReQL_ast> args) {
  return init(_reql_ast_to_iso8601_, this, args);
}
ReQL_ast to_iso8601(std::vector<ReQL_ast> args) {
  return init(_reql_ast_to_iso8601_, args);
}

/**
 */
ReQL_ast ReQL_ast::to_json_string(std::vector<ReQL_ast> args) {
  return init(_reql_ast_to_json_string_, this, args);
}
ReQL_ast to_json_string(std::vector<ReQL_ast> args) {
  return init(_reql_ast_to_json_string_, args);
}

/**
 */
ReQL_ast ReQL_ast::tuesday(std::vector<ReQL_ast> args) {
  return init(_reql_ast_tuesday_, this, args);
}
ReQL_ast tuesday(std::vector<ReQL_ast> args) {
  return init(_reql_ast_tuesday_, args);
}

/**
 */
ReQL_ast ReQL_ast::type_of(std::vector<ReQL_ast> args) {
  return init(_reql_ast_type_of_, this, args);
}
ReQL_ast type_of(std::vector<ReQL_ast> args) {
  return init(_reql_ast_type_of_, args);
}

/**
 */
ReQL_ast ReQL_ast::ungroup(std::vector<ReQL_ast> args) {
  return init(_reql_ast_ungroup_, this, args);
}
ReQL_ast ungroup(std::vector<ReQL_ast> args) {
  return init(_reql_ast_ungroup_, args);
}

/**
 */
ReQL_ast ReQL_ast::union_(std::vector<ReQL_ast> args) {
  return init(_reql_ast_union_, this, args);
}
ReQL_ast union_(std::vector<ReQL_ast> args) {
  return init(_reql_ast_union_, args);
}

/**
 */
ReQL_ast ReQL_ast::upcase(std::vector<ReQL_ast> args) {
  return init(_reql_ast_upcase_, this, args);
}
ReQL_ast upcase(std::vector<ReQL_ast> args) {
  return init(_reql_ast_upcase_, args);
}

/**
 */
ReQL_ast ReQL_ast::update(std::vector<ReQL_ast> args, std::map<std::string, ReQL_ast> kwargs) {
  return init(_reql_ast_update_, this, args, kwargs);
}
ReQL_ast update(std::vector<ReQL_ast> args, std::map<std::string, ReQL_ast> kwargs) {
  return init(_reql_ast_update_, args, kwargs);
}
ReQL_ast ReQL_ast::update(std::vector<ReQL_ast> args) {
  return init(_reql_ast_update_, this, args);
}
ReQL_ast update(std::vector<ReQL_ast> args) {
  return init(_reql_ast_update_, args);
}

/**
 */
ReQL_ast ReQL_ast::uuid(std::vector<ReQL_ast> args) {
  return init(_reql_ast_uuid_, this, args);
}
ReQL_ast uuid(std::vector<ReQL_ast> args) {
  return init(_reql_ast_uuid_, args);
}

/**
 */
ReQL_ast ReQL_ast::var(std::vector<ReQL_ast> args) {
  return init(_reql_ast_var_, this, args);
}
ReQL_ast var(std::vector<ReQL_ast> args) {
  return init(_reql_ast_var_, args);
}

/**
 */
ReQL_ast ReQL_ast::wednesday(std::vector<ReQL_ast> args) {
  return init(_reql_ast_wednesday_, this, args);
}
ReQL_ast wednesday(std::vector<ReQL_ast> args) {
  return init(_reql_ast_wednesday_, args);
}

/**
 */
ReQL_ast ReQL_ast::without(std::vector<ReQL_ast> args) {
  return init(_reql_ast_without_, this, args);
}
ReQL_ast without(std::vector<ReQL_ast> args) {
  return init(_reql_ast_without_, args);
}

/**
 */
ReQL_ast ReQL_ast::with_fields(std::vector<ReQL_ast> args) {
  return init(_reql_ast_with_fields_, this, args);
}
ReQL_ast with_fields(std::vector<ReQL_ast> args) {
  return init(_reql_ast_with_fields_, args);
}

/**
 */
ReQL_ast ReQL_ast::year(std::vector<ReQL_ast> args) {
  return init(_reql_ast_year_, this, args);
}
ReQL_ast year(std::vector<ReQL_ast> args) {
  return init(_reql_ast_year_, args);
}

/**
 */
ReQL_ast ReQL_ast::zip(std::vector<ReQL_ast> args) {
  return init(_reql_ast_zip_, this, args);
}
ReQL_ast zip(std::vector<ReQL_ast> args) {
  return init(_reql_ast_zip_, args);
}
