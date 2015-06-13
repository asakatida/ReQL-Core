// Copyright 2015 Adam Grandquist

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#import <libReQL.h>

@interface ObjcTestPseudoLiteralStringsInJson : XCTestCase

@end

@implementation ObjcTestPseudoLiteralStringsInJson


- (void)test0 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"a";
  NSMutableDictionary *var2 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var3 = @"b";
  NSNumber *var4 = @2;
  [var2 setObject:var4 forKey:var3];
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

@end
