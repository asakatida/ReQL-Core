// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./reql/core.h"

#include <limits>

TEST_CASE("c expr array", "[reql][expr][array]") {
  std::unique_ptr<ReQL_Obj_t> ary(new ReQL_Obj_t);

  const uint32_t size = 5;

  ReQL_Obj_t *arr[size];

  reql_array_init(ary.get(), arr, size);

  REQUIRE(reql_datum_type(ary.get()) == REQL_R_ARRAY);

  REQUIRE(reql_size(ary.get()) == 0);

  SECTION("over fill array") {
    std::vector<std::unique_ptr<ReQL_Obj_t>> elements;
    uint32_t i;

    for (i=0; i < size; ++i) {
      std::unique_ptr<ReQL_Obj_t> elem(new ReQL_Obj_t);
      elements.push_back(std::move(elem));
      reql_null_init(elements.back().get());
      REQUIRE(reql_array_append(ary.get(), elements.back().get()) == 0);
    }

    std::unique_ptr<ReQL_Obj_t> extra(new ReQL_Obj_t);

    reql_null_init(extra.get());

    REQUIRE(reql_array_append(ary.get(), extra.get()) != 0);
  }

  SECTION("grow and shrink") {
    std::unique_ptr<ReQL_Obj_t> elem(new ReQL_Obj_t);

    reql_null_init(elem.get());

    reql_array_append(ary.get(), elem.get());

    REQUIRE(reql_array_pop(ary.get()) != nullptr);
    REQUIRE(reql_array_last(ary.get()) == nullptr);
    REQUIRE(reql_array_pop(ary.get()) == nullptr);
  }

  SECTION("insert after end") {
    std::unique_ptr<ReQL_Obj_t> elem(new ReQL_Obj_t);

    reql_null_init(elem.get());

    REQUIRE(reql_array_insert(ary.get(), elem.get(), size * 2) != 0);
  }
}

TEST_CASE("c expr object", "[reql][expr][object]") {
  std::unique_ptr<ReQL_Obj_t> obj(new ReQL_Obj_t);
  std::unique_ptr<ReQL_Obj_t> key(new ReQL_Obj_t);
  std::unique_ptr<ReQL_Obj_t> val(new ReQL_Obj_t);

  ReQL_Pair_t pair[1];

  reql_object_init(obj.get(), pair, 1);

  REQUIRE(reql_datum_type(obj.get()) == REQL_R_OBJECT);

  const uint32_t size = 4;

  std::unique_ptr<uint8_t> buf(new uint8_t[size]);
  const uint8_t string[] = "key";

  reql_string_init(key.get(), buf.get(), size);
  reql_string_append(key.get(), string, size);

  reql_null_init(val.get());

  REQUIRE(reql_object_add(obj.get(), key.get(), val.get()) == 0);

  SECTION("verify insert") {
    REQUIRE(reql_object_get(obj.get(), key.get()) != nullptr);

    ReQL_Obj_t *res = reql_object_get(obj.get(), key.get());

    REQUIRE(reql_datum_type(res) == REQL_R_NULL);
    REQUIRE(res == val.get());
  }

  SECTION("reuse key") {
    std::unique_ptr<ReQL_Obj_t> new_val(new ReQL_Obj_t);

    const double num = 3.14;

    reql_number_init(new_val.get(), num);

    REQUIRE(reql_object_add(obj.get(), key.get(), new_val.get()) == 0);
    REQUIRE(reql_object_get(obj.get(), key.get()) != nullptr);

    ReQL_Obj_t *res = reql_object_get(obj.get(), key.get());

    REQUIRE(reql_datum_type(res) == REQL_R_NUM);
    REQUIRE(reql_to_number(res) == Approx(num));
    REQUIRE(res == new_val.get());
  }

  SECTION("duplicate key") {
    std::unique_ptr<ReQL_Obj_t> new_key(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t> new_val(new ReQL_Obj_t);

    const double num = 3.14;

    std::unique_ptr<uint8_t> new_buf(new uint8_t[size]);
    const uint8_t new_string[] = "key";

    reql_string_init(new_key.get(), new_buf.get(), size);
    reql_string_append(new_key.get(), new_string, size);

    reql_number_init(new_val.get(), num);

    REQUIRE(reql_object_add(obj.get(), new_key.get(), new_val.get()) == 0);
    REQUIRE(reql_object_get(obj.get(), new_key.get()) != nullptr);

    ReQL_Obj_t *res = reql_object_get(obj.get(), new_key.get());

    REQUIRE(reql_datum_type(res) == REQL_R_NUM);
    REQUIRE(res == new_val.get());

    new_buf.reset();
  }

  SECTION("out of space") {
    std::unique_ptr<ReQL_Obj_t> new_key(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t> new_val(new ReQL_Obj_t);

    const double num = 3.14;

    std::unique_ptr<uint8_t> new_buf(new uint8_t[size]);
    const uint8_t new_string[] = "new";

    reql_string_init(new_key.get(), new_buf.get(), size);
    reql_string_append(new_key.get(), new_string, size);

    reql_number_init(new_val.get(), num);

    REQUIRE(reql_object_add(obj.get(), new_key.get(), new_val.get()) > 1);
    REQUIRE(reql_object_get(obj.get(), new_key.get()) == nullptr);

    ReQL_Obj_t *res = reql_object_get(obj.get(), key.get());

    REQUIRE(reql_datum_type(res) == REQL_R_NULL);
    REQUIRE(res == val.get());

    new_buf.reset();
  }

  buf.reset();
}

TEST_CASE("c expr", "[reql][expr]") {
  std::unique_ptr<ReQL_Obj_t> val(new ReQL_Obj_t);

  SECTION("bool") {
    reql_bool_init(val.get(), 10);

    REQUIRE(reql_datum_type(val.get()) == REQL_R_BOOL);

    REQUIRE(reql_to_bool(val.get()) == true);

    reql_bool_init(val.get(), false);

    REQUIRE(reql_to_bool(val.get()) == false);
  }

  SECTION("null") {
    reql_null_init(val.get());

    REQUIRE(reql_datum_type(val.get()) == REQL_R_NULL);
  }

  SECTION("number") {
    const double num = 42.0;

    reql_number_init(val.get(), num);

    REQUIRE(reql_datum_type(val.get()) == REQL_R_NUM);

    REQUIRE(num == Approx(reql_to_number(val.get())));
  }

  SECTION("number edges") {
    const double num = std::numeric_limits<std::double_t>::max();

    reql_number_init(val.get(), num);

    REQUIRE(num == Approx(reql_to_number(val.get())));
  }

  SECTION("string") {
    const std::uint32_t size = 12;

    std::unique_ptr<uint8_t> buf(new uint8_t[size]);
    const std::uint8_t hello[] = "Hello World";

    std::string orig = std::string(reinterpret_cast<char*>(const_cast<std::uint8_t*>(hello)), size);

    reql_string_init(val.get(), buf.get(), size);
    reql_string_append(val.get(), hello, size);

    REQUIRE(reql_datum_type(val.get()) == REQL_R_STR);

    REQUIRE(orig.compare(0, size, reinterpret_cast<char*>(reql_string_buf(val.get())), size) == 0);
    REQUIRE(size == reql_size(val.get()));

    buf.reset();
  }
}
