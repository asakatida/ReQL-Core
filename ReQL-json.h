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

#include <stddef.h>
#include <stdint.h>

#ifndef _REQL_JSON_H
#define _REQL_JSON_H

/**
 * @brief JSON types.
 */
enum _ReQL_Datum_e {
  _REQL_R_REQL,
  _REQL_R_ARRAY = 5,
  _REQL_R_BOOL = 2,
  _REQL_R_JSON = 7,
  _REQL_R_NULL = 1,
  _REQL_R_NUM = 3,
  _REQL_R_OBJECT = 6,
  _REQL_R_STR = 4
};
typedef enum _ReQL_Datum_e _ReQL_Datum_t;

/**
 * @brief ReQL Terms.
 */
enum _ReQL_Term_e {
  _REQL_ADD = 24,
  _REQL_ALL = 67,
  _REQL_ANY = 66,
  _REQL_APPEND = 29,
  _REQL_APRIL = 117,
  _REQL_ARGS = 154,
  _REQL_ASC = 73,
  _REQL_AUGUST = 121,
  _REQL_AVG = 146,
  _REQL_BETWEEN = 36,
  _REQL_BINARY = 155,
  _REQL_BRACKET = 170,
  _REQL_BRANCH = 65,
  _REQL_CHANGES = 152,
  _REQL_CHANGE_AT = 84,
  _REQL_CIRCLE = 165,
  _REQL_COERCE_TO = 51,
  _REQL_CONCAT_MAP = 40,
  _REQL_CONFIG = 174,
  _REQL_CONTAINS = 93,
  _REQL_COUNT = 43,
  _REQL_DATE = 106,
  _REQL_DATUM = 1,
  _REQL_DAY = 130,
  _REQL_DAY_OF_WEEK = 131,
  _REQL_DAY_OF_YEAR = 132,
  _REQL_DB = 14,
  _REQL_DB_CREATE = 57,
  _REQL_DB_DROP = 58,
  _REQL_DB_LIST = 59,
  _REQL_DECEMBER = 125,
  _REQL_DEFAULT = 92,
  _REQL_DELETE = 54,
  _REQL_DELETE_AT = 83,
  _REQL_DESC = 74,
  _REQL_DIFFERENCE = 95,
  _REQL_DISTANCE = 162,
  _REQL_DISTINCT = 42,
  _REQL_DIV = 27,
  _REQL_DOWNCASE = 142,
  _REQL_DURING = 105,
  _REQL_EPOCH_TIME = 101,
  _REQL_EQ = 17,
  _REQL_EQ_JOIN = 50,
  _REQL_ERROR = 12,
  _REQL_FEBRUARY = 115,
  _REQL_FILL = 167,
  _REQL_FILTER = 39,
  _REQL_FOR_EACH = 68,
  _REQL_FRIDAY = 111,
  _REQL_FUNC = 69,
  _REQL_FUNCALL = 64,
  _REQL_GE = 22,
  _REQL_GEOJSON = 157,
  _REQL_GET = 16,
  _REQL_GET_ALL = 78,
  _REQL_GET_FIELD = 31,
  _REQL_GET_INTERSECTING = 166,
  _REQL_GET_NEAREST = 168,
  _REQL_GROUP = 144,
  _REQL_GT = 21,
  _REQL_HAS_FIELDS = 32,
  _REQL_HOURS = 133,
  _REQL_HTTP = 153,
  _REQL_IMPLICIT_VAR = 13,
  _REQL_INCLUDES = 164,
  _REQL_INDEXES_OF = 87,
  _REQL_INDEX_CREATE = 75,
  _REQL_INDEX_DROP = 76,
  _REQL_INDEX_LIST = 77,
  _REQL_INDEX_RENAME = 156,
  _REQL_INDEX_STATUS = 139,
  _REQL_INDEX_WAIT = 140,
  _REQL_INFO = 79,
  _REQL_INNER_JOIN = 48,
  _REQL_INSERT = 56,
  _REQL_INSERT_AT = 82,
  _REQL_INTERSECTS = 163,
  _REQL_IN_TIMEZONE = 104,
  _REQL_ISO8601 = 99,
  _REQL_IS_EMPTY = 86,
  _REQL_JANUARY = 114,
  _REQL_JAVASCRIPT = 11,
  _REQL_JSON = 98,
  _REQL_JULY = 120,
  _REQL_JUNE = 119,
  _REQL_KEYS = 94,
  _REQL_LE = 20,
  _REQL_LIMIT = 71,
  _REQL_LINE = 160,
  _REQL_LITERAL = 137,
  _REQL_LT = 19,
  _REQL_MAKE_ARRAY = 2,
  _REQL_MAKE_OBJ = 3,
  _REQL_MAP = 38,
  _REQL_MARCH = 116,
  _REQL_MATCH = 97,
  _REQL_MAX = 148,
  _REQL_MAY = 118,
  _REQL_MERGE = 35,
  _REQL_MIN = 147,
  _REQL_MINUTES = 134,
  _REQL_MOD = 28,
  _REQL_MONDAY = 107,
  _REQL_MONTH = 129,
  _REQL_MUL = 26,
  _REQL_NE = 18,
  _REQL_NOT = 23,
  _REQL_NOVEMBER = 124,
  _REQL_NOW = 103,
  _REQL_NTH = 45,
  _REQL_OBJECT = 143,
  _REQL_OCTOBER = 123,
  _REQL_ORDER_BY = 41,
  _REQL_OUTER_JOIN = 49,
  _REQL_PLUCK = 33,
  _REQL_POINT = 159,
  _REQL_POLYGON = 161,
  _REQL_POLYGON_SUB = 171,
  _REQL_PREPEND = 80,
  _REQL_RANDOM = 151,
  _REQL_RANGE = 173,
  _REQL_REBALANCE = 179,
  _REQL_RECONFIGURE = 176,
  _REQL_REDUCE = 37,
  _REQL_REPLACE = 55,
  _REQL_SAMPLE = 81,
  _REQL_SATURDAY = 112,
  _REQL_SECONDS = 135,
  _REQL_SEPTEMBER = 122,
  _REQL_SET_DIFFERENCE = 91,
  _REQL_SET_INSERT = 88,
  _REQL_SET_INTERSECTION = 89,
  _REQL_SET_UNION = 90,
  _REQL_SKIP = 70,
  _REQL_SLICE = 30,
  _REQL_SPLICE_AT = 85,
  _REQL_SPLIT = 149,
  _REQL_STATUS = 175,
  _REQL_SUB = 25,
  _REQL_SUM = 145,
  _REQL_SUNDAY = 113,
  _REQL_SYNC = 138,
  _REQL_TABLE = 15,
  _REQL_TABLE_CREATE = 60,
  _REQL_TABLE_DROP = 61,
  _REQL_TABLE_LIST = 62,
  _REQL_THURSDAY = 110,
  _REQL_TIME = 136,
  _REQL_TIMEZONE = 127,
  _REQL_TIME_OF_DAY = 126,
  _REQL_TO_EPOCH_TIME = 102,
  _REQL_TO_GEOJSON = 158,
  _REQL_TO_ISO8601 = 100,
  _REQL_TO_JSON_STRING = 172,
  _REQL_TUESDAY = 108,
  _REQL_TYPE_OF = 52,
  _REQL_UNGROUP = 150,
  _REQL_UNION = 44,
  _REQL_UPCASE = 141,
  _REQL_UPDATE = 53,
  _REQL_UUID = 169,
  _REQL_VAR = 10,
  _REQL_WAIT = 177,
  _REQL_WEDNESDAY = 109,
  _REQL_WITHOUT = 34,
  _REQL_WITH_FIELDS = 96,
  _REQL_YEAR = 128,
  _REQL_ZIP = 72
};
typedef enum _ReQL_Term_e _ReQL_Term_t;

