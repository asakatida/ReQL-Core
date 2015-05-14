// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("cpp Test point changebasics", "[cpp][ast]") {

  SECTION("test0") {
    Result var0;
  }

  SECTION("test1") {
    std::vector<Result> arr0(1);

    std::map<std::string, Result> map1;

    std::string src2("new_val", 7);
    Result var2(src2);

    Result var3;

    map1.insert({src2, var3});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test2") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("partial", 7);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test3") {
    std::vector<Result> arr0(1);

    std::map<std::string, Result> map1;

    std::string src2("new_val", 7);
    Result var2(src2);

    std::map<std::string, Result> map3;

    std::string src4("id", 2);
    Result var4(src4);

    double num5(1);
    Result var5(num5);

    map3.insert({src4, var5});

    Result var3(map3);

    map1.insert({src2, var3});

    std::string src6("old_val", 7);
    Result var6(src6);

    Result var7;

    map1.insert({src6, var7});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test4") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("partial", 7);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test5") {
    std::vector<Result> arr0(1);

    std::map<std::string, Result> map1;

    std::string src2("new_val", 7);
    Result var2(src2);

    std::map<std::string, Result> map3;

    std::string src4("id", 2);
    Result var4(src4);

    double num5(1);
    Result var5(num5);

    map3.insert({src4, var5});

    std::string src6("update", 6);
    Result var6(src6);

    double num7(1);
    Result var7(num7);

    map3.insert({src6, var7});

    Result var3(map3);

    map1.insert({src2, var3});

    std::string src8("old_val", 7);
    Result var8(src8);

    std::map<std::string, Result> map9;

    std::string src10("id", 2);
    Result var10(src10);

    double num11(1);
    Result var11(num11);

    map9.insert({src10, var11});

    Result var9(map9);

    map1.insert({src8, var9});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test6") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("partial", 7);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test7") {
    std::vector<Result> arr0(1);

    std::map<std::string, Result> map1;

    std::string src2("new_val", 7);
    Result var2(src2);

    Result var3;

    map1.insert({src2, var3});

    std::string src4("old_val", 7);
    Result var4(src4);

    std::map<std::string, Result> map5;

    std::string src6("id", 2);
    Result var6(src6);

    double num7(1);
    Result var7(num7);

    map5.insert({src6, var7});

    std::string src8("update", 6);
    Result var8(src8);

    double num9(1);
    Result var9(num9);

    map5.insert({src8, var9});

    Result var5(map5);

    map1.insert({src4, var5});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test8") {
    Result var0;
  }

  SECTION("test9") {
    Result var0;
  }

  SECTION("test10") {
    Result var0;
  }

  SECTION("test11") {
    Result var0;
  }

  SECTION("test12") {
    Result var0;
  }

  SECTION("test13") {
    Result var0;
  }

  SECTION("test14") {
    std::vector<Result> arr0(2);

    double num1(4);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(7);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    Result var0(arr0);
  }

  SECTION("test15") {
    Result var0;
  }

  SECTION("test16") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("partial", 7);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test17") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("partial", 7);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test18") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("partial", 7);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test19") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("partial", 7);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test20") {
    std::vector<Result> arr0(4);

    std::map<std::string, Result> map1;

    std::string src2("red", 3);
    Result var2(src2);

    double num3(1);
    Result var3(num3);

    map1.insert({src2, var3});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map4;

    std::string src5("red", 3);
    Result var5(src5);

    double num6(1);
    Result var6(num6);

    map4.insert({src5, var6});

    std::string src7("blue", 4);
    Result var7(src7);

    double num8(2);
    Result var8(num8);

    map4.insert({src7, var8});

    Result var4(map4);

    arr0.insert(arr0.end(), var4);

    std::map<std::string, Result> map9;

    std::string src10("red", 3);
    Result var10(src10);

    double num11(1);
    Result var11(num11);

    map9.insert({src10, var11});

    std::string src12("blue", 4);
    Result var12(src12);

    double num13(2);
    Result var13(num13);

    map9.insert({src12, var13});

    Result var9(map9);

    arr0.insert(arr0.end(), var9);

    std::map<std::string, Result> map14;

    std::string src15("red", 3);
    Result var15(src15);

    double num16(1);
    Result var16(num16);

    map14.insert({src15, var16});

    std::string src17("blue", 4);
    Result var17(src17);

    double num18(4);
    Result var18(num18);

    map14.insert({src17, var18});

    Result var14(map14);

    arr0.insert(arr0.end(), var14);

    Result var0(arr0);
  }

  SECTION("test22") {
    Result var0;
  }

  SECTION("test23") {
    std::vector<Result> arr0(1);

    std::map<std::string, Result> map1;

    std::string src2("new_val", 7);
    Result var2(src2);

    Result var3;

    map1.insert({src2, var3});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test24") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("partial", 7);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test25") {
    std::vector<Result> arr0(1);

    std::map<std::string, Result> map1;

    std::string src2("new_val", 7);
    Result var2(src2);

    std::map<std::string, Result> map3;

    std::string src4("id", 2);
    Result var4(src4);

    double num5(1);
    Result var5(num5);

    map3.insert({src4, var5});

    Result var3(map3);

    map1.insert({src2, var3});

    std::string src6("old_val", 7);
    Result var6(src6);

    Result var7;

    map1.insert({src6, var7});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test26") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("partial", 7);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test27") {
    std::vector<Result> arr0(1);

    std::map<std::string, Result> map1;

    std::string src2("new_val", 7);
    Result var2(src2);

    std::map<std::string, Result> map3;

    std::string src4("id", 2);
    Result var4(src4);

    double num5(1);
    Result var5(num5);

    map3.insert({src4, var5});

    std::string src6("update", 6);
    Result var6(src6);

    double num7(1);
    Result var7(num7);

    map3.insert({src6, var7});

    Result var3(map3);

    map1.insert({src2, var3});

    std::string src8("old_val", 7);
    Result var8(src8);

    std::map<std::string, Result> map9;

    std::string src10("id", 2);
    Result var10(src10);

    double num11(1);
    Result var11(num11);

    map9.insert({src10, var11});

    Result var9(map9);

    map1.insert({src8, var9});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test28") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("partial", 7);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test29") {
    std::vector<Result> arr0(1);

    std::map<std::string, Result> map1;

    std::string src2("new_val", 7);
    Result var2(src2);

    Result var3;

    map1.insert({src2, var3});

    std::string src4("old_val", 7);
    Result var4(src4);

    std::map<std::string, Result> map5;

    std::string src6("id", 2);
    Result var6(src6);

    double num7(1);
    Result var7(num7);

    map5.insert({src6, var7});

    std::string src8("update", 6);
    Result var8(src8);

    double num9(1);
    Result var9(num9);

    map5.insert({src8, var9});

    Result var5(map5);

    map1.insert({src4, var5});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test30") {
    Result var0;
  }

  SECTION("test31") {
    Result var0;
  }

  SECTION("test32") {
    std::vector<Result> arr0(1);

    std::map<std::string, Result> map1;

    std::string src2("red", 3);
    Result var2(src2);

    double num3(1);
    Result var3(num3);

    map1.insert({src2, var3});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test33") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("partial", 7);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test34") {
    std::vector<Result> arr0(1);

    std::map<std::string, Result> map1;

    std::string src2("red", 3);
    Result var2(src2);

    double num3(1);
    Result var3(num3);

    map1.insert({src2, var3});

    std::string src4("blue", 4);
    Result var4(src4);

    double num5(2);
    Result var5(num5);

    map1.insert({src4, var5});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test35") {
    Result var0;
  }

  SECTION("test36") {
    Result var0;
  }

  SECTION("test37") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("partial", 7);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test38") {
    Result var0;
  }

  SECTION("test39") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("partial", 7);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }
}
