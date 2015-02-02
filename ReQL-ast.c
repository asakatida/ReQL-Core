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

#include "ReQL-ast.h"

#include <stdlib.h>

extern void
_reql_ast_add(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_ADD);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_all(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_ALL);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_any(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_ANY);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_append(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_APPEND);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_april(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_APRIL);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_args(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_ARGS);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_asc(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_ASC);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_august(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_AUGUST);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_avg(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_AVG);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_between(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_BETWEEN);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_binary(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_BINARY);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_bracket(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_BRACKET);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_branch(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_BRANCH);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_changes(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_CHANGES);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_change_at(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_CHANGE_AT);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_circle(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_CIRCLE);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_coerce_to(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_COERCE_TO);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_concat_map(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_CONCAT_MAP);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_config(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_CONFIG);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_contains(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_CONTAINS);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_count(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_COUNT);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_date(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_DATE);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_datum(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_DATUM);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_day(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_DAY);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_day_of_week(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_DAY_OF_WEEK);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_day_of_year(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_DAY_OF_YEAR);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_db(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_DB);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_db_create(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_DB_CREATE);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_db_drop(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_DB_DROP);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_db_list(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_DB_LIST);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_december(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_DECEMBER);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_default(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_DEFAULT);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_delete(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_DELETE);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_delete_at(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_DELETE_AT);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_desc(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_DESC);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_difference(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_DIFFERENCE);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_distance(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_DISTANCE);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_distinct(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_DISTINCT);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_div(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_DIV);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_downcase(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_DOWNCASE);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_during(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_DURING);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_epoch_time(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_EPOCH_TIME);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_eq(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_EQ);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_eq_join(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_EQ_JOIN);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_error(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_ERROR);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_february(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_FEBRUARY);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_fill(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_FILL);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_filter(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_FILTER);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_for_each(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_FOR_EACH);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_friday(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_FRIDAY);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_func(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_FUNC);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_funcall(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_FUNCALL);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_ge(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_GE);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_geojson(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_GEOJSON);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_get(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_GET);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_get_all(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_GET_ALL);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_get_field(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_GET_FIELD);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_get_intersecting(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_GET_INTERSECTING);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_get_nearest(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_GET_NEAREST);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_group(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_GROUP);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_gt(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_GT);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_has_fields(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_HAS_FIELDS);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_hours(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_HOURS);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_http(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_HTTP);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_implicit_var(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_IMPLICIT_VAR);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_includes(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_INCLUDES);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_indexes_of(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_INDEXES_OF);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_index_create(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_INDEX_CREATE);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_index_drop(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_INDEX_DROP);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_index_list(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_INDEX_LIST);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_index_rename(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_INDEX_RENAME);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_index_status(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_INDEX_STATUS);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_index_wait(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_INDEX_WAIT);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_info(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_INFO);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_inner_join(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_INNER_JOIN);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_insert(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_INSERT);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_insert_at(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_INSERT_AT);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_intersects(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_INTERSECTS);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_in_timezone(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_IN_TIMEZONE);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_iso8601(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_ISO8601);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_is_empty(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_IS_EMPTY);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_january(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_JANUARY);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_javascript(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_JAVASCRIPT);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_json(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_JSON);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_july(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_JULY);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_june(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_JUNE);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_keys(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_KEYS);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_le(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_LE);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_limit(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_LIMIT);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_line(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_LINE);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_literal(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_LITERAL);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_lt(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_LT);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_make_array(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_MAKE_ARRAY);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_make_obj(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_MAKE_OBJ);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_map(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_MAP);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_march(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_MARCH);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_match(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_MATCH);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_max(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_MAX);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_may(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_MAY);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_merge(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_MERGE);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_min(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_MIN);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_minutes(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_MINUTES);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_mod(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_MOD);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_monday(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_MONDAY);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_month(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_MONTH);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_mul(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_MUL);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_ne(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_NE);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_not(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_NOT);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_november(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_NOVEMBER);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_now(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_NOW);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_nth(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_NTH);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_object(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_OBJECT);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_october(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_OCTOBER);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_order_by(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_ORDER_BY);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_outer_join(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_OUTER_JOIN);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_pluck(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_PLUCK);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_point(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_POINT);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_polygon(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_POLYGON);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_polygon_sub(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_POLYGON_SUB);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_prepend(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_PREPEND);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_random(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_RANDOM);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_range(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_RANGE);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_rebalance(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_REBALANCE);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_reconfigure(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_RECONFIGURE);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_reduce(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_REDUCE);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_replace(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_REPLACE);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_sample(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_SAMPLE);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_saturday(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_SATURDAY);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_seconds(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_SECONDS);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_september(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_SEPTEMBER);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_set_difference(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_SET_DIFFERENCE);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_set_insert(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_SET_INSERT);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_set_intersection(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_SET_INTERSECTION);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_set_union(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_SET_UNION);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_skip(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_SKIP);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_slice(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_SLICE);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_splice_at(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_SPLICE_AT);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_split(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_SPLIT);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_status(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_STATUS);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_sub(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_SUB);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_sum(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_SUM);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_sunday(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_SUNDAY);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_sync(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_SYNC);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_table(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_TABLE);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_table_create(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_TABLE_CREATE);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_table_drop(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_TABLE_DROP);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_table_list(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_TABLE_LIST);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_thursday(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_THURSDAY);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_time(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_TIME);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_timezone(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_TIMEZONE);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_time_of_day(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_TIME_OF_DAY);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_to_epoch_time(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_TO_EPOCH_TIME);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_to_geojson(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_TO_GEOJSON);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_to_iso8601(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_TO_ISO8601);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_to_json_string(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_TO_JSON_STRING);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_tuesday(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_TUESDAY);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_type_of(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_TYPE_OF);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_ungroup(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_UNGROUP);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_union(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_UNION);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_upcase(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_UPCASE);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_update(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_UPDATE);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_uuid(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_UUID);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_var(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_VAR);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_wait(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_WAIT);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_wednesday(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_WEDNESDAY);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_without(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_WITHOUT);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_with_fields(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_WITH_FIELDS);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_year(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_YEAR);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}

extern void
_reql_ast_zip(_ReQL_Obj_t *term, _ReQL_Obj_t *args, _ReQL_Obj_t *kwargs) {
  _reql_obj_set_term_type(term, _REQL_ZIP);
  _reql_obj_set_args(term, args);
  _reql_obj_set_kwargs(term, kwargs);
}
