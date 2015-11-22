// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./ReQL.hpp"

using namespace ReQL;

TEST_CASE("cpp Tests of converstion to and from the RQL binary type", "[cpp][ast]") {

  SECTION("test1") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("s", 1);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test2") {
    double num0(0);
    Query var0(num0);
  }

  SECTION("test4") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("s", 1);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test5") {
    double num0(1);
    Query var0(num0);
  }

  SECTION("test7") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("s", 1);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test8") {
    double num0(2);
    Query var0(num0);
  }

  SECTION("test10") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("s", 1);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test11") {
    double num0(3);
    Query var0(num0);
  }

  SECTION("test13") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("s", 1);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test14") {
    double num0(4);
    Query var0(num0);
  }

  SECTION("test16") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("s", 1);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test17") {
    double num0(5);
    Query var0(num0);
  }

  SECTION("test19") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("s", 1);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test20") {
    double num0(6);
    Query var0(num0);
  }

  SECTION("test22") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("s", 1);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test23") {
    double num0(7);
    Query var0(num0);
  }

  SECTION("test25") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("s", 1);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test26") {
    double num0(8);
    Query var0(num0);
  }

  SECTION("test28") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("s", 1);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test29") {
    double num0(9);
    Query var0(num0);
  }

  SECTION("test31") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("s", 1);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test32") {
    double num0(10);
    Query var0(num0);
  }

  SECTION("test34") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("s", 1);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test35") {
    double num0(11);
    Query var0(num0);
  }

  SECTION("test37") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("s", 1);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test38") {
    double num0(12);
    Query var0(num0);
  }

  SECTION("test45") {
    Query var0(true);
  }

  SECTION("test46") {
    Query var0(true);
  }

  SECTION("test47") {
    Query var0(true);
  }

  SECTION("test48") {
    Query var0(false);
  }

  SECTION("test49") {
    Query var0(false);
  }

  SECTION("test50") {
    Query var0(false);
  }

  SECTION("test51") {
    Query var0(true);
  }

  SECTION("test52") {
    Query var0(true);
  }

  SECTION("test53") {
    Query var0(true);
  }

  SECTION("test54") {
    Query var0(false);
  }

  SECTION("test55") {
    Query var0(false);
  }

  SECTION("test56") {
    Query var0(false);
  }

  SECTION("test57") {
    Query var0(true);
  }

  SECTION("test58") {
    Query var0(true);
  }

  SECTION("test59") {
    Query var0(true);
  }

  SECTION("test60") {
    Query var0(false);
  }

  SECTION("test61") {
    Query var0(false);
  }

  SECTION("test62") {
    Query var0(false);
  }

  SECTION("test63") {
    Query var0(true);
  }

  SECTION("test64") {
    Query var0(true);
  }

  SECTION("test65") {
    Query var0(true);
  }

  SECTION("test66") {
    Query var0(false);
  }

  SECTION("test67") {
    Query var0(false);
  }

  SECTION("test68") {
    Query var0(false);
  }

  SECTION("test69") {
    Query var0(true);
  }

  SECTION("test70") {
    Query var0(true);
  }

  SECTION("test71") {
    Query var0(true);
  }

  SECTION("test72") {
    Query var0(false);
  }

  SECTION("test73") {
    Query var0(false);
  }

  SECTION("test74") {
    Query var0(false);
  }

  SECTION("test75") {
    Query var0(true);
  }

  SECTION("test76") {
    Query var0(true);
  }

  SECTION("test77") {
    Query var0(true);
  }

  SECTION("test78") {
    Query var0(false);
  }

  SECTION("test79") {
    Query var0(false);
  }

  SECTION("test80") {
    Query var0(false);
  }

  SECTION("test81") {
    Query var0(true);
  }

  SECTION("test82") {
    Query var0(true);
  }

  SECTION("test83") {
    Query var0(true);
  }

  SECTION("test84") {
    Query var0(false);
  }

  SECTION("test85") {
    Query var0(false);
  }

  SECTION("test86") {
    Query var0(false);
  }

  SECTION("test87") {
    std::map<std::string, Query> map0;

    std::string src1("result", 6);
    Query var1(src1);

    std::string src2("blank", 5);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test88") {
    std::map<std::string, Query> map0;

    std::string src1("result", 6);
    Query var1(src1);

    std::string src2("blank", 5);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test89") {
    std::map<std::string, Query> map0;

    std::string src1("result", 6);
    Query var1(src1);

    std::string src2("blank", 5);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test90") {
    std::string src0("foo", 3);
    Query var0(src0);
  }

  SECTION("test91") {
    std::map<std::string, Query> map0;

    std::string src1("result", 6);
    Query var1(src1);

    std::string src2("blank", 5);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test92") {
    std::map<std::string, Query> map0;

    std::string src1("result", 6);
    Query var1(src1);

    std::string src2("blank", 5);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test93") {
    std::string src0("foo", 3);
    Query var0(src0);
  }

  SECTION("test94") {
    std::string src0("foo", 3);
    Query var0(src0);
  }

  SECTION("test95") {
    std::string src0("ef", 2);
    Query var0(src0);
  }

  SECTION("test96") {
    std::string src0("ab", 2);
    Query var0(src0);
  }

  SECTION("test97") {
    std::string src0("def", 3);
    Query var0(src0);
  }

  SECTION("test98") {
    std::string src0("cde", 3);
    Query var0(src0);
  }

  SECTION("test99") {
    std::string src0("ab", 2);
    Query var0(src0);
  }

  SECTION("test100") {
    std::string src0("fg", 2);
    Query var0(src0);
  }

  SECTION("test101") {
    std::string src0("ab", 2);
    Query var0(src0);
  }

  SECTION("test102") {
    std::string src0("fg", 2);
    Query var0(src0);
  }

  SECTION("test103") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("b", 1);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test104") {
    std::map<std::string, Query> map0;

    std::string src1("$reql_type$", 11);
    Query var1(src1);

    std::string src2("BINARY", 6);
    Query var2(src2);

    map0.insert({src1, var2});

    std::string src3("data", 4);
    Query var3(src3);

    std::string src4("AAE=", 4);
    Query var4(src4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test105") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("Buffer", 6);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test106") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test107") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test108") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test109") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test110") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test111") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test112") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test113") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test114") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test115") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test116") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test117") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }
}
