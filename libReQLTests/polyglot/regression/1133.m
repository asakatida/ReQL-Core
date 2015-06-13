// Copyright 2015 Adam Grandquist

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#import <libReQL.h>

@interface ObjcRegressionTestsForIssue : XCTestCase

@end

@implementation ObjcRegressionTestsForIssue


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
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test5 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"a";
  NSMutableDictionary *var2 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var3 = @"a";
  NSMutableDictionary *var4 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var5 = @"a";
  NSMutableDictionary *var6 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var7 = @"a";
  NSMutableDictionary *var8 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var9 = @"a";
  NSMutableDictionary *var10 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var11 = @"a";
  NSMutableDictionary *var12 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var13 = @"a";
  NSDictionary *var14 = [NSDictionary dictionary];
  [var12 setObject:var14 forKey:var13];
  [var10 setObject:var12 forKey:var11];
  [var8 setObject:var10 forKey:var9];
  [var6 setObject:var8 forKey:var7];
  [var4 setObject:var6 forKey:var5];
  [var2 setObject:var4 forKey:var3];
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

@end
