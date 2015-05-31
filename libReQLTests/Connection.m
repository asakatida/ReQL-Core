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
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testExample {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
