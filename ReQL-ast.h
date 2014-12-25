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

#include "ReQL-json.h"

#ifndef _REQL_AST_H
#define _REQL_AST_H

typedef _ReQL_Op (*_ReQL_AST_Function) (_ReQL_Op, _ReQL_Op);
typedef _ReQL_Op (*_ReQL_AST_Function_) (_ReQL_Op, _ReQL_Op , _ReQL_Op);

/**
 */
_ReQL_Op _reql_ast_add(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_add_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_all(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_all_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_any(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_any_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_append(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_append_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_april(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_april_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_args(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_args_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_asc(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_asc_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_august(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_august_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_avg(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_avg_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_between(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_between_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_binary(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_binary_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_bracket(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_bracket_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_branch(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_branch_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_changes(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_changes_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_change_at(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_change_at_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_circle(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_circle_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_coerce_to(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_coerce_to_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_concat_map(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_concat_map_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_contains(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_contains_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_count(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_count_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_date(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_date_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_datum(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_datum_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_day(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_day_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_day_of_week(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_day_of_week_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_day_of_year(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_day_of_year_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_db(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_db_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_db_config(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_db_config_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_db_create(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_db_create_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_db_drop(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_db_drop_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_db_list(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_db_list_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_december(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_december_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_default(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_default_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_delete(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_delete_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_delete_at(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_delete_at_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_desc(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_desc_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_difference(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_difference_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_distance(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_distance_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_distinct(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_distinct_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_div(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_div_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_downcase(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_downcase_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_during(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_during_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_epoch_time(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_epoch_time_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_eq(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_eq_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_eq_join(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_eq_join_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_error(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_error_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_february(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_february_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_fill(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_fill_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_filter(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_filter_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_for_each(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_for_each_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_friday(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_friday_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_func(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_func_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_funcall(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_funcall_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_ge(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_ge_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_geojson(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_geojson_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_get(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_get_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_get_all(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_get_all_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_get_field(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_get_field_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_get_intersecting(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_get_intersecting_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_get_nearest(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_get_nearest_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_group(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_group_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_gt(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_gt_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_has_fields(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_has_fields_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_hours(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_hours_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_http(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_http_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_implicit_var(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_implicit_var_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_includes(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_includes_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_indexes_of(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_indexes_of_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_index_create(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_index_create_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_index_drop(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_index_drop_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_index_list(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_index_list_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_index_rename(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_index_rename_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_index_status(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_index_status_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_index_wait(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_index_wait_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_info(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_info_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_inner_join(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_inner_join_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_insert(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_insert_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_insert_at(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_insert_at_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_intersects(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_intersects_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_in_timezone(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_in_timezone_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_iso8601(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_iso8601_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_is_empty(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_is_empty_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_january(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_january_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_javascript(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_javascript_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_json(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_json_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_july(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_july_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_june(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_june_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_keys(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_keys_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_le(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_le_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_limit(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_limit_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_line(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_line_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_literal(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_literal_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_lt(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_lt_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_make_array(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_make_array_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_make_obj(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_make_obj_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_map(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_map_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_march(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_march_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_match(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_match_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_max(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_max_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_may(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_may_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_merge(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_merge_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_min(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_min_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_minutes(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_minutes_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_mod(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_mod_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_monday(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_monday_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_month(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_month_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_mul(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_mul_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_ne(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_ne_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_not(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_not_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_november(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_november_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_now(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_now_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_nth(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_nth_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_object(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_object_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_october(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_october_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_order_by(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_order_by_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_outer_join(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_outer_join_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_pluck(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_pluck_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_point(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_point_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_polygon(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_polygon_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_polygon_sub(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_polygon_sub_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_prepend(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_prepend_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_random(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_random_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_range(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_range_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_rebalance(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_rebalance_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_reconfigure(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_reconfigure_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_reduce(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_reduce_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_replace(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_replace_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_sample(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_sample_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_saturday(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_saturday_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_seconds(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_seconds_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_september(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_september_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_set_difference(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_set_difference_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_set_insert(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_set_insert_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_set_intersection(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_set_intersection_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_set_union(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_set_union_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_skip(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_skip_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_slice(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_slice_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_splice_at(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_splice_at_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_split(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_split_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_sub(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_sub_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_sum(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_sum_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_sunday(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_sunday_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_sync(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_sync_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_table(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_table_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_table_config(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_table_config_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_table_create(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_table_create_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_table_drop(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_table_drop_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_table_list(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_table_list_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_table_status(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_table_status_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_table_wait(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_table_wait_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_thursday(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_thursday_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_time(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_time_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_timezone(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_timezone_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_time_of_day(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_time_of_day_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_to_epoch_time(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_to_epoch_time_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_to_geojson(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_to_geojson_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_to_iso8601(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_to_iso8601_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_to_json_string(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_to_json_string_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_tuesday(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_tuesday_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_type_of(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_type_of_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_ungroup(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_ungroup_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_union(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_union_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_upcase(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_upcase_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_update(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_update_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_uuid(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_uuid_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_var(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_var_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_wednesday(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_wednesday_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_without(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_without_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_with_fields(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_with_fields_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_year(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_year_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
_ReQL_Op _reql_ast_zip(_ReQL_Op args, _ReQL_Op kwargs);
/**
 */
_ReQL_Op _reql_ast_zip_(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

#endif