/**
 * @brief A single key and associated value for objects.
 */
struct _ReQL_Pair_s {
  struct _ReQL_Obj_s *key;
  struct _ReQL_Obj_s *val;
};
typedef struct _ReQL_Pair_s _ReQL_Pair_t;

/**
 * @brief Iterator for easy enumeration.
 *
 * Supports objects and arrays.
 */
struct _ReQL_Iter_s {
  uint32_t idx;
  struct _ReQL_Obj_s *obj;
};
typedef struct _ReQL_Iter_s _ReQL_Iter_t;

/**
 * @brief Represents a single node in a query tree.
 */
struct _ReQL_Obj_s {
  _ReQL_Term_t tt;
  union {
    struct {
      _ReQL_Datum_t dt;
      union {
        struct {
          uint32_t size;
          uint32_t alloc_size;
          union {
            uint8_t *str;
            struct _ReQL_Obj_s **array;
            _ReQL_Pair_t *pair;
          };
        };
        double number;
        char boolean;
      } json;
    } datum;
    struct {
      struct _ReQL_Obj_s *args;
      struct _ReQL_Obj_s *kwargs;
    } args;
  } obj;
};
typedef struct _ReQL_Obj_s _ReQL_Obj_t;

/**
 * @brief get raw JSON datum type.
 *
 * _REQL_R_REQL indicates an error such as the object is not a datum.
 * _REQL_R_JSON is reserved for future expansion.
 * all other types corespond to a concrete JSON type.
 *
 * @param obj ReQL object that should be a raw datum.
 * @return datum type.
 */
