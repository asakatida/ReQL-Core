// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("cpp Tests of converstion to and from the RQL binary type", "[cpp][ast]") {

  SECTION("test1") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("s", 1);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test2") {
    double num0(0);
    Result var0(num0);
  }

  SECTION("test4") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("s", 1);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test5") {
    double num0(1);
    Result var0(num0);
  }

  SECTION("test7") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("s", 1);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test8") {
    double num0(2);
    Result var0(num0);
  }

  SECTION("test10") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("s", 1);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test11") {
    double num0(3);
    Result var0(num0);
  }

  SECTION("test13") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("s", 1);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test14") {
    double num0(4);
    Result var0(num0);
  }

  SECTION("test16") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("s", 1);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test17") {
    double num0(5);
    Result var0(num0);
  }

  SECTION("test19") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("s", 1);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test20") {
    double num0(6);
    Result var0(num0);
  }

  SECTION("test22") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("s", 1);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test23") {
    double num0(7);
    Result var0(num0);
  }

  SECTION("test25") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("s", 1);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test26") {
    double num0(8);
    Result var0(num0);
  }

  SECTION("test28") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("s", 1);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test29") {
    double num0(9);
    Result var0(num0);
  }

  SECTION("test31") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("s", 1);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test32") {
    double num0(10);
    Result var0(num0);
  }

  SECTION("test34") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("s", 1);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test35") {
    double num0(11);
    Result var0(num0);
  }

  SECTION("test37") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("s", 1);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test38") {
    double num0(12);
    Result var0(num0);
  }

  SECTION("test45") {
    Result var0(true);
  }

  SECTION("test46") {
    Result var0(true);
  }

  SECTION("test47") {
    Result var0(true);
  }

  SECTION("test48") {
    Result var0(false);
  }

  SECTION("test49") {
    Result var0(false);
  }

  SECTION("test50") {
    Result var0(false);
  }

  SECTION("test51") {
    Result var0(true);
  }

  SECTION("test52") {
    Result var0(true);
  }

  SECTION("test53") {
    Result var0(true);
  }

  SECTION("test54") {
    Result var0(false);
  }

  SECTION("test55") {
    Result var0(false);
  }

  SECTION("test56") {
    Result var0(false);
  }

  SECTION("test57") {
    Result var0(true);
  }

  SECTION("test58") {
    Result var0(true);
  }

  SECTION("test59") {
    Result var0(true);
  }

  SECTION("test60") {
    Result var0(false);
  }

  SECTION("test61") {
    Result var0(false);
  }

  SECTION("test62") {
    Result var0(false);
  }

  SECTION("test63") {
    Result var0(true);
  }

  SECTION("test64") {
    Result var0(true);
  }

  SECTION("test65") {
    Result var0(true);
  }

  SECTION("test66") {
    Result var0(false);
  }

  SECTION("test67") {
    Result var0(false);
  }

  SECTION("test68") {
    Result var0(false);
  }

  SECTION("test69") {
    Result var0(true);
  }

  SECTION("test70") {
    Result var0(true);
  }

  SECTION("test71") {
    Result var0(true);
  }

  SECTION("test72") {
    Result var0(false);
  }

  SECTION("test73") {
    Result var0(false);
  }

  SECTION("test74") {
    Result var0(false);
  }

  SECTION("test75") {
    Result var0(true);
  }

  SECTION("test76") {
    Result var0(true);
  }

  SECTION("test77") {
    Result var0(true);
  }

  SECTION("test78") {
    Result var0(false);
  }

  SECTION("test79") {
    Result var0(false);
  }

  SECTION("test80") {
    Result var0(false);
  }

  SECTION("test81") {
    Result var0(true);
  }

  SECTION("test82") {
    Result var0(true);
  }

  SECTION("test83") {
    Result var0(true);
  }

  SECTION("test84") {
    Result var0(false);
  }

  SECTION("test85") {
    Result var0(false);
  }

  SECTION("test86") {
    Result var0(false);
  }

  SECTION("test87") {
    std::map<std::string, Result> map0;

    std::string src1("result", 6);
    Result var1(src1);

    std::string src2("blank", 5);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test88") {
    std::map<std::string, Result> map0;

    std::string src1("result", 6);
    Result var1(src1);

    std::string src2("blank", 5);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test89") {
    std::map<std::string, Result> map0;

    std::string src1("result", 6);
    Result var1(src1);

    std::string src2("blank", 5);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test90") {
    std::string src0("foo", 3);
    Result var0(src0);
  }

  SECTION("test91") {
    std::map<std::string, Result> map0;

    std::string src1("result", 6);
    Result var1(src1);

    std::string src2("blank", 5);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test92") {
    std::map<std::string, Result> map0;

    std::string src1("result", 6);
    Result var1(src1);

    std::string src2("blank", 5);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test93") {
    std::string src0("foo", 3);
    Result var0(src0);
  }

  SECTION("test94") {
    std::string src0("foo", 3);
    Result var0(src0);
  }

  SECTION("test95") {
    std::string src0("ef", 2);
    Result var0(src0);
  }

  SECTION("test96") {
    std::string src0("ab", 2);
    Result var0(src0);
  }

  SECTION("test97") {
    std::string src0("def", 3);
    Result var0(src0);
  }

  SECTION("test98") {
    std::string src0("cde", 3);
    Result var0(src0);
  }

  SECTION("test99") {
    std::string src0("ab", 2);
    Result var0(src0);
  }

  SECTION("test100") {
    std::string src0("fg", 2);
    Result var0(src0);
  }

  SECTION("test101") {
    std::string src0("ab", 2);
    Result var0(src0);
  }

  SECTION("test102") {
    std::string src0("fg", 2);
    Result var0(src0);
  }

  SECTION("test103") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("b", 1);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test104") {
    std::map<std::string, Result> map0;

    std::string src1("$reql_type$", 11);
    Result var1(src1);

    std::string src2("BINARY", 6);
    Result var2(src2);

    map0.insert({src1, var2});

    std::string src3("data", 4);
    Result var3(src3);

    std::string src4("AAE=", 4);
    Result var4(src4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test105") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("Buffer", 6);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test106") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test107") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test108") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test109") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test110") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test111") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test112") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test113") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test114") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test115") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test116") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test117") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }
}
