// Copyright 2015 Adam Grandquist

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#import <libReQL.h>

@interface ObjcTestsForMatch : XCTestCase

@end

@implementation ObjcTestsForMatch


- (void)test0 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:4];
  NSString *var1 = @"end";
  NSNumber *var2 = @5;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"groups";
  NSMutableArray *var4 = [NSMutableArray arrayWithCapacity:2];
  NSNull *var5 = [NSNull null];
  [var4 addObject:var5];
  NSMutableDictionary *var6 = [NSMutableDictionary dictionaryWithCapacity:3];
  NSString *var7 = @"end";
  NSNumber *var8 = @5;
  [var6 setObject:var8 forKey:var7];
  NSString *var9 = @"start";
  NSNumber *var10 = @2;
  [var6 setObject:var10 forKey:var9];
  NSString *var11 = @"str";
  NSString *var12 = @"cde";
  [var6 setObject:var12 forKey:var11];
  [var4 addObject:var6];
  [var0 setObject:var4 forKey:var3];
  NSString *var13 = @"start";
  NSNumber *var14 = @1;
  [var0 setObject:var14 forKey:var13];
  NSString *var15 = @"str";
  NSString *var16 = @"bcde";
  [var0 setObject:var16 forKey:var15];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test1 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNull *var0 = [NSNull null];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test2 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:4];
  NSString *var1 = @"end";
  NSNumber *var2 = @5;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"groups";
  NSMutableArray *var4 = [NSMutableArray arrayWithCapacity:2];
  NSNull *var5 = [NSNull null];
  [var4 addObject:var5];
  NSMutableDictionary *var6 = [NSMutableDictionary dictionaryWithCapacity:3];
  NSString *var7 = @"end";
  NSNumber *var8 = @5;
  [var6 setObject:var8 forKey:var7];
  NSString *var9 = @"start";
  NSNumber *var10 = @2;
  [var6 setObject:var10 forKey:var9];
  NSString *var11 = @"str";
  NSString *var12 = @"cde";
  [var6 setObject:var12 forKey:var11];
  [var4 addObject:var6];
  [var0 setObject:var4 forKey:var3];
  NSString *var13 = @"start";
  NSNumber *var14 = @1;
  [var0 setObject:var14 forKey:var13];
  NSString *var15 = @"str";
  NSString *var16 = @"bcde";
  [var0 setObject:var16 forKey:var15];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test3 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSString *var1 = @"aca";
  [var0 addObject:var1];
  NSString *var2 = @"ada";
  [var0 addObject:var2];
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
  NSNumber *var6 = @3;
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
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var2 = @"a";
  NSString *var3 = @"abc";
  [var1 setObject:var3 forKey:var2];
  NSString *var4 = @"id";
  NSNumber *var5 = @0;
  [var1 setObject:var5 forKey:var4];
  [var0 addObject:var1];
  NSMutableDictionary *var6 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var7 = @"a";
  NSString *var8 = @"ab";
  [var6 setObject:var8 forKey:var7];
  NSString *var9 = @"id";
  NSNumber *var10 = @1;
  [var6 setObject:var10 forKey:var9];
  [var0 addObject:var6];
  NSMutableDictionary *var11 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var12 = @"a";
  NSString *var13 = @"bc";
  [var11 setObject:var13 forKey:var12];
  NSString *var14 = @"id";
  NSNumber *var15 = @2;
  [var11 setObject:var15 forKey:var14];
  [var0 addObject:var11];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test6 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var2 = @"a";
  NSString *var3 = @"abc";
  [var1 setObject:var3 forKey:var2];
  NSString *var4 = @"id";
  NSNumber *var5 = @0;
  [var1 setObject:var5 forKey:var4];
  [var0 addObject:var1];
  NSMutableDictionary *var6 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var7 = @"a";
  NSString *var8 = @"ab";
  [var6 setObject:var8 forKey:var7];
  NSString *var9 = @"id";
  NSNumber *var10 = @1;
  [var6 setObject:var10 forKey:var9];
  [var0 addObject:var6];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test7 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:1];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var2 = @"a";
  NSString *var3 = @"ab";
  [var1 setObject:var3 forKey:var2];
  NSString *var4 = @"id";
  NSNumber *var5 = @1;
  [var1 setObject:var5 forKey:var4];
  [var0 addObject:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test8 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
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

@end
