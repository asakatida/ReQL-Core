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

typedef void (*ReQL_AST_Function_Kwargs) (ReQL_Obj_t *, ReQL_Obj_t *, ReQL_Obj_t *);
typedef void (*ReQL_AST_Function) (ReQL_Obj_t *, ReQL_Obj_t *);

/**
 * @brief get raw JSON datum type.
 *
 * REQL_R_REQL indicates an error such as the object is not a datum.
 * REQL_R_JSON is reserved for future expansion.
 * all other types corespond to a concrete JSON type.
 *
 * @param obj ReQL object that should be a raw datum.
 * @return datum type.
 */
extern ReQL_Datum_t
reql_datum_type(const ReQL_Obj_t *obj);

/**
 * @brief get ReQL term type.
 *
 * REQL_DATUM indicates that the object is raw JSON.
 * The object will then have a datum sub type.
 *
 * @param obj any initialized ReQL object.
 * @return term type.
 */
extern ReQL_Term_t
reql_term_type(const ReQL_Obj_t *obj);

/**
 * @brief initialize an allocated ReQL object as a JSON bool.
 * @param obj allocated ReQL object.
 * @param val 0 for a false bool, true bool otherwise.
 */
extern void
reql_bool_init(ReQL_Obj_t *obj, char val);

/**
 * @brief get c value from a JSON bool.
 * @param obj ReQL bool datum.
 * @return 1 if bool contains true, 0 if false.
 */
extern char
reql_to_bool(const ReQL_Obj_t *obj);

/**
 * @brief initialize an allocated ReQL object as a JSON null.
 * @param obj allocated ReQL object.
 */
extern void
reql_null_init(ReQL_Obj_t *obj);

/**
 * @brief initialize an allocated ReQL object as a JSON number.
 * @param obj allocated ReQL object.
 * @param val stored as the JSON value.
 */
extern void
reql_number_init(ReQL_Obj_t *obj, double val);

/**
 * @brief get c value from a JSON number.
 * @param obj ReQL number datum.
 * @return value stored in ReQL object.
 */
extern double
reql_to_number(const ReQL_Obj_t *obj);

/**
 * @brief initialize an allocated ReQL object as a JSON string.
 * @param obj allocated ReQL object.
 * @param buf uninitialized buffer.
 * @param alloc_size number of bytes in buffer.
 */
extern void
reql_string_init(ReQL_Obj_t *obj, ReQL_Byte *buf, const ReQL_Byte *ext, ReQL_Size alloc_size);

/**
 * @brief get byte array from a JSON string.
 *
 * Byte array may be longer than size given by reql_size.
 * Array may contain null bytes, and will not be null terminated.
 *
 * @param obj ReQL string datum.
 * @return byte array with contents of JSON string.
 */
extern ReQL_Byte *
reql_string_buf(const ReQL_Obj_t *obj);

/**
 * @brief get number of elements from a variable size JSON value.
 * @param obj ReQL string, array or object datum.
 * @return number of elements from variable size JSON value.
 */
extern ReQL_Size
reql_size(const ReQL_Obj_t *obj);

/**
 * @brief initialize an allocated ReQL object as a JSON array.
 *
 * Internal c array will be initialized to NULL pointers.
 *
 * @param obj allocated ReQL object.
 * @param arr uninitialized c array of ReQL objects.
 * @param alloc_size number of objects in arr.
 */
extern void
reql_array_init(ReQL_Obj_t *obj, ReQL_Obj_t **arr, ReQL_Size alloc_size);

/**
 * @brief replace object at index with value.
 * @param obj ReQL array datum.
 * @param val new element for array.
 * @param idx index to replace with value.
 * @return 0 if successful. Otherwise the new internal array size requested to allow inserting at idx.
 */
extern ReQL_Size
reql_array_insert(ReQL_Obj_t *obj, ReQL_Obj_t *val, const ReQL_Size idx);

/**
 * @brief object at c index of JSON array.
 * @param obj ReQL array datum.
 * @param idx index to pull value from.
 * @return index object or NULL.
 */
extern ReQL_Obj_t *
reql_array_index(const ReQL_Obj_t *obj, const ReQL_Size idx);

/**
 * @brief push object onto end of array.
 * @param arr ReQL array datum.
 * @param val new element for array.
 * @return 0 if successful. Otherwise the new internal array size requested to allow inserting at idx.
 */
extern ReQL_Size
reql_array_append(ReQL_Obj_t *arr, ReQL_Obj_t *val);

/**
 * @brief last object in array.
 * @param obj ReQL array datum.
 * @return last object or NULL.
 */
extern ReQL_Obj_t *
reql_array_last(ReQL_Obj_t *obj);

