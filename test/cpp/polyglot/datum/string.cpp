// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./test.hpp"
#include "./ReQL.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("cpp Tests of converstion to and from the RQL string type", "[cpp][ast]") {

  SECTION("test0") {
    std::string src0("str", 3);
    Query var0(src0);
  }

  SECTION("test1") {
    std::string src0("str", 3);
    Query var0(src0);
  }

  SECTION("test2") {
    std::string src0("str", 3);
    Query var0(src0);
  }

  SECTION("test3") {
    std::string src0("\u3053\u3093\u306b\u3061\u306f", 30);
    Query var0(src0);
  }

  SECTION("test4") {
    std::string src0("STRING", 6);
    Query var0(src0);
  }

  SECTION("test5") {
    std::string src0("foo", 3);
    Query var0(src0);
  }

  SECTION("test6") {
    double num0(-1.2);
    Query var0(num0);
  }

  SECTION("test7") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test8") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test9") {
    double num0(10);
    Query var0(num0);
  }

  SECTION("test10") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test11") {
    Types::array arr0;
    Query var0(arr0);
  }

  SECTION("test12") {
    Types::array arr0;
    Query var0(arr0);
  }

  SECTION("test13") {
    Types::array arr0(1);

    std::string src1("", 0);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test14") {
    Types::array arr0;
    Query var0(arr0);
  }

  SECTION("test15") {
    Types::array arr0;
    Query var0(arr0);
  }

  SECTION("test16") {
    Types::array arr0(1);

    std::string src1("", 0);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test17") {
    Types::array arr0;
    Query var0(arr0);
  }

  SECTION("test18") {
    Types::array arr0(3);

    std::string src1("aaaa", 4);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("bbbb", 4);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("cccc", 4);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test19") {
    Types::array arr0(3);

    std::string src1("aaaa", 4);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("bbbb", 4);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("cccc", 4);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test20") {
    Types::array arr0(5);

    std::string src1("aaaa", 4);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("bbbb", 4);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("", 0);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4("cccc", 4);
    Query var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5("", 0);
    Query var5(src5);

    arr0.insert(arr0.end(), var5);

    Query var0(arr0);
  }

  SECTION("test21") {
    Types::array arr0(16);

    std::string src1("a", 1);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("a", 1);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("a", 1);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4("a", 1);
    Query var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5(" ", 1);
    Query var5(src5);

    arr0.insert(arr0.end(), var5);

    std::string src6("b", 1);
    Query var6(src6);

    arr0.insert(arr0.end(), var6);

    std::string src7("b", 1);
    Query var7(src7);

    arr0.insert(arr0.end(), var7);

    std::string src8("b", 1);
    Query var8(src8);

    arr0.insert(arr0.end(), var8);

    std::string src9("b", 1);
    Query var9(src9);

    arr0.insert(arr0.end(), var9);

    std::string src10(" ", 1);
    Query var10(src10);

    arr0.insert(arr0.end(), var10);

    std::string src11(" ", 1);
    Query var11(src11);

    arr0.insert(arr0.end(), var11);

    std::string src12("c", 1);
    Query var12(src12);

    arr0.insert(arr0.end(), var12);

    std::string src13("c", 1);
    Query var13(src13);

    arr0.insert(arr0.end(), var13);

    std::string src14("c", 1);
    Query var14(src14);

    arr0.insert(arr0.end(), var14);

    std::string src15("c", 1);
    Query var15(src15);

    arr0.insert(arr0.end(), var15);

    std::string src16(" ", 1);
    Query var16(src16);

    arr0.insert(arr0.end(), var16);

    Query var0(arr0);
  }

  SECTION("test22") {
    Types::array arr0(5);

    std::string src1("aaaa ", 5);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("", 0);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4("", 0);
    Query var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5("  cccc ", 7);
    Query var5(src5);

    arr0.insert(arr0.end(), var5);

    Query var0(arr0);
  }

  SECTION("test23") {
    Types::array arr0(3);

    std::string src1("aaaa ", 5);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("  cccc ", 7);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test24") {
    Types::array arr0(2);

    std::string src1("aaaa", 4);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc ", 5);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    Query var0(arr0);
  }

  SECTION("test25") {
    Types::array arr0(6);

    std::string src1("aaaa ", 5);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("  cccc b d ", 11);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4(" e ", 3);
    Query var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5("", 0);
    Query var5(src5);

    arr0.insert(arr0.end(), var5);

    std::string src6(" f", 2);
    Query var6(src6);

    arr0.insert(arr0.end(), var6);

    Query var0(arr0);
  }

  SECTION("test26") {
    Types::array arr0(2);

    std::string src1("aaaa", 4);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc b d bb e bbbb f", 20);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    Query var0(arr0);
  }

  SECTION("test27") {
    Types::array arr0(3);

    std::string src1("aaaa", 4);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc b d bb e", 13);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("f", 1);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test28") {
    Types::array arr0(3);

    std::string src1("aaaa", 4);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("bbbb", 4);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("cccc", 4);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test29") {
    Types::array arr0(5);

    std::string src1("aaaa", 4);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("bbbb", 4);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("", 0);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4("cccc", 4);
    Query var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5("", 0);
    Query var5(src5);

    arr0.insert(arr0.end(), var5);

    Query var0(arr0);
  }

  SECTION("test30") {
    Types::array arr0(6);

    std::string src1("a", 1);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("a", 1);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("a", 1);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4("a", 1);
    Query var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5(" ", 1);
    Query var5(src5);

    arr0.insert(arr0.end(), var5);

    std::string src6("bbbb  cccc ", 11);
    Query var6(src6);

    arr0.insert(arr0.end(), var6);

    Query var0(arr0);
  }

  SECTION("test31") {
    Types::array arr0(5);

    std::string src1("aaaa ", 5);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("", 0);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4("", 0);
    Query var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5("  cccc ", 7);
    Query var5(src5);

    arr0.insert(arr0.end(), var5);

    Query var0(arr0);
  }

  SECTION("test32") {
    Types::array arr0(3);

    std::string src1("aaaa ", 5);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("  cccc ", 7);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test33") {
    Types::array arr0(2);

    std::string src1("aaaa", 4);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc ", 5);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    Query var0(arr0);
  }

  SECTION("test34") {
    Types::array arr0(6);

    std::string src1("aaaa ", 5);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("  cccc b d ", 11);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4(" e ", 3);
    Query var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5("", 0);
    Query var5(src5);

    arr0.insert(arr0.end(), var5);

    std::string src6(" f", 2);
    Query var6(src6);

    arr0.insert(arr0.end(), var6);

    Query var0(arr0);
  }

  SECTION("test35") {
    Types::array arr0(2);

    std::string src1("aaaa", 4);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc b d bb e bbbb f", 20);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    Query var0(arr0);
  }

  SECTION("test36") {
    Types::array arr0(3);

    std::string src1("aaaa", 4);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc b d bb e", 13);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("f", 1);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test37") {
    Types::array arr0(3);

    std::string src1("aaaa", 4);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("bbbb", 4);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("cccc ", 5);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test38") {
    Types::array arr0(2);

    std::string src1("a", 1);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("b", 1);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    Query var0(arr0);
  }

  SECTION("test39") {
    Types::array arr0(5);

    std::string src1("aaaa", 4);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("bbbb", 4);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("", 0);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4("cccc", 4);
    Query var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5("", 0);
    Query var5(src5);

    arr0.insert(arr0.end(), var5);

    Query var0(arr0);
  }

  SECTION("test40") {
    Types::array arr0(5);

    std::string src1("a", 1);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("a", 1);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("a", 1);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4("a", 1);
    Query var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5(" bbbb  cccc ", 12);
    Query var5(src5);

    arr0.insert(arr0.end(), var5);

    Query var0(arr0);
  }

  SECTION("test41") {
    Types::array arr0(5);

    std::string src1("aaaa ", 5);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("", 0);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4("", 0);
    Query var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5("  cccc ", 7);
    Query var5(src5);

    arr0.insert(arr0.end(), var5);

    Query var0(arr0);
  }

  SECTION("test42") {
    Types::array arr0(3);

    std::string src1("aaaa ", 5);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("  cccc ", 7);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test43") {
    Types::array arr0(2);

    std::string src1("aaaa", 4);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc ", 5);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    Query var0(arr0);
  }

  SECTION("test44") {
    Types::array arr0(6);

    std::string src1("aaaa ", 5);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("  cccc b d ", 11);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4(" e ", 3);
    Query var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5("", 0);
    Query var5(src5);

    arr0.insert(arr0.end(), var5);

    std::string src6(" f", 2);
    Query var6(src6);

    arr0.insert(arr0.end(), var6);

    Query var0(arr0);
  }

  SECTION("test45") {
    Types::array arr0(2);

    std::string src1("aaaa", 4);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc b d bb e bbbb f", 20);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    Query var0(arr0);
  }

  SECTION("test46") {
    Types::array arr0(3);

    std::string src1("aaaa", 4);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc b d bb e", 13);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("f", 1);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test47") {
    Types::array arr0(2);

    std::string src1("aaaa", 4);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("bbbb  cccc ", 11);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    Query var0(arr0);
  }

  SECTION("test48") {
    Types::array arr0(3);

    std::string src1("aaaa", 4);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("bbbb", 4);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3(" cccc ", 6);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test49") {
    Types::array arr0(3);

    std::string src1("a", 1);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("a", 1);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("aa bbbb  cccc ", 14);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test50") {
    Types::array arr0(3);

    std::string src1("aaaa ", 5);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("bb  cccc ", 9);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test51") {
    Types::array arr0(3);

    std::string src1("aaaa ", 5);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("  cccc ", 7);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test52") {
    Types::array arr0(2);

    std::string src1("aaaa", 4);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc ", 5);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    Query var0(arr0);
  }

  SECTION("test53") {
    Types::array arr0(3);

    std::string src1("aaaa ", 5);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("  cccc b d bb e bbbb f", 22);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test54") {
    Types::array arr0(2);

    std::string src1("aaaa", 4);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc b d bb e bbbb f", 20);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    Query var0(arr0);
  }

  SECTION("test55") {
    Types::array arr0(3);

    std::string src1("aaaa", 4);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc b d bb e", 13);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("f", 1);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test56") {
    Types::array arr0;
    Query var0(arr0);
  }

  SECTION("test57") {
    Types::array arr0;
    Query var0(arr0);
  }

  SECTION("test58") {
    Types::array arr0(3);

    std::string src1("", 0);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("", 0);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test59") {
    Types::array arr0;
    Query var0(arr0);
  }

  SECTION("test60") {
    Types::array arr0(3);

    std::string src1("", 0);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("", 0);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test61") {
    Types::array arr0(3);

    std::string src1("aaaa", 4);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("bbbb", 4);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("cccc", 4);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test62") {
    Types::array arr0(3);

    std::string src1("aaaa", 4);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("bbbb", 4);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("cccc", 4);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test63") {
    Types::array arr0(7);

    std::string src1("", 0);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("aaaa", 4);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4("bbbb", 4);
    Query var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5("", 0);
    Query var5(src5);

    arr0.insert(arr0.end(), var5);

    std::string src6("cccc", 4);
    Query var6(src6);

    arr0.insert(arr0.end(), var6);

    std::string src7("", 0);
    Query var7(src7);

    arr0.insert(arr0.end(), var7);

    Query var0(arr0);
  }

  SECTION("test64") {
    Types::array arr0(5);

    std::string src1("  aaaa ", 7);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("", 0);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4("", 0);
    Query var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5("  cccc ", 7);
    Query var5(src5);

    arr0.insert(arr0.end(), var5);

    Query var0(arr0);
  }

  SECTION("test65") {
    Types::array arr0(3);

    std::string src1("  aaaa ", 7);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("  cccc ", 7);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test66") {
    Types::array arr0(2);

    std::string src1("  aaaa", 6);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc ", 5);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    Query var0(arr0);
  }

  SECTION("test67") {
    Types::array arr0(6);

    std::string src1("  aaaa ", 7);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("  cccc b d ", 11);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4(" e ", 3);
    Query var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5("", 0);
    Query var5(src5);

    arr0.insert(arr0.end(), var5);

    std::string src6(" f", 2);
    Query var6(src6);

    arr0.insert(arr0.end(), var6);

    Query var0(arr0);
  }

  SECTION("test68") {
    Types::array arr0(2);

    std::string src1("  aaaa", 6);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc b d bb e bbbb f", 20);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    Query var0(arr0);
  }

  SECTION("test69") {
    Types::array arr0(3);

    std::string src1("  aaaa", 6);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc b d bb e", 13);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("f", 1);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test70") {
    Types::array arr0(3);

    std::string src1("aaaa", 4);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("bbbb", 4);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("cccc", 4);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test71") {
    Types::array arr0(6);

    std::string src1("", 0);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("aaaa", 4);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4("bbbb", 4);
    Query var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5("", 0);
    Query var5(src5);

    arr0.insert(arr0.end(), var5);

    std::string src6("cccc ", 5);
    Query var6(src6);

    arr0.insert(arr0.end(), var6);

    Query var0(arr0);
  }

  SECTION("test72") {
    Types::array arr0(5);

    std::string src1("  aaaa ", 7);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("", 0);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4("", 0);
    Query var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5("  cccc ", 7);
    Query var5(src5);

    arr0.insert(arr0.end(), var5);

    Query var0(arr0);
  }

  SECTION("test73") {
    Types::array arr0(3);

    std::string src1("  aaaa ", 7);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("  cccc ", 7);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test74") {
    Types::array arr0(2);

    std::string src1("  aaaa", 6);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc ", 5);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    Query var0(arr0);
  }

  SECTION("test75") {
    Types::array arr0(6);

    std::string src1("  aaaa ", 7);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("  cccc b d ", 11);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4(" e ", 3);
    Query var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5("", 0);
    Query var5(src5);

    arr0.insert(arr0.end(), var5);

    std::string src6(" f", 2);
    Query var6(src6);

    arr0.insert(arr0.end(), var6);

    Query var0(arr0);
  }

  SECTION("test76") {
    Types::array arr0(2);

    std::string src1("  aaaa", 6);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc b d bb e bbbb f", 20);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    Query var0(arr0);
  }

  SECTION("test77") {
    Types::array arr0(3);

    std::string src1("  aaaa", 6);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc b d bb e", 13);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("f", 1);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test78") {
    Types::array arr0(3);

    std::string src1("aaaa", 4);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("bbbb", 4);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("cccc ", 5);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test79") {
    Types::array arr0(2);

    std::string src1("a", 1);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("b", 1);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    Query var0(arr0);
  }

  SECTION("test80") {
    Types::array arr0(5);

    std::string src1("", 0);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("aaaa", 4);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4("bbbb", 4);
    Query var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5(" cccc ", 6);
    Query var5(src5);

    arr0.insert(arr0.end(), var5);

    Query var0(arr0);
  }

  SECTION("test81") {
    Types::array arr0(5);

    std::string src1("  aaaa ", 7);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("", 0);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4("", 0);
    Query var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5("  cccc ", 7);
    Query var5(src5);

    arr0.insert(arr0.end(), var5);

    Query var0(arr0);
  }

  SECTION("test82") {
    Types::array arr0(3);

    std::string src1("  aaaa ", 7);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("  cccc ", 7);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test83") {
    Types::array arr0(2);

    std::string src1("  aaaa", 6);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc ", 5);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    Query var0(arr0);
  }

  SECTION("test84") {
    Types::array arr0(6);

    std::string src1("  aaaa ", 7);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("  cccc b d ", 11);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4(" e ", 3);
    Query var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5("", 0);
    Query var5(src5);

    arr0.insert(arr0.end(), var5);

    std::string src6(" f", 2);
    Query var6(src6);

    arr0.insert(arr0.end(), var6);

    Query var0(arr0);
  }

  SECTION("test85") {
    Types::array arr0(2);

    std::string src1("  aaaa", 6);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc b d bb e bbbb f", 20);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    Query var0(arr0);
  }

  SECTION("test86") {
    Types::array arr0(3);

    std::string src1("  aaaa", 6);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc b d bb e", 13);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("f", 1);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test87") {
    Types::array arr0(2);

    std::string src1("aaaa", 4);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("bbbb  cccc ", 11);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    Query var0(arr0);
  }

  SECTION("test88") {
    Types::array arr0(3);

    std::string src1("", 0);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("aaaa bbbb  cccc ", 16);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test89") {
    Types::array arr0(3);

    std::string src1("  aaaa ", 7);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("bb  cccc ", 9);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test90") {
    Types::array arr0(3);

    std::string src1("  aaaa ", 7);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("  cccc ", 7);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test91") {
    Types::array arr0(2);

    std::string src1("  aaaa", 6);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc ", 5);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    Query var0(arr0);
  }

  SECTION("test92") {
    Types::array arr0(3);

    std::string src1("  aaaa ", 7);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("  cccc b d bb e bbbb f", 22);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test93") {
    Types::array arr0(2);

    std::string src1("  aaaa", 6);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc b d bb e bbbb f", 20);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    Query var0(arr0);
  }

  SECTION("test94") {
    Types::array arr0(3);

    std::string src1("  aaaa", 6);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc b d bb e", 13);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("f", 1);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test95") {
    std::string src0("ABC-DEF-GHJ", 11);
    Query var0(src0);
  }

  SECTION("test96") {
    std::string src0("abc-def-ghj", 11);
    Query var0(src0);
  }

  SECTION("test97") {
    Types::array arr0(4);

    std::string src1("f", 1);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("\xe9", 4);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("o", 1);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4("o", 1);
    Query var4(src4);

    arr0.insert(arr0.end(), var4);

    Query var0(arr0);
  }

  SECTION("test98") {
    Types::array arr0(4);

    std::string src1("f", 1);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("e\u0301", 7);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("o", 1);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4("o", 1);
    Query var4(src4);

    arr0.insert(arr0.end(), var4);

    Query var0(arr0);
  }

  SECTION("test99") {
    Types::array arr0(7);

    std::string src1("foo", 3);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("bar", 3);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("baz", 3);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4("quux", 4);
    Query var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5("fred", 4);
    Query var5(src5);

    arr0.insert(arr0.end(), var5);

    std::string src6("barney", 6);
    Query var6(src6);

    arr0.insert(arr0.end(), var6);

    std::string src7("wilma", 5);
    Query var7(src7);

    arr0.insert(arr0.end(), var7);

    Query var0(arr0);
  }

  SECTION("test100") {
    Types::array arr0(7);

    std::string src1("foo", 3);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("bar", 3);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("baz\u2060quux", 13);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4("fred", 4);
    Query var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5("barney", 6);
    Query var5(src5);

    arr0.insert(arr0.end(), var5);

    std::string src6("wilma", 5);
    Query var6(src6);

    arr0.insert(arr0.end(), var6);

    std::string src7("betty\u200b", 11);
    Query var7(src7);

    arr0.insert(arr0.end(), var7);

    Query var0(arr0);
  }
}
