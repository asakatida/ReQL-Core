// Copyright 2015 Adam Grandquist

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#import <libReQL.h>

@interface ObjcTheseTestsTestTheTypeOfCommand : XCTestCase

@end

@implementation ObjcTheseTestsTestTheTypeOfCommand


- (void)test0 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSString *var0 = @"NULL";
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test1 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSString *var0 = @"NULL";
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

@end
