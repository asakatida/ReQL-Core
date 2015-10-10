// Copyright 2015 Adam Grandquist

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#import <libReQL.h>

@interface ObjcTestReqlInterfaceToGeoIndexes : XCTestCase

@end

@implementation ObjcTestReqlInterfaceToGeoIndexes


- (void)test1 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:6];
  NSString *var1 = @"deleted";
  NSNumber *var2 = @0;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"errors";
  NSNumber *var4 = @0;
  [var0 setObject:var4 forKey:var3];
  NSString *var5 = @"inserted";
  NSNumber *var6 = @3;
  [var0 setObject:var6 forKey:var5];
  NSString *var7 = @"replaced";
  NSNumber *var8 = @0;
  [var0 setObject:var8 forKey:var7];
  NSString *var9 = @"skipped";
  NSNumber *var10 = @0;
  [var0 setObject:var10 forKey:var9];
  NSString *var11 = @"unchanged";
  NSNumber *var12 = @0;
  [var0 setObject:var12 forKey:var11];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test2 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"created";
  NSNumber *var2 = @1;
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test3 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"created";
  NSNumber *var2 = @1;
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test4 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"created";
  NSNumber *var2 = @1;
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test5 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"created";
  NSNumber *var2 = @1;
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test6 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"result";
  NSString *var2 = @"blank";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test7 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test8 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err_regex";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test9 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test10 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test11 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test12 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test13 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test14 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test15 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test16 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test17 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @1;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test18 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @1;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test19 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @1;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test20 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @0;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test21 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @2;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test22 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @3;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test23 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSString *var0 = @"SELECTION<STREAM>";
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test24 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSString *var0 = @"SELECTION<STREAM>";
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test25 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSString *var0 = @"STREAM";
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test26 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @1;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test27 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @1;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test28 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @1;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test29 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @0;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test30 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @1;
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
  NSString *var2 = @"err_regex";
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