/**
 * @brief create object iterator initialized at object start
 *
 * JSON objects with iterate over keys, arrays iterate elements.
 * Iterator results are undefined if the loop modifies the object being iterated.
 *
 * @param obj ReQL array or object datum.
 * @return new iterator.
 */
extern ReQL_Iter_t
reql_new_iter(const ReQL_Obj_t *obj);

/**
 * @brief get next element and step iterator.
 * @param arr reference to iterator.
 * @return next object or NULL for end of iteration.
 */
extern ReQL_Obj_t *
reql_iter_next(ReQL_Iter_t *arr);

/**
 * @brief initialize an allocated ReQL object as a JSON object.
 *
 * Internal c pairs array will be initialized to NULL pointers.
 *
 * @param obj allocated ReQL object.
 * @param pair uninitialized c array of pairs.
 * @param alloc_size number of objects in pair.
 */
extern void
reql_object_init(ReQL_Obj_t *obj, ReQL_Pair_t *pair, const ReQL_Size alloc_size);

/**
 * @brief set key to value, updating if key already exists.
 * @param obj ReQL object datum.
 * @param key ReQL string datum.
 * @param val new object for key.
 * @return 0 if successful. Otherwise the new internal array size requested to allow adding key.
 */
extern ReQL_Size
reql_object_add(ReQL_Obj_t *obj, ReQL_Obj_t *key, ReQL_Obj_t *val);

/**
 * @brief get value of key in object.
 * @param obj ReQL object datum.
 * @param key ReQL string datum.
 * @return value in object or NULL if key does not exist.
 */
extern ReQL_Obj_t *
reql_object_get(const ReQL_Obj_t *obj, ReQL_Obj_t *key);

/**
 * @brief recursive free of all nodes in a query tree.
 *
 * This is used to reclaim memory after a query response is used.
 *
 * @param json ReQL object.
 */
extern void
reql_json_destroy(ReQL_Obj_t *json);

/**
 */
extern void
reql_ast_add(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_and(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_append(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_april(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_args(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_asc(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_august(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_avg(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_between(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_between_deprecated(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_binary(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_bracket(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_branch(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_ceil(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_changes(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_change_at(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_circle(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_coerce_to(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_concat_map(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_config(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_contains(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_count(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_date(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_datum(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_day(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_day_of_week(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_day_of_year(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_db(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_db_create(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_db_drop(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_db_list(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_december(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_default(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_delete(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_delete_at(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_desc(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_difference(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_distance(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_distinct(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_div(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_downcase(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_during(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_epoch_time(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_eq(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_eq_join(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_error(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_february(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_fill(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_filter(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_floor(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_for_each(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_friday(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_func(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_funcall(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_ge(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_geojson(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_get(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_get_all(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_get_field(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_get_intersecting(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_get_nearest(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_group(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_gt(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_has_fields(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_hours(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_http(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_implicit_var(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_includes(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_index_create(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_index_drop(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_index_list(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_index_rename(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_index_status(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_index_wait(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_info(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_inner_join(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_insert(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_insert_at(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_intersects(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_in_timezone(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_iso8601(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_is_empty(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_january(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_javascript(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_json(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_july(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_june(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_keys(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_le(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_limit(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_line(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_literal(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_lt(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_make_array(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_make_obj(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_map(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_march(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_match(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_max(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_maxval(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_may(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_merge(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_min(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_minutes(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_minval(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_mod(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_monday(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_month(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_mul(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_ne(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_not(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_november(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_now(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_nth(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_object(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_october(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_offsets_of(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_or(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_order_by(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_outer_join(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_pluck(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_point(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_polygon(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_polygon_sub(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_prepend(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_random(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_range(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_rebalance(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_reconfigure(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_reduce(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_replace(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_round(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_sample(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_saturday(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_seconds(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_september(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_set_difference(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_set_insert(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_set_intersection(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_set_union(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_skip(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_slice(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_splice_at(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_split(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_status(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_sub(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_sum(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_sunday(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_sync(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_table(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_table_create(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_table_drop(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_table_list(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_thursday(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_time(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_timezone(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_time_of_day(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_to_epoch_time(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_to_geojson(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_to_iso8601(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_to_json_string(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_tuesday(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_type_of(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_ungroup(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_union(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_upcase(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_update(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_uuid(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_values(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_var(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_wait(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_wednesday(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_without(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_with_fields(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_year(ReQL_Obj_t *t, ReQL_Obj_t *a);

/**
 */
extern void
reql_ast_zip(ReQL_Obj_t *t, ReQL_Obj_t *a);

#ifdef __cplusplus
}
#endif

#endif  // REQL_REQL_QUERY_H_
