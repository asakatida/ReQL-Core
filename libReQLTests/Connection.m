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

- (void)setUp {
    [super setUp];
}

- (void)tearDown {
    [super tearDown];
}

- (void)testExample {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  ReQLQuery *num = [ReQLQuery newWithNumber:@2];
  ReQLQuery *query = [num add:@[[ReQLQuery newWithNumber:@2]]];
  ReQLCursor *cursor = [query run:connection];
  [cursor setDelegate:nil];
  XCTAssert(cursor != nil);
  for (ReQLQuery *res in cursor) {
    XCTAssert(res != nil);
  }
  NSError *err;
  XCTAssert(![cursor error:&err]);
  [cursor close];
  [connection close];
}

@end
