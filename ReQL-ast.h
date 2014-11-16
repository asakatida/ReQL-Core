/**
 * @author Adam Grandquist
 */

#include "ReQL-expr.h"

#ifndef _REQL_AST_H
#define _REQL_AST_H

/**
 */
_ReQL_Op_t *_reql_add(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_all(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_any(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_append(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_april(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_args(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_asc(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_august(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_avg(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_between(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_binary(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_bracket(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_branch(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_changes(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_change_at(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_circle(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_coerce_to(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_concat_map(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_contains(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_count(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_date(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_datum(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_day(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_day_of_week(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_day_of_year(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_db(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_db_create(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_db_drop(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_db_list(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_december(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_default_(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_delete_(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_delete_at(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_desc(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_difference(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_distance(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_distinct(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_div(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_downcase(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_during(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_epoch_time(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_eq(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_eq_join(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_error(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_february(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_fill(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_filter(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_for_each(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_friday(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_func(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_funcall(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_ge(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_geojson(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_get(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_get_all(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_get_field(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_get_intersecting(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_get_nearest(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_group(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_gt(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_has_fields(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_hours(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_http(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_implicit_var(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_includes(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_indexes_of(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_index_create(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_index_drop(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_index_list(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_index_rename(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_index_status(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_index_wait(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_info(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_inner_join(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_insert(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_insert_at(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_intersects(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_in_timezone(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_iso8601(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_is_empty(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_january(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_javascript(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_json(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_july(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_june(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_keys(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_le(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_limit(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_line(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_literal(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_lt(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_make_array(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_make_obj(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_map(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_march(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_match(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_max(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_may(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_merge(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_min(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_minutes(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_mod(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_monday(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_month(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_mul(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_ne(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_not_(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_november(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_now(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_nth(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_object(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_october(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_order_by(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_outer_join(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_pluck(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_point(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_polygon(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_polygon_sub(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_prepend(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_random(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_range(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_reduce(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_replace(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_sample(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_saturday(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_seconds(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_september(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_set_difference(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_set_insert(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_set_intersection(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_set_union(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_skip(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_slice(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_splice_at(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_split(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_sub(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_sum(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_sunday(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_sync(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_table(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_table_create(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_table_drop(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_table_list(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_thursday(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_time(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_timezone(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_time_of_day(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_to_epoch_time(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_to_geojson(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_to_iso8601(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_to_json_string(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_tuesday(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_type_of(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_ungroup(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_union_(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_upcase(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_update(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_uuid(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_var(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_wednesday(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_without(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_with_fields(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_year(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_zip(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

#endif
