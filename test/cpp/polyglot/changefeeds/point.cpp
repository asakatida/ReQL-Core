// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./ReQL.hpp"

using namespace ReQL;

TEST_CASE("cpp Test point changebasics", "[cpp][ast]") {

  SECTION("test0") {
    Types::object map0;

    std::string src1("result", 6);
    Query var1(src1);

    std::string src2("blank", 5);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test1") {
    Types::array arr0(1);

    Types::object map1;

    std::string src2("new_val", 7);
    Query var2(src2);

    Query var3;

    map1.insert({src2, var3});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test2") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("partial", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test3") {
    Types::array arr0(1);

    Types::object map1;

    std::string src2("new_val", 7);
    Query var2(src2);

    Types::object map3;

    std::string src4("id", 2);
    Query var4(src4);

    double num5(1);
    Query var5(num5);

    map3.insert({src4, var5});

    Query var3(map3);

    map1.insert({src2, var3});

    std::string src6("old_val", 7);
    Query var6(src6);

    Query var7;

    map1.insert({src6, var7});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test4") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("partial", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test5") {
    Types::array arr0(1);

    Types::object map1;

    std::string src2("new_val", 7);
    Query var2(src2);

    Types::object map3;

    std::string src4("id", 2);
    Query var4(src4);

    double num5(1);
    Query var5(num5);

    map3.insert({src4, var5});

    std::string src6("update", 6);
    Query var6(src6);

    double num7(1);
    Query var7(num7);

    map3.insert({src6, var7});

    Query var3(map3);

    map1.insert({src2, var3});

    std::string src8("old_val", 7);
    Query var8(src8);

    Types::object map9;

    std::string src10("id", 2);
    Query var10(src10);

    double num11(1);
    Query var11(num11);

    map9.insert({src10, var11});

    Query var9(map9);

    map1.insert({src8, var9});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test6") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("partial", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test7") {
    Types::array arr0(1);

    Types::object map1;

    std::string src2("new_val", 7);
    Query var2(src2);

    Query var3;

    map1.insert({src2, var3});

    std::string src4("old_val", 7);
    Query var4(src4);

    Types::object map5;

    std::string src6("id", 2);
    Query var6(src6);

    double num7(1);
    Query var7(num7);

    map5.insert({src6, var7});

    std::string src8("update", 6);
    Query var8(src8);

    double num9(1);
    Query var9(num9);

    map5.insert({src8, var9});

    Query var5(map5);

    map1.insert({src4, var5});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test8") {
    Types::object map0;

    std::string src1("result", 6);
    Query var1(src1);

    std::string src2("blank", 5);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test9") {
    Types::object map0;

    std::string src1("result", 6);
    Query var1(src1);

    std::string src2("blank", 5);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test10") {
    Types::object map0;

    std::string src1("result", 6);
    Query var1(src1);

    std::string src2("blank", 5);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test11") {
    Types::object map0;

    std::string src1("result", 6);
    Query var1(src1);

    std::string src2("blank", 5);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test12") {
    Types::object map0;

    std::string src1("result", 6);
    Query var1(src1);

    std::string src2("blank", 5);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test13") {
    Types::object map0;

    std::string src1("result", 6);
    Query var1(src1);

    std::string src2("blank", 5);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test14") {
    Types::array arr0(2);

    double num1(4);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(7);
    Query var2(num2);

    arr0.insert(arr0.end(), var2);

    Query var0(arr0);
  }

  SECTION("test15") {
    Types::object map0;

    std::string src1("result", 6);
    Query var1(src1);

    std::string src2("blank", 5);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test16") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("partial", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test17") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("partial", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test18") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("partial", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test19") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("partial", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test20") {
    Types::array arr0(4);

    Types::object map1;

    std::string src2("red", 3);
    Query var2(src2);

    double num3(1);
    Query var3(num3);

    map1.insert({src2, var3});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map4;

    std::string src5("blue", 4);
    Query var5(src5);

    double num6(2);
    Query var6(num6);

    map4.insert({src5, var6});

    std::string src7("red", 3);
    Query var7(src7);

    double num8(1);
    Query var8(num8);

    map4.insert({src7, var8});

    Query var4(map4);

    arr0.insert(arr0.end(), var4);

    Types::object map9;

    std::string src10("blue", 4);
    Query var10(src10);

    double num11(2);
    Query var11(num11);

    map9.insert({src10, var11});

    std::string src12("red", 3);
    Query var12(src12);

    double num13(1);
    Query var13(num13);

    map9.insert({src12, var13});

    Query var9(map9);

    arr0.insert(arr0.end(), var9);

    Types::object map14;

    std::string src15("blue", 4);
    Query var15(src15);

    double num16(4);
    Query var16(num16);

    map14.insert({src15, var16});

    std::string src17("red", 3);
    Query var17(src17);

    double num18(1);
    Query var18(num18);

    map14.insert({src17, var18});

    Query var14(map14);

    arr0.insert(arr0.end(), var14);

    Query var0(arr0);
  }

  SECTION("test22") {
    Types::object map0;

    std::string src1("result", 6);
    Query var1(src1);

    std::string src2("blank", 5);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test23") {
    Types::array arr0(1);

    Types::object map1;

    std::string src2("new_val", 7);
    Query var2(src2);

    Query var3;

    map1.insert({src2, var3});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test24") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("partial", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test25") {
    Types::array arr0(1);

    Types::object map1;

    std::string src2("new_val", 7);
    Query var2(src2);

    Types::object map3;

    std::string src4("id", 2);
    Query var4(src4);

    double num5(1);
    Query var5(num5);

    map3.insert({src4, var5});

    Query var3(map3);

    map1.insert({src2, var3});

    std::string src6("old_val", 7);
    Query var6(src6);

    Query var7;

    map1.insert({src6, var7});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test26") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("partial", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test27") {
    Types::array arr0(1);

    Types::object map1;

    std::string src2("new_val", 7);
    Query var2(src2);

    Types::object map3;

    std::string src4("id", 2);
    Query var4(src4);

    double num5(1);
    Query var5(num5);

    map3.insert({src4, var5});

    std::string src6("update", 6);
    Query var6(src6);

    double num7(1);
    Query var7(num7);

    map3.insert({src6, var7});

    Query var3(map3);

    map1.insert({src2, var3});

    std::string src8("old_val", 7);
    Query var8(src8);

    Types::object map9;

    std::string src10("id", 2);
    Query var10(src10);

    double num11(1);
    Query var11(num11);

    map9.insert({src10, var11});

    Query var9(map9);

    map1.insert({src8, var9});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test28") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("partial", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test29") {
    Types::array arr0(1);

    Types::object map1;

    std::string src2("new_val", 7);
    Query var2(src2);

    Query var3;

    map1.insert({src2, var3});

    std::string src4("old_val", 7);
    Query var4(src4);

    Types::object map5;

    std::string src6("id", 2);
    Query var6(src6);

    double num7(1);
    Query var7(num7);

    map5.insert({src6, var7});

    std::string src8("update", 6);
    Query var8(src8);

    double num9(1);
    Query var9(num9);

    map5.insert({src8, var9});

    Query var5(map5);

    map1.insert({src4, var5});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test30") {
    Types::object map0;

    std::string src1("deleted", 7);
    Query var1(src1);

    double num2(0);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("errors", 6);
    Query var3(src3);

    double num4(0);
    Query var4(num4);

    map0.insert({src3, var4});

    std::string src5("inserted", 8);
    Query var5(src5);

    double num6(1);
    Query var6(num6);

    map0.insert({src5, var6});

    std::string src7("replaced", 8);
    Query var7(src7);

    double num8(0);
    Query var8(num8);

    map0.insert({src7, var8});

    std::string src9("skipped", 7);
    Query var9(src9);

    double num10(0);
    Query var10(num10);

    map0.insert({src9, var10});

    std::string src11("unchanged", 9);
    Query var11(src11);

    double num12(0);
    Query var12(num12);

    map0.insert({src11, var12});

    Query var0(map0);
  }

  SECTION("test31") {
    Types::object map0;

    std::string src1("result", 6);
    Query var1(src1);

    std::string src2("blank", 5);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test32") {
    Types::array arr0(1);

    Types::object map1;

    std::string src2("red", 3);
    Query var2(src2);

    double num3(1);
    Query var3(num3);

    map1.insert({src2, var3});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test33") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("partial", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test34") {
    Types::array arr0(1);

    Types::object map1;

    std::string src2("blue", 4);
    Query var2(src2);

    double num3(2);
    Query var3(num3);

    map1.insert({src2, var3});

    std::string src4("red", 3);
    Query var4(src4);

    double num5(1);
    Query var5(num5);

    map1.insert({src4, var5});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test35") {
    Types::object map0;

    std::string src1("result", 6);
    Query var1(src1);

    std::string src2("blank", 5);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test36") {
    Types::object map0;

    std::string src1("result", 6);
    Query var1(src1);

    std::string src2("blank", 5);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test37") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("partial", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test38") {
    Types::object map0;

    std::string src1("result", 6);
    Query var1(src1);

    std::string src2("blank", 5);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test39") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("partial", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }
}
