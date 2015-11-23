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

#ifndef REQL_REQL_QUERY_HPP_
#define REQL_REQL_QUERY_HPP_

#include "./reql/stream.hpp"
#include "./reql/string.hpp"
#include "./reql/types.hpp"

#include <algorithm>
#include <map>
#include <string>
#include <vector>

namespace _ReQL {

enum Term_t {
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
  REQL_VALUES = 186,
  REQL_VAR = 10,
  REQL_WAIT = 177,
  REQL_WEDNESDAY = 109,
  REQL_WITHOUT = 34,
  REQL_WITH_FIELDS = 96,
  REQL_YEAR = 128,
  REQL_ZIP = 72
};

template <class stream_t>
class Any_t {
public:
  template <class wrap_t>
  Any_t(const wrap_t &value) {
    value.toJSON(p_value);
  }

  void toJSON(stream_t &stream) const {
    stream << p_value;
  }

private:
  stream_t p_value;
};

template <class stream_t, class vect_t>
void
to_JSON(const vect_t &vect, stream_t &stream) {
  auto first = true;
  for (auto &&elem : vect) {
    if (!first) stream << ",";
    elem.toJSON(stream);
    first = false;
  }
}

template <class vect_t>
class Array_t {
public:
  Array_t(const vect_t &value) : p_value(value) {}

  template <class stream_t>
  void toJSON(stream_t &stream) const {
    stream << "[";
    to_JSON(p_value, stream);
    stream << "]";
  }

private:
  vect_t p_value;
};

template <class bool_t>
class Bool_t {
public:
  Bool_t(const bool_t value) : p_value(value) {}

  template <class stream_t>
  void toJSON(stream_t &stream) const {
    stream << (p_value ? "true" : "false");
  }

private:
  bool_t p_value;
};

template <class stream_t>
class Null_t {
public:
  void toJSON(stream_t &stream) const {
    stream << "null";
  }
};

template <class num_t>
class Num_t {
public:
  Num_t(const num_t value) : p_value(value) {}

  template <class stream_t>
  void toJSON(stream_t &stream) const {
    stream << p_value;
  }

private:
  num_t p_value;
};

/**
 * @brief A single key and associated value for objects.
 */
template <class key_t, class value_t>
class Pair_t {
public:
  Pair_t(const key_t &key, const value_t &val) : p_key(key), p_val(val) {}

  template <class stream_t>
  void toJSON(stream_t &stream) const {
    p_key.toJSON(stream);
    stream << ":";
    p_val.toJSON(stream);
  }

private:
  key_t p_key;
  value_t p_val;
};

template <class map_t>
class Obj_t {
public:
  Obj_t(const map_t &value) : p_value(value) {}

  template <class stream_t>
  void toJSON(stream_t &stream) const {
    stream << "{";
    std::vector<Pair_t<Any_t<stream_t>, Any_t<stream_t> > > temp;
    temp.reserve(p_value.size());
    std::transform(p_value.cbegin(), p_value.cend(), temp.begin(), [](auto &pair) { return Pair_t<Any_t<stream_t>, Any_t<stream_t> >(pair.first, pair.second); });
    to_JSON(temp, stream);
    stream << "}";
  }

private:
  map_t p_value;
};

template <class args_t, class kwargs_t>
class ReQL_Kwargs_t {
public:
  ReQL_Kwargs_t(Term_t tt, const args_t &args, const kwargs_t &kwargs) : p_tt(tt), p_args(args), p_kwargs(kwargs) {}

  template <class stream_t>
  void toJSON(stream_t &stream) const {
    stream << "[" << static_cast<int>(p_tt) << ",";
    p_args.toJSON(stream);
    stream << ",";
    p_kwargs.toJSON(stream);
    stream << "]";
  }

private:
  Term_t p_tt;
  args_t p_args;
  kwargs_t p_kwargs;
};

template <class args_t>
class ReQL_Args_t {
public:
  ReQL_Args_t(Term_t tt, const args_t &args) : p_tt(tt), p_args(args) {}

  template <class stream_t>
  void toJSON(stream_t &stream) const {
    stream << "[" << static_cast<int>(p_tt) << ",";
    p_args.toJSON(stream);
    stream << "]";
  }

private:
  Term_t p_tt;
  args_t p_args;
};

template <class stream_t>
class ReQL_t {
public:
  ReQL_t(Term_t tt) : p_tt(tt) {}

  void toJSON(stream_t &stream) const {
    stream << "[" << static_cast<int>(p_tt) << "]";
  }

private:
  Term_t p_tt;
};

template <class str_t>
class String_t {
public:
  String_t(const str_t &value) : p_value(value) {}

