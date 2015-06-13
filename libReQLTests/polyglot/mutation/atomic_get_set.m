// Copyright 2015 Adam Grandquist

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#import <libReQL.h>

@interface ObjcTestsReplacementOfSelections : XCTestCase

@end

@implementation ObjcTestsReplacementOfSelections


- (void)test0 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test1 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"changes";
  NSMutableArray *var2 = [NSMutableArray arrayWithCapacity:1];
  NSMutableDictionary *var3 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var4 = @"new_val";
  NSMutableDictionary *var5 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var6 = @"id";
  NSNumber *var7 = @0;
  [var5 setObject:var7 forKey:var6];
  [var3 setObject:var5 forKey:var4];
  NSString *var8 = @"old_val";
  NSNull *var9 = [NSNull null];
  [var3 setObject:var9 forKey:var8];
  [var2 addObject:var3];
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test2 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var1 = @"changes";
  NSArray *var2 = [NSArray array];
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"first_error";
  NSString *var4 = @"Duplicate primary key `id`:\n{\n\t\"id\":\t0\n}\n{\n\t\"id\":\t0\n}";
  [var0 setObject:var4 forKey:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test3 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var1 = @"changes";
  NSMutableArray *var2 = [NSMutableArray arrayWithCapacity:1];
  NSMutableDictionary *var3 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var4 = @"new_val";
  NSMutableDictionary *var5 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var6 = @"id";
  NSNumber *var7 = @0;
  [var5 setObject:var7 forKey:var6];
  [var3 setObject:var5 forKey:var4];
  NSString *var8 = @"old_val";
  NSMutableDictionary *var9 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var10 = @"id";
  NSNumber *var11 = @0;
  [var9 setObject:var11 forKey:var10];
  [var3 setObject:var9 forKey:var8];
  [var2 addObject:var3];
  [var0 setObject:var2 forKey:var1];
  NSString *var12 = @"first_error";
  NSString *var13 = @"Duplicate primary key `id`:\n{\n\t\"id\":\t0\n}\n{\n\t\"id\":\t0\n}";
  [var0 setObject:var13 forKey:var12];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test4 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:7];
  NSString *var1 = @"changes";
  NSMutableArray *var2 = [NSMutableArray arrayWithCapacity:1];
  NSMutableDictionary *var3 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var4 = @"new_val";
  NSMutableDictionary *var5 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var6 = @"id";
  NSNumber *var7 = @1;
  [var5 setObject:var7 forKey:var6];
  [var3 setObject:var5 forKey:var4];
  NSString *var8 = @"old_val";
  NSNull *var9 = [NSNull null];
  [var3 setObject:var9 forKey:var8];
  [var2 addObject:var3];
  [var0 setObject:var2 forKey:var1];
  NSString *var10 = @"deleted";
  NSNumber *var11 = @0;
  [var0 setObject:var11 forKey:var10];
  NSString *var12 = @"errors";
  NSNumber *var13 = @0;
  [var0 setObject:var13 forKey:var12];
  NSString *var14 = @"inserted";
  NSNumber *var15 = @1;
  [var0 setObject:var15 forKey:var14];
  NSString *var16 = @"replaced";
  NSNumber *var17 = @0;
  [var0 setObject:var17 forKey:var16];
  NSString *var18 = @"skipped";
  NSNumber *var19 = @0;
  [var0 setObject:var19 forKey:var18];
  NSString *var20 = @"unchanged";
  NSNumber *var21 = @0;
  [var0 setObject:var21 forKey:var20];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test5 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var1 = @"changes";
  NSArray *var2 = [NSArray array];
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"first_error";
  NSString *var4 = @"Duplicate primary key `id`:\n{\n\t\"id\":\t0\n}\n{\n\t\"id\":\t0\n}";
  [var0 setObject:var4 forKey:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test6 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"changes";
  NSMutableArray *var2 = [NSMutableArray arrayWithCapacity:1];
  NSMutableDictionary *var3 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var4 = @"new_val";
  NSMutableDictionary *var5 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var6 = @"id";
  NSNumber *var7 = @0;
  [var5 setObject:var7 forKey:var6];
  NSString *var8 = @"x";
  NSNumber *var9 = @1;
  [var5 setObject:var9 forKey:var8];
  [var3 setObject:var5 forKey:var4];
  NSString *var10 = @"old_val";
  NSMutableDictionary *var11 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var12 = @"id";
  NSNumber *var13 = @0;
  [var11 setObject:var13 forKey:var12];
  [var3 setObject:var11 forKey:var10];
  [var2 addObject:var3];
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test7 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var1 = @"changes";
  NSArray *var2 = [NSArray array];
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"first_error";
  NSString *var4 = @"a";
  [var0 setObject:var4 forKey:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test8 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"changes";
  NSMutableArray *var2 = [NSMutableArray arrayWithCapacity:2];
  NSMutableDictionary *var3 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var4 = @"new_val";
  NSMutableDictionary *var5 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var6 = @"id";
  NSNumber *var7 = @0;
  [var5 setObject:var7 forKey:var6];
  NSString *var8 = @"x";
  NSNumber *var9 = @3;
  [var5 setObject:var9 forKey:var8];
  [var3 setObject:var5 forKey:var4];
  NSString *var10 = @"old_val";
  NSMutableDictionary *var11 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var12 = @"id";
  NSNumber *var13 = @0;
  [var11 setObject:var13 forKey:var12];
  NSString *var14 = @"x";
  NSNumber *var15 = @1;
  [var11 setObject:var15 forKey:var14];
  [var3 setObject:var11 forKey:var10];
  [var2 addObject:var3];
  NSMutableDictionary *var16 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var17 = @"new_val";
  NSMutableDictionary *var18 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var19 = @"id";
  NSNumber *var20 = @1;
  [var18 setObject:var20 forKey:var19];
  NSString *var21 = @"x";
  NSNumber *var22 = @3;
  [var18 setObject:var22 forKey:var21];
  [var16 setObject:var18 forKey:var17];
  NSString *var23 = @"old_val";
  NSMutableDictionary *var24 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var25 = @"id";
  NSNumber *var26 = @1;
  [var24 setObject:var26 forKey:var25];
  [var16 setObject:var24 forKey:var23];
  [var2 addObject:var16];
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test9 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"changes";
  NSMutableArray *var2 = [NSMutableArray arrayWithCapacity:1];
  NSMutableDictionary *var3 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var4 = @"new_val";
  NSMutableDictionary *var5 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var6 = @"id";
  NSNumber *var7 = @0;
  [var5 setObject:var7 forKey:var6];
  NSString *var8 = @"x";
  NSNumber *var9 = @2;
  [var5 setObject:var9 forKey:var8];
  [var3 setObject:var5 forKey:var4];
  NSString *var10 = @"old_val";
  NSMutableDictionary *var11 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var12 = @"id";
  NSNumber *var13 = @0;
  [var11 setObject:var13 forKey:var12];
  NSString *var14 = @"x";
  NSNumber *var15 = @3;
  [var11 setObject:var15 forKey:var14];
  [var3 setObject:var11 forKey:var10];
  [var2 addObject:var3];
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test10 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var1 = @"changes";
  NSArray *var2 = [NSArray array];
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"first_error";
  NSString *var4 = @"a";
  [var0 setObject:var4 forKey:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test11 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var1 = @"changes";
  NSMutableArray *var2 = [NSMutableArray arrayWithCapacity:1];
  NSMutableDictionary *var3 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var4 = @"new_val";
  NSMutableDictionary *var5 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var6 = @"id";
  NSNumber *var7 = @0;
  [var5 setObject:var7 forKey:var6];
  NSString *var8 = @"x";
  NSNumber *var9 = @2;
  [var5 setObject:var9 forKey:var8];
  [var3 setObject:var5 forKey:var4];
  NSString *var10 = @"old_val";
  NSMutableDictionary *var11 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var12 = @"id";
  NSNumber *var13 = @0;
  [var11 setObject:var13 forKey:var12];
  NSString *var14 = @"x";
  NSNumber *var15 = @2;
  [var11 setObject:var15 forKey:var14];
  [var3 setObject:var11 forKey:var10];
  [var2 addObject:var3];
  [var0 setObject:var2 forKey:var1];
  NSString *var16 = @"first_error";
  NSString *var17 = @"a";
  [var0 setObject:var17 forKey:var16];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test12 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"changes";
  NSMutableArray *var2 = [NSMutableArray arrayWithCapacity:2];
  NSMutableDictionary *var3 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var4 = @"new_val";
  NSMutableDictionary *var5 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var6 = @"id";
  NSNumber *var7 = @0;
  [var5 setObject:var7 forKey:var6];
  [var3 setObject:var5 forKey:var4];
  NSString *var8 = @"old_val";
  NSMutableDictionary *var9 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var10 = @"id";
  NSNumber *var11 = @0;
  [var9 setObject:var11 forKey:var10];
  NSString *var12 = @"x";
  NSNumber *var13 = @2;
  [var9 setObject:var13 forKey:var12];
  [var3 setObject:var9 forKey:var8];
  [var2 addObject:var3];
  NSMutableDictionary *var14 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var15 = @"new_val";
  NSMutableDictionary *var16 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var17 = @"id";
  NSNumber *var18 = @1;
  [var16 setObject:var18 forKey:var17];
  [var14 setObject:var16 forKey:var15];
  NSString *var19 = @"old_val";
  NSMutableDictionary *var20 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var21 = @"id";
  NSNumber *var22 = @1;
  [var20 setObject:var22 forKey:var21];
  NSString *var23 = @"x";
  NSNumber *var24 = @3;
  [var20 setObject:var24 forKey:var23];
  [var14 setObject:var20 forKey:var19];
  [var2 addObject:var14];
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test13 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var1 = @"changes";
  NSMutableArray *var2 = [NSMutableArray arrayWithCapacity:2];
  NSMutableDictionary *var3 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var4 = @"new_val";
  NSMutableDictionary *var5 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var6 = @"id";
  NSNumber *var7 = @0;
  [var5 setObject:var7 forKey:var6];
  [var3 setObject:var5 forKey:var4];
  NSString *var8 = @"old_val";
  NSMutableDictionary *var9 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var10 = @"id";
  NSNumber *var11 = @0;
  [var9 setObject:var11 forKey:var10];
  [var3 setObject:var9 forKey:var8];
  [var2 addObject:var3];
  NSMutableDictionary *var12 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var13 = @"new_val";
  NSMutableDictionary *var14 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var15 = @"id";
  NSNumber *var16 = @1;
  [var14 setObject:var16 forKey:var15];
  [var12 setObject:var14 forKey:var13];
  NSString *var17 = @"old_val";
  NSMutableDictionary *var18 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var19 = @"id";
  NSNumber *var20 = @1;
  [var18 setObject:var20 forKey:var19];
  [var12 setObject:var18 forKey:var17];
  [var2 addObject:var12];
  [var0 setObject:var2 forKey:var1];
  NSString *var21 = @"first_error";
  NSString *var22 = @"Inserted object must have primary key `id`:\n{\n\t\"x\":\t1\n}";
  [var0 setObject:var22 forKey:var21];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test22 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"changes";
  NSMutableArray *var2 = [NSMutableArray arrayWithCapacity:1];
  NSMutableDictionary *var3 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var4 = @"new_val";
  NSNull *var5 = [NSNull null];
  [var3 setObject:var5 forKey:var4];
  NSString *var6 = @"old_val";
  NSMutableDictionary *var7 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var8 = @"id";
  NSNumber *var9 = @0;
  [var7 setObject:var9 forKey:var8];
  [var3 setObject:var7 forKey:var6];
  [var2 addObject:var3];
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test23 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:7];
  NSString *var1 = @"changes";
  NSMutableArray *var2 = [NSMutableArray arrayWithCapacity:1];
  NSMutableDictionary *var3 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var4 = @"new_val";
  NSNull *var5 = [NSNull null];
  [var3 setObject:var5 forKey:var4];
  NSString *var6 = @"old_val";
  NSMutableDictionary *var7 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var8 = @"id";
  NSNumber *var9 = @1;
  [var7 setObject:var9 forKey:var8];
  [var3 setObject:var7 forKey:var6];
  [var2 addObject:var3];
  [var0 setObject:var2 forKey:var1];
  NSString *var10 = @"deleted";
  NSNumber *var11 = @1;
  [var0 setObject:var11 forKey:var10];
  NSString *var12 = @"errors";
  NSNumber *var13 = @0;
  [var0 setObject:var13 forKey:var12];
  NSString *var14 = @"inserted";
  NSNumber *var15 = @0;
  [var0 setObject:var15 forKey:var14];
  NSString *var16 = @"replaced";
  NSNumber *var17 = @0;
  [var0 setObject:var17 forKey:var16];
  NSString *var18 = @"skipped";
  NSNumber *var19 = @0;
  [var0 setObject:var19 forKey:var18];
  NSString *var20 = @"unchanged";
  NSNumber *var21 = @0;
  [var0 setObject:var21 forKey:var20];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

@end
