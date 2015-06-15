//
//  Connection.m
//  libReQL
//
//  Created by Adam Grandquist on 5/30/15.
//  Copyright (c) 2015 Adam Grandquist. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#import <libReQL.h>

@interface Connection : XCTestCase

@end

@implementation Connection

- (void)testExample {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  if ([connection isOpen]) {
    ReQLCursor *cursor = [[ReQLQuery add:@[@2, @2]] run:connection];
    XCTAssert(cursor);
    if (cursor) {
      NSArray *res = [cursor toArray];
      NSError *err;
      XCTAssert(![cursor error:&err]);
      XCTAssert([res isEqualTo:@[@4]]);
    }
    [cursor close];
  }
  [connection close];
}

@end
