// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("cpp Tests of converstion to and from the RQL string type", "[cpp][ast]") {

  SECTION("test0") {
    std::string src0("str", 3);
    Result var0(src0);
  }

  SECTION("test1") {
    std::string src0("str", 3);
    Result var0(src0);
  }

  SECTION("test2") {
    std::string src0("str", 3);
    Result var0(src0);
  }

  SECTION("test3") {
    std::string src0("\u3053\u3093\u306b\u3061\u306f", 30);
    Result var0(src0);
  }

  SECTION("test4") {
    std::string src0("STRING", 6);
    Result var0(src0);
  }

  SECTION("test5") {
    std::string src0("foo", 3);
    Result var0(src0);
  }

  SECTION("test6") {
    double num0(-1.2);
    Result var0(num0);
  }

  SECTION("test7") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test8") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test9") {
    double num0(10);
    Result var0(num0);
  }

  SECTION("test10") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test11") {
    std::vector<Result> arr0;
    Result var0(arr0);
  }

  SECTION("test12") {
    std::vector<Result> arr0;
    Result var0(arr0);
  }

  SECTION("test13") {
    std::vector<Result> arr0(1);

    std::string src1("", 0);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test14") {
    std::vector<Result> arr0;
    Result var0(arr0);
  }

  SECTION("test15") {
    std::vector<Result> arr0;
    Result var0(arr0);
  }

  SECTION("test16") {
    std::vector<Result> arr0(1);

    std::string src1("", 0);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test17") {
    std::vector<Result> arr0;
    Result var0(arr0);
  }

  SECTION("test18") {
    std::vector<Result> arr0(3);

    std::string src1("aaaa", 4);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("bbbb", 4);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("cccc", 4);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test19") {
    std::vector<Result> arr0(3);

    std::string src1("aaaa", 4);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("bbbb", 4);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("cccc", 4);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test20") {
    std::vector<Result> arr0(5);

    std::string src1("aaaa", 4);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("bbbb", 4);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("", 0);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4("cccc", 4);
    Result var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5("", 0);
    Result var5(src5);

    arr0.insert(arr0.end(), var5);

    Result var0(arr0);
  }

  SECTION("test21") {
    std::vector<Result> arr0(16);

    std::string src1("a", 1);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("a", 1);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("a", 1);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4("a", 1);
    Result var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5(" ", 1);
    Result var5(src5);

    arr0.insert(arr0.end(), var5);

    std::string src6("b", 1);
    Result var6(src6);

    arr0.insert(arr0.end(), var6);

    std::string src7("b", 1);
    Result var7(src7);

    arr0.insert(arr0.end(), var7);

    std::string src8("b", 1);
    Result var8(src8);

    arr0.insert(arr0.end(), var8);

    std::string src9("b", 1);
    Result var9(src9);

    arr0.insert(arr0.end(), var9);

    std::string src10(" ", 1);
    Result var10(src10);

    arr0.insert(arr0.end(), var10);

    std::string src11(" ", 1);
    Result var11(src11);

    arr0.insert(arr0.end(), var11);

    std::string src12("c", 1);
    Result var12(src12);

    arr0.insert(arr0.end(), var12);

    std::string src13("c", 1);
    Result var13(src13);

    arr0.insert(arr0.end(), var13);

    std::string src14("c", 1);
    Result var14(src14);

    arr0.insert(arr0.end(), var14);

    std::string src15("c", 1);
    Result var15(src15);

    arr0.insert(arr0.end(), var15);

    std::string src16(" ", 1);
    Result var16(src16);

    arr0.insert(arr0.end(), var16);

    Result var0(arr0);
  }

  SECTION("test22") {
    std::vector<Result> arr0(5);

    std::string src1("aaaa ", 5);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("", 0);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4("", 0);
    Result var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5("  cccc ", 7);
    Result var5(src5);

    arr0.insert(arr0.end(), var5);

    Result var0(arr0);
  }

  SECTION("test23") {
    std::vector<Result> arr0(3);

    std::string src1("aaaa ", 5);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("  cccc ", 7);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test24") {
    std::vector<Result> arr0(2);

    std::string src1("aaaa", 4);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc ", 5);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    Result var0(arr0);
  }

  SECTION("test25") {
    std::vector<Result> arr0(6);

    std::string src1("aaaa ", 5);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("  cccc b d ", 11);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4(" e ", 3);
    Result var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5("", 0);
    Result var5(src5);

    arr0.insert(arr0.end(), var5);

    std::string src6(" f", 2);
    Result var6(src6);

    arr0.insert(arr0.end(), var6);

    Result var0(arr0);
  }

  SECTION("test26") {
    std::vector<Result> arr0(2);

    std::string src1("aaaa", 4);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc b d bb e bbbb f", 20);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    Result var0(arr0);
  }

  SECTION("test27") {
    std::vector<Result> arr0(3);

    std::string src1("aaaa", 4);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc b d bb e", 13);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("f", 1);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test28") {
    std::vector<Result> arr0(3);

    std::string src1("aaaa", 4);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("bbbb", 4);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("cccc", 4);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test29") {
    std::vector<Result> arr0(5);

    std::string src1("aaaa", 4);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("bbbb", 4);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("", 0);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4("cccc", 4);
    Result var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5("", 0);
    Result var5(src5);

    arr0.insert(arr0.end(), var5);

    Result var0(arr0);
  }

  SECTION("test30") {
    std::vector<Result> arr0(6);

    std::string src1("a", 1);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("a", 1);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("a", 1);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4("a", 1);
    Result var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5(" ", 1);
    Result var5(src5);

    arr0.insert(arr0.end(), var5);

    std::string src6("bbbb  cccc ", 11);
    Result var6(src6);

    arr0.insert(arr0.end(), var6);

    Result var0(arr0);
  }

  SECTION("test31") {
    std::vector<Result> arr0(5);

    std::string src1("aaaa ", 5);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("", 0);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4("", 0);
    Result var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5("  cccc ", 7);
    Result var5(src5);

    arr0.insert(arr0.end(), var5);

    Result var0(arr0);
  }

  SECTION("test32") {
    std::vector<Result> arr0(3);

    std::string src1("aaaa ", 5);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("  cccc ", 7);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test33") {
    std::vector<Result> arr0(2);

    std::string src1("aaaa", 4);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc ", 5);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    Result var0(arr0);
  }

  SECTION("test34") {
    std::vector<Result> arr0(6);

    std::string src1("aaaa ", 5);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("  cccc b d ", 11);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4(" e ", 3);
    Result var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5("", 0);
    Result var5(src5);

    arr0.insert(arr0.end(), var5);

    std::string src6(" f", 2);
    Result var6(src6);

    arr0.insert(arr0.end(), var6);

    Result var0(arr0);
  }

  SECTION("test35") {
    std::vector<Result> arr0(2);

    std::string src1("aaaa", 4);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc b d bb e bbbb f", 20);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    Result var0(arr0);
  }

  SECTION("test36") {
    std::vector<Result> arr0(3);

    std::string src1("aaaa", 4);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc b d bb e", 13);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("f", 1);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test37") {
    std::vector<Result> arr0(3);

    std::string src1("aaaa", 4);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("bbbb", 4);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("cccc ", 5);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test38") {
    std::vector<Result> arr0(2);

    std::string src1("a", 1);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("b", 1);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    Result var0(arr0);
  }

  SECTION("test39") {
    std::vector<Result> arr0(5);

    std::string src1("aaaa", 4);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("bbbb", 4);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("", 0);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4("cccc", 4);
    Result var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5("", 0);
    Result var5(src5);

    arr0.insert(arr0.end(), var5);

    Result var0(arr0);
  }

  SECTION("test40") {
    std::vector<Result> arr0(5);

    std::string src1("a", 1);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("a", 1);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("a", 1);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4("a", 1);
    Result var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5(" bbbb  cccc ", 12);
    Result var5(src5);

    arr0.insert(arr0.end(), var5);

    Result var0(arr0);
  }

  SECTION("test41") {
    std::vector<Result> arr0(5);

    std::string src1("aaaa ", 5);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("", 0);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4("", 0);
    Result var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5("  cccc ", 7);
    Result var5(src5);

    arr0.insert(arr0.end(), var5);

    Result var0(arr0);
  }

  SECTION("test42") {
    std::vector<Result> arr0(3);

    std::string src1("aaaa ", 5);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("  cccc ", 7);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test43") {
    std::vector<Result> arr0(2);

    std::string src1("aaaa", 4);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc ", 5);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    Result var0(arr0);
  }

  SECTION("test44") {
    std::vector<Result> arr0(6);

    std::string src1("aaaa ", 5);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("  cccc b d ", 11);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4(" e ", 3);
    Result var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5("", 0);
    Result var5(src5);

    arr0.insert(arr0.end(), var5);

    std::string src6(" f", 2);
    Result var6(src6);

    arr0.insert(arr0.end(), var6);

    Result var0(arr0);
  }

  SECTION("test45") {
    std::vector<Result> arr0(2);

    std::string src1("aaaa", 4);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc b d bb e bbbb f", 20);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    Result var0(arr0);
  }

  SECTION("test46") {
    std::vector<Result> arr0(3);

    std::string src1("aaaa", 4);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc b d bb e", 13);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("f", 1);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test47") {
    std::vector<Result> arr0(2);

    std::string src1("aaaa", 4);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("bbbb  cccc ", 11);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    Result var0(arr0);
  }

  SECTION("test48") {
    std::vector<Result> arr0(3);

    std::string src1("aaaa", 4);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("bbbb", 4);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3(" cccc ", 6);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test49") {
    std::vector<Result> arr0(3);

    std::string src1("a", 1);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("a", 1);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("aa bbbb  cccc ", 14);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test50") {
    std::vector<Result> arr0(3);

    std::string src1("aaaa ", 5);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("bb  cccc ", 9);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test51") {
    std::vector<Result> arr0(3);

    std::string src1("aaaa ", 5);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("  cccc ", 7);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test52") {
    std::vector<Result> arr0(2);

    std::string src1("aaaa", 4);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc ", 5);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    Result var0(arr0);
  }

  SECTION("test53") {
    std::vector<Result> arr0(3);

    std::string src1("aaaa ", 5);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("  cccc b d bb e bbbb f", 22);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test54") {
    std::vector<Result> arr0(2);

    std::string src1("aaaa", 4);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc b d bb e bbbb f", 20);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    Result var0(arr0);
  }

  SECTION("test55") {
    std::vector<Result> arr0(3);

    std::string src1("aaaa", 4);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc b d bb e", 13);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("f", 1);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test56") {
    std::vector<Result> arr0;
    Result var0(arr0);
  }

  SECTION("test57") {
    std::vector<Result> arr0;
    Result var0(arr0);
  }

  SECTION("test58") {
    std::vector<Result> arr0(3);

    std::string src1("", 0);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("", 0);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test59") {
    std::vector<Result> arr0;
    Result var0(arr0);
  }

  SECTION("test60") {
    std::vector<Result> arr0(3);

    std::string src1("", 0);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("", 0);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test61") {
    std::vector<Result> arr0(3);

    std::string src1("aaaa", 4);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("bbbb", 4);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("cccc", 4);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test62") {
    std::vector<Result> arr0(3);

    std::string src1("aaaa", 4);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("bbbb", 4);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("cccc", 4);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test63") {
    std::vector<Result> arr0(7);

    std::string src1("", 0);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("aaaa", 4);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4("bbbb", 4);
    Result var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5("", 0);
    Result var5(src5);

    arr0.insert(arr0.end(), var5);

    std::string src6("cccc", 4);
    Result var6(src6);

    arr0.insert(arr0.end(), var6);

    std::string src7("", 0);
    Result var7(src7);

    arr0.insert(arr0.end(), var7);

    Result var0(arr0);
  }

  SECTION("test64") {
    std::vector<Result> arr0(5);

    std::string src1("  aaaa ", 7);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("", 0);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4("", 0);
    Result var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5("  cccc ", 7);
    Result var5(src5);

    arr0.insert(arr0.end(), var5);

    Result var0(arr0);
  }

  SECTION("test65") {
    std::vector<Result> arr0(3);

    std::string src1("  aaaa ", 7);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("  cccc ", 7);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test66") {
    std::vector<Result> arr0(2);

    std::string src1("  aaaa", 6);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc ", 5);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    Result var0(arr0);
  }

  SECTION("test67") {
    std::vector<Result> arr0(6);

    std::string src1("  aaaa ", 7);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("  cccc b d ", 11);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4(" e ", 3);
    Result var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5("", 0);
    Result var5(src5);

    arr0.insert(arr0.end(), var5);

    std::string src6(" f", 2);
    Result var6(src6);

    arr0.insert(arr0.end(), var6);

    Result var0(arr0);
  }

  SECTION("test68") {
    std::vector<Result> arr0(2);

    std::string src1("  aaaa", 6);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc b d bb e bbbb f", 20);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    Result var0(arr0);
  }

  SECTION("test69") {
    std::vector<Result> arr0(3);

    std::string src1("  aaaa", 6);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc b d bb e", 13);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("f", 1);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test70") {
    std::vector<Result> arr0(3);

    std::string src1("aaaa", 4);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("bbbb", 4);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("cccc", 4);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test71") {
    std::vector<Result> arr0(6);

    std::string src1("", 0);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("aaaa", 4);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4("bbbb", 4);
    Result var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5("", 0);
    Result var5(src5);

    arr0.insert(arr0.end(), var5);

    std::string src6("cccc ", 5);
    Result var6(src6);

    arr0.insert(arr0.end(), var6);

    Result var0(arr0);
  }

  SECTION("test72") {
    std::vector<Result> arr0(5);

    std::string src1("  aaaa ", 7);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("", 0);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4("", 0);
    Result var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5("  cccc ", 7);
    Result var5(src5);

    arr0.insert(arr0.end(), var5);

    Result var0(arr0);
  }

  SECTION("test73") {
    std::vector<Result> arr0(3);

    std::string src1("  aaaa ", 7);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("  cccc ", 7);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test74") {
    std::vector<Result> arr0(2);

    std::string src1("  aaaa", 6);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc ", 5);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    Result var0(arr0);
  }

  SECTION("test75") {
    std::vector<Result> arr0(6);

    std::string src1("  aaaa ", 7);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("  cccc b d ", 11);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4(" e ", 3);
    Result var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5("", 0);
    Result var5(src5);

    arr0.insert(arr0.end(), var5);

    std::string src6(" f", 2);
    Result var6(src6);

    arr0.insert(arr0.end(), var6);

    Result var0(arr0);
  }

  SECTION("test76") {
    std::vector<Result> arr0(2);

    std::string src1("  aaaa", 6);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc b d bb e bbbb f", 20);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    Result var0(arr0);
  }

  SECTION("test77") {
    std::vector<Result> arr0(3);

    std::string src1("  aaaa", 6);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc b d bb e", 13);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("f", 1);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test78") {
    std::vector<Result> arr0(3);

    std::string src1("aaaa", 4);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("bbbb", 4);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("cccc ", 5);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test79") {
    std::vector<Result> arr0(2);

    std::string src1("a", 1);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("b", 1);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    Result var0(arr0);
  }

  SECTION("test80") {
    std::vector<Result> arr0(5);

    std::string src1("", 0);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("aaaa", 4);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4("bbbb", 4);
    Result var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5(" cccc ", 6);
    Result var5(src5);

    arr0.insert(arr0.end(), var5);

    Result var0(arr0);
  }

  SECTION("test81") {
    std::vector<Result> arr0(5);

    std::string src1("  aaaa ", 7);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("", 0);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4("", 0);
    Result var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5("  cccc ", 7);
    Result var5(src5);

    arr0.insert(arr0.end(), var5);

    Result var0(arr0);
  }

  SECTION("test82") {
    std::vector<Result> arr0(3);

    std::string src1("  aaaa ", 7);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("  cccc ", 7);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test83") {
    std::vector<Result> arr0(2);

    std::string src1("  aaaa", 6);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc ", 5);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    Result var0(arr0);
  }

  SECTION("test84") {
    std::vector<Result> arr0(6);

    std::string src1("  aaaa ", 7);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("  cccc b d ", 11);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4(" e ", 3);
    Result var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5("", 0);
    Result var5(src5);

    arr0.insert(arr0.end(), var5);

    std::string src6(" f", 2);
    Result var6(src6);

    arr0.insert(arr0.end(), var6);

    Result var0(arr0);
  }

  SECTION("test85") {
    std::vector<Result> arr0(2);

    std::string src1("  aaaa", 6);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc b d bb e bbbb f", 20);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    Result var0(arr0);
  }

  SECTION("test86") {
    std::vector<Result> arr0(3);

    std::string src1("  aaaa", 6);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc b d bb e", 13);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("f", 1);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test87") {
    std::vector<Result> arr0(2);

    std::string src1("aaaa", 4);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("bbbb  cccc ", 11);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    Result var0(arr0);
  }

  SECTION("test88") {
    std::vector<Result> arr0(3);

    std::string src1("", 0);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("aaaa bbbb  cccc ", 16);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test89") {
    std::vector<Result> arr0(3);

    std::string src1("  aaaa ", 7);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("bb  cccc ", 9);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test90") {
    std::vector<Result> arr0(3);

    std::string src1("  aaaa ", 7);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("  cccc ", 7);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test91") {
    std::vector<Result> arr0(2);

    std::string src1("  aaaa", 6);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc ", 5);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    Result var0(arr0);
  }

  SECTION("test92") {
    std::vector<Result> arr0(3);

    std::string src1("  aaaa ", 7);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("", 0);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("  cccc b d bb e bbbb f", 22);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test93") {
    std::vector<Result> arr0(2);

    std::string src1("  aaaa", 6);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc b d bb e bbbb f", 20);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    Result var0(arr0);
  }

  SECTION("test94") {
    std::vector<Result> arr0(3);

    std::string src1("  aaaa", 6);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("cccc b d bb e", 13);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("f", 1);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test95") {
    std::string src0("ABC-DEF-GHJ", 11);
    Result var0(src0);
  }

  SECTION("test96") {
    std::string src0("abc-def-ghj", 11);
    Result var0(src0);
  }

  SECTION("test97") {
    std::vector<Result> arr0(4);

    std::string src1("f", 1);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("\xe9", 4);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("o", 1);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4("o", 1);
    Result var4(src4);

    arr0.insert(arr0.end(), var4);

    Result var0(arr0);
  }

  SECTION("test98") {
    std::vector<Result> arr0(4);

    std::string src1("f", 1);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("e\u0301", 7);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("o", 1);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4("o", 1);
    Result var4(src4);

    arr0.insert(arr0.end(), var4);

    Result var0(arr0);
  }

  SECTION("test99") {
    std::vector<Result> arr0(7);

    std::string src1("foo", 3);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("bar", 3);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("baz", 3);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4("quux", 4);
    Result var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5("fred", 4);
    Result var5(src5);

    arr0.insert(arr0.end(), var5);

    std::string src6("barney", 6);
    Result var6(src6);

    arr0.insert(arr0.end(), var6);

    std::string src7("wilma", 5);
    Result var7(src7);

    arr0.insert(arr0.end(), var7);

    Result var0(arr0);
  }

  SECTION("test100") {
    std::vector<Result> arr0(7);

    std::string src1("foo", 3);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("bar", 3);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("baz\u2060quux", 13);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4("fred", 4);
    Result var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5("barney", 6);
    Result var5(src5);

    arr0.insert(arr0.end(), var5);

    std::string src6("wilma", 5);
    Result var6(src6);

    arr0.insert(arr0.end(), var6);

    std::string src7("betty\u200b", 11);
    Result var7(src7);

    arr0.insert(arr0.end(), var7);

    Result var0(arr0);
  }
}
