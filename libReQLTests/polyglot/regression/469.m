// Copyright 2015 Adam Grandquist

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#import <libReQL.h>

@interface ObjcIssue457 : XCTestCase

@end

@implementation ObjcIssue457


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
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var1 = @"type";
  NSString *var2 = @"NULL";
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"value";
  NSString *var4 = @"null";
  [var0 setObject:var4 forKey:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test5 {
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

- (void)test6 {
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

- (void)test7 {
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

- (void)test8 {
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

- (void)test9 {
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

- (void)test10 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"partial";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test11 {
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

- (void)test12 {
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

- (void)test13 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"type";
  NSString *var2 = @"STREAM";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test14 {
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
