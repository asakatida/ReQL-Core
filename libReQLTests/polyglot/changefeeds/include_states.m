// Copyright 2015 Adam Grandquist

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#import <libReQL.h>

@interface ObjcTestIncludeStates : XCTestCase

@end

@implementation ObjcTestIncludeStates


- (void)test0 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:1];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var2 = @"state";
  NSString *var3 = @"ready";
  [var1 setObject:var3 forKey:var2];
  [var0 addObject:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test1 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var2 = @"state";
  NSString *var3 = @"initializing";
  [var1 setObject:var3 forKey:var2];
  [var0 addObject:var1];
  NSMutableDictionary *var4 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var5 = @"new_val";
  NSNull *var6 = [NSNull null];
  [var4 setObject:var6 forKey:var5];
  [var0 addObject:var4];
  NSMutableDictionary *var7 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var8 = @"state";
  NSString *var9 = @"ready";
  [var7 setObject:var9 forKey:var8];
  [var0 addObject:var7];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test2 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var2 = @"state";
  NSString *var3 = @"initializing";
  [var1 setObject:var3 forKey:var2];
  [var0 addObject:var1];
  NSMutableDictionary *var4 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var5 = @"state";
  NSString *var6 = @"ready";
  [var4 setObject:var6 forKey:var5];
  [var0 addObject:var4];
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
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var2 = @"state";
  NSString *var3 = @"initializing";
  [var1 setObject:var3 forKey:var2];
  [var0 addObject:var1];
  NSMutableDictionary *var4 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var5 = @"new_val";
  NSMutableDictionary *var6 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var7 = @"id";
  NSNumber *var8 = @1;
  [var6 setObject:var8 forKey:var7];
  [var4 setObject:var6 forKey:var5];
  [var0 addObject:var4];
  NSMutableDictionary *var9 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var10 = @"state";
  NSString *var11 = @"ready";
  [var9 setObject:var11 forKey:var10];
  [var0 addObject:var9];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test5 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"result";
  NSString *var2 = @"blank";
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
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var2 = @"state";
  NSString *var3 = @"ready";
  [var1 setObject:var3 forKey:var2];
  [var0 addObject:var1];
  NSMutableDictionary *var4 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var5 = @"new_val";
  NSMutableDictionary *var6 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var7 = @"id";
  NSNumber *var8 = @2;
  [var6 setObject:var8 forKey:var7];
  [var4 setObject:var6 forKey:var5];
  NSString *var9 = @"old_val";
  NSNull *var10 = [NSNull null];
  [var4 setObject:var10 forKey:var9];
  [var0 addObject:var4];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test8 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"result";
  NSString *var2 = @"blank";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test9 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"result";
  NSString *var2 = @"blank";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test10 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:4];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var2 = @"state";
  NSString *var3 = @"initializing";
  [var1 setObject:var3 forKey:var2];
  [var0 addObject:var1];
  NSMutableDictionary *var4 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var5 = @"new_val";
  NSMutableDictionary *var6 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var7 = @"id";
  NSNumber *var8 = @2;
  [var6 setObject:var8 forKey:var7];
  [var4 setObject:var6 forKey:var5];
  [var0 addObject:var4];
  NSMutableDictionary *var9 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var10 = @"state";
  NSString *var11 = @"ready";
  [var9 setObject:var11 forKey:var10];
  [var0 addObject:var9];
  NSMutableDictionary *var12 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var13 = @"new_val";
  NSMutableDictionary *var14 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var15 = @"a";
  NSNumber *var16 = @1;
  [var14 setObject:var16 forKey:var15];
  NSString *var17 = @"id";
  NSNumber *var18 = @2;
  [var14 setObject:var18 forKey:var17];
  [var12 setObject:var14 forKey:var13];
  NSString *var19 = @"old_val";
  NSMutableDictionary *var20 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var21 = @"id";
  NSNumber *var22 = @2;
  [var20 setObject:var22 forKey:var21];
  [var12 setObject:var20 forKey:var19];
  [var0 addObject:var12];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test11 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"result";
  NSString *var2 = @"blank";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test12 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"result";
  NSString *var2 = @"blank";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test13 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"result";
  NSString *var2 = @"blank";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test14 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var2 = @"state";
  NSString *var3 = @"initializing";
  [var1 setObject:var3 forKey:var2];
  [var0 addObject:var1];
  NSMutableDictionary *var4 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var5 = @"new_val";
  NSMutableDictionary *var6 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var7 = @"id";
  NSNumber *var8 = @1;
  [var6 setObject:var8 forKey:var7];
  [var4 setObject:var6 forKey:var5];
  [var0 addObject:var4];
  NSMutableDictionary *var9 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var10 = @"new_val";
  NSMutableDictionary *var11 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var12 = @"a";
  NSNumber *var13 = @1;
  [var11 setObject:var13 forKey:var12];
  NSString *var14 = @"id";
  NSNumber *var15 = @2;
  [var11 setObject:var15 forKey:var14];
  [var9 setObject:var11 forKey:var10];
  [var0 addObject:var9];
  NSMutableDictionary *var16 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var17 = @"state";
  NSString *var18 = @"ready";
  [var16 setObject:var18 forKey:var17];
  [var0 addObject:var16];
  NSMutableDictionary *var19 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var20 = @"new_val";
  NSMutableDictionary *var21 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var22 = @"id";
  NSNumber *var23 = @3;
  [var21 setObject:var23 forKey:var22];
  [var19 setObject:var21 forKey:var20];
  NSString *var24 = @"old_val";
  NSNull *var25 = [NSNull null];
  [var19 setObject:var25 forKey:var24];
  [var0 addObject:var19];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test15 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var2 = @"state";
  NSString *var3 = @"initializing";
  [var1 setObject:var3 forKey:var2];
  [var0 addObject:var1];
  NSMutableDictionary *var4 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var5 = @"new_val";
  NSMutableDictionary *var6 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var7 = @"a";
  NSNumber *var8 = @1;
  [var6 setObject:var8 forKey:var7];
  NSString *var9 = @"id";
  NSNumber *var10 = @2;
  [var6 setObject:var10 forKey:var9];
  [var4 setObject:var6 forKey:var5];
  [var0 addObject:var4];
  NSMutableDictionary *var11 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var12 = @"new_val";
  NSMutableDictionary *var13 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var14 = @"id";
  NSNumber *var15 = @1;
  [var13 setObject:var15 forKey:var14];
  [var11 setObject:var13 forKey:var12];
  [var0 addObject:var11];
  NSMutableDictionary *var16 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var17 = @"state";
  NSString *var18 = @"ready";
  [var16 setObject:var18 forKey:var17];
  [var0 addObject:var16];
  NSMutableDictionary *var19 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var20 = @"new_val";
  NSMutableDictionary *var21 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var22 = @"id";
  NSNumber *var23 = @3;
  [var21 setObject:var23 forKey:var22];
  [var19 setObject:var21 forKey:var20];
  NSString *var24 = @"old_val";
  NSNull *var25 = [NSNull null];
  [var19 setObject:var25 forKey:var24];
  [var0 addObject:var19];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

@end
