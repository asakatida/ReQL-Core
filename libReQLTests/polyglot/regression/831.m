// Copyright 2015 Adam Grandquist

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#import <libReQL.h>

@interface Objc831EmptyBatchedReplacesTConstructed : XCTestCase

@end

@implementation Objc831EmptyBatchedReplacesTConstructed


- (void)test0 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:7];
  NSString *var1 = @"deleted";
  NSNumber *var2 = @0;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"errors";
  NSNumber *var4 = @2;
  [var0 setObject:var4 forKey:var3];
  NSString *var5 = @"first_error";
  NSString *var6 = @"Expected type OBJECT but found BOOL.";
  [var0 setObject:var6 forKey:var5];
  NSString *var7 = @"inserted";
  NSNumber *var8 = @0;
  [var0 setObject:var8 forKey:var7];
  NSString *var9 = @"replaced";
  NSNumber *var10 = @0;
  [var0 setObject:var10 forKey:var9];
  NSString *var11 = @"skipped";
  NSNumber *var12 = @0;
  [var0 setObject:var12 forKey:var11];
  NSString *var13 = @"unchanged";
  NSNumber *var14 = @0;
  [var0 setObject:var14 forKey:var13];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

@end
