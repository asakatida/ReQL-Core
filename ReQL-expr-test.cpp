#include "ReQL-test.hpp"

#include "catch.h"

#include <limits>

using namespace ReQL;

TEST_CASE("Connection", "[c++][connect]") {
  Connection conn = connect();

  REQUIRE(conn.isOpen());
}

TEST_CASE("Expr object", "[c][expr][object]") {
  _ReQL_Op_t obj, key, val;

  _ReQL_Pair_t pair[1];

  _reql_object_init(&obj, pair, 1);

  const uint32_t size = 4;

  uint8_t buf[size] = "key";

  _reql_string_init(&key, buf, size, size);

  _reql_null_init(&val);

  CHECK(_reql_object_add(&obj, &key, &val) == 0);

  SECTION("verify insert") {
    CHECK(_reql_object_get(&obj, &key) != NULL);

    _ReQL_Op res = _reql_object_get(&obj, &key);

    CHECK(_reql_datum_type(res) == _REQL_R_NULL);
  }

  SECTION("reuse key") {
    _ReQL_Op_t new_val;

    const double num = 3.14;

    _reql_number_init(&new_val, num);

    CHECK(_reql_object_add(&obj, &key, &new_val) == 0);
    CHECK(_reql_object_get(&obj, &key) != NULL);

    _ReQL_Op res = _reql_object_get(&obj, &key);

    CHECK(_reql_datum_type(res) == _REQL_R_NUM);
    CHECK(_reql_to_number(res) == num);
  }

  SECTION("duplicate key") {
    _ReQL_Op_t new_key, new_val;

    const double num = 3.14;

    uint8_t new_buf[size] = "key";

    _reql_string_init(&new_key, new_buf, size, size);

    _reql_number_init(&new_val, num);

    CHECK(_reql_object_add(&obj, &new_key, &new_val) == 0);
    CHECK(_reql_object_get(&obj, &new_key) != NULL);

    _ReQL_Op res = _reql_object_get(&obj, &new_key);

    CHECK(_reql_datum_type(res) == _REQL_R_NUM);
  }

  SECTION("out of space") {
    _ReQL_Op_t new_key, new_val;

    const double num = 3.14;

    uint8_t new_buf[size] = "new";

    _reql_string_init(&new_key, new_buf, size, size);

    _reql_number_init(&new_val, num);

    CHECK(_reql_object_add(&obj, &new_key, &new_val) != 0);
    CHECK(_reql_object_get(&obj, &new_key) == NULL);

    _ReQL_Op res = _reql_object_get(&obj, &key);

    CHECK(_reql_datum_type(res) == _REQL_R_NULL);
  }
}

TEST_CASE("Expr", "[c][expr]") {
  _ReQL_Op_t val;

  SECTION("bool") {
    _reql_bool_init(&val, 10);

    CHECK(_reql_to_bool(&val) == true);

    _reql_bool_init(&val, false);

    CHECK(_reql_to_bool(&val) == false);
  }

  SECTION("null") {
    _reql_null_init(&val);

    CHECK(_reql_datum_type(&val) == _REQL_R_NULL);
  }

  SECTION("number") {
    const double num = 42.0;

    _reql_number_init(&val, num);

    CHECK(num == _reql_to_number(&val));
  }

  SECTION("number edges") {
    const double num = std::numeric_limits<std::double_t>::max();

    _reql_number_init(&val, num);

    CHECK(num == _reql_to_number(&val));
  }

  SECTION("string") {
    const uint32_t size = 12;

    uint8_t buf[size] = "Hello World";

    std::string orig = std::string((char *)buf, size);

    _reql_string_init(&val, buf, size, size);

    CHECK(orig.compare(0, size, (char *)_reql_string_buf(&val), size) == 0);
    CHECK(size == _reql_string_size(&val));
  }
}
