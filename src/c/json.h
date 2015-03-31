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

#ifndef REQL_JSON_H_
#define REQL_JSON_H_

#include <stdint.h>

/**
 * @brief JSON types.
 */
enum ReQL_Datum_e {
  REQL_R_REQL,
  REQL_R_ARRAY = 5,
  REQL_R_BOOL = 2,
  REQL_R_JSON = 7,
  REQL_R_NULL = 1,
  REQL_R_NUM = 3,
  REQL_R_OBJECT = 6,
  REQL_R_STR = 4
};
typedef enum ReQL_Datum_e ReQL_Datum_t;

/**
 * @brief ReQL Terms.
 */
enum ReQL_Term_e {
  REQL_ADD = 24,
  REQL_AND = 67,
  REQL_APPEND = 29,
  REQL_APRIL = 117,
  REQL_ARGS = 154,
  REQL_ASC = 73,
  REQL_AUGUST = 121,
  REQL_AVG = 146,
  REQL_BETWEEN = 182,
  REQL_BETWEEN_DEPRECATED = 36,
  REQL_BINARY = 155,
  REQL_BRACKET = 170,
  REQL_BRANCH = 65,
  REQL_CEIL = 184,
  REQL_CHANGES = 152,
  REQL_CHANGE_AT = 84,
  REQL_CIRCLE = 165,
  REQL_COERCE_TO = 51,
  REQL_CONCAT_MAP = 40,
  REQL_CONFIG = 174,
  REQL_CONTAINS = 93,
  REQL_COUNT = 43,
  REQL_DATE = 106,
  REQL_DATUM = 1,
  REQL_DAY = 130,
  REQL_DAY_OF_WEEK = 131,
  REQL_DAY_OF_YEAR = 132,
  REQL_DB = 14,
  REQL_DB_CREATE = 57,
  REQL_DB_DROP = 58,
  REQL_DB_LIST = 59,
  REQL_DECEMBER = 125,
  REQL_DEFAULT = 92,
  REQL_DELETE = 54,
  REQL_DELETE_AT = 83,
  REQL_DESC = 74,
  REQL_DIFFERENCE = 95,
  REQL_DISTANCE = 162,
  REQL_DISTINCT = 42,
  REQL_DIV = 27,
  REQL_DOWNCASE = 142,
  REQL_DURING = 105,
  REQL_EPOCH_TIME = 101,
  REQL_EQ = 17,
  REQL_EQ_JOIN = 50,
  REQL_ERROR = 12,
  REQL_FEBRUARY = 115,
  REQL_FILL = 167,
  REQL_FILTER = 39,
  REQL_FLOOR = 183,
  REQL_FOR_EACH = 68,
  REQL_FRIDAY = 111,
  REQL_FUNC = 69,
  REQL_FUNCALL = 64,
  REQL_GE = 22,
  REQL_GEOJSON = 157,
  REQL_GET = 16,
  REQL_GET_ALL = 78,
  REQL_GET_FIELD = 31,
  REQL_GET_INTERSECTING = 166,
  REQL_GET_NEAREST = 168,
  REQL_GROUP = 144,
  REQL_GT = 21,
  REQL_HAS_FIELDS = 32,
  REQL_HOURS = 133,
  REQL_HTTP = 153,
  REQL_IMPLICIT_VAR = 13,
  REQL_INCLUDES = 164,
  REQL_INDEX_CREATE = 75,
  REQL_INDEX_DROP = 76,
  REQL_INDEX_LIST = 77,
  REQL_INDEX_RENAME = 156,
  REQL_INDEX_STATUS = 139,
  REQL_INDEX_WAIT = 140,
  REQL_INFO = 79,
  REQL_INNER_JOIN = 48,
  REQL_INSERT = 56,
  REQL_INSERT_AT = 82,
  REQL_INTERSECTS = 163,
  REQL_IN_TIMEZONE = 104,
  REQL_ISO8601 = 99,
  REQL_IS_EMPTY = 86,
  REQL_JANUARY = 114,
  REQL_JAVASCRIPT = 11,
  REQL_JSON = 98,
  REQL_JULY = 120,
  REQL_JUNE = 119,
  REQL_KEYS = 94,
  REQL_LE = 20,
  REQL_LIMIT = 71,
  REQL_LINE = 160,
  REQL_LITERAL = 137,
  REQL_LT = 19,
  REQL_MAKE_ARRAY = 2,
  REQL_MAKE_OBJ = 3,
  REQL_MAP = 38,
  REQL_MARCH = 116,
  REQL_MATCH = 97,
  REQL_MAX = 148,
  REQL_MAXVAL = 181,
  REQL_MAY = 118,
  REQL_MERGE = 35,
  REQL_MIN = 147,
  REQL_MINUTES = 134,
  REQL_MINVAL = 180,
  REQL_MOD = 28,
  REQL_MONDAY = 107,
  REQL_MONTH = 129,
  REQL_MUL = 26,
  REQL_NE = 18,
  REQL_NOT = 23,
  REQL_NOVEMBER = 124,
  REQL_NOW = 103,
  REQL_NTH = 45,
  REQL_OBJECT = 143,
  REQL_OCTOBER = 123,
  REQL_OFFSETS_OF = 87,
  REQL_OR = 66,
  REQL_ORDER_BY = 41,
  REQL_OUTER_JOIN = 49,
  REQL_PLUCK = 33,
  REQL_POINT = 159,
  REQL_POLYGON = 161,
  REQL_POLYGON_SUB = 171,
  REQL_PREPEND = 80,
  REQL_RANDOM = 151,
  REQL_RANGE = 173,
  REQL_REBALANCE = 179,
  REQL_RECONFIGURE = 176,
  REQL_REDUCE = 37,
  REQL_REPLACE = 55,
  REQL_ROUND = 185,
  REQL_SAMPLE = 81,
  REQL_SATURDAY = 112,
  REQL_SECONDS = 135,
  REQL_SEPTEMBER = 122,
  REQL_SET_DIFFERENCE = 91,
  REQL_SET_INSERT = 88,
  REQL_SET_INTERSECTION = 89,
  REQL_SET_UNION = 90,
  REQL_SKIP = 70,
  REQL_SLICE = 30,
  REQL_SPLICE_AT = 85,
  REQL_SPLIT = 149,
  REQL_STATUS = 175,
  REQL_SUB = 25,
  REQL_SUM = 145,
  REQL_SUNDAY = 113,
  REQL_SYNC = 138,
  REQL_TABLE = 15,
  REQL_TABLE_CREATE = 60,
  REQL_TABLE_DROP = 61,
  REQL_TABLE_LIST = 62,
  REQL_THURSDAY = 110,
  REQL_TIME = 136,
  REQL_TIMEZONE = 127,
  REQL_TIME_OF_DAY = 126,
  REQL_TO_EPOCH_TIME = 102,
  REQL_TO_GEOJSON = 158,
  REQL_TO_ISO8601 = 100,
  REQL_TO_JSON_STRING = 172,
  REQL_TUESDAY = 108,
  REQL_TYPE_OF = 52,
  REQL_UNGROUP = 150,
  REQL_UNION = 44,
  REQL_UPCASE = 141,
  REQL_UPDATE = 53,
  REQL_UUID = 169,
  REQL_VAR = 10,
  REQL_WAIT = 177,
  REQL_WEDNESDAY = 109,
  REQL_WITHOUT = 34,
  REQL_WITH_FIELDS = 96,
  REQL_YEAR = 128,
  REQL_ZIP = 72
};
typedef enum ReQL_Term_e ReQL_Term_t;

