// Copyright 2015 Adam Grandquist

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#import <libReQL.h>

@interface ObjcTestsTheRqlMapFunction : XCTestCase

@end

@implementation ObjcTestsTheRqlMapFunction


- (void)test0 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSString *var0 = @"STREAM";
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test1 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSString *var0 = @"STREAM";
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test2 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSString *var0 = @"ARRAY";
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test3 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @0;
  [var0 addObject:var2];
  NSNumber *var3 = @0;
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test4 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @0;
  [var0 addObject:var2];
  NSNumber *var3 = @0;
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test5 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:1];
  NSMutableArray *var1 = [NSMutableArray arrayWithCapacity:1];
  NSNumber *var2 = @1;
  [var1 addObject:var2];
  [var0 addObject:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test6 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:1];
  NSMutableArray *var1 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var2 = @1;
  [var1 addObject:var2];
  NSNumber *var3 = @1;
  [var1 addObject:var3];
  [var0 addObject:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test7 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:1];
  NSMutableArray *var1 = [NSMutableArray arrayWithCapacity:3];
  NSNumber *var2 = @1;
  [var1 addObject:var2];
  NSNumber *var3 = @1;
  [var1 addObject:var3];
  NSNumber *var4 = @1;
  [var1 addObject:var4];
  [var0 addObject:var1];
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
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test11 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSMutableArray *var1 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var2 = @1;
  [var1 addObject:var2];
  NSNumber *var3 = @1;
  [var1 addObject:var3];
  [var0 addObject:var1];
  NSMutableArray *var4 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var5 = @2;
  [var4 addObject:var5];
  NSNumber *var6 = @2;
  [var4 addObject:var6];
  [var0 addObject:var4];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test12 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSMutableArray *var1 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var2 = @0;
  [var1 addObject:var2];
  NSNumber *var3 = @0;
  [var1 addObject:var3];
  [var0 addObject:var1];
  NSMutableArray *var4 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var5 = @1;
  [var4 addObject:var5];
  NSNumber *var6 = @1;
  [var4 addObject:var6];
  [var0 addObject:var4];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test13 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:4];
  NSMutableArray *var1 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var2 = @0;
  [var1 addObject:var2];
  NSNumber *var3 = @1;
  [var1 addObject:var3];
  [var0 addObject:var1];
  NSMutableArray *var4 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var5 = @1;
  [var4 addObject:var5];
  NSNumber *var6 = @2;
  [var4 addObject:var6];
  [var0 addObject:var4];
  NSMutableArray *var7 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var8 = @2;
  [var7 addObject:var8];
  NSNumber *var9 = @3;
  [var7 addObject:var9];
  [var0 addObject:var7];
  NSMutableArray *var10 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var11 = @3;
  [var10 addObject:var11];
  NSNumber *var12 = @4;
  [var10 addObject:var12];
  [var0 addObject:var10];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test14 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSMutableArray *var1 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var2 = @0;
  [var1 addObject:var2];
  NSNumber *var3 = @0;
  [var1 addObject:var3];
  [var0 addObject:var1];
  NSMutableArray *var4 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var5 = @1;
  [var4 addObject:var5];
  NSNumber *var6 = @1;
  [var4 addObject:var6];
  [var0 addObject:var4];
  NSMutableArray *var7 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var8 = @2;
  [var7 addObject:var8];
  NSNumber *var9 = @2;
  [var7 addObject:var9];
  [var0 addObject:var7];
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
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSMutableArray *var1 = [NSMutableArray arrayWithCapacity:1];
  NSNumber *var2 = @0;
  [var1 addObject:var2];
  [var0 addObject:var1];
  NSMutableArray *var3 = [NSMutableArray arrayWithCapacity:1];
  NSNumber *var4 = @1;
  [var3 addObject:var4];
  [var0 addObject:var3];
  NSMutableArray *var5 = [NSMutableArray arrayWithCapacity:1];
  NSNumber *var6 = @2;
  [var5 addObject:var6];
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test18 {
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

- (void)test19 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSMutableArray *var1 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var2 = @0;
  [var1 addObject:var2];
  NSNumber *var3 = @0;
  [var1 addObject:var3];
  [var0 addObject:var1];
  NSMutableArray *var4 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var5 = @1;
  [var4 addObject:var5];
  NSNumber *var6 = @1;
  [var4 addObject:var6];
  [var0 addObject:var4];
  NSMutableArray *var7 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var8 = @2;
  [var7 addObject:var8];
  NSNumber *var9 = @2;
  [var7 addObject:var9];
  [var0 addObject:var7];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

@end
