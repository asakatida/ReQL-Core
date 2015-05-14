// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("cpp secondary indexes on times", "[cpp][ast]") {

  SECTION("test8") {
    double num0(5);
    Result var0(num0);
  }

  SECTION("test10") {
    std::string src0("Duplicate primary key `id`:\n{\n\t\"id\":\t{\n\t\t\"$reql_type$\":\t\"TIME\",\n\t\t\"epoch_time\":\t1375445163.0869998932,\n\t\t\"timezone\":\t\"-07:00\"\n\t}\n}\n{\n\t\"id\":\t{\n\t\t\"$reql_type$\":\t\"TIME\",\n\t\t\"epoch_time\":\t1375445163.0869998932,\n\t\t\"timezone\":\t\"+00:00\"\n\t}\n}", 295);
    Result var0(src0);
  }

  SECTION("test11") {
    double num0(5);
    Result var0(num0);
  }

  SECTION("test12") {
    double num0(3);
    Result var0(num0);
  }

  SECTION("test13") {
    double num0(4);
    Result var0(num0);
  }

  SECTION("test14") {
    double num0(5);
    Result var0(num0);
  }

  SECTION("test15") {
    double num0(3);
    Result var0(num0);
  }

  SECTION("test16") {
    double num0(4);
    Result var0(num0);
  }

  SECTION("test17") {
    double num0(5);
    Result var0(num0);
  }

  SECTION("test18") {
    std::map<std::string, Result> map0;

    std::string src1("created", 7);
    Result var1(src1);

    double num2(1);
    Result var2(num2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test19") {
    double num0(1);
    Result var0(num0);
  }

  SECTION("test20") {
    double num0(5);
    Result var0(num0);
  }

  SECTION("test21") {
    double num0(3);
    Result var0(num0);
  }

  SECTION("test22") {
    double num0(4);
    Result var0(num0);
  }

  SECTION("test23") {
    double num0(5);
    Result var0(num0);
  }

  SECTION("test24") {
    double num0(3);
    Result var0(num0);
  }

  SECTION("test25") {
    double num0(4);
    Result var0(num0);
  }

  SECTION("test26") {
    std::map<std::string, Result> map0;

    std::string src1("created", 7);
    Result var1(src1);

    double num2(1);
    Result var2(num2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test27") {
    double num0(1);
    Result var0(num0);
  }

  SECTION("test28") {
    double num0(1);
    Result var0(num0);
  }

  SECTION("test29") {
    double num0(3);
    Result var0(num0);
  }

  SECTION("test30") {
    double num0(3);
    Result var0(num0);
  }

  SECTION("test31") {
    double num0(3);
    Result var0(num0);
  }

  SECTION("test32") {
    double num0(3);
    Result var0(num0);
  }

  SECTION("test33") {
    double num0(3);
    Result var0(num0);
  }

  SECTION("test34") {
    double num0(3);
    Result var0(num0);
  }

  SECTION("test37") {
    double num0(1);
    Result var0(num0);
  }

  SECTION("test38") {
    std::string src0("PTYPE<TIME>", 11);
    Result var0(src0);
  }
}
