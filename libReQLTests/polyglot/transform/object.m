// Copyright 2015 Adam Grandquist

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#import <libReQL.h>

@interface ObjcTestsManipulationOperationsOnObjects : XCTestCase

@end

@implementation ObjcTestsManipulationOperationsOnObjects


- (void)test1 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @1;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test2 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSString *var0 = @"str";
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test3 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = [NSNumber numberWithBool:YES];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test4 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = [NSNumber numberWithBool:YES];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test5 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = [NSNumber numberWithBool:NO];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test6 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = [NSNumber numberWithBool:YES];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test7 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = [NSNumber numberWithBool:NO];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test8 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = [NSNumber numberWithBool:NO];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test9 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = [NSNumber numberWithBool:YES];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test10 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = [NSNumber numberWithBool:NO];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test11 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = [NSNumber numberWithBool:NO];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test12 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = [NSNumber numberWithBool:YES];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test13 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @2;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test14 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @1;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test15 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @2;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test16 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"a";
  NSNumber *var2 = @1;
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test17 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var1 = @"a";
  NSNumber *var2 = @1;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"b";
  NSNumber *var4 = @2;
  [var0 setObject:var4 forKey:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test18 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:4];
  NSString *var1 = @"b";
  NSNumber *var2 = @2;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"c";
  NSString *var4 = @"str";
  [var0 setObject:var4 forKey:var3];
  NSString *var5 = @"d";
  NSNull *var6 = [NSNull null];
  [var0 setObject:var6 forKey:var5];
  NSString *var7 = @"e";
  NSMutableDictionary *var8 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var9 = @"f";
  NSString *var10 = @"buzz";
  [var8 setObject:var10 forKey:var9];
  [var0 setObject:var8 forKey:var7];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test19 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:3];
  NSString *var1 = @"c";
  NSString *var2 = @"str";
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"d";
  NSNull *var4 = [NSNull null];
  [var0 setObject:var4 forKey:var3];
  NSString *var5 = @"e";
  NSMutableDictionary *var6 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var7 = @"f";
  NSString *var8 = @"buzz";
  [var6 setObject:var8 forKey:var7];
  [var0 setObject:var6 forKey:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test20 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"e";
  NSMutableDictionary *var2 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var3 = @"f";
  NSString *var4 = @"buzz";
  [var2 setObject:var4 forKey:var3];
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test21 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:5];
  NSString *var1 = @"a";
  NSNumber *var2 = @1;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"b";
  NSNumber *var4 = @2;
  [var0 setObject:var4 forKey:var3];
  NSString *var5 = @"c";
  NSString *var6 = @"str";
  [var0 setObject:var6 forKey:var5];
  NSString *var7 = @"d";
  NSNull *var8 = [NSNull null];
  [var0 setObject:var8 forKey:var7];
  NSString *var9 = @"e";
  NSDictionary *var10 = [NSDictionary dictionary];
  [var0 setObject:var10 forKey:var9];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test22 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:5];
  NSString *var1 = @"a";
  NSNumber *var2 = @1;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"b";
  NSNumber *var4 = @2;
  [var0 setObject:var4 forKey:var3];
  NSString *var5 = @"c";
  NSString *var6 = @"str";
  [var0 setObject:var6 forKey:var5];
  NSString *var7 = @"d";
  NSNull *var8 = [NSNull null];
  [var0 setObject:var8 forKey:var7];
  NSString *var9 = @"e";
  NSMutableDictionary *var10 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var11 = @"f";
  NSString *var12 = @"buzz";
  [var10 setObject:var12 forKey:var11];
  [var0 setObject:var10 forKey:var9];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test23 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @1;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test24 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:5];
  NSString *var1 = @"a";
  NSNumber *var2 = @1;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"b";
  NSNumber *var4 = @2;
  [var0 setObject:var4 forKey:var3];
  NSString *var5 = @"c";
  NSString *var6 = @"str";
  [var0 setObject:var6 forKey:var5];
  NSString *var7 = @"d";
  NSNull *var8 = [NSNull null];
  [var0 setObject:var8 forKey:var7];
  NSString *var9 = @"e";
  NSNumber *var10 = @-2;
  [var0 setObject:var10 forKey:var9];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test25 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:4];
  NSString *var1 = @"a";
  NSNumber *var2 = @1;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"b";
  NSNumber *var4 = @2;
  [var0 setObject:var4 forKey:var3];
  NSString *var5 = @"c";
  NSString *var6 = @"str";
  [var0 setObject:var6 forKey:var5];
  NSString *var7 = @"d";
  NSNull *var8 = [NSNull null];
  [var0 setObject:var8 forKey:var7];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test26 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:5];
  NSString *var1 = @"a";
  NSNumber *var2 = @1;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"b";
  NSNumber *var4 = @2;
  [var0 setObject:var4 forKey:var3];
  NSString *var5 = @"c";
  NSString *var6 = @"str";
  [var0 setObject:var6 forKey:var5];
  NSString *var7 = @"d";
  NSNull *var8 = [NSNull null];
  [var0 setObject:var8 forKey:var7];
  NSString *var9 = @"e";
  NSMutableDictionary *var10 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var11 = @"f";
  NSString *var12 = @"quux";
  [var10 setObject:var12 forKey:var11];
  [var0 setObject:var10 forKey:var9];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test27 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:5];
  NSString *var1 = @"a";
  NSNumber *var2 = @1;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"b";
  NSNumber *var4 = @2;
  [var0 setObject:var4 forKey:var3];
  NSString *var5 = @"c";
  NSString *var6 = @"str";
  [var0 setObject:var6 forKey:var5];
  NSString *var7 = @"d";
  NSNull *var8 = [NSNull null];
  [var0 setObject:var8 forKey:var7];
  NSString *var9 = @"e";
  NSMutableDictionary *var10 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var11 = @"f";
  NSString *var12 = @"buzz";
  [var10 setObject:var12 forKey:var11];
  NSString *var13 = @"g";
  NSString *var14 = @"quux";
  [var10 setObject:var14 forKey:var13];
  [var0 setObject:var10 forKey:var9];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test28 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:5];
  NSString *var1 = @"a";
  NSNumber *var2 = @1;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"b";
  NSNumber *var4 = @2;
  [var0 setObject:var4 forKey:var3];
  NSString *var5 = @"c";
  NSString *var6 = @"str";
  [var0 setObject:var6 forKey:var5];
  NSString *var7 = @"d";
  NSNull *var8 = [NSNull null];
  [var0 setObject:var8 forKey:var7];
  NSString *var9 = @"e";
  NSMutableDictionary *var10 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var11 = @"g";
  NSString *var12 = @"quux";
  [var10 setObject:var12 forKey:var11];
  [var0 setObject:var10 forKey:var9];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test29 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:5];
  NSString *var1 = @"a";
  NSNumber *var2 = @-1;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"b";
  NSNumber *var4 = @2;
  [var0 setObject:var4 forKey:var3];
  NSString *var5 = @"c";
  NSString *var6 = @"str";
  [var0 setObject:var6 forKey:var5];
  NSString *var7 = @"d";
  NSNull *var8 = [NSNull null];
  [var0 setObject:var8 forKey:var7];
  NSString *var9 = @"e";
  NSMutableDictionary *var10 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var11 = @"f";
  NSString *var12 = @"buzz";
  [var10 setObject:var12 forKey:var11];
  [var0 setObject:var10 forKey:var9];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test31 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test32 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test33 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test35 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:4];
  NSString *var1 = @"a";
  NSMutableDictionary *var2 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var3 = @"b";
  NSNumber *var4 = @1;
  [var2 setObject:var4 forKey:var3];
  NSString *var5 = @"c";
  NSNumber *var6 = @2;
  [var2 setObject:var6 forKey:var5];
  [var0 setObject:var2 forKey:var1];
  NSString *var7 = @"d";
  NSNumber *var8 = @3;
  [var0 setObject:var8 forKey:var7];
  NSString *var9 = @"e";
  NSNumber *var10 = @4;
  [var0 setObject:var10 forKey:var9];
  NSString *var11 = @"f";
  NSNumber *var12 = @5;
  [var0 setObject:var12 forKey:var11];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test36 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:3];
  NSString *var2 = @"a";
  NSMutableDictionary *var3 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var4 = @"b";
  NSNumber *var5 = @1;
  [var3 setObject:var5 forKey:var4];
  NSString *var6 = @"c";
  NSNumber *var7 = @2;
  [var3 setObject:var7 forKey:var6];
  [var1 setObject:var3 forKey:var2];
  NSString *var8 = @"d";
  NSNumber *var9 = @3;
  [var1 setObject:var9 forKey:var8];
  NSString *var10 = @"e";
  NSNumber *var11 = @3;
  [var1 setObject:var11 forKey:var10];
  [var0 addObject:var1];
  NSMutableDictionary *var12 = [NSMutableDictionary dictionaryWithCapacity:3];
  NSString *var13 = @"a";
  NSMutableDictionary *var14 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var15 = @"b";
  NSNumber *var16 = @1;
  [var14 setObject:var16 forKey:var15];
  NSString *var17 = @"c";
  NSNumber *var18 = @2;
  [var14 setObject:var18 forKey:var17];
  [var12 setObject:var14 forKey:var13];
  NSString *var19 = @"d";
  NSNumber *var20 = @4;
  [var12 setObject:var20 forKey:var19];
  NSString *var21 = @"e";
  NSNumber *var22 = @4;
  [var12 setObject:var22 forKey:var21];
  [var0 addObject:var12];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test37 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:3];
  NSString *var2 = @"a";
  NSMutableDictionary *var3 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var4 = @"b";
  NSNumber *var5 = @1;
  [var3 setObject:var5 forKey:var4];
  NSString *var6 = @"c";
  NSNumber *var7 = @2;
  [var3 setObject:var7 forKey:var6];
  [var1 setObject:var3 forKey:var2];
  NSString *var8 = @"d";
  NSNumber *var9 = @3;
  [var1 setObject:var9 forKey:var8];
  NSString *var10 = @"e";
  NSNumber *var11 = @3;
  [var1 setObject:var11 forKey:var10];
  [var0 addObject:var1];
  NSMutableDictionary *var12 = [NSMutableDictionary dictionaryWithCapacity:3];
  NSString *var13 = @"a";
  NSMutableDictionary *var14 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var15 = @"b";
  NSNumber *var16 = @1;
  [var14 setObject:var16 forKey:var15];
  NSString *var17 = @"c";
  NSNumber *var18 = @2;
  [var14 setObject:var18 forKey:var17];
  [var12 setObject:var14 forKey:var13];
  NSString *var19 = @"d";
  NSNumber *var20 = @4;
  [var12 setObject:var20 forKey:var19];
  NSString *var21 = @"e";
  NSNumber *var22 = @4;
  [var12 setObject:var22 forKey:var21];
  [var0 addObject:var12];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test38 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var2 = @"a";
  NSMutableDictionary *var3 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var4 = @"b";
  NSNumber *var5 = @2;
  [var3 setObject:var5 forKey:var4];
  NSString *var6 = @"c";
  NSNumber *var7 = @2;
  [var3 setObject:var7 forKey:var6];
  [var1 setObject:var3 forKey:var2];
  NSString *var8 = @"d";
  NSNumber *var9 = @3;
  [var1 setObject:var9 forKey:var8];
  [var0 addObject:var1];
  NSMutableDictionary *var10 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var11 = @"a";
  NSMutableDictionary *var12 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var13 = @"b";
  NSNumber *var14 = @2;
  [var12 setObject:var14 forKey:var13];
  NSString *var15 = @"c";
  NSNumber *var16 = @2;
  [var12 setObject:var16 forKey:var15];
  [var10 setObject:var12 forKey:var11];
  NSString *var17 = @"d";
  NSNumber *var18 = @4;
  [var10 setObject:var18 forKey:var17];
  [var0 addObject:var10];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test39 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var2 = @"a";
  NSMutableDictionary *var3 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var4 = @"b";
  NSNumber *var5 = @2;
  [var3 setObject:var5 forKey:var4];
  [var1 setObject:var3 forKey:var2];
  NSString *var6 = @"d";
  NSNumber *var7 = @3;
  [var1 setObject:var7 forKey:var6];
  [var0 addObject:var1];
  NSMutableDictionary *var8 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var9 = @"a";
  NSMutableDictionary *var10 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var11 = @"b";
  NSNumber *var12 = @2;
  [var10 setObject:var12 forKey:var11];
  [var8 setObject:var10 forKey:var9];
  NSString *var13 = @"d";
  NSNumber *var14 = @4;
  [var8 setObject:var14 forKey:var13];
  [var0 addObject:var8];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test40 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSString *var1 = @"a";
  [var0 addObject:var1];
  NSString *var2 = @"b";
  [var0 addObject:var2];
  NSString *var3 = @"c";
  [var0 addObject:var3];
  NSString *var4 = @"d";
  [var0 addObject:var4];
  NSString *var5 = @"e";
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

@end
