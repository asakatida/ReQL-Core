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
  ReQLQuery *num = [ReQLQuery newWithNumber:@2];
  ReQLQuery *query = [num add:@[[ReQLQuery newWithNumber:@2]]];
  ReQLCursor *cursor = [query run:connection];
  XCTAssert(cursor != nil);
  NSArray *res = [cursor toArray];
  NSError *err;
  XCTAssert(![cursor error:&err]);
  XCTAssert(res != nil);
  XCTAssert([res isEqualTo:@[@4]]);
  [cursor close];
  [connection close];
}

@end
