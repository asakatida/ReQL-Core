// Copyright 2015 Adam Grandquist

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#import <libReQL.h>

@interface ObjcTestsInsertionIntoTables : XCTestCase

@end

@implementation ObjcTestsInsertionIntoTables


- (void)test0 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"partial";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test2 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:6];
  NSString *var1 = @"deleted";
  NSNumber *var2 = @0.0;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"errors";
  NSNumber *var4 = @0.0;
  [var0 setObject:var4 forKey:var3];
  NSString *var5 = @"inserted";
  NSNumber *var6 = @1;
  [var0 setObject:var6 forKey:var5];
  NSString *var7 = @"replaced";
  NSNumber *var8 = @0.0;
  [var0 setObject:var8 forKey:var7];
  NSString *var9 = @"skipped";
  NSNumber *var10 = @0.0;
  [var0 setObject:var10 forKey:var9];
  NSString *var11 = @"unchanged";
  NSNumber *var12 = @0.0;
  [var0 setObject:var12 forKey:var11];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test3 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @1;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test4 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:6];
  NSString *var1 = @"deleted";
  NSNumber *var2 = @0.0;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"errors";
  NSNumber *var4 = @0.0;
  [var0 setObject:var4 forKey:var3];
  NSString *var5 = @"inserted";
  NSNumber *var6 = @1;
  [var0 setObject:var6 forKey:var5];
  NSString *var7 = @"replaced";
  NSNumber *var8 = @0.0;
  [var0 setObject:var8 forKey:var7];
  NSString *var9 = @"skipped";
  NSNumber *var10 = @0.0;
  [var0 setObject:var10 forKey:var9];
  NSString *var11 = @"unchanged";
  NSNumber *var12 = @0.0;
  [var0 setObject:var12 forKey:var11];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test5 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @2;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test6 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:6];
  NSString *var1 = @"deleted";
  NSNumber *var2 = @0.0;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"errors";
  NSNumber *var4 = @0.0;
  [var0 setObject:var4 forKey:var3];
  NSString *var5 = @"inserted";
  NSNumber *var6 = @1;
  [var0 setObject:var6 forKey:var5];
  NSString *var7 = @"replaced";
  NSNumber *var8 = @0.0;
  [var0 setObject:var8 forKey:var7];
  NSString *var9 = @"skipped";
  NSNumber *var10 = @0.0;
  [var0 setObject:var10 forKey:var9];
  NSString *var11 = @"unchanged";
  NSNumber *var12 = @0.0;
  [var0 setObject:var12 forKey:var11];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test7 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @3;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test8 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test9 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @3;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test10 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:6];
  NSString *var1 = @"deleted";
  NSNumber *var2 = @1;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"errors";
  NSNumber *var4 = @0.0;
  [var0 setObject:var4 forKey:var3];
  NSString *var5 = @"inserted";
  NSNumber *var6 = @0.0;
  [var0 setObject:var6 forKey:var5];
  NSString *var7 = @"replaced";
  NSNumber *var8 = @0.0;
  [var0 setObject:var8 forKey:var7];
  NSString *var9 = @"skipped";
  NSNumber *var10 = @0.0;
  [var0 setObject:var10 forKey:var9];
  NSString *var11 = @"unchanged";
  NSNumber *var12 = @0.0;
  [var0 setObject:var12 forKey:var11];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test11 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:6];
  NSString *var1 = @"deleted";
  NSNumber *var2 = @0.0;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"errors";
  NSNumber *var4 = @0.0;
  [var0 setObject:var4 forKey:var3];
  NSString *var5 = @"inserted";
  NSNumber *var6 = @2;
  [var0 setObject:var6 forKey:var5];
  NSString *var7 = @"replaced";
  NSNumber *var8 = @0.0;
  [var0 setObject:var8 forKey:var7];
  NSString *var9 = @"skipped";
  NSNumber *var10 = @0.0;
  [var0 setObject:var10 forKey:var9];
  NSString *var11 = @"unchanged";
  NSNumber *var12 = @0.0;
  [var0 setObject:var12 forKey:var11];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test12 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:6];
  NSString *var1 = @"deleted";
  NSNumber *var2 = @0.0;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"errors";
  NSNumber *var4 = @0.0;
  [var0 setObject:var4 forKey:var3];
  NSString *var5 = @"inserted";
  NSNumber *var6 = @4;
  [var0 setObject:var6 forKey:var5];
  NSString *var7 = @"replaced";
  NSNumber *var8 = @0.0;
  [var0 setObject:var8 forKey:var7];
  NSString *var9 = @"skipped";
  NSNumber *var10 = @0.0;
  [var0 setObject:var10 forKey:var9];
  NSString *var11 = @"unchanged";
  NSNumber *var12 = @0.0;
  [var0 setObject:var12 forKey:var11];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test13 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:7];
  NSString *var1 = @"deleted";
  NSNumber *var2 = @0.0;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"errors";
  NSNumber *var4 = @1;
  [var0 setObject:var4 forKey:var3];
  NSString *var5 = @"first_error";
  NSString *var6 = @"Duplicate primary key `id`:\n{\n\t\"a\":\t2,\n\t\"id\":\t2\n}\n{\n\t\"b\":\t20,\n\t\"id\":\t2\n}";
  [var0 setObject:var6 forKey:var5];
  NSString *var7 = @"inserted";
  NSNumber *var8 = @0.0;
  [var0 setObject:var8 forKey:var7];
  NSString *var9 = @"replaced";
  NSNumber *var10 = @0.0;
  [var0 setObject:var10 forKey:var9];
  NSString *var11 = @"skipped";
  NSNumber *var12 = @0.0;
  [var0 setObject:var12 forKey:var11];
  NSString *var13 = @"unchanged";
  NSNumber *var14 = @0.0;
  [var0 setObject:var14 forKey:var13];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test14 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:7];
  NSString *var1 = @"deleted";
  NSNumber *var2 = @0.0;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"errors";
  NSNumber *var4 = @1;
  [var0 setObject:var4 forKey:var3];
  NSString *var5 = @"first_error";
  NSString *var6 = @"Duplicate primary key `id`:\n{\n\t\"a\":\t2,\n\t\"id\":\t2\n}\n{\n\t\"b\":\t20,\n\t\"id\":\t2\n}";
  [var0 setObject:var6 forKey:var5];
  NSString *var7 = @"inserted";
  NSNumber *var8 = @0.0;
  [var0 setObject:var8 forKey:var7];
  NSString *var9 = @"replaced";
  NSNumber *var10 = @0.0;
  [var0 setObject:var10 forKey:var9];
  NSString *var11 = @"skipped";
  NSNumber *var12 = @0.0;
  [var0 setObject:var12 forKey:var11];
  NSString *var13 = @"unchanged";
  NSNumber *var14 = @0.0;
  [var0 setObject:var14 forKey:var13];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test15 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:6];
  NSString *var1 = @"deleted";
  NSNumber *var2 = @0.0;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"errors";
  NSNumber *var4 = @0.0;
  [var0 setObject:var4 forKey:var3];
  NSString *var5 = @"inserted";
  NSNumber *var6 = @1;
  [var0 setObject:var6 forKey:var5];
  NSString *var7 = @"replaced";
  NSNumber *var8 = @0.0;
  [var0 setObject:var8 forKey:var7];
  NSString *var9 = @"skipped";
  NSNumber *var10 = @0.0;
  [var0 setObject:var10 forKey:var9];
  NSString *var11 = @"unchanged";
  NSNumber *var12 = @0.0;
  [var0 setObject:var12 forKey:var11];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test16 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var1 = @"b";
  NSNumber *var2 = @20;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"id";
  NSNumber *var4 = @15;
  [var0 setObject:var4 forKey:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test17 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:6];
  NSString *var1 = @"deleted";
  NSNumber *var2 = @0.0;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"errors";
  NSNumber *var4 = @0.0;
  [var0 setObject:var4 forKey:var3];
  NSString *var5 = @"inserted";
  NSNumber *var6 = @0.0;
  [var0 setObject:var6 forKey:var5];
  NSString *var7 = @"replaced";
  NSNumber *var8 = @1;
  [var0 setObject:var8 forKey:var7];
  NSString *var9 = @"skipped";
  NSNumber *var10 = @0.0;
  [var0 setObject:var10 forKey:var9];
  NSString *var11 = @"unchanged";
  NSNumber *var12 = @0.0;
  [var0 setObject:var12 forKey:var11];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test18 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var1 = @"b";
  NSNumber *var2 = @20;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"id";
  NSNumber *var4 = @2;
  [var0 setObject:var4 forKey:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test19 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:6];
  NSString *var1 = @"deleted";
  NSNumber *var2 = @0.0;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"errors";
  NSNumber *var4 = @0.0;
  [var0 setObject:var4 forKey:var3];
  NSString *var5 = @"inserted";
  NSNumber *var6 = @1;
  [var0 setObject:var6 forKey:var5];
  NSString *var7 = @"replaced";
  NSNumber *var8 = @0.0;
  [var0 setObject:var8 forKey:var7];
  NSString *var9 = @"skipped";
  NSNumber *var10 = @0.0;
  [var0 setObject:var10 forKey:var9];
  NSString *var11 = @"unchanged";
  NSNumber *var12 = @0.0;
  [var0 setObject:var12 forKey:var11];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test20 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var1 = @"b";
  NSNumber *var2 = @20;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"id";
  NSNumber *var4 = @20;
  [var0 setObject:var4 forKey:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test21 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:6];
  NSString *var1 = @"deleted";
  NSNumber *var2 = @0.0;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"errors";
  NSNumber *var4 = @0.0;
  [var0 setObject:var4 forKey:var3];
  NSString *var5 = @"inserted";
  NSNumber *var6 = @0.0;
  [var0 setObject:var6 forKey:var5];
  NSString *var7 = @"replaced";
  NSNumber *var8 = @1;
  [var0 setObject:var8 forKey:var7];
  NSString *var9 = @"skipped";
  NSNumber *var10 = @0.0;
  [var0 setObject:var10 forKey:var9];
  NSString *var11 = @"unchanged";
  NSNumber *var12 = @0.0;
  [var0 setObject:var12 forKey:var11];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test22 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:3];
  NSString *var1 = @"b";
  NSNumber *var2 = @20;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"c";
  NSNumber *var4 = @30;
  [var0 setObject:var4 forKey:var3];
  NSString *var5 = @"id";
  NSNumber *var6 = @2;
  [var0 setObject:var6 forKey:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test23 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:6];
  NSString *var1 = @"deleted";
  NSNumber *var2 = @0.0;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"errors";
  NSNumber *var4 = @0.0;
  [var0 setObject:var4 forKey:var3];
  NSString *var5 = @"inserted";
  NSNumber *var6 = @1;
  [var0 setObject:var6 forKey:var5];
  NSString *var7 = @"replaced";
  NSNumber *var8 = @0.0;
  [var0 setObject:var8 forKey:var7];
  NSString *var9 = @"skipped";
  NSNumber *var10 = @0.0;
  [var0 setObject:var10 forKey:var9];
  NSString *var11 = @"unchanged";
  NSNumber *var12 = @0.0;
  [var0 setObject:var12 forKey:var11];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test24 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var1 = @"b";
  NSNumber *var2 = @20;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"id";
  NSNumber *var4 = @30;
  [var0 setObject:var4 forKey:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test25 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test26 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"partial";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test27 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:7];
  NSString *var1 = @"deleted";
  NSNumber *var2 = @0.0;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"errors";
  NSNumber *var4 = @0.0;
  [var0 setObject:var4 forKey:var3];
  NSString *var5 = @"generated_keys";
  NSMutableDictionary *var6 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var7 = @"func";
  NSString *var8 = @"arrlen";
  [var6 setObject:var8 forKey:var7];
  [var0 setObject:var6 forKey:var5];
  NSString *var9 = @"inserted";
  NSNumber *var10 = @1;
  [var0 setObject:var10 forKey:var9];
  NSString *var11 = @"replaced";
  NSNumber *var12 = @0.0;
  [var0 setObject:var12 forKey:var11];
  NSString *var13 = @"skipped";
  NSNumber *var14 = @0.0;
  [var0 setObject:var14 forKey:var13];
  NSString *var15 = @"unchanged";
  NSNumber *var16 = @0.0;
  [var0 setObject:var16 forKey:var15];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test28 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:1];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var2 = @"foo";
  NSMutableDictionary *var3 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var4 = @"func";
  NSString *var5 = @"uuid";
  [var3 setObject:var5 forKey:var4];
  [var1 setObject:var3 forKey:var2];
  [var0 addObject:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test29 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:7];
  NSString *var1 = @"deleted";
  NSNumber *var2 = @0.0;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"errors";
  NSNumber *var4 = @0.0;
  [var0 setObject:var4 forKey:var3];
  NSString *var5 = @"generated_keys";
  NSMutableDictionary *var6 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var7 = @"func";
  NSString *var8 = @"arrlen";
  [var6 setObject:var8 forKey:var7];
  [var0 setObject:var6 forKey:var5];
  NSString *var9 = @"inserted";
  NSNumber *var10 = @1;
  [var0 setObject:var10 forKey:var9];
  NSString *var11 = @"replaced";
  NSNumber *var12 = @0.0;
  [var0 setObject:var12 forKey:var11];
  NSString *var13 = @"skipped";
  NSNumber *var14 = @0.0;
  [var0 setObject:var14 forKey:var13];
  NSString *var15 = @"unchanged";
  NSNumber *var16 = @0.0;
  [var0 setObject:var16 forKey:var15];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test30 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:7];
  NSString *var1 = @"deleted";
  NSNumber *var2 = @0.0;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"errors";
  NSNumber *var4 = @0.0;
  [var0 setObject:var4 forKey:var3];
  NSString *var5 = @"generated_keys";
  NSMutableDictionary *var6 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var7 = @"func";
  NSString *var8 = @"arrlen";
  [var6 setObject:var8 forKey:var7];
  [var0 setObject:var6 forKey:var5];
  NSString *var9 = @"inserted";
  NSNumber *var10 = @1;
  [var0 setObject:var10 forKey:var9];
  NSString *var11 = @"replaced";
  NSNumber *var12 = @0.0;
  [var0 setObject:var12 forKey:var11];
  NSString *var13 = @"skipped";
  NSNumber *var14 = @0.0;
  [var0 setObject:var14 forKey:var13];
  NSString *var15 = @"unchanged";
  NSNumber *var16 = @0.0;
  [var0 setObject:var16 forKey:var15];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test31 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"partial";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test32 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:6];
  NSString *var1 = @"deleted";
  NSNumber *var2 = @0.0;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"errors";
  NSNumber *var4 = @0.0;
  [var0 setObject:var4 forKey:var3];
  NSString *var5 = @"inserted";
  NSNumber *var6 = @7;
  [var0 setObject:var6 forKey:var5];
  NSString *var7 = @"replaced";
  NSNumber *var8 = @0.0;
  [var0 setObject:var8 forKey:var7];
  NSString *var9 = @"skipped";
  NSNumber *var10 = @0.0;
  [var0 setObject:var10 forKey:var9];
  NSString *var11 = @"unchanged";
  NSNumber *var12 = @0.0;
  [var0 setObject:var12 forKey:var11];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test33 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"partial";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test34 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"partial";
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
  NSString *var2 = @"partial";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

@end
