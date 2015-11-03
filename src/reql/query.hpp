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

#ifndef REQL_REQL_QUERY_H_
#define REQL_REQL_QUERY_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "./reql/types.h"

typedef void (*ReQL_AST_Function_Kwargs) (ReQL_ReQL_t *, ReQL_Array_t (*)(void *), ReQL_Obj_t (*)(void *), void *);
typedef void (*ReQL_AST_Function) (ReQL_ReQL_t *, ReQL_Array_t (*)(void *), void *);

extern ReQL_Term_t
reql_term_type(const ReQL_ReQL_t *obj);

extern ReQL_Datum_t
reql_datum_type(const ReQL_Any_t *obj);

extern ReQL_Size
reql_size(const ReQL_String_t *obj);

extern void
reql_string_init(ReQL_String_t *obj,
                 ReQL_Byte *(*buffer)(void *),
                 ReQL_Size (*size)(void *),
                 void *data);

extern ReQL_Byte *
reql_string_buf(const ReQL_String_t *obj);

extern void
reql_array_iter_init(ReQL_Array_Iter_t *iter, const ReQL_Array_t *obj);

extern ReQL_Any_t *
reql_array_iter_next(ReQL_Array_Iter_t *obj);

extern void
reql_object_iter_init(ReQL_Object_Iter_t *iter, const ReQL_Obj_t *obj);

extern ReQL_Pair_t *
reql_object_iter_next(ReQL_Object_Iter_t *obj);

extern void
reql_array_init(ReQL_Array_t *obj,
                ReQL_Any_t *(*get)(void *, ReQL_Size),
                ReQL_Size (*size)(void *),
                void *data);

extern void
reql_object_init(ReQL_Obj_t *obj,
                 ReQL_Pair_t *(*get)(void *, ReQL_Size),
                 ReQL_Size (*size)(void *),
                 void *data);

/**
 */
extern void
reql_ast_add(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_and(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_append(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_april(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_args(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_asc(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_august(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_avg(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_between(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_between_deprecated(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_binary(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_bracket(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_branch(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_ceil(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_changes(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_change_at(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_circle(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  ReQL_Obj_t (*k)(void *),
  void *d);

/**
 */
extern void
reql_ast_coerce_to(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_concat_map(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_config(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_contains(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_count(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_date(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_datum(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_day(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_day_of_week(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_day_of_year(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_db(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_db_create(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_db_drop(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_db_list(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_december(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_default(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_delete(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  ReQL_Obj_t (*k)(void *),
  void *d);

/**
 */
extern void
reql_ast_delete_at(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_desc(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_difference(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_distance(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_distinct(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  ReQL_Obj_t (*k)(void *),
  void *d);

/**
 */
extern void
reql_ast_div(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_downcase(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_during(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_epoch_time(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_eq(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_eq_join(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  ReQL_Obj_t (*k)(void *),
  void *d);

/**
 */
extern void
reql_ast_error(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_february(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_fill(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_filter(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  ReQL_Obj_t (*k)(void *),
  void *d);

/**
 */
extern void
reql_ast_floor(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_for_each(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_friday(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_func(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_funcall(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_ge(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_geojson(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_get(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_get_all(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  ReQL_Obj_t (*k)(void *),
  void *d);

/**
 */
extern void
reql_ast_get_field(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_get_intersecting(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  ReQL_Obj_t (*k)(void *),
  void *d);

/**
 */
extern void
reql_ast_get_nearest(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  ReQL_Obj_t (*k)(void *),
  void *d);

/**
 */
extern void
reql_ast_group(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  ReQL_Obj_t (*k)(void *),
  void *d);

/**
 */
extern void
reql_ast_gt(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_has_fields(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_hours(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_http(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  ReQL_Obj_t (*k)(void *),
  void *d);

/**
 */
extern void
reql_ast_implicit_var(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_includes(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_index_create(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  ReQL_Obj_t (*k)(void *),
  void *d);

/**
 */
extern void
reql_ast_index_drop(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_index_list(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_index_rename(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  ReQL_Obj_t (*k)(void *),
  void *d);

/**
 */
extern void
reql_ast_index_status(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_index_wait(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_info(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_inner_join(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_insert(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_insert_at(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_intersects(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_in_timezone(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_iso8601(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  ReQL_Obj_t (*k)(void *),
  void *d);

/**
 */
extern void
reql_ast_is_empty(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_january(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_javascript(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  ReQL_Obj_t (*k)(void *),
  void *d);

/**
 */
extern void
reql_ast_json(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_july(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_june(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_keys(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_le(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_limit(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_line(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_literal(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_lt(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_make_array(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_make_obj(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_map(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_march(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_match(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_max(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_maxval(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_may(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_merge(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_min(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_minutes(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_minval(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_mod(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_monday(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_month(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_mul(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_ne(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_not(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_november(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_now(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_nth(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_object(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_october(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_offsets_of(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_or(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_order_by(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  ReQL_Obj_t (*k)(void *),
  void *d);

/**
 */
extern void
reql_ast_outer_join(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_pluck(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_point(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_polygon(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_polygon_sub(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_prepend(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_random(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  ReQL_Obj_t (*k)(void *),
  void *d);

/**
 */
extern void
reql_ast_range(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_rebalance(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_reconfigure(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_reduce(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_replace(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  ReQL_Obj_t (*k)(void *),
  void *d);

/**
 */
extern void
reql_ast_round(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_sample(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_saturday(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_seconds(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_september(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_set_difference(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_set_insert(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_set_intersection(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_set_union(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_skip(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_slice(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  ReQL_Obj_t (*k)(void *),
  void *d);

/**
 */
extern void
reql_ast_splice_at(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_split(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_status(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_sub(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_sum(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_sunday(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_sync(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_table(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  ReQL_Obj_t (*k)(void *),
  void *d);

/**
 */
extern void
reql_ast_table_create(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  ReQL_Obj_t (*k)(void *),
  void *d);

/**
 */
extern void
reql_ast_table_drop(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_table_list(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_thursday(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_time(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_timezone(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_time_of_day(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_to_epoch_time(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_to_geojson(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_to_iso8601(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_to_json_string(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_tuesday(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_type_of(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_ungroup(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_union(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_upcase(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_update(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  ReQL_Obj_t (*k)(void *),
  void *d);

/**
 */
extern void
reql_ast_uuid(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_values(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_var(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_wait(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_wednesday(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_without(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_with_fields(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_year(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

/**
 */
extern void
reql_ast_zip(
  ReQL_ReQL_t *t,
  ReQL_Array_t (*a)(void *),
  void *d);

#ifdef __cplusplus
}
#endif

#endif  // REQL_REQL_QUERY_H_