/**
 * @brief A single key and associated value for objects.
 */
struct ReQL_Pair_s {
  struct ReQL_Obj_s *key;
  struct ReQL_Obj_s *val;
};
typedef struct ReQL_Pair_s ReQL_Pair_t;

/**
 * @brief Iterator for easy enumeration.
 *
 * Supports objects and arrays.
 */
struct ReQL_Iter_s {
  uint32_t idx;
  const struct ReQL_Obj_s *obj;
};
typedef struct ReQL_Iter_s ReQL_Iter_t;

/**
 * @brief Represents a single node in a query tree.
 */
struct ReQL_Obj_s {
  ReQL_Term_t tt;
  union {
    struct {
      ReQL_Datum_t dt;
      union {
        struct {
          uint32_t size;
          uint32_t alloc_size;
          union {
            uint8_t *str;
            struct ReQL_Obj_s **array;
            ReQL_Pair_t *pair;
          } data;
        } var;
        double number;
        char boolean;
      } json;
    } datum;
    struct {
      struct ReQL_Obj_s *args;
      struct ReQL_Obj_s *kwargs;
    } args;
  } obj;
};
typedef struct ReQL_Obj_s ReQL_Obj_t;

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

extern void
reql_set_term_type(ReQL_Obj_t *obj, const ReQL_Term_t type);

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

