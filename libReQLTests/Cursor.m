//
//  Cursor.m
//  libReQL
//
//  Created by Adam Grandquist on 6/14/15.
//  Copyright (c) 2015 Adam Grandquist. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#import <libReQL.h>

@interface Cursor : XCTestCase

@property(strong) ReQLConnection *connection;
@property(strong) ReQLCursor *cursor;

@end

@implementation Cursor

-(void)setUp {
  [super setUp];
  self.connection = [ReQLConnection new];
}

-(void)tearDown {
  if (self.cursor != nil) {
    [self.cursor close];
  }
  [self.connection close];
  [super tearDown];
}

-(void)verifyQuery:(ReQLQuery *)query result:(NSArray *)result {
  ReQLCursor *cursor = [query run:self.connection];
  XCTAssert(cursor != nil);
  NSArray *res = [cursor toArray];
  NSError *err;
  XCTAssert(![cursor error:&err]);
  XCTAssert(res != nil);
  XCTAssert([res isEqualTo:result]);
}

-(void)testExample {
  [self verifyQuery:[[ReQLQuery newWithNumber:@2] add:@[[ReQLQuery newWithNumber:@2]]] result:@[@4]];
}

-(void)testPerformanceExample {
  [self measureBlock:^{
    [self verifyQuery:[[ReQLQuery newWithNumber:@2] add:@[[ReQLQuery newWithNumber:@2]]] result:@[@4]];
  }];
}

@end
