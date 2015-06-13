// Copyright 2015 Adam Grandquist

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#import <libReQL.h>

@interface ObjcTestChangefeedSquashing : XCTestCase

@end

@implementation ObjcTestChangefeedSquashing


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
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"result";
  NSString *var2 = @"blank";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test2 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"result";
  NSString *var2 = @"blank";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test3 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"result";
  NSString *var2 = @"blank";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test4 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"result";
  NSString *var2 = @"blank";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test5 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @1;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test6 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @1;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test7 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var2 = @"new_val";
  NSMutableDictionary *var3 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var4 = @"id";
  NSNumber *var5 = @100;
  [var3 setObject:var5 forKey:var4];
  [var1 setObject:var3 forKey:var2];
  NSString *var6 = @"old_val";
  NSNull *var7 = [NSNull null];
  [var1 setObject:var7 forKey:var6];
  [var0 addObject:var1];
  NSMutableDictionary *var8 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var9 = @"new_val";
  NSMutableDictionary *var10 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var11 = @"a";
  NSNumber *var12 = @1;
  [var10 setObject:var12 forKey:var11];
  NSString *var13 = @"id";
  NSNumber *var14 = @100;
  [var10 setObject:var14 forKey:var13];
  [var8 setObject:var10 forKey:var9];
  NSString *var15 = @"old_val";
  NSMutableDictionary *var16 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var17 = @"id";
  NSNumber *var18 = @100;
  [var16 setObject:var18 forKey:var17];
  [var8 setObject:var16 forKey:var15];
  [var0 addObject:var8];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test8 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var2 = @"new_val";
  NSMutableDictionary *var3 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var4 = @"id";
  NSNumber *var5 = @100;
  [var3 setObject:var5 forKey:var4];
  [var1 setObject:var3 forKey:var2];
  NSString *var6 = @"old_val";
  NSNull *var7 = [NSNull null];
  [var1 setObject:var7 forKey:var6];
  [var0 addObject:var1];
  NSMutableDictionary *var8 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var9 = @"new_val";
  NSMutableDictionary *var10 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var11 = @"a";
  NSNumber *var12 = @1;
  [var10 setObject:var12 forKey:var11];
  NSString *var13 = @"id";
  NSNumber *var14 = @100;
  [var10 setObject:var14 forKey:var13];
  [var8 setObject:var10 forKey:var9];
  NSString *var15 = @"old_val";
  NSMutableDictionary *var16 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var17 = @"id";
  NSNumber *var18 = @100;
  [var16 setObject:var18 forKey:var17];
  [var8 setObject:var16 forKey:var15];
  [var0 addObject:var8];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test9 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:1];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var2 = @"new_val";
  NSMutableDictionary *var3 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var4 = @"a";
  NSNumber *var5 = @1;
  [var3 setObject:var5 forKey:var4];
  NSString *var6 = @"id";
  NSNumber *var7 = @100;
  [var3 setObject:var7 forKey:var6];
  [var1 setObject:var3 forKey:var2];
  NSString *var8 = @"old_val";
  NSNull *var9 = [NSNull null];
  [var1 setObject:var9 forKey:var8];
  [var0 addObject:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test10 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:1];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var2 = @"new_val";
  NSMutableDictionary *var3 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var4 = @"a";
  NSNumber *var5 = @1;
  [var3 setObject:var5 forKey:var4];
  NSString *var6 = @"id";
  NSNumber *var7 = @100;
  [var3 setObject:var7 forKey:var6];
  [var1 setObject:var3 forKey:var2];
  NSString *var8 = @"old_val";
  NSNull *var9 = [NSNull null];
  [var1 setObject:var9 forKey:var8];
  [var0 addObject:var1];
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

@end