  template <class stream_t>
  void toJSON(stream_t &stream) const {
    const typename stream_t::string_type::value_type json_esc[][6] = {
      {'\\', 'u', '0', '0', '0', '0'},  // 0x00
      {'\\', 'u', '0', '0', '0', '1'},  // 0x01
      {'\\', 'u', '0', '0', '0', '2'},  // 0x02
      {'\\', 'u', '0', '0', '0', '3'},  // 0x03
      {'\\', 'u', '0', '0', '0', '4'},  // 0x04
      {'\\', 'u', '0', '0', '0', '5'},  // 0x05
      {'\\', 'u', '0', '0', '0', '6'},  // 0x06
      {'\\', 'u', '0', '0', '0', '7'},  // 0x07
      {'\\', 'b'},  // 0x08
      {'\\', 't'},  // 0x09
      {'\\', 'n'},  // 0x0A
      {'\\', 'u', '0', '0', '0', 'B'},  // 0x0B
      {'\\', 'f'},  // 0x0C
      {'\\', 'r'},  // 0x0D
      {'\\', 'u', '0', '0', '0', 'E'},  // 0x0E
      {'\\', 'u', '0', '0', '0', 'F'},  // 0x0F
      {'\\', 'u', '0', '0', '1', '0'},  // 0x10
      {'\\', 'u', '0', '0', '1', '1'},  // 0x11
      {'\\', 'u', '0', '0', '1', '2'},  // 0x12
      {'\\', 'u', '0', '0', '1', '3'},  // 0x13
      {'\\', 'u', '0', '0', '1', '4'},  // 0x14
      {'\\', 'u', '0', '0', '1', '5'},  // 0x15
      {'\\', 'u', '0', '0', '1', '6'},  // 0x16
      {'\\', 'u', '0', '0', '1', '7'},  // 0x17
      {'\\', 'u', '0', '0', '1', '8'},  // 0x18
      {'\\', 'u', '0', '0', '1', '9'},  // 0x19
      {'\\', 'u', '0', '0', '1', 'A'},  // 0x1A
      {'\\', 'u', '0', '0', '1', 'B'},  // 0x1B
      {'\\', 'u', '0', '0', '1', 'C'},  // 0x1C
      {'\\', 'u', '0', '0', '1', 'D'},  // 0x1D
      {'\\', 'u', '0', '0', '1', 'E'},  // 0x1E
      {'\\', 'u', '0', '0', '1', 'F'},  // 0x1F
      {}, {},  // 0x21
      {'\\', '"'},  // 0x22
      {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {},  // 0x2F
      {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {},  // 0x3F
      {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {},  // 0x4F
      {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {},  // 0x5B
      {'\\', '\\'}  // 0x5C
    };

    const unsigned int json_size[] = {
      6, 6, 6, 6, 6, 6, 6, 6, 2, 2, 2, 6, 2, 2, 6, 6,  // 0x0x
      6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,  // 0x1x
      0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  // 0x2x
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  // 0x3x
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  // 0x4x
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0  // 0x5x
    };

    stream << "\"";
    for (const auto chr : p_value) {
      auto idx = static_cast<unsigned int>(chr);
      if (idx <= 0x5C) {
        auto ext_size = json_size[idx];
        if (ext_size) {
          stream << typename stream_t::string_type(json_esc[idx], ext_size);
          continue;
        }
      }
      stream << chr;
    }
    stream << "\"";
  }

  bool operator<(const String_t &other) const {
    return p_value < other.p_value;
  }

private:
  str_t p_value;
};

enum Query_e {
  REQL_CONTINUE = 2,
  REQL_NOREPLY_WAIT = 4,
  REQL_START = 1,
  REQL_STOP = 3
};

template <class str_t>
class Query_t {
public:
  Query_t(const ReQL_Token token, const Query_e type) : p_token(token) {
    p_stream << "[" << static_cast<int>(type) << "]";
  }

  template <class query_t>
  Query_t(const ReQL_Token token, const query_t &query) : p_token(token) {
    p_stream << "[" << static_cast<int>(REQL_START) << ",";
    query.toJSON(p_stream);
    p_stream << "]";
  }

  template <class kwargs_t, class query_t>
  Query_t(const ReQL_Token token, const query_t &query, const kwargs_t &kwargs) : p_token(token) {
    p_stream << "[" << static_cast<int>(REQL_START) << ",";
    query.toJSON(p_stream);
    p_stream << ",";
    kwargs.toJSON(p_stream);
    p_stream << "]";
  }

  ReQL_Token token() const {
    return p_token;
  }

  str_t str() const {
    return p_stream.str();
  }

private:
  Stream_t<str_t> p_stream;
  const ReQL_Token p_token;
};

typedef Any_t<_Stream> Any;
typedef Array_t<std::vector<Any> > Array;
typedef Bool_t<bool> Boolean;
typedef Null_t<_Stream> Null;
typedef Num_t<double> Number;
typedef String_t<std::string> String;
typedef Obj_t<std::map<String, Any> > Object;
typedef ReQL_Kwargs_t<Array, Object> ReQL_Kwargs;
typedef ReQL_Args_t<Array> ReQL_Args;
typedef ReQL_t<_Stream> ReQL;

}  // namespace _ReQL

#endif  // REQL_REQL_QUERY_HPP_
