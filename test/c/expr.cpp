// Copyright 2015 Adam Grandquist

#include <limits>
#include <string>

#include "./test.hpp"

#include "./catch.hpp"

using namespace ReQL;

TEST_CASE("c expr array", "[c][expr][array]") {
  std::unique_ptr<ReQL_Obj_t> ary(new ReQL_Obj_t);

  const uint32_t size = 5;

  ReQL_Obj_t *arr[size];

  reql_array_init(ary.get(), arr, size);

  CHECK(reql_datum_type(ary.get()) == REQL_R_ARRAY);

  CHECK(reql_size(ary.get()) == 0);

  SECTION("over fill array") {
    uint32_t i;

    for (i=0; i < size; ++i) {
      CHECK(reql_array_append(ary.get(), ary.get()) == 0);
    }

    CHECK(reql_array_append(ary.get(), ary.get()) != 0);
  }

  SECTION("grow and shrink") {
    reql_array_append(ary.get(), ary.get());

    CHECK(reql_array_pop(ary.get()) != NULL);
    CHECK(reql_array_last(ary.get()) == NULL);
    CHECK(reql_array_pop(ary.get()) == NULL);
  }

  SECTION("insert after end") {
    CHECK(reql_array_insert(ary.get(), ary.get(), size * 2) != 0);
  }
}

TEST_CASE("c expr object", "[c][expr][object]") {
  std::unique_ptr<ReQL_Obj_t> obj(new ReQL_Obj_t);
  std::unique_ptr<ReQL_Obj_t> key(new ReQL_Obj_t);
  std::unique_ptr<ReQL_Obj_t> val(new ReQL_Obj_t);

  ReQL_Pair_t pair[1];

  reql_object_init(obj.get(), pair, 1);

  CHECK(reql_datum_type(obj.get()) == REQL_R_OBJECT);

  const uint32_t size = 4;

  std::unique_ptr<uint8_t> buf(new uint8_t[size]);
  const uint8_t string[] = "key";

  reql_string_init(key.get(), buf.get(), size);
  reql_string_append(key.get(), string, size);

  reql_null_init(val.get());

  CHECK(reql_object_add(obj.get(), key.get(), val.get()) == 0);

  SECTION("verify insert") {
    CHECK(reql_object_get(obj.get(), key.get()) != NULL);

    ReQL_Obj_t *res = reql_object_get(obj.get(), key.get());

    CHECK(reql_datum_type(res) == REQL_R_NULL);
    CHECK(res == val.get());
  }

  SECTION("reuse key") {
    std::unique_ptr<ReQL_Obj_t> new_val(new ReQL_Obj_t);

    const double num = 3.14;

    reql_number_init(new_val.get(), num);

    CHECK(reql_object_add(obj.get(), key.get(), new_val.get()) == 0);
    CHECK(reql_object_get(obj.get(), key.get()) != NULL);

    ReQL_Obj_t *res = reql_object_get(obj.get(), key.get());

    CHECK(reql_datum_type(res) == REQL_R_NUM);
    CHECK(reql_to_number(res) == Approx(num));
    CHECK(res == new_val.get());
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

    CHECK(reql_object_add(obj.get(), new_key.get(), new_val.get()) == 0);
    CHECK(reql_object_get(obj.get(), new_key.get()) != NULL);

    ReQL_Obj_t *res = reql_object_get(obj.get(), new_key.get());

    CHECK(reql_datum_type(res) == REQL_R_NUM);
    CHECK(res == new_val.get());

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

    CHECK(reql_object_add(obj.get(), new_key.get(), new_val.get()) > 1);
    CHECK(reql_object_get(obj.get(), new_key.get()) == NULL);

    ReQL_Obj_t *res = reql_object_get(obj.get(), key.get());

    CHECK(reql_datum_type(res) == REQL_R_NULL);
    CHECK(res == val.get());

    new_buf.reset();
  }

  buf.reset();
}

TEST_CASE("c expr", "[c][expr]") {
  std::unique_ptr<ReQL_Obj_t> val(new ReQL_Obj_t);

  SECTION("bool") {
    reql_bool_init(val.get(), 10);

    CHECK(reql_datum_type(val.get()) == REQL_R_BOOL);

    CHECK(reql_to_bool(val.get()) == true);

    reql_bool_init(val.get(), false);

    CHECK(reql_to_bool(val.get()) == false);
  }

  SECTION("null") {
    reql_null_init(val.get());

    CHECK(reql_datum_type(val.get()) == REQL_R_NULL);
  }

  SECTION("number") {
    const double num = 42.0;

    reql_number_init(val.get(), num);

    CHECK(reql_datum_type(val.get()) == REQL_R_NUM);

    CHECK(num == Approx(reql_to_number(val.get())));
  }

  SECTION("number edges") {
    const double num = std::numeric_limits<std::double_t>::max();

    reql_number_init(val.get(), num);

    CHECK(num == Approx(reql_to_number(val.get())));
  }

  SECTION("string") {
    const std::uint32_t size = 12;

    std::unique_ptr<uint8_t> buf(new uint8_t[size]);
    const std::uint8_t hello[] = "Hello World";

    std::string orig = std::string(reinterpret_cast<char*>(const_cast<std::uint8_t*>(hello)), size);

    reql_string_init(val.get(), buf.get(), size);
    reql_string_append(val.get(), hello, size);

    CHECK(reql_datum_type(val.get()) == REQL_R_STR);

    CHECK(orig.compare(0, size, reinterpret_cast<char*>(reql_string_buf(val.get())), size) == 0);
    CHECK(size == reql_size(val.get()));

    buf.reset();
  }
}
