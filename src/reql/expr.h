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

#ifndef REQL_REQL_JSON_H_
#define REQL_REQL_JSON_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "./reql/types.h"

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
reql_string_init(ReQL_Obj_t *obj, ReQL_Byte *buf, ReQL_Size alloc_size);

/**
 * @brief append c string to JSON string.
 * @param obj ReQL string datum.
 * @param ext buffer with null bytes permited.
 * @param size number of bytes in ext buffer.
 * @return 0 if successful. Otherwise the new internal buffer size requested to allow appending ext.
 */
extern ReQL_Size
reql_string_append(ReQL_Obj_t *obj, const ReQL_Byte *ext, const ReQL_Size size);

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
 * @brief remove and return last object in array.
 * @param obj ReQL array datum.
 * @return last object or NULL.
 */
extern ReQL_Obj_t *
reql_array_pop(ReQL_Obj_t *obj);

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

extern void
reql_term_init(ReQL_Obj_t *obj, const ReQL_Term_t tt, ReQL_Obj_t *args, ReQL_Obj_t *kwargs);

extern ReQL_Obj_t *
reql_term_args(const ReQL_Obj_t *obj);

extern ReQL_Obj_t *
reql_term_kwargs(const ReQL_Obj_t *obj);

extern char
reql_op_eq(const ReQL_Obj_t *l, const ReQL_Obj_t *r);

extern ReQL_Obj_t *
reql_json_copy(const ReQL_Obj_t *other);

extern ReQL_Obj_t *
reql_json_move(ReQL_Obj_t *other);

/**
 * @brief recursive free of all nodes in a query tree.
 *
 * This is used to reclaim memory after a query response is used.
 *
 * @param json ReQL object.
 */
extern void
reql_json_destroy(ReQL_Obj_t *json);

#ifdef __cplusplus
}
#endif

#endif  // REQL_REQL_JSON_H_
