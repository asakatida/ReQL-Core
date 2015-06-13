// Copyright 2015 Adam Grandquist

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#import <libReQL.h>

@interface ObjcTestsDeletesOfSelections : XCTestCase

@end

@implementation ObjcTestsDeletesOfSelections


- (void)test0 {
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
  NSNumber *var6 = @100;
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

- (void)test1 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @100;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test2 {
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

- (void)test3 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test4 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:6];
  NSString *var1 = @"deleted";
  NSNumber *var2 = @49;
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

- (void)test5 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:6];
  NSString *var1 = @"deleted";
  NSNumber *var2 = @50;
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

- (void)test6 {
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
