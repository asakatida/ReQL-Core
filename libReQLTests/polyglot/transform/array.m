// Copyright 2015 Adam Grandquist

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#import <libReQL.h>

@interface ObjcTestsManipulationOperationsOnArrays : XCTestCase

@end

@implementation ObjcTestsManipulationOperationsOnArrays


- (void)test4 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:4];
  NSNumber *var1 = @1;
  [var0 addObject:var1];
  NSNumber *var2 = @2;
  [var0 addObject:var2];
  NSNumber *var3 = @3;
  [var0 addObject:var3];
  NSNumber *var4 = @4;
  [var0 addObject:var4];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test5 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:4];
  NSNumber *var1 = @1;
  [var0 addObject:var1];
  NSNumber *var2 = @2;
  [var0 addObject:var2];
  NSNumber *var3 = @3;
  [var0 addObject:var3];
  NSString *var4 = @"a";
  [var0 addObject:var4];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test6 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:4];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test7 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:4];
  NSString *var1 = @"a";
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test8 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:1];
  NSNumber *var1 = @3;
  [var0 addObject:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test9 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSNumber *var1 = @1;
  [var0 addObject:var1];
  NSNumber *var2 = @2;
  [var0 addObject:var2];
  NSNumber *var3 = @3;
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test10 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSNumber *var1 = @1;
  [var0 addObject:var1];
  NSNumber *var2 = @2;
  [var0 addObject:var2];
  NSNumber *var3 = @3;
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test11 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSNumber *var1 = @1;
  [var0 addObject:var1];
  NSNumber *var2 = @2;
  [var0 addObject:var2];
  NSNumber *var3 = @3;
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test12 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:4];
  NSNumber *var1 = @1;
  [var0 addObject:var1];
  NSNumber *var2 = @2;
  [var0 addObject:var2];
  NSNumber *var3 = @3;
  [var0 addObject:var3];
  NSNumber *var4 = @4;
  [var0 addObject:var4];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test13 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @1;
  [var0 addObject:var1];
  NSNumber *var2 = @2;
  [var0 addObject:var2];
  NSNumber *var3 = @3;
  [var0 addObject:var3];
  NSNumber *var4 = @4;
  [var0 addObject:var4];
  NSNumber *var5 = @5;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test14 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @1;
  [var0 addObject:var1];
  NSNumber *var2 = @2;
  [var0 addObject:var2];
  NSNumber *var3 = @3;
  [var0 addObject:var3];
  NSNumber *var4 = @5;
  [var0 addObject:var4];
  NSNumber *var5 = @6;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test15 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var1 = @1;
  [var0 addObject:var1];
  NSNumber *var2 = @2;
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test16 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test17 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var1 = @2;
  [var0 addObject:var1];
  NSNumber *var2 = @3;
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test18 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var1 = @1;
  [var0 addObject:var1];
  NSNumber *var2 = @3;
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test19 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var1 = @2;
  [var0 addObject:var1];
  NSNumber *var2 = @3;
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test20 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var1 = @1;
  [var0 addObject:var1];
  NSNumber *var2 = @2;
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test21 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var1 = @2;
  [var0 addObject:var1];
  NSNumber *var2 = @3;
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test22 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:1];
  NSNumber *var1 = @2;
  [var0 addObject:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test23 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var1 = @2;
  [var0 addObject:var1];
  NSNumber *var2 = @3;
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test24 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:1];
  NSNumber *var1 = @3;
  [var0 addObject:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test25 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test26 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var1 = @1;
  [var0 addObject:var1];
  NSNumber *var2 = @2;
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test27 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test28 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSNumber *var1 = @1;
  [var0 addObject:var1];
  NSNumber *var2 = @2;
  [var0 addObject:var2];
  NSNumber *var3 = @3;
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test29 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var2 = @"a";
  NSNumber *var3 = @1;
  [var1 setObject:var3 forKey:var2];
  NSString *var4 = @"b";
  NSString *var5 = @"a";
  [var1 setObject:var5 forKey:var4];
  [var0 addObject:var1];
  NSMutableDictionary *var6 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var7 = @"a";
  NSNumber *var8 = @2;
  [var6 setObject:var8 forKey:var7];
  NSString *var9 = @"b";
  NSString *var10 = @"b";
  [var6 setObject:var10 forKey:var9];
  [var0 addObject:var6];
  NSMutableDictionary *var11 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var12 = @"a";
  NSNumber *var13 = @3;
  [var11 setObject:var13 forKey:var12];
  NSString *var14 = @"b";
  NSString *var15 = @"c";
  [var11 setObject:var15 forKey:var14];
  [var0 addObject:var11];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test30 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var2 = @"a";
  NSNumber *var3 = @1;
  [var1 setObject:var3 forKey:var2];
  [var0 addObject:var1];
  NSMutableDictionary *var4 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var5 = @"a";
  NSNumber *var6 = @2;
  [var4 setObject:var6 forKey:var5];
  [var0 addObject:var4];
  NSMutableDictionary *var7 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var8 = @"a";
  NSNumber *var9 = @3;
  [var7 setObject:var9 forKey:var8];
  [var0 addObject:var7];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test31 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSDictionary *var1 = [NSDictionary dictionary];
  [var0 addObject:var1];
  NSDictionary *var2 = [NSDictionary dictionary];
  [var0 addObject:var2];
  NSDictionary *var3 = [NSDictionary dictionary];
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test33 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:6];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var2 = @"a";
  NSNumber *var3 = @1;
  [var1 setObject:var3 forKey:var2];
  [var0 addObject:var1];
  NSMutableDictionary *var4 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var5 = @"a";
  NSNumber *var6 = @2;
  [var4 setObject:var6 forKey:var5];
  [var0 addObject:var4];
  NSMutableDictionary *var7 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var8 = @"a";
  NSNumber *var9 = @3;
  [var7 setObject:var9 forKey:var8];
  [var0 addObject:var7];
  NSMutableDictionary *var10 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var11 = @"a";
  NSNumber *var12 = @1;
  [var10 setObject:var12 forKey:var11];
  [var0 addObject:var10];
  NSMutableDictionary *var13 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var14 = @"a";
  NSNumber *var15 = @2;
  [var13 setObject:var15 forKey:var14];
  [var0 addObject:var13];
  NSMutableDictionary *var16 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var17 = @"a";
  NSNumber *var18 = @3;
  [var16 setObject:var18 forKey:var17];
  [var0 addObject:var16];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test34 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:6];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var2 = @"b";
  NSString *var3 = @"a";
  [var1 setObject:var3 forKey:var2];
  [var0 addObject:var1];
  NSMutableDictionary *var4 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var5 = @"b";
  NSString *var6 = @"b";
  [var4 setObject:var6 forKey:var5];
  [var0 addObject:var4];
  NSMutableDictionary *var7 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var8 = @"b";
  NSString *var9 = @"c";
  [var7 setObject:var9 forKey:var8];
  [var0 addObject:var7];
  NSMutableDictionary *var10 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var11 = @"b";
  NSString *var12 = @"a";
  [var10 setObject:var12 forKey:var11];
  [var0 addObject:var10];
  NSMutableDictionary *var13 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var14 = @"b";
  NSString *var15 = @"b";
  [var13 setObject:var15 forKey:var14];
  [var0 addObject:var13];
  NSMutableDictionary *var16 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var17 = @"b";
  NSString *var18 = @"c";
  [var16 setObject:var18 forKey:var17];
  [var0 addObject:var16];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test35 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var2 = @"a";
  NSNumber *var3 = @1;
  [var1 setObject:var3 forKey:var2];
  NSString *var4 = @"b";
  NSString *var5 = @"a";
  [var1 setObject:var5 forKey:var4];
  [var0 addObject:var1];
  NSMutableDictionary *var6 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var7 = @"a";
  NSNumber *var8 = @2;
  [var6 setObject:var8 forKey:var7];
  NSString *var9 = @"b";
  NSString *var10 = @"b";
  [var6 setObject:var10 forKey:var9];
  [var0 addObject:var6];
  NSMutableDictionary *var11 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var12 = @"a";
  NSNumber *var13 = @3;
  [var11 setObject:var13 forKey:var12];
  NSString *var14 = @"b";
  NSString *var15 = @"c";
  [var11 setObject:var15 forKey:var14];
  [var0 addObject:var11];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test36 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:10];
  NSDictionary *var1 = [NSDictionary dictionary];
  [var0 addObject:var1];
  NSDictionary *var2 = [NSDictionary dictionary];
  [var0 addObject:var2];
  NSDictionary *var3 = [NSDictionary dictionary];
  [var0 addObject:var3];
  NSDictionary *var4 = [NSDictionary dictionary];
  [var0 addObject:var4];
  NSDictionary *var5 = [NSDictionary dictionary];
  [var0 addObject:var5];
  NSDictionary *var6 = [NSDictionary dictionary];
  [var0 addObject:var6];
  NSDictionary *var7 = [NSDictionary dictionary];
  [var0 addObject:var7];
  NSDictionary *var8 = [NSDictionary dictionary];
  [var0 addObject:var8];
  NSDictionary *var9 = [NSDictionary dictionary];
  [var0 addObject:var9];
  NSDictionary *var10 = [NSDictionary dictionary];
  [var0 addObject:var10];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test38 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:6];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var2 = @"b";
  NSMutableDictionary *var3 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var4 = @"c";
  NSNumber *var5 = @1;
  [var3 setObject:var5 forKey:var4];
  [var1 setObject:var3 forKey:var2];
  [var0 addObject:var1];
  NSMutableDictionary *var6 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var7 = @"b";
  NSMutableDictionary *var8 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var9 = @"c";
  NSNumber *var10 = @2;
  [var8 setObject:var10 forKey:var9];
  [var6 setObject:var8 forKey:var7];
  [var0 addObject:var6];
  NSMutableDictionary *var11 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var12 = @"b";
  NSMutableDictionary *var13 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var14 = @"c";
  NSNumber *var15 = @3;
  [var13 setObject:var15 forKey:var14];
  [var11 setObject:var13 forKey:var12];
  [var0 addObject:var11];
  NSMutableDictionary *var16 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var17 = @"b";
  NSMutableDictionary *var18 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var19 = @"c";
  NSNumber *var20 = @1;
  [var18 setObject:var20 forKey:var19];
  [var16 setObject:var18 forKey:var17];
  [var0 addObject:var16];
  NSMutableDictionary *var21 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var22 = @"b";
  NSMutableDictionary *var23 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var24 = @"c";
  NSNumber *var25 = @2;
  [var23 setObject:var25 forKey:var24];
  [var21 setObject:var23 forKey:var22];
  [var0 addObject:var21];
  NSMutableDictionary *var26 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var27 = @"b";
  NSMutableDictionary *var28 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var29 = @"c";
  NSNumber *var30 = @3;
  [var28 setObject:var30 forKey:var29];
  [var26 setObject:var28 forKey:var27];
  [var0 addObject:var26];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test39 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test40 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test41 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSDictionary *var1 = [NSDictionary dictionary];
  [var0 addObject:var1];
  NSDictionary *var2 = [NSDictionary dictionary];
  [var0 addObject:var2];
  NSDictionary *var3 = [NSDictionary dictionary];
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test42 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var2 = @"b";
  NSString *var3 = @"a";
  [var1 setObject:var3 forKey:var2];
  [var0 addObject:var1];
  NSMutableDictionary *var4 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var5 = @"b";
  NSString *var6 = @"b";
  [var4 setObject:var6 forKey:var5];
  [var0 addObject:var4];
  NSMutableDictionary *var7 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var8 = @"b";
  NSString *var9 = @"c";
  [var7 setObject:var9 forKey:var8];
  [var0 addObject:var7];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test43 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var2 = @"a";
  NSNumber *var3 = @1;
  [var1 setObject:var3 forKey:var2];
  NSString *var4 = @"b";
  NSString *var5 = @"a";
  [var1 setObject:var5 forKey:var4];
  [var0 addObject:var1];
  NSMutableDictionary *var6 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var7 = @"a";
  NSNumber *var8 = @2;
  [var6 setObject:var8 forKey:var7];
  NSString *var9 = @"b";
  NSString *var10 = @"b";
  [var6 setObject:var10 forKey:var9];
  [var0 addObject:var6];
  NSMutableDictionary *var11 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var12 = @"a";
  NSNumber *var13 = @3;
  [var11 setObject:var13 forKey:var12];
  NSString *var14 = @"b";
  NSString *var15 = @"c";
  [var11 setObject:var15 forKey:var14];
  [var0 addObject:var11];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test44 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSNumber *var1 = @2;
  [var0 addObject:var1];
  NSNumber *var2 = @3;
  [var0 addObject:var2];
  NSNumber *var3 = @4;
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test45 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @6;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test46 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @6;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test47 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @12;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test48 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @12;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test49 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:1];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var2 = @"a";
  NSNumber *var3 = @2;
  [var1 setObject:var3 forKey:var2];
  NSString *var4 = @"b";
  NSString *var5 = @"b";
  [var1 setObject:var5 forKey:var4];
  [var0 addObject:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test50 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:6];
  NSNumber *var1 = @1;
  [var0 addObject:var1];
  NSNumber *var2 = @2;
  [var0 addObject:var2];
  NSNumber *var3 = @1;
  [var0 addObject:var3];
  NSNumber *var4 = @2;
  [var0 addObject:var4];
  NSNumber *var5 = @1;
  [var0 addObject:var5];
  NSNumber *var6 = @2;
  [var0 addObject:var6];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test51 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:6];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var2 = @"v";
  NSNumber *var3 = @1;
  [var1 setObject:var3 forKey:var2];
  [var0 addObject:var1];
  NSMutableDictionary *var4 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var5 = @"v2";
  NSNumber *var6 = @2;
  [var4 setObject:var6 forKey:var5];
  [var0 addObject:var4];
  NSMutableDictionary *var7 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var8 = @"v";
  NSNumber *var9 = @2;
  [var7 setObject:var9 forKey:var8];
  [var0 addObject:var7];
  NSMutableDictionary *var10 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var11 = @"v2";
  NSNumber *var12 = @3;
  [var10 setObject:var12 forKey:var11];
  [var0 addObject:var10];
  NSMutableDictionary *var13 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var14 = @"v";
  NSNumber *var15 = @3;
  [var13 setObject:var15 forKey:var14];
  [var0 addObject:var13];
  NSMutableDictionary *var16 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var17 = @"v2";
  NSNumber *var18 = @4;
  [var16 setObject:var18 forKey:var17];
  [var0 addObject:var16];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test52 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var2 = @"a";
  NSNumber *var3 = @1;
  [var1 setObject:var3 forKey:var2];
  NSString *var4 = @"b";
  NSString *var5 = @"a";
  [var1 setObject:var5 forKey:var4];
  [var0 addObject:var1];
  NSMutableDictionary *var6 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var7 = @"a";
  NSNumber *var8 = @2;
  [var6 setObject:var8 forKey:var7];
  NSString *var9 = @"b";
  NSString *var10 = @"b";
  [var6 setObject:var10 forKey:var9];
  [var0 addObject:var6];
  NSMutableDictionary *var11 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var12 = @"a";
  NSNumber *var13 = @3;
  [var11 setObject:var13 forKey:var12];
  NSString *var14 = @"b";
  NSString *var15 = @"c";
  [var11 setObject:var15 forKey:var14];
  [var0 addObject:var11];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test53 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var2 = @"a";
  NSNumber *var3 = @3;
  [var1 setObject:var3 forKey:var2];
  NSString *var4 = @"b";
  NSString *var5 = @"c";
  [var1 setObject:var5 forKey:var4];
  [var0 addObject:var1];
  NSMutableDictionary *var6 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var7 = @"a";
  NSNumber *var8 = @2;
  [var6 setObject:var8 forKey:var7];
  NSString *var9 = @"b";
  NSString *var10 = @"b";
  [var6 setObject:var10 forKey:var9];
  [var0 addObject:var6];
  NSMutableDictionary *var11 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var12 = @"a";
  NSNumber *var13 = @1;
  [var11 setObject:var13 forKey:var12];
  NSString *var14 = @"b";
  NSString *var15 = @"a";
  [var11 setObject:var15 forKey:var14];
  [var0 addObject:var11];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test54 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var2 = @"-a";
  NSNumber *var3 = @1;
  [var1 setObject:var3 forKey:var2];
  [var0 addObject:var1];
  NSMutableDictionary *var4 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var5 = @"-a";
  NSNumber *var6 = @2;
  [var4 setObject:var6 forKey:var5];
  [var0 addObject:var4];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test55 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:4];
  NSNumber *var1 = @1;
  [var0 addObject:var1];
  NSNumber *var2 = @2;
  [var0 addObject:var2];
  NSNumber *var3 = @3;
  [var0 addObject:var3];
  NSNumber *var4 = @4;
  [var0 addObject:var4];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test56 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @3;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test57 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:6];
  NSNumber *var1 = @1;
  [var0 addObject:var1];
  NSNumber *var2 = @2;
  [var0 addObject:var2];
  NSNumber *var3 = @3;
  [var0 addObject:var3];
  NSMutableDictionary *var4 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var5 = @"a";
  NSNumber *var6 = @1;
  [var4 setObject:var6 forKey:var5];
  NSString *var7 = @"b";
  NSString *var8 = @"a";
  [var4 setObject:var8 forKey:var7];
  [var0 addObject:var4];
  NSMutableDictionary *var9 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var10 = @"a";
  NSNumber *var11 = @2;
  [var9 setObject:var11 forKey:var10];
  NSString *var12 = @"b";
  NSString *var13 = @"b";
  [var9 setObject:var13 forKey:var12];
  [var0 addObject:var9];
  NSMutableDictionary *var14 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var15 = @"a";
  NSNumber *var16 = @3;
  [var14 setObject:var16 forKey:var15];
  NSString *var17 = @"b";
  NSString *var18 = @"c";
  [var14 setObject:var18 forKey:var17];
  [var0 addObject:var14];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test58 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @2;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test59 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @1;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test60 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = [NSNumber numberWithBool:YES];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test61 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = [NSNumber numberWithBool:NO];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test62 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = [NSNumber numberWithBool:YES];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test63 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = [NSNumber numberWithBool:YES];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test64 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = [NSNumber numberWithBool:NO];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test65 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = [NSNumber numberWithBool:NO];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test66 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = [NSNumber numberWithBool:NO];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test67 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = [NSNumber numberWithBool:YES];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test68 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = [NSNumber numberWithBool:YES];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test69 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = [NSNumber numberWithBool:YES];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test70 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = [NSNumber numberWithBool:NO];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test71 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = [NSNumber numberWithBool:NO];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test72 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = [NSNumber numberWithBool:NO];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test73 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = [NSNumber numberWithBool:YES];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test74 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var1 = @1;
  [var0 addObject:var1];
  NSNumber *var2 = @3;
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test75 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

@end