extern _ReQL_Datum_t
_reql_datum_type(_ReQL_Obj_t *obj);

extern void
_reql_obj_set_term_type(_ReQL_Obj_t *obj, const _ReQL_Term_t type);

/**
 * @brief get ReQL term type.
 *
 * _REQL_DATUM indicates that the object is raw JSON.
 * The object will then have a datum sub type.
 *
 * @param obj any initialized ReQL object.
 * @return term type.
 */
extern _ReQL_Term_t
_reql_term_type(_ReQL_Obj_t *obj);

extern void
_reql_obj_set_args(_ReQL_Obj_t *obj, _ReQL_Obj_t *args);

extern _ReQL_Obj_t *
_reql_obj_args(_ReQL_Obj_t *obj);

extern void
_reql_obj_set_kwargs(_ReQL_Obj_t *obj, _ReQL_Obj_t *kwargs);

extern _ReQL_Obj_t *
_reql_obj_kwargs(_ReQL_Obj_t *obj);

/**
 * @brief initialize an allocated ReQL object as a JSON bool.
 * @param obj allocated ReQL object.
 * @param val 0 for a false bool, true bool otherwise.
 */
extern void
_reql_bool_init(_ReQL_Obj_t *obj, char val);

/**
 * @brief get c value from a JSON bool.
 * @param obj ReQL bool datum.
 * @return 1 if bool contains true, 0 if false.
 */
extern char
_reql_to_bool(_ReQL_Obj_t *obj);

/**
 * @brief initialize an allocated ReQL object as a JSON null.
 * @param obj allocated ReQL object.
 */
extern void
_reql_null_init(_ReQL_Obj_t *obj);

/**
 * @brief initialize an allocated ReQL object as a JSON number.
 * @param obj allocated ReQL object.
 * @param val stored as the JSON value.
 */
extern void
_reql_number_init(_ReQL_Obj_t *obj, double val);

/**
 * @brief get c value from a JSON number.
 * @param obj ReQL number datum.
 * @return value stored in ReQL object.
 */
extern double
_reql_to_number(_ReQL_Obj_t *obj);

/**
 * @brief initialize an allocated ReQL object as a JSON string.
 * @param obj allocated ReQL object.
 * @param buf uninitialized buffer.
 * @param alloc_size number of bytes in buffer.
 */
extern void
_reql_string_init(_ReQL_Obj_t *obj, uint8_t *buf, uint32_t alloc_size);

/**
 * @brief append c string to JSON string.
 * @param obj ReQL string datum.
 * @param ext buffer with null bytes permited.
 * @param size number of bytes in ext buffer.
 * @return 0 if successful. Otherwise the new internal buffer size requested to allow appending ext.
 */
extern uint32_t
_reql_string_append(_ReQL_Obj_t *obj, const uint8_t *ext, const uint32_t size);

