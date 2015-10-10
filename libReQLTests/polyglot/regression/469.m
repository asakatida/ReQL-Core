// Copyright 2015 Adam Grandquist

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#import <libReQL.h>

@interface ObjcIssue470 : XCTestCase

@end

@implementation ObjcIssue470


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

- (void)test1 {
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
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:1];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var2 = @"index";
  NSString *var3 = @"x";
  [var1 setObject:var3 forKey:var2];
  NSString *var4 = @"ready";
  NSNumber *var5 = [NSNumber numberWithBool:YES];
  [var1 setObject:var5 forKey:var4];
  [var0 addObject:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test4 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"type";
  NSString *var2 = @"MINVAL";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test5 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"type";
  NSString *var2 = @"MAXVAL";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test6 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"type";
  NSString *var2 = @"NULL";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test7 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var1 = @"type";
  NSString *var2 = @"BOOL";
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"value";
  NSString *var4 = @"true";
  [var0 setObject:var4 forKey:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test8 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var1 = @"type";
  NSString *var2 = @"NUMBER";
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"value";
  NSString *var4 = @"1";
  [var0 setObject:var4 forKey:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test9 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var1 = @"type";
  NSString *var2 = @"STRING";
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"value";
  NSString *var4 = @"\"1\"";
  [var0 setObject:var4 forKey:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test10 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var1 = @"type";
  NSString *var2 = @"ARRAY";
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"value";
  NSString *var4 = @"[\n\t1\n]";
  [var0 setObject:var4 forKey:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test11 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var1 = @"type";
  NSString *var2 = @"OBJECT";
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"value";
  NSString *var4 = @"{\n\t\"a\":\t1\n}";
  [var0 setObject:var4 forKey:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test12 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"partial";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test13 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:7];
  NSString *var1 = @"db";
  NSMutableDictionary *var2 = [NSMutableDictionary dictionaryWithCapacity:3];
  NSString *var3 = @"id";
  NSMutableDictionary *var4 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var5 = @"func";
  NSString *var6 = @"uuid";
  [var4 setObject:var6 forKey:var5];
  [var2 setObject:var4 forKey:var3];
  NSString *var7 = @"name";
  NSString *var8 = @"d469";
  [var2 setObject:var8 forKey:var7];
  NSString *var9 = @"type";
  NSString *var10 = @"DB";
  [var2 setObject:var10 forKey:var9];
  [var0 setObject:var2 forKey:var1];
  NSString *var11 = @"doc_count_estimates";
  NSMutableArray *var12 = [NSMutableArray arrayWithCapacity:1];
  NSNumber *var13 = @0;
  [var12 addObject:var13];
  [var0 setObject:var12 forKey:var11];
  NSString *var14 = @"id";
  NSMutableDictionary *var15 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var16 = @"func";
  NSString *var17 = @"uuid";
  [var15 setObject:var17 forKey:var16];
  [var0 setObject:var15 forKey:var14];
  NSString *var18 = @"indexes";
  NSMutableArray *var19 = [NSMutableArray arrayWithCapacity:1];
  NSString *var20 = @"x";
  [var19 addObject:var20];
  [var0 setObject:var19 forKey:var18];
  NSString *var21 = @"name";
  NSString *var22 = @"t469";
  [var0 setObject:var22 forKey:var21];
  NSString *var23 = @"primary_key";
  NSString *var24 = @"id";
  [var0 setObject:var24 forKey:var23];
  NSString *var25 = @"type";
  NSString *var26 = @"TABLE";
  [var0 setObject:var26 forKey:var25];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test14 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var1 = @"table";
  NSMutableDictionary *var2 = [NSMutableDictionary dictionaryWithCapacity:7];
  NSString *var3 = @"db";
  NSMutableDictionary *var4 = [NSMutableDictionary dictionaryWithCapacity:3];
  NSString *var5 = @"id";
  NSMutableDictionary *var6 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var7 = @"func";
  NSString *var8 = @"uuid";
  [var6 setObject:var8 forKey:var7];
  [var4 setObject:var6 forKey:var5];
  NSString *var9 = @"name";
  NSString *var10 = @"d469";
  [var4 setObject:var10 forKey:var9];
  NSString *var11 = @"type";
  NSString *var12 = @"DB";
  [var4 setObject:var12 forKey:var11];
  [var2 setObject:var4 forKey:var3];
  NSString *var13 = @"doc_count_estimates";
  NSMutableArray *var14 = [NSMutableArray arrayWithCapacity:1];
  NSNumber *var15 = @0;
  [var14 addObject:var15];
  [var2 setObject:var14 forKey:var13];
  NSString *var16 = @"id";
  NSMutableDictionary *var17 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var18 = @"func";
  NSString *var19 = @"uuid";
  [var17 setObject:var19 forKey:var18];
  [var2 setObject:var17 forKey:var16];
  NSString *var20 = @"indexes";
  NSMutableArray *var21 = [NSMutableArray arrayWithCapacity:1];
  NSString *var22 = @"x";
  [var21 addObject:var22];
  [var2 setObject:var21 forKey:var20];
  NSString *var23 = @"name";
  NSString *var24 = @"t469";
  [var2 setObject:var24 forKey:var23];
  NSString *var25 = @"primary_key";
  NSString *var26 = @"id";
  [var2 setObject:var26 forKey:var25];
  NSString *var27 = @"type";
  NSString *var28 = @"TABLE";
  [var2 setObject:var28 forKey:var27];
  [var0 setObject:var2 forKey:var1];
  NSString *var29 = @"type";
  NSString *var30 = @"SELECTION<STREAM>";
  [var0 setObject:var30 forKey:var29];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test15 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"type";
  NSString *var2 = @"STREAM";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test16 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:8];
  NSString *var1 = @"index";
  NSString *var2 = @"id";
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"left_bound";
  NSNumber *var4 = @0;
  [var0 setObject:var4 forKey:var3];
  NSString *var5 = @"left_bound_type";
  NSString *var6 = @"closed";
  [var0 setObject:var6 forKey:var5];
  NSString *var7 = @"right_bound";
  NSNumber *var8 = @1;
  [var0 setObject:var8 forKey:var7];
  NSString *var9 = @"right_bound_type";
  NSString *var10 = @"open";
  [var0 setObject:var10 forKey:var9];
  NSString *var11 = @"sorting";
  NSString *var12 = @"UNORDERED";
  [var0 setObject:var12 forKey:var11];
  NSString *var13 = @"table";
  NSMutableDictionary *var14 = [NSMutableDictionary dictionaryWithCapacity:7];
  NSString *var15 = @"db";
  NSMutableDictionary *var16 = [NSMutableDictionary dictionaryWithCapacity:3];
  NSString *var17 = @"id";
  NSMutableDictionary *var18 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var19 = @"func";
  NSString *var20 = @"uuid";
  [var18 setObject:var20 forKey:var19];
  [var16 setObject:var18 forKey:var17];
  NSString *var21 = @"name";
  NSString *var22 = @"d469";
  [var16 setObject:var22 forKey:var21];
  NSString *var23 = @"type";
  NSString *var24 = @"DB";
  [var16 setObject:var24 forKey:var23];
  [var14 setObject:var16 forKey:var15];
  NSString *var25 = @"doc_count_estimates";
  NSMutableArray *var26 = [NSMutableArray arrayWithCapacity:1];
  NSNumber *var27 = @0;
  [var26 addObject:var27];
  [var14 setObject:var26 forKey:var25];
  NSString *var28 = @"id";
  NSMutableDictionary *var29 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var30 = @"func";
  NSString *var31 = @"uuid";
  [var29 setObject:var31 forKey:var30];
  [var14 setObject:var29 forKey:var28];
  NSString *var32 = @"indexes";
  NSMutableArray *var33 = [NSMutableArray arrayWithCapacity:1];
  NSString *var34 = @"x";
  [var33 addObject:var34];
  [var14 setObject:var33 forKey:var32];
  NSString *var35 = @"name";
  NSString *var36 = @"t469";
  [var14 setObject:var36 forKey:var35];
  NSString *var37 = @"primary_key";
  NSString *var38 = @"id";
  [var14 setObject:var38 forKey:var37];
  NSString *var39 = @"type";
  NSString *var40 = @"TABLE";
  [var14 setObject:var40 forKey:var39];
  [var0 setObject:var14 forKey:var13];
  NSString *var41 = @"type";
  NSString *var42 = @"TABLE_SLICE";
  [var0 setObject:var42 forKey:var41];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test17 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:8];
  NSString *var1 = @"index";
  NSString *var2 = @"a";
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"left_bound";
  NSNumber *var4 = @0;
  [var0 setObject:var4 forKey:var3];
  NSString *var5 = @"left_bound_type";
  NSString *var6 = @"closed";
  [var0 setObject:var6 forKey:var5];
  NSString *var7 = @"right_bound";
  NSNumber *var8 = @1;
  [var0 setObject:var8 forKey:var7];
  NSString *var9 = @"right_bound_type";
  NSString *var10 = @"open";
  [var0 setObject:var10 forKey:var9];
  NSString *var11 = @"sorting";
  NSString *var12 = @"UNORDERED";
  [var0 setObject:var12 forKey:var11];
  NSString *var13 = @"table";
  NSMutableDictionary *var14 = [NSMutableDictionary dictionaryWithCapacity:7];
  NSString *var15 = @"db";
  NSMutableDictionary *var16 = [NSMutableDictionary dictionaryWithCapacity:3];
  NSString *var17 = @"id";
  NSMutableDictionary *var18 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var19 = @"func";
  NSString *var20 = @"uuid";
  [var18 setObject:var20 forKey:var19];
  [var16 setObject:var18 forKey:var17];
  NSString *var21 = @"name";
  NSString *var22 = @"d469";
  [var16 setObject:var22 forKey:var21];
  NSString *var23 = @"type";
  NSString *var24 = @"DB";
  [var16 setObject:var24 forKey:var23];
  [var14 setObject:var16 forKey:var15];
  NSString *var25 = @"doc_count_estimates";
  NSMutableArray *var26 = [NSMutableArray arrayWithCapacity:1];
  NSNumber *var27 = @0;
  [var26 addObject:var27];
  [var14 setObject:var26 forKey:var25];
  NSString *var28 = @"id";
  NSMutableDictionary *var29 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var30 = @"func";
  NSString *var31 = @"uuid";
  [var29 setObject:var31 forKey:var30];
  [var14 setObject:var29 forKey:var28];
  NSString *var32 = @"indexes";
  NSMutableArray *var33 = [NSMutableArray arrayWithCapacity:1];
  NSString *var34 = @"x";
  [var33 addObject:var34];
  [var14 setObject:var33 forKey:var32];
  NSString *var35 = @"name";
  NSString *var36 = @"t469";
  [var14 setObject:var36 forKey:var35];
  NSString *var37 = @"primary_key";
  NSString *var38 = @"id";
  [var14 setObject:var38 forKey:var37];
  NSString *var39 = @"type";
  NSString *var40 = @"TABLE";
  [var14 setObject:var40 forKey:var39];
  [var0 setObject:var14 forKey:var13];
  NSString *var41 = @"type";
  NSString *var42 = @"TABLE_SLICE";
  [var0 setObject:var42 forKey:var41];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test18 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:8];
  NSString *var1 = @"index";
  NSString *var2 = @"a";
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"left_bound";
  NSNumber *var4 = @0;
  [var0 setObject:var4 forKey:var3];
  NSString *var5 = @"left_bound_type";
  NSString *var6 = @"closed";
  [var0 setObject:var6 forKey:var5];
  NSString *var7 = @"right_bound";
  NSNumber *var8 = @1;
  [var0 setObject:var8 forKey:var7];
  NSString *var9 = @"right_bound_type";
  NSString *var10 = @"open";
  [var0 setObject:var10 forKey:var9];
  NSString *var11 = @"sorting";
  NSString *var12 = @"ASCENDING";
  [var0 setObject:var12 forKey:var11];
  NSString *var13 = @"table";
  NSMutableDictionary *var14 = [NSMutableDictionary dictionaryWithCapacity:7];
  NSString *var15 = @"db";
  NSMutableDictionary *var16 = [NSMutableDictionary dictionaryWithCapacity:3];
  NSString *var17 = @"id";
  NSMutableDictionary *var18 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var19 = @"func";
  NSString *var20 = @"uuid";
  [var18 setObject:var20 forKey:var19];
  [var16 setObject:var18 forKey:var17];
  NSString *var21 = @"name";
  NSString *var22 = @"d469";
  [var16 setObject:var22 forKey:var21];
  NSString *var23 = @"type";
  NSString *var24 = @"DB";
  [var16 setObject:var24 forKey:var23];
  [var14 setObject:var16 forKey:var15];
  NSString *var25 = @"doc_count_estimates";
  NSMutableArray *var26 = [NSMutableArray arrayWithCapacity:1];
  NSNumber *var27 = @0;
  [var26 addObject:var27];
  [var14 setObject:var26 forKey:var25];
  NSString *var28 = @"id";
  NSMutableDictionary *var29 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var30 = @"func";
  NSString *var31 = @"uuid";
  [var29 setObject:var31 forKey:var30];
  [var14 setObject:var29 forKey:var28];
  NSString *var32 = @"indexes";
  NSMutableArray *var33 = [NSMutableArray arrayWithCapacity:1];
  NSString *var34 = @"x";
  [var33 addObject:var34];
  [var14 setObject:var33 forKey:var32];
  NSString *var35 = @"name";
  NSString *var36 = @"t469";
  [var14 setObject:var36 forKey:var35];
  NSString *var37 = @"primary_key";
  NSString *var38 = @"id";
  [var14 setObject:var38 forKey:var37];
  NSString *var39 = @"type";
  NSString *var40 = @"TABLE";
  [var14 setObject:var40 forKey:var39];
  [var0 setObject:var14 forKey:var13];
  NSString *var41 = @"type";
  NSString *var42 = @"TABLE_SLICE";
  [var0 setObject:var42 forKey:var41];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test19 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:6];
  NSString *var1 = @"index";
  NSString *var2 = @"id";
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"left_bound_type";
  NSString *var4 = @"unbounded";
  [var0 setObject:var4 forKey:var3];
  NSString *var5 = @"right_bound_type";
  NSString *var6 = @"unbounded";
  [var0 setObject:var6 forKey:var5];
  NSString *var7 = @"sorting";
  NSString *var8 = @"UNORDERED";
  [var0 setObject:var8 forKey:var7];
  NSString *var9 = @"table";
  NSMutableDictionary *var10 = [NSMutableDictionary dictionaryWithCapacity:7];
  NSString *var11 = @"db";
  NSMutableDictionary *var12 = [NSMutableDictionary dictionaryWithCapacity:3];
  NSString *var13 = @"id";
  NSMutableDictionary *var14 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var15 = @"func";
  NSString *var16 = @"uuid";
  [var14 setObject:var16 forKey:var15];
  [var12 setObject:var14 forKey:var13];
  NSString *var17 = @"name";
  NSString *var18 = @"d469";
  [var12 setObject:var18 forKey:var17];
  NSString *var19 = @"type";
  NSString *var20 = @"DB";
  [var12 setObject:var20 forKey:var19];
  [var10 setObject:var12 forKey:var11];
  NSString *var21 = @"doc_count_estimates";
  NSMutableArray *var22 = [NSMutableArray arrayWithCapacity:1];
  NSNumber *var23 = @0;
  [var22 addObject:var23];
  [var10 setObject:var22 forKey:var21];
  NSString *var24 = @"id";
  NSMutableDictionary *var25 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var26 = @"func";
  NSString *var27 = @"uuid";
  [var25 setObject:var27 forKey:var26];
  [var10 setObject:var25 forKey:var24];
  NSString *var28 = @"indexes";
  NSMutableArray *var29 = [NSMutableArray arrayWithCapacity:1];
  NSString *var30 = @"x";
  [var29 addObject:var30];
  [var10 setObject:var29 forKey:var28];
  NSString *var31 = @"name";
  NSString *var32 = @"t469";
  [var10 setObject:var32 forKey:var31];
  NSString *var33 = @"primary_key";
  NSString *var34 = @"id";
  [var10 setObject:var34 forKey:var33];
  NSString *var35 = @"type";
  NSString *var36 = @"TABLE";
  [var10 setObject:var36 forKey:var35];
  [var0 setObject:var10 forKey:var9];
  NSString *var37 = @"type";
  NSString *var38 = @"TABLE_SLICE";
  [var0 setObject:var38 forKey:var37];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test20 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:6];
  NSString *var1 = @"index";
  NSString *var2 = @"id";
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"left_bound_type";
  NSString *var4 = @"unachievable";
  [var0 setObject:var4 forKey:var3];
  NSString *var5 = @"right_bound_type";
  NSString *var6 = @"unachievable";
  [var0 setObject:var6 forKey:var5];
  NSString *var7 = @"sorting";
  NSString *var8 = @"UNORDERED";
  [var0 setObject:var8 forKey:var7];
  NSString *var9 = @"table";
  NSMutableDictionary *var10 = [NSMutableDictionary dictionaryWithCapacity:7];
  NSString *var11 = @"db";
  NSMutableDictionary *var12 = [NSMutableDictionary dictionaryWithCapacity:3];
  NSString *var13 = @"id";
  NSMutableDictionary *var14 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var15 = @"func";
  NSString *var16 = @"uuid";
  [var14 setObject:var16 forKey:var15];
  [var12 setObject:var14 forKey:var13];
  NSString *var17 = @"name";
  NSString *var18 = @"d469";
  [var12 setObject:var18 forKey:var17];
  NSString *var19 = @"type";
  NSString *var20 = @"DB";
  [var12 setObject:var20 forKey:var19];
  [var10 setObject:var12 forKey:var11];
  NSString *var21 = @"doc_count_estimates";
  NSMutableArray *var22 = [NSMutableArray arrayWithCapacity:1];
  NSNumber *var23 = @0;
  [var22 addObject:var23];
  [var10 setObject:var22 forKey:var21];
  NSString *var24 = @"id";
  NSMutableDictionary *var25 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var26 = @"func";
  NSString *var27 = @"uuid";
  [var25 setObject:var27 forKey:var26];
  [var10 setObject:var25 forKey:var24];
  NSString *var28 = @"indexes";
  NSMutableArray *var29 = [NSMutableArray arrayWithCapacity:1];
  NSString *var30 = @"x";
  [var29 addObject:var30];
  [var10 setObject:var29 forKey:var28];
  NSString *var31 = @"name";
  NSString *var32 = @"t469";
  [var10 setObject:var32 forKey:var31];
  NSString *var33 = @"primary_key";
  NSString *var34 = @"id";
  [var10 setObject:var34 forKey:var33];
  NSString *var35 = @"type";
  NSString *var36 = @"TABLE";
  [var10 setObject:var36 forKey:var35];
  [var0 setObject:var10 forKey:var9];
  NSString *var37 = @"type";
  NSString *var38 = @"TABLE_SLICE";
  [var0 setObject:var38 forKey:var37];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test21 {
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