- (void)test34 {
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
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test36 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test37 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test38 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var2 = @"dist";
  NSNumber *var3 = @0;
  [var1 setObject:var3 forKey:var2];
  NSString *var4 = @"doc";
  NSMutableDictionary *var5 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var6 = @"id";
  NSNumber *var7 = @1;
  [var5 setObject:var7 forKey:var6];
  [var1 setObject:var5 forKey:var4];
  [var0 addObject:var1];
  NSMutableDictionary *var8 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var9 = @"dist";
  NSNumber *var10 = @0.055659745396754216;
  [var8 setObject:var10 forKey:var9];
  NSString *var11 = @"doc";
  NSMutableDictionary *var12 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var13 = @"id";
  NSNumber *var14 = @2;
  [var12 setObject:var14 forKey:var13];
  [var8 setObject:var12 forKey:var11];
  [var0 addObject:var8];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test39 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var2 = @"dist";
  NSNumber *var3 = @0;
  [var1 setObject:var3 forKey:var2];
  NSString *var4 = @"doc";
  NSMutableDictionary *var5 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var6 = @"id";
  NSNumber *var7 = @2;
  [var5 setObject:var7 forKey:var6];
  [var1 setObject:var5 forKey:var4];
  [var0 addObject:var1];
  NSMutableDictionary *var8 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var9 = @"dist";
  NSNumber *var10 = @0.11130264976984369;
  [var8 setObject:var10 forKey:var9];
  NSString *var11 = @"doc";
  NSMutableDictionary *var12 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var13 = @"id";
  NSNumber *var14 = @1;
  [var12 setObject:var14 forKey:var13];
  [var8 setObject:var12 forKey:var11];
  [var0 addObject:var8];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test40 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var2 = @"dist";
  NSNumber *var3 = @0;
  [var1 setObject:var3 forKey:var2];
  NSString *var4 = @"doc";
  NSMutableDictionary *var5 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var6 = @"id";
  NSNumber *var7 = @1;
  [var5 setObject:var7 forKey:var6];
  [var1 setObject:var5 forKey:var4];
  [var0 addObject:var1];
  NSMutableDictionary *var8 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var9 = @"dist";
  NSNumber *var10 = @0.055659745396754216;
  [var8 setObject:var10 forKey:var9];
  NSString *var11 = @"doc";
  NSMutableDictionary *var12 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var13 = @"id";
  NSNumber *var14 = @2;
  [var12 setObject:var14 forKey:var13];
  [var8 setObject:var12 forKey:var11];
  [var0 addObject:var8];
  NSMutableDictionary *var15 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var16 = @"dist";
  NSNumber *var17 = @1565109.0992178896;
  [var15 setObject:var17 forKey:var16];
  NSString *var18 = @"doc";
  NSMutableDictionary *var19 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var20 = @"id";
  NSNumber *var21 = @0;
  [var19 setObject:var21 forKey:var20];
  [var15 setObject:var19 forKey:var18];
  [var0 addObject:var15];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test41 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var2 = @"dist";
  NSNumber *var3 = @0;
  [var1 setObject:var3 forKey:var2];
  NSString *var4 = @"doc";
  NSMutableDictionary *var5 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var6 = @"id";
  NSNumber *var7 = @1;
  [var5 setObject:var7 forKey:var6];
  [var1 setObject:var5 forKey:var4];
  [var0 addObject:var1];
  NSMutableDictionary *var8 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var9 = @"dist";
  NSNumber *var10 = @0.055659745396754216;
  [var8 setObject:var10 forKey:var9];
  NSString *var11 = @"doc";
  NSMutableDictionary *var12 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var13 = @"id";
  NSNumber *var14 = @2;
  [var12 setObject:var14 forKey:var13];
  [var8 setObject:var12 forKey:var11];
  [var0 addObject:var8];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test42 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test43 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var2 = @"dist";
  NSNumber *var3 = @0;
  [var1 setObject:var3 forKey:var2];
  NSString *var4 = @"doc";
  NSMutableDictionary *var5 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var6 = @"id";
  NSNumber *var7 = @1;
  [var5 setObject:var7 forKey:var6];
  [var1 setObject:var5 forKey:var4];
  [var0 addObject:var1];
  NSMutableDictionary *var8 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var9 = @"dist";
  NSNumber *var10 = @5.565974539675422e-05;
  [var8 setObject:var10 forKey:var9];
  NSString *var11 = @"doc";
  NSMutableDictionary *var12 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var13 = @"id";
  NSNumber *var14 = @2;
  [var12 setObject:var14 forKey:var13];
  [var8 setObject:var12 forKey:var11];
  [var0 addObject:var8];
  NSMutableDictionary *var15 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var16 = @"dist";
  NSNumber *var17 = @1565.1090992178897;
  [var15 setObject:var17 forKey:var16];
  NSString *var18 = @"doc";
  NSMutableDictionary *var19 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var20 = @"id";
  NSNumber *var21 = @0;
  [var19 setObject:var21 forKey:var20];
  [var15 setObject:var19 forKey:var18];
  [var0 addObject:var15];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test44 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var2 = @"dist";
  NSNumber *var3 = @0;
  [var1 setObject:var3 forKey:var2];
  NSString *var4 = @"doc";
  NSMutableDictionary *var5 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var6 = @"id";
  NSNumber *var7 = @1;
  [var5 setObject:var7 forKey:var6];
  [var1 setObject:var5 forKey:var4];
  [var0 addObject:var1];
  NSMutableDictionary *var8 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var9 = @"dist";
  NSNumber *var10 = @8.726646259990191e-09;
  [var8 setObject:var10 forKey:var9];
  NSString *var11 = @"doc";
  NSMutableDictionary *var12 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var13 = @"id";
  NSNumber *var14 = @2;
  [var12 setObject:var14 forKey:var13];
  [var8 setObject:var12 forKey:var11];
  [var0 addObject:var8];
  NSMutableDictionary *var15 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var16 = @"dist";
  NSNumber *var17 = @0.24619691677893205;
  [var15 setObject:var17 forKey:var16];
  NSString *var18 = @"doc";
  NSMutableDictionary *var19 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var20 = @"id";
  NSNumber *var21 = @0;
  [var19 setObject:var21 forKey:var20];
  [var15 setObject:var19 forKey:var18];
  [var0 addObject:var15];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test45 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSString *var0 = @"ARRAY";
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test46 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSString *var0 = @"ARRAY";
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

@end
