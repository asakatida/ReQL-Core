// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("cpp 831 -- Empty batched_replaces_t constructed", "[cpp][ast]") {

  SECTION("test0") {
    std::map<std::string, Result> map0;

    std::string src1("deleted", 7);
    Result var1(src1);

    double num2(0);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("errors", 6);
    Result var3(src3);

    double num4(2);
    Result var4(num4);

    map0.insert({src3, var4});

    std::string src5("first_error", 11);
    Result var5(src5);

    std::string src6("Expected type OBJECT but found BOOL.", 36);
    Result var6(src6);

    map0.insert({src5, var6});

    std::string src7("inserted", 8);
    Result var7(src7);

    double num8(0);
    Result var8(num8);

    map0.insert({src7, var8});

    std::string src9("replaced", 8);
    Result var9(src9);

    double num10(0);
    Result var10(num10);

    map0.insert({src9, var10});

    std::string src11("skipped", 7);
    Result var11(src11);

    double num12(0);
    Result var12(num12);

    map0.insert({src11, var12});

    std::string src13("unchanged", 9);
    Result var13(src13);

    double num14(0);
    Result var14(num14);

    map0.insert({src13, var14});

    Result var0(map0);
  }
}