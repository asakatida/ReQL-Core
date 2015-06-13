// Copyright 2015 Adam Grandquist

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#import <libReQL.h>

@interface ObjcSkipAfterOrderbyCausesUseAfterFree522 : XCTestCase

@end

@implementation ObjcSkipAfterOrderbyCausesUseAfterFree522


- (void)test0 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"result";
  NSString *var2 = @"blank";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test1 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var2 = @"id";
  NSNumber *var3 = @1;
  [var1 setObject:var3 forKey:var2];
  [var0 addObject:var1];
  NSMutableDictionary *var4 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var5 = @"id";
  NSNumber *var6 = @2;
  [var4 setObject:var6 forKey:var5];
  [var0 addObject:var4];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

@end