/**
 * @brief get byte array from a JSON string.
 *
 * Byte array may be longer than size given by _reql_string_size.
 * Array may contain null bytes, and will not be null terminated.
 *
 * @param obj ReQL string datum.
 * @return byte array with contents of JSON string.
 */
extern uint8_t *
_reql_string_buf(_ReQL_Obj_t *obj);

/**
 * @brief get number of valid bytes from a JSON string.
 * @param obj ReQL string datum.
 * @return number of bytes from _reql_string_buf return that are valid.
 */
extern uint32_t
_reql_string_size(_ReQL_Obj_t *obj);

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
_reql_array_init(_ReQL_Obj_t *obj, _ReQL_Obj_t **arr, uint32_t alloc_size);

/**
 * @brief get number of objects in ReQL array.
 *
 * A sparse array filled by using _reql_array_insert will have undefineds represented as c NULL.
 * This may make iteration over the array tricky.
 *
 * @param obj ReQL array datum.
 * @return last index considered valid plus 1.
 */
extern uint32_t
_reql_array_size(_ReQL_Obj_t *obj);

/**
 * @brief replace object at index with value.
 * @param obj ReQL array datum.
 * @param val new element for array.
 * @param idx index to replace with value.
 * @return 0 if successful. Otherwise the new internal array size requested to allow inserting at idx.
 */
extern uint32_t
_reql_array_insert(_ReQL_Obj_t *obj, _ReQL_Obj_t *val, uint32_t idx);

/**
 * @brief object at c index of JSON array.
 * @param obj ReQL array datum.
 * @param idx index to pull value from.
 * @return index object or NULL.
 */
extern _ReQL_Obj_t *
_reql_array_index(_ReQL_Obj_t *obj, uint32_t idx);

/**
 * @brief push object onto end of array.
 * @param arr ReQL array datum.
 * @param val new element for array.
 * @return 0 if successful. Otherwise the new internal array size requested to allow inserting at idx.
 */
extern uint32_t
_reql_array_append(_ReQL_Obj_t *arr, _ReQL_Obj_t *val);

/**
 * @brief remove and return last object in array.
 * @param obj ReQL array datum.
 * @return last object or NULL.
 */
extern _ReQL_Obj_t *
_reql_array_pop(_ReQL_Obj_t *obj);

/**
 * @brief last object in array.
 * @param obj ReQL array datum.
 * @return last object or NULL.
 */
extern _ReQL_Obj_t *
_reql_array_last(_ReQL_Obj_t *obj);

/**
 * @brief create object iterator initialized at object start
 *
 * JSON objects with iterate over keys, arrays iterate elements.
 * Iterator results are undefined if the loop modifies the object being iterated.
 *
 * @param obj ReQL array or object datum.
 * @return new iterator.
 */
extern _ReQL_Iter_t
_reql_new_iter(_ReQL_Obj_t *obj);

/**
 * @brief get next element and step iterator.
 * @param arr reference to iterator.
 * @return next object or NULL for end of iteration.
 */
extern _ReQL_Obj_t *
_reql_iter_next(_ReQL_Iter_t *arr);

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
_reql_object_init(_ReQL_Obj_t *obj, _ReQL_Pair_t *pair, uint32_t alloc_size);

/**
 * @brief set key to value, updating if key already exists.
 * @param obj ReQL object datum.
 * @param key ReQL string datum.
 * @param val new object for key.
 * @return 0 if successful. Otherwise the new internal array size requested to allow adding key.
 */
extern uint32_t
_reql_object_add(_ReQL_Obj_t *obj, _ReQL_Obj_t *key, _ReQL_Obj_t *val);

/**
 * @brief get value of key in object.
 * @param obj ReQL object datum.
 * @param key ReQL string datum.
 * @return value in object or NULL if key does not exist.
 */
extern _ReQL_Obj_t *
_reql_object_get(_ReQL_Obj_t *obj, _ReQL_Obj_t *key);

/**
 * @brief recursive free of all nodes in a query tree.
 *
 * This is used to reclaim memory after a query response is used.
 *
 * @param json ReQL object.
 */
extern void
_reql_json_destroy(_ReQL_Obj_t *json);

#endif
