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

#include "ReQL-ast.h"

#include <stdlib.h>

/**
 */
_ReQL_Op _reql_ast_add(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_add_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_add_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_ADD;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_all(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_all_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_all_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_ALL;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_any(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_any_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_any_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_ANY;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_append(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_append_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_append_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_APPEND;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_april(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_april_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_april_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_APRIL;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_args(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_args_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_args_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_ARGS;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_asc(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_asc_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_asc_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_ASC;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_august(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_august_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_august_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_AUGUST;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_avg(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_avg_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_avg_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_AVG;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_between(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_between_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_between_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_BETWEEN;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_binary(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_binary_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_binary_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_BINARY;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_bracket(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_bracket_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_bracket_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_BRACKET;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_branch(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_branch_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_branch_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_BRANCH;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_changes(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_changes_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_changes_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_CHANGES;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_change_at(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_change_at_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_change_at_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_CHANGE_AT;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_circle(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_circle_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_circle_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_CIRCLE;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_coerce_to(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_coerce_to_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_coerce_to_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_COERCE_TO;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_concat_map(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_concat_map_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_concat_map_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_CONCAT_MAP;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_contains(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_contains_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_contains_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_CONTAINS;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_count(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_count_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_count_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_COUNT;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_date(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_date_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_date_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_DATE;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_datum(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_datum_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_datum_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_DATUM;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_day(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_day_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_day_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_DAY;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_day_of_week(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_day_of_week_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_day_of_week_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_DAY_OF_WEEK;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_day_of_year(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_day_of_year_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_day_of_year_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_DAY_OF_YEAR;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_db(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_db_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_db_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_DB;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_db_config(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_db_config_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_db_config_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_DB_CONFIG;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_db_create(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_db_create_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_db_create_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_DB_CREATE;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_db_drop(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_db_drop_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_db_drop_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_DB_DROP;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_db_list(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_db_list_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_db_list_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_DB_LIST;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_december(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_december_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_december_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_DECEMBER;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_default(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_default_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_default_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_DEFAULT;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_delete(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_delete_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_delete_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_DELETE;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_delete_at(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_delete_at_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_delete_at_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_DELETE_AT;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_desc(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_desc_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_desc_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_DESC;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_difference(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_difference_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_difference_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_DIFFERENCE;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_distance(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_distance_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_distance_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_DISTANCE;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_distinct(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_distinct_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_distinct_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_DISTINCT;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_div(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_div_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_div_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_DIV;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_downcase(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_downcase_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_downcase_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_DOWNCASE;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_during(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_during_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_during_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_DURING;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_epoch_time(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_epoch_time_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_epoch_time_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_EPOCH_TIME;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_eq(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_eq_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_eq_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_EQ;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_eq_join(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_eq_join_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_eq_join_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_EQ_JOIN;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_error(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_error_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_error_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_ERROR;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_february(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_february_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_february_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_FEBRUARY;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_fill(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_fill_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_fill_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_FILL;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_filter(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_filter_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_filter_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_FILTER;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_for_each(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_for_each_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_for_each_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_FOR_EACH;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_friday(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_friday_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_friday_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_FRIDAY;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_func(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_func_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_func_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_FUNC;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_funcall(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_funcall_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_funcall_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_FUNCALL;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_ge(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_ge_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_ge_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_GE;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_geojson(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_geojson_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_geojson_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_GEOJSON;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_get(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_get_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_get_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_GET;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_get_all(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_get_all_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_get_all_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_GET_ALL;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_get_field(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_get_field_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_get_field_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_GET_FIELD;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_get_intersecting(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_get_intersecting_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_get_intersecting_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_GET_INTERSECTING;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_get_nearest(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_get_nearest_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_get_nearest_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_GET_NEAREST;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_group(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_group_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_group_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_GROUP;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_gt(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_gt_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_gt_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_GT;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_has_fields(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_has_fields_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_has_fields_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_HAS_FIELDS;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_hours(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_hours_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_hours_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_HOURS;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_http(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_http_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_http_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_HTTP;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_implicit_var(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_implicit_var_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_implicit_var_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_IMPLICIT_VAR;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_includes(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_includes_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_includes_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_INCLUDES;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_indexes_of(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_indexes_of_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_indexes_of_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_INDEXES_OF;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_index_create(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_index_create_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_index_create_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_INDEX_CREATE;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_index_drop(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_index_drop_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_index_drop_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_INDEX_DROP;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_index_list(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_index_list_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_index_list_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_INDEX_LIST;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_index_rename(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_index_rename_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_index_rename_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_INDEX_RENAME;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_index_status(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_index_status_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_index_status_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_INDEX_STATUS;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_index_wait(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_index_wait_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_index_wait_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_INDEX_WAIT;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_info(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_info_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_info_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_INFO;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_inner_join(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_inner_join_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_inner_join_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_INNER_JOIN;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_insert(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_insert_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_insert_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_INSERT;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_insert_at(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_insert_at_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_insert_at_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_INSERT_AT;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_intersects(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_intersects_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_intersects_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_INTERSECTS;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_in_timezone(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_in_timezone_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_in_timezone_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_IN_TIMEZONE;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_iso8601(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_iso8601_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_iso8601_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_ISO8601;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_is_empty(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_is_empty_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_is_empty_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_IS_EMPTY;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_january(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_january_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_january_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_JANUARY;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_javascript(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_javascript_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_javascript_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_JAVASCRIPT;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_json(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_json_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_json_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_JSON;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_july(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_july_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_july_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_JULY;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_june(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_june_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_june_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_JUNE;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_keys(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_keys_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_keys_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_KEYS;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_le(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_le_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_le_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_LE;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_limit(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_limit_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_limit_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_LIMIT;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_line(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_line_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_line_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_LINE;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_literal(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_literal_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_literal_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_LITERAL;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_lt(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_lt_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_lt_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_LT;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_make_array(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_make_array_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_make_array_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_MAKE_ARRAY;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_make_obj(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_make_obj_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_make_obj_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_MAKE_OBJ;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_map(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_map_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_map_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_MAP;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_march(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_march_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_march_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_MARCH;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_match(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_match_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_match_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_MATCH;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_max(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_max_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_max_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_MAX;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_may(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_may_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_may_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_MAY;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_merge(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_merge_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_merge_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_MERGE;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_min(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_min_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_min_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_MIN;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_minutes(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_minutes_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_minutes_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_MINUTES;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_mod(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_mod_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_mod_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_MOD;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_monday(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_monday_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_monday_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_MONDAY;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_month(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_month_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_month_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_MONTH;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_mul(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_mul_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_mul_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_MUL;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_ne(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_ne_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_ne_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_NE;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_not(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_not_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_not_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_NOT;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_november(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_november_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_november_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_NOVEMBER;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_now(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_now_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_now_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_NOW;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_nth(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_nth_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_nth_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_NTH;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_object(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_object_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_object_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_OBJECT;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_october(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_october_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_october_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_OCTOBER;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_order_by(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_order_by_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_order_by_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_ORDER_BY;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_outer_join(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_outer_join_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_outer_join_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_OUTER_JOIN;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_pluck(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_pluck_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_pluck_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_PLUCK;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_point(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_point_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_point_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_POINT;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_polygon(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_polygon_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_polygon_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_POLYGON;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_polygon_sub(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_polygon_sub_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_polygon_sub_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_POLYGON_SUB;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_prepend(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_prepend_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_prepend_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_PREPEND;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_random(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_random_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_random_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_RANDOM;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_range(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_range_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_range_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_RANGE;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_rebalance(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_rebalance_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_rebalance_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_REBALANCE;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_reconfigure(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_reconfigure_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_reconfigure_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_RECONFIGURE;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_reduce(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_reduce_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_reduce_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_REDUCE;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_replace(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_replace_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_replace_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_REPLACE;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_sample(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_sample_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_sample_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_SAMPLE;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_saturday(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_saturday_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_saturday_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_SATURDAY;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_seconds(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_seconds_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_seconds_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_SECONDS;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_september(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_september_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_september_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_SEPTEMBER;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_set_difference(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_set_difference_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_set_difference_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_SET_DIFFERENCE;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_set_insert(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_set_insert_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_set_insert_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_SET_INSERT;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_set_intersection(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_set_intersection_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_set_intersection_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_SET_INTERSECTION;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_set_union(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_set_union_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_set_union_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_SET_UNION;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_skip(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_skip_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_skip_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_SKIP;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_slice(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_slice_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_slice_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_SLICE;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_splice_at(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_splice_at_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_splice_at_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_SPLICE_AT;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_split(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_split_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_split_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_SPLIT;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_sub(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_sub_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_sub_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_SUB;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_sum(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_sum_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_sum_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_SUM;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_sunday(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_sunday_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_sunday_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_SUNDAY;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_sync(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_sync_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_sync_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_SYNC;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_table(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_table_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_table_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_TABLE;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_table_config(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_table_config_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_table_config_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_TABLE_CONFIG;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_table_create(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_table_create_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_table_create_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_TABLE_CREATE;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_table_drop(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_table_drop_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_table_drop_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_TABLE_DROP;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_table_list(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_table_list_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_table_list_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_TABLE_LIST;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_table_status(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_table_status_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_table_status_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_TABLE_STATUS;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_table_wait(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_table_wait_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_table_wait_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_TABLE_WAIT;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_thursday(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_thursday_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_thursday_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_THURSDAY;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_time(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_time_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_time_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_TIME;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_timezone(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_timezone_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_timezone_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_TIMEZONE;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_time_of_day(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_time_of_day_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_time_of_day_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_TIME_OF_DAY;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_to_epoch_time(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_to_epoch_time_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_to_epoch_time_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_TO_EPOCH_TIME;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_to_geojson(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_to_geojson_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_to_geojson_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_TO_GEOJSON;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_to_iso8601(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_to_iso8601_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_to_iso8601_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_TO_ISO8601;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_to_json_string(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_to_json_string_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_to_json_string_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_TO_JSON_STRING;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_tuesday(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_tuesday_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_tuesday_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_TUESDAY;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_type_of(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_type_of_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_type_of_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_TYPE_OF;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_ungroup(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_ungroup_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_ungroup_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_UNGROUP;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_union(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_union_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_union_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_UNION;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_upcase(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_upcase_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_upcase_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_UPCASE;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_update(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_update_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_update_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_UPDATE;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_uuid(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_uuid_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_uuid_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_UUID;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_var(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_var_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_var_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_VAR;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_wednesday(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_wednesday_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_wednesday_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_WEDNESDAY;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_without(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_without_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_without_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_WITHOUT;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_with_fields(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_with_fields_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_with_fields_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_WITH_FIELDS;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_year(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_year_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_year_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_YEAR;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}

/**
 */
_ReQL_Op _reql_ast_zip(_ReQL_Op args, _ReQL_Op kwargs) {
  return _reql_ast_zip_(NULL, args, kwargs);
}

/**
 */
_ReQL_Op _reql_ast_zip_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term = _reql_json_null(term);
  term->tt = _REQL_ZIP;
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
  return term;
}
