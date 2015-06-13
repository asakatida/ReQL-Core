// Copyright 2015 Adam Grandquist

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#import <libReQL.h>

@interface Objc2767EvaulateSecondaryIndexFunctionWithPristineEnv : XCTestCase

@end

@implementation Objc2767EvaulateSecondaryIndexFunctionWithPristineEnv


- (void)test0 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"created";
  NSNumber *var2 = @1;
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

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
  NSNumber *var6 = @1;
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
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:1];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var2 = @"a";
  NSMutableArray *var3 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var4 = @1;
  [var3 addObject:var4];
  NSNumber *var5 = @2;
  [var3 addObject:var5];
  NSNumber *var6 = @3;
  [var3 addObject:var6];
  NSNumber *var7 = @4;
  [var3 addObject:var7];
  NSNumber *var8 = @5;
  [var3 addObject:var8];
  [var1 setObject:var3 forKey:var2];
  NSString *var9 = @"id";
  NSNumber *var10 = @1;
  [var1 setObject:var10 forKey:var9];
  [var0 addObject:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test3 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:1];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var2 = @"a";
  NSMutableArray *var3 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var4 = @1;
  [var3 addObject:var4];
  NSNumber *var5 = @2;
  [var3 addObject:var5];
  NSNumber *var6 = @3;
  [var3 addObject:var6];
  NSNumber *var7 = @4;
  [var3 addObject:var7];
  NSNumber *var8 = @5;
  [var3 addObject:var8];
  [var1 setObject:var3 forKey:var2];
  NSString *var9 = @"id";
  NSNumber *var10 = @1;
  [var1 setObject:var10 forKey:var9];
  [var0 addObject:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test4 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:1];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var2 = @"a";
  NSMutableArray *var3 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var4 = @1;
  [var3 addObject:var4];
  NSNumber *var5 = @2;
  [var3 addObject:var5];
  NSNumber *var6 = @3;
  [var3 addObject:var6];
  NSNumber *var7 = @4;
  [var3 addObject:var7];
  NSNumber *var8 = @5;
  [var3 addObject:var8];
  [var1 setObject:var3 forKey:var2];
  NSString *var9 = @"id";
  NSNumber *var10 = @1;
  [var1 setObject:var10 forKey:var9];
  [var0 addObject:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

@end
