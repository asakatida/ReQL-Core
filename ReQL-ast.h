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

typedef void (*_ReQL_AST_Function) (_ReQL_Op, _ReQL_Op , _ReQL_Op);

/**
 */
void _reql_ast_add(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_all(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_any(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_append(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_april(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_args(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_asc(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_august(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_avg(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_between(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_binary(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_bracket(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_branch(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_changes(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_change_at(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_circle(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_coerce_to(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_concat_map(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_contains(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_count(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_date(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_datum(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_day(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_day_of_week(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_day_of_year(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_db(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_db_config(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_db_create(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_db_drop(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_db_list(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_december(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_default(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_delete(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_delete_at(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_desc(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_difference(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_distance(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_distinct(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_div(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_downcase(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_during(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_epoch_time(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_eq(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_eq_join(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_error(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_february(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_fill(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_filter(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_for_each(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_friday(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_func(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_funcall(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_ge(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_geojson(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_get(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_get_all(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_get_field(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_get_intersecting(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_get_nearest(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_group(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_gt(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_has_fields(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_hours(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_http(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_implicit_var(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_includes(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_indexes_of(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_index_create(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_index_drop(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_index_list(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_index_rename(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_index_status(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_index_wait(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_info(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_inner_join(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_insert(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_insert_at(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_intersects(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_in_timezone(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_iso8601(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_is_empty(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_january(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_javascript(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_json(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_july(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_june(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_keys(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_le(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_limit(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_line(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_literal(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_lt(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_make_array(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_make_obj(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_map(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_march(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_match(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_max(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_may(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_merge(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_min(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_minutes(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_mod(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_monday(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_month(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_mul(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_ne(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_not(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_november(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_now(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_nth(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_object(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_october(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_order_by(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_outer_join(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_pluck(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_point(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_polygon(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_polygon_sub(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_prepend(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_random(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_range(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_rebalance(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_reconfigure(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_reduce(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_replace(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_sample(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_saturday(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_seconds(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_september(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_set_difference(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_set_insert(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_set_intersection(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_set_union(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_skip(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_slice(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_splice_at(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_split(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_sub(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_sum(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_sunday(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_sync(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_table(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_table_config(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_table_create(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_table_drop(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_table_list(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_table_status(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_table_wait(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_thursday(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_time(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_timezone(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_time_of_day(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_to_epoch_time(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_to_geojson(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_to_iso8601(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_to_json_string(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_tuesday(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_type_of(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_ungroup(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_union(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_upcase(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_update(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_uuid(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_var(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_wednesday(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_without(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_with_fields(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_year(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

/**
 */
void _reql_ast_zip(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);

#endif