extern void
reql_set_args(ReQL_Obj_t *obj, ReQL_Obj_t *args);

extern ReQL_Obj_t *
reql_args(const ReQL_Obj_t *obj);

extern void
reql_set_kwargs(ReQL_Obj_t *obj, ReQL_Obj_t *kwargs);

extern ReQL_Obj_t *
reql_kwargs(const ReQL_Obj_t *obj);

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
reql_string_init(ReQL_Obj_t *obj, uint8_t *buf, uint32_t alloc_size);

/**
 * @brief append c string to JSON string.
 * @param obj ReQL string datum.
 * @param ext buffer with null bytes permited.
 * @param size number of bytes in ext buffer.
 * @return 0 if successful. Otherwise the new internal buffer size requested to allow appending ext.
 */
extern uint32_t
reql_string_append(ReQL_Obj_t *obj, const uint8_t *ext, const uint32_t size);

/**
 * @brief get byte array from a JSON string.
 *
 * Byte array may be longer than size given by reql_size.
 * Array may contain null bytes, and will not be null terminated.
 *
 * @param obj ReQL string datum.
 * @return byte array with contents of JSON string.
 */
extern uint8_t *
reql_string_buf(const ReQL_Obj_t *obj);

/**
 * @brief get number of elements from a variable size JSON value.
 * @param obj ReQL string, array or object datum.
 * @return number of elements from variable size JSON value.
 */
extern uint32_t
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
reql_array_init(ReQL_Obj_t *obj, ReQL_Obj_t **arr, uint32_t alloc_size);

/**
 * @brief replace object at index with value.
 * @param obj ReQL array datum.
 * @param val new element for array.
 * @param idx index to replace with value.
 * @return 0 if successful. Otherwise the new internal array size requested to allow inserting at idx.
 */
extern uint32_t
reql_array_insert(ReQL_Obj_t *obj, ReQL_Obj_t *val, const uint32_t idx);

/**
 * @brief object at c index of JSON array.
 * @param obj ReQL array datum.
 * @param idx index to pull value from.
 * @return index object or NULL.
 */
extern ReQL_Obj_t *
reql_array_index(const ReQL_Obj_t *obj, const uint32_t idx);

/**
 * @brief push object onto end of array.
 * @param arr ReQL array datum.
 * @param val new element for array.
 * @return 0 if successful. Otherwise the new internal array size requested to allow inserting at idx.
 */
extern uint32_t
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
reql_array_last(const ReQL_Obj_t *obj);

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
reql_object_init(ReQL_Obj_t *obj, ReQL_Pair_t *pair, const uint32_t alloc_size);

/**
 * @brief set key to value, updating if key already exists.
 * @param obj ReQL object datum.
 * @param key ReQL string datum.
 * @param val new object for key.
 * @return 0 if successful. Otherwise the new internal array size requested to allow adding key.
 */
extern uint32_t
reql_object_add(ReQL_Obj_t *obj, ReQL_Obj_t *key, ReQL_Obj_t *val);

/**
 * @brief get value of key in object.
 * @param obj ReQL object datum.
 * @param key ReQL string datum.
 * @return value in object or NULL if key does not exist.
 */
extern ReQL_Obj_t *
reql_object_get(const ReQL_Obj_t *obj, ReQL_Obj_t *key);

extern char
reql_op_eq(const ReQL_Obj_t *l, const ReQL_Obj_t *r);

/**
 * @brief recursive free of all nodes in a query tree.
 *
 * This is used to reclaim memory after a query response is used.
 *
 * @param json ReQL object.
 */
extern void
reql_json_destroy(ReQL_Obj_t *json);

#endif  // REQL_JSON_H_
